#include<stdio.h>
#include<time.h>
void swap(int arr[],int l,int h){
    int temp = arr[l];
    arr[l] = arr[h];
    arr[h] = temp;
}
int partition(int arr[], int l, int h){
    int X = arr[l],i = l;
    for(int j = l+1;j <= h;j++){
        if(arr[j]<X){
          i++;
          swap(arr,i,j);
        }
    }
    swap(arr,l,i);
    return(i);
}
void quick_sort(int arr[],int l,int h){
    if(l<h){
        int X = partition(arr,l,h);
        quick_sort(arr,l,X-1);
        quick_sort(arr,X+1,h); 
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
        quick_sort(arr,0,y-1);
        t2 = clock();
        double total = ((double)(t2 - t1))/CLOCKS_PER_SEC;
        printf("%lf \n",total);
        for(int i=0;i<y;i++){
            arr[i] = arr2[i];
        }
    }
}