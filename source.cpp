#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAX		1001

int N, M;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int dp[MAX][MAX][2];
bool visited[MAX][MAX];
int ans = 1e9;
using namespace std;

pair<int, int> getNext(int k, int x, int y, vector< vector<int> >& map)
{
	int nx, ny;
	nx = x + dx[k];
	ny = y + dy[k];

	if (nx < 0 || nx >= N || ny < 0 || ny >= M)
		return make_pair(x, y);
	
	if(map[nx][ny] == 0 || map[nx][ny] == 3)
		return make_pair(x, y);

	return getNext(k, nx, ny, map);
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

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	visited[0][0] = true;

	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			int c = map[nx][ny];
			if (!visited[nx][ny] && c != 0)
			{
				if (c == 1)
				{
					visited[nx][ny] = true;
					if (ans > dp[x][y][z] + 1)
					{
						ans = dp[x][y][z] + 1;
						dp[nx][ny][z] = dp[x][y][z] + 1;
						q.push(make_tuple(nx, ny, z));
					}
				}
				else if (c == 2)
				{
					visited[nx][ny] = true;
					if (ans > dp[x][y][z] + 1)
					{
						ans = dp[x][y][z] + 1;
						dp[nx][ny][1] = dp[x][y][z] + 1;
						q.push(make_tuple(nx, ny, 1));
					}
				}
				else if (c == 3 && z == 1)
				{
					visited[nx][ny] = true;
					if (ans > dp[x][y][z] + 1)
					{
						ans = dp[x][y][z] + 1;
						dp[nx][ny][z] = ans;
						q.push(make_tuple(nx, ny, 1));
					}
				}
				else if (c == 4)
				{
					pair<int, int> slide = getNext(k, nx, ny, map);
					if (!visited[slide.first][slide.second])
					{
						int diff = max(abs(x - slide.first), abs(y - slide.second));

						if (ans > dp[x][y][z] + diff)
						{
							ans = dp[x][y][z] + diff;
							dp[slide.first][slide.second][0] = ans;
							q.push(make_tuple(slide.first, slide.second, 0));
						}
					}
				}
				else
				{ }
			}
		}
	}

	int A = dp[N - 1][M - 1][0];
	int B = dp[N - 1][M - 1][1];

	if (A != 0 && B != 0)
		cout << min(A, B) << endl;
	else if (A == 0 && B == 0)
		cout << -1 << endl;
	else if (A == 0 && B != 0)
		cout << B << endl;
	else
		cout << A << endl;

	return 0;
}