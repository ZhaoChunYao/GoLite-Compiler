//generate harmonic series upto n terms

package harmonic

func f(n int){
        print("The Harmonic Series is: ")
        var result float64=0.0
        for n>0{
                result=result+1/n
                n=n-1
                print(result+" ")
        }
}
