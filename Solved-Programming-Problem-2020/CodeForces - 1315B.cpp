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

    int test, a, b, p;

    cin>>test;

    while(test--){
        cin>>a>>b>>p;
        string str;

        cin>>str;

        int n = str.size();
        vector<int> v;

        int res = 0;


        char prev = '#';
        int ans = -1;
        for(int i = n - 2; i >= 0; i--){
            if(str[i] != prev){
                prev = str[i];
                if(str[i] == 'A')
                    res += a;
                else
                    res += b;
            }
            if(res > p){
                ans = i;
                break;
            }
        }

        cout<<ans + 2<<endl;
    }
    return 0;
}
