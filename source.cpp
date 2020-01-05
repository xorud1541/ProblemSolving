#include <iostream>
#include <vector>
#include <algorithm>
#define MAX		10
using namespace std;

int C, n, m;
int main()
{
	cin >> C;
	for (int tc = 1; tc <= C; tc++)
	{
		int ans = 0;
		cin >> n >> m;

		vector<int> f;
		vector< vector<bool> > isFriends(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++)
			f.push_back(i);

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			isFriends[a][b] = isFriends[b][a] = true;
		}

		do
		{
			int before = -1;
			int cur = 0;
			bool ok = true;
			for (int i = 0; i < f.size(); i = i + 2)
			{
				cur = f[i];
				int next = f[i + 1];
				if (before < cur && cur < next && isFriends[cur][next])
				{
					before = cur;
				}
				else
				{
					ok = false;
					break;
				}
			}

			if (ok)
				ans++;

		} while (next_permutation(f.begin(), f.end()));

		cout << ans << endl;
	}

	return 0;
}