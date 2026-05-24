class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int>tw;
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        for(auto [num,freq]:mp){
            if(freq==2){
                tw.push_back(num);
            }
        }
        int x=0;
        for(int i:tw){
            x^=i;
        }
        return x;
    }
};