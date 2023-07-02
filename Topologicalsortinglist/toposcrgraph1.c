/*program to implement the topological sorting with dsource removal method on adjacency list */

#include<stdio.h>
 #include<stdlib.h>

int count1,count2,count3;
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


  int stack[100];
  int top=-1;
  struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->vertices = vertices;
  graph->edges=0;
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
int s[100];

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
             count1++;
        }
        count1++;
     }
     for(int i=0;i<graph->vertices;i++)
     {
          if(inq[i]==0)
          {
            temp->r=(temp->r+1)%graph->vertices;
             temp->arr[temp->r]=i;
             temp->cnt=temp->cnt+1;
              flag[i]=1;
             // count2++;
            }
             count2++;
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
    
            count3++;
             if(inq[k]==0&&flag[k]==0)
            {
             temp->r=(temp->r+1)%graph->vertices; 
              temp->arr[temp->r]=k; 
              temp->cnt=temp->cnt+1; 
               flag[k]=1;
              // count2++;
            }
        }
           count3++;
}
/*
if(cnt!=graph->vertices)
{
  printf("Cycles exist no topological sorting possible\n");
}
else
{
  printf("The topological sorting is\n"); 
  for(int i=0;i<graph->vertices;i++)
   printf("%c\t",s[i]+65);
}*/
}


int max(int num1,int num2,int num3)
{
     if(num1>num2&&num1>num3)
      return num1;
    if(num2>num1&&num2>num3)
       return num2;
       return num3;
}

void ploter(int k)
{

   FILE *fdata,*f1,*f2;
   fdata = fopen("GRAPHDATA.txt","a");
   f1=fopen("TSRCWROST.txt","a");
   f2=fopen("TSRCBEST.txt","a");
    for(int i=1;i<=100;i++)
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
  /* for(int i=0;i<g->vertices;i++)
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
*/
   count1=0;
   count2=0;
   count3=0;
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
  int max1= max(count1,count2,count3);
   fprintf(fdata,"%d \t %d\t %d\t%d\n",n+g->edges,count1,count2,count3);
   if(k==0)
    fprintf(f1,"%d \t %d\n",n+g->edges,max1);
    else
    fprintf(f2,"%d \t %d\n",n+g->edges,max1);
   free(g);

}
fclose(fdata);
fclose(f1);
fclose(f2);
}

void main()
{
    for(int i=0;i<2;i++)
    ploter(i);

}