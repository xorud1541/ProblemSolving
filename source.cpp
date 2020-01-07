#include <cstring>
#include <math.h>
#include <vector>
#include <iostream>

#define MAX		1000000007
using namespace std;

int n;
bool isPrime[MAX + 1];

void eratosthenes()
{
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; ++i)
	{
		if (isPrime[i])
			for (int j = i * i; j <= n; j += i)
				isPrime[j] = false;
	}
}

int n;
vector<int> primes;
vector<int> sumes;
int main()
{
	cin >> n;
	vector<bool> check(MAX, true);
	for (int i = 2; i*i <= n; i++)
	{
		if (!check[i]) continue;
		for (int j = i * i; j <= n; j += i)
		{
			check[j] = false;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (check[i]) primes.push_back(i);
	}
}