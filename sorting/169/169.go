func majorityElement(nums []int) int {
	curr := nums[0]
	cnt := 1
	for i := 1; i < len(nums); i++ {
		if cnt == 0 {
			curr = nums[i]
			cnt = 1
		} else {
			if nums[i] == curr {
				cnt++
			} else {
				cnt--
			}
		}
		if cnt > len(nums)/2 {
			return curr
		}
	}
	return curr
}