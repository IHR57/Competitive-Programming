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

vector<int> v[10005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, a, b, c;

    for(int i = 1; i <= 10000; i++){
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0){
                v[i].pb(j);
                if(i / j != j)
                    v[i].pb(i / j);
            }
        }
    }
    cin>>test;


    while(test--){
        cin>>a>>b>>c;
        int MinOps = INF;
        int ansa, ansb, ansc;

        for(int i = 1; i <= 11000; i++){
            for(int j = i; j <= 11000; j += i){
                for(int k = j; k <= 11000; k += j){
                    int temp = abs(a - i) + abs(b - j) + abs(c - k);
                    if(temp < MinOps){
                        MinOps = temp;
                        ansa = i, ansb = j, ansc = k;
                    }
                }
            }
        }

        cout<<MinOps<<endl;
        cout<<ansa<<" "<<ansb<<" "<<ansc<<endl;
    }

    return 0;
}
