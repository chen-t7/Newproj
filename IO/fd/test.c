#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    //关闭标准输入
    close(0);
    int fp = open("./tmp.txt", O_RDWR | O_CREAT, 0664);
    if(fp < 0)
    {
        perror("open");
        return 0;
    }
    printf("fp :[%d]\n", fp);

    while(1)
    {
        sleep(1);
    }
    return 0;
}
