#include <iostream>
#include <string.h>
using namespace std;

const int length=1000;

char* sum(char* First, char* Second);
void revStr(char* one);

bool isPalin(char* str)
{
    int len=strlen(str)-1;
    char newStr[length];

    int i=0;

    for(int j=len; j>=0; j--){
        newStr[i]=str[j];
        i++;
    }
    newStr[i]='\0';

    if(strcmp(str, newStr)==0)
        return true;
    return false;
}

int main()
{
    char first[length], second[length];
    int i, j, test, count;
    bool flag=false;

    cin>>test;

    while(test--){
        count=0;
        cin>>first;
        while(isPalin(first)!=true){
            int len=strlen(first);

            for(j=len-1, i=0; j>=0; j--){
                second[i]=first[j];
                i++;
            }
            second[i]='\0';
            //cout<<second<<endl;
            strcpy(first, sum(first, second));
            //cout<<first<<endl;
            count++;
        }
        cout<<count<<" "<<first<<endl;
    }

    return 0;

}

char* sum(char* First, char* Second)
{
    int firstLen, secondLen, sum, carry=0, first, second, i=0;
    char *totalSum;

    totalSum=new char[length];

    firstLen=strlen(First)-1;
    secondLen=strlen(Second)-1;

    while(firstLen>=0 || secondLen>=0){
        first=First[firstLen]-48;
        second=Second[secondLen]-48;

        if(firstLen<0)  first=0;
        if(secondLen<0)  second=0;

        sum=first+second+carry;

        if(sum>9)
            carry=1;
        else
            carry=0;
        totalSum[i]=(sum%10)+48;
        i++;
        firstLen--;     secondLen--;
    }
    if(carry>0){
        totalSum[i]=carry+48;
        totalSum[++i]='\0';
    }
    else
        totalSum[i]='\0';
    revStr(totalSum);

    return totalSum;
}

void revStr(char* one)
{
    char temp[length];
    int i=0, j;
    int len=strlen(one)-1;

    for(j=len; j>=0; j--){
        temp[i]=one[j];
        i++;
    }
    temp[i++]='\0';

    strcpy(one, temp);
}
