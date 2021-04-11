/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: Psychedelic
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
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
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

string correctSeq;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    string str;
    int test, n, k;

    cin>>test;

    while(test--){
        cin>>n>>k;
        cin>>str;

        vector<ii> res;
        
        for(int i = 0; i < n / 2; i++){
            correctSeq += "(";
            correctSeq += ")";
        }

        for(int i = 0; i < n; i++){
            if(str[i] != correctSeq[i]){
                for(int j = i + 1; j < n; j++){
                    if(str[j] == correctSeq[i]){
                        res.pb(mk(i + 1, j + 1));
                        string t;
                        for(int x = j; x >= i; x--)
                            t += str[x];
                        for(int x = i, y = 0; y < t.size(); x++, y++)
                            str[x] = t[y];
                        break;
                    }
                }
            }
        }

        int cnt = n / 2;
        if(k < cnt){
            for(int i = 0; i < n - 1; i++){
                if(str[i] == ')' && str[i+1] == '('){
                    res.pb(mk(i + 1, i + 2));
                    swap(str[i], str[i+1]);
                    cnt--;
                    if(cnt == k)
                        break;
                }
            }
        }

        cout<<res.size()<<endl;
        for(int i = 0; i < res.size(); i++){
            cout<<res[i].ff<<" "<<res[i].ss<<endl;
        }
    }

    return 0;
}
