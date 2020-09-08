// Scanning error: Nested comments which are invalid.

package error2

/* Some comment:
   line 1
   line 2
   line 3
   line 4
   /* nested multiline comment here:
      nested line 1
      nested line 2
   */ 
   not legal!!!
*/

func main() {
	return
}
