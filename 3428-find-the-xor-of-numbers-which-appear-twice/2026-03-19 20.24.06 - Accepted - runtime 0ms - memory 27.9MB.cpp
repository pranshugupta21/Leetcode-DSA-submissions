class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
          int x=0;
        for(auto [num,freq]:mp){
            if(freq==2){
              x^=num;  
            }
        }
        return x;
    }
};