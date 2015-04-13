package ;

import tardis.*; // import the generated Go code

class Main {
 	public static function main(){
		trace("Go 'math' and 'strconv' standard library trivial example");
		// for documentation see http://golang.org/pkg/math and http://golang.org/pkg/strconv
		// math.Nextafter returns the next representable float64 value after x towards y. 
		// The built-in Haxe float->string conversions for cpp & cs round the results to "2",
		// so Go formatting was used to give a consistent cross-platform result.
		var na:String = Go_strconv_FFormatFFloat.hx(
			Go_math_NNextafter.hx(2.0,3.0),		
			"g".charCodeAt(0),-1,64);
		trace("The next valid floating point value after 2.0 towards 3.0 is: "+na); // 2.0000000000000004
		na = Go_strconv_FFormatFFloat.hx(
			Go_math_NNextafter.hx(2.0,1.0),
			"g".charCodeAt(0),-1,64);
		trace("The next valid floating point value after 2.0 towards 1.0 is: "+na); // 1.9999999999999998
	}
} 