#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int test, n, i, j, c1, c2, c3, c4, c5, c6, c7, c8, c9, c0;
    char str[100005];

    cin>>test;

    while(test--){
        cin>>n;
        c0=c1=c2=c3=c4=c5=c6=c7=c8=c9=0;
        j=0;
        for(i=1; i<=n; i++){
            int n=i;
            while(n!=0){
                str[j++]=(n%10)+48;
                n=n/10;
            }

        }
        str[j++]='\0';
        int len=strlen(str);

        for(j=0; str[j]; j++){
            if(str[j]=='0') c0++;
            else if(str[j]=='1')    c1++;
            else if(str[j]=='2')    c2++;
            else if(str[j]=='3')    c3++;
            else if(str[j]=='4')    c4++;
            else if(str[j]=='5')    c5++;
            else if(str[j]=='6')    c6++;
            else if(str[j]=='7')    c7++;
            else if(str[j]=='8')    c8++;
            else if(str[j]=='9')    c9++;
        }
        cout<<c0<<" "<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<" "<<c5<<" "<<c6<<" "<<c7<<" "<<c8<<" "<<c9<<endl;
    }

    return 0;
}
