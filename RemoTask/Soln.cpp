#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int p=1000000007,B=23333,iB=203960058;
int T,n,x,y,pw[1005],ipw[1005],siz[1005];
int h[2005],rev[2005],now,Rev,fg,D,ax[1005],ay[1005];
int head[1005],to[2005],nex[2005],cnt;
int rt,ls[160005],rs[160005],sum[160005],num[160005],tot;
map<int,int> mp,Mp;
map<int,vector<int> > s[1005];
inline void adde(int f,int t){
	to[++cnt]=t;
	nex[cnt]=head[f];
	head[f]=cnt;
}
void modi(int &u,int l,int r,int x,int y){
	if(!u)u=++tot,ls[u]=rs[u]=sum[u]=num[u]=0;
	if(l==r){
		if(y>0)sum[u]=(ll)(sum[u]+x)*pw[y]%p;
		else sum[u]=((ll)sum[u]*ipw[-y]%p-x+p)%p;
		return num[u]+=y,void();
	}
	int mid=(l+r)>>1;
	if(x<=mid)modi(ls[u],l,mid,x,y);
	else modi(rs[u],mid+1,r,x,y);
	sum[u]=(sum[ls[u]]+(ll)sum[rs[u]]*pw[num[ls[u]]])%p;
	num[u]=num[ls[u]]+num[rs[u]];
}
void dfs(int u,int pre,int j){
	siz[u]=1;
	for(int i=head[u],v;i;i=nex[i]){
		v=to[i];
		if(v==pre)continue;
		dfs(v,u,i);
		siz[u]+=siz[v];
	}
	mp.clear(),now=Rev=rt=tot=0;
	for(int i=head[u],v;i;i=nex[i]){
		v=to[i];
		if(v==pre)continue;
		modi(rt,0,p-1,h[i],siz[v]);
		now-=mp[h[i]],Rev^=rev[i];
		mp[h[i]]^=1,now+=mp[h[i]];
	}
	h[j]=(sum[rt]+siz[u])%p;
	rev[j]=(!now || (now==1 && Rev));
}
void dfs2(int u,int pre){
	mp.clear(),now=Rev=rt=tot=0;
	for(int i=head[u],v;i;i=nex[i]){
		v=to[i];
		modi(rt,0,p-1,h[i],siz[v]);
		now-=mp[h[i]],Rev^=rev[i];
		mp[h[i]]^=1,now+=mp[h[i]];
	}
	for(int i=head[u],v;i;i=nex[i]){
		v=to[i];
		if(v==pre)continue;
		modi(rt,0,p-1,h[i],-siz[v]);
		now-=mp[h[i]],Rev^=rev[i];
		mp[h[i]]^=1,now+=mp[h[i]];
		h[i^1]=(sum[rt]+n-siz[v])%p;
		rev[i^1]=(!now || (now==1 && Rev));
		modi(rt,0,p-1,h[i],siz[v]);
		now-=mp[h[i]],Rev^=rev[i];
		mp[h[i]]^=1,now+=mp[h[i]];
	}
	int sz=siz[u];
	for(int i=head[u],v;i;i=nex[i]){
		v=to[i];
		if(v==pre)continue;
		siz[u]=n-siz[v];
		dfs2(v,u);
	}
	siz[u]=sz;
}
int solve(int u,int v,int x,int L,int R,int I,int J){
	D=max(D,x);
	ax[u]=ax[v]=x,ay[u]=L,ay[v]=R;
	s[u].clear(),s[v].clear();
	for(int i=head[u];i;i=nex[i])
		if(i^I)s[u][h[i]].eb(i);
	for(int i=head[v];i;i=nex[i])
		if(i^J)s[v][h[i]].eb(i);
	for(auto t:s[u]){
		int H=t.fi;
		for(int i=0;i<(int)s[u][H].size();++i){
			int U=s[u][H][i],V=s[v][H][i];
			R=solve(to[U],to[V],x+1,L-1,R+1,U^1,V^1);
			L=-R;
		}
	}
	return R;
}
void Solve(int u,int I){
	ax[u]=++D,ay[u]=0;
	int d=D;
	Mp.clear();
	for(int i=head[u],j,R=0;i;i=nex[i]){
		if(i==I)continue;
		if(Mp.count(h[i])){
			j=Mp[h[i]],Mp.erase(h[i]);
			R=solve(to[i],to[j],d+1,-R-1,R+1,i^1,j^1);
		}
		else Mp[h[i]]=i;
	}
	if(!Mp.empty()){
		int i=Mp.begin()->se,v=to[i];
		Solve(v,i^1);
	}
}
inline void print(){
	puts("YES");
	for(int i=1;i<=n;++i)
		printf("%d %d\n",ax[i],ay[i]);
	puts("0 1 0");
}
int main(){
	scanf("%d",&T),pw[0]=ipw[0]=1;
	for(int i=1;i<=1000;++i){
		pw[i]=(ll)pw[i-1]*B%p;
		ipw[i]=(ll)ipw[i-1]*iB%p;
	}
	while(T--){
		scanf("%d",&n),cnt=1;
		for(int i=1;i<=n;++i)head[i]=0;
		for(int i=1;i<n;++i){
			scanf("%d%d",&x,&y);
			adde(x,y),adde(y,x);
		}
		dfs(1,0,0),dfs2(1,0);
		cnt=fg=0,D=-1;
		for(int i=1,x,y;i<n;++i){
			x=i<<1,y=i<<1|1;
			if(h[x]==h[y]){
				solve(to[x],to[y],D+1,-1,1,x^1,y^1),fg=1;
				break;
			}
		}
		if(fg){print();continue;}
		for(int u=1;u<=n;++u){
			mp.clear(),now=Rev=0;
			for(int i=head[u];i;i=nex[i]){
				now-=mp[h[i]],Rev^=rev[i];
				mp[h[i]]^=1,now+=mp[h[i]];
			}
			if(!now || (now==1 && Rev)){
				Solve(u,0),fg=1;
				break;
			}
		}
		if(fg)print();
		else puts("NO");
	}
	return 0;
}