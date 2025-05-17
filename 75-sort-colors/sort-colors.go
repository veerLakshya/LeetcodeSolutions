func sortColors(nums []int)  {
    r,w,b := 0, 0, 0
    for _ , v := range nums {
        if v == 0 {
            r++;
        }
        if v == 1 {
            w++;
        }
        if v == 2 {
            b++;
        }
    }  
    i := 0
    for {
        if r == 0 {
            break;
        }
        nums[i] = 0
        i++
        r--
    }
    for {
        if w == 0 {
            break;
        }
        nums[i] = 1
        i++
        w--
    }
    for {
        if b == 0 {
            break;
        }
        nums[i] = 2
        i++
        b--
    }
}