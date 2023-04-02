#include<stdio.h>
#include<stdbool.h>
int parent[100],weight[100][100];
int min(int key[],bool isused[],int num){
    int minkey = 20000,i;
    for(int x=0;x<num;x++){
       if(isused[x] == false && key[x] < minkey){
          minkey = key[x];
          i = x;
       }
    }
    return i;
}

int prim(int num){
    int key[num],total=0;
    bool isused[num];
    for(int i=0;i<num;i++){
        key[i] = 20000;
        isused[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int i=0;i<num-1;i++){
       int u = min(key,isused,num);
       isused[i] = true;
       for(int x=0;x<num;x++){
          if(weight[u][x] < key[x] && isused[x] == false && weight[u][x]>0){
            parent[x] = u;
            key[x] = weight[u][x];
            total = total + key[x];
          }
       }
    }
    return total;
}

int main(){
    int num,s,e,w,ch;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&num);
    printf("\nEnter the edges and weights: ");
    do{
        printf("\nEnter Start Point: ");
        scanf("%d",&s);
        printf("\nEnter End Point: ");
        scanf("%d",&e);
        printf("\nEnter Weight: ");
        scanf("%d",&w);
        weight[s][e] = w;
        weight[e][s] = w;
        printf("\nEnter 0 to stop: ");
        scanf("%d",&ch);
    }while(ch!=0);
    int total = prim(num);
    printf("Edge\tWeight");
    for(int i=1;i<num;i++){
       printf("\n%d - %d\t%d",parent[i],i,weight[i][parent[i]]);
    }
    printf("\nTotal = %d",total);
}