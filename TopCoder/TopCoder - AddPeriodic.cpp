/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
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
typedef pair<ll, ll> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

class AddPeriodic
{
    public:
        pair<ll, ll> convertToNumber(string str)
        {
            string t1 = "", t2 = "";
            bool flag = true, found = false, foundDecimal = false;;
            int len = str.size(), cnt = 0, decimal = 0;
            for(int i = 0; i < len; i++){
                if(flag && str[i] > '0' && str[i] <= '9'){
                    flag = false;
                }
                if(str[i] == '(')
                    found = true;
                if(str[i] == '.')
                    foundDecimal = true;
                if(foundDecimal && str[i] >= '0' && str[i] <= '9')
                    decimal++;
                if(found && str[i] >= '0' && str[i] <= '9')
                    cnt++;
                if(flag || str[i] == '.' || str[i] == '(' || str[i] == ')')
                    continue;
                t1 += str[i];
                if(!found)
                    t2 += str[i];
            }
            ll n1 = 0, n2 = 0, k = 1;
            for(int i = t1.size() - 1; i >= 0; i--){
                n1 = (n1 + (t1[i] - 48) * k);
                k *= 10;
            }
            k = 1;
            for(int i = t2.size() - 1; i >= 0; i--){
                n2 = (n2 + (t2[i] - 48) * k);
                k *= 10;
            }
            k = 1;
            ll u = 0;
            for(int i = 0; i < cnt; i++){
                u = (u + (9 * 1LL * k));
                k *= 10;
            }
            for(int i = 0; i < (decimal - cnt); i++)
                u = (u * 10);
            return mp((n1 - n2), u);
        }
        pair<ll, ll> result(ii A, ii B)
        {
            ll lc = (A.ss * B.ss) / __gcd(A.ss, B.ss);
            return mp(((A.ff * (lc / A.ss)) + (B.ff * (lc / B.ss))), lc);
        }
        string calAns(ii p)
        {
            string res = "";
            bool found = false;
            ll n = p.ff, k = p.ss;
            for(int i = 1; i <= 500; i++){
                ll temp = (n / k);
                if(temp == 0){
                    n = n * 10;
                    if(i == 1)
                        res += "0";
                    if(!found){
                        res += ".";
                        found = true;
                    }
                    if(n < k)
                        res += "0";
                } 
                else{
                    ll t = temp;
                    string str = "";
                    while(t){
                        str += (t % 10) + 48;
                        t /= 10;
                    }
                    reverse(str.begin(), str.end());
                    res += str;   
                    n = (n - (k * temp));
                }               
            }
            int pos;
            for(int i = 0; i < res.size(); i++){
                if(res[i] == '.'){
                    pos = i;
                    break;
                }
            }
            // cout<<p.ff<<" "<<p.ss<<endl;
            // cout<<res<<endl;
            string ans = "";
            int Min = 1e9;
            for(int i = pos + 1; i < res.size(); i++){
                int lim = min((ll) 100, ll(res.size()) - i);
                for(int j = 1; j <= lim; j++){
                    string prev = res.substr(i, j);
                    bool flag = true;
                    for(int k = i; k <= (res.size() - j); k += j){
                        string curr = res.substr(k, j);
                        if(curr != prev){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        if(i + prev.size()< Min){
                            Min = i + prev.size();
                            ans = res.substr(0, i) + "(" + prev + ")";
                        }
                    }
                }
            }
            return ans;
        }
        string add(string A, string B)
        {
            ii p1 = convertToNumber(A);
            ii p2 = convertToNumber(B);
            ii p = result(p1, p2);
            string ans = calAns(p);
            return ans;
        }

};

// void solve()
// {
//     string a, b;
//     while(cin>>a>>b){
//         AddPeriodic obj = AddPeriodic();
//         cin>>a>>b;
//         int len1 = a.size();
//         int len2 = b.size();
//         string res = obj.add(a.substr(1, len1 - 1), b.substr(0, len2 - 1));
//         cout<<res<<endl;
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     #ifndef ONLINE_JUDGE
//     	freopen("input.txt", "r", stdin);
//     	freopen("output.txt", "w", stdout);
//     #endif
//     solve();

//     return 0;
// }
