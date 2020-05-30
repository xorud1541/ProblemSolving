#include <iostream>
#include <vector>
#include <string>
using namespace std;

string recursive(int n, int t, char num)
{
	string ret;
	if (n == t)
	{
		ret += '0';
		ret += num;
		ret += '1';
		return ret;
	}
	else
	{
		ret += recursive(n, t + 1, '0');
		ret += num;
		ret += recursive(n, t + 1, '1');
		return ret;
	}
}

vector<int> solution(int n) {
	vector<int> answer;

	string s = recursive(n, 1, '0');
	for (int i = 0; i < s.size(); i++)
	{
		answer.push_back(s[i] - '0');
	}
	return answer;
}

int main()
{
	solution(3);
	return 0;
}