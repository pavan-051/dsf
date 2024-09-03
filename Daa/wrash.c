#include<stdio.h>
#define V 5
int i,j,k;
void printmatrix(int reach[V][V])
{
	printf("Transitive Closure Matrix\n");
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			printf("%d ",reach[i][j]);
		}
		printf("\n");
	}
}
void warshall(int graph[V][V])
{
	int reach[V][V];
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			reach[i][j]=graph[i][j];
		}
	}
	for(k=0;k<V;k++)
	{
		for(i=0;i<V;i++)
		{
			for(j=0;j<V;j++){
				reach[i][j]=reach[i][j]||(reach[i][k] && reach[k][j]);
			}
		}
	}
	printmatrix(reach);
	}
	int main()
	{
		int graph[V][V]={
					{1,1,0,1},
					{0,1,1,0},
					{0,0,1,1},
					{0,0,0,1}};
		warshall(graph);
		return 0;
	}
