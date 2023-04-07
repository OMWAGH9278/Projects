#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int createFile(char name[])
{
    int fd = 0;
    fd = creat(name, 0777);
    return (fd);
}

int main(void)
{
    char Fname[20];
    int fd = 0;

    printf("Enter the file name that you want to create : ");
    scanf("%s", Fname);

    fd = createFile(Fname);

    if(fd == -1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("File is successfully creatde with fd : %d\n", fd);
    }

    return (0);
}