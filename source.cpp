#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;

	if (s.size() == 1)
		return 1;

	for (int bundle = 1; bundle <= s.size() / 2; bundle++)
	{
		string pattern;
		string ret;
		int curStep = 0;
		int cntPatterns = 1;
		while (1)
		{
			if (pattern.empty())
			{
				int nextStep = curStep + bundle;
				pattern = s.substr(curStep, bundle);
				if (nextStep >= s.size())
				{
					ret += pattern;
					break;
				}
				else
				{
					cntPatterns = 1;
					curStep = nextStep;
				}
			}
			else
			{
				string temp = s.substr(curStep, bundle);
				if (temp == pattern)
				{
					cntPatterns++;
					int nextStep = curStep + bundle;
					if (nextStep >= s.size())
					{
						if (cntPatterns == 1)
							ret += pattern;
						else
							ret += to_string(cntPatterns) + pattern;
						pattern.clear();
						break;
					}
					else
						curStep += bundle;
				}
				else
				{
					if (cntPatterns == 1)
						ret += pattern;
					else
						ret += to_string(cntPatterns) + pattern;
					pattern.clear();
				}
			}
		}

		if (answer == 0)
			answer = ret.size();
		else
		{
			if (answer > ret.size())
				answer = ret.size();
		}
	}
	return answer;
}

int main()
{
	cout << solution("abcabcdede") << endl;
	return 0;
}