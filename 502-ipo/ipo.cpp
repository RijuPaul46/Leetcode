class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& prof, vector<int>& cap) {
        int n=prof.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)arr.push_back({cap[i],prof[i]});
        sort(arr.begin(),arr.end());
        int curr=w;
        int l=0;
        priority_queue<int>pq;
        while(k>0){
            auto idx=upper_bound(arr.begin(),arr.end(),pair<int,int>(curr,INT_MAX))-arr.begin();
            for(int i=l;i<idx && i<n;i++){
                pq.push(arr[i].second);
            }
            l=idx;
            if(pq.size()==0)break;
            if(pq.size()>0){curr+=pq.top();
            pq.pop();}
            k--;

        }
        return curr;

    }
};