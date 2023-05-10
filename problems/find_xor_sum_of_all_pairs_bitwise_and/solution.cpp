class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int f1[32]={},f2[32]={};
        for (auto n : arr1){
            for (int i=0; i<31;i++)
                if ((1<<i) & n) f1[i]++;
        }
        for (auto n : arr2){
            for (int i=0; i<31;i++)
                if ((1<<i) & n) f2[i]++;
        }
        int ans = 0;
        for (int i=0; i<31;i++){
            f1[i]&=1;f2[i]&=1;
            if (f1[i] & f2[i]) ans |= 1<<i;
        }
        return ans;
    }
};