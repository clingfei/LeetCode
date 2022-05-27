/*
 * @lc app=leetcode.cn id=2034 lang=golang
 *
 * [2034] 股票价格波动
 */
package leetcode

import (
	"container/heap"
)

// @lc code=start

type StockPrice struct {
    maxTime int
    timeMap map[int]int
    maxPrice, minPrice IntHeap
}


func Constructor() StockPrice {
    return StockPrice{timeMap:map[int]int{}}
}


func (this *StockPrice) Update(timestamp int, price int)  {
    if this.maxTime < timestamp {
        this.maxTime = timestamp
    }
    this.timeMap[timestamp] = price
    heap.Push(&this.maxPrice, []int{-price, timestamp})
    heap.Push(&this.minPrice, []int{price, timestamp})
}


func (this *StockPrice) Current() int {
    return this.timeMap[this.maxTime]
}


func (this *StockPrice) Maximum() int {
    for {
        cur := heap.Pop(&this.maxPrice).([]int)
        v := this.timeMap[cur[1]]
        if v == -cur[0] {
            heap.Push(&this.maxPrice, cur)
            return v
        }
    }
}


func (this *StockPrice) Minimum() int {
    for {
        cur := heap.Pop(&this.minPrice).([]int)
        v := this.timeMap[cur[1]]
        if v == cur[0] {
            heap.Push(&this.minPrice, cur)
            return v
        }
    }
}


/**
 * Your StockPrice object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Update(timestamp,price);
 * param_2 := obj.Current();
 * param_3 := obj.Maximum();
 * param_4 := obj.Minimum();
 */

type IntHeap [][]int
func (h IntHeap) Len() int{return len(h)}
func (h IntHeap) Less(i, j int) bool{return h[i][0] < h[j][0]}
func (h IntHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i]}
func (h *IntHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n - 1]
    *h = old[0 : n - 1]
    return x
}
func (h *IntHeap) Push(x interface{}) {
    *h = append(*h, x.([]int))
}

// @lc code=end

