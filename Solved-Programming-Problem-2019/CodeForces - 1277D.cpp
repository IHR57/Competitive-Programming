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
    int test, n;

    cin>>test;

    while(test--){
        cin>>n;
        string str;

        set<string> s;
        vector<pair<string, int> >vs;

        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < n; i++){
            cin>>str;
            int len = str.size();
            if(str[0] == str[len-1]){
                if(str[0] == '0')
                    cnt0++;
                else
                    cnt1++;
            }
            else{
                s.insert(str);
                vs.pb(mk(str, i));
            }
        }

        vector<pair<string, int> > rev;
        int lastOne = 0;
        for(int i = 0; i < vs.size(); i++){
            string temp = vs[i].ff;
            reverse(temp.begin(), temp.end());
            if(!s.count(temp)){
                rev.pb(mk(vs[i].ff, vs[i].ss));
            }
            int len = vs[i].ff.size();
            if(vs[i].ff[len-1] == '1')
                lastOne++;
        }
        int firstOne = vs.size() - lastOne;
        vector<int> ans;
        if(firstOne - lastOne > 1){
            for(int i = 0; i < rev.size(); i++){
                if(rev[i].ff[0] == '1'){
                    firstOne--;
                    lastOne++;
                    ans.pb(rev[i].ss);
                }
                if(firstOne - lastOne <= 1)
                    break;
            }
            if(firstOne - lastOne > 1){
                cout<<-1<<endl;
            }
            else{
                cout<<ans.size()<<endl;
                for(int i = 0; i < ans.size(); i++){
                    cout<<ans[i] + 1<<" ";
                }
                cout<<endl;
            }
        }
        else if(lastOne - firstOne > 1){
            for(int i = 0; i < rev.size(); i++){
                if(rev[i].ff[0] == '0'){
                    lastOne--;
                    firstOne++;
                    ans.pb(rev[i].ss);
                }
                if(lastOne - firstOne <= 1){
                    break;
                }
            }
            if(lastOne - firstOne > 1){
                cout<<-1<<endl;
            }
            else{
                cout<<ans.size()<<endl;
                for(int i = 0; i < ans.size(); i++){
                    cout<<ans[i] + 1<<" ";
                }
                cout<<endl;
            }
        }
        else{
            if(firstOne == 0 && lastOne == 0){
                if(cnt0 == 0 || cnt1 == 0)
                    cout<<0<<endl;
                else
                    cout<<-1<<endl;
            }
            else
                cout<<0<<endl;
        }
    }
    return 0;
}
