// This program print out the prime numbers from 2 to 150000.
// Total runtime is 6.461397084s.
 
package main

//import "time"
//import "fmt"

func isPrime(n int) bool{
	for i:=2; i<n; i++ {
		if (n%i) == 0 {
			return false;
		}
	}
    	return true;
}

//This program calculates all the primes below 1 million
func main() {
	//start := time.Now()	
	println("The prime numbers below 150000 are: ")
	for i:=2; i<150000; i++ {
		if(isPrime(i)){
			println(i)
                }
	}
	//elapsed := time.Since(start)
	//fmt.Println("Toatal runtime is %s", elapsed)
}
