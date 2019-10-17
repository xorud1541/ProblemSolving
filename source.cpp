#include <iostream>
#include <queue>
#define MAX		1000000
int dp[MAX + 1];
bool visited[MAX + 1];
using namespace std;

int main()
{
	int total, src, dst, up, down;
	cin >> total >> src >> dst >> up >> down;

	dp[src] = 0;
	visited[src] = true;
	queue< int > q;
	q.push(src);

	while (!q.empty())
	{
		int x = q.front(); q.pop();

		int ux = x + up;
		int dx = x - down;

		if (ux <= total && visited[ux] == false)
		{
			dp[ux] = dp[x] + 1;
			q.push(ux);
			visited[ux] = true;
		}

		if (dx >= 1 && visited[dx] == false)
		{
			dp[dx] = dp[x] + 1;
			q.push(dx);
			visited[dx] = true;
		}
	}

	if (dp[dst] == 0)
		cout << "use the stairs" << endl;
	else
		cout << dp[dst] << endl;
	return 0;
}