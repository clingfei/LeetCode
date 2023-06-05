package leetcode

func replaceSpace(s string) string {
	res := ""
	for _, v := range s {
		if v != ' ' {
			res += string(v)
		} else {
			res += "%20"
		}
	}
	return res
}