#include<stdio.h>
int main(){
    int n=9;
    for(int i=1;i<=n;i++){
        int count=i;
        for(int j=1;j<n+i;j++){
            if(j<=n-i){
                printf(" ");
            }else if(j>n-i && j<n){
                printf("%d",count);
                count--;
            }else{
                printf("%d",count);
                count++;
            }

        }
        printf("\n");
    }
}