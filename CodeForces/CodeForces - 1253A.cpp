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

int test, arr[MAX], b[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>test;

    while(test--){
        int n;
        cin>>n;
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        for(int i = 0; i < n; i++)
            cin>>b[i];
        bool flag = true, foundDiff = false;
        int k;
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(arr[i] != b[i]){
                if(arr[i] > b[i]){
                    flag = false;
                    break;
                }
                else{
                    if(!foundDiff){
                        foundDiff = true;
                        k = b[i] - arr[i];
                    }
                    else{
                        if(b[i] - arr[i] != k){
                            flag = false;
                            break;
                        }
                    }
                    v.pb(i);
                }
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        if(v.size()){
            for(int i = 0; i < v.size() - 1; i++){
                if(v[i] + 1 != v[i+1]){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }

    return 0;
}
