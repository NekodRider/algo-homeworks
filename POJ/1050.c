#include <stdio.h>
int a[100][100];
int get_max_sub (int n,int a[])
{
    int s[100], max, i;
    max = s[0] = a[0];
    for (i=1; i<n; i++)
    {
        if (s[i-1] > 0)
            s[i] = s[i-1] + a[i];
        else
            s[i] = a[i];
        if (s[i] > max)
            max = s[i];
    }
    return max;
}
 
int main()
{
    int n, i, j, k, t[100], max= -128, m;
    scanf("%d", &n);
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d", &a[i][j]);
    for (i=0; i<n; i++)
    {
        m = get_max_sub(n,a[i]);
        if (m > max) 
            max = m;
        for (j=i+1; j<n; j++)
        {
            for (k=0; k<n; k++)
            {
                a[i][k] += a[j][k];
            }
            m = get_max_sub(n,a[i]);
            if (m > max) 
                max = m;
        }
    }
    printf("%d", max);
}