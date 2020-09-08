// Invalid program for Rule 4.8.2 Capacity: cap(expr)
// A cap expression is well-typed if expr is well-typed, has type S and S resolves to []T or [N]T. The result has type int.
// The program is invalid because S doesn't resolve to a []T or [N]T.

package error27

type t struct {
	t0 int
}
func main() {
	var x t
	cap(x)
}