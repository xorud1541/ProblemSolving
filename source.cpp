#include <iostream>
#include <vector>
#include <algorithm>
#define MAX		501
using namespace std;

int cache[MAX];

int go(int x, vector<int>& arr)
{
	if (x == arr.size() - 1)
		return 1;

	int& ret = cache[x];
	if (ret != 1)
		return ret;

	for (int i = x + 1; i < arr.size(); i++)
	{
		int next = arr[i];
		if (next > arr[x])
		{
			ret = max(ret, go(i, arr) + 1);
		}
	}

	return ret;
}

int main()
{
	int C, N;
	cin >> C;
	for (int tc = 1; tc <= C; tc++)
	{
		cin >> N;
		vector<int> arr(N, 0);
		for (int i = 0; i < N; i++)
		{
			cache[i] = 1;
			cin >> arr[i];
		}

		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			ans = max(ans, go(i, arr));
		}

		cout << ans << endl;
	}
	return 0;
}