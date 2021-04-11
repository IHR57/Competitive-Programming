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
#define MAX 200005
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

    int n, val, test;

    cin>>test;

    while(test--) {
        int x;
        cin>>n>>x;
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++) {
            cin>>val;
            if(val & 1)
                odd++;
            else
                even++;
        }

        bool flag = false;
        for(int i = 1; i <= odd; i++) {
            for(int j = 0; j <= even; j++) {
                if(i + j == x && (i + 2 * j) % 2 != 0) {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }

        (flag) ? cout<<"Yes"<<endl : cout<<"No"<<endl;
    }
    return 0;
}
