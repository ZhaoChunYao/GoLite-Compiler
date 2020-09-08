package correct1
// Calculate GCD of two input integers.
func gcd(x, y int) int {
	var i = 1
	for i <= x && i <= y {
		var mod1 = x % i
		var mod2 = y % i
		if mod1 == 0 && mod2 == 0 {
			return i
		}
		i ++
	}
}
