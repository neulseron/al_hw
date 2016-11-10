//20150257 윤영빈
#include <iostream>
#include <ctime>

using namespace std;

void partition(int *S, int low, int high, int& pivotpoint)
{
	int i, j;
	int pivotitem;

	pivotitem = S[low];
	j = low;

	for (i = low + 1; i <= high; i++)
	{
		if (S[i] < pivotitem)
		{
			j++;
			swap(S[i], S[j]);
		}
	}

	pivotpoint = j;
	//swap(S[low], S[pivotpoint]);
}

void QuickSort(int *S, int low, int high) 
{
	int pivotpoint;

	if (high > low)
	{
		partition(S, low, high, pivotpoint);
		QuickSort(S, low, pivotpoint - 1);
		QuickSort(S, pivotpoint + 1, high);
	}
}

void TimeSearch(int *S) //시간 측정 함수
{
	int n[30]; //Sort 함수에 넘겨줄 배열의 개수
	int low = 1;
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
			QuickSort(S+1, low, n[j]); //n배열 개수만큼 Sort함수에서 정렬됨

		stop = clock(); //종료 시간


		clock_t totalTime = stop-start; //총 걸린 시간 계산
		float runTime = (float)(totalTime)/(float)(r[j]); //한번 실행되는데 걸린 시간 계산

		cout<<" "<<n[j]<<" "<<totalTime<<" "<<runTime<<endl;
	}

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
