//Check if some one can vote
package valid

type person struct{
	age, vote int
	name string
}

func canVote(person p){
	if p.age>=18{
		println("You can vote!");
	}else{
		println("Sorry!");
	}
	return;
}

func main(){
	var sam person;
	sam.age = 21;
	sam.name = "Sam";
	sam.vote = 1;
	canVote(sam);
}
