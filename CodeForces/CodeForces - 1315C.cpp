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

int arr[MAX], res[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, n;

    cin>>test;

    while(test--){
        cin>>n;
        set<int> s;
        for(int i = 1; i <= 2 * n; i++){
            s.insert(i);
        }

        for(int i = 0; i < n; i++){
            int val;
            cin>>arr[i];
            s.erase(arr[i]);
        }

        bool flag = 0;
        for(int i = 0; i < n; i++){
            set<int> :: iterator it = s.upper_bound(arr[i]);
            if(it == s.end()){
                flag = 1;
                break;
            }
            else{
                res[2*i] = arr[i];
                res[2*i+1] = *it;
                s.erase(*it);
            }
        }

        if(flag){
            cout<<-1<<endl;
            continue;
        }
        for(int i = 0; i < 2 * n; i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
