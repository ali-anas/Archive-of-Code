#include <bits/stdc++.h>
using namespace std;
#define maxn 100010

char Ans[][15] = {"none", "any", "at least one"};
int head[maxn],low[maxn],dfn[maxn],vis[maxn],fa[maxn],com[maxn];
int n,m,tot,td,num;

struct Edge {
	int source;
	int dest;
	int weight;
	int id;
	int ans;
}e[maxn];

struct edge {
	int dest, pre, id;
}E[maxn*2];

bool compare(Edge val1, Edge val2) {
	return val1.weight < val2.weight;
}

bool comp1(Edge val1, Edge val2){
	return val1.id < val2.id;
}

int getParent(int x) {
	if(x == fa[x]) {
		return fa[x];
	}
	return fa[x] = getParent(fa[x]);
}

void insert(int source, int dest, int id) {
	E[++num].dest = dest;
	E[num].id = id;
	E[num].pre = head[source];
	head[source] = num;
}

void dfs(int u, int parent, int dep) {
	low[u] = dfn[u] = dep;
	vis[u] = 1;
	for(int i = head[u]; i ; i = E[i].pre) {
		int v = E[i].dest;
		if(vis[v] == 1 && E[i].id != parent)
			low[u] = min(low[u], dfn[v]);
		else if(!vis[v]) {
			dfs(v, E[i].id, dep+1);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]) 
				e[E[i].id].ans = 1;
		}
	}
	vis[u] = 2;
}

void printOutputKruskal() {
	sort(e+1, e+m+1, compare);
	
	for(int i = 1; i <= m;) {
		int s = i;
		while(e[s].weight == e[i].weight) {
			i++;
		}
		for(int j = s; j < i; j++) {
			int pSource = getParent(e[j].source);
			int pDest = getParent(e[j].dest);
			if(pSource == pDest)
				continue;
			e[j].ans = 2;
			insert(pSource, pDest, j);
			insert(pDest, pSource, j);
			com[j] = pSource;
		}
		
		for(int j = s; j < i; j++) {
			if(com[j] && !vis[com[j]]) {
				dfs(com[j], 0, 1);
			}
		}
		for(int j = s; j < i; j++) {
			int pSource = getParent(e[j].source);
			int pDest = getParent(e[j].dest);
			if(pSource != pDest) {
				vis[pSource] = vis[pDest] = 0;
				head[pSource] = head[pDest] = 0;
				fa[pSource] = pDest;
			}
		}
		tot = 0;
	}
	sort(e+1, e+m+1, comp1);
	for(int i = 1; i <= m; i++) {
		cout << Ans[e[i].ans] << "\n";
	}
	return;
}


int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		e[i].source = s;
		e[i].dest = d;
		e[i].weight = w;
		e[i].ans = 0;
		e[i].id = i;
	}
	for(int i = 0; i <= n; i++) {
		fa[i] = i;
	}
	
	printOutputKruskal();
	return 0;
}



/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
using namespace std;
char Ans[][15]={"none","any","at least one"};
int head[maxn],low[maxn],dfn[maxn],vis[maxn],fa[maxn],com[maxn];
int n,m,tot,td,num;
struct node{int to,pre,id;}e[100010*2];
struct Node{int from,to,v,id,ans;}E[maxn];
bool cmp(Node x,Node y){return x.v<y.v;}
bool cmp1(Node x,Node y){return x.id<y.id;}
void Insert(int from,int to,int id){
	e[++num].to=to;
	e[num].id=id;
	e[num].pre=head[from];
	head[from]=num;
}
void dfs(int u,int father,int dep){
	low[u]=dfn[u]=dep;vis[u]=1;
	for(int i=head[u];i;i=e[i].pre){
		int v=e[i].to;
		if(vis[v]==1&&e[i].id!=father)low[u]=min(low[u],dfn[v]);
		else if(!vis[v]){
			dfs(v,e[i].id,dep+1);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])E[e[i].id].ans=1;
		}
	}
	vis[u]=2;
}
int find(int x){
	if(x==fa[x])return fa[x];
	return fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&E[i].from,&E[i].to,&E[i].v);
		E[i].ans=0;E[i].id=i;
	}
	sort(E+1,E+m+1,cmp);
	for(int i=1;i<=m;){
		int s=i;
		while(E[s].v==E[i].v)i++;
		for(int j=s;j<i;j++){
			int f1=find(E[j].from);
			int f2=find(E[j].to);
			if(f1==f2)continue;
			E[j].ans=2;
			Insert(f1,f2,j);Insert(f2,f1,j);
			com[j]=f1;
		}
		for(int j=s;j<i;j++)
			if(com[j]&&!vis[com[j]])dfs(com[j],0,1);
		for(int j=s;j<i;j++){
			int f1=find(E[j].from);
			int f2=find(E[j].to);
			if(f1!=f2){
				vis[f1]=vis[f2]=0;
				head[f1]=head[f2]=0;
				fa[f1]=f2;
			}
		}
		tot=0;
	}
	sort(E+1,E+m+1,cmp1);
	for(int i=1;i<=m;i++)printf("%s\n",Ans[E[i].ans]);
	return 0;
}*/
