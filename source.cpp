#include <iostream>
#include <vector>
#include <string>
#define MIN     97
#define MAX		123
using namespace std;

int main()
{
	int C;
	cin >> C;
	for (int tc = 1; tc <= C; tc++)
	{
		vector<string> m[MAX][MAX];

		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			int end_index = s.size() - 1;
			m[s[0]][s[end_index]].push_back(s);
		}

		for (int i = MIN; i < MAX; i++)
		{
			for (int j = MIN; j < MAX; j++)
			{

			}
		}
	}
	return 0;
}