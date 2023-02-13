class Solution {
public:
    int countOdds(int low, int high) {
     int diff = high - low;   
     return (low & 1) + (diff/2) + (diff&1 ? (high & 1) : 0 );
    }
};