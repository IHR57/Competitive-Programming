#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;

bool isSqrt(int num)
{
    int sqrtNum=sqrt(num);

    if(num==sqrtNum*sqrtNum)
        return true;
    return false;
}

int main()
{
    char str[10010], c;
    char temp[110][10010];
    int len, test, val;

    scanf("%d", &test);
    getchar();

    while(test--){
        gets(str);
        len=strlen(str);
        if(isSqrt(len)==false){
            cout<<"INVALID"<<endl;
            continue;
        }
        int k=0, i, j;

        val=sqrt(len);
        for(i=0; i<val; i++){
            for(j=0; j<val; j++){
                temp[i][j]=str[k++];
            }
        }

        for(i=0; i<val; i++){
            for(j=0; j<val; j++){
                cout<<temp[j][i];
            }
        }
        cout<<endl;
    }

    return 0;
}
