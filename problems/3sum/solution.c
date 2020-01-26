

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b){
return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){



    * returnSize=0;
    int total=32;
    * returnColumnSizes = (int *) malloc(sizeof(int)*total);
   int ** ret = (int **) malloc(sizeof(int*)*total);
    if(numsSize<3)
        return 0;
    qsort(nums,numsSize,sizeof(int),cmp);
    int n1=nums[0]+1;
   // int debug=0;
    // [ -4 -1 -1 0 1 2]
    for (int i=0; i< numsSize-2 && nums[i]<=0; i++)
    {
        if (i>0 && nums[i] == nums[i-1])
            continue;
        n1=-nums[i];
        //int n2=nums[i+1]+1;
        
        for (int j=i+1,k=numsSize-1; j<k; )
        {         

            int s= (nums[k]+nums[j]);
            if (s<n1) j++;
            else  if (s>n1)k--;
            else
            {
                ret[* returnSize] = (int*)malloc(sizeof(int)*3);
                ret[* returnSize][0]=nums[i];ret[* returnSize][1]=nums[j];ret[* returnSize][2]=nums[k];           
                j++;k--;
                while(j<k && nums[j-1]==nums[j] ){
                    j++;
                }
                while (j<k && nums[k]==nums[k+1]){
                    k--;}                
                (* returnColumnSizes)[* returnSize]=3;
                (* returnSize)++;
                
//                debug++;
                if((*returnSize)==total)
                {
                    total*=2;
                    *returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int)*total);
                    ret=(int**)realloc(ret,sizeof(int*)*total);
                }                
            }
        }
    }
      
  return ret;
}