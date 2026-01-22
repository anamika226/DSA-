#include <stdio.h>
int main(){
    int n,sum=0,avg;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum=sum+arr[i];
    }
    avg=sum/n;
    sum=0;
    for(int i=0;i<n;i++){
        if(avg<arr[i])
        sum=sum+arr[i];

    }
    printf("sum=%d",sum);
    return 0;
}
