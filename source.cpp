#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>
#define MAX		1000
using namespace std;

int N, M;
int map[MAX + 1][MAX + 1];
int ans[MAX + 1][MAX + 1][2];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main()
{
	cin >> N >> M;
	vector<string> v;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < N; i++)
	{
		string s = v[i];
		for (int j = 0; j < s.size(); j++)
		{
			char c = s[j];
			if (c == '0')
				map[i][j] = 0;
			else
				map[i][j] = 1;
		}
	}

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	memset(ans, -1, sizeof(ans));
	ans[0][0][0] = 0;

	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front(); q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (z == 0)
			{
				if (map[nx][ny] == 0 && ans[nx][ny][0] == -1)
				{
					ans[nx][ny][0] = ans[x][y][0] + 1;
					q.push(make_tuple(nx, ny, 0));
				}
				else if (map[nx][ny] == 1 && ans[nx][ny][1] == -1)
				{
					ans[nx][ny][1] = ans[x][y][0] + 1;
					q.push(make_tuple(nx, ny, 1));
				}
			}
			else // z=1
			{
				if (map[nx][ny] == 0 && ans[nx][ny][1] == -1)
				{
					ans[nx][ny][1] = ans[x][y][1] + 1;
					q.push(make_tuple(nx, ny, 1));
				}
			}
		}
	}

	if (ans[N - 1][M - 1][0] == -1 && ans[N - 1][M - 1][1] == -1)
		cout << -1 << '\n';
	else
	{
		int a = ans[N - 1][M - 1][0];
		int b = ans[N - 1][M - 1][1];
		
		if (a == -1)
			cout << b + 1<< '\n';
		else if (b == -1)
			cout << a  + 1<< '\n';
		else
		{
			if (a > b)
				cout << b + 1<< '\n';
			else
				cout << a + 1<< '\n';
		}
	}
	return 0;
}