#include <iostream>
#include <vector>
#include <algorithm>
#define MAX		1001

using namespace std;

int cache[MAX];
int arr[MAX];
int N;
int go(int x)
{
	if (x == N - 1)
	{
		return arr[x];
	}

	int& ret = cache[x];
	if (ret != 0)
		return ret;

	int num = arr[x];
	ret = num;
	for (int i = x + 1; i < N; i++)
	{
		if(arr[i] > num)
			ret = max(ret, num + go(i));
	}
	return ret;
}

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int ans = 0;
	
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, go(i));
	}

	cout << ans << endl;
	return 0;
}