#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

struct file
{
    char name[10];
    int index_block;
    int blocks[MAX];
    int size;
} f[MAX];

int bit[MAX];   // 0 = free, 1 = allocated
int n, count = 0;


void init()
{
    int i;
    printf("Enter number of disk blocks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        bit[i] = 0;

    srand(time(NULL));  
}

void show_bit()
{
    int i;
    printf("Bit Vector: ");
    for(i = 0; i < n; i++)
        printf("%d ", bit[i]);
    printf("\n");
}

void create()
{
    int i, j, b, free_count = 0;

    printf("Enter file name: ");
    scanf("%s", f[count].name);

    printf("Enter File Size (in Blocks): ");
    scanf("%d", &f[count].size);


    for(i = 0; i < n; i++)
        if(bit[i] == 0)
            free_count++;

    if(free_count < f[count].size + 1)
    {
        printf("Not enough free blocks\n");
        return;
    }

    for(i = 0; i < n; i++)
        if(bit[i] == 0)
            break;

    f[count].index_block = i;
    bit[i] = 1;

    for(j = 0; j < f[count].size; j++)
    {
        b = rand() % n;

        if(bit[b] == 1 || b == f[count].index_block || bit[b] == -1)
        {
            j--;   // retry
        }
        else if(j < f[count].size - 1)
        {
            f[count].blocks[j] = b;
            bit[b] = 1;
        }
        else
          {
            f[count].blocks[j] = b;
            bit[b] = -1;
          }
    }

    count++;
    printf("File created successfully\n");
}

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
            bit[f[i].index_block] = 0;

            for(j = 0; j < f[i].size; j++)
                bit[f[i].blocks[j]] = 0;

            for(j = i; j < count - 1; j++)
                f[j] = f[j + 1];

            count--;
            printf("File deleted\n");
            return;
        }
    }
    printf("File not found\n");
}

void show_dir()
{
    int i, j,k,a[50];
    printf("\nFile Name\tFile Size\tIndex Blocks\tBlocks");
    
    for(i = 0; i < count; i++)
      {
        for (j = 0; j<f[i].size; j++){
          a[j] = f[i].blocks[j];
        } 
        printf("\n%s\t\t%d\t\t\t%d\t",f[i].name,f[i].size, f[i].index_block);
        for (k=0; k<f[i].size; k++){
          printf("|%d",a[k]);
       

        }
      }
      printf("\n");
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
            default: printf("Invalid choice\n");
        }
    }
}
