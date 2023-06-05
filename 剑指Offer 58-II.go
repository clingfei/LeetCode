package leetcode

func reverseLeftWords(s string, n int) string {
	bytes := []byte(s)
	reverse(bytes, 0, n)
	reverse(bytes, n, len(bytes))
	reverse(bytes, 0, len(bytes))
	return string(bytes)
}

func reverse(s []byte, left, right int) {
	i, j := left, right - 1
	for i < j {
		temp := s[i]
		s[i] = s[j]
		s[j] = temp
	}
}

