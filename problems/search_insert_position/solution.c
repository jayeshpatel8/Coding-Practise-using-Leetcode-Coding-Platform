
int bs(int* nums,int l, int r,int t){
    if(l<=r)
    {
        if (l==r) return l;
        int m = r+(l-r)/2;
        if(nums[m]==t) return m;
        else if (nums[m]<t) {int k = bs(nums,m+1,r,t);
                             return (k==-1?m:k);}
        else if (nums[m]>t) {int k = bs(nums,l,m-1,t);
                             return (k==-1?m:k);}
    }
    return -1;
}
int searchInsert(int* nums, int numsSize, int target){
    if (!numsSize) return 0;
    if (nums[0]>=target) return 0;
    if(nums[numsSize-1]<target) return numsSize;
    
    int i = bs(nums,0,numsSize-1,target);
    
    if (nums[i]==target) return i;
    else if ( i>0 )
        if ( nums[i-1] < target &&  nums[i] > target) return i;
        else return i+1;
    else if (nums[0] < target) return 1;
    else return 0;
}

