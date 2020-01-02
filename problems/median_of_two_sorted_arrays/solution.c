
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

        // [1 5 7 11 60] [6 8 10 40 80]  [1 5 6 7 8 10 11 40 60 80] [3 4]
        //
    int hlen = (nums1Size + nums2Size + 1)  /2;
    int *a ,*b,aMin=0,aMax,aLen,bLen;
    if (nums1Size < nums2Size)
        a=nums1,b=nums2,  aMax=aLen=nums1Size,bLen=nums2Size;
    else
        a=nums2,b=nums1,  aMax=aLen=nums2Size,bLen=nums1Size;

    while(aMin <= aMax)
    {
        int aCnt=aMin+(aMax-aMin)/2;
        int bCnt=hlen-aCnt;
        if(aCnt>0 && a[aCnt-1]>b[bCnt]  )
            aMax=aCnt-1;
        else if  (aCnt <aLen && b[bCnt-1]>a[aCnt])
            aMin=aCnt+1;
        else {
            int LEnd = (0==aCnt)?b[bCnt-1]:(0==bCnt)?a[aCnt-1]:MAX(b[bCnt-1],a[aCnt-1]);
                if ((nums1Size+nums2Size)%2!=0)
                    return LEnd;
            int RStart = (aLen==aCnt)?b[bCnt]:(bLen==bCnt)?a[aCnt]:MIN(b[bCnt],a[aCnt]);
            
            return (LEnd+RStart)/2.0;
        }
    }
    return -1;
}

