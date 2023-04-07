#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

// O_RDONLY     Open for reading
// O_WRONLY     Open for writing
// O_RDWR       Open for reading and writing

int main(void)
{
    char Fname[20];
    int fd = 0;

    printf("Enter the file name that you want to open : ");
    scanf("%s", Fname);

    fd = open(Fname, O_RDWR);

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