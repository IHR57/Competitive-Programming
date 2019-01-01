#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

bool isMirrored(char c)
{
    return c=='A' || c=='H' || c=='I' || c=='M' || c=='O' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y';
}
int main()
{
    char str[100005];
    int i;

    scanf("%s", str);
    int len=strlen(str);

    for(int i=0; i<len; i++){
        if(!isMirrored(str[i]) || str[i]!=str[len-i-1]){
            printf("NO");
            return 0;
        }
    }
    printf("YES");

    return 0;
}
