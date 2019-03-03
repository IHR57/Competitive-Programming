//Problem ID: CodeForces - 864C (Bus)
//Programmer: IQBAL HOSSAIN     Description: Implementation / Simple Math
//Date: 03/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, f, k;

    cin>>a>>b>>f>>k;

    if(b < f){
        cout<<-1<<endl;
        return 0;
    }

    int cnt = 0, temp = b - f;

    for(int i = 1; i <= k; i++){
        if(i & 1){
            if(i != k){
                if((a - f) * 2 > b){
                    cout<<-1<<endl;
                    return 0;
                }
                if((a - f) * 2 > temp){
                    cnt++;
                    temp = b - ((a - f) * 2);
                }
                else{
                    temp -= ((a - f) * 2);
                }
            }
            else{
                if((a - f) > temp){
                    if(b < (a - f)){
                        cout<<-1<<endl;
                        return 0;
                    }
                    else{
                        cnt++;
                    }
                }
            }
        }
        else{
            if(i != k){
                if(f * 2 > b){
                    cout<<-1<<endl;
                    return 0;
                }
                if(f * 2 > temp){
                    cnt++;
                    temp = b - (f * 2);
                }
                else{
                    temp -= (f * 2);
                }
            }
            else{
                if(temp < f){
                    if(b < f){
                        cout<<-1<<endl;
                        return 0;
                    }
                    else{
                        cnt++;
                    }
                }
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
