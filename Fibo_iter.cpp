//20150257 윤영빈
#include <iostream>
#include <ctime>

using namespace std;

int fib(int n)
{
	int i;
	int f[n];

	f[0] = 0;

	if (n > 0)
	{
		f[1] = 1;

		for (i = 2; i <= n; i++)
			f[i] = f[i-1] + f[i-2];
	}

	return f[n];
}

void TimeSearch(int num) //시간 측정 함수
{
	int n[10]; 
	const long r[28] = {300000, 300000, 250000, 200000, 200000, 100000, 100000, 90000, 80000, 65000, 50000, 50000, 40000, 30000, 25000, 20000, 15000, 10000, 10000, 8000, 7500, 7000, 6000, 5500, 5000, 4000, 3500, 2500}; //시간 측정시 함수가 실행되는 횟수

	for (int j = 0; j < 10; j++)
	{
		n[j] = 3 * j;
	}

	cout<<"n totalTime runTime"<<endl;

	for (int j = 0; j < 10; j++) //3000까지만 출력하기 위해 28번 반복
	{
		clock_t start, stop;

		start = clock(); 

		for (long b = 1; b <= r[j]; b++) // r배열 횟수 만큼 Search 함수 실행
			fib(n[j]); 

		stop = clock(); 

		clock_t totalTime = stop-start;
		float runTime = (float)(totalTime)/(float)(r[j]); 

		cout<<" "<<n[j]<<" "<<totalTime<<" "<<runTime<<endl;
	}

	cout<<"\nTimes are in hundredths of a second."<<endl;
}

int main()
{
	int num = 50;

	TimeSearch(num); // 시간 측정 함수 실행
}
