//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000009
#define MAX 300005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int x, y;
ii suff[MAX], pref[MAX];
string str;
int n;

void changeSuff(int idx)
{
    int x = idx;
    suff[idx] = suff[idx+1];
    if(str[x] == 'D')
        suff[idx].ss += 1;
    else if(str[x] == 'U')
        suff[idx].ss -= 1;
    else if(str[x] == 'L')
        suff[idx].ff += 1;
    else
        suff[idx].ff -= 1;
}

void changePref(int idx)
{
    int x = idx - 1;
    pref[idx] = pref[idx-1];
    if(str[x] == 'L')
        pref[idx].ff -= 1;
    else if(str[x] == 'R')
        pref[idx].ff += 1;
    else if(str[x] == 'U')
        pref[idx].ss += 1;
    else
        pref[idx].ss -= 1;
}

bool isOk(int i, int j)
{
    //cout<<"( "<<i<<" "<<j<<" )"<<endl;
    int dist = abs(suff[j].ff - pref[i].ff) + abs(suff[j].ss - pref[i].ss);
    //cout<<dist<<endl;

    if((dist % 2) != ((j-i)%2))
        return false;

    return (j - i) >= dist;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>n;
    cin>>str;
    cin>>x>>y;

    if(abs(x) + abs(y) > n) {
        cout<<-1<<endl;
        return 0;
    }
    suff[n].ff = x, suff[n].ss = y;
    pref[0].ff = 0, pref[0].ss = 0;

    for(int i = n - 1; i >= 0; i--) {
        changeSuff(i);
        changePref(n - i);
    }


    if(pref[n].ff == x && pref[n].ss == y) {
        cout<<0<<endl;
        return 0;
    }

    int low = 1, high = n, mid, ans = -1;
    while(low <= high) {
        mid = (low + high + 1) >> 1;
        bool flag = false;
        for(int i = 0; i <= n - mid; i++) {
            if(isOk(i, i + mid)) {
                flag = true;
                break;
            }
        }
        if(flag){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout<<ans<<endl;
}
