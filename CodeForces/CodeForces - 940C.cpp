//Problem ID: CodeForces - 940C (Phone Numbers)
//Programmer: IQBAL HOSSAIN     Description: Constructive Algorithm
//Date: 25/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int visited[30];

string charSet, result;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str, temp;
    map<char, int> mp;
    int n, k;

    cin>>n>>k;

    cin>>str;

    temp = str;
    sort(temp.begin(), temp.end());

    int x = 0;
    for(int i = 0; i < (int) temp.length(); i++){
        if(!visited[temp[i]-'a']){
            visited[temp[i]-'a'] = 1;
            charSet += temp[i];
            mp[temp[i]] = x++;
        }
    }

    if(k > n){
        cout<<str;
        for(int i = 0; i < k - n; i++){
            cout<<charSet[0];
        }
        cout<<endl;
        return 0;
    }

    bool flag = true;
    for(int i = k - 1; i >= 0; i--){
        int idx = mp[str[i]];
        if(flag && idx == x - 1){
            result += charSet[0];
        }
        else if(flag && idx != x - 1){
            result += charSet[idx+1];
            flag = false;
        }
        else{
            result += str[i];
        }
    }

    reverse(result.begin(), result.end());

    cout<<result<<endl;

    return 0;

}
