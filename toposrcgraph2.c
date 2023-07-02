/*program to implement the topological sorting with dsource removal method on adjacency matrix*/

#include<stdio.h>
#include<stdlib.h>
  int count=0;

typedef struct queue
{
int f,r,*arr,cnt;
}QUE;

int s[10];
int count1,count2,count3;

 void indegree(int *a[],int v,int inq[],QUE *temp,int flag[])
{
       for(int i=0;i<v;i++)
     {
       for(int j=0;j<v;j++)
       {
         if(a[j][i]==1)
        inq[i]=inq[i]+1;
        count1++;
       }
          if(inq[i]==0)
          {
            temp->r=(temp->r+1)%v;
             temp->arr[temp->r]=i;
             temp->cnt=temp->cnt+1;
              flag[i]=1;
              count2++;
            }
       }
}

void sourceremove(int *a[],int v,QUE *temp,int inq[],int flag[])
{
int cnt=0; 
while(temp->cnt!=0)
{
  int source=temp->arr[temp->f]; 
   temp->f=(temp->f+1)%v;
   s[cnt]=source;
   temp->cnt=temp->cnt-1; 
    cnt++;
   for(int i=0;i<v;i++)
  {  
    if(a[source][i]==1)
      inq[i]=inq[i]-1; 
      count3++;
      if(inq[i]==0&&flag[i]==0)
     {
       temp->r=(temp->r+1)%v; 
       temp->arr[temp->r]=i; 
       temp->cnt=temp->cnt+1; 
        flag[i]=1;
        count2++;
     }
   }

}

if(cnt!=v)
{
  printf("Cycles exist no topological sorting possible\n");
 //printf("abhishek");
}
else
{

  printf("The topological sorting is\n"); 
  for(int i=0;i<v;i++)
   printf("%c\t",s[i]+65);
  
}
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

     printf("Adjacency matrix\n"); 
   for(int i=0;i<v;i++)
  {
    for(int j=0;j<v;j++)
    {
     printf("%d\t",arr[i][j]);
    }
     printf("\n");
   }

   
printf("\n");
  QUE q;
  q.f=0;
  q.r=-1;
  q.cnt=0;
   q.arr=(int*)malloc(sizeof(int)*v);

  int *inq=(int *)malloc(sizeof(int)*v);
   for(int i=0;i<v;i++)
   inq[i]=0;
 int *flag=(int *)malloc(sizeof(int)*v); 
 for(int i=0;i<v;i++)
 flag[i]=0; 
   count1=0;
   count2=0;
   count3=0;
   indegree(arr,v,inq,&q,flag);
   sourceremove(arr,v,&q,inq,flag);
   printf("%d \t %d\t %d\t%d\n",v,count1,count2,count3);

printf("\n");
}
}

void main()
{
    for(int i=0;i<2;i++)
    ploter(i);
}
