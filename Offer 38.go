package leetcode

func permutation(s string) []string {
	set := make(map[string]bool)
	var res *[]string
	isVisited := make([]bool, len(s))
	var temp []byte
	for i := 0; i < len(s); i++ {
		temp = append(temp, s[i])
		isVisited[i] = true
		backtracing(res, s, isVisited, temp, set)
		isVisited[i] = false
		temp = temp[:len(temp)-1]
	}
	return *res
}

func backtracing(res *[]string, s string, isVisited []bool, temp []byte, set map[string]bool) {
	if (len(temp) == len(s)) {
		if _, ok := set[string(temp)]; !ok {
			*res = append(*res, string(temp))
			set[string(temp)] = true
		}
		return
	}
	for i := 0; i < len(s); i++ {
		if !isVisited[i] {
			temp = append(temp, s[i])
			isVisited[i] = true
			backtracing(res, s, isVisited, temp, set)
			isVisited[i] = false
			temp = temp[:len(temp) - 1]
		}
	}
}