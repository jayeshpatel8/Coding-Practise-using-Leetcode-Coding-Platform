

int removeDuplicates(int* nums, int numsSize){
    if(numsSize<2) return numsSize;
int j=0,i=1;
    while (i < numsSize)
    {
        if (nums[j]!=nums[i])
            nums[++j]=nums[i];
        i++;
    }
    
    return ++j;
}

