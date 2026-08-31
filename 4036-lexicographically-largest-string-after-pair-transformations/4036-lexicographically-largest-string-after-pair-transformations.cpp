class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n=nums.size();
        vector<string>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=buildstring(nums[i]);
        }
        return ans;
    }
    private:
     string buildstring(int x){
        string str="";
        for(int i=25;i>=0;i--){
            long long curr=1<<i; // 2^i;
            if(x<curr) continue;
            int cnt=x/curr;
            x%=curr;
            string temp(cnt,'a'+i);  // fill constructor cnt no of characters will be appended to temp of character 'a'+i
            str+=temp;
        }
        return str;
     }
};