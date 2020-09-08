//semantic error: field name doesn't exits
package fault13
func main() {
	var x struct{
		y int
	}
	print(x.z)
}
