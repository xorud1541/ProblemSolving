#include <iostream>
#include <vector>
#include <algorithm>
#define SWITHES		10
#define CLOCKS		16
#define INF			100000007
using namespace std;

const char linked[SWITHES][CLOCKS + 1] =
{
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......XXX.X.X...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

int T;

void move(vector<int>& clocks, int num)
{
	int ret = clocks[num];
	switch (num)
	{
	case 12:
		clocks[num] = 3;
		break;
	case 3:
		clocks[num] = 6;
		break;
	case 6:
		clocks[num] = 9;
		break;
	case 9:
		clocks[num] = 12;
	default:
		break;
	}
}

int run(vector<int>& clocks, int swithNum)
{
	//push
	for (int i = 0; i < CLOCKS; i++)
	{
		if (linked[swithNum][i] == 'x')
		{
			move(clocks, i);
		}
	}

	bool flag = true;
	for (int i = 0; i < CLOCKS; i++)
	{
		if (clocks[i] != 12)
		{
			flag = false;
			break;
		}
	}

	if (flag)
		return 0;

	int ans = INF;
	for (int i = 1; i < 4; i++)
	{
		int ret;
		if (swithNum + 1 < 10)
			ret = run(clocks, swithNum + 1);
		else
			continue;

		ans = min(ans, ret + i);
	}
	return ans;
}

int main()
{
	cin >> T;
	while (T--)
	{
		vector<int> clocks(CLOCKS, 0);
		for (int i = 0; i < CLOCKS; i++)
			cin >> clocks[i];

		int switchNum = 0;
		int ans = INF;
		for (int i = 1; i < 4; i++)
		{
			int ret = run(clocks, switchNum);

			ans = min(ans, i + ret);
		}
		cout << ans << endl;
	}
	return 0;
}