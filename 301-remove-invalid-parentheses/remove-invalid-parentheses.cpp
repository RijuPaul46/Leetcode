class Solution {
public:
    set<string>ans;
    bool isValid(string &s){
        int score=0;
        for(auto &c:s){
            if(c=='('){
                score++;
            }
            else if(c==')')score--;
            if(score<0){
                return 0;
            }
        }
        return score==0;
    }
    void solve(int i, string &s, string &cur,
           int open, int close, int balance) {

    if(balance < 0) return;

    if(i == s.size()) {
        if(open == 0 && close == 0 && balance == 0)
            ans.insert(cur);
        return;
    }

    if(s[i] == '(') {

        // Keep
        cur.push_back('(');
        solve(i+1, s, cur, open, close, balance+1);
        cur.pop_back();

        // Delete
        if(open > 0)
            solve(i+1, s, cur, open-1, close, balance);

    }
    else if(s[i] == ')') {

        // Keep
        if(balance > 0) {
            cur.push_back(')');
            solve(i+1, s, cur, open, close, balance-1);
            cur.pop_back();
        }

        // Delete
        if(close > 0)
            solve(i+1, s, cur, open, close-1, balance);
    }
    else {
        cur.push_back(s[i]);
        solve(i+1, s, cur, open, close, balance);
        cur.pop_back();
    }
}
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        int open=0,close=0,score=0;
        for(auto &c:s){
            if(c=='('){
                score++;
            }
            else if(c==')')score--;
            if(score<0){
                close++;
                score=0;
            }
        }
        open+=score;
        string str="";
        solve(0,s,str,open,close,0);
        vector<string>f;
        for(auto &s:ans)f.push_back(s);
        return f;
    }
};