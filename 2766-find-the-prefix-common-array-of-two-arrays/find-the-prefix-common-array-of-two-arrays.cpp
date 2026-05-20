class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_set<int> st1;
        unordered_set<int> st2;
        vector<int> ans(n,0);
        st1.insert(A[0]);
        st2.insert(B[0]);
        ans[0]=A[0]==B[0];
        for(int i=1;i<n;i++){
            st1.insert(A[i]);
            st2.insert(B[i]);
            if(A[i]==B[i]){
                ans[i]=1+ans[i-1];
            }else{
            int cnt=0;
            if(st2.count(A[i]))cnt++;
            if(st1.count(B[i]))cnt++;
            ans[i]=ans[i-1]+cnt;
            }
            
        }
        return ans;
        
    }
};