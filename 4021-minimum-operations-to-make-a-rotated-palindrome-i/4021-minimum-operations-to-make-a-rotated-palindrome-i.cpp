class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        
        int minops=1e9;
        for(int k=0;k<n;k++){     // rotate left position each time from 0 to n
            int i=0,j=n-1;
            int ops=k;            // initial cost of rotation 
            while(i<j){
                char ch1=s[(i+k)%n];   // character at ith location if the string rotated by k 
                char ch2=s[(j+k)%n];
                int diff1=(ch2-ch1+26)%26;  // changing ch1 to ch2 
                int diff2=(ch1-ch2+26)%26;  // changing ch2 to ch1
                int diff=min(diff1,diff2);  // taking minimum rotation cost
                ops+=diff;
            i++;
            j--;
        }
            minops=min(minops,ops);   // minimum of all possible rotation 
        }
        
       return minops;
    }
};