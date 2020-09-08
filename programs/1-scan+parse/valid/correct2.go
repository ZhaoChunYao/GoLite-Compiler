package correct2

// Check if a given integer is a perfect number. 
// A perfect number is a positive integer that is equal to the sum of its proper positive divisors excluding the number itself.
func is_perfect(n int) bool{
	var i int = 1
	var sum int = 0

	for i < n {
		if (n % i == 0) {
			sum += i
		}
	}

	if sum == n {
		return true
	} else {
		return false
	}
}

