#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

int min[numsSize];
int max[numsSize];
    min[0]=max[0]=nums[0];
    
    for (int i=1; i < numsSize; i++){
        int rem_target = target-nums[i];
        min[i] = nums[i]>min[i-1]?min[i-1]:nums[i];
        max[i] = nums[i]<max[i-1]?max[i-1]:nums[i];

        {
             for (int j=i-1; (j >= 0) && (rem_target >= min[j]) && (rem_target <= max[j]); j--)
             {
                 if (nums[j] == rem_target)
                 {
                    *returnSize=2;
                    int * returnArr = (int *) malloc(sizeof(int)*2);          
                    returnArr[0] = j;
                    returnArr[1] = i;
                    return returnArr;                     
                 }
             }
        }
    
    }
*returnSize=0;
    return 0;
}

