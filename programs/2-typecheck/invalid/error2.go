//semantic error: redeclare a variable in the same scope
package fault2
func main(){
	var x int=0
	var x string="something"
}
