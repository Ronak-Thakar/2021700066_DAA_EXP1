#include<stdio.h>
#define row 2
#define col 2
void mat_in(int a[row][col]){
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
           printf("\nEnter elemnet %d%d: ",i,j);
           scanf("%d",&a[i][j]);
        }
     }
}

void mat_print(int a[row][col]){
    printf("\n|\t\t\t|\n");
     for(int i=0;i<row;i++){
        printf("|");
        printf("\t");
        for(int j=0;j<col;j++){
           printf("%d\t",a[i][j]);
        }
        printf("|");
        printf("\n|\t\t\t|\n");
     }
}

int main(){
    int a[row][col],b[row][col],m1,m2,m3,m4,m5,m6,m7,c[row][col];
    printf("\nEnter matrix A values: ");
    mat_in(a);
    printf("\nEnter matrix B values: ");
    mat_in(b);
    //Strassen's matrix multiplication;
    m1 = (a[0][0] + a[1][1])*(b[0][0] + b[1][1]);
    m2 = (a[1][0] + a[1][1])*b[0][0];
    m3 = a[0][0]*(b[0][1] - b[1][1]);
    m4 = a[1][1]*(-b[0][0] + b[1][0]);
    m5 = (a[0][0] + a[0][1])*b[1][1];
    m6 = (-a[0][0] + a[1][0])*(b[0][0] + b[0][1]);
    m7 = (a[0][1] - a[1][1])*(b[1][0] + b[1][1]);

    c[0][0] = m1 + m4 - m5 + m7;
    c[1][0] = m2 + m4;
    c[0][1] = m3 + m5;
    c[1][1] = m1 + m3 - m2 + m6;
    
    printf("\n\nMatrix A::\n");
    mat_print(a);
    printf("\n\nMatrix B::\n");
    mat_print(b);
    printf("\n\nThe answer is:\n");
    mat_print(c);
}