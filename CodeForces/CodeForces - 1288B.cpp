//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int digitCnt = 0;

bool numOfDigit(int x)
{
    bool flag = true;
    while(x){
        digitCnt++;
        if(x % 10 != 9){
            flag = false;
        }
        x /= 10;
    }

    return flag;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int x = 1, y = 999;

//    int pow[12];
//
//    pow[0] = 1;
//    for(int i = 1; i <= 9; i++)
//        pow[i] = (10 * pow[i-1]);
//
//    int cnt = 0;
//    for(int i = x; i <= y; i++){
//        for(int j = x; j <= y; j++){
//            int temp = (i * j) + i + j;
//            int tx = numOfDigit(j);
//            int tt = i * pow[tx] + j;
//            if(temp == tt){
//                cnt++;
//            }
//        }
//    }
//
//    cout<<cnt<<endl;

    int test;

    cin>>test;

    while(test--){
        ll a, b;

        cin>>a>>b;
        int cnt = 0;
        ll x = 9;
        while(x <= b){
            cnt++;
            x = (x * 10) + 9;
        }

        ll ans = 1LL * a * cnt;

        cout<<ans<<endl;
    }

    return 0;
}
