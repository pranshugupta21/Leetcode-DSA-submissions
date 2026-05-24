class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int>v;
       for(int i=0;i<nums.size();i++){
        int index=nums[i]-1; 
        if(nums[index]<0){
            v.push_back(index+1);
        }
        else{
            nums[index]=-1*nums[index];
        }
       }
       return v;
       }
       
    };
