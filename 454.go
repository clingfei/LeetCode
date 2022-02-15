package leetcode

import "sort"

func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
	sort.Ints(nums1)
	sort.Ints(nums2)
	sort.Ints(nums3)
	umap := make(map[int]int)
	for i := 0; i < len(nums4); i++ {
		for j := 0; j < len(nums3); j++ {
			umap[nums4[i] + nums3[j]]++
		}
	}
	cnt := 0
	for i := 0; i < len(nums1); i++ {
		for j := 0; j < len(nums2); j++ {
			cnt += umap[-(nums1[i] + nums2[j])]
		}
	}
	return cnt
}