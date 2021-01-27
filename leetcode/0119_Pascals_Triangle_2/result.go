func getRow(rowIndex int) []int {
    if rowIndex == 0 {
        return []int{1}
    }
    
    prev := []int{1}
    var next []int
    
    for i := 1; i <= rowIndex; i++ {
        next = []int{}
        for j := 0; j <= i; j++ {
            l := 0
            r := 0
            
            if j > 0 {
                l = prev[j-1]
            }
            
            if j < i {
                r = prev[j]
            }
            
            next = append(next, l + r)
        }
        prev = next
    }
                 
    return next
}
