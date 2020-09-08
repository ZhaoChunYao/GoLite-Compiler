// Invalid program for Rule 4.6 Indexing expr[index] in specifications: Indexing into a slice or an array is well-typed if expr is well-typed and resolves to []T or [N]T; and index is well-typed and resolves to int.
// The program is invalid because index resolves to float64 and doesn't resolve to type int.

package error23
func main() {
	var arr [100]string
	arr[3.2] ++
}
