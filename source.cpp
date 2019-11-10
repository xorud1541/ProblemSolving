#include <iostream>
#include <vector>
#define MAX		100
using namespace std;

int R, C, M;

struct Shark
{
	Shark(int r, int c, int s, int d, int z)
		: x(r), y(c), vel(s), dir(d), size(z)
	{};

	~Shark()
	{};

	void Up(int dist)
	{
		if (dist > x - 1)
		{
			dir = 2; //down
			dist = dist - x + 1;
			x = 1;
			Down(dist);
		}
		else
			x = x - dist;
	}

	void Down(int dist)
	{
		if (dist > R - x)
		{
			dir = 1;
			dist = dist - R + x;
			x = R;
			Up(dist);
		}
		else
			x = x + dist;
	}

	void Left(int dist)
	{
		if (dist > y - 1)
		{
			dir = 3;
			dist = dist - y + 1;
			y = 1;
			Right(dist);
		}
		else
			y = y - dist;
	}

	void Right(int dist)
	{
		if (dist > C - y)
		{
			dir = 4;
			dist = dist - C + y;
			y = C;
			Left(dist);
		}
		else
			y = y + dist;
	}

	void Move()
	{
		switch (dir)
		{
		case 1:
			Up(vel);
			break;
		case 2:
			Down(vel);
			break;
		case 3:
			Right(vel);
			break;
		case 4:
			Left(vel);
			break;
		}
	}
	
	pair<int, int> getPos() const { return make_pair(x, y); }

	int getSize() const { return size; }

	int x;
	int y;
	int vel;
	int dir;
	int size;
};
int main()
{
	cin >> R >> C >> M;
	int ans = 0;
	vector<Shark> sharks;
	if (M == 0)
	{
		cout << ans << endl;
		return 0;
	}

	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Shark shark(r, c, s, d, z);
		sharks.push_back(shark);
	}

	for (int person = 1; person <= C; person++)
	{
		int depth = R + 1;
		bool getShark = false;
		vector<Shark>::iterator iter, target;
		for (iter = sharks.begin(); iter != sharks.end(); ++iter)
		{
			pair<int, int> pos = iter->getPos();
			if (pos.second == person)
			{
				//사람이랑 같은 곳에 있을 경우
				
				if (depth > pos.first)
				{
					depth = pos.first;
					target = iter;
					getShark = true;
				}
			}
		}

		if (getShark)
		{
			ans = ans + target->getSize();
			sharks.erase(target);
		}

		vector< vector<Shark>::iterator > eraseList;
		vector< vector< vector<Shark>::iterator > >map(R + 1, vector< vector<Shark>::iterator >(C + 1, sharks.end()));
		for (iter = sharks.begin(); iter != sharks.end(); ++iter)
		{
			iter->Move();
			pair<int, int> pos = iter->getPos();
			if (map[pos.first][pos.second] == sharks.end())
			{
				map[pos.first][pos.second] = iter;
			}
			else
			{
				vector<Shark>::iterator other = map[pos.first][pos.second];
				if (other->getSize() < iter->getSize())
				{
					map[pos.first][pos.second] = iter;
					eraseList.push_back(other);
				}
				else
					eraseList.push_back(iter);
			}
		}

		for (auto it : eraseList)
		{
			sharks.erase(it);
		}
	}

	cout << ans << endl;
	return 0;
}