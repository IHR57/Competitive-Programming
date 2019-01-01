#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> v;
    char str[50];

    int n;

    cin>>n;

    cin>>str;

    for(int i = 0; i < n; i++){
        if(str[i] > '1'){
            if(str[i] == '4'){
                v.push_back(3);
                v.push_back(2);
                v.push_back(2);
            }
            else if(str[i] == '6'){
                v.push_back(3);
                v.push_back(5);
            }
            else if(str[i] == '8'){
                v.push_back(7);
                v.push_back(2);
                v.push_back(2);
                v.push_back(2);
            }
            else if(str[i] == '9'){
                v.push_back(7);
                v.push_back(3);
                v.push_back(3);
                v.push_back(2);
            }
            else{
                v.push_back(str[i] - 48);
            }
        }
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout<<v[i];
    }
    cout<<endl;

    return 0;
}
