#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;

    cin>>n>>a>>b;

    for(int x = 0; x * a <= n; x++){
        int y = (n - x * a);
        if(y % b == 0){
            y = y / b;
            int temp = 1;
            for(int i = 0; i < x; i++){
                for(int j = 0; j < a; j++){
                    cout<<(temp + (j + 1) % a)<<" ";
                }
                temp += a;
            }
            for(int i = 0; i < y; i++){
                for(int j = 0; j < b; j++){
                    cout<<(temp + (j + 1) % b)<<" ";
                }
                temp += b;
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}
