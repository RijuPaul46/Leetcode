class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        string st;
        int n=num.size();
        for(auto c:num){
            while(!st.empty() && k>0 && st.back()>c){
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        while(k>0){st.pop_back();k--;}
        int i=0;
        while(i<st.size() && st[i]=='0'){
            i++;
        }
        ans=st.substr(i);
        if(ans.size()==0)return "0";
        return ans;
    }
};