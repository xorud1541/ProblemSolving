#include <iostream>
#include <vector>
#include <algorithm>
#define MAX		50
using namespace std;

int map[MAX + 1][MAX + 1];
int N, M;

int calc(int x, int y, vector<pair<int, int>>& vec)
{
	int ans = -1;
	for (int i = 0; i < vec.size(); i++)
	{
		int kx = vec[i].first;
		int ky = vec[i].second;

		int dis = abs(kx - x) + abs(ky - y);
		if (ans < 0)
			ans = dis;
		else
			ans = min(ans, dis);
	}

	return ans;
}
int main()
{
	cin >> N >> M;
	vector<pair<int, int>> nodes;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				nodes.emplace_back(i, j);
		}
	}

	vector<int> index(nodes.size(), 0);
	for (int i = 0; i < M; i++)
		index[i] = 1;

	int ans = -1;
	do
	{
		vector<pair<int, int>> candidate;

		for (int i = 0; i < nodes.size(); i++)
		{
			if (index[i] == 1)
			{
				candidate.push_back(nodes[i]);
			}
		}

		int ret = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 1)
				{
					ret += calc(i, j, candidate);
				}
			}
		}

		if (ans < 0)
			ans = ret;
		else
			ans = min(ans, ret);

	} while (prev_permutation(index.begin(), index.end()));

	cout << ans << '\n';
	return 0;
}