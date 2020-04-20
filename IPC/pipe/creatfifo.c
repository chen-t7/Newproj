#include <stdio.h>
#include <sys/stat.h>

int main()
{
    int ret = mkfifo("./CFIFO", 0664);
    if(ret < 0)
    {
        perror("mkfifo");
        return 0;
    }
    //open
    //write
    //read
    //close

    return 0;
}
