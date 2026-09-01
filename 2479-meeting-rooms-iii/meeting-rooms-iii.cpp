#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& mtn) {
        sort(mtn.begin(),mtn.end());
        set<ll>avail;
        for(ll i=0;i<n;i++)avail.insert(i);
        vector<ll>freq(n);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        for(auto &arr:mtn){
            ll at=1ll*arr[0];
            ll et=1ll*arr[1];
            ll bt=et-at;
            
                while(!pq.empty() && pq.top().first<=at){
                    auto [u,v]=pq.top();
                    pq.pop();
                    avail.insert(v);
                }
                if(avail.size()>0){
                    pq.push({et,*avail.begin()});
                    freq[*avail.begin()]++;
                    avail.erase(avail.begin());
                }
                else{
                    if(pq.size()>0){
                        auto [u,v]=pq.top();
                        
                        pq.pop();
                        
                        ll st=max(u,at);
                        et=st+bt;
                        pq.push({et,v});
                        freq[v]++;
                        
                    }
                }
            
        }
        ll mx=*max_element(freq.begin(),freq.end());
        for(int i=0;i<n;i++){
            if(freq[i]==mx)return i;
        }
        return -1;
    }
};