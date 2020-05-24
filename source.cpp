#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	vector<int> ans;
	for (int i = 0; i < N; i++)
	{
		int x = v[i].first;
		int y = v[i].second;

		int k = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;

			if (x < v[j].first && y < v[j].second)
				k++;
		}
		ans.push_back(k + 1);
	}

	for (auto a : ans)
		cout << a << endl;
	return 0;
}