package correct2

// Check if a given integer is a perfect number. 
// A perfect number is a positive integer that is equal to the sum of its proper positive divisors excluding the number itself.
func main() {

}

func is_perfect(n int){
	var i int = 1
	var sum int = 0
	
	for b:=0;b < n;b++ {
		if (n % i == 0) {
			sum += i
		}
		i ++;
	}

	
	if c:=0;sum == n {
		print(c);
		var str string=""
	} else {
		
	}

	switch d:=100;d{
		case 0:
			d++
		case 100:
			d--
	}

}

