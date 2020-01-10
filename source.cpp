#include <iostream>
#include <vector>
#include <queue>
#define MAX		12
using namespace std;

bool isAnswer(vector< vector<int> >& arr, int n)
{
	bool ok = true;
	if (arr[3].empty())
		return false;

	for (int i = 1; i <= n; i++)
	{
		if (arr[3][i - 1] != i)
		{
			ok = false;
			break;
		}
	}
	return ok;
}

bool isMove(vector<int>& src, vector<int>& dst)
{
	if (!src.empty())
	{
		int src_back = src.back();
		int dst_back;

		if (dst.empty())
		{
			src.pop_back();
			dst.push_back(src_back);
		}
		else
		{
			dst_back = dst.back();
			if (dst_back > src_back)
			{
				src.pop_back();
				dst.push_back(src_back);
			}
			else
				return false;
		}

		return true;
	}
	else
		return false;
}

int main()
{
	int C;
	cin >> C;
	for (int tc = 1; tc <= C; tc++)
	{
		int N;
		cin >> N;

		vector< vector<int> > arr;
		for (int i = 0; i < 4; i++)
		{
			int num;
			cin >> num;
			vector<int> a(num, 0);
			for (int j = 0; j < num; j++)
			{
				cin >> a[j];
			}
			arr.push_back(a);
		}

		queue< pair<vector< vector<int> >, int> > q;

		int ans = 0;
		bool end = false;
		if (isAnswer(arr, N))
		{
			cout << ans << endl;
			return 0;
		}
		else
		{
			q.push(make_pair(arr, 0));

			while (!q.empty())
			{
				vector< vector<int> > temp = q.front().first;
				int cnt = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++)
				{
					if (isMove(temp[k], temp[(k + 1) % 4]))
					{
						if (isAnswer(temp, N))
						{
							ans = cnt + 1;
							end = true;
						}
						else
						{
							int back = temp[(k + 1) % 4].back();
							temp[k].push_back(back);
							temp[(k + 1) % 4].pop_back();
							q.push(make_pair(temp, cnt + 1));
						}
					}

					if (isMove(temp[k], temp[(k + 2) % 4]))
					{
						if (isAnswer(temp, N))
						{
							ans = cnt + 1;
							end = true;
						}
						else
						{
							int back = temp[(k + 2) % 4].back();
							temp[k].push_back(back);
							temp[(k + 2) % 4].pop_back();
							q.push(make_pair(temp, cnt + 1));
						}
					}

					if (isMove(temp[k], temp[(k + 3) % 4]))
					{
						if (isAnswer(temp, N))
						{
							ans = cnt + 1;
							end = true;
						}
						else
						{
							int back = temp[(k + 3) % 4].back();
							temp[k].push_back(back);
							temp[(k + 3) % 4].pop_back();
							q.push(make_pair(temp, cnt + 1));
						}
					}
				}

				if (end)
					break;
			}

			cout << ans << endl;
		}
	}
	return 0;
}
