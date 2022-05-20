/*
 * @lc app=leetcode.cn id=462 lang=golang
 *
 * [462] 最少移动次数使数组元素相等 II
 */
package leetcode

import (
	"time"
	"math/rand"
	"sort"
)
// @lc code=start

func abs(num int) int {
	if num < 0 {
		return -num
	} else {
		return num
	}
}

func minMoves2(nums []int) int {
	if len(nums) == 1 {
		return 0
	}
	//sort.Ints(nums)
	mid := quickSelect(nums, len(nums) / 2 + 1)
	res := 0
	for _, k := range nums {
		res += abs(mid - k)
	}
	return res
}

func quickSelect(nums []int, k int) int {
	rand.Seed(time.Now().UnixNano())
	return quickSort(nums, k, 0, len(nums)-1)
}

func quickSort(nums []int, k int, low int, high int) int {
	mid := divide(nums, low, high)
	if mid == k-1 {
		return nums[mid]
	} else if mid < k-1 {
		return quickSort(nums, k, mid+1, high)
	} else {
		return quickSort(nums, k, low, mid-1)
	}
}

func divide(nums []int, low int, high int) int {
	i := rand.Intn(high-low+1) + low
	nums[low], nums[i] = nums[i], nums[low]
	pixos := nums[low]
	for low < high {
		for low < high && nums[high] > pixos {
			high--
		}
		if low < high {
			nums[low] = nums[high]
			low++
		}
		for low < high && nums[low] < pixos {
			low++
		}
		if low < high {
			nums[high] = nums[low]
			high--
		}
	}
	nums[low] = pixos
	return low
}
// @lc code=end

