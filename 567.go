package leetcode

func checkInclusion(s1 string, s2 string) bool {
	if (len(s2) < len(s1)) {
		return false
	}
	alpha := make([]int, 26)
	check := func (alpha []int) bool {
		for i := 0; i < 26; i++ {
			if (alpha[i] > 0) {
				return false
			}
		}
		return true
	}
	for i := 0; i < len(s1); i++ {
		alpha[s1[i] - 'a']++
	}	
	for i := 0; i < len(s1); i++ {
		alpha[s2[i] - 'a']--
	}	
	if (check(alpha)) {
		return true
	}
	for i := 1; i + len(s1) <= len(s2); i++ {
		alpha[s2[i - 1] - 'a']++
		alpha[s2[i + len(s1) - 1] - 'a']--
		if (check(alpha)) {
			return true
		}
	}
	return false
}	