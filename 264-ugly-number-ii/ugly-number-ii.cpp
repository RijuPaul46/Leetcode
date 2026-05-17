#define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {
       vector<ll>arr(n+1);
       arr[1]=1;
       set<ll>st;
       for(int i=2;i<=n;i++){
        int prev=arr[i-1];
        st.insert(1ll*prev*2);
        st.insert(1ll*prev*3);
        st.insert(1ll*prev*5);
        arr[i]=*st.begin();
        st.erase(st.begin());
       }
       return (int)arr[n];
    }
};