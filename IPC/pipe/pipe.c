#include <stdio.h>
#include <unistd.h>
int main()
{
    int fd[2];
    int ret = pipe(fd);
    if(ret < 0)
    {
        perror("pipe");
        return 0;
    }

    //fd[0] : 读端-->文件描述符
    //fd[1] : 写端-->文件描述符

    write(fd[1], "be happy", 8);

    char buf[1024] = {0};

    read(fd[0], buf, sizeof(buf) - 1);
    printf("buf [%s]\n", buf);
    while(1)
    {
        sleep(1);
    }
    return 0;
}
