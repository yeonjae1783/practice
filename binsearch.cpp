#include<iostream>
#include<time.h>
using namespace std;
void TimeSearch();
void binsearch(int n, int S[], int x);
int main(){
	
	cout << "binsearch Time" << endl;
	TimeSearch();
}
void binsearch(int n, int S[], int x) {
	int low, high, mid;
	low = 1; high = n;
	int location = 0;
	while (low <= high && location == 0) {
		mid = (low + high) / 2;
		if (x == S[mid])
			location = mid;
		else if (x < S[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

}
void TimeSearch() {
	int a[3001];
	int n[30];
	const long r[30] = { 300000,300000,200000,200000,100000,100000,100000,80000,80000,50000,50000,25000,15000,15000,100000,7500,7000,6000,5000,5000,4500,4500,4000,4000,3500,3500,3000,3000,2500,250 };
	for (int j = 1; j <= 3000; j++)
	a[j] = j;
	for (int j = 0; j < 10; j++) {
		n[j] = 10 * j;
		n[j + 10] = 100 * (j + 1);
		n[j + 20] = 1000 + 200 * (j + 1);

	}
	cout << "n   runTime" << endl;
	for (int j = 0; j <30; j++) {
		long start, stop;
		start = clock() * 100000;
		for (long b = 1; b <= r[j]; b++)
			binsearch(n[j],a,4000);
		stop = clock() * 100000;
		long totalTime = (stop - start);
		float runTime = ((float)((totalTime) / (CLK_TCK)) / (float)(r[j]));
		cout << " " << n[j] << "   " << runTime << endl;
	}
	

}
