// Invalid program for Rule 4.5: The special function init may not be called as a function call.
// The program is invalid because the special function init may not be called as a function call.
package error22
func init() {
	var a, b, c int = 1, 2, 3
}
func main() {
	init()
}
