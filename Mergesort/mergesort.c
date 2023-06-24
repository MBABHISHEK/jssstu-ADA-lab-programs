/* program to implement merge sort and perfrom its analysis*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
void merge(int *arr,int beg,int mid,int end)
{
   int i,j,k;
   int n1=(mid-beg)+1;
   int n2=end-mid;
   int left[n1],right[n2];
   for(i=0;i<n1;i++)
   left[i]=arr[beg+i];
   for(j=0;j<n2;j++)
   right[j]=arr[mid+j+1];
    i=0;j=0;k=beg;
   while(i<n1&&j<n2)
   {
        count++;
       if(left[i]<=right[j])
        arr[k]=left[i++];
       else
        arr[k]=right[j++];
       k++;
   }

    while(i<n1)
    arr[k++]=left[i++];
     while(j<n2)
    arr[k++]=right[j++];

}



void mergesort(int *arr,int beg,int end)
{
    if(beg<end)
    {
     int mid=(beg+end)/2;
     mergesort(arr,beg,mid);
     mergesort(arr,mid+1,end);
     merge(arr,beg,mid,end);
    }
}


void worst(int arr[],int beg,int end)
{
   if(beg<end)
  {
   int mid=(beg+end)/2;
   int i,j,k;
   int n1=(mid-beg)+1;
   int n2=end-mid;
   int a[n1],b[n2];
   for(i=0;i<n1;i++)
   a[i]=arr[(2*i)];
   for(j=0;j<n2;j++)
   b[j]=arr[(2*j)+1];
   
   worst(a,beg,mid);
   worst(b,mid+1,end);
   
  for(i=0;i<n1;i++)
   arr[i]=a[i];
   for(j=0;j<n2;j++)
   arr[j+i]=b[j];
 
  }

}

void main()
{
   int *arr,n;
   srand(time(NULL));
   FILE *f1,*f2,*f3,*f4;
   f1=fopen("MERGESORTBEST.txt","a");
   f2=fopen("MERGESORTWORST.txt","a");
   f3=fopen("MERGESORTAVG.txt","a");
   f4=fopen("WORSTDATA.txt","a");

    for(n=2;n<=1024;n=n*2)
    {
       arr=(int *)malloc(sizeof(int)*n);
      for(int i=0;i<n;i++)
      *(arr+i)=i+1;
       count=0;
      //Best case
      mergesort(arr,0,n-1);
        fprintf(f1,"%d\t%d\n",n,count);
 
     //worst case
      count=0;
      worst(arr,0,n-1);
       for(int i=0;i<n;i++)
      fprintf(f4,"%d ",*(arr+i));
      fprintf(f4,"\n");
      mergesort(arr,0,n-1);
      fprintf(f2,"%d\t%d\n",n,count);

     //AVG case
      for(int i=0;i<n;i++)
      *(arr+i)=rand()%n;
      count=0;
      mergesort(arr,0,n-1);
      fprintf(f3,"%d\t%d\n",n,count);
      free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
}
