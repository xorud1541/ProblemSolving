// 소인수 분해 알고리즘
#include <vector>

using namespace std;

vector<int> factorSimple(int n)
{
	vector<int> ret;
	int sqrtn = int(sqrt(n));
	for(int div = 2; div <= sqrtn; ++div)
		while (n % div == 0)
		{
			n /= div;
			ret.push_back(div);
		}
	if (n > 1) ret.push_back(n);
	return ret;
}