class Solution {
public:
    int N;
    vector<int> aux;
    int reversePairs(vector<int>& nums) {
        N=nums.size();
        if (!N) 
            return 0;
       
       aux.resize(N);
       return mergesort(nums, 0, N-1);
    }    
    int mergesort(vector<int>& A, int lo, int hi){
        
        int revCnt=0;
        //[1,3,2,3,1]
        if (lo >=hi) return 0;
        int mid = lo + (hi-lo)/2;
        
        revCnt += mergesort(A, lo,mid);
        revCnt += mergesort(A, mid+1,hi);
        // 3,2,1  3,1
        int j=lo;
        for (int i=mid+1; i<=hi; i++){
            while (j<=mid && A[j] > (2L*A[i]))
                j++;
            revCnt +=j-lo;
        }
        merge(A,lo,mid,hi);
        return revCnt;
    }
    void merge(vector<int>& a, int lo, int mid, int hi){        
        for (int i=lo; i<=hi; i++)
            aux[i]=a[i];
        int i=lo,j=mid+1;
        for (int k=lo; k<=hi; k++){
            if (i>mid || (j<=hi && aux[i] < aux[j])) 
                a[k]=aux[j++];
            else
                a[k]=aux[i++];
        }
    }
};