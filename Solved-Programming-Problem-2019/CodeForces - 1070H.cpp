//Problem ID: CodeForces - 1070H (BerOS File Suggestion)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 13/04/19
#include <bits/stdc++.h>
#define MAX 400005
using namespace std;

typedef long long ll;
map<string, int> mp;
set<string> st;
int counter[MAX];
string res[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    string str, tstr;

    cin>>n;

    int idx = 1;

    for(int i = 0; i < n; i++){
        cin>>str;
        int len = str.length();
        for(int j = 0; j < len; j++){
            tstr.clear();
            for(int k = j; k < len; k++){
                tstr += str[k];
                st.insert(tstr);
            }
        }
        for(set<string> :: iterator it = st.begin(); it != st.end(); it++){
            string temp = *it;
            if(mp[temp] == 0){
                mp[temp] = idx++;
                res[mp[temp]] = str;
            }
            counter[mp[temp]]++;
        }
        st.clear();
    }

    cin>>q;

    for(int i = 0; i < q; i++){
        cin>>str;
        if(counter[mp[str]] > 0){
            cout<<counter[mp[str]]<<" "<<res[mp[str]]<<endl;
        }
        else{
            cout<<0<<" -"<<endl;
        }
    }

    return 0;
}
