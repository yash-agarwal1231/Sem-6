#include <stdio.h>
#include <stdlib.h>
void accept_requests(int requests[], int nreqs)
{
  int i;
  for(i = 0; i < nreqs; i++)
  {
    printf("Enter request %d: ", i+1);
    scanf("%d", &requests[i]);
  }
}
int fcfs(int head, int requests[], int nreqs)
{
  int i, total_movement = 0;
  printf("\nSequence: %d", head);
  for(i = 0; i < nreqs; i++)
  {
    total_movement += abs(requests[i] - head);
    head = requests[i];
    printf(" -> %d", head);
  }
  printf("\nTotal Head Movement = %d\n", total_movement);
  return total_movement;
}
int main()
{
  int requests[200];
  int nreqs, head;
 
  printf("\n");
  printf("=============First Cum First Serve (FCFS)=================");
  printf("\n\n");
  printf("Enter number of requests: ");
  scanf("%d", &nreqs);
  
  accept_requests(requests, nreqs);
  
  printf("Enter initial head position: ");
  scanf("%d", &head);
  
  fcfs(head, requests, nreqs);
  
return 0;
}
