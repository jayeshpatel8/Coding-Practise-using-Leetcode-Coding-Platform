class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        //[2,3,4,7,11]
        for (int i=1,j=0; i<arr[n-1] ; i++){
            if(arr[j] == i) {j++; continue;}            
            if (k<=arr[j]-i) return i+k-1;
            k -=arr[j]-i; 
            i =arr[j++];
        }
        return arr[n-1]+k;
    }

};