package ;

@:cppFileCode('extern "C" int gogo; extern "C" int Myadd(int a, int b);')

class Gogo {
	public static function add(a:Int,b:Int):Int {
		return untyped __cpp__("Myadd(a,b)");
	}
	public static function get():Int 
	{
		return untyped __cpp__("gogo");
	}
	public static function set(v:Int) 
	{
		untyped __cpp__("gogo=v");
	}
}