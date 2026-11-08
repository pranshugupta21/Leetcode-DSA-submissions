class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<long long >prefixsum(n+1,0);
        for(int i=1;i<=n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i-1];
        }
        long long ans=0;
        vector<int>nseR(n,n);
        vector<int>nseL(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >=nums[i]) st.pop();
            if(!st.empty())
               nseR[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();  
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >=nums[i]) st.pop();
            if(!st.empty())
               nseL[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            long long sumRange=(prefixsum[nseR[i]]-prefixsum[nseL[i]+1]);
            long long min_product=sumRange*nums[i];
            ans=max(ans,min_product);
        }
        return ans%1000000007;
    }
};




/*
precompute the sum for each window using prefix sum
take each element as minimum in every window and calculate sum and multiply by nums[i] to get the product
take the maximum of those
prefixsum[],
nse(right)[],
nse(left)[],
ans=max(ans,(prefixsum[right]-prefixsum[left+1])*nums[i])
*/