//check number is prime
package valid

type num int
func checkPrime(num n) int{
	for i:=0;i<n;i++{
		if n%i == 0{
			return 0;
		}
	}
	return 1;
}

func main(){
	var n num = 29;
	if x=checkPrime(29);x==0{
		println("Yes");
	}else if x==1{
		println("No");
	}
}
