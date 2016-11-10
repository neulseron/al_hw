#include <stdio.h>
#include <math.h>

#define n 4 	// 도시개수
#define min(a, b) ((a) < (b) ? (a) : (b))

const int INF = 99999999;
int W[n][n];	// 가중치 그래프 
int D[n][1<<16];
int cityArr[n];		// 도시 저장 배열
int cities;		// 모든 도시 저장(비트)
int total = 0;
int last;

int travel(int from, int path)	// from : 출발점
{
	int npath, cost;
	int newcost, ans = INF;
	int visited;

	printf("from : %d, path : %d\n", from, path);
	for (int i = 0; i < n; i++)
	{
		if (cityArr[i] & path)		// 출발도시가 아니면
		{
			int to = (int)log2((double)cityArr[i]);		// 다음 목적지 임의 지정
			//visited[to] = 1;
			npath = path & (~cityArr[to]);		// 다음 목적지 제외 도시 저장

			if (npath == 0)		// 그 다음 목적지가 없을 때
			{
				last = to;
				return W[from][to];
			}
			else
				cost = travel(to, npath); 	// 재귀함수 호출

			cost = W[from][to] + cost;
			ans = min(ans, cost);
		}
		//printf("//%d\n", ans);
	}

//	D[from][path] = ans;

	return ans + W[last][from];
}

int main()
{
	int path, cost = 0, ans = INF;

	for (int i = 0; i < n; i++)
		cityArr[i] = 1 << i;	// v1 = 0001, v2 = 0010, ...
	
	for (int i = 0; i < n; i++)
		visited[i] = 0;	

	for (int i = 0; i < n; i++)
		cities |= 1 << i;		// 도시가 4개 일 경우 1111

	printf("가중치 그래프(W) 입력 : ");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &W[i][j]);

	for (int i = 0; i < n; i++)
	{
		path = cities & (~cityArr[i]);
		cost = travel(i, path);
		ans = min(ans, cost);
		D[cityArr[i]][path] = ans;
		printf("%d \n", ans);
	}
}
