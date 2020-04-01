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


string kmp(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    s += "#";
    s += t;
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return s.substr(0, pi[n-1]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, n;
    string str, revStr;

    cin>>test;

    while(test--){
        cin>>str;
        string tStr = str;
        reverse(str.begin(), str.end());
        revStr = str;
        str = tStr;
        n = str.size();

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(str[i] != revStr[i])
                break;
            cnt++;
        }

        if(cnt == n){
            cout<<str<<endl;
            continue;
        }
//        if(n / cnt == 2 && n % cnt == 0){
//            cout<<str<<endl;
//            continue;
//        }
        string tempStr = str.substr(cnt, n - 2 * cnt);
        string ans = "";
        if(cnt)
            ans += str.substr(0, cnt);
        int Mx = 0;
        string pref = kmp(tempStr);
        //cout<<Mx<<endl;
        reverse(tempStr.begin(), tempStr.end());
        string suff = kmp(tempStr);
        if(pref.size() > suff.size()){
            ans += pref;
        }
        else{
            ans += suff;
        }
        if(cnt){
            string x = str.substr(0, cnt);
            reverse(x.begin(), x.end());
            ans += x;
        }

        cout<<ans<<endl;
    }

    return 0;
}
