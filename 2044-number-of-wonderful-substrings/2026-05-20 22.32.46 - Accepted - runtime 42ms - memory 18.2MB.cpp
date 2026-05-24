class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long>bitmask_count(1024,0);
        long long total_wonderful=0;
        long long curr_bitmask=0;
        bitmask_count[0]=1;
        for(char ch:word){
            int bit_index=ch-'a';
            curr_bitmask^=(1<<bit_index);
            total_wonderful+=bitmask_count[curr_bitmask];
            for(int k=0;k<10;k++){
                int look_mask=curr_bitmask^(1<<k);
                total_wonderful+=bitmask_count[look_mask];
            }
            bitmask_count[curr_bitmask]++;
        }
        return total_wonderful;
    }
};