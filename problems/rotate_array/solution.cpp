class Solution {
public:
    void rotate(vector<int>& nums, int k) { 
        int l = nums.size();
        k=k%l;
        if (k < 1 || l < 2) return;
        int temp=nums[0];
        int total=0;
            for(int i=0,j=0;i<k && total<nums.size();i++)
            {
                temp = nums[i];
                j=i;
                do {
                    j=(j+k)%l;
                    int x=nums[j];
                    nums[j]=temp;
                    temp=x;
                    total++;
                }while (i!=j);
            }
          
    }
};
// 1 2 3 4 5 6 7
// 5 6 7 1 2 3 4

