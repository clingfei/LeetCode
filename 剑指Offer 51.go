package leetcode

func reversePairs(nums []int) int {
	return mergeSort(nums, 0, len(nums))
}

func mergeSort(nums []int, low, high int) int {
	if low >= high - 1 {
		return 0
	}
	mid := (high + low) / 2
	res := 0
	res += mergeSort(nums, low, mid)
	res += mergeSort(nums, mid, high)
	temp := make([]int, high - low)
	k := 0
	i, j := low, mid
	for i < mid && j < high  {
		if nums[i] > nums[j] {
			res += mid - i
			temp[k] = nums[j]
			j, k = j + 1, k + 1
		} else {
			temp[k] = nums[i]
			i, k = i + 1, k + 1
		}
	} 
	for i < mid {
		temp[k] = nums[i]
		i, k = i + 1, k + 1
	}
	for j < high {
		temp[k] = nums[j]
		j, k = j + 1, k + 1
	}
	copy(nums[low:high], temp)
	return res
} 