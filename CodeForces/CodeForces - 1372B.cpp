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
#define MAX 200005
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

    cin>>test;

    while(test--) {
        int n;
        cin>>n;

        if(n % 2 == 0) {
            cout<<(n / 2) <<" "<<(n / 2)<<endl;
        }
        else {
            int lcm = n;
            int x, y, ansx, ansy;
            for(int i = 1; i * i <= n; i++) {
                if(n % i == 0) {
                    x = i, y = (n - i);
                    ll temp = (1LL * x * y) / __gcd(x, y);
                    if(temp < lcm) {
                        lcm = temp;
                        ansx = i, ansy = y;
                    }
                    if(i != 1 && n / i != i) {
                        x = n / i, y = (n - x);
                        ll temp = (1LL * x * y) / __gcd(x, y);
                        if(temp < lcm) {
                            lcm = temp;
                            ansx = x, ansy = y;
                        }
                    }
                }
            }

            cout<<ansx<<" "<<ansy<<endl;
        }
    }

    return 0;
}

