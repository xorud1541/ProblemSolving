#include <iostream>
#include <queue>
#include <map>
#define MAX		 100001
using namespace std;

map<pair<int, int>, int> m;
int a, b, c, d;
int ans = 100000007;
int main()
{
	cin >> a >> b >> c >> d;

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	m.insert(make_pair(make_pair(0, 0), 0));
	bool ok = false;
	int space = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int cnt = m[make_pair(x, y)];

		for (int k = 0; k < 6; k++)
		{
			int nx, ny;
			switch (k)
			{
			case 0: // F(A)
				nx = a; ny = y;
				break;
			case 1: // F(B)
				nx = x; ny = b;
				break;
			case 2: // E(A)
				nx = 0; ny = y;
				break;
			case 3: // E(B)
				nx = x; ny = 0;
				break;
			case 4: // M(A, B)
				space = b - y;
				if (space >= x)
				{
					nx = 0; ny = y + x;
				}
				else
				{
					nx = x - space; ny = b;
				}
				break;
			case 5:
				space = a - x;
				if (space >= y)
				{
					nx = x + y; ny = 0;
				}
				else
				{
					nx = a; ny = y - space;
				}
				break;
			}

			if (m.count(make_pair(nx, ny)) == 0)
			{
				m.insert(make_pair(make_pair(nx, ny), cnt + 1));

				if (nx == c && ny == d)
				{
					ok = true;
					break;
				}
				q.push(make_pair(nx, ny));
			}
		}
		if (ok)
			break;
	}

	if (m.count(make_pair(c, d)) != 0)
		cout << m[make_pair(c, d)] << endl;
	else
		cout << -1 << endl;
	return 0;
}