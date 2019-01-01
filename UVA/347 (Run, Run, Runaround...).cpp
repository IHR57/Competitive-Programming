#include <bits//stdc++.h>
#include <string.h>
using namespace std;

char str[120];
int N, sols[9999999];

bool check (int n)
{
    int position = n % 10;

    int d[10] = {0};

    while(n != 0){
        if(d[position] || position == 0)
            return false;       //if digit is 0 or repeating digit
        d[position] = 1;
        n = n / 10;
        position = n % 10;
    }

    return true;
}

bool initialize(int n)
{
    if(!check(n))
        return false;

    sprintf(str, "%d", n);        //converting to string

    int index, digit[16] = {0};
    index = 0;
    char position = str[0] - 48;

    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if((index = index + position % len) >= len)
            index = index - len;
        if(digit[position] == 1)
            return false;
        digit[position] = 1;
        position = str[index] - 48;
    }

    if(position == str[0] - 48)     //if we find it first position again
        return true;
    return false;
}

int main()
{
    int n, digit[20], location, position, cases = 1;
    int dgt[30];

    for(int i = 9876543; i >= 10; i--){
        if(initialize(i))
            sols[i] = i;
        else
            sols[i] = sols[i + 1];
    }

    for(int i = 0; ; i++){
        cin>>N;
        if(N == 0)
            break;
        cout<<"Case "<<cases++<<": "<<sols[N]<<endl;
    }

    return 0;
}
