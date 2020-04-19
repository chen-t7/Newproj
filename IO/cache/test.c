#include <stdio.h>
#include <unistd.h>

int main()
{
    while(1)
    {
        printf("hello world");
        usleep(10000);
    }
    sleep(5);
    return 0;
}
