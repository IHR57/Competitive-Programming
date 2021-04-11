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
    int test, n;

    cin>>test;

    while(test--){
        cin>>n;
        if(n == 1) {
            cout<<"FastestFinger"<<endl;
        }
        else if(n == 2) {
            cout<<"Ashishgup"<<endl;
        }
        else if(n & 1) {
            cout<<"Ashishgup"<<endl;
        }
        else {
            bool found = false;
            for(int i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    if(i % 2 != 0 && (n / i) != 2) {
                        found = true;
                    }
                    else if((n / i) % 2 != 0 && i != 2) {
                        found = true;
                    }
                }
            }
            if(found) {
                cout<<"Ashishgup"<<endl;
            }
            else{
                cout<<"FastestFinger"<<endl;
            }
        }
    }

    return 0;
}

