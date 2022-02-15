package leetcode

func maximumGap(nums []int) int {
    if (len(nums) < 2) {
        return 0
    }
	nums = quicksort(nums, 0, len(nums)-1)
	max := 0
	for i := 1; i < len(nums);  i++ {
		if (nums[i] - nums[i-1] > max) {
			max = nums[i] - nums[i-1]
		}
	}
	return max
}

func divide(nums []int, low int, high int) int {
	pivot := nums[low]
	for low < high {
		for low < high && nums[high] >= pivot {
			high--
		}
		if (low < high) {
			temp := nums[low]
			nums[low] = nums[high]
			nums[high] = temp
		}
		for low < high && nums[low] <= pivot {
			low++
		}
        if (low < high) {
			temp := nums[low]
			nums[low] = nums[high]
			nums[high] = temp
		}
	}
	nums[low] = pivot
	return low
}

func quicksort(nums []int, low int, high int) []int{
	if (low >= high) {
		return nums
	}
	mid := divide(nums, low, high)
	quicksort(nums, low, mid - 1)
	quicksort(nums, mid + 1, high)
	return nums
}