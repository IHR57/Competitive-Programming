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

    int n;
    string str;

    cin>>n;
    cin>>str;

    int ans = 0, cnt = 0;
    for(int i = 25; i > 0; i--){

        while(true){
            bool found = false;
            n = str.size();
            string tStr = "";
            vector<int> mark(n + 1, 0);

            for(int j = 0; j < n; j++){
                if((str[j]-'a') == i && j == 0){
                    if(j + 1 < n && (str[j+1]-'a') + 1 == i){
                        mark[j] = 1, cnt++;
                        found = true;
                    }
                }
                else if((str[j]-'a') == i && j == n - 1){
                    if(j - 1 >= 0 && (str[j-1]-'a') + 1 == i){
                        mark[j] = 1, cnt++;
                        found = true;
                    }
                }
                else if((str[j]-'a') == i){
                    if((str[j-1]-'a') + 1 == i || (str[j+1]-'a') + 1 == i){
                        mark[j] = 1;
                        cnt++;
                        found = true;
                    }
                }
            }
            for(int j = 0; j < n; j++){
                if(!mark[j])
                    tStr += str[j];
            }
            str = tStr;
            if(!found)
                break;
        }
        //cout<<str<<endl;
    }

    cout<<cnt<<endl;

    return 0;
}
