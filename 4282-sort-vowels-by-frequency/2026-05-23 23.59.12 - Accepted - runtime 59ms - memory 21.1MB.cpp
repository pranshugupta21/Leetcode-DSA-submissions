class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string sortVowels(string s) {
    // Track frequency and first occurrence index for each of the 5 vowels
      // Map characters to indices: a->0, e->1, i->2, o->3, u->4
        vector<int> freq(5, 0);
        vector<int> first_occ(5, -1);
        
        auto getVowelIdx = [](char c) {
            if (c == 'a') return 0;
            if (c == 'e') return 1;
            if (c == 'i') return 2;
            if (c == 'o') return 3;
            return 4; // 'u'
        };
        // Step 1: Collect frequencies and first occurrence positions
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                int vIdx = getVowelIdx(s[i]);
                freq[vIdx]++;
                if (first_occ[vIdx] == -1) {
                    first_occ[vIdx] = i;
                }
            }
        }
        // Step 2: Extract all vowels found in the string
        vector<char> vowels;
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels.push_back(ch);
            }
        }
        // Step 3: Sort the vowels based on the rules
        sort(vowels.begin(), vowels.end(), [&](char a, char b) {
            int idxA = getVowelIdx(a);
            int idxB = getVowelIdx(b);
            
            // Rule 1: Non-increasing order of frequency (highest first)
            if (freq[idxA] != freq[idxB]) {
                return freq[idxA] > freq[idxB];
            }
            // Rule 2: If tied, sort by position of first occurrence
            return first_occ[idxA] < first_occ[idxB];
        });
        // Step 4: Rebuild the string
        string ans = "";
        int vowelPtr = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                ans += vowels[vowelPtr++];
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};