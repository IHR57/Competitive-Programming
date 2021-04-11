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
#define MAX 1000005
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
    int n;

    cin>>n;

    vector<int> v;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        v.pb(arr[i]);
    }

    sort(v.begin(), v.end());

    vector<int> ans;

    for(int i = 0; i < n; i++) {
        bool found = false;
        for(int j = 0; j < 31; j++) {
            if(binary_search(v.begin(), v.end(), arr[i] + (1<<j)) && binary_search(v.begin(), v.end(), arr[i] - (1<<j))){
                ans.clear();
                ans.pb(arr[i]);
                ans.pb(arr[i] + (1<<j));
                ans.pb(arr[i] - (1<<j));
                found = true;
                break;
            }
            else{
                if(ans.empty() && binary_search(v.begin(), v.end(), arr[i] + (1<<j))) {
                    ans.pb(arr[i]);
                    ans.pb(arr[i] + (1<<j));
                }
                else if(ans.empty() && binary_search(v.begin(), v.end(), arr[i] - (1<<j))) {
                    ans.pb(arr[i]);
                    ans.pb(arr[i] - (1<<j));
                }
            }
        }
    }

    if(ans.empty()) {
        ans.pb(arr[0]);
    }

    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
