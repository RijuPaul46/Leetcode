class Solution {
public:
    #define ll long long
    using state=pair<ll,ll>;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        // auto com=[&](state p1,state p2){
        //     if(p1.first>p2.first)return true;
        //     if(p1.first<p2.first)return false;
        //     return p1.second>p2.second;
        // };
        priority_queue<state,vector<state>,greater<state>> mt,occ;
        for(int i=0;i<n;i++){
            mt.push({1ll*servers[i],1ll*i});
        }
        vector<int>ans(m);
        int t=0;
        for(int i=0;i<m;i++){
            while(!occ.empty() && occ.top().first<=t){
                auto [et,idx]=occ.top();
                occ.pop();
                mt.push({1ll*servers[idx],idx});
            }
            if((int)mt.size()>0){
                auto [wt,idx]=mt.top();
                mt.pop();
                ans[i]=idx;
                occ.push({1ll*t+1ll*tasks[i],idx});
                if(i==t)
                t++;
            }
            else{
                auto [ett,idxx]=occ.top();
                // cout<<"No free server so ett="<<ett<<endl;
                while(!occ.empty() && occ.top().first==ett){
                    auto [et,idx]=occ.top();
                    // cout<<"index is "<<idx<<endl;
                    occ.pop();
                    mt.push({servers[idx],idx});
                }
                t=ett;
                auto [wt,idx]=mt.top();
                mt.pop();
                ans[i]=idx;
                occ.push({1ll*t+1ll*tasks[i],idx});
                // t++;
            }
        }
        return ans;
    }
};