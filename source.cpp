#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			q.push(num);
		}

		int ret = 0;
		while (!q.empty())
		{
			int a = q.top(); q.pop();
			int b = q.top(); q.pop();

			ret += a + b;

			if(!q.empty())
				q.push(a + b);
		}

		cout << ret << endl;
	}
	return 0;
}