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

    fd = open(fname,O_RDWR | O_APPEND);

    if(fd == -1)
    {
        return (-1);
    }
    
    printf("Enter the data that you want to write in the file :\n");
    scanf(" %[^'\n']", data);

    length = strlen(data);

    // write(kashat,kay,kiti);
    write(fd,data,length);

    return (0);
}