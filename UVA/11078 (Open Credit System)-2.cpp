#include <iostream>
using namespace std;

int main()
{
    int data[100005], n, Max, test;

    cin>>test;

    while(test--)
    {
        cin>>n;

        for(int i=0; i<n; i++){
            cin>>data[i];
        }

        Max=data[0];
        int result = data[0]-data[1];

        for(int i=1; i<n; i++){
            result = max(Max-data[i], result);
            Max = max(Max, data[i]);
        }

        cout<<result<<endl;
    }

    return 0;
}
