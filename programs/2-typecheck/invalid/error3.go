//semantic error: redeclare a type in the same scope

package fault3
func main() {
	type wrong int
	type wrong string
}
