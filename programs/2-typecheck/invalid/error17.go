//semantic error: try to access a variable that is out of scope
package fault17
func main(){
	for(){
		var x int=0;
	}
	print(x);
}
