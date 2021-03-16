#include<stdio.h>
#include<math.h>

int for_sum(int n){
    int sum=0;
    while(n!=0){
        sum+=n%10;
        n=n/10;
    }
    return sum;
}

int is_prime(int n){
    int flag=1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            flag=0;
            return flag;
        }
    }
    return flag;
}

int for_factor(int n){
    int i,flag=0;
    for(i=2;i<n;i++){
        if(n%i==0 && is_prime(i)){
            flag=1;
            break;
        }
    }
    if(flag==0 && is_prime(n))
        return for_sum(n);
    if(flag==1)
        return for_sum(i)+for_factor(n/i);
}

int main(){
    int a[100],i=0;
    while(1){
        scanf_s("%d",&a[i]);
        if(a[i]==0)
            break;
        i++;
    }
    for(i=0;a[i]!=0;i++){
        if(for_sum(a[i])==for_factor(a[i]))
            printf("yes");
        else
            printf("no");
    }
    return 0;
}