#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& vec, int left, int right)
{
	int N = right - left + 1;
	if (N == 1) // base case
	{
		return vec[left];
	}
	else
	{
		int mid = (right + left) / 2;
		int ret = max(solution(vec, left, mid), solution(vec, mid + 1, right));

		int l = mid;
		int r = mid + 1;
		int h = min(vec[l], vec[r]);
		int w = 0;
		while (1)
		{
			w = r - l + 1;
			int range = h * w;
			ret = max(range, ret);

			if (l > left && r < right)
			{
				if (vec[l - 1] < vec[r + 1])
				{
					h = min(h, vec[r + 1]);
					r++;
				}
				else
				{
					h = min(h, vec[l - 1]);
					l--;
				}
			}
			else if (l == left && r < right)
			{
				h = min(h, vec[r + 1]);
				r++;
			}
			else if (l > left && r == right)
			{
				h = min(h, vec[l - 1]);
				l--;
			}
			else
				break;
		}

		return ret;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> vec(N, 0);
		for (int i = 0; i < N; i++)
		{
			cin >> vec[i];
		}

		cout << solution(vec, 0, N-1) << endl;
	}
	return 0;
}