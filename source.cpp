#include <iostream>
#include <vector>
#include <algorithm>
#define MAX		10

using namespace std;
int T, n, m;
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		int ans = 0;
		vector< vector< bool > > isFriend(n+1, vector< bool >(n+1, false));
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			isFriend[a][b] = true;
			isFriend[b][a] = true;
		}

		vector<int> friends;
		for (int i = 0; i < n; i++)
			friends.push_back(i);
		do
		{
			int index = 0;
			int before = -1;
			bool succ = true;
			while (index + 1 < n)
			{
				int a = friends[index];
				int b = friends[index + 1];
				if (before == -1)
					before = a;
				
				if (a > b)
				{
					succ = false;
					break;
				}
				else
				{
					if (!isFriend[a][b])
					{
						succ = false;
						break;
					}
					else
					{
						if (before > a)
						{
							succ = false;
							break;
						}
						else
						{
							before = a;
						}
					}
				}
				index = index + 2;
			}

			if (succ)
				ans++;

		} while (next_permutation(friends.begin(), friends.end()));

		cout << ans << endl;
	}
	return 0;
}