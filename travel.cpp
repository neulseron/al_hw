#include <iostream>
#include <cmath>

using namespace std;

void travel(int n, const int W[][])
{
	int i, j, k;
	int D[n][pow(2, n-1)];

	for(i = 2; i <= n; i++)
		D[i][0] = W[i][1]; // 0일때 공집합

	for(k = 1; k <= n-2; k++)
	{
		for(int l = 1; l <= n-1; l++)
		{
			for()
			{
			}
		}
	}
}

int main()
{
	int W[4][4] = {{0, 2, 9, -1}, {1, 0, 6, 4}, {-1, 7, 0, 8}, {6, 3, -1, 0}};
}
