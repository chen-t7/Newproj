#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd[2];
    int ret = pipe(fd);
    if(ret < 0)
    {
        perror("pipe");
        return 0;
    }

    //获取当前文件描述符的属性，通过返回值返回回来
    int flags = fcntl(fd[0], F_GETFL, 0);
    flags |= O_NONBLOCK;
    fcntl(fd[0], F_SETFL, flags);

    //创建子进程
    ret = fork();
    if(ret < 0)
    {
        perror("fork");
        return 0;
    }
    else if(ret == 0)
    {
        //child  读
        //sleep(3);
        //close(fd[0]);
        close(fd[1]);
        char buf[1024] = {0};
        int  readsize = read(fd[0], buf, sizeof(buf) - 1);
        if(readsize < 0)
        {
             perror("read");
             printf("readsize :[%d]\n", readsize);
             exit(0);
        }
        printf("i am child and i read buf [%s]\n", buf);
        printf("size :[%d]\n", readsize);
        //1.管道当中没有数据了，read就会阻塞
        //2.管道当中的数据是被拿走了
        //readsize = read(fd[0], buf, sizeof(buf) - 1);
        while(1)
        {
            sleep(1);
        }
    }
    //father 写
    //sleep(30);
    //close(fd[0]);
    //int count = 0;
    //while(1)
    //{
    //    int ret = write(fd[1], "6", 1);
    //    if(ret < 0)
    //    {
    //        perror("write:");
    //        break;
    //    }
    //    count++;
    //    printf("write size [%d]\n", count);
    //}

    close(fd[1]);
    while(1)
    {
        sleep(1);
        printf("i am father\n");
    }
    return 0;
}
