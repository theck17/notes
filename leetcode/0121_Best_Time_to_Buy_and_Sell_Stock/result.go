func maxProfit(prices []int) int {    
    i := 0
    min := prices[i]
    maxDiff := 0
    
    for i = 1; i < len(prices); i++ {
        if prices[i] < min {
            min = prices[i]
        } else {
            diff := prices[i] - min
            if diff > maxDiff {
                maxDiff = diff
            }
        }
    }
    
    return maxDiff
}
