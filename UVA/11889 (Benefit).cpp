#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string.h>
#define MAX 3200
using namespace std;

typedef long long int llint;

int primes[500], mark[MAX], listA[MAX], listB[MAX];
int counter = 0;

llint Power(int n, int m)       //calculate n^m
{
	llint result = 1;

	for(int i = 1; i <= m; i++)
		result *= n;

	return result;
}

void genSieve()
{
	int limit = sqrt(MAX + 1);

	mark[1] = 1;

	for(int i = 4; i < MAX; i += 2)
		mark[i] = 1;

	primes[counter++] = 2;

	for(int i = 3; i < MAX; i += 2){
		if(!mark[i]){
			primes[counter++] = i;
			if(i <= limit){
				for(int j = i * i; j < MAX; j += i * 2)
					mark[j] = 1;
			}
		}
	}
}

void genList(int first, int second)     //generating prime factor list of two number
{
	int idx = 0, pf = primes[idx];

	while(pf * pf <= first){
		while(first % pf == 0){
			first /= pf;
			listA[pf]++;
		}
		pf = primes[++idx];
	}

	if(first != 1){
		listA[first]++;
	}

	idx = 0, pf = primes[idx];
	while(pf * pf <= second){
		while(second % pf == 0){
			second /= pf;
			listB[pf]++;
		}
		pf = primes[++idx];
	}

	if(second != 1){
		listB[second]++;
	}
}

int main()
{
	int test, firstNumber, lcm;
	llint result;

	genSieve();
	scanf("%d", &test);

	while(test--){
		scanf("%d %d", &firstNumber, &lcm);

		for(int i = 0; i < MAX; i++)
            listA[i] = 0, listB[i] = 0;     //initialize
		if(lcm % firstNumber != 0){
			printf("NO SOLUTION\n");
		}
		else{
			genList(firstNumber, lcm);		//generate prime factor list of both number
			int sqrtN = sqrt(lcm + 1);
			result = 1;

			for(int i = 0; i < MAX; i++){
				if(listA[primes[i]] > listB[primes[i]]){
					result  = result * Power(primes[i], listA[primes[i]]);
				}
				else if(listB[primes[i]] > listA[primes[i]])
					result = result * Power(primes[i], listB[primes[i]]);
			}

			printf("%lld\n", result);
		}
	}

	return 0;
}
