class Solution {
    public int bin_search(int[] nums, int target, int si, int ei) {
        if (si > ei) return -1;

        int mid = si + (ei - si) / 2;
        if (nums[mid] == target) return mid;

        // Left half is sorted
        if (nums[si] <= nums[mid]) {
            if (nums[si] <= target && target < nums[mid]) {
                return bin_search(nums, target, si, mid - 1);
            } else {
                return bin_search(nums, target, mid + 1, ei);
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[ei]) {
                return bin_search(nums, target, mid + 1, ei);
            } else {
                return bin_search(nums, target, si, mid - 1);
            }
        }
    }

    public int search(int[] nums, int target) {
        return bin_search(nums, target, 0, nums.length - 1);
    }
}