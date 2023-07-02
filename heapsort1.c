
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;
void heap(int *heap, int n) {
    int pi;
    int pv;
    int flag;
    int ci;

    for (int i = n/2;i >= 1;i--) {
        pi = i;
        pv = heap[pi];
        flag = 0;

        while (flag != 1 && 2 * pi <= n) {
            ci = 2 * pi;
            if (ci < n) {
                if (heap[ci + 1] > heap[ci]) {
                    ci = ci + 1;
                }
            }
            if (pv > heap[ci]) {
                flag = 1;
            } else {
                heap[pi] = heap[ci];
                pi = ci;
            }
        }

        heap[pi] = pv;
    }
}

void swap(int *x,int *y)
{
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;

}
void heapify(int *arr,int n)
{
    int pi;
    int pv;
    int flag;
    int ci;
        for (int i = n; i >= 2; i--) {
    swap(&arr[1], &arr[i]);
    pi = 1;
    pv = arr[pi];
    flag = 0;
    
    while (flag != 1 && 2 * pi <= i-1) {
        ci = 2 * pi;
        
        if (ci < i-1) {
            if (arr[ci + 1] > arr[ci]) {
                ci = ci + 1;
            }
        }
        if (pv > arr[ci]) {
            flag = 1;
        } else {
            arr[pi] = arr[ci];
            pi = ci;
        }
    }
    
    arr[pi] = pv;
  }
}


void main()
{
  
   int *arr,n;
   arr=(int *)malloc(sizeof(int)*n+1);
   srand(time(NULL));
   FILE *f1,*f2,*f3;
   n=5;
   for(int i=1;i<=5;i++) 
   arr[i] =i;
   for(int i=1;i<=n;i++)
        printf("%d ",arr[i]);
        printf("\n");
        count=0;
   heap(arr,n);
   for(int i=1;i<=n;i++)
         printf("%d ",arr[i]);
         printf("\n");
   heapify(arr,n);
    for(int i=1;i<=n;i++)
         printf("%d ",arr[i]);
         printf("\n");
    printf("%d\t%d\n",n,count);

   
 
 /*f1=fopen("HEAPSORTBEST.txt","a");
   f2=fopen("HEAPSORTWORST.txt","a");
   f3=fopen("HEAPSORTAVG.txt","a");
    n=10;
   
    while(n<=30000)
    {
         printf("hae\n");
         printf("hai\n");
       arr=(int *)malloc(sizeof(int)*(n+1));
       for(int i=1;i<=n;i++)
       *(arr+i)=n-i+1;
       count=0;
        //wrost case
         heap(arr,n);
        // for(int i=1;i<=n;i++)
        // printf("%d ",arr[i]);
        // printf("\n");
         heapify(arr, n); 
        //  for(int i=1;i<=n;i++)
      //   printf("%d ",arr[i]);
        // printf("abhit\n");
       // fprintf(f2,"%d\t%d\n",n,count);
        //printf("abhi");
        printf("%d\t%d\n",n,count);
 
     //best case
      count=0;
      for(int i=1;i<=n;i++)
      *(arr+i)=i+1;
        heap(arr,n);
         heapify(arr, n); 
      //fprintf(f1,"%d\t%d\n",n,count);
      printf("%d\t%d\n",n,count);

     //AVG case
      for(int i=1;i<=n;i++)
      *(arr+i)=rand()%n;
      count=0;
      heap(arr,n);
      heapify(arr, n); 
      //fprintf(f3,"%d\t%d\n",n,count);
       printf("%d\t%d\n",n,count);

      if(n<10000)
      n=n*10;
      else
      n=n+10000;
      free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);*/
}
