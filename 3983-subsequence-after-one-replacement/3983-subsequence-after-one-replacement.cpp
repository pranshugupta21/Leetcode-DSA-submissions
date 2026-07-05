class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
   int match0 = 0; // Max characters matched with 0 replacements used
    int match1 = 0; // Max characters matched with 1 replacement used
    int s_len = s.length();

    for (char char_t : t) {
        // Save the previous match0 state before we modify it this turn
        int prev_match0 = match0;

        // 1. Can we advance our 1-replacement track using a natural match?
        if (match1 < s_len && char_t == s[match1]) {
            match1++;
        }

        // 2. See if we can build upon our 0-replacement track
        if (prev_match0 < s_len) {
            // Option A: The character matches naturally, keeping our 0-replacement streak alive
            if (char_t == s[prev_match0]) {
                match0 = prev_match0 + 1;
            }

            // Option B: We burn our 1 replacement right now on s[prev_match0] to match char_t.
            // This pushes our 1-replacement score up to (prev_match0 + 1).
            match1 = max(match1, prev_match0 + 1);
        }

        // Early exit: If either track successfully matched the entirety of s, we're good!
        if (match0 == s_len || match1 == s_len) {
            return true;
        }
    }

    return match0 == s_len || match1 == s_len;
}
};