#include <bits/stdc++.h>
#define MAX 35
using namespace std;

typedef long long ll;

vector<ll> setA, setB;
ll arr[MAX], n, weight;

ll genSet1(ll i, ll sum, ll Max)
{
    if(sum > weight)
        return 0;
    if(i == Max){
        setA.push_back(sum);
        return 0;
    }

    genSet1(i + 1, sum + arr[i], Max);
    genSet1(i + 1, sum, Max);
}

ll genSet2(ll i, ll sum, ll Max)
{
    if(sum > weight)
        return 0;
    if(i == Max){
        setB.push_back(sum);
        return 0;
    }

    genSet2(i + 1, sum + arr[i], Max);
    genSet2(i + 1, sum, Max);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &n, &weight);

        for(int i = 0; i < n; i++){
            scanf("%lld", &arr[i]);
        }

        genSet1(0, 0, n/2);     //first half
        genSet2(n/2, 0, n);       //second half

        sort(setA.begin(), setA.end());         //sorting two set
        sort(setB.begin(), setB.end());

        ll result = 0;

        ll l = upper_bound(setA.begin(), setA.end(), weight) - setA.begin();
        ll r = upper_bound(setB.begin(), setB.end(), weight) - setB.begin();

        result += (l + r - 2);

        for(int i = 1; i < setA.size(); i++){
            ll rem = weight - setA[i];
            int idx = upper_bound(setB.begin(), setB.end(), rem) - setB.begin();
            result += (ll) idx - 1;
        }

        printf("Case %d: %lld\n", caseNo++, result + 1);      //including Null set
        setA.clear();
        setB.clear();
    }

    return 0;
}
