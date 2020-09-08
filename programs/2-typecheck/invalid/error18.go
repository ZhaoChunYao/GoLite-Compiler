//type error: case expression has different type from switch expression
package fault18
func main(){
	var x int=0
	switch x{
	case 0:
		break
	case true:
		break
	}
}
