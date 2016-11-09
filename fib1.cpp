#include<iostream>
#include<time.h>
using namespace std;
int fib(int n);
void TimeSearch();
int main(){

	//cout<<fib(7)<<endl;
	cout << "fibonacci1" << endl;
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
	for (int j = 0; j <= 30; j++) {
		n[j] = j;
		//n[j + 10] = 100 * (j + 1);
		//n[j + 20] = 1000 + 200 * (j + 1);

	}
	cout << "  n   runTime" << endl;
	for (int j = 0; j < 30; j++) {
		long start, stop;
		start = clock()*1000;
		for (long b = 1; b <= r[j]; b++)
			fib(n[j]);
		stop = clock()*1000;
		long totalTime = stop - start;
		float runTime = (float)((totalTime) / (CLK_TCK)) / (float)(r[j]);
		cout << "  " << n[j] <<"   " << runTime << endl;
	}
	cout << "Times are in hundredths of a second" << endl;

}

int fib(int n) {
	if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);

}