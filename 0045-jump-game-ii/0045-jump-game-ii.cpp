class Solution {
public:
    int jump(vector<int>& nums)
    {
        int l=0,r=0,jump=0;
        while(r<nums.size()-1)
        {
            int far=0;
            for(int i=l;i<=r;i++)
            {
                far=max(far,i+nums[i]);
            }
            l=l+1;
            r=far;
            jump=jump+1;
        }
        return jump;
    }
};