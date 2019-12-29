/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
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
#define MAX 500005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

string str;
vector<char> vc;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    int n, k, cnt = 0;

    cin>>n>>k;
    cin>>str;

    if(k == 2){
        int cnt = 0;
        string temp = "";
        if(str[0] != 'A')
            cnt++;
        temp += "A";
        for(int i = 1; i < n; i++){
            if(i & 1){
                if(str[i] != 'B')
                    cnt++;
                temp += "B";
            }
            else{
                if(str[i] != 'A')
                    cnt++;
                temp += "A";
            }
        }
        int ans = cnt;
        string t = "";
        cnt = 0;
        if(str[0] != 'B')
            cnt++;
        t += "B";
        for(int i = 1; i <  n; i++){
            if(i & 1){
                if(str[i] != 'A')
                    cnt++;
                t += "A";
            }
            else{
                if(str[i] != 'B')
                    cnt++;
                t += "B";
            }
        }

        if(cnt < ans){
            cout<<cnt<<endl;
            cout<<t<<endl;
        }
        else{
            cout<<ans<<endl;
            cout<<temp<<endl;
        }
        return 0;
    }

    for(int i = 65; i < 65 + k; i++)
        vc.pb(i);

    for(int i = 1; i < n; i++){
        if(str[i] == str[i-1]){
            cnt++;
            for(int j = 0; j < vc.size(); j++){
                if(i + 1 < n){
                    if(vc[j] != str[i-1] && vc[j] != str[i+1]){
                        str[i] = vc[j];
                        break;
                    }
                }
                else{
                    if(vc[j] != str[i-1]){
                        str[i] = vc[j];
                        break;
                    }
                }
            }
        }
    }

    cout<<cnt<<endl;
    for(int i = 0; i < n; i++){
        cout<<str[i];
    }
    cout<<endl;

    return 0;
}
