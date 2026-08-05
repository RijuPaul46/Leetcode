class Solution {
public:
    void bfs(int node,vector<vector<int>> &from,unordered_set<int> &sus){
        sus.insert(node);
        for(auto &ch:from[node]){
            if(!sus.count(ch)){
                bfs(ch,from,sus);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> from(n);
        vector<vector<int>> to(n);
        for(auto &inv:invocations){
            int u=inv[0];
            int v=inv[1];
            from[u].push_back(v);
            to[v].push_back(u);
        }
        unordered_set<int> sus;
        bool remove=true;
        bfs(k,from,sus);
        for(auto &aff:sus){
            for(auto & x:to[aff]){
                if(!sus.count(x)){
                    remove=false;
                    break;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(sus.count(i) && remove){

            }
            else ans.push_back(i);
        }
        return ans;

    }
};