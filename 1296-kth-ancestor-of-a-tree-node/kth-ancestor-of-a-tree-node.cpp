class TreeAncestor {
public:
    vector<vector<int>> anc;
    int total;
    TreeAncestor(int n, vector<int>& parent) {
        int mxj=31-__builtin_clz(n)+1;
        anc=vector(n,vector<int>(mxj+1,-1));
        total=n;
        for(int i=0;i<n;i++){
            anc[i][0]=parent[i];
        }
        for(int j=1;j<=mxj;j++){
            for(int i=0;i<n;i++){
                if(anc[i][j-1]!=-1)
                anc[i][j]=anc[anc[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(node==-1)return -1; 
        if(k==0)return node;
        int msb=31-__builtin_clz(k);
        return getKthAncestor(anc[node][msb],k-(1<<msb));
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */