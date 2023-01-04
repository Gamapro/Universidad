package main

import (
	"fmt"

	"github.com/zellyn/kooky"
	_ "github.com/zellyn/kooky/browser/all" // register cookie store finders!
)

func main() {
	// uses registered finders to find cookie store files in default locations
	// applies the passed filters "Valid", "DomainHasSuffix()" and "Name()" in order to the cookies
	cookies := kooky.ReadCookies(kooky.Valid, kooky.DomainHasSuffix(`google.com`), kooky.Name(`NID`))

	for _, cookie := range cookies {
		fmt.Println(cookie.Domain, cookie.Name, cookie.Value)
	}
 }