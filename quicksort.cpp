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
	int a[3001], n[30]; //3000���� �迭 ����, Ƚ�� ����
	int r[30] = { 300000, 300000, 200000, 200000, 100000, 100000,
		100000, 80000, 80000, 50000, 50000, 25000, 15000, 15000, 10000, 7500, 7000,
		6000, 5000, 5000, 4500, 4500, 4000, 4000, 3500, 3500, 3000, 3000, 2500, 2500 };
	for (int j = 1; j <= 3000; j++) // a�ʱ�ȭ
		a[j] = 3001 - j; //������������ �־��ֱ�(�־��� ���)

	for (int j = 0; j < 10; j++) {// n������
		n[j] = 10 * j; n[j + 10] = 100 * (j + 1); n[j + 20] = 1000 + 200 * (j + 1); //0~100������ 10��, 100~1000������ 100��, 1000���� 3000������ 200��

	}

	cout << "   n   totalTime   runTime" << endl;

	for (int j = 0; j < 30; j++) //�ð� ������ֱ�
	{
		long start, stop;
		start = clock(); //�ð����� ����
		int s = sizeof(a) / sizeof(a[0]);
		for (long b = 1; b <= r[j]; b++)
			quickSort(a, 0, n[j]);
			//quicksort(n[0],n[j]); // �־��� ��� ����(Selectionsort�Լ� ȣ��)
		stop = clock(); // �ð����� ��
		long totalTime = stop - start;
		float runTime = (float)((totalTime) / (CLK_TCK)) / (float)(r[j]); //totalTime �ʷ� ��Ÿ���ֱ�,Ƚ���� �����ֱ�
		cout << "   " << n[j] << "   " << totalTime << "   " << runTime << endl; //�ð� ���
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
	// ���� �ڿ� �ִ� ���� �ǹ����� ����.
	int pivot = arr[high];
	int i = (low - 1);

	// arr ���� ��� ���� Ž��.
	for (int j = low; j <= high - 1; j++)
	{
		// �ǹ����� ���� ������ �ڷ� ������.
		if (arr[j] <= pivot)
		{
			// �� for���� ���ʷ� ������ ���� �����ϰ��
			// �׻� arr[i] < pivot && arr[i+1] > pivot ������ �����Ѵ�.
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	// ���� for���� ������ high ��ġ�� �ִ� �ǹ��� i + 1 ��ġ�� �Ű��ش�.
	// �̷μ� i + 1���� ���� ���� �ε����鸦 ���� ���ҵ��� �ǹ����� ���� ������ ������ �ְ�
	// i + 1���� ū ���� �ε����� ���� ���ҵ��� �ǹ����� ū ������ ������ �ִ�.
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		// partition �Լ��� ����Ǹ� arr �迭 ������
		// low ~ pi-1 �������� arr[pi] ���� ���� ������,
		// pi+1 ~ high �������� arr[pi] ���� ū ������ ��� �ְ� �ȴ�.
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

