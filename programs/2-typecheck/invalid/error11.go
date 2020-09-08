//type error: index type not int
package fault11
func main() {
	var x [3]int
	x[true]
}
