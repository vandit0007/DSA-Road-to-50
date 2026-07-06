class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
     int i=0;
     for(int j=0;j<nums.size();j++)
     {
        if(nums[j]!=nums[i])
        {
            i++;
            nums[i]=nums[j];
            
        }
        //i=i+1;
     }   
     return i+1;
    }
};