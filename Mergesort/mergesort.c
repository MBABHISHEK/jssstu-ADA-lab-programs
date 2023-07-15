/* program to implement merge sort and perfrom its analysis*/
/*TESTER IS USED TO CHECK THE CORRECTNESS OF THE ALGORITH*/
/*PLOTTER IS USED TO PLOT THE GRAPH*/
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

void plotter()
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



void tester()
{
  int *arr, n;
   printf("ENTER THE NUMBER OF ELEMENTS\n");
   scanf("%d",&n);

   arr=(int *)malloc(sizeof(int)*n);
   printf("ENTER THE ELEMENTS OF THE ARRAY\n");
      for(int i=0;i<n;i++)
       scanf("%d",&arr[i]);

  printf("THE ELEMENTS OF THE ARRAY BEFORE SORTING\n"); 
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
    printf("\n");

      mergesort(arr,0,n-1);

      printf("THE ELEMENTS OF THE ARRAY BEFORE SORTING\n"); 
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
       printf("\n");
       printf("\n");
}


void main()
{
    for(;;)
    {
        int key;
        printf("ENTER THE CHOICE \n1.TO TEST \n2.TO PLOT\nO  TO EXIT\n");
        scanf("%d",&key);
         
         switch(key)
         {
           case 1:tester();break;
           case 2:plotter();break;
           default:exit(1);
         } 
    }
}
