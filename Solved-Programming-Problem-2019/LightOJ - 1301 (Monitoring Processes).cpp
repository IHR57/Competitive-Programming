//Problem ID: LightOJ - 1301 (Monitoring Process)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 24/04/19
#include <bits/stdc++.h>
#define MAX 50005
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
int a[MAX], b[MAX];

int main()
{
    int test, caseno = 1, n, l, r;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d %d", &a[i], &b[i]);
        }
        sort(a, a + n);
        sort(b, b + n);
        int cnt = 1, Max = 1, i = 1, j = 0;
        while(i < n && j < n){
            if(a[i] <= b[j]){
                cnt++;
                Max = max(Max, cnt);
                i++;
            }
            else{
                cnt--;
                j++;
            }
        }
        printf("Case %d: %d\n", caseno++, Max);
        //vp.clear(), v.clear();
    }

    return 0;
}
