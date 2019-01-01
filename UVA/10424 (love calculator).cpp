#include <stdio.h>
#include <string.h>

int main()
{
    char name1[30], name2[30];
    int i, t1, t2, count, sum1, sum2, len1, len2;
    double percentage;

    while(scanf("%s %s", name1, name2)==2){
        sum1=0;
        sum2=0;
        t1=0;
        t2=0;
        len1=strlen(name1);
        len2=strlen(name2);

        for(i=0; i<len1; i++){
            if(name1[i]=='A' || name1[i]=='a')
                count=1;
            else if(name1[i]=='B' || name1[i]=='b')
                count=2;
            else if(name1[i]=='C' || name1[i]=='c')
                count=3;
            else if(name1[i]=='D' || name1[i]=='d')
                count=4;
            else if(name1[i]=='E' || name1[i]=='e')
                count=5;
            else if(name1[i]=='F' || name1[i]=='f')
                count=6;
            else if(name1[i]=='G' || name1[i]=='g')
                count=7;
            else if(name1[i]=='H' || name1[i]=='h')
                count=8;
            else if(name1[i]=='I' || name1[i]=='i')
                count=9;
            else if(name1[i]=='J' || name1[i]=='j')
                count=10;
            else if(name1[i]=='K' || name1[i]=='k')
                count=11;
            else if(name1[i]=='L' || name1[i]=='l')
                count=12;
            else if(name1[i]=='M' || name1[i]=='m')
                count=13;
            else if(name1[i]=='N' || name1[i]=='n')
                count=14;
            else if(name1[i]=='O' || name1[i]=='o')
                count=15;
            else if(name1[i]=='P' || name1[i]=='p')
                count=16;
            else if(name1[i]=='Q' || name1[i]=='q')
                count=17;
            else if(name1[i]=='R' || name1[i]=='r')
                count=18;
            else if(name1[i]=='S' || name1[i]=='s')
                count=19;
            else if(name1[i]=='T' || name1[i]=='t')
                count=20;
            else if(name1[i]=='U' || name1[i]=='u')
                count=21;
            else if(name1[i]=='V' || name1[i]=='v')
                count=22;
            else if(name1[i]=='W' || name1[i]=='w')
                count=23;
            else if(name1[i]=='X' || name1[i]=='x')
                count=24;
            else if(name1[i]=='Y' || name1[i]=='y')
                count=25;
            else if(name1[i]=='Z' || name1[i]=='z')
                count=26;
            sum1+=count;
        }
        for(i=0; i<len2; i++){
            if(name2[i]=='A' || name2[i]=='a')
                count=1;
            else if(name2[i]=='B' || name2[i]=='b')
                count=2;
            else if(name2[i]=='C' || name2[i]=='c')
                count=3;
            else if(name2[i]=='D' || name2[i]=='d')
                count=4;
            else if(name2[i]=='E' || name2[i]=='e')
                count=5;
            else if(name2[i]=='F' || name2[i]=='f')
                count=6;
            else if(name2[i]=='G' || name2[i]=='g')
                count=7;
            else if(name2[i]=='H' || name2[i]=='h')
                count=8;
            else if(name2[i]=='I' || name2[i]=='i')
                count=9;
            else if(name2[i]=='J' || name2[i]=='j')
                count=10;
            else if(name2[i]=='K' || name2[i]=='k')
                count=11;
            else if(name2[i]=='L' || name2[i]=='l')
                count=12;
            else if(name2[i]=='M' || name2[i]=='m')
                count=13;
            else if(name2[i]=='N' || name2[i]=='n')
                count=14;
            else if(name2[i]=='O' || name2[i]=='o')
                count=15;
            else if(name2[i]=='P' || name2[i]=='p')
                count=16;
            else if(name2[i]=='Q' || name2[i]=='q')
                count=17;
            else if(name2[i]=='R' || name2[i]=='r')
                count=18;
            else if(name2[i]=='S' || name2[i]=='s')
                count=19;
            else if(name2[i]=='T' || name2[i]=='t')
                count=20;
            else if(name2[i]=='U' || name2[i]=='u')
                count=21;
            else if(name2[i]=='V' || name2[i]=='v')
                count=22;
            else if(name2[i]=='W' || name2[i]=='w')
                count=23;
            else if(name2[i]=='X' || name2[i]=='x')
                count=24;
            else if(name2[i]=='Y' || name2[i]=='y')
                count=25;
            else if(name2[i]=='Z' || name2[i]=='z')
                count=26;
            sum2+=count;
        }
        /*printf("%d %d", sum1, sum2);*/
        while(1){
            while(sum1!=0){
                t1=t1+(sum1%10);
                sum1=sum1/10;
            }
            if(t1/10==0){
                break;
            }
            else{
                sum1=t1;
                t1=0;
            }
        }
        while(1){
            while(sum2!=0){
                t2=t2+(sum2%10);
                sum2=sum2/10;
            }
            if(t2/10==0){
                break;
            }
            else{
                sum2=t2;
                t2=0;
            }
        }
        if(t1>t2){
            percentage=(double)(t2*100.00)/t1;
        }
        else
            percentage=(double)(t1*100.00)/t2;
        printf("%0.2lf %%\n", percentage);
    }

    return 0;
}
