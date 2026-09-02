class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        if(n==2){
            if(nums[0]!=nums[1]) return 0;
            return 1;
        }
        auto countsplits=[&](vector<int>&arr){
        int m=arr.size();
        vector<int>prefix(m),suffix(m);
        prefix[0]=arr[0];
        for(int i=1;i<m;i++){
            prefix[i]=__gcd(prefix[i-1],arr[i]);
        }
        suffix[m-1]=arr[m-1];
        for(int i=m-2;i>=0;i--){
            suffix[i]=__gcd(suffix[i+1],arr[i]);
        }
        int c=0;
        for(int i=0;i<m-1;i++){
            if(prefix[i]==suffix[i+1])c++; // counting valid splits position from which GCD till i-> prefix== GCD from n to i+1
        }
        return c;
    };
        int maxscore=countsplits(nums); // for whole array removing no elements
        for(int i=0;i<n;i++){
            vector<int>arr;
            for(int j=0;j<n;j++){
                if(i!=j)arr.push_back(nums[j]);  // execluding one element at a time for every element in the array
            }
            maxscore=max(maxscore,countsplits(arr));
        }
        return maxscore;
    }
};