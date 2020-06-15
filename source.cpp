#include <iostream>
#include <vector>
#include <string>
#include <map>
#define MAX		200001
using namespace std;

map<long long, long long> parent;

long long find(long long x)
{
	if (parent[x] == 0)
		return x;
	else
		return parent[x] = find(parent[x]);
}


vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (int i = 0; i < room_number.size(); i++)
	{
		long long idx = room_number[i];
		long long p = find(idx);

		answer.push_back(p);
		parent[p] = p + 1;
	}

	return answer;
}

int main()
{
	vector<long long> a = { 1, 3, 4, 1, 3, 1 };

	solution(10, a);
	return 0;
}