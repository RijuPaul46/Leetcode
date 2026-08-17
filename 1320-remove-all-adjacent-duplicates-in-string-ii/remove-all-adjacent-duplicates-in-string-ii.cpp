class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        vector<pair<char,int>> st;
        int ptr=0;
        for(int i=0;i<n;i++){
            int j=i;
            while(j<n && s[j]==s[i])j++;
            int seq=(j-i)%k;
            while(st.size()>0 && st.back().first==s[i]){
                seq=(seq+st.back().second)%k;
                st.pop_back();
            }
            if(seq>0){
                st.push_back(make_pair(s[i],seq));
            }
            i=j-1;
        }
        string ans="";
        for(auto &[c,v]:st){
            for(int i=0;i<v;i++)ans+=c;
        }
        return ans;
    }
};