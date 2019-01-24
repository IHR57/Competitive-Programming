//Problem ID: LightOJ - 1042 (Secret Origins)
//Programmer: IQBAL HOSSAIN     Description: Bit
//Date: 23/01/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1042
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    vector<int> digit;

    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int temp = n;
        while(n){
            digit.push_back(n % 2);
            n /= 2;
        }

        ll ans;

        if(temp % 2 != 0){
            int cnt = 0;
            for(int i = 0; i < digit.size(); i++){
                if(digit[i] == 0)
                    break;
                cnt++;
            }
            ans = (ll) temp + (1LL<<(cnt-1));
        }
        else{
            digit.push_back(0);
            reverse(digit.begin(), digit.end());
            int k;
            for(int i = digit.size() - 1; i >= 0; i--){
                if(digit[i] == 1 && digit[i-1] == 0){
                    digit[i] = 0, digit[i-1] = 1;
                    k = i;
                    break;
                }
            }

            sort(digit.begin() + k + 1, digit.end());

            ans = 0;
            int cnt = 0;
            for(int i = digit.size() - 1; i >= 0; i--){
                ans += ll(digit[i] * ll(1LL << cnt));
                cnt++;
            }
        }
        printf("Case %d: %lld\n", caseno++, ans);
        digit.clear();
    }

    return 0;
}
