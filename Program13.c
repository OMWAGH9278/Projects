#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    char fname[20], data[100];
    int fd = 0, length = 0, total_characters = 0, small_characters = 0;
    int i = 0;

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
        total_characters = total_characters + length;
        for(i = 0; i < length; ++i)
        {
            if((data[i] >= 'a') && (data[i] <= 'z'))
            {
                small_characters++;
            }
        }
    }

    printf("Total characters in file : %d\n", total_characters);
    printf("Small characters in file : %d\n", small_characters);

    close(fd);

    return (0);
}