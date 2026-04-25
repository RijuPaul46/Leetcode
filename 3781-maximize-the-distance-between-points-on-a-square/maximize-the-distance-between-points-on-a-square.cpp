#define ll long long
class Solution{
public:
    bool ok(ll g,vector<ll>&d,vector<int>&nxt,int n,int k,ll p){
        for(int i=0,j=0;i<n;i++){
            j=max(j,i+1);
            while(j<n && d[j]<d[i]+g) 
                j++;
            nxt[i]=j;
        }

        ll lim=p-g;
        for(int i=0;i<n;i++){
            int cur=i;
            for(int c=k-1;c>0 && cur<n; c--)
                cur=nxt[cur];

            if(cur<n && d[cur]-d[i]<=lim)
                return 1;
        }
        return 0;
    }

    int maxDistance(int s,vector<vector<int>>&pt,int k){
        int n=pt.size();
        ll p=4LL*s;
        vector<ll>d(n);
        vector<int>nxt(n);

        for(int i=0;i<n;i++){
            ll x=pt[i][0];
            ll y=pt[i][1];

            if(x==0||y==s)
                d[i]=p-x-y;
            else d[i]=x+y;
        }

        sort(d.begin(),d.end());

        ll lo=1,hi=p/k;
        while(lo<hi){
            ll m=(lo+hi+1)/2;

            if(ok(m,d,nxt,n,k,p))
                lo=m;
            else hi=m-1;
        }
        return hi;
    }
};