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
 
int arr[1030], orgCnt[1030];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test;
 
    cin>>test;
 
    while(test--) {
        int n;
        cin>>n;
 
        int ans = -1;
        memset(orgCnt, 0, sizeof(orgCnt));
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
            orgCnt[arr[i]]++;
        }
 
        for(int i = 1; i <= 1023; i++) {
            vector<int> currCnt(1024, 0);
            for(int j = 0; j < n; j++){
                int t = arr[j] ^ i;
                //cout<<t<<endl;
                currCnt[t]++;
            }
            bool flag = true;
            for(int j = 0; j <= 1023; j++) {
                if(orgCnt[j] != currCnt[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans = i;
                break;
            }
        }
 
        cout<<ans<<endl;
    }
 
    return 0;
}