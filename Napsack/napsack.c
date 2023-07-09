//PROGRAM TO IMPLEMENT THE KNAPSAC PROBLEM WITH BOTTOM UP APPROACH
// this is only 4 testing and ploting will be updated soon as like warshal

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return (a>b) ? a : b;
}
int t[100][100], v[100], w[100];

void napsack(int n,int m)
{
   int i,j;
	for(i=0;i<n+1;i++)
    {
		for(j=0;j<m+1;j++)
        {
			if (i==0||j==0)
				t[i][j] = 0;
			else if (j<w[i])
				t[i][j] = t[i-1][j];
			else
				t[i][j] = max(t[i-1][j], v[i]+t[i-1][j-w[i]]);
		}
	}
	
	printf("THE MAXIMUM VALUE IS : %d\n",t[n][m]);
	
	printf("THE COMPOSITON IS \n");
	for(i=n;i>0;i--){
		if (t[i][m] != t[i-1][m]){
			printf("%d ",i);
			m = m-w[i];
		}
	}


}
void main(){
    int  n, m, i, j;
	printf("ENTER NO OF ITEMS:\n");
	scanf("%d",&n);
	printf("ENTER THE STACK CAPACITY:\n");
	scanf("%d",&m);
	
	
	printf("WEIGHT\tVALUE\n");
	for(i=1;i<n+1;i++){
		scanf("%d\t%d",&w[i],&v[i]);
	}
	
	napsack(n,m);
}
 
