#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    set<int> s;

    getline(cin, str);
    int len = str.size();

    for(int i = 1; i < len - 1; i++)
    {
        if(i % 3 == 1){
            s.insert(str[i] - 'a');
        }
    }

    cout<<s.size()<<endl;

    return 0;
}
