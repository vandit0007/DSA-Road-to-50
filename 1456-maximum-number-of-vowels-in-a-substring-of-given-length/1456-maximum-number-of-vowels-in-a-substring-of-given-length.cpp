class Solution {
public:
    int maxVowels(string s, int k) 
    {
     int maxi=0;
     int count=0;
     for(int i=0;i<k;i++)
     {
        if(string("aeiou").find(s[i])!=string ::npos)
        {
            count++;
        }
     }
     maxi=count;
     for(int i=k;i<s.size();i++)
     {
        if(string("aeiou").find(s[i-k])!=string::npos)
        {
            count--;
        }
        if(string("aeiou").find(s[i])!=string::npos)
        {
            count++;
        }
        maxi=max(maxi,count);
        if(maxi==k)
        {
            return k;
        }
     }   
     return maxi;
    }
};