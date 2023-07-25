/*program to implement BFS to check connectivity and acyclicity for the adjacency matrix*/

#include<stdio.h>
#include<stdlib.h>
int bfsCount = 0, cyclic=0;
int count = 0;//to count how many vertex visited 
int orderCount = 0;

int graph[100][100], visited[100];

void bfs(int n, int start){
    int queue[n], parent[n];
    int rear = -1, front = -1, i, parentNode;
    visited[start] = 1; count++;
    queue[++rear] = start;
    parent[rear] = -1;
    while(rear != front){
        start = queue[++front];
        parentNode = parent[front];
        printf("-->%c", start+65);
        for(i=0; i<n; i++){
            orderCount++;
            if (i != parentNode && graph[start][i] && visited[i])
                cyclic = 1;
            if((graph[start][i]) && (visited[i] == 0)){
                queue[++rear] = i;
                parent[rear] = start;
                visited[i] = 1;
                count++;
            }
        }
    }
}


void bfs1(int n, int start){
    int queue[n], parent[n];
    int rear = -1, front = -1, i, parentNode;
    visited[start] = 1; count++;
    queue[++rear] = start;
    parent[rear] = -1;
    while(rear != front){
        start = queue[++front];
        parentNode = parent[front];
        for(i=0; i<n; i++){
            orderCount++;
            if (i != parentNode && graph[start][i] && visited[i])
                cyclic = 1;
            if((graph[start][i]) && (visited[i] == 0)){
                queue[++rear] = i;
                parent[rear] = start;
                visited[i] = 1;
               // count++;
            }
        }
    }
}
void tester(){
    int n, i, j, start;
    printf("Enter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0; 
    }

     printf("the Adjacency Matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
     bfsCount = 0, cyclic=0;
count = 0;
 orderCount = 0;
    printf("Breadth First Search Traversal:\n");
    bfsCount++;
    bfs(n, 0);
    if(count == n){
        printf("\nGraph is connected.\n");
    }
    else {
        printf("\nThe graph is not connected.\n");
        start = 1;
        while(count != n){
            if(visited[start] != 1) {
                bfsCount++;
                bfs(n, start);
                printf("\n");
            }
            start++;
        }
    }
    printf("\nThe number of components in the graph is %d\n", bfsCount);
    if(cyclic) {
        printf("\nThe graph is cyclic\n");
    } else {
        printf("\nThe graph is acyclic\n");
    }
}




void ploter(int k)
{

    FILE *f1= fopen("BFSBEST.txt", "a");
    FILE *f2=fopen("BFSWOSR.txt", "a");
    int v,start;
    for(int i=1;i<=10;i++)
  {
    v=i;
  int *arr[v];
  for(int i=0;i<v;i++)
  arr[i]=(int *)malloc(sizeof(int)*v); 


 if(k==0)
 {
  for(int i=0;i<v;i++)
{

   for(int j=0;j<v;j++)
  {
       
       if(i!=j)
       {
        arr[i][j] =1;
       }
       else
       arr[i][j] =0;
  }
}
 }

if(k==1)
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
         arr[i][j] =0;
    }
    for(int i=0;i<v-1;i++)
    {
            arr[i][i+1]=1;
    }

}

    bfsCount = 0, cyclic=0;
    count = 0;
    orderCount = 0;
    bfsCount++;
    bfs1(v, 0);
    if(count != v){
        start = 1;
        while(count != v){
            if(visited[start] != 1) {
                bfsCount++;
                bfs1(v, start);
            }
            start++;
        }
    }
           if(k==0)
         fprintf(f2,"%d\t%d\n",v,orderCount);
         else
          fprintf(f1,"%d\t%d\n",v,orderCount);
         // printf("%d\t%d\n",v,orderCount);


  }

  fclose(f1);
  fclose(f2);

}


void main()
{
    for(;;)
    {
        int key;
        printf("ENTER THE CHOICE 1.TO TEST \n2.TO PLOT\nOTHER TO EXIT\n");
        scanf("%d",&key);
         
         switch(key)
         {
           case 1:tester();break;
           case 2:for(int i=0;i<2;i++)
                   ploter(i);
                   break;
           default:exit(1);
         } 

    }
}
