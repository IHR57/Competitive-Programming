#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 5000005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, d;

    cin>>m>>d;

    int cnt = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 10; j <= d; j++){
            if(j % 10  >= 2 && (j / 10) >= 2){
                int ans = (j % 10) * (j / 10);
                if(ans == i)
                    cnt++;
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
