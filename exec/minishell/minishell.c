#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
#include <stdlib.h>

char g_Command[1024];

int GetCommand()
{
    memset(g_Command, '\0', sizeof(g_Command));
    printf("[minishell@localhost ~]");
    fflush(stdout);
    //一定要预留\0的位置
    if(fgets(g_Command, sizeof(g_Command) - 1, stdin) == NULL)
    {
        printf("fgets error\n");
        return -1;
    }
    printf("g_Command: %s\n", g_Command);
    return 0;
}

//argv[]
// argv[0] : 可执行程序的名称，没有路径
// argv[1] : 可执行程序的参数
// ...
// argv[x] : NULL
int ExecCommand(char *argv[])
{
    if(argv[0] == NULL)
    {
        printf("ExecCommand error\n");
        return -1;
    }

    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return -1;
    }
    else if(pid == 0)
    {
        //child 进程程序替换
        //将已经切割命令好的命令程序（可执行程序以及可执行程序的参数），进行程序替换
        execvp(argv[0], argv);
        //将没有替换成功的子进程杀掉
        exit(0);
    }
    else
    {
        //father  进程等待
        waitpid(pid, NULL, 0);
    }
    return 0;
}

int DealCommand(char *command)
{
    if(!command && command == '\0')
    {
        printf("command error\n");
        return -1;
    }
    
    //ls -al 区分哪一部分是命令，哪一部分是命令行参数
    //    ls   -al -s- d
    int argc = 0;
    char *argv[1024] = {0};
    //argv[0] = 可执行程序的名称，在这里是保存命令的
    //argv[1] = 保存命令行参数
    //...   argv[i] = NULL;
    
    while(*command)
    {
        while(!isspace(*command) && *command != '\0')
        {
            argv[argc] = command;
            argc++;
            //去找下一个空格
            while(!isspace(*command) && *command != '\0')
            {
                command++;
            }
            command = '\0';
        }
        command++;
    }
    argv[argc] = NULL;
    int i = 0;
    //for(; i < argc; i++)
    //{
    //      printf("%d:%s\n", argc, argv[i]);
    //}

    ExecCommand(argv);
    return 0;
}

int main()
{
    while(1)
    {
        if(GetCommand() == -1)
        {
            continue;
        }
        //处理字符串
        DealCommand(g_Command);
    }
    return 0;
}
