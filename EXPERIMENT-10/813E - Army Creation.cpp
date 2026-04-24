#include<bits/stdc++.h>
using namespace std;
const int N=1e5,B=200;
vector<int>p[N];
int i,j,n,m,l,r,t,ans,g[N],a[N],f[500][N];
int main()
{
for(scanf("%d%d",&n,&m);i<n;p[--a[i]].push_back(i),++i)scanf("%d",a+i);
for(i=0;i*B<n;++i,memset(g,t=0,4*N))
for(j=i*B;j<n;++j)f[i][j]=t+=g[a[j]]++<m;
for(scanf("%d",&t);t--;printf("%d\n",ans))
{
scanf("%d%d",&l,&r);
if((l=(l+ans)%n)>(r=(r+ans)%n))swap(l,r);
if(ans=0,l/B==r/B)
{
for(j=l;j<=r;++j)ans+=g[a[j]]++<m;
for(j=l;j<=r;g[a[j++]]=0);
}else 
{
for(ans=f[i=l/B+1][r],j=i*B;j-->l;ans+=g[a[j]]++<m)
if(!g[a[j]])g[a[j]]=upper_bound(p[a[j]].begin(),p[a[j]].end(),r)-lower_bound(p[a[j]].begin(),p[a[j]].end(),i*B);
for(j=i*B;j-->l;g[a[j]]=0);
}
}
}