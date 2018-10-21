#include <iostream>
#include <cmath>
#include <algorithm>		   
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN=200050;
const double INF=1e40;

struct point{
	double x,y;
	bool flag;
}px[MAXN],py[MAXN],p1[MAXN],p2[MAXN];

struct spair{
	point a,b;
	double dis;
};							   

bool cmpx(const point &x,const point &y){
	if (x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}

bool cmpy(const point &x,const point &y){
	if (x.y==y.y) return x.x<y.x;
	return x.y<y.y;
}

bool cmpequal(const point &x,const point &y){
	return x.x==y.x && x.y==y.y && x.flag==y.flag;
}

double Distance(point &a,point &b){
	return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

spair solve(int a,int  b){
	spair s;
	s.dis=INF,s.a=s.b=px[a];
	for (int i=a;i<b;i++){
		for (int j=i+1;j<b;j++){
			double dis;
			if (px[i].flag!=px[j].flag &&  (dis=Distance(px[i],px[j]))<s.dis){
				s.dis=dis;
				s.a=px[i],s.b=px[j];
			}		   
		}
	}
	return s;
}

spair solve(int a,int b,int c,int d){
	if (b-a<=3) return solve(a,b);
	else{
		int mid=(a+b)/2+1,cnt=mid-a;
		double x0=px[mid-1].x;
		int i,j,k,cnt1=0,cnt2=0;
		for (i=c;i<d && cnt1<cnt;i++){
			if (py[i].x<=x0) p1[cnt1++]=py[i];
			else p2[cnt2++]=py[i];
		}
		for (;i<d;i++)p2[cnt2++]=py[i];
		for (i=0;i<cnt1;i++)py[c+i]=p1[i];
		for (i=0;i<cnt2;i++)py[c+cnt1+i]=p2[i];
		spair s1=solve(a,mid,c,c+cnt1);
		spair s2=solve(mid,b,c+cnt1,d);
		spair s;
		if (s1.dis<=s2.dis) s=s1;else s=s2;
		memcpy(p1,py+c,cnt1*sizeof(point));
		memcpy(p2,py+c+cnt1,cnt2*sizeof(point));
	      merge(p1,p1+cnt1,p2,p2+cnt2,py+c,cmpy);
		for (i=c,j=0;i<d;i++){
			if (fabs(py[i].x-x0)<=s.dis) p1[j++]=py[i];
		}
		for (i=0;i<j;i++){
			for (k=1;k<=7 && k+i<j;k++){
				double dis;
				if (p1[i].flag!=p1[i+k].flag && (dis=Distance(p1[i],p1[i+k]))<s.dis){
					s.dis=dis;
					s.a=p1[i];
					s.b=p1[i+k];
				}
			}
		}
		return s;
	} 
}

int main()
{
	int n,i,m;
    scanf("%d",&m);
	while (m--)   {
		scanf("%d",&n);
		for (i=0;i<n;i++) {
			scanf("%lf %lf",&px[i].x,&px[i].y);
			px[i].flag=0;
		}
		for (i=n;i<2*n;i++) {
			scanf("%lf %lf",&px[i].x,&px[i].y);
			px[i].flag=1;
		}
		sort(px,px+2*n,cmpx);
		n=unique(px,px+2*n,cmpequal)-px;
		memcpy(py,px,sizeof(py));
		sort(py,py+n,cmpy);
		spair ans=solve(0,n,0,n);
		printf("%.3f\n",ans.dis);
	}
	return 0;
}