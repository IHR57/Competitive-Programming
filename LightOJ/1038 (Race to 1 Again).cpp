#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int primes[MAX/10], mark[MAX], counter = 0;
vector<int> divisor[MAX];
double E[MAX];

void genSieve()
{
    int limit = (int) sqrt(MAX + 1);

    mark[1] = 1;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = 1;

    primes[counter++] = 2;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2){
                    mark[j] = 1;
                }
            }
        }
    }
}

void genDiv()
{
    for(int i = 1; i < MAX; i++){
        int sqrtN = sqrt(i + 1);
        if(!mark[i])
            divisor[i].push_back(1), divisor[i].push_back(i);
        else{
            for(int j = 1; j <= sqrtN; j++){
                if(i % j == 0){
                    divisor[i].push_back(j);
                    if(i / j != j)
                        divisor[i].push_back(i / j);
                }
            }
        }
    }
}

int main()
{
    genSieve();
    genDiv();

    E[1] = 0;
    for(int i = 2; i < MAX; i++){
        double sum = 1.0;
        for(int j = 0; j < divisor[i].size(); j++){
            if(divisor[i][j] != i){
                sum += E[divisor[i][j]] + 1.0;
            }
        }
        E[i] = sum / (divisor[i].size() - 1);
    }

    //cout<<E[2]<<" "<<E[5]<<" "<<E[10]<<" "<<E[25]<<" "<<E[50]<<endl;
    int test, caseNo = 1, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        printf("Case %d: %0.8lf\n", caseNo++, E[n]);
    }

    return 0;
}
