/*LeastSquares*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void jacobian(int N,double A[N+1][N+2]){
    int i,j,n=0;
    float x[N],b[N],t[N],er,X;
    X=1.0;
    for(i=0;i<N+1;i++) {
    b[i]=A[i][N+1];
    x[i]=X;
    }
    do {
    er=0.0;
    for(i=0;i<N+1;i++) {
         t[i]=b[i];
        for(j=0;j<N+1;j++)
            if(i!=j) t[i]-=A[i][j]*x[j];
            t[i]/=A[i][i];

    }
    n++;
    for(i=0;i<N+1;i++){
       er+=fabs(t[i]-x[i]);
       x[i]=t[i];
    }
    }
    while(er>1.0e-4);
    printf("n=%d\n",n);
    printf("y=%8.6f",x[0]);
    for(i=1;i<N+1;i++) printf("+(%8.6f)x^%d",x[i],i);
}
 
void saisyou2zyou(const char *filepath,int data,int N){
    double x[data],y[data],F[N+1][N+2];
    int i,j,n;
    FILE fp;
    if( (fp=fopen(filepath,"r"))==NULL ) {
        printf("cannot open file.\n");
        exit(0);
    }
    for(i=0;i<data;i++){
        fscanf(fp,"%lf",&x[i]);
        fscanf(fp,"%lf",&y[i]);
    }

    fclose(fp);

    for(i=0;i<(N+1);i++){
        for(j=0;j<(N+1);j++)
            for(n=0;n<data;n++)
                F[i][j]+=pow(x[n],j+i);

        for(n=0;n<data;n++)
            F[i][N+1]+=y[n]pow(x[n],i);
    }

    for(i=0;i<N+1;i++){
        for(j=0;j<N+2;j++)
            printf(" %7.5lf",F[i][j]);
        printf("\n");
    }
    jacobian(N,F);
}
int main(){

    saisyou2zyou("text2.txt",4,2);//データ数は４、１次方程式
}