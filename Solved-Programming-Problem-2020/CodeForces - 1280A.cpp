//Date: 29/03/2020
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test, x;
    string str;

    cin>>test;

    while(test--){
        cin>>x;
        cin>>str;
        string tempStr = str;
        ll len = str.size();

        for(int i = 0; i < x; i++){
            int k = tempStr[i] - 48;
            len = (len + (1LL * (k - 1) * (len - i - 1)) % MOD) % MOD;
            if(len < 0)
                len += MOD;
            //cout<<len<<endl;
            int Sz = tempStr.size();
            if(tempStr.size() <= x){
                for(int j = 0; j < k - 1; j++){
                    bool flag = false;
                    for(int m = i + 1; m < Sz; m++){
                        tempStr += tempStr[m];
                        if(tempStr.size() > x){
                            flag = true;
                            break;
                        }
                    }
                    if(flag)
                        break;
                }
            }
            //cout<<tempStr<<endl;
        }

        cout<<(len + MOD) % MOD<<endl;
    }

}
