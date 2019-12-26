#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAX		1005

int N, M;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int dp[MAX][MAX][2];
const int INF = 100000007;
using namespace std;

pair<int, int> getNext(int k, int x, int y, vector< vector<int> >& map)
{
	int nx, ny;
	nx = x + dx[k];
	ny = y + dy[k];

	if (nx < 0 || nx >= N || ny < 0 || ny >= M)
		return make_pair(x, y);

	if (map[nx][ny] == 0 || map[nx][ny] == 3)
		return make_pair(x, y);

	return getNext(k, nx, ny, map);
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				dp[i][j][k] = INF;
			}
		}
	}
	vector< vector<int> > map(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	dp[0][0][0] = 0;

	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		if (x == N - 1 && y == M - 1) continue;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			int c = map[nx][ny];
			if (c == 1)
			{
				if (dp[nx][ny][z] > dp[x][y][z] + 1)
				{
					dp[nx][ny][z] = dp[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z));
				}
			}
			else if (c == 2)
			{
				if (dp[nx][ny][1] > dp[x][y][z] + 1)
				{
					dp[nx][ny][1] = dp[x][y][z] + 1;
					q.push(make_tuple(nx, ny, 1));
				}
			}
			else if (c == 3 && z == 1)
			{
				if (dp[nx][ny][z] > dp[x][y][z] + 1)
				{
					dp[nx][ny][z] = dp[x][y][z] + 1;
					q.push(make_tuple(nx, ny, 1));
				}
			}
			else if (c == 4)
			{
				//pair<int, int> slide = getNext(k, nx, ny, map);
				int diff = 1;
				while (1)
				{
					if (map[nx][ny] != 4) break;
					int next_x = nx + dx[k];
					int next_y = ny + dy[k];
					if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) break;
					if (map[next_x][next_y] == 0 || map[next_x][next_y] == 3) break;
					nx = next_x; ny = next_y; diff++;
 				}

				if (map[nx][ny] == 2)
				{
					if (dp[nx][ny][1] > dp[x][y][z] + diff)
					{
						dp[nx][ny][1] = dp[x][y][z] + diff;
						q.push(make_tuple(nx, ny, 1));
					}
				}
				else if (map[nx][ny] == 4 || map[nx][ny] == 1)
				{
					if (dp[nx][ny][0] > dp[x][y][z] + diff)
					{
						dp[nx][ny][0] = dp[x][y][z] + diff;
						q.push(make_tuple(nx, ny, 0));
					}
				}
			}
			else {}
		}
	}

	int ans = dp[N - 1][M - 1][0] > dp[N - 1][M - 1][1] ? dp[N - 1][M - 1][1] : dp[N - 1][M - 1][0];
	if (ans == INF)
		ans = -1;
	cout << ans << endl;

	return 0;
}