class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int c=0;
        for(auto num:nums){
            while(num!=0){
                int ld=num%10;
                if(ld==digit) c++;
                num=num/10;
            }
        }
        return c;
    }
};