/*
 * @lc app=leetcode.cn id=1357 lang=golang
 *
 * [1357] 每隔 n 个顾客打折
 */
package leetcode
// @lc code=start
type Cashier struct {
	num       int
	cousNum   int
	disciunt  int
	pricesMap map[int]int
}

func Constructor(n int, discount int, products []int, prices []int) Cashier {
	var res = Cashier{
		num:       n,
		cousNum:   0,
		disciunt:  discount,
		pricesMap: make(map[int]int, 10),
	}
	lenth := len(products)
	for i := 0; i < lenth; i++ {
		res.pricesMap[products[i]] = prices[i]
	}
	return res
}

func (this *Cashier) GetBill(product []int, amount []int) float64 {
	lenth := len(product)
	var sum = 0
	for i := 0; i < lenth; i++ {
		sum += amount[i] * this.pricesMap[product[i]]
	}
	var res float64
	this.cousNum++
	if this.cousNum%this.num == 0 {
		res = float64(sum) * float64(100-this.disciunt) / 100
	} else {
		res = float64(sum)
	}
	return res
}

/**
 * Your Cashier object will be instantiated and called as such:
 * obj := Constructor(n, discount, products, prices);
 * param_1 := obj.GetBill(product,amount);
 */
// @lc code=end

