#include <conio.h>
#include <iostream>


using namespace std;
 
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},_min,mincost=0,cost[10][10];
 
void main()
{
	int path[100]={0}; //В этот массив будут записываться вершины, по которым составится путь
	int path_index=0;
 
	//setlocale(LC_ALL ,"Russian");

	cin>>n; //Ввод количество вершин

	//Ввод матрицы смежности
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		cin>>cost[i][j];
		if(cost[i][j]==0)
			cost[i][j]=999; //999 больше, чем значения веса каждого из ребер в графе
	}
	visited[1]=1;
	cout<<"\n";
 
	while(ne < n)
	{
		for(i=1,_min=999;i<=n;i++)
		for(j=1;j<=n;j++)
		if(cost[i][j]< _min)
		if(visited[i]!=0)
		{
			_min=cost[i][j];
			a=u=i;
			b=v=j;
		}
		if(visited[u]==0 || visited[v]==0)
		{
			path[path_index]=b;
			path_index++;
			ne++; //вывод
			mincost+=_min;
			visited[b]=1;
 
		}
		cost[a][b]=cost[b][a]=999;
	}
 
 
	cout<<"\n";
 
	cout<<1<<" --> ";
	for (int i=0;i<n-1;i++)
	{
	  cout<<path[i];
	  if (i<n-2) cout<<" --> ";
	}
 
	cout<<mincost; //Минимальная стоимость  
 
	cin.get();
	cin.get();

}
