class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;  // Quick rejection if lengths differ

       vector<int>freq(26,0);

        for (char ch : s) {
            freq[ch-'a']++;  // Count characters in s
        }

        for (char ch : t) {
            freq[ch-'a']--;  // Subtract counts for t
        }

        for(int x:freq)
        {
            if(x!=0) return false;
        }
        return true;
    }
};
