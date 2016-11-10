#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

	static int num; // 도시 총 개수
	static int W[num][num]; // 가중치 그래프

int tsp(int from, int path, int len)
{
	if (len == 1)
	{
		int to = (int)log2(path); // 저장된 도시 위치 알아냄

		return W[from][to];
	}

	if (D[from][path]) // 0이 아니면(= 저장된 값이 있으면)
		return D[from][path];

	double ans = 1000000000000000.0;

	for (int i = 0; i < num; i++)
	{
		if (cityArr[i] & path)
		{
			int node = cityArr[i]; // 목적지
			int npath = (path & ~node); // 목적지 제외 도시
			int to = (int)log2(node); // 다음 목적지

			int cost = tsp(to, npath, len-1);
			double newcost = W[from][to] + cost;

			ans = fmin(ans, newcost);
		}
	}

	D[from][path] = ans;

	return ans;
}

int main()
{
	int npath, result;
	double ans = 1000000000000000.0;

	cout<<"도시 개수 : ";
	cin>>num;

	int cityArr[num];
	for (int i = 0; i < num; i++)
		cityArr[i] = 1 << i; // cityArr[0] : v1, cityArr[1] : v2, ...

	int path = 0; // 경로 구할 도시 모두 저장
	for (int i = 0; i < num; i++)
		path |= 1 << i;

	cout<<"가중치(W) 입력 : ";
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin>>W[i][j];

	int D[num][path];
	memset(D, 0, sizeof(D)); // 0 으로 초기화

	// *** optimal tour ***
	for (int i = 0; i < num; i++)
	{
		npath = (path & ~cityArr[i]); // 출발 도시 제외하고 저장
		result = tsp(i, npath, num - 1);
		ans = fmin(ans, result);
	}

	cout<<ans;
}
