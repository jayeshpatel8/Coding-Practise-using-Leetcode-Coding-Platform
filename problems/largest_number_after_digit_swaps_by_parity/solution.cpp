class Solution {
public:
    int largestInteger(int num) {
        vector<int> dig;
        while (num > 0){
            dig.push_back(num%10);
            num /= 10;
        }
        for (int i=dig.size()-1; i>=0; i--){
            for (int j=i-1; j>=0; j--){
                if (dig[j] > dig[i] && dig[i] %2 == dig[j]%2)
                    swap(dig[j],dig[i]);
            }
        }
        int ans = 0;
        for (int i=dig.size()-1; i>=0; i--){
            ans = ans * 10 + dig[i];
        }
        return ans;
    }
};