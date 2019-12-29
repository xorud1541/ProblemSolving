#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

map<string, int> m;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

string map_string(vector< vector<int> >& map)
{
	string s;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			s += map[i][j] + '0';
		}
	}
	return s;
}

void string_map(const string& s, vector< vector<int> >& map)
{
	map[0][0] = s[0] - '0'; map[0][1] = s[1] - '0'; map[0][2] = s[2] - '0';
	map[1][0] = s[3] - '0'; map[1][1] = s[4] - '0'; map[1][2] = s[5] - '0';
	map[2][0] = s[6] - '0'; map[2][1] = s[7] - '0'; map[2][2] = s[8] - '0';
}

pair<int, int> get_zero(vector< vector<int> >& map)
{
	pair<int, int> p;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[i][j] == 0)
			{
				p = make_pair(i, j);
				break;
			}
		}
	}
	return p;
}

int main()
{
	string ans = "123456780";

	vector< vector<int> > map(3, vector<int>(3, 0));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> map[i][j];
		}
	}

	string t = map_string(map);
	m[t] = 0;

	queue<string> q;
	q.push(t);
	bool ok = false;
	while (!q.empty())
	{
		string str = q.front(); q.pop();
		int cnt = m[str];

		vector< vector<int> > temp_map(3, vector<int>(3, 0));
		string_map(str, temp_map);

		pair<int, int> p = get_zero(temp_map);
		int x = p.first;
		int y = p.second;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

			swap(temp_map[x][y], temp_map[nx][ny]);

			string s = map_string(temp_map);
			if (m.count(s) == 0)
			{
				m[s] = cnt + 1;
				if (s == ans)
				{
					ok = true;
					break;
				}
				q.push(s);
			}

			swap(temp_map[x][y], temp_map[nx][ny]);
		}

		if (ok)
			break;
	}

	if (m.count(ans) != 0)
		cout << m[ans] << endl;
	else
		cout << -1 << endl;

	return 0;
}