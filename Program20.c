#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int fdSource = 0, fdDest = 0, length = 0;
    char data[100];

    fdSource = open(argv[1], O_RDONLY);

    if(fdSource == -1)
    {
        printf("Unable to open file\n");
        return (-1);
    }

    fdDest = creat(argv[2],0777);
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

    printf("Data copied successfully\n");

    return (0);
}