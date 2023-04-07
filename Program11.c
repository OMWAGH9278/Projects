#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    char fname[20], data[100];
    int fd = 0, length = 0;

    printf("Enter the file name that you want to open :\n");
    scanf("%s", fname);

    fd = open(fname, O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return (-1);
    }

    while((length = read(fd,data,sizeof(data))) != 0)
    {
        write(1,data,length);
    }

    close(fd);

    return (0);
}