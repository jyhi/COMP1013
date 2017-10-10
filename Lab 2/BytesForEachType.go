package main

import (
	"fmt"
	"unsafe"
)

func main() {
	/* Go basic data types:
	 *
	 * bool
	 *
	 * string
	 *
	 * int  int8  int16  int32  int64
	 * uint uint8 uint16 uint32 uint64 uintptr
	 *
	 * byte // alias for uint8
	 *
	 * rune // alias for int32
	 *      // represents a Unicode code point
	 *
	 * float32 float64
	 *
	 * complex64 complex128
	 *
	 * https://tour.golang.org/basics/11
	 */
  /* Go fmt docs: https://golang.org/pkg/fmt/ */
	fmt.Printf("Number of bytes used to store a bool type variable is %v\n", unsafe.Sizeof(bool))
	fmt.Printf("Number of bytes used to store a byte type variable is %v\n", unsafe.Sizeof(byte))
	fmt.Printf("Number of bytes used to store a rune type variable is %v\n", unsafe.Sizeof(rune))
	fmt.Printf("Number of bytes used to store an int type variable is %v\n", unsafe.Sizeof(int)) // ILP64
	fmt.Printf("Number of bytes used to store a uint type variable is %v\n", unsafe.Sizeof(uint))
	fmt.Printf("Number of bytes used to store a uintptr type variable is %v\n", unsafe.Sizeof(uintptr))
	fmt.Printf("Number of bytes used to store a string type variable is %v\n", unsafe.Sizeof(string))
}
