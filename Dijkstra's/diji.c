#include <stdio.h>
#include <stdlib.h>

struct Vertex {
    int index;
    int distance;
};

void swap(struct Vertex *a, struct Vertex *b) {
    struct Vertex temp = *a;
    *a = *b;
    *b = temp;
}

//this for heapify
void minHeapify(struct Vertex heap[], int size, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && heap[leftChild].distance < heap[smallest].distance)
        smallest = leftChild;

    if (rightChild < size && heap[rightChild].distance < heap[smallest].distance)
        smallest = rightChild;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}


//this used to build the heap
void buildMinHeap(struct Vertex heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        minHeapify(heap, size, i);
}

//this used to get the root and heapify again 
struct Vertex extractMin(struct Vertex heap[], int *size) {
    struct Vertex minVertex = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
    return minVertex;
}

//this for updating the value in the heap if new value is lesser than old value
void decreaseKey(struct Vertex heap[], int index, int newDistance) {
    heap[index].distance = newDistance;
    while (index > 0 && heap[(index - 1) / 2].distance > heap[index].distance) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void dijkstra(int n, int cost[10][10], int s, int dist[10]) {
    int i, count = 0;
    struct Vertex minHeap[10];
    int  visited[10] = { 0 };

    //this for instialization of the each vertex and if it is root then it is 0
    //otherwise it is infinite
    for (i = 1; i <= n; i++) {
        minHeap[i - 1].index = i;
        minHeap[i - 1].distance = (i == s) ? 0 : 999;
    }

    int heapSize = n;
    buildMinHeap(minHeap, heapSize);

    while (count < n) {
        struct Vertex minVertex = extractMin(minHeap, &heapSize);
        int u = minVertex.index;
        visited[u] = 1;
        count++;

        for (i = 1; i <= n; i++) {
            if (!visited[i] && cost[u][i] > 0) {
                int alt = dist[u] + cost[u][i];
                if (alt < dist[i]) {
                    dist[i] = alt;
                    decreaseKey(minHeap, i - 1, alt);
                }
            }
        }
    }
}

int main() {
    int i, j, n, s, cost[10][10], dist[10];

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    printf("Read the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &s);

    for (i = 1; i <= n; i++)
        dist[i] = (i == s) ? 0 : 999;

    dijkstra(n, cost, s, dist);

    printf("Shortest path from %d is:\n", s);
    for (i = 1; i <= n; i++) {
        if (s != i)
            printf("%c -> %c = %d\n", s+65-1, i+65-1, dist[i]);
    }

    return 0;
}