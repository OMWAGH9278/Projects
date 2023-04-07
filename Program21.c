#include <stdio.h>

int main(void)
{
    char crr1[80] = "My Name Is Om Mangesh Wagh";
    int wordsCnt;
    char crr2[6][80];

    wordsCnt = sscanf(crr1,"%s %s %s %s",crr2[0], crr2[1], crr2[2], crr2[3]);

    printf("Number of words are : %d\n", wordsCnt);
    printf("First word : %s\n", crr2[0]);
    printf("Second word : %s\n", crr2[1]);
    printf("Third word : %s\n", crr2[2]);
    printf("Fourth word : %s\n", crr2[3]);

    return (0);
}