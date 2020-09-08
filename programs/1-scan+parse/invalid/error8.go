// Parsing error: Invalid syntex of for statement. Too many statements and expressions after for.

package error8

func main() {
	for i := 0; i < 10; i >8; i ++ {
		println("error")
	}
	return
}
