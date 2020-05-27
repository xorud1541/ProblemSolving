#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

tuple<int, int, int> solution(vector< vector<int> >& map, int x, int y, int N)
{
	// 기저사례 조사
	// N * N 면적에 같은 숫자로 구성되어 있는지?
	int index = map[x][y];
	bool isSame = true;
	for (int i = x; i < x + N; i++)
	{
		for (int j = y; j < y + N; j++)
		{
			if (map[i][j] != index)
			{
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}

	if (isSame)
	{
		if (index == -1) return make_tuple(1, 0, 0);
		else if (index == 0) return make_tuple(0, 1, 0);
		else return make_tuple(0, 0, 1);
	}
	else
	{
		int ans1 = 0;
		int ans2 = 0;
		int ans3 = 0;
		int stride = N / 3;
		for (int i = x; i < x + N; i = i + stride)
		{
			for (int j = y; j < y + N; j = j + stride)
			{
				int a, b, c;
				tie(a, b, c) = solution(map, i, j, stride);
				ans1 += a;
				ans2 += b;
				ans3 += c;
			}
		}

		return make_tuple(ans1, ans2, ans3);
	}
}

int main()
{
	int N;
	cin >> N;

	vector< vector<int> > map(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	if (N == 1)
	{
		int index = map[0][0];
		if (index == -1)
		{
			cout << 1 << endl;
			cout << 0 << endl;
			cout << 0 << endl;
		}
		else if (index == 0)
		{
			cout << 0 << endl;
			cout << 1 << endl;
			cout << 0 << endl;
		}
		else
		{
			cout << 0 << endl;
			cout << 0 << endl;
			cout << 1 << endl;
		}
	}
	else
	{
		int a, b, c;
		tie(a, b, c) = solution(map, 0, 0, N);

		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}
	return 0;
}