#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX		101
using namespace std;

int main()
{
	int C;
	cin >> C;
	for (int tc = 1; tc <= C; tc++)
	{
		int N;
		cin >> N;
		priority_queue<int, vector<int>, greater<int>> q;
		
		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			q.push(num);
		}

		int ans = 0;
		while (q.size() > 2)
		{
			int a = q.top(); q.pop();
			int b = q.top(); q.pop();
			ans += a + b;

			q.push(a + b);
		}

		int a = q.top(); q.pop();
		int b = q.top(); q.pop();

		ans += a + b;

		cout << ans << endl;
	}
	return 0;
}