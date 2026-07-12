class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> t(n+1,0);
        //case 1 if taking first house
        t[0]=0;
        for(int i=1;i<=n;i++)
        {
         int skip=t[i-1] ;
         int steal=nums[i-1]+((i-2>=0) ? t[i-2] : 0)  ;
         t[i]=max(steal,skip);
        }
        int result1=t[n-1];
        t.clear();

        //case 2 skipping first house
        t[0]=0;
        t[1]=0;
        for(int i=2;i<=n;i++)
        {
         int skip=t[i-1] ;
         int steal=nums[i-1]+((i-2>=0) ? t[i-2] : 0)  ;
         t[i]=max(steal,skip);
        }
        int result2=t[n];
        return max(result1,result2);
    }
};