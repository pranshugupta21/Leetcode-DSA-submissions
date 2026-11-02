class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // sum of subarray maximums -sum of subarrays minimums
       return sum_subarray_maximums(nums)-sum_subarray_min(nums);
    }
 private:
  long long sum_subarray_min(vector<int>&arr){
     int n=arr.size();
     vector<int>nse(n,n);
        stack<int>st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty()&&arr[st1.top()]>=arr[i]){   
                st1.pop();
            }
            if(!st1.empty()){
                nse[i]=st1.top();
            }
            st1.push(i);
        }
        // previous smaller or equal element
        vector<int>pse(n,-1);
        stack<int>st2;
        for(int i=0;i<n;i++){
            while(!st2.empty() && arr[st2.top()]>arr[i]){// get PREVIOUS SMALLER OR EQUAL TO 
                st2.pop();
            }
             if(!st2.empty()){
                pse[i]=st2.top();
            }
            st2.push(i);
        }
        long long total=0;
        for(int i=0;i<n;i++){
          long long left=i-pse[i];
          long long right=nse[i]-i;
          total=total+(left*right*arr[i]);
        }
        return total;
  }
  long long sum_subarray_maximums(vector<int>&nums){
    int n=nums.size();
    vector<int>nge(n,n);
    stack<int>st1;
    for(int i=n-1;i>=0;i--){
        while(!st1.empty()&& nums[st1.top()]<=nums[i]){
            st1.pop();
        }
        if(!st1.empty()){
            nge[i]=st1.top();
        }
        st1.push(i);
    }
    vector<int>pge(n,-1);
    stack<int>st2;
    for(int i=0;i<n;i++){
        while(!st2.empty() && nums[st2.top()]<nums[i]){
            st2.pop();
        }
        if(!st2.empty()) 
           pge[i]=st2.top();        // store index not value
        st2.push(i);
    }
        long long total=0;
        for(int i=0;i<n;i++){
          long long left=i-pge[i];
          long long right=nge[i]-i;
          total=total+(left*right*nums[i]);
        }
        return total;
  }
};