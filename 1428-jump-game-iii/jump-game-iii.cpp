class Solution {
public:
    bool dfs(int i,vector<int>& arr,vector<bool>& visited){
        int n=arr.size();
        visited[i]=true;
        if(arr[i]==0)return true;
        bool left=false;
        bool right=false;
        if(i+arr[i]<n && !visited[i+arr[i]])right=dfs(i+arr[i],arr,visited);
        if(i-arr[i]>=0 && !visited[i-arr[i]])left=dfs(i-arr[i],arr,visited);
        return left||right;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>visited(n,false);
        return dfs(start,arr,visited);
    }
};