/*program to implement the dfs algorithm and to check connectivity and acyclicity with adjacency matrix */

#include<stdio.h>
#include<stdlib.h>

int graph[100][100], visited[100], isCyclic = 0;
int dfsCount = 0, count = 0;
int dcount=0;

void dfs(int n, int start, int parent) {
    visited[start] = 1;
    count++;
    printf("--> %c ", start+65);
    for(int i=0; i<n; i++) {
        if(i!=parent && graph[start][i] && visited[i])
            isCyclic = 1;
            dcount++;
        if(graph[start][i] && visited[i]==0)
            dfs(n, i, start);
    }
}

void dfs1(int n, int start, int parent) {
    visited[start] = 1;
    count++;
    for(int i=0; i<n; i++) {
        if(i!=parent && graph[start][i] && visited[i])
            isCyclic = 1;
            dcount++;
        if(graph[start][i] && visited[i]==0)
            dfs1(n, i, start);
    }
}


void tester(){
    int n, start;
    dfsCount = 0;
     count = 0;
      dcount=0;
    printf("Enter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
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
    isCyclic =0;
    printf("\nDFS traversal starting from node %c\n", 65);
    dfs(n, 0, -1);
    dfsCount++;
    if(count == n)
        printf("\nThe Graph is connected\n");
    else {
        printf("\nThe Graph is not connected\n");
        start = 1;
        while(count != n) {
            if(visited[start] != 1) {
                printf("\n");
                dfs(n, start, -1);
                dfsCount++;
            }
            start++;
        }
    }
    printf("\nThe number of components is %d\n", dfsCount);

    if(isCyclic) 
        printf("\nThe graph is cyclic\n");
    else
        printf("\nThe graph is not cyclic\n");
}


void ploter(int k)
{
    int v;
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
    isCyclic=0;
     dfsCount = 0;
     count = 0;
     dcount=0;
    dfs1(v, 0, -1);
    dfsCount++;
    int start;
        start = 1;
        while(count != v) {
            if(visited[start] != 1) {
                dfs1(v, start, -1);
                dfsCount++;
            }
            start++;
        }

        printf("%d\t%d\n",v,dcount);
    


  }

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