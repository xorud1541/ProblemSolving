#include <iostream>
#include <vector>
#include <cstring>
#define MAX	101
using namespace std;

int cache[MAX][MAX];
int map[MAX][MAX];
int N;
bool go(int i, int j)
{
	if (i >= N || j >= N)
	{
		return 0;
	}

	if (i == N - 1 && j == N - 1)
	{
		return 1;
	}

	int& ret = cache[i][j];
	if (ret != -1)
		return ret;

	int jump = map[i][j];
	int x = i + jump;
	int y = j + jump;

	return ret = go(x, j) || go(i, y);
}

int main()
{
	int C;
	cin >> C;
	for (int tc = 1; tc <= C; tc++)
	{
		memset(cache, -1, sizeof(cache));
		//memset(map, 0, sizeof(map));
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		if (go(0, 0))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}