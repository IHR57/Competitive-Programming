//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mp make_pair
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

string str;

int getValue(int x, int y)
{
    int sum = 0, k = 0;
    for(int i = x; i >= y; i--){
        if(str[i] == '1')
            sum += (1 << k);
        k++;
    }

    return sum;
}

int cs[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test;

    cin>>test;

    while(test--){
        cin>>str;
        int ans = 0;
        int n = str.size();
        cs[0] = 0;
        for(int i = 0; i < n; i++){
            cs[i+1] = cs[i] + (str[i] - 48);
        }

        for(int i = n - 1; i >= 0; i--){
            int k = 0, sum = 0;
            if(str[i] == '1'){
                int k = 0;
                for(int j = i; j < n; j++){
                    int temp = getValue(j, i);
                    //cout<<temp<<endl;
                    if(temp > 2e5)
                        break;
                    if(temp == (j - i + 1))
                        ans++;
                    int rem = temp - (j - i + 1);
                    if(rem > 0 && i - rem >= 0){
                        int t = cs[i] - cs[i-rem];
                        //cout<<t<<endl;
                        if(t == 0)
                            ans++;
                    }
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
