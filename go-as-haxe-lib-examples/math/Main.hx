package ;

import tardis.*; // import the generated Go code

class Main {
 	public static function main(){
		trace("Go 'math' and 'strconv' standard library trivial example");
		// for documentation see http://golang.org/pkg/math and http://golang.org/pkg/strconv
		
		// math.Nextafter returns the next representable float64 value after x towards y. 
		var na2to3=Go_math_NNextafter.hx(2.0,3.0);
		var na2to1=Go_math_NNextafter.hx(2.0,1.0);

		// The Std.string() float->string conversions for cpp & cs round the results to "2",
		// so Go formatting is used to give a consistent cross-platform result.
		trace("The next valid floating point value after 2.0 towards 3.0 is: "+
			Go_strconv_FFormatFFloat.hx(na2to3,"g".charCodeAt(0),-1,64)); // 2.0000000000000004
		trace("The next valid floating point value after 2.0 towards 1.0 is: "+
			Go_strconv_FFormatFFloat.hx(na2to1,"g".charCodeAt(0),-1,64)); // 1.9999999999999998
	}
} 