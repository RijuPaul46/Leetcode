class Solution {
public:
    int solve(vector<int>&closing,string &s,int i,int j){
        int n=s.size();
        if((i+1)==j)return 1;
        if(i>=j)return 0;
        int inner=0;
        int k=i+1;
        while(k<j){
            inner+=solve(closing,s,k,closing[k]);
            k=closing[k]+1;
        }
        return 2*inner;
    }
    int scoreOfParentheses(string s) {
        vector<char>st;
        int n=s.size();
        vector<int>closing(n);
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push_back(i);
            else {
                closing[st.back()]=i;
                st.pop_back();
            }
        }
        int ans=0;
        int i=0;
        while(i<n){
            ans+=solve(closing,s,i,closing[i]);
            i=closing[i]+1;
        }
        return ans;
    }
};