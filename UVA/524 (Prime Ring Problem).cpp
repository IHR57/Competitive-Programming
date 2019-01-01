//Problem ID: UVA 524 (Prime Ring Problem)
//Programmer: IQBAL HOSSAIN     Description: Backtracking (Permutation)
//Date: 30-01-16
#include <cstdio>
#include <math.h>
using namespace std;
int n, Case = 0;
int position[20] = {1};
//char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool isPrime(int value)
{
    int sqrtN = sqrt(value + 1);

    if(value % 2 == 0)
        return false;
    for(int i = 3; i <= sqrtN; i += 2){
        if(value % i == 0)
            return false;
    }

    return true;
}

void genPermutation(int idx, bool taken[])
{
    if(idx == n){
        if(!isPrime(position[n-1] +1))
            return;
        printf("1");
            //the number of first circle should always be 1
        for(int i = 1; i < n; i++){
            printf(" %d", position[i]);
        }
        printf("\n");

        return;
    }
    for(int i = 2; i <= n; i++){
            if(taken[i])
                continue;
            if(isPrime(i + position[idx - 1])){
                taken[i] = 1;
                position[idx] = i;
                genPermutation(idx+1, taken);
                taken[i] = 0;
            }
    }
}

int main()
{
    int test, cases = 1;

    while(scanf("%d", &n))
    {
        if(Case++)
            putchar('\n');
        bool visit[20] = {0};
        printf("Case %d:\n", cases++);
        genPermutation(1, visit);
    }
}
