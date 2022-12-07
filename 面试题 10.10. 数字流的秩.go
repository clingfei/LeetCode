package leetcode

type StreamRank struct {
	m map[int]int
}


func Constructor() StreamRank {
	res := StreamRank{}
	res.m = make(map[int]int)
	return res
}


func (this *StreamRank) Track(x int)  {
	this.m[x] += 1
}


func (this *StreamRank) GetRankOfNumber(x int) int {
	res := 0
	for k, v := range this.m {
		if k <= x {
			res += v
		}
	}
	return res
}


/**
 * Your StreamRank object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Track(x);
 * param_2 := obj.GetRankOfNumber(x);
 */