//Problem ID: CodeForces - 1089G (Guest Student)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 11/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, n, arr[10], first, last;

    cin>>test;

    while(test--){
        cin>>n;
        int cnt = 0, k;
        for(int i = 0; i < 7; i++){
            cin>>arr[i];
            if(arr[i] == 1){
                last = i; cnt++;
            }
        }

        int res = 2147483647;;

        for(int i = 0; i < 7; i++){
            if(arr[i] == 1){
                int ans = 7;
                bool flag = false;
                int c = 0;
                for(int j = i; j < 7; j++){
                    if(arr[j] == 1){
                        c++;
                        if(c == n){
                            ans -= i;
                            ans -= (6 - j);
                            res = min(res, ans);
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag)
                    continue;
                int m = n;
                m -= c;
                ans -= i;
                (m % cnt == 0) ? k = m / cnt : k = (m / cnt) + 1;
                ans += (7 * k);
                if(m % cnt == 0){
                    ans -= (6 - last);
                    res = min(res, ans);
                }
                else{
                    c = 0;
                    int t = m % cnt;
                    for(int j = 0; j < 7; j++){
                        if(arr[j] == 1){
                            c++;
                            if(c == t){
                                ans -= (6 - j);
                                //cout<<ans<<endl;
                                res = min(res, ans);
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout<<res<<endl;
    }

    return 0;
}
