#include <stdio.h>
#include <string.h>


#define MAX 50


struct file
{
    char name[10];
    int start;
    int size;
} f[MAX];


int bit[MAX];
int n, count = 0;


/* Initialize disk */
void init()
{
    int i;
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        bit[i] = 0;   // 0 = free
}


/* Show bit vector */
void show_bit()
{
    int i;
    printf("Bit Vector: ");
    for(i = 0; i < n; i++)
        printf("%d ", bit[i]);
    printf("\n");
}


/* Create file */
void create()
{
    int i, j, size;
    printf("Enter file name: ");
    scanf("%s", f[count].name);
    printf("Enter file size: ");
    scanf("%d", &size);


    for(i = 0; i <= n - size; i++)
    {
        for(j = i; j < i + size; j++)
            if(bit[j] == 1) break;


        if(j == i + size)
        {
            f[count].start = i;
            f[count].size = size;
            for(j = i; j < i + size; j++)
                bit[j] = 1;
            count++;
            printf("File created\n");
            return;
        }
    }
    printf("No contiguous space available\n");
}


/* Delete file */
void delete_file()
{
    char name[10];
    int i, j;


    printf("Enter file name to delete: ");
    scanf("%s", name);


    for(i = 0; i < count; i++)
    {
        if(strcmp(f[i].name, name) == 0)
        {
            for(j = f[i].start; j < f[i].start + f[i].size; j++)
                bit[j] = 0;


            for(j = i; j < count - 1; j++)
                f[j] = f[j + 1];


            count--;
            printf("File deleted\n");
            return;
        }
    }
    printf("File not found\n");
}


/* Show directory */
void show_dir()
{
    int i;
    printf("\nFile\tStart\tSize\n");
    for(i = 0; i < count; i++)
        printf("%s\t%d\t%d\n", f[i].name, f[i].start, f[i].size);
}


int main()
{
    int ch;
    init();
    while(1)
    {
        printf("\n1. Show Bit Vector");
        printf("\n2. Create File");
        printf("\n3. Show Directory");
        printf("\n4. Delete File");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);


        switch(ch)
        {
            case 1: show_bit(); break;
            case 2: create(); break;
            case 3: show_dir(); break;
            case 4: delete_file(); break;
            case 5: return 0;
        }
    }
}

