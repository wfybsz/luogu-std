const int NR = 1e5;
const int MR = 1e5;
struct edge{int to,next;}g[2 * MR];
int size,head[NR];

void add(int u,int v){
	g[++size] = (edge){v,head[u]};
	head[u] = size;
}
