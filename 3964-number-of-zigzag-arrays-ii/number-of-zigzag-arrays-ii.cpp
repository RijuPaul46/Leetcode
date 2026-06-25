#define ll long long
class Solution {
public:
    const ll mod=1e9+7;
    vector<vector<ll>> mat_mul(vector<vector<ll>> &mat1,vector<vector<ll>> &mat2){
        int n=mat1.size();
        vector<vector<ll>> ans(n,vector<ll>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ll sm=0;
                for(int k=0;k<n;k++){
                    sm=(sm+(mat1[i][k]*mat2[k][j])%mod)%mod;
                }
                ans[i][j]=sm;
            }
        }
        return ans;
    }
    vector<vector<ll>> power(vector<vector<ll>>& M,int n){
        if(n==1)return M;
        auto sq=mat_mul(M,M);
        auto abc=power(sq,n/2);
        if(n%2==0){
            return abc;
        }
        return mat_mul(M,abc);
    }
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        vector<vector<ll>> mat(2*m,vector<ll>(2*m));
        for(int i=0;i<2*m;i++){
            int elm1=i%m;
            for(int j=0;j<2*m;j++){
                int elm2=j%m;
                if((i/m)==0){
                    if(elm2<elm1 && j/m==1){
                        mat[i][j]=1;
                    }
                }
                else {
                    if(elm2>elm1 && j/m==0)mat[i][j]=1;
                }
            }
        }
        auto  ans=power(mat,n-1);
        ll sm=0;
        for(auto & arr:ans){
            for(auto &x:arr){
                sm=(sm+x)%mod;
            }
        }
        return sm;

    }
};