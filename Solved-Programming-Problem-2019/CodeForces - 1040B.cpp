//Problem ID: CodeForces - 1040B (Shashlik Cooking)
//Programmer: IQBAL HOSSAIN     Description: Greedy/DP/MATH
//Date: 26/08/19
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define tan(a) tan(a*PI/180)
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k;

    cin>>n>>k;

    int sz = (k * 2) + 1;
    int need = n / sz;

    if(n <= sz){
        cout<<1<<endl;
        cout<<(n / 2) + 1<<endl;
        return 0;
    }

    int p = (n % sz == 0) ? (k * 2) : (n % sz) - 1;
    if(n % sz)
        need += 1;

    cout<<need<<endl;
    int fst = 1, lst = n;
    lst -= min(k, p);
    p -= min(k, p);
    fst += min(k, p);

    for(int i = fst; i <= lst; i += sz){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
