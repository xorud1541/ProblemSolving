#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

set<string> s;
vector< vector<int> > indexs;
vector<int> ret;
int taken[9];
int answer;

bool isSame(string& a, string& b)
{
	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != '*' && a[i] != b[i])
				return false;
		}

		return true;
	}
	else
		return false;
}

void dfs(vector<string>& user_id, vector<string>& banned_id) {
	int len = ret.size();

	if (len == indexs.size())
	{
		vector<int> vec = ret;
		sort(vec.begin(), vec.end());
		string tmp;
		for (int i : vec)
			tmp += i + '0';

		s.insert(tmp);
		return;
	}

	
	vector<int> index = indexs[len];
	for (int i : index)
	{
		if (!taken[i])
		{
			taken[i] = true;
			ret.push_back(i);

			dfs(user_id, banned_id);

			ret.pop_back();
			taken[i] = false;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {

	for (int i = 0; i < banned_id.size(); i++)
	{
		vector<int> a;
		for (int j = 0; j < user_id.size(); j++)
		{
			if (isSame(banned_id[i], user_id[j]))
			{
				a.push_back(j);
			}
		}
		indexs.push_back(a);
	}

	dfs(user_id, banned_id);

	answer = s.size();

	return answer;
}

int main()
{
	vector<string> user = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> ban = { "fr*d*", "*rodo", "******", "******" };

	int a = solution(user, ban);
	return 0;
}