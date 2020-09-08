package convert
func binary(x int) string {
        var a int
        if x>0 {
                a=x%2
                return (binary(y/2)+""+a)
        }
        return "";
}
