#define ll long long
class Node{
    public:
    ll val;
    ll l,r;
    Node(ll x,ll y,ll z){val=x;l=y;r=z;}
};
class Solution {
public:
    vector<pair<int,int>> segTree;
    void buildTree(int i,vector<int>& nums,int l,int r){
        if(l==r){
            segTree[i]={nums[l],nums[l]};
            return;
        }
        int left=2*i+1;
        int right=2*i+2;
        int mid=l+(r-l)/2;
        buildTree(left,nums,l,mid);
        buildTree(right,nums,mid+1,r);
        auto & le=segTree[left];
        auto & ri=segTree[right];
        segTree[i]={min(le.first,ri.first),max(le.second,ri.second)};
        return;
    }
    pair<int,int> find(int from,int to,int l,int r,int idx){
        if(from<=l && r<=to)return segTree[idx];
        if(r<from || l> to)return {INT_MAX,INT_MIN};
        int mid=l+(r-l)/2;
        auto  left=find(from,to,l,mid,2*idx+1);
        auto  right=find(from,to,mid+1,r,2*idx+2);
        return {min(left.first,right.first),max(left.second,right.second)};
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        segTree.resize(4*n);
        buildTree(0,nums,0,n-1);
        auto com=[&](auto &n1,auto &n2){
            return (n1->val)<(n2->val);
        };
        priority_queue<
            Node*,
            vector<Node*>,
            decltype(com)
        > pq(com);
        ll sum=0;
        unordered_set<ll> visited;
        auto fn=find(0,n-1,0,n-1,0);
        pq.push(new Node(fn.second-fn.first,0,n-1));
        visited.insert(n-1);
        while(!pq.empty()){
            auto pr=pq.top();
            k--;
            pq.pop();
            int i=pr->l;
            int j=pr->r;
            sum+=pr->val;
            if(k==0)break;
            ll hash1=(i+1)*n+j;
            ll hash2=(i)*n+(j-1);
            if(i+1<j && !visited.count(hash1)){
                auto f=find(i+1,j,0,n-1,0);
                pq.push(new Node(f.second-f.first,i+1,j));
                visited.insert(hash1);
            }
            if(j-1>i && !visited.count(hash2)){
                auto f=find(i,j-1,0,n-1,0);
                pq.push(new Node(f.second-f.first,i,j-1));
                visited.insert(hash2);
                }
        }
        return sum;
    }
};