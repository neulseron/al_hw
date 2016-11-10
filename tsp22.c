#include<stdio.h>
#include <stdlib.h>

int W[10][10], cityArr[10], num, cost = 0;

int least(int c)
{
	int nc = 999;
	int min = 999,kmin;
	for (int i = 0; i < num; i++)
	{
		if ((W[c][i] > 0) && (cityArr[i] == 0)) // (가중치 > 0) && (처음 방문하는 도시)
		{
			if (W[c][i] < min)
			{
				min = W[i][c] + W[c][i]; // 
				kmin = W[c][i]; // c에서 i로 가는 가중치
				nc = i; // 도착한 i도시 값 저장
			}
		}
	}
	if(min!=999)
		cost+=kmin;
	return nc;
}
/*
int least(int city)
{
	int min = 999, nc = 999;

	for (int i = 0; i < num; i++)
	{
		if ((W[city][i] < min) && (W[city][i] > 0) && (cityArr[i] == 0))
		// 저장된 값보다 작고, 길이 있고, 처음 방문한 도시
		{
			min = W[city][i]; // 최소인 가중치 값 저장
			nc = i; // 다음 도시 저장
		}
	}

	if (min != 999)
		cost += min;

	return nc;
}
*/
void mincost(int city)
{
	int ncity;

	cityArr[city] = 1; // 방문한 도시 체크

	printf("%d-->", city + 1);

	ncity = least(city);
	
	if (ncity == 999) // 마지막 남은 도시
	{
		ncity = 0;
		printf("%d", ncity + 1);
		cost += W[city][ncity];

		return ;
	}

	mincost(ncity);
}


void put()
{
	printf("\n\nMinimum cost:");
	printf("%d",cost);
}

int main()
{
	printf("도시 개수(num) 입력 : ");
	scanf("%d", &num);

	printf("가중치 그래프(W) 입력 : ");
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			scanf("%d", &W[i][j]);
		cityArr[i] = 0;
	}

	printf("\nThe Path is:\n\n");
	mincost(0);
	put();
	getchar();
}
