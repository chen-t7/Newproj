#include <stdio.h>

int main()
{
    FILE *fp =fopen("tmp.txt", "w+");
    if(!fp)
    {
        perror("fp");
        return 0;
    }

    const char *lp = "happy everyday";
    int ret = fwrite(lp, 1, 14, fp);
    if(ret == 14)
    {
        printf("write size:[%d]\n", ret);
    }
    fseek(fp, 0, SEEK_SET);
    char arr[1024] = {0};
    ret = fread(arr, 1, sizeof(arr) - 1, fp);
    if(ret == 14)
    {
        printf("read size[%d]\n", ret);
    }

    fclose(fp);
    return 0;
}
