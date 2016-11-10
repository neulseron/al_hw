//20150257 윤영빈
#include <iostream>
#include <ctime>

using namespace std;

void SeqSearch(int n, const int *S, int x, int &loc)
{
	loc = 1;

    while (loc <= n && S[loc] != x)
	    loc++;

    if (loc > n)
        loc = 0;
}

void TimeSearch(int *S) //시간 측정 함수
{
	int n[30], loc; 
	const long r[28] = {300000, 300000, 250000, 200000, 200000, 100000, 100000, 90000, 80000, 65000, 50000, 50000, 40000, 30000, 25000, 20000, 15000, 10000, 10000, 8000, 7500, 7000, 6000, 5500, 5000, 4000, 3500, 2500}; //시간 측정시 함수가 실행되는 횟수

	for (int j = 0; j < 10; j++)
	{
		n[j] = 10 * j;
		n[j+10] = 100 * (j+1);
		n[j+20] = 250 * (j+1) + 1000; //3500까지 저장
	}

	cout<<"*** Sequential Search ***"<<endl;
	cout<<"n totalTime runTime"<<endl;

	for (int j = 0; j < 28; j++) 
	{
		clock_t start, stop; 

		start = clock(); 

		for (long b = 1; b <= r[j]; b++) 
			SeqSearch(n[j], S+1, 3000, loc); 

		stop = clock(); 

		clock_t totalTime = stop-start; 
		float runTime = (float)(totalTime)/(float)(r[j]); 

		cout<<" "<<n[j]<<" "<<totalTime<<" "<<runTime<<endl;
	}

	cout<<"\nTimes are in hundredths of a second."<<endl;
}

int main()
{
	int S[3001];

	for (int j = 1; j <= 3000; j++)
	{
		S[j] = j; // S배열에 1부터 3000까지 입력
	}

	TimeSearch(S); // 시간 측정 함수 실행
}
