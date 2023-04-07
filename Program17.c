#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    char fnameSource[20];
    char fnameDest[20];
    char data[100];
    int fdSource = 0, fdDest = 0, length = 0;

    printf("Enter the file name which contains data :\n");
    scanf("%s", fnameSource);

    fdSource = open(fnameSource, O_RDONLY);

    if(fdSource == -1)
    {
        printf("Unable to open file\n");
        return (-1);
    }

    printf("Enter the file name that you want to create :\n");
    scanf("%s", fnameDest);

    fdDest = creat(fnameDest,0777);
    if(fdDest == -1)
    {
        printf("Unable to create file\n");
        return (-1);
    }

    while((length = read(fdSource,data,sizeof(data))) != 0)
    {
        write(fdDest,data,length);
    }

    close(fdSource);
    close(fdDest);

    return (0);
}