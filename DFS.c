/*program to implement the dfs algorithm and to check connectivity and acyclicity with adjacency matrix */

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int graph[MAX][MAX], visited[MAX], isCyclic = 0;
int dfsCount = 0, count = 0;

void dfs(int n, int start, int parent) {
    visited[start] = 1;
    count++;
    printf("--> %c ", start+65);
    for(int i=0; i<n; i++) {
        if(i!=parent && graph[start][i] && visited[i])
            isCyclic = 1;
        if(graph[start][i] && visited[i]==0)
            dfs(n, i, start);
    }
}

void main(){
    int n, start;
    printf("Enter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
    }

    printf("the Adjacency Matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nDFS traversal starting from node %c\n", 65);
    dfs(n, 0, -1);
    dfsCount++;
    if(count == n)
        printf("\nThe Graph is connected\n");
    else {
        printf("\nThe Graph is not connected\n");
        start = 1;
        while(count != n) {
            if(visited[start] != 1) {
                printf("\n");
                dfs(n, start, -1);
                dfsCount++;
            }
            start++;
        }
    }
    printf("\nThe number of components is %d\n", dfsCount);

    if(isCyclic) 
        printf("\nThe graph is cyclic\n");
    else
        printf("\nThe graph is not cyclic\n");
}