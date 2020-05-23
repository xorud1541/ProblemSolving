#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<bool>> isFriends(n, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			isFriends[a][b] = true;
			isFriends[b][a] = true;
		}

		int ans = 0;
		vector<int> people;
		for (int i = 0; i < n; i++)
			people.push_back(i);

		do
		{
			bool ok = true;
			int before = -1;
			for (int i = 0; i < n; i = i + 2)
			{
				int a = people[i];
				int b = people[i + 1];
				if (a < before || a > b || !isFriends[a][b])
				{
					ok = false;
					break;
				}

				before = a;
			}

			if (ok)
				ans++;
		} while (next_permutation(people.begin(), people.end()));

		cout << ans << endl;
	}
	return 0;
}