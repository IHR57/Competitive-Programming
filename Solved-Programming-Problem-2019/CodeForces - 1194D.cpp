//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define debug (printf("PINK FLOYD:)\n"))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define EPS 1e-8
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
	int test, n, k;

	cin>>test;

	while(test--){
        cin>>n>>k;
        if(n == k){
            cout<<"Alice"<<endl;
        }
        else if(k % 3 != 0){
            if(n % 3 == 0){
                cout<<"Bob"<<endl;
            }
            else{
                cout<<"Alice"<<endl;
            }
        }
        else{
            ll low = 0, high = 1e9, mid, ans;
            while(low <= high){
                mid = (low + high + 1) >> 1;
                if(n >= (k * 1LL * mid + mid)){
                    ans = k * 1LL * mid + mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            if(n == ans + k){
                cout<<"Alice"<<endl;
            }
            else if(n % 3 == ans % 3){
                cout<<"Bob"<<endl;
            }
            else{
                cout<<"Alice"<<endl;
            }
        }
	}

    return 0;
}
