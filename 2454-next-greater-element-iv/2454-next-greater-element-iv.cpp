class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        // we use two stack 1st stack s1 contnins elements who havenot found their next greater element 
        // s2 contains the element who has found their next greater element 
        int n=nums.size();
        vector<int> ans(n,-1),s1,s2,temp;
        for(int i=0;i<n;i++){
          while(!s2.empty() && nums[s2.back()]<nums[i]){
            ans[s2.back()]=nums[i];
            s2.pop_back();
          }
          while(!s1.empty() && nums[s1.back()]<nums[i]){
            temp.push_back(s1.back());
            s1.pop_back();
          }
          while(!temp.empty()){
            s2.push_back(temp.back());
            temp.pop_back();
          }
          s1.push_back(i);
        }
        return ans;
    }
};