#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;

	for (int bundle = 1; bundle <= s.size() / 2; bundle++)
	{
		int index = 0;
		int cntPattern = 1;
		string ret;
		string pattern;

		while (index < s.size())
		{
			if (pattern.empty())
			{
				//set pattern
				pattern = s.substr(index, bundle);
				cntPattern = 1;
				if (index + bundle >= s.size())
				{
					ret += pattern;

					int cnt = s.size() - index - 1;
					ret += s.substr(index, cnt);

					pattern.clear();
				}
				else
				{
					index += bundle;
				}
				continue;
			}
			else
			{
				//compare with pattern
				string temp = s.substr(index, bundle);
				if (temp == pattern)
				{
					cntPattern++;
					if (index + bundle >= s.size())
					{
						ret += to_string(cntPattern) + pattern;

						int cnt = s.size() - index - 1;
						ret += s.substr(index, cnt);

						pattern.clear();
					}
					else
					{
						index += bundle;
					}
				}
				else
				{
					if (cntPattern != 1)
						ret += to_string(cntPattern) + pattern;
					else
						ret += pattern;
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

		ret.clear();
	}
	return answer;
}

int main()
{
	cout << solution("aabbaccc") << endl;
	return 0;
}