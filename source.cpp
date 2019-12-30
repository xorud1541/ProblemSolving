#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
#define MAX		100000007
using namespace std;

int N, M, k;
int dp[1001][1001][12];
int map[1001][1001];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int main()
{
	cin >> N >> M >> k;
	vector<string> t;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		t.push_back(s);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int l = 0; l <= k; l++)
			{
				dp[i][j][l] = MAX;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[i][j] = t[i][j] - '0';
		}
	}

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	dp[0][0][0] = 1;

	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front(); q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (z == k)
			{
				if (map[nx][ny] == 0 && (dp[nx][ny][z] > dp[x][y][z] + 1))
				{
					dp[nx][ny][z] = dp[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z));
				}
			}
			else if (z < k)
			{
				if (map[nx][ny] == 0 && (dp[nx][ny][z] > dp[x][y][z] + 1))
				{
					dp[nx][ny][z] = dp[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z));
				}
				else if (map[nx][ny] == 1 && (dp[nx][ny][z + 1] > dp[x][y][z] + 1))
				{
					dp[nx][ny][z + 1] = dp[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z + 1));
				}
			}
		}
	}

	bool no = true;
	for (int i = 0; i <= k; i++)
	{
		if (dp[N - 1][M - 1][i] != MAX)
		{
			no = false;
			break;
		}
	}

	if (no)
		cout << -1 << endl;
	else
	{
		int ret = 0;
		for (int i = 0; i <= k; i++)
		{
			if (ret == 0)
				ret = dp[N - 1][M - 1][i];
			else
			{
				if (ret > dp[N - 1][M - 1][i])
					ret = dp[N - 1][M - 1][i];
			}
		}

		cout << ret << endl;
	}
	return 0;
}