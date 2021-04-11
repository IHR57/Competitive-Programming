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

int arr[MAX], rangeMin[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, n;

    cin>>test;

    while(test--){
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            rangeMin[i] = INF;
        }
        rangeMin[n] = INF;

        for(int i = n - 1; i >= 0; i--){
            rangeMin[i] = min(rangeMin[i + 1], arr[i]);
        }

        int maxD = 0;
        bool found = false;
        for(int i = n - 1; i >= 0; i--){
            if(arr[i] >= rangeMin[i]){
                found = true;
                int d = arr[i] - rangeMin[i];
                maxD = max(maxD, d);
            }
        }

        if(!found){
            cout<<0<<endl;
        }
        else{
            int cnt = 0;
            while(maxD){
                cnt++;
                maxD /= 2;
            }

            cout<<cnt<<endl;
        }
    }

    return 0;
}
