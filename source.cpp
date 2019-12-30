#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
long long L;

bool search(vector<long long>& saro, long long left, long long right)
{
	long long low = 0;
	long long high = saro.size() - 1;
	bool ok = false;
	while (low <= high)
	{
		long long mid = (low + high) / 2;

		if (left <= saro[mid] && saro[mid] <= right)
		{
			ok = true;
			break;
		}
		else if (saro[mid] > right)
		{
			high = mid - 1;
		}
		else if (saro[mid] < left)
		{
			low = mid + 1;
		}
		else 
		{ }
	}
	return ok;
}

int main()
{
	cin >> M >> N >> L;

	vector<long long> saro(M, 0);
	vector<pair<long long, long long>> animals;
	for (int i = 0; i < M; i++)
		cin >> saro[i];

	for (int i = 0; i < N; i++)
	{
		long long x, y;
		cin >> x >> y;
		animals.push_back(make_pair(x, y));
	}

	sort(saro.begin(), saro.end());
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		long long x = animals[i].first;
		long long y = animals[i].second;

		if (L >= y)
		{
			long long left = x - (L - y);
			long long right = x + (L - y);

			bool ok = search(saro, left, right);
			if (ok)
				ans++;
		}
	}

	cout << ans << endl;
	return 0;
}