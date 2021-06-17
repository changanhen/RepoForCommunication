package main

import (
	"fmt"
)

func main()  {
	var str = "http://www.runoob.com:80/html/html-tutorial.html"
	var patt1 = /(\w+):\/\/([^/:]+)(:\d*)?([^# ]*)/
	arr = str.match(patt1)
	for (var i = 0; i < arr.length ; i++) {
		document.write(arr[i]);
		document.write("<br>");
	}
}