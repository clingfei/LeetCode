package leetcode

func canBeIncreasing(nums []int) bool {
	cnt := 0
	for i := 1; i < len(nums); i++ {
		if (nums[i] <= nums[i-1]) {
			if (i >= 2 && nums[i] <= nums[i-1]) {
				nums[i] = nums[i-1]
			}
			cnt++
			if (cnt > 1) {
				return false
			}
		}
	}
	return true;
}