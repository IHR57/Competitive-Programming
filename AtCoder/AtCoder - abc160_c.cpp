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

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k, n;

    cin>>k>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int Min = arr[n-1] - arr[0];

    Min = min(Min, arr[0] + (k - arr[1]));

    for(int i = 1; i < n - 1; i++){
        Min = min(Min, arr[i] + (k - arr[i+1]));
    }

    cout<<Min<<endl;

    return 0;
}
