#include <bits/stdc++.h>
using namespace std;

int freq[26];
vector<int> v;

bool checkValid(string str)
{
    int n = str.size();
    for(int i = 0; i < n; i++){
        freq[str[i]-'a']++;
    }

    for(int i = 0; i < 26 ; i++){
        if(freq[i])
            v.push_back(freq[i]);
    }

    sort(v.begin(), v.end());

    if(v.size() == 1)
        return true;
    
    int temp = v[1];
    bool flag = true;
    for(int i = 2; i < v.size(); i++){
        if(v[i] != temp){
            flag = false;
        }
    }
    if(flag && (v[0] == 1 || v[0] == temp))
        return true;
    
    temp = v[0];
    flag = true;
    for(int i = 1; i < v.size() - 1; i++){
        if(v[i] != temp){
            flag = false;
        }
    }
    if(flag && (v[v.size()-1] == temp + 1 || v[v.size()-1] == temp))
        return true;
    return false;
}
int main()
{
    string str;
    cin>>str;
    (checkValid(str)) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    return 0;
}