class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i=0 , N =arr.size();i<N; i++){
            if (arr[i] & 1){
                if (i+1 <N && (arr[i+1] & 1)){
                    if (i+2 <N && (arr[i+2] & 1))
                        return true;
                }
            }
        }      
        return  false;
    }
};
