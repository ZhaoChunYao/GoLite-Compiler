// Bubble sort an array with large size.
// Total runtime: 5.311313313s

package main

//import "time"
//import "fmt"

var SIZE int = 100000

func random(n int) int {
	return (9*n+7)%100000
}

func printArr(arr [100000]int) {
	for i:= 0; i < 100000; i ++ {
		print(arr[i])
		print(" ")
	}
	println()
}

func bubbleSort(arr [100000]int) [100000]int{
	for i := 0; i < cap(arr) - 1; i ++ {
		for j := 0; j < cap(arr) - i - 1; j ++ {
			if arr[j] > arr[j + 1] {
				temp := arr[j]
				arr[j] = arr[j + 1]
				arr[j + 1] = temp
			}
		}
 	}
	return arr
}

func main() {
	
	//start := time.Now()
	
	var arr [100000]int
	
	println("Generate an array of 100000 random numbers.")
	for i := 0; i < SIZE; i ++ {
		arr[i] = random(i)
	}
	
	println("Begin bubble sort.")
	println("The initial array is: ")
	printArr(arr)
	
	sorted := bubbleSort(arr)
	
	println("Finish bubble sort.")
	println("The sorted array is: ")
	printArr(sorted)
	
	//elapsed := time.Since(start)
	//fmt.Println("Total runtime is %s", elapsed)
	
}
