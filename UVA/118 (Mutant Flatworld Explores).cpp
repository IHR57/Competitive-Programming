#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    int row, col, x, y, visited[105][105] = {};
    char cp[2], str[500], current_pos;

    scanf("%d %d", &row, &col);

    while(scanf("%d %d %c", &x, &y, cp) == 3){
        scanf("%s", str);
        int len = strlen(str);

        current_pos = cp[0];
        bool flag = false;
        int tx, ty;
        for(int i = 0; i < len; i++){
            if(str[i] == 'R'){
                if(current_pos == 'N')
                    current_pos = 'E';
                else if(current_pos == 'E')
                    current_pos = 'S';
                else if(current_pos == 'W')
                    current_pos = 'N';
                else if(current_pos == 'S')
                    current_pos = 'W';
            }
            else if(str[i] == 'L'){
                if(current_pos == 'N')
                    current_pos = 'W';
                else if(current_pos == 'E')
                    current_pos = 'N';
                else if(current_pos == 'W')
                    current_pos = 'S';
                else if(current_pos == 'S')
                    current_pos = 'E';
            }
            else if(str[i] == 'F'){
                switch(current_pos)
                {
                    case 'N': y++; break;
                    case 'E': x++; break;
                    case 'W': x--; break;
                    case 'S': y--; break;
                }
            }
            if(x < 0 || y < 0 || x > row || y > col){
                switch(current_pos)
                {
                    case 'N': y--; break;
                    case 'E': x--; break;
                    case 'W': x++; break;
                    case 'S': y++; break;
                }
                if(visited[x][y] == 1)
                    continue;
                flag = true;
                visited[x][y] = 1;
                break;
            }
        }
        if(flag){
            printf("%d %d %c LOST\n", x, y, current_pos);
        }
        else
            printf("%d %d %c\n", x, y, current_pos);
    }

    return 0;
}
