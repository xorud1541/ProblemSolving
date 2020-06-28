#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX		251

using namespace std;
int R, C;
bool visited[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

pair<int, int> count(int x, int y, vector< vector<char> >& map)
{
	int ans1 = 0;
	int ans2 = 0;
	if (map[x][y] == 'v')
		ans2++;
	else if (map[x][y] == 'o')
		ans1++;
	else {}

	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;

			if (!visited[nx][ny] && map[nx][ny] != '#')
			{
				visited[nx][ny] = true;

				if (map[nx][ny] == 'v')
					ans2++;
				else if(map[nx][ny] == 'o')
					ans1++;

				q.push({ nx, ny });
			}
		}
	}

	return make_pair(ans1, ans2);
}

int main()
{
	cin >> R >> C;
	vector< vector<char> > map(R, vector<char>(C, 0));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}

	int ans1 = 0;
	int ans2 = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (!visited[i][j] && map[i][j] != '#')
			{
				visited[i][j] = true;
				pair<int, int> cnt = count(i, j, map);
				if (cnt.first <= cnt.second)
				{
					ans2 += cnt.second;
				}
				else
				{
					ans1 += cnt.first;
				}
			}
		}
	}

	printf("%d %d", ans1, ans2);
	return 0;
}