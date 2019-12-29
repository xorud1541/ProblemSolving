#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define MAX		101
using namespace std;

int N;
int map_[MAX][MAX];
bool visited[MAX][MAX];

map<pair<int, int>, int> m;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int cnt = 0;
int ans = 100000007;

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visited[i][j] = true;
	m[make_pair(i, j)] = cnt;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (map_[nx][ny] == 0)
			{
				//m.insert(make_pair(make_pair(nx, ny), cnt));
				map_[x][y] = 2;
			}

			if (!visited[nx][ny])
			{
				visited[nx][ny] = true;
				if (map_[nx][ny] == 1)
				{
					q.push(make_pair(nx, ny));
					m.insert(make_pair(make_pair(nx, ny), cnt));
				}
				else {}
			}
		}
	}
}

void dfs(int x, int y, int len, int num)
{
	if (len > ans)
	{
		return;
	}

	visited[x][y] = true;

	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (!visited[nx][ny] && map_[nx][ny] != 1)
		{
			if (map_[nx][ny] == 0)
			{
				visited[nx][ny] = true;
				dfs(nx, ny, len + 1, num);
			}
			else if(map_[nx][ny] == 2)// 2
			{
				int n = m[make_pair(nx, ny)];
				if (n != num)
				{
					ans = min(ans, len);
				}
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map_[i][j];
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && map_[i][j] == 1)
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map_[i][j];
		}
		cout << '\n';
	}
	*/
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map_[i][j] == 2)
			{
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						visited[i][j] = false;
					}
				}

				int num = m[make_pair(i, j)];
				dfs(i, j, 0, num);
			}
		}
	}

	cout << ans << endl;
	return 0;
}