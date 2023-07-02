//Program to perform analysis of heap sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INITIAL 10
#define FINAL 100
#define INCRE 10
int count = 0;

void printArray(int *arr, int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

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

void heapSort(int *heap, int n, char *name) {
    count = 0;
    FILE *fp = fopen(name, "a"); 
    printf("\nBefore Sorting:\n");
    printArray(heap, n);
    for(int i = (n/2)-1; i>=0; i--) {
        heapify(heap, n, i);
    }

    for(int i = n-1; i>=0; i--) {
        swap(&heap[0], &heap[i]);
        heapify(heap, i, 0);
    }
    printf("\nAfter Sorting:\n");
    printArray(heap, n);
    fprintf(fp, "%d\t%d\n", n, count);
    fclose(fp);
}

void main() {
    int *arr, n;
    system("rm -f *_Case.txt");
    srand(time(NULL));
    for(n = INITIAL; n<=FINAL; n+=INCRE) {
        arr = (int *)malloc(n*sizeof(int));
        //For Best case
        for(int i=0; i<n; i++)
            arr[i] = n-i;
        heapSort(arr, n, "Best_Case.txt");

        //For Worst Case
        for(int i=0; i<n; i++)
            arr[i] = i+1;
        heapSort(arr, n, "Worst_Case.txt");

        //For Average Case
        for(int i=0; i<n; i++)
            arr[i] = rand()%n;
        heapSort(arr, n, "Avg_Case.txt");
    }

    system("gnuplot -p -c cmd.txt"); 
}