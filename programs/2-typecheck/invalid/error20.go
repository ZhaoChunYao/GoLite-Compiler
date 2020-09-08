//type error: wrong function type
package fault20
func try() int{
	return 5
}
func main(){
	var x bool=try()
}
