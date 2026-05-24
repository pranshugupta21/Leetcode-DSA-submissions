class Solution {
public:
    int partitionString(string s) {
       int count=1;
       int mask=0;
       for(char ch: s){
        int bit=1<<(ch-'a');
        if((mask&bit)!=0){
           count++;
           mask=0;
        }
        mask|=bit;
       }
       return count;
    }
};