#define ll long long
class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=shifts.size();
        int m=tasks.size();
        vector<ll>pre(m,0);
        pre[0]=tasks[0];
        for(int i=1;i<m;i++){
            pre[i]=pre[i-1]+tasks[i];
        }
        ll prev=0;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ll shift=1ll*shifts[i]+prev;
            int idx=upper_bound(pre.begin(),pre.end(),shift)-pre.begin();
            int rem=m-idx;
            ans[i]=rem;
            if(rem==0)prev=0;
            else prev+=1ll*shifts[i];
        }
        return ans;
    }
};