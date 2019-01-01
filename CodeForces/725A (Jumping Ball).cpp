#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string str;

    cin>>n;
    cin>>str;

    int i = 0, count = 0;

    while(i<n && str[i]=='<'){
        count = count+1;
        i = i+1;
    }

    i = n-1;

    while(i>=0 && str[i]=='>'){
        count = count+1;
        i = i-1;
    }

    cout<<count<<endl;

    return 0;
}
