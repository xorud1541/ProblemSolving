#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, Sx = -1, Sy, Ex, Ey;
char map[1505][1505];
bool check[1505][1505];
int p[1505 * 1505];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

bool inner(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < m);
}

int find(int x)
{
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	p[x] = y;
}

int main()
{
	for (int i = 0; i < 1500 * 1500 + 2; i++)
		p[i] = i;

	scanf("%d %d", &n, &m);
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1c", &map[i][j]);
			if (map[i][j] == 'X')
				continue;
			if (map[i][j] == 'L')
			{
				if (Sx == -1)
				{
					Sx = i;
					Sy = j;
				}
				else
				{
					Ex = i;
					Ey = j;
				}
				map[i][j] = '.';
			}

			q.push({ i, j });
		}
	}

	int ans = 0;
	while (int s = q.size())
	{
		memset(check, 0, sizeof(check));
		while (s--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!inner(nx, ny))
					continue;

				if (map[nx][ny] == 'X')
				{
					q.push({ nx, ny });
					check[nx][ny] = true;
					map[nx][ny] = '.';
				}
				else
				{
					if (!check[nx][ny])
						merge(find(x*m + y), find(nx*m + ny));
				}
			}
		}
		if (find(Sx*m + Sy) == find(Ex*m + Ey)) {
			printf("%d\n", ans);
			return 0;
		}
		ans++;
	}
}