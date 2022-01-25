class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n  = arr.size();
        if (n <3) return false;
        if (arr[0]>=arr[1]) return false;
        for (int i=2, dec=0; i<n-1; i++){
            
            if ( arr[i-1] < arr[i]){
                if (dec == 1) return false;
            }                      
            else if ( arr[i-1] > arr[i]){
                dec=1;
            }
            else if ( arr[i-1] == arr[i]) return false;
        }
        return arr[n-2] > arr[n-1];
    }
};