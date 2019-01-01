#include <bits/stdc++.h>
#define MAX 25
#define pb push_back
using namespace std;

typedef long long ll;

vector<ll> setA, setB;
int coins[MAX];
int n, k;

void createSetA(int idx, ll value)
{
    setA.pb(value);
    //cout<<"("<<idx<<" "<<value<<")"<<endl;
    if(idx == n / 2)
        return;
    createSetA(idx+1, value);
    createSetA(idx+1, value+coins[idx]);
    createSetA(idx+1, value+2*coins[idx]);
}

void createSetB(int idx, ll value)
{
    setB.pb(value);
    //cout<<"("<<idx<<" "<<value<<")"<<endl;
    if(idx == n)
        return;
    createSetB(idx+1, value);
    createSetB(idx+1, value+coins[idx]);
    createSetB(idx+1, value+2*coins[idx]);
}

int main()
{
    int test, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%d", &coins[i]);
        }

        createSetA(0, 0);       //first half
        createSetB(n/2, 0);     //second half

        sort(setB.begin(), setB.end());

        int flag = 0;
        for(int i = 0; i < setA.size(); i++){
            if(binary_search(setB.begin(), setB.end(), k - setA[i])){
                flag = 1;
                printf("Case %d: Yes\n", caseNo++);
                break;
            }
        }

        if(!flag){
            printf("Case %d: No\n", caseNo++);
        }

        setA.clear();
        setB.clear();
    }

    return 0;
}
