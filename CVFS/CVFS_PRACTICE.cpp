#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <io.h>

#define MAXINODE        50

#define READ            1
#define WRITE           2

#define MAXFILESIZE     1024
#define MAXCOMMANDSIZE  80
#define MAXCOMMANDS     4

#define REGULAR         1
#define SPECIAL         2

#define START           0
#define CURRENT         1
#define END             2

typedef struct superblock
{
    int totalinodes;
    int freeinodes;
};SUPERBLOCK, *PSUPERBLOCK;

typedef struct inode
{
    char filename[50];
    int inodenumber;
    int filesize;
    int fileactualsize;
    int filetype;
    char* buffer;
    int linkcount;
    int referencecount;
    int permission;
    struct inode* next;
};INODE, *PINODE, **PPINODE;

typedef struct filetable
{
    int readoffset;
    int writeoffset;
    int mode;
    int count;
    PINODE ptrinode;
}FILETABLE, *PFILETABLE;

typedef struct ufdt
{
    PFILETABLE ptrfiletable;
}UFDT;

UFDT UFDTArr[MAXINODE+3];
SUPERBLOCK SUPERBLOCKobj;
PINODE head = NULL;

void man(char* name);
void displayHelp();
int getFdFromName(char* name);
PINODE getInode(char* name);
void createDILB();
void initialiseSuperBlock();
int createFile(char* name, int permission);
int writeFile(int fd, char* arr, int isize);
int readFile(int fd, char* arr, int isize);
int lseekFile(int fd, int size, int from);
int openFile(char* name, int mode);
void closeFileByName(int fd);
int closeFileByName(chra* name);
void closeAllFile();
int rm_File(char* name);
void ls_File();
int fstat_File(int fd);
int stat_File(char* name);
int truncate_File(char* name);

int main(void)
{
    char* ptr = NULL;
    int count = 0, ret = 0, fd = 0;
    char command[MAXCOMMANDS][MAXCOMMANDSIZE], str[MAXCOMMANDSIZE], arr[MAXFILESIZE];

    initialiseSuperBlock();
    createDILB();

    while(1)
    {
        fflush(stdin);
        strcpy(str,'');

        printf("\nMarvellous VFS : > ");

        fgets(str,MAXCOMMANDSIZE,stdin);
        count = sscanf(str,"%s %s %s %s", command[0], command[1], command[2], command[3]);

        if(count == 1)
        {
            if(strcmp(command[0],"ls") == 0)
            {
                ls_File();
                continue;
            }
            else if(strcmp(command[0],"closeall") == 0)
            {
                closeAllFile();
                puts("All files closed successfully");
                continue;
            }
            else if(strcmp(command[0],"clear") == 0)
            {
                system("cls");
                continue;
            }
            else if(strcmp(command[0],"help") == 0)
            {
                displayHelp();
                continue;
            }
            else if(strcmp(command[0],"exit") == 0)
            {
                puts("Terminating the Marvellous Virtual File System");
                break;
            }
            else
            {
                printf("\nERROR : Command Not Found!!");
                continue;
            }
        }
        else if(count == 2)
        {
            if(strcmp(command[0],"stat") == 0)
            {
                ret = stat_File(command[1]);
                if(ret == -1)
                {
                    printf("ERROR : Incorrect Parameters\n");
                    continue;
                }
                if(ret == -2)
                {
                    printf("ERROR : There is no such file\n");
                    continue;
                }
                continue;
            }
            else if(strcmp(command[0],"fstat") == 0)
            {
                ret = fstat_File(atoi(command[1]));
                if(ret == -1)
                {
                    printf("ERROR : Incorrect Parameters\n");
                    continue;
                }
                if(ret == -2)
                {
                    printf("ERROR : There is no such file\n");
                    continue;
                }
                continue;
            }
            else if(strcmp(command[0],"close") == 0)
            {
                ret = closeFileByName(command[1]);
                if(ret == -1)
                    printf("ERROR : There is no such file\n");
                continue;
            }
            else if(strcmp(command[0],"rm") == 0)
            {
                ret = rm_File(command[1]);
                if(ret == -1)
                    printf("ERROR : There is no such file\n");
                continue;
            }
            else if(strcmp(command[0],"man") == 0)
            {
                man(command[1]);
                continue;
            }
            else if(strcmp(command[0],"write") == 0)
            {
                fd = getFdFromName(atoi(command[1]));
                if(ret == -1)
                {
                    printf("ERROR : Incorrect Parameters\n");
                    continue;
                }
                printf("Enter the data :\n");
                scanf("%[^\n]s", arr);

                ret = strlen(arr);
                if(ret == 0)
                {
                    printf("ERROR : Incorrect Parameters\n");
                    continue;
                }
                ret = writeFile(fd,arr,ret);
                if(ret == -1)
                {
                    printf("ERROR : Permission denied\n");
                    continue;
                }
                if(ret == -2)
                {
                    printf("ERROR : There is no sufficient memory\n");
                    continue;
                }
                if(ret == -3)
                {
                    printf("ERROR : It is no regular file\n");
                    continue;
                }
                continue;
            }
            else if(strcmp(command[0],"truncate") == 0)
            {
                ret = truncate_File(command[1]);
                if(ret == -1)
                    printf("ERROR : Incorrect Parameters\n");
                continue;
            }
            else
            {
                printf("\nERROR : Command Not Found!!");
                continue;
            }
        }
        else if(count == 3)
        {
            if(strcmp(command[0],"create") == 0)
            {
                ret = createFile(command[1],atoi(command[2]));
                if(ret >= 0)
                {
                    printf("File is successfully created with file descriptor : %d\n", ret);
                    continue;
                }
                if(ret == -1)
                {
                    printf("ERROR : Incorrect Parameters\n");
                    continue;
                }
                if(ret == -2)
                {
                    printf("ERROR : There are no inodes\n");
                    continue;
                }
                if(ret == -3)
                {
                    printf("ERROR : File already exists\n");
                    continue;
                }
                if(ret == -4)
                {
                    printf("ERROR : Memory Allocation Failure\n");
                    continue;
                }
            }
            else if(strcmp(command[0],"open") == 0)
            {
                ret = openFile(command[1],atoi(command[2]));
                if(ret >= 0)
                {
                    printf("File is successfully created with file descriptor : %d\n", ret);
                    continue;
                }
                if(ret == -1)
                {
                    printf("ERROR : Incorrect Parameters\n");
                    continue;
                }
                if(ret == -2)
                {
                    printf("ERROR : File not present\n");
                    continue;
                }
                if(ret == -3)
                {
                    printf("ERROR : Permission denied\n");
                    continue;
                }
            }
            else
            {
                printf("\nERROR : Command Not Found!!");
                continue;
            }
        }
        else if(count == 4)
        {
            else
            {
                printf("\nERROR : Command Not Found!!");
                continue;
            }
        }
        else
        {
            printf("\nERROR : Command Not Found!!");
            continue;
        }
    }

    return (0);
}
