#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

typedef struct pos
{
	int x;
	int y;
} Pos;

bool compare(Pos& a, Pos& b)
{
	return a.x < b.x;
}

bool compare2(Pos& a, Pos& b)
{
	if (a.y != b.y)
		return a.y < b.y;
}

vector< Pos > dots;

int get_distance(const Pos& a, const Pos& b)
{
	return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}

int search(int low, int high)
{
	int ret = 0;
	int cnt = high - low + 1;

	if (cnt == 2)
	{
		ret = get_distance(dots[low], dots[high]);
	}
	else if (cnt == 3)
	{
		int mid = low + 1;
		int x = get_distance(dots[low], dots[high]);
		int y = get_distance(dots[low], dots[mid]);
		int z = get_distance(dots[mid], dots[high]);

		ret = min({ x, y, z });
	}
	else
	{
		int left = 0;
		int right = 0;
		int mid = (low + high) / 2;
		left = search(low, mid);
		right = search(mid + 1, high);

		int len = min(left, right);

		int x = dots[mid].x;

		vector<Pos> dots2;
		for (int i = low; i <= high; i++)
		{
			int diff = x - dots[i].x;
			if (diff * diff < len)
				dots2.push_back(dots[i]);
		}

		sort(dots2.begin(), dots2.end(), compare2);

		for (int i = 0; i < dots2.size(); i++)
		{
			for (int j = i + 1; j < dots2.size(); j++)
			{
				if ((dots2[j].y - dots2[i].y) * (dots2[j].y - dots2[i].y) < len)
				{
					if (ret == 0)
					{
						ret = get_distance(dots2[i], dots2[j]);
					}
					else
					{
						ret = min(ret, get_distance(dots2[i], dots2[j]));
					}
				}
			}
		}
	}
	return ret;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		Pos p;
		cin >> p.x >> p.y;
		dots.push_back(p);
	}

	sort(dots.begin(), dots.end(), compare);

	int low = 0;
	int high = dots.size() - 1;

	int ret = search(low, high);

	cout << ret << endl;
	return 0;
}