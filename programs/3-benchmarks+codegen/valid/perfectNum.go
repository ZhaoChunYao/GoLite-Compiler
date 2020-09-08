// Find the perfect square numbers below 5000000
package main

func isPerfectSquare(n int) bool{
	for x:=1;x<n;x++{
		if(x*x == n){
			return true
		}
	}
	return false
}

func main() {
	var perfect int = 1
        for x:= 1;x<5000000;x++ {
          if(isPerfectSquare(x)){
		perfect = x
	  	println(perfect)
	  }
        }
}
