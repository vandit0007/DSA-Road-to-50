class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int left=0;
        int r=0;
        int zero=0;
        int maxi=0;
        for(int r=0;r<nums.size();r++)
        {
            if(nums[r]==0)
            {
                zero++;
            }
            while(zero>1)
            {
                if(nums[left]==0)
                {
                    zero--;
                }
                left++;
            }
            maxi=max(maxi,r-left+1);
        }
        return maxi-1;
    }
};