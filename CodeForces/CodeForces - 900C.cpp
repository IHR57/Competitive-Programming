#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, p[MAX], cs[MAX];
int nextMax[MAX], nextClose[MAX][2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n;

    vector<int> dist(n + 1, 1);
    dist[0] = 0;

    for(int i = 0; i < n; i++){
        cin>>p[i];
    }

    if(n <= 2){
        cout<<"1"<<endl;
        return 0;
    }

    set<int> s;
    s.insert(p[n-1]);
    for(int i = n - 1; i >= 0; i--){
        set<int> :: iterator it;
        if(!s.empty() && p[i] < *s.rbegin()){
            it = s.lower_bound(p[i]);
            nextMax[p[i]] = *it;
            while(true){
                if(*s.begin() >= p[i]){
                    break;
                }
                s.erase(*s.begin());
            }
            s.insert(p[i]);
        }
        else{
            s.clear();
            s.insert(p[i]);
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout<<p[i]<<" --> "<<nextMax[p[i]][0]<<" "<<nextMax[p[i]][1]<<endl;
    // }

    for(int i = n - 1; i >= 0; i--){
        dist[p[i]] = (nextMax[p[i]] == 0) ? 1 : dist[nextMax[p[i]]] + 1;
    }
    s.clear();
    s.insert(p[0]);
    cs[0] = 1;
    for(int i = 1; i < n; i++){
        if(p[i] > *s.rbegin()){
            cs[i] = cs[i-1] + 1;
        }
        else
            cs[i] = cs[i-1];
        s.insert(p[i]);
    }

    //cout<<*max_element(cs, cs + n)<<endl;

    int ans = 0, idx = p[0];
    int Mx = 0;
    for(int i = 1; i < n; i++){
        Mx = max(Mx, p[i]);
        ans = max(ans, dist[Mx]);
    }
    Mx = 0;
    int firstIdx = -1, secondIdx = -1, k = 1;
    for(int i = 0; i < n - 1; i++){
        Mx = max(Mx, p[i]);
        if(firstIdx == -1){
            for(int j = k; j < n; j++){
                if(p[j] > Mx && firstIdx == -1)
                    firstIdx = j;
                else if(p[j] > Mx){
                    secondIdx = j;
                    break;
                }
                k = j + 1;
            }
        }
        else if(Mx >= p[firstIdx]){
            if(Mx > p[secondIdx]){
                firstIdx = -1, secondIdx = -1;
                for(int j = k; j < n; j++){
                    if(p[j] > Mx && firstIdx == -1)
                        firstIdx = j;
                    else if(p[j] > Mx){
                        secondIdx = j;
                        break;
                    }
                    k = j + 1;
                }
            }
            else{
                firstIdx = secondIdx;
                secondIdx = -1;
                for(int j = firstIdx + 1; j < n; j++){
                    if(p[j] > Mx){
                        secondIdx  = j;
                        break;
                    }
                    k = j + 1;
                }
            }
        }
        nextClose[Mx][0] = p[firstIdx];
        nextClose[Mx][1] = p[secondIdx];
        //cout<<Mx<<" -> "<<nextClose[Mx][0]<<" "<<nextClose[Mx][1]<<endl;
    }
    Mx = p[0];
    for(int i = 1; i < n; i++){
        int t = nextClose[Mx][0];
        if(t == p[i])
            t = nextClose[Mx][1];
        int res = cs[i-1] + dist[t];
        if(res >= ans){
            if(res == ans){
                idx = min(idx, p[i]);
            }
            else{
                ans = res;
                idx = p[i];
            }
        }
        Mx = max(Mx, p[i]);
        //cout<<res<<endl;
    }
    cout<<idx<<endl;

    return 0;
}
