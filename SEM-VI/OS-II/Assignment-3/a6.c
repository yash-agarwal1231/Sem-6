/*
C-LOOK Disk Scheduling
Head moves in one direction servicing requests.
After the last request, it jumps to the first request
on the other side and continues.
*/

#include <stdio.h>
#include <stdlib.h>

/* Sort requests in ascending order */
void sort(int arr[], int n)
{
    int i, j, temp;
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

/* Accept disk requests */
void accept_requests(int requests[], int nreqs)
{
    int i;
    for(i = 0; i < nreqs; i++)
    {
        printf("Enter request %d: ", i+1);
        scanf("%d", &requests[i]);
    }
    sort(requests, nreqs);
}

/* C-LOOK scheduling logic */
int c_look(int head, int direction, int requests[], int nreqs)
{
    int total_movement = 0, i;

    printf("\nSequence: %d", head);

    for(i = 0; i < nreqs; i++)
        if(requests[i] >= head)
            break;

    if(direction == 1)
    {
        for(int j = i; j < nreqs; j++)
        {
            total_movement += abs(requests[j] - head);
            head = requests[j];
            printf(" -> %d", head);
        }

        if(i > 0)
        {
            total_movement += abs(head - requests[0]);
            head = requests[0];
            printf(" -> %d", head);
        }

        for(int j = 1; j < i; j++)
        {
            total_movement += abs(requests[j] - head);
            head = requests[j];
            printf(" -> %d", head);
        }
    }
    else
    {
        for(int j = i - 1; j >= 0; j--)
        {
            total_movement += abs(requests[j] - head);
            head = requests[j];
            printf(" -> %d", head);
        }

        if(i < nreqs)
        {
            total_movement += abs(head - requests[nreqs-1]);
            head = requests[nreqs-1];
            printf(" -> %d", head);
        }

        for(int j = nreqs - 2; j >= i; j--)
        {
            total_movement += abs(requests[j] - head);
            head = requests[j];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Head Movement = %d\n", total_movement);
    return total_movement;
}

int main()
{
    int requests[200], nreqs, head, direction;

    printf("Enter number of requests: ");
    scanf("%d", &nreqs);

    accept_requests(requests, nreqs);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1 for right, -1 for left): ");
    scanf("%d", &direction);

    c_look(head, direction, requests, nreqs);

    return 0;
}