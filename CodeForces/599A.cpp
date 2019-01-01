#include <iostream>
using namespace std;

int main()
{
    int d1, d2, d3;

    cin>>d1>>d2>>d3;

    int value1 = 2 * (d1 + d3);
    int value2 = 2 * (d2 + d3);
    int value3 = (d1 + d2 + d3);
    int value4 = 2 * (d1 + d2);

    int result = min(value1, value2);
    result = min(result, value3);
    result = min(result, value4);

    cout<<result<<endl;

    return 0;
}
