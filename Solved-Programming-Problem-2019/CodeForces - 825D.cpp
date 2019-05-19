//Problem ID: CodeForces - 825D (Suitable Replacement)
//Programmer: IQBAL HOSSAIN     Description: Greedy/Implementation
//Date: 18/05/19
#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int counterS[30], counterT[30], counter[30], mark[30];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s, t;
    int rem = 0;

    cin>>s;
    cin>>t;

    int n1 = s.size();
    for(int i = 0; i < n1; i++){
        if(s[i] == '?')
            rem++;
        else{
            counterS[s[i]-'a']++;
        }
    }
    if(rem == 0){
        cout<<s<<endl;
        return 0;
    }

    int n2 = t.size();
    for(int i = 0; i < n2; i++){
        counterT[t[i]-'a']++;
        mark[t[i]-'a'] = 1;
    }

    int ans = 0;
    while(true){
        if(!rem)
            break;
        for(int i = 0; i < 26; i++){
            if(mark[i]){
                if(counterS[i] >= counterT[i]){
                    counterS[i] -= counterT[i];
                }
                else{
                    int temp = min(rem, counterT[i] - counterS[i]);
                    rem -= temp;
                    //cout<<rem<<endl;
                    counter[i] += temp;
                    counterS[i] = 0;
                }
                if(rem == 0)
                    break;
            }
        }
    }
    for(int i = 0; i < n1; i++){
        if(s[i] == '?'){
            for(int j = 0; j < 26; j++){
                if(counter[j]){
                    cout<<char(j+97);
                    counter[j]--;
                    break;
                }
            }
        }
        else{
            cout<<s[i];
        }
    }
    cout<<endl;

    return 0;
}
