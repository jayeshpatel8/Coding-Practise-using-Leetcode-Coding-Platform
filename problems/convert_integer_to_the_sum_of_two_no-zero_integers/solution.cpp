class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for ( int i=1; i<n; i++){
            if (nozero(i) && nozero(n-i))
                return {i,n-i};
        }
        return {};
    }
    bool nozero(int i){
        while (i){
            if (i%10 == 0) return false;
            i/=10;
        }
        return true;
    }
};