#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

struct file
{
    char name[10];
    int start;
    int size;
} f[MAX];

int link[MAX];   // -1 = free, -2 = end of file
int n, count = 0;

void init()
{
    int i;
    printf("Enter number of blocks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        link[i] = -1;

    srand(time(NULL));
}

void show_mem()
{
    int i;
    printf("| ");
    for (i = 0; i < n; i++)
        printf("%d | ",link[i]);
        
    printf("\n");

}

void create()
{
    int i, b, prev = -1, free_blocks = 0;

    if (count >= MAX)
    {
        printf("Directory full\n");
        return;
    }

    printf("Enter file name: ");
    scanf("%s", f[count].name);

    printf("Enter file size: ");
    scanf("%d", &f[count].size);


    for (i = 0; i < n; i++)
    {
        if (link[i] == -1)
            free_blocks++;
    }

    if (free_blocks < f[count].size)
    {
        printf("Not enough free blocks available\n");
        return;
    }

    i = 0;
    while (i < f[count].size)
    {
        b = rand() % n;

        if (link[b] == -1)
        {
            if (i == 0)
                f[count].start = b;
            else
                link[prev] = b;

            prev = b;
            link[b] = -2;
            i++;
        }
    }

    count++;
    printf("File created successfully\n");
}

void delete_file()
{
    char name[10];
    int i, curr, next;

    printf("Enter file name to delete: ");
    scanf("%s", name);

    for (i = 0; i < count; i++)
    {
        if (strcmp(f[i].name, name) == 0)
        {
            curr = f[i].start;

            while (curr != -2)
            {
                next = link[curr];
                link[curr] = -1;
                curr = next;
            }

            for (; i < count - 1; i++)
                f[i] = f[i + 1];

            count--;
            printf("File deleted successfully\n");
            return;
        }
    }

    printf("File not found\n");
}

void show_dir()
{
    int i;
    printf("\nFile\tStart\tSize\n");
    for (i = 0; i < count; i++)
        printf("%s\t%d\t%d\n", f[i].name, f[i].start, f[i].size);
}

int main()
{
    int ch;
    init();

    while (1)
    {
        printf("\n1. Show Memory");
        printf("\n2. Create File");
        printf("\n3. Show Directory");
        printf("\n4. Delete File");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: show_mem(); break;
            case 2: create(); break;
            case 3: show_dir(); break;
            case 4: delete_file(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

