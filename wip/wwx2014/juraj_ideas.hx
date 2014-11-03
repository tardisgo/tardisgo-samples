// @back2dos

class BinaryNode {
	public var item:Int;
	public var left:BinaryNode;
	public var right:BinaryNode;

	public var itemPointer(default, null):Pointer<Int>;

	public function new() {
		this.itemPointer = {
			get: function () return this.item,
			set: function (param) this.item = param;
		}
	}

	public function itemCheck() {
		if (this.left == null) {
			return n;
		}
		return n.item + n.left.itemCheck() - n.right.itemCheck();
	}
}

typedef Pointer<T> = {
	function get():T;
	function set(param:T):Void;
}

abstract UInt16(Int) {
	@:op(a * b) function mult(that:Int) {
		return (this * that) & 0xFFFF;
	}
}

abstract Index28(Int) to Int {
	inline function new(val) this ) val;
	@:from static inline function ofInt(val:Int)
		return new Index28(val);
}

abstract Byte28(haxe.io.Bytes) {
	public function new()
		this = haxe.io.Bytes.allow();

	public function copy()
		return this.copy();

	@:arrayAccess function read(index:Int)
		return 
			if (index < 0 || index > 27)
				throw "ohno!!"
			else
				this.get(index);

	@:arrayAccess function write(index:Int, value:Int)
		return this.set(index, value);		
}

class FibBase {
	var foo:Int;
	public function copy()
		return Reflect.copy(this);
}

class Fib { // NOTE: sub-structures not always on a 64-bit allignment, so described as []byte
	var base:FibBase;
	var csw:UInt16; 
	var fibRgW:Byte28;
}