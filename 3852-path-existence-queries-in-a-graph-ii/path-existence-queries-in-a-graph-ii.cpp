class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i]={nums[i],i};
        }
        sort(arr.begin(),arr.end());
        vector<int>ndToIdx(n);
        for(int i=0;i<n;i++){
            ndToIdx[arr[i].second]=i;
        }
        int max_log=log2(n)+1;
        vector<vector<int>> jump(n,vector<int>(max_log+1));
        for(int i=0;i<n;i++){
            int tgt=arr[i].first+maxDiff;
            auto it=upper_bound(arr.begin(),arr.end(),tgt,
            [](int tgt,const auto &b){
                return tgt<b.first;
            });
            if(it!=arr.begin())it--;
            int idx=it-arr.begin();
            jump[i][0]=idx;
        }
        for(int j=1;j<=max_log;j++){
            for(int i=0;i<n;i++){
                int x=jump[i][j-1];
                jump[i][j]=jump[x][j-1];  
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=max_log;j++){
        //         cout<<jump[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int>ans;
        for(auto &q:queries){
            int u=q[0];
            int v=q[1];
            int a=ndToIdx[u];
            int b=ndToIdx[v];
            if(b<a)swap(a,b);
            // cout<<"a="<<a<<" b= "<<b<<endl;
            int jm=0;
            //u has lower value always
            if(a==b){ans.push_back(0);continue;}
            if(jump[a][max_log]<b){ans.push_back(-1);continue;}
            for(int i=max_log;i>=0;i--){
                if(jump[a][i]<b){
                    // cout<<"After jump a="<<a<<" ";
                    a=jump[a][i];
                    jm+=(1<<i);
                }
            }
            // cout<<endl;

            ans.push_back(jm+1);
        }
        return ans;

    }
};