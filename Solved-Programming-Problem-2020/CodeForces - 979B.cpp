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

int freq[3][52], maxF[3];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    string str;

    cin>>n;

    vector<int> v;

    for(int i = 0; i < 3; i++) {
        cin>>str;
        m = str.size();
        for(int j = 0; j < str.size(); j++) {
            int id = (str[j] >= 'A' && str[j] <= 'Z') ? str[j] - 'A' : str[j] - 'a' + 26;
            freq[i][id]++;
            maxF[i] = max(maxF[i], freq[i][id]);
        }
        int req = m - maxF[i];

        if(req == 0 && n == 1)
            v.pb(m - 1);
        else if(n >= req)
            v.pb(m);
        else
            v.pb(maxF[i] + n);
    }

    if(v[0] > v[1] && v[0] > v[2]) {
        cout<<"Kuro"<<endl;
    }
    else if(v[1] > v[0] && v[1] > v[2])
        cout<<"Shiro"<<endl;
    else if(v[2] > v[0] && v[2] > v[1])
        cout<<"Katie"<<endl;
    else
        cout<<"Draw"<<endl;

    return 0;
}
