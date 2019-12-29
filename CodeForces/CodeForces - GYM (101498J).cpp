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

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int cnt[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int test;
    string str;

    cin>>test;
    for(int i = 0; i <= test; i++){
        getline(cin, str);
        //cout<<str<<endl;
        //cout<<str.size()<<endl;
        if(i){
            memset(cnt, 0, sizeof(cnt));
            vector<int> v;
            for(int j = 0; j <  str.size(); j++){
                if(str[j] == ' '){
                    v.pb(j);
                    cnt[j] = 1;
                    // cout<<j<<" ";
                }
            }
            cnt[str.size()] = 1;
            int hasAns = false;
            for(int i = 0; i < v.size() - 1; i++){
                int t = v[i] + 1;
                bool flag = false;
                for(int j = v[i] + t; j <= str.size(); j += t){
                    if(!cnt[j]){
                        flag = false;
                        break;
                    }
                    if(j == str.size()){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    hasAns = true;
                    break;
                }
            }
            (hasAns) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
        }
    }

    return 0;
}
