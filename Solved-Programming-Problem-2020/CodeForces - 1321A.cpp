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

int a[105], b[105];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++)
        cin>>b[i];

    bool flag = false;
    int cnta = 0, cntb = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            flag = true;
            if(a[i] == 1)
                cnta++;
            else
                cntb++;
        }
    }

    if(!flag || (cnta == 0)){
        cout<<-1<<endl;
        return 0;
    }

    if(cnta > cntb){
        cout<<1<<endl;
    }
    else{
        int ans = ((cntb + 1) % cnta == 0) ? (cntb + 1) / cnta : (cntb + 1) / cnta + 1;
        cout<<ans<<endl;
    }

    return 0;
}
