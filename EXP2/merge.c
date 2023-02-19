#include<stdio.h>
#include<time.h>
int merge(int arr[],int l,int m,int r){
    int i= 0,j = 0,k = 0,n1,n2;
    n1 = m - l + 1;
    n2 = r - m;
    int left[n1],right[n2];
    for(int x = 0;x<n1;x++)
       left[x] = arr[l + x];
    for(int x = 0;x<n2;x++)
       right[x] = arr[m + 1 + x];
    k = l;
    while(i<n1 && j<n2){
       if(left[i]<=right[j]){
        arr[k] = left[i];
        i++;
       }
       else{
        arr[k] = right[j];
        j++;
       }
       k++;
    }
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[],int l,int r){
    if(l<r){
      int m = l + (r-l)/2;
      merge_sort(arr,l,m);
      merge_sort(arr,m+1,r);

      merge(arr,l,m,r);  
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
        merge_sort(arr,0,y-1);
        t2 = clock();
        double total = ((double)(t2 - t1))/CLOCKS_PER_SEC;
        printf("%lf \n",total);
        for(int i=0;i<y;i++){
            arr[i] = arr2[i];
        }
    }
}