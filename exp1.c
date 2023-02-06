#include<stdio.h>
#include<math.h>
double fact(int x){
     if(x==0)
       return 1;
     else
       return x*fact(x-1);
}
int f1(int x){
    return x;
}
double f2(int x){
    return log(x);
}
double f3(int x){
    return log2(log2(x));
}
double f4(int x){
    return pow(2,log2(x));
}
double f5(int x){
    return log2(x);
}
double f6(int x){
    return pow(sqrt(2),log2(x));
}
double f7(int x){
    return pow(log2(x),2);
}
double f8(int x){
    return pow(2,sqrt(2*log2(x)));
}
double f9(int x){
    return x*log2(x);
}
double f10(int x){
    return pow(x,1.0/log2(x));
}
int main(){
    printf("\nX\tF1\tF2\tF3\tF4\tF5\tF6\tF7\tF8\tF9\tF10");
    for(int i=0;i<=100;i+=10){
       printf("\n%d\t",i);
       printf("%d\t",f1(i));
       printf("%.2lf\t",f2(i));
       printf("%.2lf\t",f3(i));
       printf("%.2lf\t",f4(i));
       printf("%.2lf\t",f5(i));
       printf("%0.2lf\t",f6(i));
       printf("%.2lf\t",f7(i));
       printf("%.2lf\t",f8(i));
       printf("%.2lf\t",f9(i));
       printf("%.2lf",f10(i));
    }
    printf("\n\nX\tF11");
    for(int i=0;i<=20;i+=2){
       printf("\n%d\t%.2lf",i,fact(i));
    }
}
