#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int convertDecimal(int a[], int n)
{
    int temp=0;
    int len=n-1;

    for(int i=0; i<n; i++){
        temp+=(a[i]*pow(10, len));
        len--;
    }

    return temp;
}

int main()
{
    int i, j, k, m, CaseNo=1, number[20], test, temp;
    char str[100000];

    cin>>test;

    while(test--){
        cin>>str;
        int len=strlen(str);

        cout<<"Case "<<CaseNo++<<": ";
        for(i=0; i<len; ){
            j=i+1;
            k=0;
            while(str[j]>='0' && str[j]<='9'){
                number[k++]=str[j]-48;      //if we find number then store it
                j++;
            }
            temp=convertDecimal(number, k);

            for(m=0; m<temp; m++){
                cout<<str[i];
            }
            i=j;    //set equal to j
        }
        cout<<endl;
    }

    return 0;
}
