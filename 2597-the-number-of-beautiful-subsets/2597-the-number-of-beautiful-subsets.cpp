class Solution {
public:
    unordered_map<int,int>mp;
    int beautifulSubsets(vector<int>& nums, int k) {
        int count=0,n=nums.size();
        recur(nums,k,n,count,0);
        return count-1;
    }
    private:
    void recur(vector<int>&nums,int k,int n,int &cnt,int i){
       if(i==n){
        cnt++;
        return;
       }
        if(mp.find(nums[i]-k)==mp.end() && mp.find(nums[i]+k)==mp.end()){
            mp[nums[i]]++;
            recur(nums,k,n,cnt,i+1);            // choose 
            mp[nums[i]]--;                       // undo
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
        }
        recur(nums,k,n,cnt,i+1);               // next
       }
    
};