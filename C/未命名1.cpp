#include <stdio.h>

int main(void) {
    int exponent, ratio;
    int arr1[101] = {0};
    int arr2[101] = {0};
     
    do{
        scanf("%d %d", &exponent, &ratio);
        arr1[exponent] = ratio;
    }while(exponent!=0);
     
    do{
        scanf("%d %d", &exponent, &ratio);
        arr2[exponent] = ratio;
    }while(exponent!=0);
    int flag = 0;
    for(int i=100;i>=0;i--){
        if (arr1[i]!=0 || arr2[i]!=0){
            int ratio = arr1[i] + arr2[i];
                if(flag == 1){
                    printf("+");
                }else{
                    flag = 1;
                }
                 
                if(i==0){
                    printf("%d",ratio);
                }else if(i==1){
                    printf("%dx",ratio);
                }else{
                    printf("%dx%d",ratio,i);
                }
        }
    }
    printf("\n");
}
