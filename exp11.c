#include<stdio.h>
#include<time.h>
int min(int arr[],int k,int size){
    int pos = k;
    for(int i = k+1;i<size;i++){
        if(arr[i]<arr[pos]){
           pos = i;
        }
    }
    return pos;
}
void selection_sort(int arr[],int size){
    int temp,m,i;
    for(i=0;i<size;i++){
       m = min(arr,i,size);
       temp = arr[i];
       arr[i] = arr[m];
       arr[m] = temp;
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
        selection_sort(arr,y);
        t2 = clock();
        double total = ((double)(t2 - t1))/CLOCKS_PER_SEC;
        printf("%lf \n",total);
        for(int i=0;i<y;i++){
            arr[i] = arr2[i];
        }
    }
}