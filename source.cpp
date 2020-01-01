#include <iostream>
#include <vector>
using namespace std;

int N;
int main()
{
	cin >> N;
	vector< long long > pays(N, 0);
	vector< long long > line(N - 1, 0);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> line[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> pays[i];
	}

	long long min = pays[0];
	long long ans = 0;

	for (int i = 0; i < N-1; i++)
	{
		long long len = line[i];
		long long pay = pays[i];
		if (min > pay)
			min = pay;

		ans = ans + min * len;
	}

	cout << ans << endl;
	return 0;
}