class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10),ans;
        for (auto i : digits) freq[i]++;
        
        for (int i=100; i<=999; i++){
            if (i%2 ==0 ){
                int n1 = (i/100), n2 = (i/10)%10, n3 = i%10 ;
                
                vector<int> f(10);
                if (++f[n1]>freq[n1] || ++f[n2]>freq[n2] || ++f[n3]>freq[n3]) continue;                
                ans.push_back(i);
            }
        }
        return ans;
    }
};