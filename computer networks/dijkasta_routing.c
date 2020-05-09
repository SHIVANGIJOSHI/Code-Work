#include<stdio.h>
#define INFINITY 9999
#define MAX 10
 
void dijikstra(int G[MAX][MAX], int n, int startnode);
 
void main(){
	int G[MAX][MAX];
        int i, j, n, u;
	printf("\nEnter the no. of vertices:: ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix::\n");
	for(i=1;i <=n;i++)
		for(j=1;j <=n;j++)
			scanf("%d", &G[i][j]);
	printf("\nEnter the starting node:: ");
	scanf("%d", &u);
	dijikstra(G,n,u);
	
}
 
void dijikstra(int G[MAX][MAX], int n, int startnode)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i,j,k;
	for(i=1;i <=n;i++)
		for(j=1;j <=n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	for(i=1;i<=n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
        printf("\n adjacency matrix of cost of edges\n");
       for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
       {
         printf("%d\t",cost[i][j]);
       }
         printf("\n");
       }
//lowest adj matrix
	while(count < n-1){
		mindistance=INFINITY;
		for(i=1;i <=n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=1;i <=n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
 
   
	//path
      		for(i=1;i <=n;i++)
		if(i!=startnode)
		{
			printf("\nDistance to %d : %d", i, distance[i]);
			printf("\nPath : %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=startnode);
		}
 printf("\n adjacency matrix of lowest cost between the vertices\n");
  for(k=1;k<=n;k++)
    { for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
         {if(cost[i][j]>cost[i][k]+cost[k][j])
            cost[i][j]=cost[i][k]+cost[k][j];
         }
       }
    }  

for(i=1;i<=n;i++)
    {for(j=1;j<=n;j++)
     {
      printf("%d\t",cost[i][j]);
     }
      printf("\n");
    }
      
    
}
 
