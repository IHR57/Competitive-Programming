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

    int test;

    cin>>test;

    while(test--){
        int n;

        cin>>n;

        int arr[n+1];
        int sum = 0, zero = 0;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            sum += arr[i];
            if(arr[i] == 0)
                zero++;
        }

        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                sum++;
            }
        }
        if(sum == 0){
            zero++;
        }

        cout<<zero<<endl;
    }
    return 0;
}
