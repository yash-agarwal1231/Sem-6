#include <stdio.h>
#include <stdlib.h>
#define MAX_CYL 200

void sort(int arr[], int n)
{
  int i, j, temp;
  for(i = 0; i < n-1; i++){
    for(j = 0; j < n-i-1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }   
  }
}

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

int scan(int head, int direction, int requests[], int nreqs)
{
  int total_movement = 0;
  int i;
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
    total_movement += abs((MAX_CYL - 1) - head);
    head = MAX_CYL - 1;
    printf(" -> %d", head);
    for(int j = i - 1; j >= 0; j--)
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
    total_movement += abs(head - 0);
    head = 0;
    printf(" -> %d", head);
    for(int j = i; j < nreqs; j++)
    {
      total_movement += abs(requests[j] - head);
      head = requests[j];
      printf(" -> %d", head);
    }
  }
  printf("\nTotal Head Movement(Seek Time) = %d\n", total_movement);
  return total_movement;
}

int main()
{
  int requests[200];
  int nreqs, head, direction;
  
  printf("\n");
  printf("================SCAN====================");
  printf("\n\n");
  printf("Enter number of requests: ");
  scanf("%d", &nreqs);
  
  accept_requests(requests, nreqs);
  
  printf("Enter initial head position: ");
  scanf("%d", &head);
  
  printf("Enter direction (1 for right, -1 for left): ");
  scanf("%d", &direction);
  scan(head, direction, requests, nreqs);
  
  return 0;
}
