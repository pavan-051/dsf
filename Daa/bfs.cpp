#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define V 5
int i,j;
void addedge(int grap[V][V],int start)
{
	bool visited={false};
	int queue[V],front=0,rear=0;
	queue[rear++]=start;
	printf("Nodes reachable from node %d:\n",start);
	while(front<rear)
	{
		int current=queue[front++];
		printf("%d ",current);
		for(int i=0,i<V;i++)
		{
			if(graph[current][i]&&![visited[i]])
			{
				visited[i]=true;
				queue[rear++]=i;
			}
		}
	}
}

