#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("./tmp.txt", O_RDWR | O_CREAT, 0664);
    if(fd < 0)
    {
        perror("open");
        return 0;
    }

    //重定向
    //把本应输出到屏幕的内容输出到文件中

    dup2(fd, 1);
    printf("good job!\n");
    while(1)
    {
        sleep(1);
    }
    return 0;
}


