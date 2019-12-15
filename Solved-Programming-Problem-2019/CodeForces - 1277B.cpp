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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test;

    cin>>test;

    while(test--){
        set<int> s;
        int n;
        cin>>n;

        for(int i = 0; i < n; i++){
            int val;
            cin>>val;
            s.insert(val);
        }

        int cnt = 0;
        while(!s.empty()){
            int t = *s.rbegin();
            s.erase(t);
            if(t % 2 == 0){
                cnt++;
                s.insert(t / 2);
            }
        }

        cout<<cnt<<endl;
    }

    return 0;
}
