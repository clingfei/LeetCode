package leetcode

func luckyNumbers (matrix [][]int) []int {
	row := make([]int, len(matrix))
	col := make([]int, len(matrix[0]))
	for i := 0; i < len(matrix); i++ {
		min := matrix[i][0]
		for j := 1; j < len(matrix[0]); j++ {
			if (matrix[i][j] < min) {
				min = matrix[i][j]
			}
		}
		row[i] = min
	}
	for i := 0; i < len(matrix[0]); i++ {
		max := 0
		for j := 0; j < len(matrix); j++ {
			if (matrix[j][i] > max) {
				max = matrix[j][i]
			}
		}
		col[i] = max
	}
	var res []int
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			if (matrix[i][j] == row[i] && matrix[i][j] == col[j]) {
				res = append(res, matrix[i][j])
			}
		}
	}
	return res
}