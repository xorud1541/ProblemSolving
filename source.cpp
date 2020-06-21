#include <iostream>
#include <vector>
#define MAX		1001
#define MOD		10007

using namespace std;

int cache[MAX][10];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < 10; i++)
		cache[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				cache[i][j] += cache[i - 1][k] % MOD;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += cache[N][i];
		ans %= MOD;
	}

	cout << ans << endl;
	return 0;

}