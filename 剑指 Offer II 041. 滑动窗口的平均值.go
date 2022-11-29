type MovingAverage struct {
	size int
	window []int
	sum  int
}


/** Initialize your data structure here. */
func Constructor(size int) MovingAverage {
	return MovingAverage{size, []int{}, 0}
}


func (this *MovingAverage) Next(val int) float64 {
	if len(this.window) < this.size() {
		this.window = append(this.window, val)
		this.sum += val
	} else {
		this.sum -= this.window[0]
		this.window = this.window[1:]
		this.window = append(this.window, val)
		this.sum += val
	}
	return float64(this.sum) / this.size
}


/**
 * Your MovingAverage object will be instantiated and called as such:
 * obj := Constructor(size);
 * param_1 := obj.Next(val);
 */