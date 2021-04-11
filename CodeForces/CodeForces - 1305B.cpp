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

int open[MAX], close[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    cin>>str;

    int n = str.size();

    for(int i = 0; i < n; i++){
        open[i+1] = open[i] + (str[i] == '(');
    }
    for(int i = n - 1; i >= 0; i--){
        close[i+1] = close[i+2] + (str[i] == ')');
    }

    int idx = -1, ans = INF;
    for(int i = 1; i <= n; i++){
        if(open[i] - close[i] == 0){
            ans = min(open[i], close[i]);
            idx = i;
            break;
        }
    }
    if(idx == -1){
        for(int i = 1; i <= n; i++){
            if(open[i] - close[i] == 1){
                ans = min(open[i], close[i]);
                idx = i;
                break;
            }
        }
    }

    if(idx != - 1){
        if(ans == 0){
            cout<<0<<endl;
            return 0;
        }
        cout<<1<<endl;
        cout<<2 * ans<<endl;
        int cnt = 0;
        for(int i = 0; i < idx; i++){
            if(str[i] == '('){
                cout<<i + 1<<" ";
                cnt++;
            }
            if(cnt >= ans)
                break;
        }
        cnt = 0;
        if(str[idx-1] == ')')
            idx--;
        for(int i = idx; i < n; i++){
            if(str[i] == ')'){
                cout<<i + 1<<" ";
                cnt++;
            }
            if(cnt >= ans)
                break;
        }
        cout<<endl;
    }
    else{
        cout<<0<<endl;
    }

    return 0;
}
