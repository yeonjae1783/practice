#include<iostream>
using namespace std;
#define n 25

void m_coloring(int i);
bool promising(int i);
int m; //칠할 색깔의 수
int repeat = 0;
int W[n + 1][n + 1];
int vcolor[n + 1];

int main() {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++)
			W[i][j] = 0; //초기화
	//서울지도 그래프 2차원 배열
	W[1][2] = W[1][5] = 1;
	W[2][1] = W[2][3] = W[2][5] = W[2][7] = 1;
	W[3][2] = W[3][4] = W[3][6] = W[3][7] = 1;
	W[4][3] = W[4][7] = W[4][8] = W[4][9] = W[4][13] = W[4][14] = 1;
	W[5][1] = W[5][2] = W[5][6] = 1;
	W[6][2] = W[6][3] = W[6][5] = W[6][7] = W[6][10] = 1;
	W[7][3] = W[7][4] = W[7][6] = W[7][11] = W[7][13] = 1;
	W[8][4] = W[8][9] = 1;
	W[9][4] = W[9][8] = W[9][14] = 1;
	W[10][11] = W[10][16] = W[10][17] = 1;
	W[11][6] = W[11][7] = W[11][10] = W[11][12] = W[11][16] = 1;
	W[12][11] = W[12][13] = W[12][15] = W[12][16] = W[12][17] = 1;
	W[13][4] = W[13][7] = W[13][12] = W[13][14] = W[13][15] = 1;
	W[14][4] = W[14][9] = W[14][13] = W[14][15] = W[14][18] = 1;
	W[15][12] = W[15][13] = W[15][14] = W[15][17] = W[15][18] = W[15][19] = W[15][20] = 1;
	W[16][10] = W[16][11] = W[16][12] = W[16][17] = 1;
	W[17][10] = W[17][12] = W[17][15] = W[17][16] = W[17][19] = W[17][25] = 1;
	W[18][14] = W[18][15] = W[18][20] = W[18][21] = 1;
	W[19][15] = W[19][17] = W[19][20] = W[19][23] = W[19][24] = W[19][25] = 1;
	W[20][15] = W[20][18] = W[20][19] = W[20][21] = 1;
	W[21][18] = W[21][20] = W[21][22] = W[21][23] = 1;
	W[22][21] = W[21][23] = 1;
	W[23][19] = W[23][21] = W[23][22] = 1;
	W[24][19] = W[24][23] = W[24][25] = 1;
	W[25][17] = W[25][19] = W[25][24] = 1;

	cout << "<m-coloring: 서로 인접한 정점이 같은 색을 갖지 않도록 최대 m개의 다른 색으로 칠하는 방법>" << endl;
	for (m = 1; m < 100; m++) {
		m_coloring(0);

		if (repeat == 0)
			cout << "m이 " << m << "일때: " << m << "가지의 색만으로는 그래프를 색칠할 수 없습니다." << endl;
		else {
			cout << "m이 " << m << "일때: " << "최소" << repeat << "가지 조합이 생성됩니다." << endl;
			break;
		}
	}
	return 0;
}
bool promising(int i) {
	int j;
	bool switchs;
	switchs = true;
	j = 1;
	while (j < i&&switchs) {
		if (W[i][j] == 1 && vcolor[i] == vcolor[j])
			switchs = false;
		j++;
	}
	return switchs;

}
void m_coloring(int i) {
	int color;
	if (promising(i)) {
		if (i == n)
		{
	
			/*for (int k = 1; k <= n; k++)
				cout << vcolor[k] << " ";
				cout << endl;*/
			repeat++;
		}
		else {
			for (color = 1; color <= m; color++) {
				vcolor[i + 1] = color;
				m_coloring(i + 1);
			}
		}
	}
}