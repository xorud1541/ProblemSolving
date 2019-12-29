#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int map[10][10];
int ans;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
vector<pair<int, int>> virus;

int func(vector< vector<int> >& _map)
{
	vector < vector<bool> > visited(N, vector<bool>(M, false));
	for (int i = 0; i < virus.size(); i++)
	{
		int x = virus[i].first;
		int y = virus[i].second;

		queue< pair<int, int> > q;
		q.push(make_pair(x, y));
		visited[x][y] = true;

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

				if (!visited[nx][ny] && _map[nx][ny] == 0)
				{
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
					_map[nx][ny] = 2;
				}
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (_map[i][j] == 0)
				ret++;
		}
	}
	return ret;
}

int main()
{
	cin >> N >> M;
	vector< pair<int, int> > zeros;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				zeros.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2)
			{
				virus.push_back(make_pair(i, j));
			}
		}
	}

	vector<int> a(zeros.size(), 0);
	a[0] = a[1] = a[2] = 1;

	do
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == 1)
			{
				int x = zeros[i].first;
				int y = zeros[i].second;

				map[x][y] = 1;
			}
		}

		vector< vector<int> > cpy_map(N, vector<int>(M, 0));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cpy_map[i][j] = map[i][j];
			}
		}

		int ret = func(cpy_map);
		ans = max(ret, ans);

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == 1)
			{
				int x = zeros[i].first;
				int y = zeros[i].second;

				map[x][y] = 0;
			}
		}
	} while (prev_permutation(a.begin(), a.end()));

	cout << ans << endl;
	return 0;
}