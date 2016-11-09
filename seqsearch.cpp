#include <iostream>
#include <time.h>
using namespace std;
void seqsearch(int, int S[], int);
void TimeSearch();
void printArray(int arr[], int size);
int main() {

	cout << "seqsearch Time"<< endl;
	TimeSearch();
	return 0;
}
void TimeSearch() {
	int a[3001], n[30];
	const long r[30] = { 300000,300000,200000,200000,100000,100000,100000,80000,80000,50000,50000,25000,15000,15000,100000,7500,7000,6000,5000,5000,4500,4500,4000,4000,3500,3500,3000,3000,2500,250 };
	for (int j = 1; j <= 3000; j++)
		a[j] = 3000 - j;
	for (int j = 0; j < 10; j++) {
		n[j] = 10 * j;
		n[j + 10] = 100 * (j + 1);
		n[j + 20] = 1000 + 200 * (j + 1);
		
	}
	cout << "n    runTime" << endl;
	for (int j = 0; j < 30; j++) {
		long start, stop;
		start = clock() * 100000;
		for (long b = 1; b <= r[j]; b++)
			seqsearch(n[j], a, 4000);
		stop = clock() *100000;
		long totalTime = stop - start;
		float runTime = (float)((totalTime) / (CLK_TCK)) / (float)(r[j]);
		cout <<  n[j] << "   " << runTime << endl;
	}
		//cout << "Times are in hundredths of a second" << endl;

	}

	
void seqsearch(int n,  int S[], int x) {
	int location = 0;
	while (location <= n && S[location] != x)
		location++;
	if (location > n)
		location = 0;
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
