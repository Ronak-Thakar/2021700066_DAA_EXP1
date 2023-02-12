#include<stdio.h>
#include<time.h>
void insertion_sort(int arr[],int y){
    int num,j;
    for(int i = 1;i<y;i++){
       num = arr[i];
       j = i-1;
       while((num<arr[j]) && j>=0){
          arr[j+1] = arr[j];
          j--;
       }
       arr[j+1] = num;
    }
}
int main(){
    int arr[100000],arr2[100000],y=0;
    clock_t t1,t2;
    FILE *f;
    f = fopen("num.txt","r");
    for(int i = 0;i<100000;i++){
       fscanf(f,"%d",&arr[i]);
       arr2[i] = arr[i];
    }
    fclose(f);
    while(y < 100000){
        y +=100;
        t1 = clock();
        insertion_sort(arr,y);
        t2 = clock();
        double total = ((double)(t2 - t1))/CLOCKS_PER_SEC;
        printf("%lf \n",total);
        for(int i=0;i<y;i++){
            arr[i] = arr2[i];
        }
    }
}