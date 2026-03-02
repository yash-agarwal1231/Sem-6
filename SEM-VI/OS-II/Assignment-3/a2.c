#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void accept_requests(int requests[], int nreqs)
{
    int i;

    for (i = 0; i < nreqs; i++)
    {
        printf("Enter request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    sort(requests, nreqs);
}

int sstf(int head, int requests[], int nreqs)
{
    int total_movement = 0;
    int count = nreqs;
    int left, right;
    int left_dist, right_dist;
    int direction = 1;
    int i;

    printf("\nSequence: %d", head);

    for (i = 0; i < nreqs; i++)
    {
        if (requests[i] >= head)
            break;
    }

    left = i - 1;
    right = i;

    while (count-- > 0)
    {
        if (left < 0)
        {
            total_movement += abs(requests[right] - head);
            head = requests[right];
            printf(" -> %d", head);
            right++;
        }
        else if (right >= nreqs)
        {
            total_movement += abs(requests[left] - head);
            head = requests[left];
            printf(" -> %d", head);
            left--;
        }
        else
        {
            left_dist = abs(requests[left] - head);
            right_dist = abs(requests[right] - head);

            if (left_dist <= right_dist)
                direction = -1;
            else
                direction = 1;

            if (direction == -1)
            {
                total_movement += left_dist;
                head = requests[left];
                printf(" -> %d", head);
                left--;
            }
            else
            {
                total_movement += right_dist;
                head = requests[right];
                printf(" -> %d", head);
                right++;
            }
        }
    }

    printf("\nTotal Head Movement(Seek Time) = %d\n", total_movement);
    return total_movement;
}

int main()
{
    int requests[200];
    int nreqs, head;
    
    printf("\n");
    printf("=============Shortest Seek Time First (SSTF)==================");
    printf("\n\n");
    printf("Enter number of requests: ");
    scanf("%d", &nreqs);

    accept_requests(requests, nreqs);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    sstf(head, requests, nreqs);

    return 0;
}

