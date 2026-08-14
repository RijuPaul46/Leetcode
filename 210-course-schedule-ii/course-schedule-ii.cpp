class Solution {
public:
    // void dfs(int node,vector<vector<int>> &adj,vector<int>&st,vector<bool> &visited,vector<int>&degree){
    //     visited[node]=true;
    //     for(auto &ch:adj[node]){
    //         degree[ch]--;
    //         if(!visited[ch] && degree[ch]==0){
    //             dfs(ch,adj,st,visited,degree);
    //         }
    //     }
    //     st.push_back(node);

    // }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int>degree(n);
        // vector<bool> visited(n,false);
        for(auto &ed:pre){
            int u=ed[0];
            int v=ed[1];
            adj[v].push_back(u);
            degree[u]++;
        }
        vector<int> st;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==0 ){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            st.push_back(node);
            q.pop();
            for(auto &ch:adj[node]){
                degree[ch]--;
                if(degree[ch]==0)q.push(ch);
            }
        }
        if(st.size()!=n)return {};
        // reverse(st.begin(),st.end());
        return st;

    }
};