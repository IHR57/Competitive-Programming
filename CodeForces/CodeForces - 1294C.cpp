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
        vector<int> divisors;
        set<int> s;
        for(ll i = 2; i * i <= n; i++){
            if(n % i == 0){
                divisors.pb(i);
                s.insert(i);
                if(n / i != i){
                    divisors.pb(n / i);
                    s.insert(n / i);
                }
            }
        }

        sort(divisors.begin(), divisors.end());

        ll a, b, c;
        bool flag = false;
        for(int i = 0; i < divisors.size(); i++){
            for(int j = i + 1; j < divisors.size(); j++){
                ll t = divisors[i] * divisors[j];
                if(n % t == 0){
                    if(s.count(n / t) && (n / t) != divisors[i] && (n / t) != divisors[j]){
                        flag = true;
                        a = divisors[i], b = divisors[j], c = n / t;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
        if(flag){
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
