package ;

@:cppFileCode('extern "C" int Gohaxecpp_Int2Dynamic(int i){return Gohaxecpp_obj::Int2Dynamic(i);};
extern "C" int Gohaxecpp_Dynamic2Int(int d){return Gohaxecpp_obj::Dynamic2Int(d);};')

@:keep
class Gohaxecpp {

	static var dynoArray = new Array<Dynamic>();
	static var dynoNext = 0;
	static var dynoLock = new cpp.vm.Mutex();

	private static inline function create(val:Dynamic):Int {
		dynoLock.acquire();
		dynoNext++;
		var id=dynoNext;
		dynoArray[id]=val;
		dynoLock.release();
		return id;
	}
	private static inline function view(id:Int):Dynamic {
		dynoLock.acquire();
		var r=dynoArray[id];
		dynoLock.release();
		return r;
	}
	private static inline function set(id:Int,val:Dynamic):Void {
		dynoLock.acquire();
		dynoArray[id]=val;
		dynoLock.release();
	}
	private static inline function recycle(id:Int):Void {
		dynoLock.acquire();
		dynoArray[id]=null; // TODO add some recycling method
		dynoLock.release();
	}

	public static function Int2Dynamic(i:Int):Int
	{
		var d:Dynamic=i;
		var id=create(d);
		trace("Int2Dynamic "+i+"=>",id);
		return id;
	}
	public static function Dynamic2Int(d:Int):Int 
	{
		var i:Int=view(d);
		trace("Dynamic2Int "+d+ "=>"+i);
		return i;
	}
}