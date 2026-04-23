class Node{
    public:
    string str;
    unordered_map<Node*,double> mp;
    Node(string s){
        str=s;
    }
};
class Solution {
public:
    double dfs(Node* src,Node* target,double product,unordered_set<Node*> &visited){
        if(src==target)return product;
        for(auto const &[node,val]:src->mp){
            if(visited.count(node)==0){
                double ans=-1;
                visited.insert(node);
                ans=dfs(node,target,product*val,visited);
                if(ans!=-1)return ans;
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,Node*> mp;
        int n=values.size();
        for(int i=0;i<n;i++){
            double val=values[i];
            string a=equations[i][0];
            string b=equations[i][1];
            if(!mp.count(a)){
                Node* node=new Node(a);
                mp[a]=node;
            }
            if(!mp.count(b)){
                Node* node=new Node(b);
                mp[b]=node;
            }
            mp[a]->mp[mp[b]]=val;
            mp[b]->mp[mp[a]]=1/val;
        }
        int q=queries.size();
        vector<double> ans(q,-1);
        for(int i=0;i<q;i++){
            string c=queries[i][0];
            string d=queries[i][1];
            if(mp.count(c) && mp.count(d) ){
                unordered_set<Node*> visited;
                ans[i]=dfs(mp[c],mp[d],1,visited);
            }
        }
        return ans;
    }
};