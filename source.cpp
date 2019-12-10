#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define MAX		200
using namespace std;

int K, W, H;
int map[MAX][MAX];
int ans[MAX][MAX][31];

int dx[] = { 0, 0, 1, -1, -1,-2,-2,-1, 1, 2, 2, 1 };
int dy[] = { 1, -1, 0, 0, -2,-1, 1, 2, 2, 1,-1,-2 };
int cost[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };

int main()
{
	cin >> K;
	cin >> W >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> map[i][j];
		}
	}

	memset(ans, -1, sizeof(ans));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	ans[0][0][0] = 0;

	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front(); q.pop();

		for (int idx = 0; idx < 12; idx++)
		{
			int nx = x + dx[idx];
			int ny = y + dy[idx];
			int nc = z + cost[idx];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

			if (map[nx][ny] == 1) continue;
			if (nc <= K)
			{
				if (ans[nx][ny][nc] == -1)
				{
					ans[nx][ny][nc] = ans[nx][ny][z] + 1;
					q.push(make_tuple(nx, ny, nc));
				}
			}
		}
	}

	int ret = -1;
	for (int i = 0; i <= K; i++)
	{
		if(ans[H - 1][W - 1][i] == -1) continue;
		if (ret == -1 || ret > ans[H - 1][W - 1][i])
			ret = ans[H - 1][W - 1][i];
	}

	cout << ret << endl;
	return 0;
}