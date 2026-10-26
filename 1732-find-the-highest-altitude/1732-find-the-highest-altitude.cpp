class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int n=gain.size();
        vector<int>gains(n+1,0);

        for(int i=0;i<gain.size();i++)
        {
            gains[i+1]=gain[i]+gains[i];
        }
        sort(gains.begin(),gains.end());
        if(gains[n]<0)
        {
            return 0;
        
        }
        return gains[n];
    }
};