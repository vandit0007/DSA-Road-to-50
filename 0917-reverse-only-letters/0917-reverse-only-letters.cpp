class Solution {
public:
    string reverseOnlyLetters(string s) 
    {
        int right=s.size()-1;
        int left=0;
        while(left<right)
        {
        while(left<right && !isalpha(s[left]))
        {
            left++;
        }
        while(left<right && !isalpha(s[right]))
        {
           right--;
        }
     


                    swap(s[left],s[right]);
                    left++;
                    right--; 
        }
        return s;
        
    }
};