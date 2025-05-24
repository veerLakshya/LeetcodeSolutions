func findWordsContaining(words []string, x byte) []int {
    ans := []int{}
    for i,v := range words {
        for _, y := range v {
            if x == byte(y) {
                ans = append(ans, i)
                break
            }
        }
    }
    return ans
}