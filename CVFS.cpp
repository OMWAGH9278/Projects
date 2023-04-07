#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
// #include <io.h>

#define MAXINODE                50

#define READ                    1
#define WRITE                   2

#define MAXFILESIZE             1024
#define MAXCOMMANDSIZE          80
#define MAXNUMBEROFCOMMANDS     4

#define REGULAR                 1
#define SPECIAL                 2

#define START                   0 
#define CURRENT                 1
#define END                     2

typedef struct superblock
{
    int totalinodes;
    int freeinode;
}SUPERBLOCK, *PSUPERBLOCK;

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
    int permission;  // 1   -   23
    struct inode* next;
}INODE, *PINODE, **PPINODE;

typedef struct filetable
{
    int readoffset;
    int writeoffset;
    int count;
    int mode;  // 1  2  3
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
int rm_File(char* name);  // rm_File("Demo.txt");
int readFile(int fd, char* arr, int iSize);
int writeFile(int fd, char* arr, int iSize);
int openFile(char* name, int mode);
void closeFileByName(int fd);
int closeFileByName(char* name);
void closeAllFile();
int lseekFile(int fd, int size, int from);
void ls_File();
int fstat_File(int fd);
int stat_File(char* name);
int truncate_File(char* name);

int main(void)
{
    char* ptr = NULL;
    int ret = 0, fd = 0, count = 0;
    char command[MAXNUMBEROFCOMMANDS][MAXCOMMANDSIZE], str[MAXCOMMANDSIZE], arr[MAXFILESIZE];

    initialiseSuperBlock();
    createDILB();

    // shell
    while(1)
    {
        fflush(stdin);
        strcpy(str,"");

        printf("\nMarvellous VFS : > ");

        fgets(str,MAXCOMMANDSIZE,stdin);  // scanf("%[^'\n']s", str);
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
                puts("Terminating the Marvellous Virtual File Systems");
                break;
            }
            else
            {
                puts("\nERROR : Command Not Found :( !!");
                continue;
            }
        }
        else if(count == 2)
        {
            if(strcmp(command[0],"stat") == 0)
            {
                ret = stat_File(command[1]);
                if(ret == -1)
                    puts("ERROR : Incorrect Parameters");
                if(ret == -2)
                    puts("ERROR : There is no such file");
                continue;
            }
            else if(strcmp(command[0],"fstat") == 0)
            {
                ret = fstat_File(atoi(command[1]));
                if(ret == -1)
                    puts("ERROR : Incorrect Parameters");
                if(ret == -2)
                    puts("ERROR : There is no such file");
                continue;
            }
            else if(strcmp(command[0],"close") == 0)
            {
                ret = closeFileByName(command[1]);
                if(ret == -1)
                    puts("Error : There is no such file");
                continue;
            }
            else if(strcmp(command[0],"rm") == 0)
            {
                ret = rm_File(command[1]);
                if(ret == -1)
                    puts("ERROR : There is no such file");
                continue;
            }
            else if(strcmp(command[0],"man") == 0)
            {
                man(command[1]);
                continue;
            }
            else if(strcmp(command[0],"write") == 0)
            {
                fd = getFdFromName(command[1]);
                if(fd == -1)
                {
                    puts("ERROR : Incorrect Parameters");
                    continue;
                }
                puts("Enter the data : ");
                fgets(arr,MAXFILESIZE,stdin);

                ret = strlen(arr);
                if(ret == 0)
                {
                    puts("ERROR : Incorrect parameter");
                    continue;
                }
                ret = writeFile(fd,arr,ret);
                if(ret == -1)
                    puts("ERROR : Permission denied");
                if(ret == -2)
                    puts("ERROR : There is no sufficient memory");
                if(ret == -3)
                    puts("ERROR : It is not regular file");
                continue;
            }
            else if(strcmp(command[0],"truncate") == 0)
            {
                ret = truncate_File(command[1]);
                if(ret == -1)
                    puts("Incorrect parameters");
                continue;
            }
            else
            {
                puts("\nERROR : Command not found :( !!");
                continue;
            }
        }
        else if(count == 3)
        {
            if(strcmp(command[0],"create") == 0)
            {
                ret = createFile(command[1],atoi(command[2]));
                if(ret >= 0)
                    printf("File is successfully created with file descriptor : %d\n", ret);
                if(ret == -1)
                    puts("ERROR : Incorrect parameters");
                if(ret == -2)
                    puts("ERROR : There are no inodes");
                if(ret == -3)
                    puts("ERROR : File already exists");
                if(ret == -4)
                    puts("ERROR : Memory Allocation Failure");
                continue;
            }
            else if(strcmp(command[0],"open") == 0)
            {
                ret = openFile(command[1],atoi(command[2]));
                if(ret >= 0)
                    printf("File is successfully opened with file descriptor : %d\n", ret);
                if(ret == -1)
                    puts("ERROR : Incorrect parameters");
                if(ret == -2)
                    puts("ERROR : File not present");
                if(ret == -3)
                    puts("ERROR : Permission denied");
                continue;
            }
            else if(strcmp(command[0],"read") == 0)
            {
                fd = getFdFromName(command[1]);
                if(fd == -1)
                {
                    puts("ERROR : Incorrect parameters");
                    continue;
                }
                ptr = (char*)malloc(sizeof(atoi(command[2]))+1);
                if(ptr == NULL)
                {
                    puts("ERROR : Memory Allocation Failed");
                    continue;
                }
                ret = readFile(fd,ptr,atoi(command[2]));
                if(ret == 0)
                {
                    puts("ERROR : File empty");
                    continue;
                }
                if(ret == -1)
                {
                    puts("ERROR : File does not exist");
                    continue;
                }
                if(ret == -2)
                {
                    puts("ERROR : Permission denied");
                    continue;
                }
                if(ret == -3)
                {
                    puts("ERROR : Reached at the end of file");
                    continue;
                }
                if(ret == -4)
                {
                    puts("ERROR : It is not a regular file");
                    continue;
                }
                if(ret > 0)
                    write(2,ptr,ret);
                continue;
            }
            else
            {
                puts("ERROR : Command not found!!");
                continue;
            }
        }
        else if(count == 4)
        {
            if(strcmp(command[0],"lseek") == 0)
            {
                fd = getFdFromName(command[1]);
                if(fd == -1)
                {
                    puts("Incorrect parameters");
                    continue;
                }
                ret = lseekFile(fd,atoi(command[2]),atoi(command[3]));
                if(ret == -1)
                    puts("ERROR : Unable to perform lseek");
                continue;
            }
            else
            {
                puts("ERROR : Command not found!!");
                continue;
            }
        }
        else
        {
            puts("ERROR : Command not found");
            continue;
        }
    }

    return (0);
}

void man(char* name)
{
    if(name == NULL) return;

    if(strcmp(name,"create") == 0)
    {
        puts("Description : Used to create new regular file");
        puts("Usage :       create    file_name    permission");
        return;
    }
    else if(strcmp(name,"read") == 0)
    {
        puts("Description : Used to read data from regular file");
        puts("Usage :       read    file_name    number_of_bytes_to_read");
        return;
    }
    else if(strcmp(name,"write") == 0)
    {
        puts("Description : Used to write into regular file");
        puts("Usage :       write    file_name");
        puts("              After this write data that we want to write");
        return;
    }
    else if(strcmp(name,"ls") == 0)
    {
        puts("Description : Used to list all information of files");
        puts("Usage :       ls");
        return;
    }
    else if(strcmp(name,"stat") == 0)
    {
        puts("Description : Used to display information of file using file name");
        puts("Usage :       stat    file_name");
        return;
    }
    else if(strcmp(name,"fstat") == 0)
    {
        puts("Description : Used to display information of file using file descriptor");
        puts("Usage :       fstat    file_descriptor");
        return;
    }
    else if(strcmp(name,"truncate") == 0)
    {
        puts("Description : Used to remove data from file");
        puts("Usage :       truncate    file_name");
        return;
    }
    else if(strcmp(name,"open") == 0)
    {
        puts("Description : Used to open existing file");
        puts("Usage :       open    file_name    mode");
        return;
    }
    else if(strcmp(name,"close") == 0)
    {
        puts("Description : Used to close opened file");
        puts("Usage :       close    file_name");
        return;
    }
    else if(strcmp(name,"closeall") == 0)
    {
        puts("Description : Used to close all opened files");
        puts("Usage :       closeall");
        return;
    }
    else if(strcmp(name,"lseek") == 0)
    {
        puts("Description : Used to change file offset");
        puts("Usage :       lseek    file_name    change_in_offset    start_point");
        return;
    }
    else if(strcmp(name,"rs") == 0)
    {
        puts("Description : Used to delete the file");
        puts("Usage :       rm    file_name");
        return;
    }
    else
    {
        puts("ERROR : No manual entry available");
    }
}

void displayHelp()
{
    puts("ls :       To list out all files");
    puts("create :   To create new regular file");
    puts("clear :    To clear console");
    puts("open :     To open the file");
    puts("close :    To close the file");
    puts("closeall : To close all opened files");
    puts("read :     To read the contents from file");
    puts("write :    To write contents into file");
    puts("exit :     To terminate file system");
    puts("stat :     To display information of file using name");
    puts("fstat :    To display information of file using file descriptor");
    puts("truncate : To remove all data from file");
    puts("rm :       To delete the file");
}

int getFdFromName(char* name)
{
    int i = 3;
    while(i < MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable != NULL)
            if(strcmp(UFDTArr[i].ptrfiletable->ptrinode->filename,name) == 0)
                break;
        i++;
    }

    return (i);
}

PINODE getInode(char* name)
{
    PINODE temp = head;

    if(name == NULL)
        return (0);

    while(temp != NULL)
    {
        if(strcmp(name,temp->filename) == 0)
            break;
        temp = temp->next;
    }

    return (temp);
}

void createDILB()
{
    int i = 1;
    PINODE newn = NULL;
    PINODE temp = head;

    while(i <= MAXINODE)
    {
        newn = (PINODE)malloc(sizeof(INODE));

        newn->linkcount = 0;
        newn->referencecount = 0;
        newn->filetype = 0;
        newn->filesize = 0;

        newn->buffer = NULL;
        newn->next = NULL;

        newn->inodenumber = i;

        if(temp == NULL)
        {
            head = newn;
            temp = head;
        }
        else
        {
            temp->next = newn;
            temp = temp->next;
        }
        i++;
    }
    puts("Disk Inode List Block created successfully");
}

void initialiseSuperBlock()
{
    int i = 0;
    while(i < MAXINODE)
    {
        UFDTArr[i].ptrfiletable = NULL;
        i++;
    }
    SUPERBLOCKobj.totalinodes = MAXINODE;
    SUPERBLOCKobj.freeinode = MAXINODE;
}

int createFile(char* name, int permission)
{
    int i = 3;
    PINODE temp = head;

    if((name == NULL) || (permission == 0) || (permission > 3))  return (-1);
    if(SUPERBLOCKobj.freeinode == 0)  return (-2);

    (SUPERBLOCKobj.freeinode)--;

    if(getInode(name) != NULL)  return (-3);

    while(temp != NULL)
    {
        if(temp->filetype == 0)
            break;
        temp = temp->next;
    }

    while(i < (MAXINODE+3))
    {
        if(UFDTArr[i].ptrfiletable == NULL)
            break;
        i++;
    }

    UFDTArr[i].ptrfiletable = (PFILETABLE)malloc(sizeof(FILETABLE));

    UFDTArr[i].ptrfiletable->count = 1;
    UFDTArr[i].ptrfiletable->mode = permission;
    UFDTArr[i].ptrfiletable->readoffset = 0;
    UFDTArr[i].ptrfiletable->writeoffset = 0;

    UFDTArr[i].ptrfiletable->ptrinode = temp;

    strcpy(UFDTArr[i].ptrfiletable->ptrinode->filename,name);
    UFDTArr[i].ptrfiletable->ptrinode->filetype = REGULAR;
    UFDTArr[i].ptrfiletable->ptrinode->referencecount = 1;
    UFDTArr[i].ptrfiletable->ptrinode->linkcount = 1;
    UFDTArr[i].ptrfiletable->ptrinode->filesize = MAXFILESIZE;
    UFDTArr[i].ptrfiletable->ptrinode->fileactualsize = 0;
    UFDTArr[i].ptrfiletable->ptrinode->permission = permission;
    UFDTArr[i].ptrfiletable->ptrinode->buffer = (char*)malloc(MAXFILESIZE);

    return (i);
}

int rm_File(char* name)  // rm_File("Demo.txt");
{
    int fd = 0;

    fd = getFdFromName(name);
    if(fd == -1)
        return (-1);

    (UFDTArr[fd].ptrfiletable->ptrinode->linkcount)--;

    if(UFDTArr[fd].ptrfiletable->ptrinode->linkcount == 0)
    {
        UFDTArr[fd].ptrfiletable->ptrinode->filetype = 0;
        free(UFDTArr[fd].ptrfiletable);  // free(UFDTArr[fd].ptrfiletable->ptrinode->buffer);
    }
    UFDTArr[fd].ptrfiletable = NULL;
    (SUPERBLOCKobj.freeinode)++;

    return (fd);
}

int readFile(int fd, char* arr, int iSize)
{
    int read_size = 0;

    if(UFDTArr[fd].ptrfiletable == NULL)  return (-1);

    if((UFDTArr[fd].ptrfiletable->mode != READ) && (UFDTArr[fd].ptrfiletable->mode != READ+WRITE))  return (-2);

    if((UFDTArr[fd].ptrfiletable->ptrinode->permission != READ) && (UFDTArr[fd].ptrfiletable->ptrinode->permission != READ+WRITE))  return (-2);

    if(UFDTArr[fd].ptrfiletable->readoffset == UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize)  return (-3);

    if(UFDTArr[fd].ptrfiletable->ptrinode->filetype != REGULAR)  return (-4);

    read_size = (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize) - (UFDTArr[fd].ptrfiletable->readoffset);
    if(read_size < iSize)
    {
        strncpy(arr,(UFDTArr[fd].ptrfiletable->ptrinode->buffer) + (UFDTArr[fd].ptrfiletable->readoffset),read_size);

        (UFDTArr[fd].ptrfiletable->readoffset) = (UFDTArr[fd].ptrfiletable->readoffset) + read_size;
    }
    else
    {
        strncpy(arr,(UFDTArr[fd].ptrfiletable->ptrinode->buffer) + (UFDTArr[fd].ptrfiletable->readoffset),iSize);

        (UFDTArr[fd].ptrfiletable->readoffset) = (UFDTArr[fd].ptrfiletable->readoffset) + iSize;
    }

    return (iSize);
}

int writeFile(int fd, char* arr, int iSize)
{
    if((UFDTArr[fd].ptrfiletable->mode != WRITE) && (UFDTArr[fd].ptrfiletable->mode != READ+WRITE))  return (-1);

    if((UFDTArr[fd].ptrfiletable->ptrinode->permission != WRITE) && (UFDTArr[fd].ptrfiletable->ptrinode->permission != READ+WRITE))  return (-1);

    if(UFDTArr[fd].ptrfiletable->writeoffset == MAXFILESIZE)  return (-2);

    if(UFDTArr[fd].ptrfiletable->ptrinode->filetype != REGULAR)  return (-3);
    
    strncpy((UFDTArr[fd].ptrfiletable->ptrinode->buffer) + (UFDTArr[fd].ptrfiletable->writeoffset),arr,iSize);  // copied in file (buffer)

    UFDTArr[fd].ptrfiletable->writeoffset = UFDTArr[fd].ptrfiletable->writeoffset + iSize;

    UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize = UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize + iSize;

    return (iSize);
}

int openFile(char* name, int mode)
{
    int i = 0;
    PINODE temp = NULL;

    if(name == NULL || mode <= 0)
        return (-1);

    temp = getInode(name);
    if(temp == NULL)
        return (-2);

    if(temp->permission < mode)
        return (-3);

    while(i < MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable == NULL)
            break;
        i++;
    }

    UFDTArr[i].ptrfiletable = (PFILETABLE)malloc(sizeof(FILETABLE));
    if(UFDTArr[i].ptrfiletable == NULL)  
        return (-1);

    UFDTArr[i].ptrfiletable->count = 1;
    UFDTArr[i].ptrfiletable->mode = mode;
    if(mode == READ+WRITE)
    {
        UFDTArr[i].ptrfiletable->readoffset = 0;
        UFDTArr[i].ptrfiletable->writeoffset = 0;
    }
    else if(mode == READ)
    {
        UFDTArr[i].ptrfiletable->readoffset = 0;
    }
    else if(mode == WRITE)
    {
        UFDTArr[i].ptrfiletable->writeoffset = 0;
    }
    UFDTArr[i].ptrfiletable->ptrinode = temp;
    (UFDTArr[i].ptrfiletable->ptrinode->referencecount)++;

    return (i);
}

void closeFileByName(int fd)
{
    UFDTArr[fd].ptrfiletable->readoffset = 0;
    UFDTArr[fd].ptrfiletable->writeoffset = 0;
    (UFDTArr[fd].ptrfiletable->ptrinode->referencecount)--;
}

int closeFileByName(char* name)
{
    int fd = 0;
    fd = getFdFromName(name);
    if(fd == -1)
        return (-1);

    UFDTArr[fd].ptrfiletable->readoffset = 0;
    UFDTArr[fd].ptrfiletable->writeoffset = 0;
    (UFDTArr[fd].ptrfiletable->ptrinode->referencecount)--;

    return (fd);
}

void closeAllFile()
{
    int i = 0;
    while(i < MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable != NULL)
        {
            UFDTArr[i].ptrfiletable->readoffset = 0;
            UFDTArr[i].ptrfiletable->writeoffset = 0;
            (UFDTArr[i].ptrfiletable->ptrinode->referencecount)--;
            break;
        }
        i++;
    }
}

int lseekFile(int fd, int size, int from)
{
    if((fd < 0) || (from > 2) || (UFDTArr[fd].ptrfiletable == NULL))  return (-1);

    if((UFDTArr[fd].ptrfiletable->mode == READ) || (UFDTArr[fd].ptrfiletable->mode == READ+WRITE))
    {
        if(from == CURRENT)
        {
            if(((UFDTArr[fd].ptrfiletable->readoffset) + size) > UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize)  return (-1);
            if(((UFDTArr[fd].ptrfiletable->readoffset) + size) < 0)  return (-1);
            
            UFDTArr[fd].ptrfiletable->readoffset = (UFDTArr[fd].ptrfiletable->readoffset) + size;
        }
        else if(from == START)
        {
            if(size > (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize))  return (-1);
            if(size < 0)  return (-1);
            
            UFDTArr[fd].ptrfiletable->readoffset = size;
        }
        else if(from == END)
        {
            if(((UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize) + size) > MAXFILESIZE)  return (-1);
            if(((UFDTArr[fd].ptrfiletable->readoffset) + size) < 0)  return (-1);

            UFDTArr[fd].ptrfiletable->readoffset = (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize) + size;
        }
    }
    else if(UFDTArr[fd].ptrfiletable->mode == WRITE)
    {
        if(from == CURRENT)
        {
            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) > MAXFILESIZE)  return (-1);
            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) < 0)  return (-1);
            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) > (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize))
                UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize = (UFDTArr[fd].ptrfiletable->writeoffset) + size;
            
            UFDTArr[fd].ptrfiletable->writeoffset = (UFDTArr[fd].ptrfiletable->writeoffset) + size;
        }
        else if(from == START)
        {
            if(size > MAXFILESIZE)  return (-1);
            if(size < 0)  return (-1);
            if(size > (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize))
                UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize = size;
            
            UFDTArr[fd].ptrfiletable->writeoffset = size;
        }
        else if(from == END)
        {
            if(((UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize) + size) > MAXFILESIZE)  return (-1);
            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) < 0)  return (-1);

            UFDTArr[fd].ptrfiletable->writeoffset = (UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize) + size;
        }
    }

    return (0);
}

void ls_File()
{
    int i = 0;
    PINODE temp = head;

    if(SUPERBLOCKobj.freeinode == MAXINODE)
    {
        puts("ERROR : There are no files");
        return;
    }
    printf("\nFile Name\tInode Number\tFile Size\tLink count\n");
    puts("--------------------------------------------------------");
    while(temp != NULL)
    {
        if(temp->filetype != 0)
            printf("%s\t\t%d\t\t%d\t\t%d\n", temp->filename, temp->inodenumber, temp->fileactualsize, temp->linkcount);
        temp = temp->next;
    }
    puts("--------------------------------------------------------");
}

int fstat_File(int fd)
{
    PINODE temp = head;

    if(fd < 0)  return (-1);
    if(UFDTArr[fd].ptrfiletable == NULL)  return (-2);

    temp = UFDTArr[fd].ptrfiletable->ptrinode;

    printf("\n---------Statistical Information about file----------\n");
    printf("File name : %s\n", temp->filename);
    printf("Inode number : %d\n", temp->inodenumber);
    printf("File size : %d\n", temp->filesize);
    printf("Actual File size : %d\n", temp->fileactualsize);
    printf("Link count : %d\n", temp->linkcount);
    printf("Reference count : %d\n", temp->referencecount);

    if(temp->permission == 1)
        puts("File permission : Read only");
    else if(temp->permission == 2)
        puts("File permission : Write");
    else if(temp->permission == 3)
        puts("File permission : Read & Write");
    printf("-----------------------------------------\n\n");

    return (0);
}

int stat_File(char* name)
{
    PINODE temp = head;

    if(name == NULL)  return (-1);

    while(temp != NULL)
    {
        if(strcmp(name,temp->filename) == 0)
            break;
        temp = temp->next;
    }
    if(temp == NULL)  return (-2);

    printf("\n---------Statistical Information about file----------\n");
    printf("File name : %s\n", temp->filename);
    printf("Inode number : %d\n", temp->inodenumber);
    printf("File size : %d\n", temp->filesize);
    printf("Actual file size : %d\n", temp->fileactualsize);
    printf("Link count : %d\n", temp->linkcount);
    printf("Reference count : %d\n", temp->referencecount);

    if(temp->permission == 1)
        puts("File permission : Read only");
    else if(temp->permission == 2)
        puts("File permission : Write only");
    else if(temp->permission == 3)
        puts("File permission : Read & Write");
    printf("------------------------------------------------------------\n\n");
 
    return (0);
}

int truncate_File(char* name)
{
    int fd = getFdFromName(name);
    if(fd == -1)  return (-1);

    memset(UFDTArr[fd].ptrfiletable->ptrinode->buffer,0,MAXFILESIZE);
    UFDTArr[fd].ptrfiletable->readoffset = 0;
    UFDTArr[fd].ptrfiletable->writeoffset = 0;
    UFDTArr[fd].ptrfiletable->ptrinode->fileactualsize = 0;

    return (0);
}
