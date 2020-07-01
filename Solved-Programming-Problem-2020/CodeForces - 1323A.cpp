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

int arr[105];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test;

    cin>>test;

    while(test--) {
        int n;
        cin>>n;

        int odd = 0, even = 0;
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
            (arr[i] & 1) ? odd++ : even++;
        }

        if(even >= 1){
            cout<<1<<endl;
            for(int i = 0; i < n; i++) {
                if(arr[i] % 2 == 0){
                    cout<<i + 1<<endl;
                    break;
                }
            }
        }
        else if(odd >= 2) {
            cout<<2<<endl;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i] % 2 != 0){
                    cout<<i + 1<<" ";
                    cnt++;
                    if(cnt >= 2)
                        break;
                }
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }

    return 0;
}
