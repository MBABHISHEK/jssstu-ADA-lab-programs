#include<stdio.h>
#include<stdlib.h>


int selectionsort(int *a,int n)
{
     int i,j,min,t,f,count=0;
   for(i=0;i<n-1;i++)
   {
       min=i;
    for(j=i+1;j<n;j++)    
     {
         count++;      
         if(*(a+j)<*(a+min))
          min=j;
     }
    
      if(min!=i)
      {
         t=*(a+min);
         *(a+min)=*(a+i);
         *(a+i)=t;

      }

   }

   return count;

}

void plotter()
{
   FILE *f;
     f=fopen("selectionsort.txt", "a");

   int j,count;
   int n=10;
   
   while (n<=30000)
   {
   
        int *a=(int*)malloc(sizeof(int)*n);
      for(int i=0;i<n;i++)
      { 
        *(a+i)=i;
      }
      count=selectionsort(a,n);
      fprintf(f,"%d\t%d\n",n,count);
      printf("%d\t%d\n",n,count);



      if(n<10000)
         n*=10;
       else
       n+=10000;  

   }
}



void main()
{
      plotter();

}