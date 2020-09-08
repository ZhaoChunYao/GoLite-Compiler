//type error: apply selector on non struct type
package fault12
func main(){
	var x int
	print(x.field1)
}
