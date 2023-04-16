#include<stdio.h>
#include<time.h>
#include<stdlib.h>



void bubble(int n, int * a)
{
   int i,j,temp ,count=0;
    for(i=0;i<n-1;i++)
    {
         count=0;
        for(j=0;j<n-i-1;j++)
        {
            if(*(a+j)>*(a+j+1))
            {
                count++;
                temp=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=temp;
            }
        }
        if(count==0)
        break;
    }
}

void main()
{
      clock_t st,et;

     FILE *d,*g;
     d=fopen("data.txt","a");
     g=fopen("graph.txt","a");
     int n=10;
     int k,j;
     for(k=0;k<5;k++)
     {
    int * a=(int *)malloc(sizeof(int)*n);
     for(int i=0;i<n;i++)
      {  *(a+i)=n-i;
          fprintf(d,"%d ",*(a+i));
      }
        fprintf(d,"\n\n\n");
        st=clock();

        bubble(n,a);

        et=clock();

        double result=(et-st)/CLOCKS_PER_SEC;
        printf(" the %d is %lf\n", n,result);
        fprintf(g,"%d    %lf\n",n,result);
        n=n*10;
    

     

     }



    fclose(d);
    fclose(g);


}

/*
void bubble(int n, int * a)
{
   int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(*(a+j)>*(a+j+1))
            {
                temp=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=temp;
            }
        }
    }


}*/
