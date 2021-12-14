#include <stdio.h>
#include <fcntl.h>             
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define size 100
int main(int argc, char const *argv)

{
    pid_t id;
    char buff[20];
    int fd[2];
    pipe(fd);
    printf("before fork\n");
    id=fork();
     printf("after fork\n");
     if (id==0)
     {
         close(fd[1]);
         printf("process 2: reads data\n");
         read(fd[0],buff,20);
         printf("process 2:%s\n",buff);
     }
    else
    {
        close(fd[0]);
        printf("process 1: writes data\n");
        write(fd[1],"M",20);
        printf("process 1:sends data to process\n");
    }
    printf("length of the string:%d\n");
    return 0;
}