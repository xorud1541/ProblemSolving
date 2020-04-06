#include <iostream>
using namespace std;

int T;
int main()
{
	cin >> T;
	while (T--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		if (x1 == x2 && (a != 0 || b != 0))
			cout << "NO" << endl;
		else if (y1 == y2 && (c != 0 || d != 0))
			cout << "NO" << endl;
		else
		{
			int nx = x - a + b;
			int ny = y - c + d;
			if (nx >= x1 && nx <= x2 && ny >= y1 && ny <= y2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}