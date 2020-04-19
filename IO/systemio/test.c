#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fp = open("./tmp.txt", O_RDWR | O_CREAT | O_APPEND, 0664);
    if (fp < 0)
    {
        perror("open");
        return 0;
    }
    
    int ret = write(fp, "hello world", 11);
    if(ret < 0)
    {
        perror("write");
        return 0;
    }

    lseek(fp, 0, SEEK_SET);

    char buf[1024] = {0};
    ret = read(fp, buf, sizeof(buf) - 1);
    if(ret < 0)
    {
        printf("read");
        return 0;
    }
    else if(ret == 0)
    {
        printf("read size :[%d]\n", ret);
    }

    printf("%s\n",buf);
    close(fp);
    return 0;
}
