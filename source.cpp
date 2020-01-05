#include <iostream>
#include <vector>
#include <string>
using namespace std;

string solution(string::iterator& iter)
{
	string out;
	if (*iter == 'b')
	{
		out += 'b';
	}
	else if (*iter == 'w')
	{
		out += 'w';
	}
	else // x
	{
		iter++;
		string a = solution(iter); //b 

		iter++;
		string b = solution(iter); //b

		iter++;
		string c = solution(iter); //x

		iter++;
		string d = solution(iter); //w

		out = 'x' + c + d + a + b;
	}

	return out;
}

int main()
{
	int C;
	cin >> C;
	for (int tc = 1; tc <= C; tc++)
	{
		string s;
		cin >> s;
		string::iterator iter = s.begin();
		string out = solution(iter);
		cout << out << endl;
	}
	return 0;
}