class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int N= arr.size() ,s=0;
        for (auto i : arr) s+=i;
        if (s%3) return{-1,-1};
        if (s==0|| s==N) return {N/3-1,N-N/3};
        
        int i=getidx(arr,1),j=getidx(arr,s/3+1),k=getidx(arr,2* (s/3)+1);
     
        while(k<N && arr[i]==arr[j] && arr[j]==arr[k] ) {
            i++;j++;k++;
        }
                
        if (k==N) 
            return {i-1,j};
        return {-1,-1};
    }
    int getidx(vector<int>& arr, int s){
        
        for (int i=0; i< arr.size(); i++){
            s-=arr[i];
            if(s==0) return i;
        }
        return 0;
    }
};