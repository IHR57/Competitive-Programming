#include <stdio.h>

bool data[1000005];
int cupNumber, holeNumber, operation;
int hole;

int main()
{
    scanf("%d %d %d", &cupNumber, &holeNumber, &operation);

    for(int i = 0; i < holeNumber; i++){
        scanf("%d", &hole);
        data[hole] = true;
    }

    int a, b, currentPosition = 1;

    for(int i = 0; i < operation; i++){
        scanf("%d %d", &a, &b);
        if(data[currentPosition])   //if we find any hole
            break;
        if(a == currentPosition)
            currentPosition = b;
        else if(b == currentPosition)
            currentPosition = a;
    }

    printf("%d\n", currentPosition);

    return 0;

}
