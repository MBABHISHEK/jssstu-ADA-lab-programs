//Knapsac problem using memory function
#include<stdio.h>
int value[100], weight[100];
int knap[100][100];

int maximum(int a, int b) {
    int max = (a > b) ? a : b;
    return max;
}

int knapsac(int i, int j) {
    int v;
    if(knap[i][j] < 0) {
        if(j<weight[i]) {
            v = knapsac(i-1, j);
        } else {
            v = maximum(knapsac(i-1, j), (value[i-1] + knapsac(i-1, j-weight[i-1])));
        }
    }
    knap[i][j] = v;
    return knap[i][j];
}

int main() {
    int n, capacity;
    printf("\nEnter number of items:\n");
    scanf("%d", &n);
    printf("\nEnter the value and weight of each item:\n");
    printf("Value  Weight\n");
    for(int i=0; i<n; i++) {
        scanf("%d%d", &value[i], &weight[i]);
    }
    printf("\nEnter the maximum capacity of knapsac:\n");
    scanf("%d", &capacity);
    int i, j;
    for(i=0; i<n+1; i++) {
        for(j=0; j<capacity+1; j++) {
            if(i==0 || j==0)
                knap[i][j] = 0;
            else 
                knap[i][j] = -1;
        }
    }
    int sol = knapsac(n, capacity);
    printf("\nThe optimum knapsac value is: %d\n", sol);
    return 0;
}
