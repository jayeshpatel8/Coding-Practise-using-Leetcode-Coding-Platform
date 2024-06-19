class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        long l=1, r= *max_element(begin(b), end(b))+1, _max=r;

        while (l<r){
            long mid = (l+r)/2;
            int d=0,c=0;
            for (auto i : b){
                if (i <=mid) c++;
                else c= 0;
                if (c == k) {
                    d++,c=0;
                }
            }
            if (d >= m) r=mid;
            else l = mid+1; 

        }
        return r==_max ? -1 : r;
    }
};
