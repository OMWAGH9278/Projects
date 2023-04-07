#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    char Fname[20];
    int fd = 0;

    printf("Enter the file name that you want to create : ");
    scanf("%s", Fname);

    fd = creat(Fname,0777);

    if(fd == -1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("File is successfully created with FD : %d\n", fd);
    }

    return (0);
}