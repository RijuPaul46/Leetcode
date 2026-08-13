class Node{
    public:
    int pre;
    int suff;
    int mxlen;
    Node(int a,int b,int c){
        pre=a;
        suff=b;
        mxlen=c;
    }
};

class Solution {
public:
    vector<Node*> segTree;
    Node* buildTree(int idx,int l,int r,string &s){
        if(l==r){
            return segTree[idx]=new Node(1,1,1);
        }
        int left=2*idx+1;
        int right=2*idx+2;
        int mid=l+(r-l)/2;
        Node* lft=buildTree(left,l,mid,s);
        Node* rt=buildTree(right,mid+1,r,s);
        int mx=max(lft->mxlen,rt->mxlen);
        int npre=lft->pre;
        int nsuff=rt->suff;
        if(s[mid]==s[mid+1]){
            mx=max(mx,lft->suff+rt->pre);
            if(lft->pre==mid-l+1){
                // left pre was whole
                npre+=rt->pre;
            }
            if(rt->suff==r-mid){
                nsuff+=lft->suff;
            }
        }
       
        segTree[idx]=new Node(npre,nsuff,mx);
        
        return segTree[idx];
    }
    void update(char c,int i,int l,int r,int idx,string &s){
        if(l==r){
            s[i]=c;
            return ;
        }
        int left=2*idx+1;
        int right=2*idx+2;
        int mid=l+(r-l)/2;
        if(i<=mid){
        update(c,i,l,mid,idx*2+1,s);
        }
        else update(c,i,mid+1,r,idx*2+2,s);

        Node* lft=segTree[left];
        Node* rt=segTree[right];
        int mx=max(lft->mxlen,rt->mxlen);
        int npre=lft->pre;
        int nsuff=rt->suff;
        if(s[mid]==s[mid+1]){
            mx=max(mx,lft->suff+rt->pre);
            if(lft->pre==mid-l+1){
                // left pre was whole
                npre+=rt->pre;
            }
            if(rt->suff==r-mid){
                nsuff+=lft->suff;
            }
        }
        auto nd=segTree[idx];
        nd->pre=npre;
        nd->suff=nsuff;
        nd->mxlen=mx;
        segTree[idx]=nd;
        return ;
    }
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int n=s.size();
        segTree.resize(4*n);
        buildTree(0,0,n-1,s);
        int k=qc.size();
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            char c=qc[i];
            int id=qi[i];
            update(c,id,0,n-1,0,s);
            ans[i]=segTree[0]->mxlen;
        }
        return ans;
    }
};