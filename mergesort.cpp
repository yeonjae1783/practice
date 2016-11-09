
#include <iostream>
#include<time.h>
using namespace std;


void merge(int h, int m, int *Left, int *Right, int *mergeArray);
void mergeSort(int n, int *Array);
void TimeSearch();

void main()
{
	
	TimeSearch();
	
}
void TimeSearch() {
	int a[3001], n[30]; //3000개의 배열 선언, 횟수 선언
	const long r[30] = { 300000, 300000, 200000, 200000, 100000, 100000,
		100000, 80000, 80000, 50000, 50000, 25000, 15000, 15000, 10000, 7500, 7000,
		6000, 5000, 5000, 4500, 4500, 4000, 4000, 3500, 3500, 3000, 3000, 2500, 2500 };
	for (int j = 1; j <= 3000; j++) // a초기화
		a[j] = 3001 - j; //내림차순으로 넣어주기(최악의 경우)
	for (int j = 0; j < 30; j++) {// n값설정
		n[j] =  j; 
		//n[j + 10] = 100 * (j + 1);
		//n[j + 20] = 1000 + 200 * (j + 1); //0~100까지는 10씩, 100~1000까지는 100씩, 1000부터 3000까지는 200씩

	}

	printf("   n     runTime\n");

	for (int j = 0; j < 30; j++) //시간 계산해주기
	{
		long start, stop;
		start = clock()*100; //시간측정 시작
		for (long b = 1; b <= r[j]; b++)
			mergeSort( n[j],a+1); // 최악의 경우 측정(Selectionsort함수 호출)
		stop = clock()*100; // 시간측정 끝
		long totalTime = stop - start;
		float runTime = (float)((totalTime) / (CLK_TCK)) / (float)(r[j]); //totalTime 초로 나타내주기,횟수로 나눠주기
		cout << " " << n[j] << "   " << runTime << endl;
		//printf(" %d %lf %lf \n ", n[j],totalTime, runTime); //시간 출력
	}
	//cout << "Times are in hundredths of a second." << endl;

}
void mergeSort(int n, int *sortingArray)
{

	int h = n / 2;
	int m = n - h;

	int *Left = (int*)malloc(sizeof(int) * h);

	int *Right = (int*)malloc(sizeof(int) * m);

	if (n > 1)
	{
		for (int i = 0; i<h; i++)
		{
			Left[i] = sortingArray[i];
		}
		for (int i = 0; i<m; i++)
		{
			Right[i] = sortingArray[i + h];
		}

		mergeSort(h, Left);
		mergeSort(m, Right);
		merge(h, m, Left, Right, sortingArray);
	}
}

void merge(int h, int m, int *Left, int *Right, int *mergeArray)
{
	int i, j, k;
	i = 0; j = 0; k = 0; //i는 Left[]의 플래그, j는 Right[]의 플래그. k는 Array[]의 플래그

	while (i<h && j<m)
	{
		if (Left[i] < Right[j]) {
			mergeArray[k] = Left[i];
			i++;
		}
		else {
			mergeArray[k] = Right[j];
			j++;
		}

		k++;
	}
	if (i >= h) {
		while (j < m) {
			mergeArray[k] = Right[j];
			k++;
			j++;
		}
	}
	else {
		while (i < h) {
			mergeArray[k] = Left[i];
			k++;
			i++;
		}
	}

}
