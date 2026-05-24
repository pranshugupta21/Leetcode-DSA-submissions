class Solution {
    int gcd(int a,int b){
              if (a == 0)
                return b;
               return gcd(b % a, a);
           }
public:
    long long gcdSum(vector<int>& nums) {
       vector<int>prefixGCD;
        int n=nums.size();
        int maxx=INT_MIN;
        for(int i=0;i<n;i++){
             maxx=max(maxx,nums[i]);
            int gc=gcd(nums[i],maxx);
            prefixGCD.push_back(gc);
        }
         sort(prefixGCD.begin(),prefixGCD.end());
        int n1=prefixGCD.size();
        int l=0,r=n1-1;
        long long gcdsum=0;
        while(l<r){
            gcdsum+=gcd(prefixGCD[l],prefixGCD[r]);
            l++;
            r--;
        }
        return gcdsum; 
    }
};