// Invalid program for Rule 4.8.1 Append: append(e1, e2)
// An append expression is well-typed if e1 is well-typed, has type S and S resolves to a []T; and e2 is well-typed and has type T.
// The program is invalid because S doesn't resolve to a []T.

package error26


func main() {
	var arr []bool
	append(arr, 3)
}