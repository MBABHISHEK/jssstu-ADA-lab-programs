/*program to implement the topological sorting with dsource removal method on adjacency list */

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
  int count=0;


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


typedef struct queue
{
int f,r,*arr,cnt;
}QUE;
int s[10];

  void indegree(  struct Graph* graph ,int inq[],QUE *temp,int flag[])
{
    Node adj;
       for(int i=0;i<graph->vertices;i++)
     {
        adj=graph->adjLists[i];
        while(adj!=NULL)
        {
             int k=adj->info;
             inq[adj->info]++;
            adj=adj->next;
        }

     }
     for(int i=0;i<graph->vertices;i++)
     {
          if(inq[i]==0)
          {
            temp->r=(temp->r+1)%graph->vertices;
             temp->arr[temp->r]=i;
             temp->cnt=temp->cnt+1;
              flag[i]=1;
            }
     }
}

void sourceremove( struct Graph* graph,QUE *temp,int inq[],int flag[])
{
int cnt=0; 
while(temp->cnt!=0)
{
  int source=temp->arr[temp->f]; 
   temp->f=(temp->f+1)%graph->vertices;
   s[cnt]=source;
   temp->cnt=temp->cnt-1; 
    cnt++;
    Node adj;
    adj=graph->adjLists[source];
        while(adj!=NULL)
        {
             int k=adj->info;
             inq[k]--;
             adj=adj->next;
    

             if(inq[k]==0&&flag[k]==0)
            {
             temp->r=(temp->r+1)%graph->vertices; 
              temp->arr[temp->r]=k; 
              temp->cnt=temp->cnt+1; 
               flag[k]=1;
            }
        }

          for(int i=0; i<graph->vertices;i++)
      printf("%c-->%d\n",i+65,inq[i]);
}

if(cnt!=graph->vertices)
{
  printf("Cycles exist no topological sorting possible\n");
 //printf("abhishek");
}
else
{

  printf("The topological sorting is\n"); 
  for(int i=0;i<graph->vertices;i++)
   printf("%c\t",s[i]+65);
  
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
       }
     printf("\n");
   }
  QUE q;
  q.f=0;
  q.r=-1;
  q.cnt=0;
   q.arr=(int*)malloc(sizeof(int)*g->vertices);

  int *inq=(int *)malloc(sizeof(int)*g->vertices);
   for(int i=0;i<g->vertices;i++)
   inq[i]=0;
 int *flag=(int *)malloc(sizeof(int)*g->vertices); 
 for(int i=0;i<g->vertices;i++)
 flag[i]=0; 
 
   indegree(g,inq,&q,flag);
   sourceremove(g,&q,inq,flag);

printf("\n");
}