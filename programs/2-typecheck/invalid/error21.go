// Invalid program for Rule 4.4 in specifications: A binary expression is well-typed if its sub-expressions are well-typed, are of the same type and that type resolves to a type appropriate for the operation.
// The lhs and rhs of a binary expression doesn't have the same type, so the binary expression doesn't type check.

package error21
func main() {
	var x float64 = 3 + 3.4
}
