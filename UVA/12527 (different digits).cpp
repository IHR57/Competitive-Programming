#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int low, high, i, j, k, count;
    bool flag;
    char str[100];  //character array

    while(cin>>low>>high){
        count=0;
        for(k=low; k<=high; k++){
            int value=k;
            i=0;
            while(value!=0){
                str[i++]=value%10+48;   //converting integer to character and putting it into array
                value=value/10;
            }
            str[i++]='\0';  //assign null at the end;

            int len=strlen(str);

            flag=true;

            for(i=0; i<len-1; i++){     //checking each character
                for(j=i+1; j<len; j++){
                    if(str[i]==str[j])
                    {
                        flag=false;     //if we find same character twice set flag equal false
                        break;
                    }
                }
            }
            if(flag==true)
                count++;
        }
        cout<<count<<endl;
    }

    return 0;
}
