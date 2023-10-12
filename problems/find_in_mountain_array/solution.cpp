/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int N = mountainArr.length();
        int l=0, r=N-1;
        while (l<r){
            int m =  (l+r+1)/2;
            if (m>0){
                if (mountainArr.get(m) > mountainArr.get(m-1) ) l= m;
                else r=m-1;
            }
            else{
                if (mountainArr.get(m) < mountainArr.get(m+1) ) l= m+1;
                else r=m;
            }
        }
        int l1=0, r1=r;
        while (l1<=r1){
            int m =  (l1+r1+1)/2;
            int v = mountainArr.get(m);
            if ( v ==target ) return m;
            else if ( target <  v) r1= m-1;
            else l1=m+1;
        }
         l1=r+1, r1=N-1;
        while (l1<=r1){
            int m =  (l1+r1+1)/2;
            int v = mountainArr.get(m);
            if ( v ==target ) return m;
            else if ( target <  v) l1= m+1;
            else r1=m-1;
        }
        return -1;
    }
};