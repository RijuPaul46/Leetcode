class Solution {
public:
    //simple xor with euler tour 
    // segtree will give range xor ..... in a range find xor
    // palindrome if xor is 0 even length .... and for odd lenth only one bit survive ... 26 char poss a-0th bit , b-1st bit , c-2nd bit 
    vector<int>tin,tout,euler;
    vector<vector<int>> adj,up;
    int max_log=17;
    string str;
    vector<int>segTree;
    bool isAnc(int a,int b){
        if(tin[a]<=tin[b] && tout[b]<=tout[a])return 1;
        return 0;
    }
    int lca(int a,int b){
        if(isAnc(a,b))return a;
        if(isAnc(b,a))return b;
        for(int j=max_log-1;j>=0;j--){
            if(!isAnc(up[a][j],b))a=up[a][j];
        }
        return up[a][0];
    }
    void buildTree(int i,int l,int r){
        int mid=l+(r-l)/2;
        if(l==r){
           segTree[i]=euler[l];
            return;
        }
        int left=2*i+1;
        int right=2*i+2;
        buildTree(left,l,mid);
        buildTree(right,mid+1,r);
        segTree[i]=segTree[left]^segTree[right];
        return;
    }
    void update(int tgt,int val,int i,int l,int r){
        if(l==r && l==tgt){
            euler[tgt]=val;
            segTree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        int left=2*i+1;
        int right=2*i+2;
        if(tgt<=mid){
            update(tgt,val,left,l,mid);
        }
        else update(tgt,val,right,mid+1,r);
        segTree[i]=segTree[left]^segTree[right];
        return;

    }
    int getxor(int from,int to,int i,int l,int r){
        if(r<from || l>to )return 0;
        if(l>=from && r<=to)return segTree[i];
        int mid=l+(r-l)/2;
        int left=2*i+1;
        int right=2*i+2;
        int lft=getxor(from,to,left,l,mid);
        int rt=getxor(from,to,right,mid+1,r);
        return lft^rt;
    }
    void euler_tour(int node,int par,int &time){
        up[node][0]=par;
        tin[node]=time++;
        int idx=str[node]-'a';
        euler.push_back((1<<idx));
        for(auto &ch:adj[node]){
            euler_tour(ch,node,time);
        }
        euler.push_back((1<<idx));
        tout[node]=time++;

    }
    bool isPalindrome(int n){
        if(n==0)return true;
        if( (n & (n-1)) ==0)return true;
        return false;
    }
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.resize(n);
        up.resize(n,vector<int>(max_log+1));
        str=s;
        vector<int>indegree(n);
        for(auto &ed:edges){
            int u=ed[0];
            int v=ed[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        // i need for each node i will keep track of tin index 
        tin.resize(n);
        tout.resize(n);
        int root=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                root=i;
                break;
            }
        }
        int time=0;
        euler_tour(root,root,time);
        for(int j=1;j<max_log;j++){
            for(int i=0;i<n;i++){
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }
        int len=euler.size();
        segTree.resize(4*len);
        buildTree(0,0,len-1);
        vector<bool>ans;
        for (auto &qr:queries){
            stringstream ss(qr);
            vector<string>words;
            string word;
            while(ss>>word){
                words.push_back(word);
            }
            if(words[0]=="query"){
                int u=stoi(words[1]);
                int v=stoi(words[2]);
                int uin=tin[u],vin=tin[v];
                int uout=tout[u],vout=tout[v];
                if(uout<vin){
                    int from=uout;
                    int to=vin;
                    int val=getxor(from,to,0,0,len-1);
                    int lc=lca(u,v);
                    int idx=1<<(str[lc]-'a');
                    val^=idx;
                    if(isPalindrome(val))ans.push_back(true);
                    else ans.push_back(false);
                }
                if(vout<uin){
                    int from=vout,to=uin;
                    int val=getxor(from,to,0,0,len-1);
                    int lc=lca(u,v);
                    int idx=1<<(str[lc]-'a');
                    val^=idx;
                    if(isPalindrome(val))ans.push_back(true);
                    else ans.push_back(false);
                }
                else if(vin>=uin && vin<=uout){
                    int from=uin,to=vin;
                    int val=getxor(from,to,0,0,len-1);
                    if(isPalindrome(val))ans.push_back(true);
                    else ans.push_back(false);
                }
                else if(uin>=vin && uin<=vout){
                    int from=vin,to=uin;
                    int val=getxor(from,to,0,0,len-1);
                    if(isPalindrome(val))ans.push_back(true);
                    else ans.push_back(false);
                }
                
            }
            else{
                int tgt=stoi(words[1]);
                char ch=words[2][0];
                str[tgt]=ch;
                int val=1<<(ch-'a');
                int in=tin[tgt],out=tout[tgt];
                update(in,val,0,0,len-1);
                update(out,val,0,0,len-1);
            }
        }
        return ans;


    }
};