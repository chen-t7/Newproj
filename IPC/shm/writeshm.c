#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

#define shm_key 0x12345678
int main()
{
    int shmid = shmget(shm_key, 1024, IPC_CREAT | 0664);
    if(shmid < 0)
    {
        perror("shmget");
        return 0;
    }

    void *lp = shmat(shmid, NULL, 0);
    if(!lp)
    {
        perror("shmat");
        return 0;
    }
    int i = 0;
    while(1)
    {
        sprintf((char*)lp, "%s-%d", "linux", i);
        i++;
        sleep(1);
    }
    //shmdt(lp);
    //shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
