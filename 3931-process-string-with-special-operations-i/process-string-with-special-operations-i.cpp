class Solution {
public:
    string processStr(string s) {
        string str="";
        for(auto & ch:s){
            if(islower(ch))str+=ch;
            else if(ch=='*'){
                if(!str.empty())str.pop_back();
            }
            else if(ch=='#')str+=str;
            else if(ch=='%')reverse(str.begin(),str.end());
        }
        return str;
    }
};