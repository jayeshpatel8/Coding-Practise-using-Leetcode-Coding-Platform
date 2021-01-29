class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int hpoint=0,sum=0;;
        for (auto i : gain){
            sum += i;
            hpoint = max(hpoint,sum);
        }
        return hpoint;
    }
};