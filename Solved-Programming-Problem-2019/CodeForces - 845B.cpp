//Problem ID: CodeForces - 845B (Luba and the Ticket)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 15/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    cin>>str;

    int Min = 50;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                for(int l = 0; l < 10; l++){
                    for(int m = 0; m < 10; m++){
                        for(int n = 0; n < 10; n++){
                            if(i + j + k == l + m + n){
                                int cnt = 0;
                                if(str[0]-48 != i)
                                    cnt++;
                                if(str[1]-48 != j)
                                    cnt++;
                                if(str[2]-48 != k)
                                    cnt++;
                                if(str[3]-48 != l)
                                    cnt++;
                                if(str[4]-48 != m)
                                    cnt++;
                                if(str[5]-48 != n)
                                    cnt++;
                                if(cnt < Min)
                                    Min = cnt;
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<Min<<endl;

    return 0;
}
