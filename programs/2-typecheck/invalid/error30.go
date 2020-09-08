// Invalid program for Rule 4.9 Type cast: type(expr)
// A type cast expression is well-typed if:
// type resolves to a base type int, float64, bool, rune or string; 
// expr is well-typed and has a type that can be cast to type:
// 	1. type and expr resolve to identical underlying types;
//	2. type and expr both resolve to numeric types;
//	3. type resolves to a string type and expr resolves to an integer type (rune or int)

// The program is invalid because expr doesn't have a type that can be cast to the specified type

package error30

func main() {
	var x bool
	var y = int(x)
}