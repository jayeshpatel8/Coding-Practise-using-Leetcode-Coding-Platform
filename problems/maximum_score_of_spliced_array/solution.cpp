class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(begin(nums1),end(nums1),0);
        int sum2 = accumulate(begin(nums2),end(nums2),0);
       // cout << sum1 << " " <<sum2 <<endl;
       // if (sum1 < sum2) swap(nums1,nums2) ,swap(sum1,sum2);
       // cout << sum1 << " " <<sum2 <<endl;
        int s=0,c=0;
        for (int i=0;i<nums1.size(); i++){
            int d = nums2[i]-nums1[i];
            c= max(c+d,d);
            s = max(s,c);
        }
        int s2=0,c2=0;
        for (int i=0;i<nums1.size(); i++){
            int d = nums1[i]-nums2[i];
            c2= max(c2+d,d);
            s2 = max(s2,c2);
        }        
        //cout << sum1 << " " << s <<endl<<endl;;
        return max(sum1 + s, sum2 +s2);
    }
};