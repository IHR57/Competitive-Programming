//Problem ID: CodeForces - 713A (Sonya and Queries)
//Programmer: IQBAL HOSSAIN     Description: Data Structures
//Date: 27/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
int counter[MAX];

string convertToString(ll n)
{
    string str = "";
    int cnt =  0;

    while(n){
        str += ((n % 10) % 2 == 0) ? "0" : "1";
        n /= 10;
        cnt++;
    }

    for(int i = 0; i < (19 - cnt); i++){
        str += "0";
    }
    reverse(str.begin(), str.end());

    return str;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, idx = 0;
    map<string, int> mp;
    char ch;
    ll num;
    string str, patt;

    cin>>t;

    while(t--){
        cin>>ch;
        if(ch == '+'){
            cin>>num;
            str = convertToString(num);
            if(mp.find(str) == mp.end()){
                mp[str] = idx++;
            }
            counter[mp[str]]++;
            //cout<<str<<endl;
        }
        else if(ch == '-'){
            cin>>num;
            str = convertToString(num);
            counter[mp[str]]--;
        }
        else{
            cin>>patt;
            int len = patt.length();
            string temp;
            for(int i = 0; i < (19 - len); i++){
                temp += "0";
            }
            temp += patt;
            //cout<<temp<<endl;
            //reverse(patt.begin(), patt.end());
            if(mp.find(temp) != mp.end()){
                cout<<counter[mp[temp]]<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }

    return 0;
}
