#include <iostream>
#define MOD		1000000000
#define MAX		101
using namespace std;

int N;
long long dp[MAX][10];

int main()
{
	cin >> N;
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][0] = dp[i - 1][1];
			}
			else if (j == 9)
			{
				dp[i][9] = dp[i - 1][8];
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += dp[N][i];
		ans = ans % MOD;
	}

	cout << ans << endl;
	return 0;
}