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
#define MAX 500005
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

    int n, k;
    string str;

    cin>>n>>k;
    cin>>str;

    string temp = str.substr(0, k);

    for(int i = k; i < n; i++){
        if(temp[i%k] > str[i]){
            break;
        }
        else if(str[i] > temp[i%k]){
            int carry = 1;
            for(int j = k - 1; j >= 0; j--){
                int x = ((temp[j] - 48) + carry) % 10;
                carry = ((temp[j] - 48) + carry) / 10;
                temp[j] = x + '0';
            }
            break;
        }
    }

    cout<<n<<endl;
    for(int i = 0; i < n; i++){
        cout<<temp[i%k];
    }
    cout<<endl;

    return 0;
}

