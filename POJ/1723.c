#include<stdio.h>
#include<stdlib.h>
int cmp ( const void *a , const void *b)
{
    return *(int *)a - *(int *)b;
}


int main(){
    int i,n,x[10000],y[10000],y_step=0,x_step=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    qsort(x,n,sizeof(int),cmp);
    qsort(y,n,sizeof(int),cmp);
    for(i=0;i<n;i++){
        y_step+=abs(y[i]-y[n/2]);
        x[i]=x[i]-i;
    }
    qsort(x,n,sizeof(int),cmp);
    for(i=0;i<n;i++){
        x_step+=abs(x[i]-x[n/2]);
    }
    printf("%d",x_step+y_step);
    return 0;
}