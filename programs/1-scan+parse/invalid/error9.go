// Scanning error: Invalid raw string litral which contains escape single quote. Raw string shouldn't contain any escape sequences.
package error9

func main() int{
	var s = 'String includs escape single quote\''
	return 1
}

