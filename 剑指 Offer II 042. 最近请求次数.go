type RecentCounter struct {
	reqs []int
}


func Constructor() RecentCounter {
	return RecentCounter{reqs[]{}}
}


func (this *RecentCounter) Ping(t int) int {
	idx := 0
	for i := 0; i < len(this.reqs); i++ {
		if i >= t - 3000 {
			idx = i
			break
		}
	}
	this.reqs = this.reqs[idx:]
	this.reqs = append(this.reqs, t)
	return len(this.reqs)
}


/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */