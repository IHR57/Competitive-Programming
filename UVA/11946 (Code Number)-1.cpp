#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    char str[100];
    char codeNumber[] = "OIZEASGTBP";
    int test;

    cin>>test;
    getchar();

    while(test--){
        while(gets(str) != '\0'){
            int len = strlen(str);
            if(len == 0)
                break;

            for(int i = 0; i < len; i++){
                if(str[i] >= '0' && str[i] <= '9'){
                    str[i] = codeNumber[str[i] - '0'];
                }
            }
            puts(str);
        }
        if(test)
            puts("");
    }

    return 0;
}
