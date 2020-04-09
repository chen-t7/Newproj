#include <stdio.h>

int main()
{
    FILE *fp = fopen("tmp.txt", "r+");
    if(!fp)
    {
        perror("fp");
    }

    char arr[1024] = {0};
    int ret = fread(arr, 1, sizeof(arr) - 1, fp);
    if(ret == 14)
    {
        printf("read size[%d]\n", ret);
    }
    return 0;
}
