#include<cstdio>
#include<iostream>

class Matrix
{
    public:
        int n,mod,m[33][33];
        Matrix()
        {
            int i,j;
            this->n=0;
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++)
                    this->m[i][j]=0;
        }
        Matrix(int t,int mod)
        {
            int i,j;
            this->n=t;
            this->mod=mod;
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++)
                    scanf("%d",&this->m[i][j]);
        }
        Matrix(int t,int mod,int flag)
        {
            int i,j;
            this->n=t;
            this->mod=mod;
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++)
                    this->m[i][j]=0;
        }
        void init(Matrix a){
            int i,j;
            this->n=a.n;
            this->mod=a.mod;
            for (i=1;i<=a.n;i++)
                for (j=1;j<=a.n;j++)
                    this->m[i][j]=a.m[i][j];
        }
        void clear()
        {
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    this->m[i][j]=0;     
        }
        void add(const Matrix &b)
        {
            int i,j;
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++)
                    m[i][j]=(m[i][j]+b.m[i][j])%this->mod;     
        }
        void print()
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<n;j++)
                    printf("%d ",m[i][j]);
                printf("%d\n",m[i][n]);    
            }     
        }
        void mul(Matrix b,Matrix &c)
        {
            int i,j,k;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    for(k=1;k<=n;k++){
                        // printf("%d %d %d %d %d %d %d",i,j,k,c.m[i][j],this->m[i][k],b.m[k][j],this->mod);
                        c.m[i][j]=(c.m[i][j]+(this->m[i][k])*(b.m[k][j]))%(this->mod);
                    }
        }
};

int main()
{
    int i,n,k,mod;
    scanf("%d%d%d",&n,&k,&mod);
    Matrix a(n,mod),b,f,c(n,mod,1);
    b.init(a);
    f.init(a);
    for (i=0;(1<<i)<=k;i++);
    for (i-=2;i>=0;i--)
    {
        b.mul(f,c);
        f.add(c);
        c.clear();
        b.mul(b,c);
        b=c;
        if (((1<<i)&k)>0){
            b.mul(a,c);
            b=c;
            f.add(b); 
        }
    }
    f.print();
    return 0;   
}