package Leetcode
func oneEditAway(first string, second string) bool {
	if len(first) - len(second) > 1 || len(first) - len(second) < -1 {
		return false
	}
	r := 1;
	for i, j := 0, 0; i < len(first) && j < len(second); {
		if first[i] == second[j] {
			i++
			j++
		} else if r == 0 {
			return false
		} else if i == len(first) - 1 || j == len(second) - 1 {
			if i == len(first) - 1 && j == len(second) -1 {
				return true
			} else {
				return false
			}
		} else if first[i + 1] == second[j] {
			if len(first) == len(second) + 1 {
				i++
				r--
			} else {
				return false
			}
		} else if first[i] == second[j + 1] {
			if len(first) == len(second) - 1{
				j++
				r--
			} else {
				return false
			}
		} else {
			if len(first) == len(second) {
				r--
				i++
				j++
			} else {
				return false
			}
		}
	} 
	return true
}