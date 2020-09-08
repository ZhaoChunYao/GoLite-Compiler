// Invalid program for Rule 4.7 Field selection: expr.id
// Selecting a field in a struct is well-typed if expr is well-typed and has type S; and S resolves to a struct type that has a field named id.
// The program is invalid because S doesn't have a field named id.

package error24

type person struct {
	name string
	age int
}

func main() {
	var a_person person
	a_person.name = "David"
	a_person.gender = "F"	// invalid
}