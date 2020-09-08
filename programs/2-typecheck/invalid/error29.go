// Invalid program for Rule 4.9 Type cast: type(expr)
// A type cast expression is well-typed if:
// type resolves to a base type int, float64, bool, rune or string; 
// expr is well-typed and has a type that can be be cast to type:
// 	1. type and expr resolve to identical underlying types;
//	2. type and expr both resolve to numeric types;
//	3. type resolves to a string type and expr resolves to an integer type (rune or int)

// The program is invalid because type doesn't resolve to a base type.
package error29

type arr []int

func main() {
	var x []int
	var y = arr(x)
}