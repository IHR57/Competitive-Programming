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

int arr[MAX], cnt[MAX*10], dcnt[MAX*10];
vector<int> v[MAX*10];

bool Check(int l, int r)
{
    //cout<<l<<" "<<r<<endl;
    for(int i = l; i <= r; i++){
        if(arr[i] < 0){
            if(!cnt[abs(arr[i])]){
                return false;
            }
            else{
                cnt[abs(arr[i])]--;
            }
        }
        else if(arr[i] > 0){
            cnt[arr[i]]++;
            dcnt[arr[i]]++;
            if(cnt[arr[i]] > 1 || dcnt[arr[i]] > 1){
                return false;
            }
        }
        //cout<<i<<endl;
    }
    for(int i = l; i <= r; i++){
        if(arr[i] > 0){
            dcnt[arr[i]] = 0;
            cnt[arr[i]] = 0;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] < 0){
            v[abs(arr[i])].pb(i);
        }
    }

    int x = 0;
    vector<int> ans;
    while(true){
        if(x >= n)
            break;
        if(arr[x] < 0){
            cout<<-1<<endl;
            return 0;
        }
        if(v[arr[x]].size() == 0){
            cout<<-1<<endl;
            return 0;
        }
        int t = lower_bound(v[arr[x]].begin(), v[arr[x]].end(), x) - v[arr[x]].begin();
        if(t >= v[arr[x]].size()){
            cout<<-1<<endl;
            return 0;
        }
        int temp = v[arr[x]][t];
        int y = temp;
        for(int i = x + 1; i < y; i++){
            if(arr[i] > 0){
                if(v[arr[i]].size()){
                    int tt = lower_bound(v[arr[i]].begin(), v[arr[i]].end(), i) - v[arr[i]].begin();
                    if(tt >= v[arr[i]].size()){
                        cout<<-1<<endl;
                        return 0;
                    }
                    else{
                        y = max(v[arr[i]][tt], y);
                    }
                }
                else{
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
        if(Check(x, y)){
            ans.pb(y - x + 1);
            x = y + 1;
        }
        else{
            cout<<-1<<endl;
            return 0;
        }

    }

    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
