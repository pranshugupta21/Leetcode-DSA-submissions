class Solution {
public:
       int findKthPositive(vector<int>& A, int k) {
       int low=0,high=A.size()-1;
       while(low<=high){
        int mid=(low+high)/2;
        if(A[mid]-(mid+1)<k){
            low=mid+1;
        }
        else{
           high=mid-1; 
        }
       }
       return low+k;
    }
};                                                                                