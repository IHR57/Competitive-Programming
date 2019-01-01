#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

long int skewBinary(char *input)
{
    int n;
    long int number=0;
    int len=strlen(input);

    for(int i=0; input[i]; i++){
        n=input[i]-48;
        number+=n*(pow(2, len)-1);
        len--;
    }
    return number;
}

int main()
{
    char str[1000];
    int len, i;
    long int result;

    while(cin>>str){
        if(strcmp(str, "0")==0)
            break;

        result=skewBinary(str);
        cout<<result<<endl;
    }

    return 0;
}
