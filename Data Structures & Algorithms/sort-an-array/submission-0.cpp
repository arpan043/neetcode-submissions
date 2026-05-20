class Solution {
public:

    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[start];
        int left = start + 1;
        int right = end;

        while(left <= right){
            while(left <= end && nums[left] < pivot) 
                left++;
            while(right >= start && nums[right] > pivot)
                right--;
            
            if(left < right){
                swap(nums[left++], nums[right--]);
            } else break;
        }
        swap(nums[start], nums[right]);
        return right;
    }
    void quickSort(vector<int>& nums, int start, int end){
        if(start >= end)
            return;

        int pivot = partition(nums, start, end);

        quickSort(nums,start,pivot - 1);
        quickSort(nums,pivot+1,end);

    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};