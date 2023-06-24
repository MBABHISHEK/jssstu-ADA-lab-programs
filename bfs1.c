/*program to implement the bfs algorithm and to check connectivity and acyclicity with adjacency list */

#include<stdio.h>
#include<stdlib.h>

 struct node
{
   int info;
   struct node *next;
};
struct Graph{
   int vertices;
   int edges;
    int * visit;
    struct node ** adjLists;
};
  typedef struct node * Node;
  Node createnode(int n)
  {
     Node nn=(Node)malloc(sizeof(struct node));
     nn->info=n;
     nn->next=NULL;
    return nn;
  }

 struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->vertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visit = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i]= NULL;
    graph->visit[i] = 0;
  }
  return graph;
}

int count=0,iscyclic=0;
int ordercount=0;
void bfs(struct Graph* graph, int start)
{
    int queue[15], parent[15];
    int rear = -1, front = -1, i, parentNode;
    graph->visit[start] = 1; 
    count++;
    queue[++rear] = start;
    parent[rear] = -1;
    while(rear != front){
        start = queue[++front];
        parentNode = parent[front];
        printf("-->%c", start+65);
         Node temp = graph->adjLists[start];
        while (temp !=NULL){
        {
            int connectedVertex = temp->info;
            ordercount++;
            if (connectedVertex != parentNode&& graph->visit[connectedVertex])
                iscyclic = 1;
            if(graph->visit[connectedVertex]==0){
                queue[++rear] = connectedVertex;
                parent[rear] = start;
                graph->visit[connectedVertex] = 1;
                count++;
            }
             temp = temp->next;
        }
    }
}
} 

void main()
{
    int n;
     printf("ENTER THE NUUMBER OF VERTICES\n");
    scanf("%d",&n);
   struct Graph*   g=createGraph(n);
   Node temp;
  int key;

  
printf("Enter the adjacency LIST \n");
  for(int i=0;i<g->vertices;i++)
{
  printf("Enter 1 for the vertices adjacent to vertex %c\n",i+65); 
   for(int j=0;j<g->vertices;j++)
  {
       printf("\nVertex %c : ",j+65);
       scanf("%d",&key);
       if(key==1)
       {
            Node nn=createnode(j);
            nn->next = g->adjLists[i];
            g->adjLists[i] = nn;
    
       }
  }
}

    
   for(int i=0;i<g->vertices;i++)
  {
     temp=g->adjLists[i];
     printf("THE VERTEX ADJACENT TO %c : ",i+65);
      while(temp!=NULL)
       {
        printf("%c ",temp->info+65);
        temp=temp->next;
       }
     printf("\n");
   }
  int bfscount=0;
   printf("BFS TRAVERSAL STARTING FROM NODE %C\n",65);
   bfs(g,0);
    bfscount++;
   if(count==g->vertices)
    printf("the graph is connected \n");
    else
    {
    printf("\nthe graph is not connected ");
        int start=1;
       while(count!=g->vertices)
         {
            if(g->visit[start]!=1)
             {
                printf("\n");
                bfs(g,start);
                bfscount++;
             }
             start++;
         }

    }


    printf("\nTHE NUMBER OF CONNECTED COMPONENTS ARE %d\n",bfscount);
    if(iscyclic) 
    printf("the graph is cyclic\n");
    else
    printf("the graph is not cyclic\n");
}