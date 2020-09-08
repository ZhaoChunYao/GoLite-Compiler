// Parsing error: Invalid if else statement. There shouldn't be condition expression on the else branch!

package error6

func main() {
    if 1 == 2 {
        println("ok")
    } else 1 == 3 { // conditioning the else is invalid
        println("error")
    }
    return 
}
