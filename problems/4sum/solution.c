

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
return *(int *)a - *(int *)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){

    * returnSize=0;
    int total=32;
    * returnColumnSizes = (int *) malloc(sizeof(int)*total);
   int ** ret = (int **) malloc(sizeof(int*)*total);
    if(numsSize<4)
        return 0;
    qsort(nums,numsSize,sizeof(int),cmp);
    int n1=0,n2;
   
    for (int i=0; i< numsSize-3 ; i++)
    {
        if (i>0 && nums[i] == nums[i-1])
            continue;
         n2=INT_MAX;
       for (int l=i+1; l< numsSize-2 ; l++)
       {
           if (nums[l] == n2)
               continue;
           n2=nums[l];
           n1=target-(nums[i]+nums[l]);
        
            for (int j=l+1,k=numsSize-1; j<k; )
            {         

                int s= (nums[k]+nums[j]);
                if (s<n1) j++;
                else  if (s>n1)k--;
                else
                {
                    ret[* returnSize] = (int*)malloc(sizeof(int)*4);
                    ret[* returnSize][0]=nums[i];ret[* returnSize][1]=nums[l];ret[* returnSize][2]=nums[j];ret[*returnSize][3]=nums[k];           
                    j++;k--;
                    while(j<k && nums[j-1]==nums[j] ){
                        j++;
                    }
                    while (j<k && nums[k]==nums[k+1]){
                        k--;}                
                    (* returnColumnSizes)[* returnSize]=4;
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
    }
      
  return ret;
}

