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

int arr[MAX], b[MAX];
bool cs[MAX][2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int test;
 
    cin>>test;

    while(test--) {
        int n;
        cin>>n;

        memset(cs, 0, sizeof(cs));

        for(int i = 0; i < n; i++) {
            cin>>arr[i];
            cs[i+1][0] = cs[i][0] | (arr[i] == -1);
            cs[i+1][1] = cs[i][1] | (arr[i] == 1);
        }

        for(int i = 0; i < n; i++) {
            cin>>b[i];
        }
        bool flag = true;

        if(arr[0] != b[0])
            flag = false;

        for(int i = n - 1; i >= 0; i--) {
            if(b[i] < arr[i]) {
                if(!cs[i][0]) {
                    flag = false;
                    break;
                }
            }
            else if(b[i] > arr[i]) {
                if(!cs[i][1]) {
                    flag = false;
                    break;
                }
            }
        }

        (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }

    return 0;
}