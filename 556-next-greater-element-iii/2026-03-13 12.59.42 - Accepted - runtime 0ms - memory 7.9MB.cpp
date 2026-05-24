class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>nums;
        int temp=n;
        while(temp!=0){
            int ld=temp%10;
             nums.push_back(ld);
             temp/=10;
        }
        reverse(nums.begin(),nums.end());
        int s=nums.size();
        int idx=-1;
        for(int i=s-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
              idx=i;
            break;
            } 
        }
        if(idx==-1) return -1;
        for(int i=s-1;i>=0;i--){
            if(nums[i]>nums[idx]){
            swap(nums[i],nums[idx]);
            break;
            }
        }
        reverse(nums.begin()+idx+1,nums.end());
        long long x1=0;
        for(int i=0;i<nums.size();i++){
            x1=((x1*10)+nums[i]);
        }
        return x1>INT_MAX? -1:x1;
    }
};