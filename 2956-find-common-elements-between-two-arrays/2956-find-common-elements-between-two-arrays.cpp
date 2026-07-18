class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) 
    {
     unordered_set<int> set1(nums1.begin(),nums1.end());    
     unordered_set<int> set2(nums2.begin(),nums2.end());        
     int count1=0;
     int count2=0;

     for(int i:nums1)
     {
        if(set2.count(i))
        {
            count1++;
        }
     }

     for(int i:nums2)
     {
        if(set1.count(i))
        {
            count2++;
        }
     }

     return {count1,count2};
    }
};