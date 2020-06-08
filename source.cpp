#include <iostream>
#include <vector>
#include <algorithm>
#define MAX		10001
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> e(N, 0);
		vector<int> m(N, 0);

		for (int i = 0; i < N; i++) 
			cin >> m[i];
		for (int i = 0; i < N; i++) 
			cin >> e[i];

		vector<pair<int, int>> order;
		for (int i = 0; i < N; i++)
			order.push_back(make_pair(-e[i], i));

		sort(order.begin(), order.end());
		int ret = 0, beginEat = 0;
		for (int i = 0; i < N; i++)
		{
			int box = order[i].second;
			beginEat += m[box];
			ret = max(ret, beginEat + e[box]);
		}
		cout << ret << endl;
	}
	return 0;
}