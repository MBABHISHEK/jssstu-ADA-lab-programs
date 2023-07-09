/* program to implement the Warshall's Algorithm*/

#include<stdio.h>
#include<stdlib.h>

int graph[100][100];
int counter=0;
void warshall (int n)
{
    for(int k=1; k<=n; k++) 
    {
        for(int i=1; i<=n; i++) 
        {

            if(graph[i][k]!=0)
            {
                 for(int j=1; j<=n; j++)
                {// graph[i][j] = (graph[i][k] && graph[k][j]));
                  graph[i][j] = (graph[i][j] || (graph[i][k] && graph[k][j]));
                   counter++;
                }
            }
        }
    }
}

void tester() {
    int n, i, j;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
     
    warshall(n);

    printf("\nTransitive closure matrix is:\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}



void ploter(int c)
{

  FILE *f1=fopen("warshalbest.txt","a");
  FILE *f2=fopen("warshallworst.txt","a");
   
    for(int i=1;i<=10;i++)
  {
    int n=i; 
 if(c==1)
{
    for(int i=1;i<=n;i++)
  {
     for(int j=1;j<=n;j++)
    {   
       if(i!=j)
       {
        graph[i][j] =1;
       }
       else
       graph[i][j] =0;
    }
  }
 }

if(c==0)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
         graph[i][j] =0;
    }
    for(int i=1;i<n;i++)
    {
            graph[i][i+1]=1;
    }
     graph[n][1]=1;
}
    /*printf("the input graph is \n");

     for(int i=1; i<=n; i++)
      {
        for(int j=1; j<=n; j++) 
        {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }*/
    counter=0;
    warshall(n);    
    if(c==0)
    fprintf(f1,"%d\t%d\n",n,counter);
    else
    fprintf(f2,"%d\t%d\n",n,counter);
    printf("\n");

    /* printf("\nTransitive closure matrix is:\n");
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }*/

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
