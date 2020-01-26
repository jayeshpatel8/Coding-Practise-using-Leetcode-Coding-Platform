void swap(int *nums, int left, int right) {
    int tmp = nums[left];
    nums[left] = nums[right];
    nums[right] = tmp;
}

int position(int *nums, int left, int right, int pivot) {
    while(left <= right) {
        while(nums[left] < pivot) left++;
        while(nums[right] > pivot) right--;
        if (left <= right) {
            swap(nums, left, right);
            left++;
            right--;
        }
    }
    return left;
}

void quicksort_f(int *nums, int left, int right) {
    if (left >= right) return;
    int pivot = nums[(left + right) / 2];
    int index = position(nums, left, right, pivot);
    quicksort_f(nums, left, index -1);
    quicksort_f(nums, index, right);
    return;
}

void quicksort(int *nums, int numsSize) {
    quicksort_f(nums, 0, numsSize-1);
    return;
}
int threeSumClosest(int* nums, int numsSize, int target){

    quicksort(nums,numsSize);
    int p_sum=0xFFFFFF,p_abs_sum=0xFFFFFF;
    for (int i=0; i <numsSize-2;i++){
        if (i>0 && nums[i]==nums[i-1]) continue;
        int l=i+1, r=numsSize-1;
        while(l<r){
            int c_sum=nums[i]+nums[l]+nums[r];
            
            if (c_sum < target)
                do
                  l++;
                while(l<r && nums[l]==nums[l-1]);
            else if (c_sum > target)
                do
                    r--;
                while(l<r && nums[r]==nums[r+1]) ;
            else{
                return target;
            }
            int diff = abs(target-c_sum);
            if (p_abs_sum > diff)
               p_sum =c_sum,p_abs_sum=diff;
    
            
        }
   }
    return ( p_sum);
}

