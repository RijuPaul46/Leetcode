#define ll long long
class Solution {
public:
    int visited[50001][4];
    pair<ll,vector<int>> dp[50001][4];
    bool isSmaller(vector<int>a,vector<int>b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        return a<b;
    }
    pair<ll,vector<int>> solve(int i,vector<vector<int>> &arr,int cnt){
        int n=arr.size();
        if(i==n || cnt==4)return {0ll,{}};
        // skip this
        if(visited[i][cnt])return dp[i][cnt];
        auto &ref=dp[i][cnt];
        visited[i][cnt]=true;
        auto [skp_sm,skp_str]=solve(i+1,arr,cnt);
        int x=arr[i][1];
        auto it=upper_bound(arr.begin(),arr.end(),x,
        [](int x,const vector<int>&a){
            return x<a[0];
        })
        -arr.begin();

        auto [tk_sm,tk_str]=solve(it,arr,cnt+1);
        tk_sm+=arr[i][2];
        tk_str.push_back(arr[i][3]);
        if(tk_sm>skp_sm)return ref={tk_sm,tk_str};
        if(tk_sm<skp_sm)return ref={skp_sm,skp_str};
        auto smaller=tk_str;
        if(isSmaller(skp_str,tk_str))smaller=skp_str;
        return ref={tk_sm,smaller};
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        vector<vector<int>> arr;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            auto a=intervals[i];
            a.push_back(i);
            arr.push_back(a);
        }
        sort(arr.begin(),arr.end());
        auto [sm,idx]=solve(0,arr,0);
        sort(idx.begin(),idx.end());
        return idx;
    }
};