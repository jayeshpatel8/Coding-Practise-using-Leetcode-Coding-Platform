
int mbsearch(int * n, int l, int r, int t)
{
    if (l >r)
        return -1;
    
    int m = r+(l-r)/2;
    
    if (t == n[m]) return m;
    
    if (n[l] < n[m]) // right side is correctly sorted
    {
        if (t < n[m])
            if (t >= n[l])
                return mbsearch(n, l, m-1,t);
            else if (t <=n[r])
                return mbsearch(n, m+1, r,t);
            else
                return -1;
        else
            return mbsearch(n, m+1, r,t);        
    }
    else{
        if (t > n[m])
            if (t <= n[r])
                return mbsearch(n, m+1, r,t);
            else if (t >= n[l])
                return mbsearch(n, l, m-1,t);
            else
                return -1;
        else
            return mbsearch(n, l, m-1,t);        
    }
}
int search(int* nums, int numsSize, int target){

    return mbsearch(nums,0,numsSize-1,target);
}

