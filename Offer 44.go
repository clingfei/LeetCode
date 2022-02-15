package leetcode

import "math"

func findNthDigit(n int) int {
	if n <= 9 {
		return n
	}
	n -= 9
	count, dig := 90, 2
	for n > count*dig {
		n -= count * dig
		count *= 10
		dig++
	}
	num := int(math.Pow10(dig - 1)) + n / dig
	if n % dig == 0 {
		num--
		return num % 10
	} else {
		for i := 0; i < (dig - n % dig); i++ {
			num /= 10
		}
		return num % 10
	}
}