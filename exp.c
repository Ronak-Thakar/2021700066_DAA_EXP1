#include<stdio.h>
int main(){
    FILE *f;
    f = fopen("num.txt","w");
    for(int i = 0;i<100000;i++){
       fprintf(f,"%d\n",rand());
    }
}