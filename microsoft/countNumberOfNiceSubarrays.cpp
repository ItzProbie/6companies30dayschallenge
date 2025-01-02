class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();

        int start = 0 , end = 0;
        int ans = 0 , odd = 0;
        while(end < n){

            if(nums[end]%2 != 0)
                odd++;

            if(odd == k){

                int left = 1 , right = 1;
                while(nums[start]%2 == 0){
                    left++ , start++;
                }
                end++;
                while(end < n && nums[end]%2 == 0){
                    end++ , right++;
                }

                //number of possible starting points * number of possible ending points

                ans += left*right;
                start++;
                odd--;
            }
            else
                end++;

        }
        return ans;
    }
};