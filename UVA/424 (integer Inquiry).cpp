#include <iostream>
#include <string.h>
using namespace std;

void revStr(char* one, char* two);

int main()
{
    char strFirst[200], strSecond[200], strSum[200];
    int firstLen, secondLen, carry;
    int first, second, sum;

    cin>>strFirst;
    while(cin>>strSecond && strSecond[0]!='0'){
        carry=0;
        int i=0;
        firstLen=strlen(strFirst)-1;
        secondLen=strlen(strSecond)-1;

        while(firstLen>=0 || secondLen>=0){
            first=strFirst[firstLen]-48;
            second=strSecond[secondLen]-48;

            if(firstLen<0)  first=0;
            if(secondLen<0) second=0;

            sum=first+second+carry;

            if(sum>9){
                carry=1;
            }
            else
                carry=0;
            strSum[i]=(sum%10)+48;
            i++;
            firstLen--; secondLen--;
        }
        if(carry>0){
            strSum[i]=carry+48;
            strSum[++i]='\0';
        }
        else{
            strSum[i]='\0';
        }
        revStr(strSum, strFirst);
    }

    cout<<strFirst<<endl;

    return 0;
}

void revStr(char* one, char* two)
{
    int len=strlen(one)-1;
    int i=0;

    for(int j=len; j>=0; j--){
        two[i]=one[j];
        i++;
    }
    two[i]='\0';
}
