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
        int n=mountainArr.length();
        int peak=getpeak(mountainArr,n);
        if(mountainArr.get(peak)==target) return peak;
        int idx1=firstsearch(mountainArr,n,peak,target);
        if(idx1!=-1) return idx1;
        return lastsearch(mountainArr,n,peak,target);

    }
    private:
    int getpeak( MountainArray &mountainArr,int n){
        int low=1,high=n-2;
        while(low<high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low=mid+1;
            }
            else high=mid;
        }
        return low;
    }
    int firstsearch(MountainArray &mountainArr,int n,int peak,int target){
      int low=0,high=peak;
      while(low<=high){
        int mid=low+(high-low)/2;
        int midval=mountainArr.get(mid);
        if(midval==target) return mid;
        else if(midval>target)high=mid-1;
        else low=mid+1;
      }
      return -1;
    }
    int lastsearch(MountainArray &mountainArr,int n,int peak,int target){
      int low=peak+1,high=n-1;
      while(low<=high){
        int mid=low+(high-low)/2;
        int midval=mountainArr.get(mid);
        if(midval==target) return mid;
        else if(midval<target)high=mid-1;
        else low=mid+1;
      }
      return -1;
    }
};