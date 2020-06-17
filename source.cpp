#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, S, answer = 0;
	cin >> N >> S;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		vector<int> indexs(N, 0);
		for (int j = 0; j < i; j++)
			indexs[j] = 1;


		do
		{
			int sum = 0;
			for (int i = 0; i < N; i++)
			{
				if (indexs[i])
				{
					sum += arr[i];
				}
			}

			if (sum == S)
				answer++;

		} while (prev_permutation(indexs.begin(), indexs.end()));

	}

	cout << answer << "\n";
	return 0;
}