class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for ( int i=m-1,j=n-1,k=i+j+1; k>=0; k-- ){
            int n1 = i>=0 ? nums1[i] : INT_MIN;
            int n2 = j>=0 ? nums2[j] : INT_MIN;
            if (n1 >= n2)
                nums1[k] = n1, i--;
            else
                nums1[k] = n2, j--;
        }
        return ;
    }
};