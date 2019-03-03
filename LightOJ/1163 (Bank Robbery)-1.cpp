#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll n;
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        ll temp = n, sum = temp;
        while(temp != 0){
            sum += (temp/10);
            temp /= 10;
        }

        ll diff = (sum - (sum / 10));
        //cout<<sum<<" "<<diff<<endl;
        printf("Case %d: ", caseno++);

        if(diff <= n){
            while((sum - sum / 10) != n){
                sum++;
            }
            printf("%lld", sum);
            if((sum + 1) - (sum + 1) / 10 == n)
                printf(" %lld", sum + 1);
            printf("\n");
        }
        else{
            while((sum - sum / 10) != n){
                sum--;
            }
            //printf("%lld", sum);
            if((sum - 1) - (sum - 1) / 10 == n){
                printf("%lld %lld\n", sum, sum - 1);
            }
            else
                printf("%lld", sum);
            printf("\n");
        }
    }

    return 0;
}
