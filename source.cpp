#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, K;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void check(vector< vector<bool> >& map, int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			map[i][j] = true;
		}
	}
}

int dfs(vector <vector<bool> >& map, int x, int y)
{
	int ret = 0;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

		if (!map[nx][ny])
		{
			map[nx][ny] = true;
			ret += dfs(map, nx, ny) + 1;
		}
	}
	return ret;
}

int main()
{
	cin >> M >> N >> K;
	priority_queue<int, vector<int>, greater<int> > q;
	vector< vector<bool> > map(M, vector<bool>(N, 0));

	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		check(map, y1, x1, y2 - 1, x2 - 1);
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!map[i][j])
			{
				map[i][j] = true;
				int ret = dfs(map, i, j) + 1;
				q.push(ret);
			}
		}
	}

	int cnt = q.size();
	cout << cnt << "\n";
	while (!q.empty())
	{
		int ans = q.top();
		cout << ans << endl;
		q.pop();
	}

	return 0;
}