//prims algorithm -MST
#include<stdio.h>
#include<stdlib.h>
void main()
{int u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];
printf("\nenter the no of nodes:");
scanf("%d",&n);
printf("\nenter the advecency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{  scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
   cost[i][j]=999;
}
visited[1]=1;
printf("\n");
while(ne < n)
{  min=999;
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
     if(cost[i][j]<min)
	if(visited[i]!=0 && visited[j]==0)
	{  min=cost[i][j];
	   u=i;
	   v=j;
 	}
     printf("\n Edge %d :(%d %d) cost:%d ",ne++,u,v,min);
     mincost+=min;
     visited[v]=1;
     cost[u][v]=cost[v][u]=999;
}
   printf("\n\tMinimunm cost = %d\n",mincost);
}



/*
enter the no of nodes:5

enter the advecency matrix:
0 9 0 3 2
9 0 1 2 4
0 1 0 3 0
3 2 3 0 5
2 4 0 5 0


 Edge 1 :(1 5) cost:2
 Edge 2 :(1 4) cost:3
 Edge 3 :(4 2) cost:2
 Edge 4 :(2 3) cost:1
        Minimunm cost = 8

*/