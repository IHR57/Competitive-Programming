//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define debug (printf("PINK FLOYD:)\n"))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define EPS 1e-8
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

int p[MAX];
int counter[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, n;
    cin>>test;

    while(test--){
        cin>>n;
        set<int> s;
        mem(counter, 0);
        for(int i = 0; i < 4 * n; i++){
            cin>>p[i];
            s.insert(p[i]);
            counter[p[i]]++;
        }

        int m = (*s.begin() * (*s.rbegin()));
        bool flag = true;
        while(!s.empty()){
            int x = *s.begin();
            if(counter[x] % 2){
                flag = false;
                break;
            }
            int req = m / x;
            if(m % x || counter[req] <= 0 || counter[req] % 2){
                flag = false;
                break;
            }
            counter[x] -= 2;
            counter[req] -= 2;
            if(counter[x] <= 0){
                s.erase(x);
            }
            if(counter[req] <= 0)
                s.erase(req);
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

