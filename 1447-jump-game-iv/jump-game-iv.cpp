class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool>visited(n,false);
        unordered_map<int,bool> vis;
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int lvl=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            int idx=q.front();
            if(idx==n-1)return lvl;
            q.pop();
            if(idx-1>=0 && !visited[idx-1]){
                visited[idx-1]=true;
                q.push(idx-1);
            }
            if(idx+1<n && !visited[idx+1]){
                visited[idx+1]=true;
                q.push(idx+1);
            }
            if(!vis[arr[idx]]){
                vis[arr[idx]]=true;
            for(auto &x:mp[arr[idx]]){
                if(x!=idx && !visited[x]){
                    visited[x]=true;
                    q.push(x);
                }
            }
            }
            }
            lvl++;


        }
        return -1;
    }
};