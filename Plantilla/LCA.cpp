int dmax = 0, st[N][20], dep[N];
int n,m;
vector<int> adj[N];
void dfs(int u,int p,int h){
	st[u][0] = p;
	dep[u] = h;
	dmax = max(dmax,h);
	for(auto v : adj[u]){
		if(v == p) continue;
		dfs(v,u,h+1);
	}
}
void buildlca(){
	for(int j = 1 ; (1<<j) <= dmax ; j++){
		for(int i = 0 ; i < n  ; i++){
			st[i][j] = st[st[i][j-1]][j-1];
		}
	}
}
int getlca(int u,int v){
	if(u==v) return u;
	if(dep[u] < dep[v]) swap(u,v);
	int bit = 31 - __builtin_clz(dep[u]);
	for(int i = bit ; i >= 0 ; i--){
		if(dep[st[u][i]] >= dep[v]) u = st[u][i];
	}
	bit = 31 - __builtin_clz(dep[u]);
	for(int i = bit ; i >= 0 ; i--){
		if(st[u][i] != st[v][i]) u = st[u][i], v = st[v][i];
	}
	return st[u][0];
}

int main(){
	dfs(0,0,0);
}
