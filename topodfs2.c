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
    int *path;
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
  
int stack[10];
int top=-1;
 struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->vertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visit = malloc(vertices * sizeof(int));
  graph->path = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i]= NULL;
    graph->visit[i] = 0;
  }
  return graph;
}


int isparent(struct Graph *graph, int parent, int connect)
{
   if(parent==-1)
   return 0;
    Node temp = graph->adjLists[parent];
    while(temp != NULL)
    {
      if(temp->info==connect)
      return 1;
      temp = temp->next;
    }
    return 0;
  
}
int count=0,iscyclic=0;

void DFS(struct Graph* graph, int vertex,int parent) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;
 
  count++;
  graph->visit[vertex] = 1;
  graph->path[vertex] = 1;

  while (temp != NULL) 
  {
    int connectedVertex = temp->info;
    if (graph->visit[connectedVertex]==1&&graph->path[connectedVertex]==1)
         {
              iscyclic=1;
               return;
         }
      if(graph->visit[connectedVertex] == 0)
           DFS(graph,connectedVertex,vertex);
    
    temp = temp->next;
  }
   graph->path[vertex] =0;
    stack[++top] = vertex;
  
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
       printf("\nVertex %c : ",g->vertices-j-1+65);
       scanf("%d",&key);
       if(key==1)
       {
            Node nn=createnode(g->vertices-j-1);
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
        //printf("abhishek")
       }
     printf("\n");
   }
  int dfscount=0;
   printf("\nDFS TRAVERSAL STARTING FROM NODE %C\n",65);
   DFS(g,0,-1);
   dfscount++;
   int start=1;
       while(count!=g->vertices)
         {
            if(g->visit[start]!=1)
             {
                printf("\n");
                DFS(g,start,-1);
                dfscount++;
             }
             start++;
         }
    if(iscyclic==1)
    {
       printf("\nTHE GRAPH  HAS A  CYCLE \n");
    }
    else
    {
    printf("\nTHE TOPOLOGICAL SORT IS:\n");
    for(int i=0;i<g->vertices;i++)
     printf("-->%c ", stack[i]+65);
    }
  }