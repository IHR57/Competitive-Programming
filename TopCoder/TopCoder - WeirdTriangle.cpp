#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

class WeirdTriangle
{
	public:
		long long findAllTriangle(int N, vector <int> B, int seed, int MX)
		{
			vector<ll> A(N+5), L(MAX);
			A[0] = seed;
			for(int i = 1; i < N; i++)
				A[i] = (A[i-1]*1103515245 + 12345) % 2147483648;

			for(int i = 0; i < B.size(); i++){
				L[i] = B[i];
			}

			for(int i = B.size(); i < N; i++){
				L[i] = 2 * (A[i] % MX) - MX + 1;
			}
			ll ans = 0, cnt = 0;
			for(int i = 0; i < N; i++){
				if(L[i] > 0)
					cnt++;
			}

			if(cnt >= 3)
				ans = cnt * (cnt - 1) / 2 * (cnt - 2) / 3;

			return ans;
		}
};