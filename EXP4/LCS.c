#include<stdio.h>
#include<string.h>
#include<time.h>
int lcs[100][100];
int max(int x,int y){
    if(x>y)
      return x;
    else 
      return y;
}
int LCS(char a[],char b[],int la,int lb){
     if(la==0 || lb==0){
       lcs[la][lb]=0;
       return 0;
     }
     if(a[la-1]==b[lb-1]){
       lcs[la][lb] = 1 + LCS(a,b,la-1,lb-1);
       return 1 + LCS(a,b,la-1,lb-1);
     }
     else{
       lcs[la][lb] = max(LCS(a,b,la-1,lb),LCS(a,b,la,lb-1));
       return lcs[la][lb];
     }    
}
int main(){
    char a[100],b[100];
    printf("\nEnter string 1: ");
    scanf("%s",a);
    printf("\nEnter string 2: ");
    scanf("%s",b);
   // double t1 = clock();
    int t = LCS(a,b,strlen(a),strlen(b));
   // t1 = clock() - t1;
    //t1 = t1/CLOCKS_PER_SEC;
    int i = strlen(a),j = strlen(b);
    char c[t+1];
    c[t] = '\0';
    while(i>0 && j>0){
      if(a[i-1]==b[j-1]){
        c[t-1] = a[i-1];
        i--;
        j--;
        t--;
      }
      else if(lcs[i-1][j]>lcs[i][j-1])
        i--;
      else
        j--;
    }
    printf("\nThe Longest Common Subsequence is %s",c);
}