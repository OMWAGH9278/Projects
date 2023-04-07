#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
    char Fname[20];
    int fd = 0;
    char data[] = "Marvellous Infosystems Logic Building";

    printf("Enter the file name that you want to open : ");
    scanf("%s", Fname);

    fd = open(Fname,O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File is successfully opened with fd : %d\n", fd);
        write(fd,data,37);
    }

    return (0);
}