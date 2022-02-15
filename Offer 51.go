package leetcode

func reversePairs(nums []int) int {
	return mergeSort(nums, 0, len(nums)-1)
}

func mergeSort(nums []int, low, high int) int {
	if low >= high {
		return 0
	} 
	cnt := 0
	mid := (low + high) / 2
	cnt += mergeSort(nums, low, mid)
	cnt += mergeSort(nums, mid + 1, high)
	temp := make([]int, high - low + 1)
    i, j := low, mid + 1
	id := 0
	for ; i <= mid && j <= high; {
		if nums[i] > nums[j] {
			cnt += mid - i + 1
			temp[id] = nums[j]
			j++			
		} else {
			temp[id] = nums[i]
			i++
		}
		id++
	}
	for ; i <= mid; i++{
		temp[id] = nums[i]
		id++
	}
	for ; j <= high; j++ {
		temp[id] = nums[j]
		id++
	}
	copy(nums[low: high + 1], temp)

    return cnt
}