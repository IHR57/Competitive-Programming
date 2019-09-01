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
#define MAX 1000005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int ans[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int test, n, s;

    cin>>test;

    while(test--){
        cin>>n>>s;
        if(n % 2  == 0 && s % 2){
            cout<<-1<<endl;
            continue;
        }
        if(n == 1 && s <= 9){
            cout<<s<<endl;
            continue;
        }
        if(s > (9 * n) || s <= 1){
            cout<<-1<<endl;
            continue;
        }

        int rem = s;
        bool answerExist = true;
        for(int i = 0; i < (n + 1) / 2; i++){
            bool flag = false;
            for(int j = 9; j >= 0; j--){
                if(i == n - i - 1){
                    if(j == rem){
                        ans[i] = rem;
                        flag = true;
                        break;
                    }
                }
                else if(j + j <= rem){
                    rem -= (2 * j);
                    ans[i] = ans[n-i-1] = j;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                answerExist = false;
                break;
            }
        }

        if(!answerExist)
            cout<<-1<<endl;
        else{
            for(int i = 0; i < n; i++)
                cout<<ans[i];
            cout<<endl;
        }

    }

    return 0;
}
