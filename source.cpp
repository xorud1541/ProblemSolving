#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int answer;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
vector<pair<int, pair<int, int>>> Edge;
vector<int> Parent;

int Find_Parent(int A)
{
	if (A == Parent[A]) return A;
	return Parent[A] = Find_Parent(Parent[A]);
}

void Union(int A, int B)
{
	A = Find_Parent(A);
	B = Find_Parent(B);
	Parent[B] = A;
}

bool Same_Parent(int A, int B)
{
	A = Find_Parent(A);
	B = Find_Parent(B);
	if (A == B) return true;
	return false;
}

void Find_Group_Dis(vector< vector<int> >& land, vector< vector<int> >& map)
{
	for (int x = 0; x < land.size(); x++)
	{
		for (int y = 0; y < land.size(); y++)
		{
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && ny >= 0 && nx < land.size() && ny < land.size())
				{
					if (map[x][y] != map[nx][ny])
					{
						Edge.push_back(make_pair(abs(land[x][y] - land[nx][ny]), make_pair(map[x][y], map[nx][ny])));
					}
				}
			}
		}
	}
}

void Kruskal(int group_cnt)
{
	Parent.resize(group_cnt);
	sort(Edge.begin(), Edge.end());
	for (int i = 0; i < group_cnt; i++) Parent[i] = i;
	for (int i = 0; i < Edge.size(); i++)
	{
		int N1 = Edge[i].second.first;
		int N2 = Edge[i].second.second;
		int cost = Edge[i].first;

		if (Same_Parent(N1, N2) == false)
		{
			Union(N1, N2);
			answer = answer + cost;
		}
	}
}

void grouping(int i, int j, int height, int group, vector< vector<int> >& map, vector< vector<int> >& land)
{
	map[i][j] = group;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;

			if (map[nx][ny] == 0)
			{
				int diff = abs(land[nx][ny] - land[x][y]);
				if (diff > height)
					continue;
				else
				{
					q.push(make_pair(nx, ny));
					map[nx][ny] = group;
				}
			}
		}
	}
}

int solution(vector<vector<int>> land, int height) {
	N = land[0].size();
	vector< vector<int> > map(N, vector<int>(N, 0));

	int group = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0)
			{
				grouping(i, j, height, group, map, land);
				group++;
			}
		}
	}

	Find_Group_Dis(land, map);
	Kruskal(group);

	return answer;
}