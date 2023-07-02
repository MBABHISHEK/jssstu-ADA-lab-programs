/*heap sort with recursion */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void heapify(int *heap, int n, int root) {
    count++;
    int largest = root;
    int left = 2*root+1;
    int right = 2*root+2;
    if(left < n && heap[left] > heap[largest]) {
        largest = left;
    }
    if(right < n && heap[right] > heap[largest]) {
        largest = right;
    }
    if(largest != root) {
        swap(&heap[root], &heap[largest]);
        heapify(heap, n, largest);
    }
}


void heapSort(int *heap, int n) {
    for(int i = (n/2)-1; i>=0; i--) {
        heapify(heap, n, i);
    }

    for(int i = n-1; i>=0; i--) {
        swap(&heap[0], &heap[i]);
        heapify(heap, i, 0);
    }
}

void main()
{
  
   int *arr,n;
   srand(time(NULL));
   FILE *f1,*f2,*f3;
   
   f1=fopen("HEAPSORTBEST.txt","a");
   f2=fopen("HEAPSORTWORST.txt","a");
   f3=fopen("HEAPSORTAVG.txt","a");
    n=10;
   
    while(n<=30000)
    {
       arr=(int *)malloc(sizeof(int)*(n+1));
       for(int i=0;i<n;i++)
       *(arr+i)=n-i+1;
       count=0;
        //best case
         heapSort(arr,n);
        fprintf(f1,"%d\t%d\n",n,count);
        //printf("abhi");
        //printf("%d\t%d\n",n,count);
 
     //worst case
      count=0;
      for(int i=0;i<n;i++)
      *(arr+i)=i+1;
        heapSort(arr,n);
      fprintf(f2,"%d\t%d\n",n,count);
      //printf("%d\t%d\n",n,count);

     //AVG case
      for(int i=0;i<n;i++)
      *(arr+i)=rand()%n;
      count=0;
      heapSort(arr,n);
      fprintf(f3,"%d\t%d\n",n,count);
      // printf("%d\t%d\n",n,count);

      if(n<10000)
      n=n*10;
      else
      n=n+10000;
      free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
