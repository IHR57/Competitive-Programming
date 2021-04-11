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

int arr[MAX];
bool mark[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, n;

    cin>>test;

    while(test--) {
        cin>>n;
        memset(mark, 0, sizeof(mark));

        bool flag = true;
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
            int m = (n + (i + arr[i]) % n) % n;
            mark[m] = true;
        }

        for(int i = 0; i < n; i++) {
            if(!mark[i]) {
                flag = false;
                break;
            }
        }

        (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }

    return 0;
}

