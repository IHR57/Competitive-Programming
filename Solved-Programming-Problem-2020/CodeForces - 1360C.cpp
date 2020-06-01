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

int arr[MAX];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, n;

    cin>>test;

    while(test--) {
        cin>>n;
        int odd = 0, even = 0;
        vector<int> v;
        set<int> s;
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
            if(arr[i] & 1){
                odd++;
                v.pb(arr[i]);
            }
            else
                even++;
            s.insert(arr[i]);
        }

        if(odd % 2 == 0 && even % 2 == 0) {
            cout<<"YES"<<endl;
            continue;
        }

        bool found = false;
        for(int i = 0; i < v.size(); i++) {
            if(s.count(v[i] - 1) || s.count(v[i] + 1)){
                found = true;
                break;
            }
        }

        (found) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    }

    return 0;
}
