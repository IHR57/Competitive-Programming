/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int mark[MAX];

class EllysThreePrimes
{
    public:
        void genSieve()
        {
            int limit = sqrt(MAX + 1);
            mark[1] = 1;
            for(int i = 4; i < MAX; i += 2)
                mark[i] = 1;
            for(int i = 3; i < MAX; i += 2){
                if(!mark[i]){
                    if(i <= limit){
                        for(int j = i * i; j < MAX; j += i * 2)
                            mark[j] = 1;
                    }
                }
            }
        }

        vector<int> getPrimes(vector<int> sums)
        {
            genSieve();
            vector<int> primes;
            for(int i = 10000; i < 100000; i++){
                if(!mark[i])
                    primes.pb(i);
            }

            vector<int> digit[MAX/10];
            for(int i = 0; i < primes.size(); i++){
                int temp = primes[i];
                while(temp){
                    digit[i].pb(temp % 10);
                    temp /= 10;
                }
                //reverse(digit[i].begin(), digit[i].end());
            }

            for(int i = 0; i < primes.size(); i++){
                for(int j = i + 1; j < primes.size(); j++){
                    int p = 1, val = 0;
                    for(int k = 4; k >= 0; k--){
                        int need = sums[k] - digit[i][k] - digit[j][k];
                        if(need > 9 || need < 0){
                            val = -1;
                            break;
                        }
                        val = (val * 10) + need;
                    }
                    if(val > 10000 && val < 100000 && !mark[val] && val > primes[j]){
                       vector<int> res;
                       res.pb(primes[i]), res.pb(primes[j]), res.pb(val);
                       return res;
                    }
                }
            }
            return {};
        }
};

// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     #ifndef ONLINE_JUDGE
//     	freopen("input.txt", "r", stdin);
//     	freopen("output.txt", "w", stdout);
//     #endif
//     EllysThreePrimes obj = EllysThreePrimes();
//     vector<int> v;
//     for(int i = 0; i < 5; i++){
//         int x;
//         cin>>x;
//         v.pb(x);
//     }
//     vector<int> ans = obj.getPrimes(v);
//     for(int i = 0; i < ans.size(); i++){
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;

//     return 0;
// }
