#include <cstdio>
#include <cmath>
#include <algorithm>

#define MAX_CITY 10
#define MAX_VALUE 987654321.0
#define INF 999999

using namespace std;

int n;	// 도시 개수
int D[MAX_CITY][512], P[MAX_CITY], W[MAX_CITY][MAX_CITY]; 	// 512 : 1 << (MAX_CITY -1)

int TSP(int cur, int visited, int order) // cur : 현재 방문한 도시, visited : 방문한 도시가 체크된 값, order : 방문한 순서
{
	P[order] = cur;

	if (visited == (1 << n) - 1)	// 전부 방문했으면
		return W[cur][0];	// 마지막 도시에서 처음 도시로 가는 값

	int& minlength = D[cur][visited];
	if (minlength != 0)
		return minlength;
	minlength = MAX_VALUE;
	
	for (int next = 0; next <= n; next++)
	{
		if (visited & (1 << next)) continue;	// 이미 방문한 도시면
		if (W[cur][next] == 0 || W[cur][next] == INF) continue;	// 자기 자신일때, 길이 없을 때
		
		minlength = min(minlength, TSP(next, visited | (1 << next), order + 1) + W[cur][next]); // visited | (1 << next) : 방문한 도시 체크
	}

	return minlength;
}

int main()
{
	int path;

	printf("도시 개수(n) 입력 : ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		path |= 1 << i;

	printf("가중치 그래프(W) 입력 : ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &W[i][j]);

			if (W[i][j] == -1)
				W[i][j] = INF;
		}
	}

	path = path & (~1);
	printf("\n*** 최적 일주 여행길(v1 출발) : %d\n", TSP(0, 1, 0));
	
	printf("*** 경로 출력 : ");
	for (int i = 0; i < n; i++)
		printf("(%d)-->", P[i]+1);
	printf("(1)\n");
}
