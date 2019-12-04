#include <iostream>
#include <vector>
#include <algorithm>
#define MAX		500
using namespace std;

int N, M;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool visited[MAX + 1][MAX + 1];

int except(int x, int y, vector< vector<int> >& map)
{
	int ret = 0;
	int center = map[x][y];
	if (x - 1 >= 0 && x + 1 < N)
	{
		int up = map[x - 1][y];
		int down = map[x + 1][y];

		if (y - 1 >= 0)
		{
			int temp = center + up + down + map[x][y - 1];
			ret = max(ret, temp);
		}

		if (y + 1 < M)
		{
			int temp = center + up + down + map[x][y + 1];
			ret = max(ret, temp);
		}
	}

	if (y - 1 >= 0 && y + 1 < M)
	{
		int left = map[x][y - 1];
		int right = map[x][y + 1];

		if (x - 1 >= 0)
		{
			int temp = center + left + right + map[x - 1][y];
			ret = max(ret, temp);
		}

		if (x + 1 < N)
		{
			int temp = center + left + right + map[x + 1][y];
			ret = max(ret, temp);
		}
	}

	return ret;
}

int solution(int x, int y, int cnt, vector< vector<int> >& map)
{
	int ret = map[x][y];
	if (cnt == 4)
	{
		return ret;
	}

	int ans = 0;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		if (!visited[nx][ny])
		{
			visited[nx][ny] = true;

			int temp = solution(nx, ny, cnt + 1, map);

			ans = max(ans, ret + temp);

			visited[nx][ny] = false;
		}
		
	}

	return ans;
}

int main()
{
	cin >> N >> M;

	vector< vector<int> > map(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = true;
			int ret = solution(i, j, 1, map);
			ans = max(ret, ans);
			visited[i][j] = false;

			ret = except(i, j, map);
			ans = max(ans, ret);
		}
	}

	cout << ans << endl;
	return 0;
}