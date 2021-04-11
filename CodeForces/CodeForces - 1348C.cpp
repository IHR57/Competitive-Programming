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
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    
    int test, n, k;
    cin>>test;

    while(test--){
        string str;

        cin>>n>>k;
        cin>>str;

        sort(str.begin(), str.end());
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(str[i] == str[0])
                cnt++;
        }

        if(cnt < k){
            cout<<str[k-1]<<endl;
            continue;
        }

        string res = "";
        res += str[0];
        bool flag = true;
        for(int i = k + 1; i < n; i++){
            if(str[i] != str[k]){
                flag = false;
                break;
            }
        }

        if(!flag){
            for(int i = k; i < n; i++)
                res += str[i];
        }
        else{
            int temp = ((n - k) % k == 0) ? (n - k) / k : (n - k) / k + 1;
            for(int i = 0; i < temp; i++){
                res += str[k];
            }
        }

        cout<<res<<endl;
    }

    return 0;
}