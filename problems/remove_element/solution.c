

int removeElement(int* nums, int numsSize, int val){
int d=0,c=0,i=0;
    for (; i <numsSize; i++)
    {
        if(nums[i]!=val)
        {
            nums[d++]=nums[i];
        }
        else 
            c++;
           
    }
    return numsSize-c;
}

