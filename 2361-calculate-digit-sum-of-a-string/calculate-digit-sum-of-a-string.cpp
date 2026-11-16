class Solution {
public:
    string findsum(string&s){
        int sm=0;
        for(auto &c:s){
            sm+=(c-'0');
        }
        return to_string(sm);
    }

    string digitSum(string s, int k) {
        int n=s.size();
        if(n<=k)return s;
        string str="";
        for(int i=0;i<n;i+=k){
            int len=min(n-i,k);
            string sub=s.substr(i,len);
            str+=findsum(sub);
        }
        return digitSum(str,k);
    }
};