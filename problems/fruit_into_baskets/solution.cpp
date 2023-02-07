class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int> freq(fruits.size());
        int ans = 0;
        for (int i=0, j=0,cnt=0;i<fruits.size(); i++){
            if (freq[fruits[i]]++ ==0) cnt++;
            while (cnt > 2){
                if (--freq[fruits[j++]] ==0) cnt--;
            }
            ans= max(ans, i-j+1);
        }
        return ans;
    }
};