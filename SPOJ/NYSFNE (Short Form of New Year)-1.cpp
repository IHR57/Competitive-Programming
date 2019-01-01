#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long llint;
const int Mod = 100;

llint bigMod(llint a, llint b)
{
	if(b == 0)
		return 1;
	llint x = bigMod(a, b / 2);

	x = (x * x) % Mod;

	if(b % 2 == 1){		//if power is odd we have to multiply a
		x = (x * a) % Mod;
	}

	return x;
}

int main()
{
	llint a, b, result;

	while(scanf("%lld %lld", &a, &b) == 2){
		result = bigMod(a, b);
		if(result < 10)
            printf("0%lld\n", result);
        else
            printf("%lld\n", result);
	}

	return 0;
}
