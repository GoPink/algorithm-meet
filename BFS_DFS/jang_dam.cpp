#include<iostream>
#include<queue>

using namespace std;

struct Point
{
	int x, y;

	Point(int _x, int _y) : x(_x), y(_y)
	{
	}
};

int** mat;
int T;
queue<Point> q;

int checkAndPush(int x, int y) //push�Ǹ� 1 ��ȯ, �ȵǸ� 0��ȯ
{
	if (x >= 0 && x < T && y >= 0 && y < T)
	{
		if (mat[y][x] != 1 && mat[y][x] != 3)	//�湮�� �ȵǾ��� ���� �ƴ϶�� push
		{
			q.push(Point(x, y));
			return 1;
		}
	}
	return 0;
}
int dam(int x, int y, int k)
{
	int water = 0;

	q.push(Point(x-1,y-1));

	while (!q.empty())
	{
		Point p = q.front();
		q.pop();
		mat[p.y][p.x] = 3;	//�湮�� ���� check

		int cnt = 0;

		cnt += checkAndPush(p.x - 1, p.y);
		cnt += checkAndPush(p.x + 1, p.y);
		cnt += checkAndPush(p.x, p.y - 1 );
		cnt += checkAndPush(p.x, p.y + 1 );

		if (cnt == 0)
		{
			cout << "OH, MY GOD" << endl;
			exit(0);
		}
		water++;
		if (water == k)
			return cnt;
	}
}
int main()
{
	cin >> T;

	mat = new int*[T];

	for (int i = 0; i < T; i++)
		mat[i] = new int[T];

	for (int i = 0; i < T; i++)
		for (int j = 0; j < T; j++)
			cin >> mat[i][j];
	
	int x, y;
	cin >> x >> y;

	int K;
	cin >> K;

	cout<<dam(x, y, K)<<endl;

	for (int i = 0; i < T; i++)
		delete[] mat[i];

	delete[] mat;

	return 0;
}