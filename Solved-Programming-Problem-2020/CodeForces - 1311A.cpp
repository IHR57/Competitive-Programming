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
    int test, a, b;

    cin>>test;

    while(test--){
        cin>>a>>b;
        int diff = abs(a - b);
        if(a == b){
            cout<<0<<endl;
        }
        else if(a > b){
            if(diff & 1){
                cout<<2<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
        else{
            if(diff & 1){
                cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
    }

    return 0;
}
