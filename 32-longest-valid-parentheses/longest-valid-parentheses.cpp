class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int>valid(n,0);
        vector<int>st;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push_back(i);
            }
            else {
                if(st.size()>0 && s[st.back()]=='('){
                    valid[st.back()]=1;
                    valid[i]=1;
                    st.pop_back();
                }
            }
        }
        int streak=0;
        int mx=0;
        for(int i=0;i<n;i++){
            if(valid[i]){
                streak++;
            }
            else{
                mx=max(mx,streak);
                streak=0;
            }
        }
        mx=max(mx,streak);
        return mx;
    }
};