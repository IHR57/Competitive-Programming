//Problem ID: CodeForces - 949A (Zebras)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 29/04/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

string str;
set<int> s[2];
vector<int> ans[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>str;

    int n = str.size();
    if(str[0] == '1' || str[n-1] == '1'){
        cout<<-1<<endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        s[str[i]-48].insert(i);
    }

    int k = 0;

    while(true){
        set<int> :: iterator it;
        int curr = 0, val = 0;
        while(true){
            it = s[curr].lower_bound(val);
            if(it != s[curr].end()){
                val = *it;
                s[curr].erase(it);
                ans[k].push_back(val + 1);
                curr = !curr;
            }
            else{
                break;
            }
        }
        if(ans[k].size() % 2 == 0){
            cout<<-1<<endl;
            return 0;
        }
        k++;
        if(s[0].empty())
            break;
    }

    if(!s[1].empty()){
        cout<<-1<<endl;
        return 0;
    }
    cout<<k<<endl;
    for(int i = 0; i < k; i++){
        cout<<ans[i].size()<<" ";
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
