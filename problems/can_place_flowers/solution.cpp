class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N=flowerbed.size();

        for (int i=0; i<N; i++){
            if (!flowerbed[i] && 
                (!i || !flowerbed[i-1]) && (i==N-1 || !flowerbed[i+1])){
                --n;
                if (n<=0) return true;
                flowerbed[i]=1;
            }
        }
        
        return n<=0;
        //  101010
    }
};