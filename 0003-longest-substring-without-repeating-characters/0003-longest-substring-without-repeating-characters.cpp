class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0;
        unordered_set<char> seen;
        for (int right = 0; right < n; right++) 
        {
            while(seen.count(s[right]))
            {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};