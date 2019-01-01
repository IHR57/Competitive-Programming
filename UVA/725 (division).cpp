#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, abcde, fghij, value, temp, count=0;

    while(cin>>n && n!=0){
        int flag=0;
        count++;
        if(count>1)
             printf("\n");
        for(fghij = 1234; fghij<=98765/n; fghij++){
            int abcde = fghij*n;
            value = (fghij<10000);
            temp = abcde;
            while(temp){
                value |= 1<<(temp%10);
                temp = temp/10;
            }

            temp = fghij;
            while(temp){
                value |= 1<<(temp%10);
                temp = temp/10;
            }

            if(value == (1<<10)-1){
                printf("%0.5d / %0.5d = %d\n", abcde, fghij, n);
                flag = 1;
            }
        }
        if(!flag)
            printf("There are no solutions for %d.\n", n);
    }

    return 0;
}
