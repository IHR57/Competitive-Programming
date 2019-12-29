//Problem ID: LightOJ - 1269 (Consecutive Sum)
//Programmer: IQBAL HOSSAIN     Description: Trie Tree
//Date: 10/04/19
#include <bits/stdc++.h>
#define MAX 2000005
using namespace std;

int node[MAX][2];
int root, nnode;

void init()
{
    root = 0;
    nnode = 0;
    for(int i = 0; i < 2; i++)
        node[root][i] = -1;
}

int convertToDecimal(string str)
{
    int len = str.size();
    int p = 1, sum = 0;
    for(int i = len - 1; i >= 0; i--){
        sum += (p * (str[i] - 48));
        p <<= 1;
    }

    return sum;
}

void insert(int n)
{
    int now = root;
    for(int i = 31; i >= 0; i--){
        bool cb = (n & (1 << i));
        if(node[now][cb] == -1){
            node[now][cb] = ++nnode;
            for(int j = 0; j < 2; j++){
                node[nnode][j] = -1;
            }
        }
        now = node[now][cb];
    }
}

int xorMax(int n)
{
    string temp;
    int now = root;
    for(int i = 31; i >= 0; i--){
        bool cb = (n & (1 << i));
        if(node[now][1-cb] != -1){
            now = node[now][1-cb];
            (cb == 1) ? temp += "0" : temp += "1";
        }
        else{
            now = node[now][cb];
            (cb == 1) ? temp += "1" : temp += "0";
        }
    }

    return convertToDecimal(temp);
}

int xorMin(int n)
{
    string temp;
    int now = root;
    for(int i = 31; i >= 0; i--){
        bool cb = (n & (1 << i));
        if(node[now][cb] != -1){
            now = node[now][cb];
            (cb == 1) ? temp += "1" : temp += "0";
        }
        else{
            now = node[now][1-cb];
            (cb == 1) ? temp += "0" : temp += "1";
        }
    }

    return convertToDecimal(temp);
}
int main()
{
    int test, caseno = 1, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int val;

        init();
        int xorSum = 0;
        insert(0);
        int Min = 2147483647, Max = -1;

        for(int i = 0; i < n; i++){
            scanf("%d", &val);
            xorSum ^= val;
            Max = max(Max, xorMax(xorSum) ^ xorSum);
            Min = min(Min, xorMin(xorSum) ^ xorSum);
            insert(xorSum);
        }

        printf("Case %d: %d %d\n", caseno++, Max, Min);
    }

    return 0;
}
