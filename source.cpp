#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <string>
#define MAX		1000
using namespace std;

int n, m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int dp[MAX + 1][MAX + 1][2];
int map[MAX + 1][MAX + 1];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}


	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	dp[0][0][0] = 1;

	int ans = -1;
	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front(); q.pop();
		for (int k = 0; k < 4; k++) 
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if (map[nx][ny] == 0 && dp[nx][ny][z] == 0)
			{
				dp[nx][ny][z] = dp[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z));
			}

			if (map[nx][ny] == 1 && z == 0 && dp[nx][ny][1] == 0)
			{
				dp[nx][ny][1] = dp[x][y][z] + 1;
				q.push(make_tuple(nx, ny, 1));
			}
		}
	}

	if (dp[n - 1][m - 1][0] != 0 || dp[n - 1][m - 1][1] != 0)
	{
		if (dp[n - 1][m - 1][0] == 0)
			ans = dp[n - 1][m - 1][1];
		else if (dp[n - 1][m - 1][1] == 0)
			ans = dp[n - 1][m - 1][0];
		else
			ans = min(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]);
	}

	cout << ans << endl;

	return 0;
}