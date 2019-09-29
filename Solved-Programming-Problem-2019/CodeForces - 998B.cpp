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
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[105];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, B;
    priority_queue<int, vector<int>, greater<int> > pq;

    cin>>n>>B;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int even = 0, odd = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] & 1)
            odd++;
        else
            even++;
        if(odd == even){
            pq.push(abs(arr[i] - arr[i+1]));
        }
    }
    (arr[n-1] & 1) ? odd++ : even++;
    
    if(odd != even){
        cout<<0<<endl;
        return 0;
    }
    int cnt = 0;
    while(B){
        if(!pq.empty()){
            B -= pq.top();
            if(B < 0)
                break;
            pq.pop();
        }
        else
            break;
        cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}
