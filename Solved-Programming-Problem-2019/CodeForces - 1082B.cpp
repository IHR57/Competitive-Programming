//Problem ID: CodeForces - 1082B (Vova and Trophies)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 12/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int tl[MAX], tr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str, temp;
    int n;

    cin>>n;
    cin>>temp;
    str += "S" + temp + "S";
    n += 2;

    int cnt = 0, counterG = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == 'S'){
            cnt = 0;
        }
        else{
            cnt++;
            tl[i] = cnt;
            counterG++;
        }
    }
    cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        if(str[i] == 'S'){
            cnt = 0;
        }
        else{
            cnt++;
            tr[i] = cnt;
        }
    }

    int Max = 0, tmp;
    for(int i = 0; i < n; i++){
        if(str[i] == 'S'){
            if(i == 0){
                tmp = tr[i+1];
                if(counterG > tr[i+1])
                    tmp++;
                Max = max(Max, tmp);
            }
            else if(i == n - 1){
                tmp = tl[i-1];
                if(counterG > tl[i-1])
                    tmp++;
                Max = max(Max, tmp);
            }
            else{
                tmp = tl[i-1] + tr[i+1];
                if(counterG > tmp){
                    tmp++;
                }
                Max = max(Max, tmp);
            }
        }
    }

    cout<<Max<<endl;

    return 0;
}
