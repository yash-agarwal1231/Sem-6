#include<stdio.h>
#include<stdlib.h>

int n,m;
int Alloc[10][10], Max[10][10], Need[10][10];
int Avail[10], Request[10];
int Work[10];
int Finish[10] = {0};
int Safe[10] = {0};
int proc;

void Accept_matrix(int a[][10])
{
  int i, j;
  for(i=0; i<n; i++)
    for(j=0; j<m; j++)
      scanf("%d", &a[i][j]);
}

void Accept_available(){
  int i;
  printf("Enter Available Resources : \n");
  for(i=0; i<m; i++)
    scanf("%d", &Avail[i]);
}

void Find_need(){
  int i,j;
  for(i=0; i<n; i++)
    for(j=0; j<m; j++)
      Need[i][j] = Max[i][j] - Alloc[i][j];
}

void Display_matrix(){
  int i,j;
  printf("\nAllocation\tMax\t\tNeed\n");
  for(i=0; i<n; i++){
    for(j=0; j<m; j++)
      printf("%d ",Alloc[i][j]);
    printf("\t\t");
    for(j=0; j<m; j++)
      printf("%d ",Max[i][j]);
    printf("\t\t"); 
    for(j=0; j<m; j++)
      printf("%d ",Need[i][j]);
    printf("\n");
  }
  printf("\nAvailable : \n");
  for(j=0; j<m; j++)
      printf("%d ",Avail[j]);
    printf("\n");
}

void Accept_request(){
  int i;
  printf("Enter Process Number : ");
  scanf("%d", &proc);
  printf("Enter Request Vector : \n");
  for(i=0; i<m; i++)
    scanf("%d", &Request[i]);      
}

int Compare_need(int p){
  int j;
  for(j=0; j<m; j++)
    if(Need[p][j] > Work[j])
      return -1;
  return p;
}

void Safety_algo(){
  int i,k, l=0, over=0, pno;
  for(i=0; i<m; i++)
    Work[i] = Avail[i];
  for(i=0; i<n; i++)
    Finish[i] = 0;
  while(!over)
  {
    for(i=0; i<m; i++)
    {
      if(Finish[i] == 0)
      {
      pno = Compare_need(i);
      if(pno >= 0)
        break;
      }
    }
    if(i==n)
    {
      printf("System is Unsafe\n");
      exit(1);
    }
    for(k=0; k<m; k++)
      Work[k] += Alloc[pno][k];
    Finish[pno] = 1;
    Safe[l++] = pno;
    
    if(l>=n)
    {
      printf("\nSafe Sequence: \n");
      for(i=0; i<n; i++)
        printf("P%d ", Safe[i]);
      printf("\n");
      over = 1;
    }
  }
}

void Resource_request_algo()
{
  int i;
  for(i=0; i<m; i++)
  {
    if(Request[i] > Need[proc][i])
    {
      printf("Error: Process Exceeds Maximum Demand\n");
      exit(1);
    }
  }
  for(i=0; i<n; i++)
    if(Request[i] > Avail[i])
    {
      printf("Process must wait - Resources not Available\n");
      exit(1);
    }
    for(i=0; i<m; i++)
    {
      Avail[i] -= Request[i];
      Alloc[proc][i] += Request[i];
      Need[proc][i] -= Request[i];
    }
    Safety_algo();
}

void Bankers_algo()
{
  Resource_request_algo();
}

int main()
{
  int option = 0;
  printf("Enter Number of Processes and Resources: ");
  scanf("%d%d",&n,&m);
  
  do
  {
    printf("\n1: Accept Allocation");
    printf("\n2: Accept Max");
    printf("\n3: Calculate Need");
    printf("\n4: Accept Available");
    printf("\n5: Display Matrices");
    printf("\n6: Accept Request and Apply Banker's Algorithm");
    printf("\n7: Display the Safe Sequence");
    printf("\n8: Exit");
    
    printf("\nEnter Option: ");
    scanf("%d", &option);
    
    switch(option)
    {
      case 1:
        Accept_matrix(Alloc);
        break;
      
      case 2:
        Accept_matrix(Max);
        break;
        
      case 3:
        Find_need();
        break;
        
      case 4:
        Accept_available();
        break;
        
      case 5:
        Display_matrix();
        break;
        
      case 6: 
        Accept_request();
        Bankers_algo();
        break;
      
      case 7:
        Safety_algo();
        break;
      
      case 8:
        printf("\n...Exited...\n");
        exit(0);
        
      default:
        printf("\nInvalid Option\n");
        continue;
    }
    
  }while(option!=8);
  return 0;
}

