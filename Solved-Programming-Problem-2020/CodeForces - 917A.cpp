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
 
int arr[MAX];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
 
    cin>>str;
 
    int n = str.size();
 
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int opt = 0, cnt = 0;
        for(int j = i; j < n; j++) {
            if(str[j] == '?'){
                cnt--;
                opt++;
            }
            else if(str[j] == '('){
                cnt++;
                opt++;
            }
            else if(str[j] == ')') {
                cnt--;
                opt--;
            }
            if(cnt < 0) {
                cnt += 2;
            }
            if(cnt > opt)
                break;
            if(cnt == 0)
                ans++;
        }
    }
 
    cout<<ans<<endl;
 
    return 0;
}