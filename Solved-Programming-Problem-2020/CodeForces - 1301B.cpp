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

    int test;

    cin>>test;

    while(test--){
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        vector<int> v;
        int diff = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == -1){
                if(i - 1 >= 0 && arr[i-1] != -1){
                    v.pb(arr[i-1]);
                }
                if(i + 1 < n && arr[i+1] != -1){
                    v.pb(arr[i+1]);
                }
            }
            if(i)
                if(arr[i] != -1 && arr[i-1] != -1)
                    diff = max(diff, abs(arr[i] - arr[i-1]));
        }

        if(v.empty()){
            cout<<0<<" "<<5<<endl;
            continue;
        }
        sort(v.begin(), v.end());
        int x = (v[0] + v[v.size()-1]) / 2;
        for(int i = 0; i < v.size(); i++){
            diff = max(diff, abs(v[i] - x));
        }

        cout<<diff<<" "<<x<<endl;
        v.clear();
    }
    return 0;
}
