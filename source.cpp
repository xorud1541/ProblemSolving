#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef struct _mInfo
{
	string start;
	string end;
	string song;
	string notes;
} mInfo;

mInfo parser(string musicinfo)
{
	mInfo info;
	vector<string> elements;
	string temp;
	for (int i = 0; i < musicinfo.size(); i++)
	{
		char c = musicinfo[i];
		if (c == ',')
		{
			elements.push_back(temp);
			temp.clear();
		}
		else
		{
			temp += c;
		}
	}
	
	if (!temp.empty())
		elements.push_back(temp);

	info.start = elements[0]; // 0 : 시작시각
	info.end = elements[1];   // 1 : 끝나는시각
	info.song = elements[2];  // 2 : 노래제목
	info.notes = elements[3]; // 3 : 음표들

	return info;
}

int toMin(string time)
{
	string hour = time.substr(0, 2);
	string min = time.substr(3, 2);

	return atoi(hour.c_str()) * 60 + atoi(min.c_str());
}

string makeSong(const mInfo& info)
{
	int runTime = toMin(info.end) - toMin(info.start);

	vector<string> notes;
	string temp;
	for (int i = 0; i < info.notes.size(); i++)
	{
		char c = info.notes[i];
		if (c == '#')
		{
			temp += c;

			notes.push_back(temp);
			temp.clear();
		}
		else
		{
			if (temp.empty())
			{
				temp += c;
			}
			else
			{
				notes.push_back(temp);
				temp.clear();

				temp += c;
			}
		}
	}

	if (!temp.empty())
		notes.push_back(temp);

	string ret;
	for (int i = 0; i < runTime; i++)
	{
		int index = i % notes.size();

		ret += notes[index];
	}

	return ret;
}

bool hasPattern(const string& pattern, const string& alSong)
{
	int i = 0;
	int len = pattern.size();

	while (i < alSong.size())
	{
		if (alSong[i] == '#') continue;
		string temp = alSong.substr(i, len);
		if (temp.back() == 'C'
			|| temp.back() == 'A'
			|| temp.back() == 'D'
			|| temp.back() == 'F'
			|| temp.back() == 'G')
		{
			if (i + len < alSong.size())
			{
				if (alSong[i + len] == '#')
				{
					temp += '#';
				}
			}

			if (temp == pattern)
				return true;
			else
				i++;
		}
		else
		{
			if (temp == pattern)
				return true;
			else
				i++;
		}
	}

	return false;
}

string solution(string m, vector<string> musicinfos) 
{
	string answer = "";
	int runTimeOfAnswer = 0;

	for (string musicinfo : musicinfos)
	{
		mInfo info = parser(musicinfo);

		string alSong = makeSong(info); // info 로 노래를 만든

		if (hasPattern(m, alSong))
		{
			if (answer.empty())
			{
				answer = info.song;
				runTimeOfAnswer = toMin(info.end) - toMin(info.start);
			}
			else
			{
				int runTime = toMin(info.end) - toMin(info.start);
				if (runTime > runTimeOfAnswer)
				{
					answer = info.song;
					runTimeOfAnswer = toMin(info.end) - toMin(info.start);
				}
			}
		}
	}

	if (answer.empty())
		return "(None)";
	else
		return answer;
}
int main()
{
	vector<string> s;
	//s.push_back("12:00,12:14,HELLO,CDEFGAB");
	//s.push_back("13:00,13:05,WORLD,ABCDEF");

	//s.push_back("03:00,03:30,FOO,CC#B");
	//s.push_back("04:00,04:08,BAR,CC#BCC#BCC#B");

	s.push_back("12:00,12:14,HELLO,C#DEFGAB");
	s.push_back("13:00,13:05,WORLD,ABCDEF");

	cout << solution("ABC", s) << endl;
	return 0;
}