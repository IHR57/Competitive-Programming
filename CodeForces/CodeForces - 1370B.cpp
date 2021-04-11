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

int arr[2005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, n;

    cin>>test;

    while(test--) {
        cin>>n;
        vector<ii> odd, even;
        for(int i = 0; i < 2 * n; i++) {
            cin>>arr[i];
            if(arr[i] & 1)
                odd.pb(mk(arr[i], i));
            else
                even.pb(mk(arr[i], i));
        }

        if(odd.size() == 0) {
            for(int i = 2; i < even.size(); i += 2) {
                cout<<even[i].second + 1<<" "<<even[i+1].second + 1<<endl;
            }
        }
        else if(odd.size() == 0) {
            for(int i = 2; i < odd.size(); i += 2) {
                cout<<odd[i].second + 1<<" "<<odd[i+1].second + 1<<endl;
            }
        }
        else {
            int x = odd.size(), y = even.size();
            if(x % 2 == 0 && y % 2 == 0) {
                for(int i = 2; i < x; i += 2) {
                    cout<<odd[i].second + 1<<" "<<odd[i+1].second + 1<<endl;
                }
                for(int i = 0; i < y; i += 2) {
                    cout<<even[i].second + 1<<" "<<even[i+1].second + 1<<endl;
                }
            }
            else {
                for(int i = 1; i < x; i += 2) {
                    cout<<odd[i].second + 1<<" "<<odd[i+1].second + 1<<endl;
                }
                for(int i = 1; i < y; i += 2) {
                    cout<<even[i].second + 1<<" "<<even[i+1].second + 1<<endl;
                }
            }
        }
    }
    return 0;
}

