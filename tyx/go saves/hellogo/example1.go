package main

import (
	"fmt"
	"log"
	"math"
	"os"
)

func init() {
	file := "./" + "message" + ".txt"
	logFile, err := os.OpenFile(file, os.O_RDWR|os.O_CREATE|os.O_APPEND, 0766)
	if err != nil {
		panic(err)
	}
	log.SetOutput(logFile) // 将文件设置为log输出的文件
	log.SetPrefix("[qSkipTool]")
	log.SetFlags(log.LstdFlags | log.Lshortfile | log.LUTC)
	return
}

func main() {
	fmt.Println("int8 range:", math.MinInt8, math.MaxInt8)
	fmt.Println("int16 range:", math.MinInt16, math.MaxInt16)
	fmt.Println("int32 range:", math.MinInt32, math.MaxInt32)
	fmt.Println("int64 range:", math.MinInt64, math.MaxInt64)
	var a int32 = 1047483647
	fmt.Printf("int32: 0x%x %d\n", a, a)
	b := int16(a)
	fmt.Printf("int16: 0x%x %d\n", b, b)
	var c float32 = math.Pi
	fmt.Println(int(c))
	var i float64 = 1
	var f float64 = 0
	f = math.Pow(-1, i-1) / (2*i - 1)
	var sum float64 = 0
	sum = sum + f
	var d float64 = 0
	d = math.Pi - sum
	for {

		i = i + 1
		f = math.Pow(-1, i-1) / (2*i - 1)
		sum = sum + f
		d = math.Pi - sum
		log.Println("Calculating...: ", 4*sum)
		if d < 1e-5 {
			break
		}
	}
	return
}
