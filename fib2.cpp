#include<iostream>
#include<time.h>
using namespace std;
int fib2(int n);
void TimeSearch();
int main() {
	cout << fib2(5) << endl;
	cout << "fibonacci2" << endl;
	TimeSearch();
	return 0;
}
void TimeSearch() {
	//int location = 0;
	//int a[3001],
	int n[30];
	const long r[30] = { 300000,300000,200000,200000,100000,100000,100000,80000,80000,50000,50000,25000,15000,15000,100000,7500,7000,6000,5000,5000,4500,4500,4000,4000,3500,3500,3000,3000,2500,250 };
	//for (int j = 1; j <= 3000; j++)
	//a[j] = 3000 - j;
	for (int j = 0; j < 30; j++) {
		n[j] = j;
		//n[j + 10] = 100 * (j + 1);
		//n[j + 20] = 1000 + 200 * (j + 1);

	}
	cout << "  n  runTime" << endl;
	for (int j = 0; j < 30; j++) {
		long start, stop;
		start = clock()*1000;
		for (long b = 1; b <= r[j]; b++)
			fib2(n[j]);
		stop = clock()*1000;
		long totalTime = stop - start;
		double runTime = (double)((totalTime) / (CLK_TCK)) / (double)(r[j]);
		//printf("run:%e", runTime);
		cout << "  " << n[j] <<"   " << runTime << endl;
	}
	//cout << "Times are in hundredths of a second" << endl;

}

int fib2(int n)
{
	int i;
	int *f = (int *)malloc(sizeof(int)*(n + 1));

	f[0] = 0;
	f[1] = 1;
	for (i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	//cout << "f[" << n << "]=" << f[n] << endl;
	return f[n];
}
