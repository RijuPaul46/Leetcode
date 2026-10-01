class Solution {
public:
    bool isOpen(char c){
        return c=='(' || c=='{' || c=='[';
    }
    char opening(char c){
        if(c=='}')return '{';
        if(c==']')return '[';
        return '(';
    }
    bool isValid(string s) {
        vector<char>st;
        for(auto &c:s){
            if(isOpen(c)){
                st.push_back(c);
            }
            else{
                if(st.size()>0){
                    char open=opening(c);
                    if(st.back()!=open)return false;
                    else st.pop_back();
                }
                else return false;
            }
        }
        return st.size()==0;
    }
};