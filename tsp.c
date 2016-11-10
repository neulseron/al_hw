#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_NODE 16
#define min(a,b) ((a)<(b)?(a):(b))

const double INF = MAX_NODE * 1500.0; 
int W[MAX_NODE][MAX_NODE];
int D[MAX_NODE][1 << 16];
int cityArr[MAX_NODE];

int tsp(int from, int path, int len)
{
	if (len == 1) {
		int to = (int)log2(path);

		if (W[from][to] > 0)
			return W[from][to];
		else return -1;
	}

	// 저장한 값을 이용
	if (D[from][path]) {
		return D[from][path];
	}

	double ans = INF;

	for(int i = 1; i < MAX_NODE; i++)
	{
		if (cityArr[i] & path) 
		{
			int node = cityArr[i];
	
			// 새로운 경로는 목적지 node를 제외한 나머지 도시들
			int npath = (path & ~node);
		
			// 다음 목적지 지정. node는 2^n 값만 존재
			int to = (int)log2(node);
		
			// f(N,{N-1,N-2...1}) = W[N][N-1] + f(N-1, {N-2,N-3...1})
			int fcost = tsp(to, npath, len-1);
			int newcost;
			if (W[from][to] > 0)
				newcost = W[from][to] + fcost;
else 

			ans = min(ans, newcost);
		}
	}

	// 최소비용을 저장
	D[from][path] = ans;

	return ans;
}

int main()
{
	//int t; 
	int num;

	// bit에서의 도시 위치를 배열에 저장
	// bit[1] = 0000 0001 ==> 1번 도시를 표시
	// bit[2] = 0000 0010 ==> 2번 도시를 표시
	// bit[3] = 0000 0100 ==> 3번 도시를 표시
	//...
	for(int i = 1; i < MAX_NODE; i++) {
		cityArr[i] = 1<<i;
	}

	//scanf("%d", &t);
	printf("Enter num(도시 개수) : ");
	scanf("%d", &num);

//	while(t--)
//	{
		// 도시간 비용 입력
		printf("Enter W(가중치 그래프) : ");
		for(int i = 1; i <= num; i++) 
		{
			for(int j = 1; j <= num; j++) {
				scanf("%lf", &W[i][j]);
			}
		}

		double ans = INF, result = 0.0; 

		memset(D, 0, sizeof(D));

		int path = 0;
		// 경로 저장. path에는 모든 도시가 저장됨
		for(int i = 1; i <= num; i++) 
		{
			path |= 1<<i;
		}
		// 출발지점을 차례대로 바꿔서 해를 구한다.
		for(int i=1; i<=num; i++) {
			int npath = (path & ~cityArr[i]);
			result = tsp(i, npath, num-1);
			ans = min(ans, result);
		}

		printf("%lf\n", ans);
//	}

	return 0;
}
