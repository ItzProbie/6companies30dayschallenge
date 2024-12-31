class Solution {

    bool isStrictlyInc(int start , int end , vector<int>& nums){

        int prev = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){

            if(i >= start && i <= end)
                continue;

            if(prev >= nums[i])
                return false;

            prev = nums[i];

        }

        return true;
    }

public:
    int incremovableSubarrayCount(vector<int>& nums) {
        
        int cnt = 0;
        int n = nums.size();
        for(int start = 0 ; start < n ; start++){
            for(int end = start ; end < n ; end++){

                if(isStrictlyInc(start , end , nums))
                    cnt++;

            }
        }

        return cnt;

    }
};