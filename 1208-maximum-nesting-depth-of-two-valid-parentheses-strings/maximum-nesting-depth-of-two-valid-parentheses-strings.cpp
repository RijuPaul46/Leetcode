class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int>ans(n);
        ans[0]=0;
        vector<int>st;
        int prev=0;
        st.push_back(0);
        for(int i=1;i<n;i++){
            if(seq[i]=='('){
                int nw=1;
                if(prev==1)nw=0;
                ans[i]=nw;
                prev=nw;
                st.push_back(i);
            }
            else{
                int tp=st.back();
                ans[i]=ans[tp];
                st.pop_back();
                if(st.size()>0)prev=ans[st.back()];
                
            }
        }
        return ans;
    }
};