class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mp;
        unordered_set<char>used;
        for(auto &c:s)mp[c]++;
        string st;
        for(auto &c:s){
            if(!used.count(c)){
                while(!st.empty() && st.back()>c && mp[st.back()]>0){
                    used.erase(st.back());
                    st.pop_back();}
                st.push_back(c);
                used.insert(c);
            }
            mp[c]--;
        }
        return st;
    }
};