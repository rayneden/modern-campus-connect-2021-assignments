#include<stdio.h>

int main(void){
    long i,j,n,sum=0;

    printf("Enter n:\n");
    scanf("%ld",&n);

    for(i=1;i<=n;i++,sum=0){
        for(j=1;j<i;j++){
            if(i%j==0){
                sum += j;
            }
        }

        if(i==sum){
            printf("%ld\n",i);
        }
    }

    return 0;
}