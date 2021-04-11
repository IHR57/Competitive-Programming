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

    int n;
    string s, t;
    int temp1 = 0, temp2 = 0;

    cin>>n;
    cin>>s>>t;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1')
            temp1++;
        if(t[i] == '1')
            temp2++;
    }

    if(temp1 != temp2) {
        cout<<-1<<endl;
        return 0;
    }

    temp1 = temp2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != t[i]) {
            if(s[i] == '1') {
                temp1++;
                temp2--;
            }
            else {
                temp1--;
                temp2++;
            }
            if(temp1 < 0)
                temp1 = 0;
            if(temp2 < 0)
                temp2 = 0;
        }
    }

    cout<<temp1 + temp2<<endl;

    return 0;
}
