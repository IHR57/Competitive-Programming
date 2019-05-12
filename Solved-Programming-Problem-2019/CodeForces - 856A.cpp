//Problem ID: CodeForces - 856A (Set Theory)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 12/05/19
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int arr[MAX];
int visited[2000005];
vector<int> b;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, n;

    cin>>test;

    while(test--){
        cin>>n;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int ret = 1;

        while(true){
            bool flag = true;
            for(int j = 0; j < n; j++){
                if(visited[arr[j] + ret]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                b.push_back(ret);
                for(int j = 0; j < n; j++){
                    visited[arr[j] + ret] = 1;
                }
            }
            if(b.size() == n)
                break;
            ret++;
        }

        cout<<"YES"<<endl;
        for(int i = 0; i < b.size(); i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
        b.clear();
    }
}
