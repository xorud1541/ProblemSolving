#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int keySize, lockSize, homeCnt;

void rotate2(vector<vector<int>>& key)
{
	int M = key[0].size();
	vector< vector<int> > tmp(M, vector<int>(M));

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tmp[i][j] = key[M - j - 1][i];
		}
	}

	key = tmp;
}

bool isUnlock(int x, int y, vector<vector<int>>& map, vector<vector<int>>& key)
{
	int cnt = 0;
	bool ok = true;
	for (int i = 0; i < keySize; i++)
	{
		for (int j = 0; j < keySize; j++)
		{
			int keyValue = key[i][j];
			int lockValue = map[x + i][y + j];

			if (lockValue == -1)
				continue;
			else if (lockValue == 1 && keyValue == 1)
				ok = false;
			else if (lockValue == 0 && keyValue == 0)
				ok = false;
			else if (lockValue == 0 && keyValue == 0)
				continue;
			else if (lockValue == 1 && keyValue == 0)
				continue;
			else
				cnt++;
		}

		if (!ok)
			break;
	}

	if (!ok)
		return false;
	else
	{
		if (cnt == homeCnt)
			return true;
		else
			return false;
	}
}

bool search(vector<vector<int>>& map, vector<vector<int>>& key)
{
	int x, y;
	bool ok = false;
	for (int i = 0; i < keySize + lockSize - 1; i++)
	{
		for (int j = 0; j < keySize + lockSize - 1; j++)
		{
			x = i; y = j;
			if (isUnlock(x, y, map, key))
			{
				ok = true;
				break;
			}
		}
		if (ok)
			break;
	}
	return ok;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	keySize = key[0].size();
	lockSize = lock[0].size();
	int mapSize = (2 * keySize) + lockSize - 2;
	vector< vector<int> > map(mapSize, vector<int>(mapSize, -1));

	for (int i = 0; i < lockSize; i++)
	{
		for (int j = 0; j < lockSize; j++)
		{
			if (lock[i][j] == 0)
				homeCnt++;
		}
	}

	for (int i = keySize - 1; i < keySize - 1 + lockSize; i++)
	{
		for (int j = keySize - 1; j < keySize - 1 + lockSize; j++)
		{
			map[i][j] = lock[i - keySize + 1][j - keySize + 1];
		}
	}

	if (search(map, key))
		return true;

	rotate2(key);

	if (search(map, key))
		return true;
	
	rotate2(key);

	if (search(map, key))
		return true;

	rotate2(key);

	if (search(map, key))
		return true;

	return false;
}