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

    fd = open(fname,O_RDWR);

    if(fd == -1)
    {
        return (-1);
    }

    // read(kuthun,kashyat,kiti);
    length = read(fd,data,13);

    printf("Data from file is :\n");
    write(1,data,length);  // 0 : Standard Input Device     Keyboard
                           // 1 : Standard Output Device    Console
                           // 2 : Standard Error Device     Console 

    close(fd);

    return (0);
}