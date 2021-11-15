class Solution {
public:
    int maxTaskAssign(vector<int>& t, vector<int>& w, int pills, int strength) {
        sort(begin(t), end(t));
        sort(begin(w), end(w));
        
        int lo = 0, hi = min(t.size(), w.size()),mid , ans;
        while(lo<=hi){
            mid = (lo + hi ) / 2;
  
            multiset<int> wo(end(w)-mid, end(w));
            for (int i = mid -1, p = pills; i>=0 ; i--){
                auto it = prev(wo.end());
                if (t[i] > *it){
                     it = wo.lower_bound(t[i] - strength);
                    if (it == wo.end() || (--p < 0))
                        break;
                }
                wo.erase(it);
            }
            
            if (wo.empty())
                 ans = mid , lo=mid+1;            
            else 
                hi = mid-1;                
        }
        return ans;
     
    }
};