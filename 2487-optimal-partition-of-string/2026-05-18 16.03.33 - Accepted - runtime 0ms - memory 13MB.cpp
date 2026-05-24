class Solution {
public:
    int partitionString(string s) {
        int count = 1;
        int mask = 0; // This integer will act as our "set"
        
        for (char c : s) {
            // Shift 1 to the left by the character's alphabetical index (0 to 25)
            int bit = 1 << (c - 'a');
            
            // Use bitwise AND to check if the bit is already set
            if ((mask & bit) != 0) {
                count++;   // We found a duplicate, start a new substring
                mask = 0;  // Clear the "set"
            }
            
            // Add the current character to the "set" using bitwise OR
            mask |= bit; 
        } 
        
        return count;
    }
};