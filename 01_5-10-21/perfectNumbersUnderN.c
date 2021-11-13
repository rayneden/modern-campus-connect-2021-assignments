#include<stdio.h>

int isPerfect(long num){
    int j,sum=0;
    for(j=1;j<num;j++){
        if(num%j==0){
            sum += j;
        }
    }

    if(num==sum){
        return 1;
    }

    return 0;
}

int main(void){
    long i,j,n;

    printf("Enter n:\n");
    scanf("%ld",&n);

    for(i=1;i<=n;i++){
        if(isPerfect(i)){
            printf("%ld\n",i);
        }
    }

    return 0;
}