#include <cstdio>

char star[2187][2187] = { 0, };		// 3^7 = 2187

void drawStar(int n, int x, int y)
{
	if (n <= 1) {
		return;
	}

	int a, b;

	// 9등분. 
	// top-left 좌표를 기준. 
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			a = x + n/3*i;
			b = y + n / 3 * j;
			if (i == 1 && j == 1) 
				for (int c = 0; c<n/3; c++)
					for (int d = 0; d<n/3; d++)
						star[a+c][b+d] = ' ';
			else
				drawStar(n/3, x+n/3*i, y+n/3*j);
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	// init
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			star[i][j] = '*';

	// draw
	drawStar(N, 0, 0);

	// print
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++)
			printf("%c", star[i][j]);
		printf("\n");
	}

	return 0;
}