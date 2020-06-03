#include <iostream>
#include <vector>
#include <algorithm>

#define MAX		1001
using namespace std;

int cache[MAX];

int solution(int N, vector<int>& arr)
{
	int last = arr.size();
	if (N == last - 1)
	{
		return 1;
	}

	int& ret = cache[N];
	if (ret != 1)
		return ret;

	int cur = arr[N];
	for (int i = N + 1; i < last; i++)
	{
		int next = arr[i];
		if (cur < next)
		{
			ret = max(ret, solution(i, arr) + 1);
		}
	}
	return ret;
}

int main()
{
	int N;
	int ans = 0;
	cin >> N;
	vector<int> arr(N, 0);
	
	for (int i = 0; i < N; i++) cache[i] = 1;
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		ans = max(ans, solution(i, arr));
	}
	cout << ans << endl;
	return 0;
}