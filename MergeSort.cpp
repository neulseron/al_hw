//20150257 윤영빈
#include <iostream>
#include <ctime>

using namespace std;

void merge(int h, int m, const int *U, const int *V, int *S)
{
	int i = 1, j = 1, k = 1;

	while (i <= h && j <= m)
	{
		if (U[i] < V[j])
		{
			S[k] = U[i];
			i++;
		}
		else
		{
			S[k] = V[j];
			j++;
		}

		k++;
	}

	if (i > h)
	{
		for (int a = j, b = k; a <= m && b <= h+m; a++, b++)
			S[b] = V[a];
	}
	else
	{
		for (int a = i, b = k; a <= h && b <= h+m; a++, b++)
			S[b] = U[a];
	}
}

void MergeSort(const int n, int *S) 
{
	if (n > 1)
	{
		const int h = n / 2;
		const int m = n - h;
		int U[h+1], V[m+1];

		for (int i = 1; i <= h; i++)
			U[i] = S[i];

		for (int i = h + 1; i <= n; i++)
			V[i-h] = S[i];

		MergeSort(h, U);
		MergeSort(m, V);

		merge(h, m, U, V, S);
	}
}

void TimeSearch(int *S) //시간 측정 함수
{
	int n[30]; //Sort 함수에 넘겨줄 배열의 개수
	const long r[28] = {300000, 300000, 250000, 200000, 200000, 100000, 100000, 90000, 80000, 65000, 50000, 50000, 40000, 30000, 25000, 20000, 15000, 10000, 10000, 8000, 7500, 7000, 6000, 5500, 5000, 4000, 3500, 2500}; //시간 측정시 함수가 실행되는 횟수

	for (int j = 0; j < 10; j++)
	{
		n[j] = 10 * j;
		n[j+10] = 100 * (j+1);
		n[j+20] = 250 * (j+1) + 1000; //3500까지 저장
	}

	cout<<"n totalTime runTime"<<endl;

	for (int j = 0; j < 28; j++) //3000까지만 출력하기 위해 28번 반복
	{
		clock_t start, stop; //시간 측정 변수

		start = clock(); //시작 시간

		for (long b = 1; b <= r[j]; b++) //r배열 횟수 만큼 Sort 함수 실행
			MergeSort(n[j], S+1); //n배열 개수만큼 Sort에서 정렬됨

		stop = clock(); //종료 시간

		clock_t totalTime = stop-start; //총 걸린 시간 계산
		float runTime = (float)(totalTime)/(float)(r[j]); //한번 실행되는데 걸린 시간 계산

		cout<<" "<<n[j]<<" "<<totalTime<<" "<<runTime<<endl;
	}

	cout<<"//"<<endl;
	for(int a = 1; a < 3001; a++)
		cout<<S[a]<<" ";

	cout<<"Times are in hundredths of a second."<<endl;
}

int main()
{
	int S[3001];

	for (int j = 1; j <= 3000; j++)
	{
		S[j] = 3000 - (j - 1);
	}

	TimeSearch(S); //시간 측정 함수 실행
}
