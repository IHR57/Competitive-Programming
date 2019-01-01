#include <bits/stdc++.h>
#define MAX 1005
#define MOD 100000007
using namespace std;

typedef long long ll;
ll way[MAX], temp[MAX];

struct data
{
    int value, quantity;
};

vector<data> v;

bool compare(data A, data B)
{
    return A.value < B.value;
}

int main()
{
    int test, caseNo = 1, a[55], c[55], target, n;

    scanf("%d",  &test);

    while(test--){
        scanf("%d %d", &n, &target);     //given coin and target value
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++){
            scanf("%d", &c[i]);
        }

        for(int i = 1; i <= n; i++){
            data d;
            d.value = a[i], d.quantity = c[i];
            v.push_back(d);
        }
        //sort(a+1, a + n + 1);

        sort(v.begin(), v.end(), compare);
        memset(way, 0, sizeof(way));
        memset(temp, 0, sizeof(temp));

        int lim = min(target, v[0].value * v[0].quantity);

        way[0] = temp[0] = 1;

        for(int i = 1; i <= lim; i++){
            if(i % v[0].value == 0)
                way[i] = 1, temp[i] = 1;
        }

        for(int i = 2; i <= n; i++){
            for(int j = v[i-1].value; j <= target; j++){
                int value = j;
                for(int k = 1; k <= v[i-1].quantity; k++){
                    int t = k * v[i-1].value;
                    if(value - t >= 0){
                        way[j] = (way[j] + temp[value - t]);
                        if(way[j] >= MOD)
                            way[j] %= MOD;
                    }
                    else
                        break;
                }
            }
            for(int j = 1; j <= target; j++){
                //cout<<way[j]<<" ";
                temp[j] = way[j];
            }
        }

        printf("Case %d: %lld\n", caseNo++, way[target]);
        v.clear();
    }

    return 0;
}
