class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prev=-1, ans = 1, i=0 , n = seats.size();
        for  (; i<n; i++){
            if (seats[i]){
                ans = max(ans, i);
                prev = i;
                break;
            }
        }
        for  (; i<n; i++){
            if (seats[i]){
                ans = max(ans, (i-prev) / 2);
                prev = i;
            }
        }
        if ( seats[n-1] ==0)
            ans = max(ans, (i-prev)-1);
        return ans = max(ans, (i-prev) / 2);
    }
};