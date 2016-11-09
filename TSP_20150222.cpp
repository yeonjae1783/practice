#include <iostream>
#include <cmath>
using namespace std;
int bit(int s, int n);
int cal(int s);
int pow2(int i);
void travel1(int n);
void travel2(int n);
void travel3(int n);
#define INF 100  //inf를 100이라 가정

int W4[4][4] = { //Figure 3.16
	{ 0, 2, 9, INF },
	{ 1, 0, 6, 4 },
	{ INF, 7, 0, 8 },
	{ 6, 3, INF, 0 }
};

int S1[3][3] = { //Sample1
	{ 0, 1, 2 },
	{ 4, 0, 2 },
	{ 3, 3, 0 }
};

int S2[3][3] = { //Sample2
	{0, 5, 1},
	{4, 0, 1},
	{4, 2, 0}
};

int main(void) {

	cout << "Figure 3.16" << endl;
	travel1(4);
	cout << "Sample1" << endl;
	travel2(3);
	cout << "Sample2" << endl;
	travel3(3);


	return 0;
}


int pow2(int i) {
	return pow(2, i);
}

typedef struct node{  //경로 저장하는 구조체 배열
	int now;//현재 노드
	int next;//이전 노드
}node;

int bit(int s, int n) {
	int count = 0;
	int one = 1;

	for (int i = 0; i<n; i++) {
		if (s & one)
			count++;
		one = one << 1;
	}
	return count;
}

int cal(int s) {
	int an = (int)(log10((double)s) / log10(2.0));
	if (an <= 0)
		return 0;
	else
		return an;
}



void travel1(int n) {
	int i, k, s;
	int sub = (int)pow(2.0, n); //부분집합


	int D[4][16];
	node P[4][16];


	// D, P 초기화
	for (i = 0; i<n; i++)
		for (s = 0; s<pow2(n); s++)
			D[i][s] = 0;

	for (i = 0; i<n; i++) {
		for (s = 0; s<pow2(n); s++) {
			P[i][s].now = 0;
			P[i][s].next = 0;
		}
	}




	for (i = 0; i<n; i++) {
		D[i][0] = W4[i][0];

	}


	for (k = 1; k< n - 1; k++) { // 거쳐가는 node 수

		for (i = 1; i<n; i++) {

			s = 2;
			while (s < sub) {//부분집합 모두

				int one = 1;
				int temp = INF;
				int min = INF * 3;

				//s가 k개의 node이고, Vi 미포함, V0 미포함
				if ((bit(s, n) == k) && !(s & pow2(i)) && !(s & 1)) {

					//n비트만큼 시프트하면서 해당 부분집합 검사
					for (int a = 0; a<n; a++) {

						if (s & one) {
							temp = (W4[i][cal(one)] + D[cal(one)][s^one]);

							if (temp >= INF)
								temp = INF;


							if (temp <= min) {
								min = temp;

								P[i][s].now = cal(one); //거쳐갈 노드
								P[i][s].next = s^one;

							}

						}
						one = one << 1;

					}
					D[i][s] = min;
				}
				s++;
			}
		}

	}
	s = pow2(n) - 2;

	int one = 1;
	int temp = INF;
	int minlength = INF * 3;

	for (int a = 0; a<n; a++) {

		if (s & one) {
			temp = (W4[0][cal(one)] + D[cal(one)][s^one]);
			if (temp < minlength) {
				minlength = temp;
				P[0][pow2(n) - 2].now = cal(one); // 최초경로
				P[0][pow2(n) - 2].next = s^one;
			}
		}
		one = one << 1;
	}

	D[0][pow2(n) - 2] = minlength;
	cout << "최적경로 : " << minlength << endl;


	//경로출력

	int p = 0;
	int q = pow2(n) - 2;
	int temp1, temp2;
	cout << "V1 -> ";
	for (i = 0; i <= n - 2; i++) {
		cout << "V" << P[p][q].now + 1 << " -> ";
		temp1 = P[p][q].now;
		temp2 = P[p][q].next;
		p = temp1;
		q = temp2;
	}
	cout << "V1" << endl << endl;

}

void travel2(int n) {
	int i, k, s;
	int sub = (int)pow(2.0, n); //부분집합

	
	int D[3][8];
	node P[3][8];
	
	//D, P초기화
	for (i = 0; i<n; i++)
		for (s = 0; s<pow2(n); s++)
			D[i][s] = 0;

	for (i = 0; i<n; i++) {
		for (s = 0; s<pow2(n); s++) {
			P[i][s].now = 0;
			P[i][s].next = 0;
			}
	}
	



	for (i = 0; i<n; i++) {
		D[i][0] = S1[i][0];
		
	}
	

	for (k = 1; k< n - 1; k++) { // 거쳐가는 node 수

		for (i = 1; i<n; i++) {

			s = 2;
			while (s < sub) {//부분집합 모두

				int one = 1;
				int temp = INF;
				int min = INF * 3;

				//s가 k개의 node이고, Vi 미포함, V0 미포함
				if ((bit(s, n) == k) && !(s & pow2(i)) && !(s & 1)) {

					//n비트만큼 시프트하면서 해당 부분집합 검사
					for (int a = 0; a<n; a++) {

						if (s & one) {
							temp = (S1[i][cal(one)] + D[cal(one)][s^one]);

							if (temp >= INF)
								temp = INF;


							if (temp <= min) {
								min = temp;

								P[i][s].now = cal(one); //거쳐갈 노드
								P[i][s].next = s^one;

							}

						}
						one = one << 1;

					}
					D[i][s] = min;
				}
				s++;
			}
		}

	}



	s = pow2(n) - 2;

	int one = 1;
	int temp = INF;
	int minlength = INF * 3;

	for (int a = 0; a<n; a++) {

		if (s & one) {
			temp = (S1[0][cal(one)] + D[cal(one)][s^one]);
			if (temp < minlength) {
				minlength = temp;
				P[0][pow2(n) - 2].now = cal(one); // 최초경로
				P[0][pow2(n) - 2].next = s^one;
	
			}
		}
		one = one << 1;
	}

	D[0][pow2(n) - 2] = minlength;
	cout << "최적경로 : " << minlength << endl;


	// 경로출력 

	int p = 0;
	int q = pow2(n) - 2;
	int temp1, temp2;
	cout << "V1 -> ";
	for (i = 0; i <= n - 2; i++) {
		cout << "V" << P[p][q].now + 1 << " -> ";
		temp1 = P[p][q].now;
		temp2 = P[p][q].next;
		p = temp1;
		q = temp2;
	}
	cout << "V1" << endl << endl;

}

void travel3(int n) {
	int i, k, s;
	int sub = (int)pow(2.0, n); //부분집합


	int D[3][8];
	node P[3][8];

	//D,P초기화
	for (i = 0; i<n; i++)
		for (s = 0; s<pow2(n); s++)
			D[i][s] = 0;

	for (i = 0; i<n; i++) {
		for (s = 0; s<pow2(n); s++) {
			P[i][s].now = 0;
			P[i][s].next = 0;
		}
	}




	for (i = 0; i<n; i++) {
		D[i][0] = S2[i][0];

	}


	for (k = 1; k< n - 1; k++) { // 거쳐가는 node 수

		for (i = 1; i<n; i++) {

			s = 2;
			while (s < sub) {//부분집합 모두

				int one = 1;
				int temp = INF;
				int min = INF * 3;

				//s가 k개의 node이고, Vi 미포함, V0 미포함
				if ((bit(s, n) == k) && !(s & pow2(i)) && !(s & 1)) {

					//n비트만큼 시프트하면서 해당 부분집합 검사
					for (int a = 0; a<n; a++) {

						if (s & one) {
							temp = (S2[i][cal(one)] + D[cal(one)][s^one]);

							if (temp >= INF)
								temp = INF;


							if (temp <= min) {
								min = temp;

								P[i][s].now = cal(one); //거쳐갈 노드
								P[i][s].next = s^one;

							}

						}
						one = one << 1;

					}
					D[i][s] = min;
				}
				s++;
			}
		}

	}


	s = pow2(n) - 2;

	int one = 1;
	int temp = INF;
	int minlength = INF * 3;

	for (int a = 0; a<n; a++) {

		if (s & one) {
			temp = (S2[0][cal(one)] + D[cal(one)][s^one]);
			if (temp < minlength) {
				minlength = temp;
				P[0][pow2(n) - 2].now = cal(one); // 최초경로
				P[0][pow2(n) - 2].next = s^one;
			}
		}
		one = one << 1;
	}

	D[0][pow2(n) - 2] = minlength;
	cout << "최적경로 : " << minlength << endl;



	// 경로 출력

	int p = 0;
	int q = pow2(n) - 2;
	int temp1, temp2;
	cout << "V1 -> ";
	for (i = 0; i <= n - 2; i++) {
		cout << "V" << P[p][q].now + 1 << " -> ";
		temp1 = P[p][q].now;
		temp2 = P[p][q].next;
		p = temp1;
		q = temp2;
	}
	cout << "V1" << endl << endl;

}
