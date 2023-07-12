/*program to implement the topological sorting with dfs on adjacency List */

#include<stdio.h>
#include<stdlib.h>

 struct node
{
   int info;
   struct node *next;
};

int dcount=0;
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
  
int stack[200];
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
     dcount++;
    if (graph->visit[connectedVertex]==1&&graph->path[connectedVertex]==1)
         {
              iscyclic=1;
         }
      if(graph->visit[connectedVertex] == 0)
           DFS(graph,connectedVertex,vertex);
    
    temp = temp->next;
  }
  dcount++;
   graph->path[vertex] =0;
    stack[++top] = vertex;
  
}

void DFS1(struct Graph* graph, int vertex,int parent) {
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



void tester()
{
    int n;
    printf("ENTER THE NUUMBER OF VERTICES\n");
    scanf("%d",&n);
    struct Graph*   g=createGraph(n);
    Node temp;
    int key;
     top=-1;
  
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
  count=0;
  iscyclic=0;
   printf("\nDFS TRAVERSAL STARTING FROM NODE %C\n",65);
   DFS1(g,0,-1);
   dfscount++;
   int start=1;
       while(count!=g->vertices)
         {
            if(g->visit[start]!=1)
             {
                printf("\n");
                DFS1(g,start,-1);
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
    free(g);
  }

void ploter(int k)
{

   FILE *f1,*f2;
   f1=fopen("TOPODFSWROST.txt","a");
   f2=fopen("TOPODFSBEST.txt","a");
    for(int i=1;i<=20;i++)
    {
      int n=i;
    
     struct Graph*   g=createGraph(n);
     Node temp;
     int key;

  
 if(k==0)
  for(int i=0;i<g->vertices;i++)
{

   for(int j=0;j<g->vertices;j++)
  {
       
       if(i!=g->vertices-1-j)
       {
            Node nn=createnode(g->vertices-j-1);
            nn->next = g->adjLists[i];
            g->adjLists[i] = nn;
       }
  }
}

if(k==1)
{
    for(int i=0;i<g->vertices-1;i++)
    {
            Node nn=createnode(i+1);
            nn->next = g->adjLists[i];
            g->adjLists[i] = nn;
    }

}
  count=0;
  dcount=0;
   int dfscount=0;
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

         if(k==0)
         fprintf(f2,"%d\t%d\n",n,count);
         else
          fprintf(f2,"%d\t%d\n",n,count);


           free(g);
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