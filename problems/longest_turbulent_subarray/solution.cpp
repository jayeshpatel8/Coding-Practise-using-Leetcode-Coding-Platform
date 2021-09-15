class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int endless = 1, endgreat=1, ans= 1;        
        for (int i=1; i<n; i++){
            if (arr[i-1] == arr[i]) {
                endless = endgreat = 1;
            }
            else if (arr[i-1] < arr[i]){
                endgreat = endless + 1;
                endless = 1;
            }
            else{
                endless = 1 + endgreat;
                endgreat = 1;
            }
            ans = max(ans, max(endless, endgreat));

        }
        return ans;
    }
};