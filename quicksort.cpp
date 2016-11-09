#include<iostream>
#include<time.h>
using namespace std;
//void quicksort(int low, int high);
//void partition(int low, int high, int& pivotpoint);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void swap(int*, int*);
void printArray(int arr[], int size);
 void TimeSearch();
int main(){
	/*int arr[30] = { 300000, 300000, 200000, 200000, 100000, 100000,
		100000, 80000, 80000, 50000, 50000, 25000, 15000, 15000, 10000, 7500, 7000,
		6000, 5000, 5000, 4500, 4500, 4000, 4000, 3500, 3500, 3000, 3000, 2500, 2500 };
	quickSort(r, 2500,300000);
	
		//int arr[] = { 10, 7, 8, 9, 1, 5 };
		int n = sizeof(arr) / sizeof(arr[0]);
		quickSort(arr, 0, n - 1);
		printf("Sorted array: \n");
		printArray(arr, n);
		return 0;*/
	cout << "quicksort" << endl;
	TimeSearch();

}
/*
void quicksort(int low, int high) {
	int pivotpoint = 0;
	if (high > low) {
		partition(low, high, pivotpoint);
		quicksort(low, pivotpoint - 1);
		quicksort(pivotpoint + 1, high);

	}
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


void partition(int low, int high, int& pivotpoint) {
	int i, j;
	int pivotitem;
	const long S[30] = { 300000, 300000, 200000, 200000, 100000, 100000,
		100000, 80000, 80000, 50000, 50000, 25000, 15000, 15000, 10000, 7500, 7000,
		6000, 5000, 5000, 4500, 4500, 4000, 4000, 3500, 3500, 3000, 3000, 2500, 2500 };
	pivotitem = S[low];
	j = low;
	for(i=low+1;i<=high;i++)
		if (S[j] < pivotitem) {
			j++;
			swap(&S[i], &S[j]);
			int temp;
			temp = *S[i];
			*S[i] = *S[j];
			*S[j] = temp;
		
			/*int temp = S[i];
			S[i] = S[j];
			S[j]=temp;
		}
	pivotpoint = j;
	int temp = S[low];
	S[low] = S[pivotpoint];
	S[pivotpoint] = temp;

}*/
void TimeSearch() {
	int a[3001], n[30]; //3000개의 배열 선언, 횟수 선언
	int r[30] = { 300000, 300000, 200000, 200000, 100000, 100000,
		100000, 80000, 80000, 50000, 50000, 25000, 15000, 15000, 10000, 7500, 7000,
		6000, 5000, 5000, 4500, 4500, 4000, 4000, 3500, 3500, 3000, 3000, 2500, 2500 };
	for (int j = 1; j <= 3000; j++) // a초기화
		a[j] = 3001 - j; //내림차순으로 넣어주기(최악의 경우)

	for (int j = 0; j < 10; j++) {// n값설정
		n[j] = 10 * j; n[j + 10] = 100 * (j + 1); n[j + 20] = 1000 + 200 * (j + 1); //0~100까지는 10씩, 100~1000까지는 100씩, 1000부터 3000까지는 200씩

	}

	cout << "   n   totalTime   runTime" << endl;

	for (int j = 0; j < 30; j++) //시간 계산해주기
	{
		long start, stop;
		start = clock(); //시간측정 시작
		int s = sizeof(a) / sizeof(a[0]);
		for (long b = 1; b <= r[j]; b++)
			quickSort(a, 0, n[j]);
			//quicksort(n[0],n[j]); // 최악의 경우 측정(Selectionsort함수 호출)
		stop = clock(); // 시간측정 끝
		long totalTime = stop - start;
		float runTime = (float)((totalTime) / (CLK_TCK)) / (float)(r[j]); //totalTime 초로 나타내주기,횟수로 나눠주기
		cout << "   " << n[j] << "   " << totalTime << "   " << runTime << endl; //시간 출력
	}
	cout << "Times are in hundredths of a second." << endl;

}



void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	// 가장 뒤에 있는 수를 피벗으로 설정.
	int pivot = arr[high];
	int i = (low - 1);

	// arr 내의 모든 수를 탐색.
	for (int j = low; j <= high - 1; j++)
	{
		// 피벗보다 작은 값들을 뒤로 보낸다.
		if (arr[j] <= pivot)
		{
			// 이 for문을 최초로 실행할 때를 제외하고는
			// 항상 arr[i] < pivot && arr[i+1] > pivot 조건을 만족한다.
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	// 위의 for문이 끝나면 high 위치에 있는 피벗을 i + 1 위치로 옮겨준다.
	// 이로서 i + 1보다 작은 값의 인덱스들를 가진 원소들은 피벗보다 작은 값들을 가지고 있고
	// i + 1보다 큰 값의 인덱스를 가진 원소들은 피벗보다 큰 값들을 가지고 있다.
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		// partition 함수가 실행되면 arr 배열 내에는
		// low ~ pi-1 범위에는 arr[pi] 보다 작은 수들이,
		// pi+1 ~ high 범위에는 arr[pi] 보다 큰 수들이 들어 있게 된다.
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

