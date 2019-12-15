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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test;
    ll n;

    cin>>test;

    while(test--){
        cin>>n;

        ll arr[] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};
        ll k = arr[0];
        int idx = 1;
        int cnt = 0;
        while(true){
            bool flag = false;
            for(int i = 1; i <= 9; i++){
                ll x = k * i;
                if(x > n){
                    flag = true;
                    break;
                }
                cnt++;
            }
            if(flag)
                break;
            k = arr[idx];
            idx++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
