#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int openFile(char name[])
{
    int fd = 0;
    fd = open(name, O_RDWR);
    return (fd);
}

int main(void)
{
    char Fname[20];
    int fd = 0;

    printf("Enter the file name that you want to open : ");
    scanf("%s", Fname);

    fd = openFile(Fname);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File is successfully opened with fd : %d\n", fd);
    }

    return (0);
}