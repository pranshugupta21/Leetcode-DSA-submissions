class Solution {
     bool check(vector<int>&arr,int k,int maxsum){
        int c=1,sum=0,n=arr.size();
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=maxsum){
                sum+=arr[i];
            }
            else{
                c++;
                sum=arr[i];
            }
            if(c>k) return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
         int high=accumulate(arr.begin(),arr.end(),0);
        int low=*max_element(arr.begin(),arr.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(check(arr,k,mid)==true){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
    
};