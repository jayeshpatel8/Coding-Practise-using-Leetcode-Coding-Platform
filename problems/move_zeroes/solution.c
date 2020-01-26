

void moveZeroes(int* nums, int numsSize){
int c=0,s=0;
    for(int i=0; i < numsSize; i++){
        if(0!=nums[i]){
            if(s!=i)
            nums[s++]=nums[i];
            else
                s++;
        }
        else{
            c++;
            
        }
    }
        while(c--)
            nums[s++]=0;
    
}

