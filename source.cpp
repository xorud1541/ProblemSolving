// O(��Ʈ(n)) �ð��� �����ϴ� �Ҽ� �Ǻ� �˰���
#include <math.h>
#include <iostream>

using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;

	if (n % 2 == 0) return false;

	int sqrtn = int(sqrt(n));
	for (int div = 3; div <= sqrtn; div += 2)
		if (n % div == 0)
			return false;
	return true;
}

int main()
{
	cout << isPrime(5) << endl;
	cout << isPrime(6) << endl;
	cout << isPrime(13) << endl;
	return 0;
}