//Problem ID: CodeForces - 748B (Santa Claus and Keyboard Check)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 25/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int idx[30];
int visited[30];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str1, str2;

    cin>>str1;
    cin>>str2;

    int len = (int) str1.length(), cnt = 0;
    memset(idx, -1, sizeof(idx));

    for(int i = 0; i < len; i++){
        int a = str1[i] - 'a';
        int b = str2[i] - 'a';
        if(a > b)
            swap(a, b);

        if(idx[a] != -1){
            if(idx[a] != b){
                cout<<"-1"<<endl;
                return 0;
            }
        }
        if(idx[b] != -1){
            if(idx[b] != a){
                cout<<"-1"<<endl;
                return 0;
            }
        }
        if(idx[a] == -1 && idx[b] == -1){
            idx[a] = b, idx[b] = a;
            if(a != b)
                cnt++;
        }
    }

    char ch1, ch2;

    cout<<cnt<<endl;
    for(int i = 0; i < 26; i++){
        if(idx[i] != -1){
            ch1 = i + 97, ch2 = idx[i] + 97;
            if(!visited[i] && !visited[idx[i]] && ch1 != ch2){
                cout<<ch1<<" "<<ch2<<endl;
                visited[i] = visited[idx[i]] = 1;
            }
        }
    }

    return 0;
}
