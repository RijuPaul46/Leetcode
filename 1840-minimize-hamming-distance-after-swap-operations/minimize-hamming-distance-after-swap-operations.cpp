class Solution {
public:
    void dfs(int ind, vector<vector<int>>&adj, vector<bool>& vis, unordered_map<int,int>&mpp1, unordered_map<int,int>&mpp2, vector<int>&source, vector<int>&target){
        vis[ind] = true;
        stack<int>s;
        s.push(ind);
        mpp1[source[ind]]++;
        mpp2[target[ind]]++;

        while(!s.empty()){
            int i = s.top();
            s.pop();

            for(auto it:adj[i]){
                if(!vis[it]){
                    s.push(it);
                    vis[it] = true;
                    mpp1[source[it]]++;
                    mpp2[target[it]]++;
                }
            }
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& a) {
        int n = source.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<a.size();i++){
            adj[a[i][0]].push_back(a[i][1]);
            adj[a[i][1]].push_back(a[i][0]);
        }

        vector<bool>vis(n,false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                unordered_map<int,int>mpp1,mpp2;
                dfs(i,adj,vis,mpp1,mpp2,source,target);

                for(auto it:mpp2){
                    int num = it.first;
                    int freq = it.second;

                    if(mpp1[num]<freq){
                        ans += (freq-mpp1[num]);
                    }
                }
            }
        }
        return ans;
    }
};