#include <iostream>
using namespace std;

int main()
{
    int n, data[110][110], sum = 0;

    cin>>n;

    for(int i = 0; i <n; i++){
        for(int j = 0; j < 3; j++){
            cin>>data[i][j];
            sum += data[i][j];
        }
    }

    if(sum == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
