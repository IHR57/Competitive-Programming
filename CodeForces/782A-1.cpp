#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#define read(x) scanf("%d", &x)
#define write(x) printf("%d\n", x)
using namespace std;

bool box[200005] = {false};

int main()
{
    int sock, n, x, ans = 1, count = 0;

    read(sock);

    for(int i = 0; i < 2 * sock; i++){
        read(x);
        if(!box[x]){
            count++;
            ans = max(ans, count);
            box[x] = true;
        }
        else{
            count--;
            box[x] = false;
        }
    }

    write(ans);

    return 0;
}
