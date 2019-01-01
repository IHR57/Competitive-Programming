#include <bits/stdc++.h>
#define MAX 35
using namespace std;

typedef long long ll;

vector<ll> v, setA, setB;
int arr[MAX], n;

void genSet1(int k)         //general all possible combination for first half of the array
{
    if(k == n / 2){
        ll sum =  0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
        }
        if(v.size() != 0)
            setA.push_back(sum);
        return;
    }

    genSet1(k + 1);
    v.push_back(arr[k]);
    genSet1(k + 1);
    v.pop_back();
}

void genSet2(int k)             ////general all possible combination for second half of the array
{
    if(k == n){
        ll sum =  0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
        }
        if(v.size() != 0)
            setB.push_back(sum);
        return;
    }

    genSet2(k + 1);
    v.push_back(arr[k]);
    genSet2(k + 1);
    v.pop_back();
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test, caseNo = 1, weight;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &weight);

        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        v.clear();
        genSet1(0);     //first half
        v.clear();
        genSet2(n/2);       //second half

        sort(setA.begin(), setA.end());         //sorting two set
        sort(setB.begin(), setB.end());

        ll result = 0;

        int l = upper_bound(setA.begin(), setA.end(), weight) - setA.begin();
        int r = upper_bound(setB.begin(), setB.end(), weight) - setB.begin();

        result += (ll) (l+r);

        for(int i = 0; i < setA.size(); i++){
            ll rem = weight - setA[i];
            int idx = upper_bound(setB.begin(), setB.end(), rem) - setB.begin();
            result += (ll) idx;
        }

        printf("Case %d: %lld\n", caseNo++, result + 1);      //including Null set
        setA.clear();
        setB.clear();
    }

    return 0;
}
