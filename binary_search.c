#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int n;
void binarysearch(int  key, int * a)
{
   int low,high,mid;
   low=0;
   high=n-1;

   while(low<high)
   {
      mid=(high+low)/2;

      if(*(a+mid)==key)
         return ;
      else if(*(a+mid)>key)
            high=mid-1;
       else
        low=mid+1;  
   }

  // printf("THE SEARCH IS NOT SUCCESFULL\n");
}

void main()
{
      clock_t st,et;

     FILE *d,*g;
     d=fopen("databinary.txt","a");
     g=fopen("graphbinary.txt","a");
     n=10;
     int k,j;
    // srand(time(NULL));

     for(k=0;k<6;k++)
     {
    int * a=(int *)malloc(sizeof(int)*n);
     for(int i=0;i<n;i++)
      {  *(a+i)=i+1;
          fprintf(d,"%d ",*(a+i));
          // printf(d,"%d ",*(a+i));
      }
        fprintf(d,"\n\n\n");
        st=clock();

          binarysearch(-1,a);

        et=clock();

        double result=(et-st)/CLOCKS_PER_SEC;
        printf(" the %d is %lf\n", n,result);
        fprintf(g,"%d    %lf\n",n,result);
        n=n*10;
     }
    fclose(d);
    fclose(g);


}

