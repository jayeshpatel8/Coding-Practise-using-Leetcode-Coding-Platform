class Solution {
public:
    const int N =  6e4 ;
    int bit[60000 + 1]={};
    void update(int i){
        for (; i<N; i+=i & -i){
            bit[i]+=1;
        }
    }
    int get(int i){
        int cnt= 0;
        for (; i>0; i-=i & -i){
            cnt += bit[i];
        }
        return cnt;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        for (int i=0; i<nums1.size(); i++)
            nums1[i] = nums1[i]  - nums2[i] +3e4;
        long long ans = 0;

        for (auto i : nums1){            
            ans += get(i+diff);
            update(i);
        }   
        return ans;
    }
};