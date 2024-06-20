class Solution {
public:
    int maxDistance(vector<int>& po, int m) {
        
        sort(begin(po),end(po));
        long l=0,r = po.back()-po[0]+1;
        while(l<r){
            auto mid = (l+r)/2;

            int cnt=1;
            long next = po[0] + mid;
            for (int i=1; i<po.size() ; i++){
                if (po[i] < next) continue;
                if (++cnt >=m) break;
                next= po[i]+mid;
            }
            if (cnt >= m)
                l = mid+1;
            else
                r = mid;
        }
        return l-1;
    }
};
