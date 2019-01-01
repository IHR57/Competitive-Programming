#include <bits//stdc++.h>
#define MAX 9876543210
using namespace std;

typedef long long int lint;

bool check(lint n)
{
    bool flag[10];

    memset(flag, false, sizeof(flag));

    while(n){
        int position = n % 10;
        if(flag[position])
            return false;       //if digit is 0 or repeating digit
        flag[position] = true;
        n = n / 10;
    }

    return true;
}

int main()
{
    int test;
    lint n, value;

    cin>>test;

    while(test--){
        cin>>n;

        //cout<<check(n)<<endl;

        for(lint i = 1; ; i++){
            if(!check(i))
                continue;
            value = n * i;

            if(value > MAX)
                break;
            if(check(value))
                cout<<value<<" / "<<i<<" = "<<n<<endl;
        }
        if(test)
            printf("\n");
    }

    return 0;
}
