//IQBAL HOSSAIN
//Date: 09/02/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

string str, result;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, visited[4];

    cin>>n;
    cin>>str;

    char temp[5];
    temp[0] = 'R', temp[1] = 'G', temp[2] = 'B';
    map<char, int> mp;
    mp['R'] = 0, mp['G'] = 1, mp['B'] = 2;

    int len = (int) str.length();

    int start = -1, cnt = 0, ans = 0;
    for(int i = 1; i < len; i++){
        if(str[i] == str[i-1]){
            cnt++;
            memset(visited,  0, sizeof(visited));
            visited[mp[str[i]]] = 1;
            if(i + 1 < len)
                visited[mp[str[i+1]]] = 1;
            for(int j = 0; j < 3; j++){
                if(!visited[j]){
                    str[i] = temp[j];
                    break;
                }
            }
        }
    }

    cout<<cnt<<endl;
    cout<<str<<endl;

    return 0;
}
