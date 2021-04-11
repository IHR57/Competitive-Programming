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
#define MAX 300005
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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int test;

    cin>>test;

    while(test--) {
        string str;
        cin>>str;

        str += "~";
        int n = str.size();

        sort(str.begin(), str.end());
        string strA = "", strB = "";

        int idx = 0;
        while(idx < n) {
            for(int j = idx; j < n; j++) {
                if(str[j] == str[idx]){
                    strA += str[j];
                    continue;
                }
                if(str[j] != str[idx] && ((str[j] - 'a') == (str[idx] - 'a') + 1)) {
                    strB += str[j];
                }
                else {
                    idx = j - 1;
                    break;
                }
            }
            idx++;
        }
        int sz = strA.size();
        strA.erase(sz - 1, 1);
        int szA = strA.size(), szB = strB.size();


        if(strB.empty()) {
            cout<<strA<<endl;
        }
        else if(strA[szA-1] != strB[0] && (abs((strA[szA-1] - 'a') - (strB[0] - 'a')) >= 2)) {
            cout<<strA<<strB<<endl;
        }
        else if(strA[0] != strB[szB-1] && (abs((strA[0] - 'a') - (strB[szB-1] - 'a')) >= 2)) {
            cout<<strB<<strA<<endl;
        }
        else{
            cout<<"No answer"<<endl;
        }
    } 

    
    return 0;
}


