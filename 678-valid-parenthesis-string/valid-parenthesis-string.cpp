class Solution {
public:
    bool checkValidString(string s) {
        vector<char>st;
        for(auto c:s){
            if(c=='(' || c=='*')st.push_back(c);
            else{
                int cnt=0;
                
                while(st.size()>0 && st.back()=='*'){st.pop_back();cnt++;}
                if(st.size()==0){
                    if(cnt>0){
                        cnt--;
                    }
                    else return false;
                }
                else{
                    if(st.back()=='('){
                        st.pop_back();
                    }
                    else if(st.back()==')'){
                        if(cnt>0){cnt--;}
                        else return false;
                    }
                }
                for(int i=0;i<cnt;i++)st.push_back('*');
            }
        }
        vector<char>st1;
        for(auto &c:st){
            if(c=='(')st1.push_back(c);
            else if(c=='*'){
                if(st1.size()>0)st1.pop_back();
            }
        }
        return st1.size()==0;
    }
};