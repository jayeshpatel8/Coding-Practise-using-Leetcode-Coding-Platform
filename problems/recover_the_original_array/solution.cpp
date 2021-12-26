class Solution {
public:
    
 int search(vector<int>&nums,vector<bool>visit,int low,int high,int target){
       int index  = -1;
         while(low <= high){
			 int mid =  (low + high)/2;
	//   here we are visiting target from left to right so in case of mutiple target with same value we sure that we not miss any element.
    //   example from the mentioned array in case of [ 9 ,9 , 9 ] 
    //   if we visit  middle 9 then for the next 9  we can't predict whether to go right or left.
    //   In case we choose of moving right then we miss searching left 9 in next binarySearch with target 9 
   //   OR if we choose of moving left then we miss  right 9 in next binarySearch with target 9
          if(nums[mid]==target){
                 if(visit[mid]){
                      low = mid +1;
                  }
                 else{
                       index = mid;    // always take  non-visit index
                       high = mid-1; // move left for checking another values equals to target which not visit till now.
                    }
				 continue;
		       }

		 if(nums[mid] > target)
               high = mid-1;
            else
               low = mid +1;
	  }
       return index;
    }
  
  vector<int> recoverArray(vector<int>& nums) {
	  int n = nums.size();
	  sort(nums.begin(),nums.end());
	  int smallest = nums[0];
       
         for(int i =1;i<n;i++){
                int k = (nums[i] - smallest)/2; // trying for each k
				
                     if(k<=0 || smallest + 2*k != nums[i]) // not a valid k for getting ans so we skip it
                             continue;
             
                       vector<bool> visit(n); // keep tracking of elements so we ensure that we not multi matched the single element.
                       vector<int>ans;         
                   
                       for(int j=0;j<n;j++){
                       
                           if(visit[j]) // there is no use of that element which is already matched with any element
                              continue;
                       
                           int target = nums[j] + 2*k; 
                           int index = search(nums,visit,j+1,n-1, target); // finding a valid leftmost index which is equal to target
                              
                            if(index==-1) // if not found the target matched  we simply break from the loop.
                               break;
                        
                            visit[index] = true; // mark the target index so we not vist this next time if we found same target.
                           
                            ans.push_back(nums[j] + k); // storing value  as an ans.(explained above why we storing nums[j] + k)
														 // lower[i] = nums[i] - k   =>  nums[i] = lower[i] + k // so we get one valid num[i] element
                       }
                    
					   if(ans.size()==n/2) // since if we able to find n/2 matched then we got our ans.
                             return ans;
             }
          return {};
    }
};
