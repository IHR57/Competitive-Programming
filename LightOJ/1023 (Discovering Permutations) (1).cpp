#include <iostream>
#include <string.h>
using namespace std;

int k, counter;

void Swap(char *x, char *y)
{
    char temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int l, int r)
{
    if(l == r){
        cout<<str<<endl;
        counter++;
    }
    else{
        for(int i = l; i <= r; i++){
            Swap((str+l), (str+i));
            permute(str, l+1, r);
            Swap((str+l), (str+i));
            if(counter == k){
                break;
            }
        }
    }
}

int main()
{
    char str[50];
    int n, test, cases = 1;

    cin>>test;

    while(test--){
        cin>>n>>k;
        counter = 0;
        int len = strlen(str);

        int j = 0;
        for(int i = 65; i < 65+n; i++){
            str[j++] = i;
        }
        str[j++] = '\0';

        cout<<"Case "<<cases++<<":"<<endl;
        permute(str, 0, n-1);
    }

    return 0;
}
