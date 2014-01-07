package tardis;


//**** START CODE COPY from https://gist.github.com/Asmageddon/4013485 
// * ...
// * @author Asmageddon

class Deep { // TODO this should not be a separate haxe class, as no non-pogo code needs access to it
	//** 
	//** Deep copy of anything using reflection (so don't hope for much performance)
	//** 
	public static function copy( v:Dynamic ) : Dynamic  { 	//***** new line was: public static function copy<T>( v:T ) : T  { 
		if (!Reflect.isObject(v)) { // simple type 
			return v; 
		}
		else if (Std.is(v, String)) { // string
			return v;
		}
		else if (Std.is(v, Pointer)) { // Pointer *** new code
			return Pointer.copy(v);
		}
		else if (Std.is(v, Closure)) { // Closure *** new code
			return v;
		}
		//else if (Std.is(v, Channel)) { // Channel *** new code
		//	return v;
		//}
		else if(Std.is( v, Array )) { // array 
			var result = Type.createInstance(Type.getClass(v), []); 
			untyped { 
				for( ii in 0...v.length ) {
					result.push(copy(v[ii]));
				}
			} 
			return result;
		}
		/**** Hash & IntHash replaced by Map in Haxe3
		else if(Std.is( v, Hash )) { // hashmap
			var result = Type.createInstance(Type.getClass(v), []);
			untyped {
				var keys : Iterator<String> = v.keys();
				for( key in keys ) {
					result.set(key, copy(v.get(key)));
				}
			} 
			return result;
		}
		else if(Std.is( v, IntHash )) { // integer-indexed hashmap
			var result = Type.createInstance(Type.getClass(v), []);
			untyped {
				var keys : Iterator<Int> = v.keys();
				for( key in keys ) {
					result.set(key, copy(v.get(key)));
				}
			} 
			return result;
		}
		****/
		else if(Std.is( v, Map )) { // **** this code section written new - TODO: test
			var result = Type.createInstance(Type.getClass(v), []);
			untyped {
				var keys : Iterator<Dynamic> = v.keys();
				for( key in keys ) {
					result.set(key, copy(v.get(key)));
				}
			} 
			return result;
		} //*** end new code
		else if(Std.is( v, List )) { // list
			//List would be copied just fine without this special case, but I want to avoid going recursive
			var result = Type.createInstance(Type.getClass(v), []);
			untyped {
				var iter : Iterator<Dynamic> = v.iterator();
				for( ii in iter ) {
					result.add(ii);
				}
			} 
			return result; 
		}
		else if(Type.getClass(v) == null) { // anonymous object 
			var obj : Dynamic = {}; 
			for( ff in Reflect.fields(v) ) { 
				Reflect.setField(obj, ff, copy(Reflect.field(v, ff))); 
			}
			return obj; 
		} 
		else { // class 
			var obj = Type.createEmptyInstance(Type.getClass(v)); 
			for(ff in Reflect.fields(v)) {
				Reflect.setField(obj, ff, copy(Reflect.field(v, ff))); 
			}
			return obj; 
		} 
		// return null;  //**** commented out to remove an unreachable code error 
	}
 
}
//END CODE COPY ****/

class Force { // TODO maybe this should not be a separate haxe class, as no non-pogo code needs access to it
	public static inline function toUint8(v:Int):Int {
		return v & 0xFF;
	}	
	public static inline function toUint16(v:Int):Int {
		return v & 0xFFFF;
	}	
	public static inline function toUint32(v:Int):Int { 
		#if js
			// return v | 0; // this is the emscripten technique to force values to int, it is shorter, but does it always work for uint32?
			return v & untyped __js__("0xffffffff"); // the obvious solution
		#elseif php
       		return v & untyped __php__("0xffffffff");
		#else
			return v; 
		#end
	}	
	public static inline function toUint64(v:GOint64):GOint64 {
		return v;
	}	
	public static function toInt8(v:Int):Int {
		var r:Int = v & 0xFF;
		if ((r & 0x80) != 0){ // it should be -ve
			return -1 - 0xFF + r;
		}
		return r;
	}	
	public static function toInt16(v:Int):Int {
		var r:Int = v & 0xFFFF;
		if ((r & 0x8000) != 0){ // it should be -ve
			return -1 - 0xFFFF + r;
		}
		return r;
	}	
	public static function toInt32(v:Int):Int {
		#if js 
			var int32_mostNeg:Int = -2147483648;
			var r:Int = v & untyped __js__("0x7FFFFFFF");
			if ((v & untyped __js__("0x80000000")) != 0){ // it should be -ve
				return int32_mostNeg+r;				
			}
			return r;
		#elseif php
			//see: http://stackoverflow.com/questions/300840/force-php-integer-overflow
     		v = (v & untyped __php__("0xFFFFFFFF"));
 		    if( (v & untyped __php__("0x80000000")) != 0)
		        v = -((~v & untyped __php__("0xFFFFFFFF")) + 1);
		    return v;
		#else
			return v;
		#end
	}	
	public static inline function toInt64(v:GOint64):GOint64 { // this in case special handling is required for some platforms
		return v;
	}	
	public static inline function toInt(v:Dynamic):Int { // get an Int from a Dynamic variable (uintptr is stored as Dynamic)
		if (!Reflect.isObject(v))  			// simple type, so leave quickly and take defaults 
			return v; 
		else
			if(Std.is(v,Interface)) {
				v=v.val; // it is in an interface, so get the value
				if (!Reflect.isObject(v))  			// simple type from inside an interface, so take defaults 
					return v; 
				else								// it should be an Int64 from inside an Interface
					return GOint64.toInt(v);	
			} else								// it should be an Int64 if not an interface
				return GOint64.toInt(v);	
	}
	public static inline function toFloat(v:Float):Float {
		// neko target platform requires special handling because it auto-converts whole-number Float into Int without asking
		// see: https://github.com/HaxeFoundation/haxe/issues/1282 which was marked as closed, but was not fixed as at 2013.9.6
		#if neko
			if(Std.is(v,Int))
				return v + 2.2251e-308; // add the smallest value possible for a 64-bit float to ensure neko doesn't still think it is an int
			else
				return v;
		#else
			return v;
		#end
	}	
	public static function uintCompare(x:Int,y:Int):Int { // +ve if uint(x)>unint(y), 0 equal, else -ve 
			if(x==y) return 0; // simple case first for speed TODO is it faster with this in or out?
			if(x>=0) {
				if(y>=0){ // both +ve so normal comparison
					return (x-y);
				}else{ // y -ve and so larger than x
					return -1;
				}
			}else { // x -ve
				if(y>=0){ // -ve x larger than +ve y
					return 1;
				}else{ // both are -ve so the normal comparison
					return (x-y); //eg -1::-7 gives -1--7 = +6 meaning -1 > -7
				}
			}
	}
	private static function checkIntDiv(x:Int,y:Int,byts:Int):Int { // implement the special processing required by Go
		var r:Int=y;
		switch(y) {
		case 0:
			Scheduler.panicFromHaxe("attempt to divide integer value by 0"); 
		case -1:
			switch (byts) {
			case 1:
				if(x== -128) r=1; // special case in the Go spec
			case 2:
				if(x== -32768) r=1; // special case in the Go spec
 			case 4:
				if(x== -2147483648) r=1; // special case in the Go spec
			default:
				// noOp
			}
		}
		return r;
	}
	//TODO maybe optimize by not passing the special value and having multiple versions of functions
	public static function intDiv(x:Int,y:Int,sv:Int):Int {
		y = checkIntDiv(x,y,sv);
		if(y==1) return x; // x div 1 is x
		var f:Float=  x / y;
		return f>=0?Math.floor(f):Math.ceil(f);
	}
	public static function intMod(x:Int,y:Int,sv:Int):Int {
		y = checkIntDiv(x,y,sv);
		if(y==1) return 0; // x mod 1 is 0
		return x % y;
	}
	public static function floatDiv(x:Float,y:Float):Float {
		if(y==0.0)
			Scheduler.panicFromHaxe("attempt to divide float value by 0"); 
		return x/y;
	}
	public static function floatMod(x:Float,y:Float):Float {
		if(y==0.0)
			Scheduler.panicFromHaxe("attempt to modulo float value by 0"); 
		return x%y;
	}

	public static function toUTF8length(gr:Int,s:String):Int {
		return "字".length==3 ? s.length : toUTF8slice(gr,s).len(); // no need to unpack the string if already UTF8
	}
	// return the UTF8 version of a UTF16 string in a Slice
	public static function toUTF8slice(gr:Int,s:String):Slice {
		var a:Array<Int> = new Array();
		var mask:Int=0xff; // TODO review if this masking is required, here defensively
		if ( "字".length==1 ) { // needs to be translated from UTF16
			mask=0xffff;
		}				
		for(i in 0...s.length){
				var t:Null<Int>=s.charCodeAt(i) ;
				if(t==null) 
					Scheduler.panicFromHaxe("Haxe runtime Force.toUTF8slice() unexpected null encountered");
				else
					a[i]=cast(t,Int) & mask;
		}
		var sl:Slice = new Slice(new Pointer(a),0,-1);
		if ( "字".length==3 ) return sl; // already UTF8 encoded
		var v1:Slice=Go_haxegoruntime_UTF16toRunes.callFromRT(gr,sl);
		return Go_haxegoruntime_RunesToUTF8.callFromRT(gr,v1);
	}
	public static function toRawString(gr:Int,sl:Slice):String {
		var ret:String="";
		var mask:Int=0xff; // TODO review if this masking is required, here defensively
		if ( "字".length==1 ) { // needs to be translated to UTF16
			var v1:Slice=Go_haxegoruntime_UTF8toRunes.callFromRT(gr,sl);
			sl=Go_haxegoruntime_RunesToUTF16.callFromRT(gr,v1);
			mask=0xffff;
		}
		for(i in 0...sl.len()) {
			ret += String.fromCharCode( sl.getAt(i) & mask );
		}
		return ret;
	}
}

// TODO: consider putting these go-compatibiliy classes into a separate library for general Haxe use when calling Go


@:keep
class UnsafePointer extends Pointer {  // Unsafe Pointers are not yet supported, but Go library code requires that they can be created
	public function new(x:Dynamic){
		super(x);
	}
}

@:keep
class Pointer {
	private var heapObj:Dynamic; // the actual object holding the value
	private var offs:Array<Int>; // the offsets into the object, if any

	public function new(from:Dynamic){
		heapObj = from;
		offs = new Array<Int>();
	}
	public inline function load():Dynamic { 
		// this was intended to return a copy of the object, rather than a reference to it, as in:
		// return Deep.copy(this.ref()); 
		// but seems to work without problem, and significantly more quickly, without this safeguard
		return this.ref(); // TODO review
	}
	public function ref():Dynamic { // this returns a reference to the pointed-at object, not for general use!
		var ret:Dynamic = heapObj;
		for(i in 0...offs.length) 
				ret = ret[offs[i]];
		return ret;	
	}
	public  function store(v:Dynamic){
		if(offs==null) offs=[]; // C# seems to need this for HaxeInt64Typedef values
		switch ( offs.length ) {
		case 0: heapObj=v;
		case 1: heapObj[offs[0]]=v;
		default:
			var a:Dynamic = heapObj;
			for(i in 0...offs.length-1) a = a[offs[i]];
			a[offs[offs.length-1]] = v;
		}
	}
	public function addr(off:Int):Pointer {
		if(off<0 || off >= this.ref().length) Scheduler.panicFromHaxe("index out of range for valid pointer address");
		var ret:Pointer = new Pointer(this.heapObj);
		ret.offs = this.offs.copy();
		ret.offs[this.offs.length]=off;
		return ret;
	}
	public function len():Int { // used by array bounds check (which ocurrs twice as belt-and-braces while we are in beta testing, see above) TODO optimise
		return this.ref().length; 
	}
	public static function copy(v:Pointer):Pointer {
		var r:Pointer = new Pointer(v.heapObj); // no copy of data, just the reference
		r.offs = v.offs.copy();
		return r;
	}
}

@:keep
class Slice {
	private var baseArray:Pointer;
	private var start:Int;
	private var end:Int;
	
	public function new(fromArray:Pointer, low:Int, high:Int) {
		baseArray = fromArray;
		if(baseArray==null) {
			start = 0;
			end = 0;
		} else {
			if(high==-1) high = baseArray.ref().length; //default upper bound is the capacity of the underlying array
			if( low<0 ) Scheduler.panicFromHaxe( "new Slice() low bound -ve"); 
			if( high > baseArray.ref().length ) Scheduler.panicFromHaxe("new Slice() high bound exceeds underlying array length"); 
			if( low>high ) Scheduler.panicFromHaxe("new Slice() low bound exceeds high bound"); 
			start = low;
			end = high;
		}
		//length = end-start;
	} 
	public function subSlice(low:Int, high:Int):Slice {
		if(high==-1) high = this.len(); //default upper bound is the length of the current slice
		return new Slice(baseArray,low+start,high+start);
	}
	public function getAt(dynIdx:Dynamic):Dynamic {
		var idx:Int=Force.toInt(dynIdx);
		if (idx<0 || idx>=(end-start)) Scheduler.panicFromHaxe("Slice index out of range for getAt()");
		if (baseArray==null) Scheduler.panicFromHaxe("Slice base array is null");
		return baseArray.load()[idx+start];
	}
	public function setAt(dynIdx:Dynamic,v:Dynamic) {
		var idx:Int=Force.toInt(dynIdx);
		if (idx<0 || idx>=(end-start)) Scheduler.panicFromHaxe("Slice index out of range for setAt()");
		if (baseArray==null) Scheduler.panicFromHaxe("Slice base array is null");
		baseArray.ref()[idx+start]=v; // this code relies on the object reference passing back
	}
	public inline function len():Int{
		return end-start;
	}
	public function cap():Int {
		if(baseArray==null) return 0;
		return cast(baseArray.ref().length,Int)-start;
	}
	public function addr(dynIdx:Dynamic):Pointer {
		var idx:Int=Force.toInt(dynIdx);
		if (idx<0 || idx>=(end-start)) Scheduler.panicFromHaxe("Slice index out of range for addr()");
		if (baseArray==null) Scheduler.panicFromHaxe("Slice base array is null");
		return baseArray.addr(idx+start);
	}
	public function toString():String {
		var ret:String = "Slice{"+start+","+end+",[";
		if(baseArray!=null) 
			for(i in 0...baseArray.ref().length) {
				if(i!=0) ret += ",";
				ret+=baseArray.ref()[i];
			}
		return ret+"]}";
	}
}

@:keep
class Closure { // "closure" is a keyword in PHP but solved using compiler flag  --php-prefix go  //TODO tidy names
	public var fn:Dynamic; 
	public var bds:Array<Dynamic>;

	public function new(f:Dynamic,b:Array<Dynamic>) {
		if(Std.is(f,Closure))	{
			if(!Reflect.isFunction(f.fn)) Scheduler.panicFromHaxe( "invalid function reference passed to make Closure(): "+f.fn);
			fn=f.fn; 
		} else{
			if(!Reflect.isFunction(f)) Scheduler.panicFromHaxe("invalid function reference passed to make Closure(): "+f); 
	 		fn=f;
		}
		if(fn==null) Scheduler.panicFromHaxe("new Closure() function has become null!"); // error test for flash/cpp TODO remove when issue resolved
		bds=b;
	}
	public function toString():String {
		var ret:String = "Closure{"+fn+",[";
		for(i in 0...bds.length) {
			if(i!=0) ret += ",";
			ret+= bds[i];
		}
		return ret+"]}";
	}
	public function methVal(t:Dynamic,v:Dynamic):Dynamic{
		var tmp:Dynamic = Deep.copy(t);
		return Reflect.callMethod(null, fn, [[],tmp,v]);
	}
	public function callFn(params:Array<Dynamic>):Dynamic {
		if(fn==null) Scheduler.panicFromHaxe("attempt to call null function reference in Closure()");
		if(!Reflect.isFunction(fn)) Scheduler.panicFromHaxe("invalid function reference in Closure(): "+fn);
		return Reflect.callMethod(null, fn, params);
	}
}

class Interface{ // "interface" is a keyword in PHP but solved using compiler flag  --php-prefix go //TODO tidy names 
	public var typ:Int; // the possibly interface type that has been cast to
	public var val:Dynamic;

	public function new(t:Int,v:Dynamic){
		typ=t;
		val=Deep.copy(v); 
	}
	public function toString():String {
		if(val==null)
			return "Interface{null:"+TypeInfo.getName(typ)+"}";
		else
			return "Interface{"+val+":"+TypeInfo.getName(typ)+"}";
	}
	public static function change(t:Int,i:Interface):Interface {
		if(i==null)	
			if(TypeInfo.isConcrete(t)) 
				return new Interface(t,TypeInfo.zeroValue(t)); 
			else {
				Scheduler.panicFromHaxe( "can't change the Interface of a nil value to Interface type: " +TypeInfo.getName(t));  
				return new Interface(t,TypeInfo.zeroValue(t));	 //dummy value as we have hit the panic button
			}
		else 
			if(Std.is(i,Interface)) 	
				if(TypeInfo.isConcrete(t)) 
					return new Interface(t,Deep.copy(i.val)); 
				else
					return new Interface(i.typ,Deep.copy(i.val)); // do not allow non-concrete types for Interfaces
			else {
				Scheduler.panicFromHaxe( "Can't change the Interface of a non-Interface type:"+i+" to: "+TypeInfo.getName(t));  
				return new Interface(t,TypeInfo.zeroValue(t));	 //dummy value as we have hit the panic button
			}
	}
	public static function isEqual(a:Interface,b:Interface):Bool {		// TODO ensure this very wide definition of equality is OK 
		if(a==null) 
			if(b==null) return true;
			else 		return false;
		if(b==null)		
			return false;
		if(! (TypeInfo.isIdentical(a.typ,b.typ)||TypeInfo.isAssignableTo(a.typ,b.typ)||	TypeInfo.isAssignableTo(b.typ,a.typ)) ) 
			return false;
		else
			if(a.val==b.val) 
				return true; // simple equality
			else // could still be equal underneath a pointer    //TODO is another special case required for Slice?
				if(Std.is(a.val,Pointer) && Std.is(b.val,Pointer))
					return a.val.load() == b.val.load();
				else
					return false;	
	}			
	/* from the SSA documentation:
	If AssertedType is a concrete type, TypeAssert checks whether the dynamic type in Interface X is equal to it, and if so, 
		the result of the conversion is a copy of the value in the Interface.
	If AssertedType is an Interface, TypeAssert checks whether the dynamic type of the Interface is assignable to it, 
		and if so, the result of the conversion is a copy of the Interface value X. If AssertedType is a superInterface of X.Type(), 
		the operation will fail iff the operand is nil. (Contrast with ChangeInterface, which performs no nil-check.)
	*/
	public static function assert(assTyp:Int,ifce:Interface):Dynamic{
		if(ifce==null) 
			Scheduler.panicFromHaxe( "Interface.assert null Interface");
		if(!(TypeInfo.isAssignableTo(ifce.typ,assTyp)||TypeInfo.isIdentical(assTyp,ifce.typ))) // TODO review need for isIdentical 
			Scheduler.panicFromHaxe( "type assert failed: expected "+TypeInfo.getName(assTyp)+", got "+TypeInfo.getName(ifce.typ) );
		if(TypeInfo.isConcrete(assTyp))	
			return Deep.copy(ifce.val);
		else	
			return new Interface(ifce.typ,ifce.val);
	}
	public static function assertOk(assTyp:Int,ifce:Interface):{r0:Dynamic,r1:Bool} {
		if(ifce==null) 
			return {r0:TypeInfo.zeroValue(assTyp),r1:false};
		if(!(TypeInfo.isAssignableTo(ifce.typ,assTyp)||TypeInfo.isIdentical(assTyp,ifce.typ))) // TODO review need for isIdentical 
			return {r0:TypeInfo.zeroValue(assTyp),r1:false};
		if(TypeInfo.isConcrete(assTyp))	
			return {r0:Deep.copy(ifce.val),r1:true};
		else	
			return {r0:new Interface(ifce.typ,ifce.val),r1:true};
	}
	public static function invoke(ifce:Interface,meth:String,args:Array<Dynamic>):Dynamic {
		if(ifce==null) 
			Scheduler.panicFromHaxe( "Interface.invoke null Interface"); 
		//trace("Invoke:"+ifce+":"+meth);
		if(!Std.is(ifce,Interface)) 
			Scheduler.panicFromHaxe( "Interface.invoke on non-Interface value"); 
		//return Reflect.callMethod(o:Dynamic, func:Dynamic, args:Array<Dynamic>);
		var fn:Dynamic=TypeInfo.method(ifce.typ,meth);
		//trace("Invoke:"+TypeInfo.getName(ifce.typ)+":"+meth+":"+ifce.val+":"+fn);
		//return fn([],Deep.copy(ifce.val));
		return Reflect.callMethod(null, fn, args);
	}
}

class Channel<T> { //TODO check close & rangeing over a channel
var entries:Array<T>;
var max_entries:Int;
var num_entries:Int;
var oldest_entry:Int;	
var closed:Bool;

public function new(how_many_entries:Int) {
	if(how_many_entries<=0)
		how_many_entries=1;
	entries = new Array<T>();
	max_entries = how_many_entries;
	oldest_entry = 0;
	num_entries = 0;
	closed = false;
}
public function hasSpace():Bool {
	if(this==null) return false; // non-existant channels never have space
	if(closed) return false; // closed channels don't have space
	return num_entries < max_entries;
}
public function send(source:T):Bool {
	if(closed) Scheduler.panicFromHaxe( "attempt to send to closed channel"); 
	var next_element:Int;
	if (this.hasSpace()) {
		next_element = (oldest_entry + num_entries) % max_entries;
		num_entries++;
		entries[next_element]=Deep.copy(source); // we need a full copy in the channel, not just a reference 
		return true;
	} else
		return false;
}
public function hasNoContents():Bool { // used by channel read
	if (this==null) return true; // spec: "Receiving from a nil channel blocks forever."
	if (closed) return false; // spec: "Receiving from a closed channel always succeeds..."
	else return num_entries == 0;
}
public function hasContents():Bool { // used by select
	if (this==null) return false; // spec: "Receiving from a nil channel blocks forever."
	if (closed) return true; // spec: "Receiving from a closed channel always succeeds..."
	return num_entries != 0;
}
public function receive(zero:T):{r0:T ,r1:Bool} {
	var ret:T=zero;
	if (num_entries > 0) {
		ret=entries[oldest_entry];
		oldest_entry = (oldest_entry + 1) % max_entries;
		num_entries--;
		return {r0:ret,r1:true};
	} else
		if(closed)
			return {r0:ret,r1:false}; // spec: "Receiving from a closed channel always succeeds, immediately returning the element type's zero value."
		else {
			Scheduler.panicFromHaxe( "channel receive unreachable code!"); 
			return {r0:ret,r1:false}; //dummy value as we have hit the panic button
		}
}
public inline function len():Int { 
	return num_entries; 
}
public inline function cap():Int { 
	return max_entries; 
}
public inline function close() {
	if(this==null) Scheduler.panicFromHaxe( "attempt to close a nil channel" ); 
	closed = true;
}
}

class Complex {
	public var real:Float;
	public var imag:Float;
public inline function new(r:Float, i:Float) {
	real = r;
	imag = i;
}
public static inline function neg(x:Complex):Complex {
	return new Complex(0.0-x.real,0.0-x.imag);
}
public static inline function add(x:Complex,y:Complex):Complex {
	return new Complex(x.real+y.real,x.imag+y.imag);
}
public static inline function sub(x:Complex,y:Complex):Complex {
	return new Complex(x.real-y.real,x.imag-y.imag);
}
public static inline function mul(x:Complex,y:Complex):Complex {
	return new Complex( (x.real * y.real) - (x.imag * y.imag), (x.imag * y.real) + (x.real * y.imag));
}
public static function div(x:Complex,y:Complex):Complex {
	if( (y.real == 0.0) && (y.imag == 0.0) ){
		Scheduler.panicFromHaxe( "complex divide by zero");
		return new Complex(0.0,0.0); //dummy value as we have hit the panic button
	} else {
		return new Complex(
			((x.real * y.real) + (x.imag * y.imag)) / ((y.real * y.real) + (y.imag * y.imag)) ,
			((x.imag * y.real) - (x.real * y.imag)) / ((y.real * y.real) + (y.imag * y.imag)) );
	}
}
public static inline function eq(x:Complex,y:Complex):Bool { // "=="
	return (x.real == y.real) && (x.imag == y.imag);
}
public static inline function neq(x:Complex,y:Complex):Bool { // "!="
	return (x.real != y.real) || (x.imag != y.imag);
}
}

#if ( cs || java )
	typedef HaxeInt64Typedef = haxe.Int64; // these implementations are using native types
#else
	typedef HaxeInt64Typedef = Int64;  // use the copied and modified version of the standard library class below
	// TODO revert to haxe.Int64 when the version below (or better) finally reaches the released libray
#end

// this abstract type to enable correct handling for Go of HaxeInt64Typedef
abstract HaxeInt64abs(HaxeInt64Typedef) 
from HaxeInt64Typedef to HaxeInt64Typedef 
{ 
inline function new(v:HaxeInt64Typedef) this=v;

public static inline function toInt(v:HaxeInt64abs):Int {
	#if java 
		return HaxeInt64Typedef.toInt(v); // NOTE: java version just returns low 32 bits
	#else
		return HaxeInt64Typedef.getLow(v); // NOTE: does not throw an error if value overflows Int
	#end
}
public static inline function ofInt(v:Int):HaxeInt64abs {
	return new HaxeInt64abs(HaxeInt64Typedef.ofInt(v));
}
public static function toFloat(vp:HaxeInt64abs):Float{ // signed int64 to float (TODO auto-cast of Unsigned pos problem)
		//TODO native versions for java & cs
		var v:HaxeInt64Typedef=vp;
		var isNegVal:Bool=false;
		if(isNeg(v)) {
			if(compare(v,make(0x80000000,0))==0) return -9223372036854775808.0; // most -ve value can't be made +ve
			isNegVal=true;
			v=neg(v);	
		}
		var ret:Float=0.0;
		var multiplier:Float=1.0;
		var one:HaxeInt64abs=make(0,1);
		for(i in 0...63) { // TODO improve speed by calculating more than 1 bit at a time
			if(!isZero(and(v,one)))
				ret += multiplier;
			multiplier *= 2.0;
			v=ushr(v,1);
		}
		if(isNegVal) return -ret;
		return ret;
}
public static function toUFloat(vp:HaxeInt64abs):Float{ // unsigned int64 to float
		//TODO native versions for java & cs
		var v:HaxeInt64Typedef=vp;
		var ret:Float=0.0;
		var multiplier:Float=1.0;
		var one:HaxeInt64abs=make(0,1);
		for(i in 0...64) { // TODO improve speed by calculating more than 1 bit at a time
			if(!isZero(and(v,one)))
	 			ret += multiplier;
			multiplier *= 2.0;
			v=ushr(v,1);
		}
		return ret;
}
public static function ofFloat(v):HaxeInt64abs { // float to signed int64 (TODO auto-cast of Unsigned is a posible problem)
		//TODO native versions for java & cs
		if(v==0.0) return make(0,0); 
		if(Math.isNaN(v)) return make(0x80000000,0); // largest -ve number is returned by Go in this situation
		var isNegVal:Bool=false;
		if(v<0.0){
			isNegVal=true;
			v = -v;
		} 
		if(v<2147483647.0) { // optimization: if just a small integer, don't do the full conversion code below
			if(isNegVal) 	return new HaxeInt64abs(HaxeInt64Typedef.neg(HaxeInt64Typedef.ofInt(Math.ceil(v))));
			else			return new HaxeInt64abs(HaxeInt64Typedef.ofInt(Math.floor(v)));
		}
		if(v>9223372036854775807.0) { // number too big to encode in 63 bits 
			if(isNegVal)	return new HaxeInt64abs(HaxeInt64Typedef.make(0x80000000,0)); 			// largest -ve number
			else			return new HaxeInt64abs(HaxeInt64Typedef.make(0x7fffffff,0xffffffff)); 	// largest +ve number
		}
		var f32:Float = 4294967296.0 ; // the number of combinations in 32-bits
		var f16:Float = 65536.0; // the number of combinations in 16-bits
		var high:Int = Math.floor(v/f32); 
		var lowFloat:Float= Math.ffloor(v-(high*f32)) ;
		var lowTop16:Int = Math.floor(lowFloat/f16) ;
		var lowBot16:Int = Math.floor(lowFloat-(lowTop16*f16)) ;
		var res:HaxeInt64Typedef = HaxeInt64Typedef.make(high,lowBot16);
		res = HaxeInt64Typedef.or(res,HaxeInt64Typedef.shl(HaxeInt64Typedef.make(0,lowTop16),16));
		if(isNegVal) return new HaxeInt64abs(HaxeInt64Typedef.neg(res));
		return new HaxeInt64abs(res);
}
public static function ofUFloat(v):HaxeInt64abs { // float to un-signed int64 
		//TODO native versions for java & cs
		if(v<=0.0) return make(0,0); // -ve values are invalid, so return 0
		if(Math.isNaN(v)) return make(0x80000000,0); // largest -ve number is returned by Go in this situation
		if(v<2147483647.0) { // optimization: if just a small integer, don't do the full conversion code below
			return ofInt(Math.floor(v));
		}
		if(v>18446744073709551615.0) { // number too big to encode in 64 bits 
			return new HaxeInt64abs(HaxeInt64Typedef.make(0xffffffff,0xffffffff)); 	// largest unsigned number
		}
		var f32:Float = 4294967296.0 ; // the number of combinations in 32-bits
		var f16:Float = 65536.0; // the number of combinations in 16-bits
		var high:Int = Math.floor(v/f32); 
		var lowFloat:Float= Math.ffloor(v-(high*f32)) ;
		var lowTop16:Int = Math.floor(lowFloat/f16) ;
		var lowBot16:Int = Math.floor(lowFloat-(lowTop16*f16)) ;
		var res:HaxeInt64Typedef = HaxeInt64Typedef.make(high,lowBot16);
		res = HaxeInt64Typedef.or(res,HaxeInt64Typedef.shl(HaxeInt64Typedef.make(0,lowTop16),16));
		return new HaxeInt64abs(res);
}
public static inline function make(h:Int,l:Int):HaxeInt64abs {
		return new HaxeInt64abs(HaxeInt64Typedef.make(h,l));
}
public static inline function toString(v:HaxeInt64abs):String {
	return HaxeInt64Typedef.toStr(v);
}
public static inline function toStr(v:HaxeInt64abs):String {
	return HaxeInt64Typedef.toStr(v);
}
public static inline function neg(v:HaxeInt64abs):HaxeInt64abs {
	return new HaxeInt64abs(HaxeInt64Typedef.neg(v));
}
public static inline function isZero(v:HaxeInt64abs):Bool {
	return HaxeInt64Typedef.isZero(v);
}
public static inline function isNeg(v:HaxeInt64abs):Bool {
	return HaxeInt64Typedef.isNeg(v);
}
public static inline function add(x:HaxeInt64abs,y:HaxeInt64abs):HaxeInt64abs {
	return new HaxeInt64abs(HaxeInt64Typedef.add(x,y));
}
public static inline function and(x:HaxeInt64abs,y:HaxeInt64abs):HaxeInt64abs {
	return new HaxeInt64abs(HaxeInt64Typedef.and(x,y));
}
private static function checkDiv(x:HaxeInt64abs,y:HaxeInt64abs,isSigned:Bool):HaxeInt64abs {
	if(HaxeInt64Typedef.isZero(y))
		Scheduler.panicFromHaxe( "attempt to divide 64-bit value by 0"); 
	if(isSigned && (HaxeInt64Typedef.compare(y,HaxeInt64Typedef.ofInt(-1))==0) && (HaxeInt64Typedef.compare(x,HaxeInt64Typedef.make(0x80000000,0))==0) ) 
	{
		//trace("checkDiv 64-bit special case");
		y=HaxeInt64Typedef.ofInt(1); // special case in the Go spec
	}
	return new HaxeInt64abs(y);
}
public static function div(x:HaxeInt64abs,y:HaxeInt64abs,isSigned:Bool):HaxeInt64abs {
	y=checkDiv(x,y,isSigned);
	if(HaxeInt64Typedef.compare(y,HaxeInt64Typedef.ofInt(1))==0) return new HaxeInt64abs(x);
	return new HaxeInt64abs(HaxeInt64Typedef.div(x,y));
}
public static function mod(x:HaxeInt64abs,y:HaxeInt64abs,isSigned:Bool):HaxeInt64abs {
	y=checkDiv(x,y,isSigned);
	if(HaxeInt64Typedef.compare(y,HaxeInt64Typedef.ofInt(1))==0) return new HaxeInt64abs(HaxeInt64Typedef.ofInt(0));
	return new HaxeInt64abs(HaxeInt64Typedef.mod(x,checkDiv(x,y,isSigned)));
}
public static inline function mul(x:HaxeInt64abs,y:HaxeInt64abs):HaxeInt64abs {
	return new HaxeInt64abs(HaxeInt64Typedef.mul(x,y));
}
public static inline function or(x:HaxeInt64abs,y:HaxeInt64abs):HaxeInt64abs {
	return new HaxeInt64abs(HaxeInt64Typedef.or(x,y));
}
public static inline function shl(x:HaxeInt64abs,y:Int):HaxeInt64abs {
	return new HaxeInt64abs(HaxeInt64Typedef.shl(x,y));
}
public static inline function ushr(x:HaxeInt64abs,y:Int):HaxeInt64abs {
	return new HaxeInt64abs(HaxeInt64Typedef.ushr(x,y));
}
public static inline function sub(x:HaxeInt64abs,y:HaxeInt64abs):HaxeInt64abs {
	return new HaxeInt64abs(HaxeInt64Typedef.sub(x,y));
}
public static inline function xor(x:HaxeInt64abs,y:HaxeInt64abs):HaxeInt64abs {
	return new HaxeInt64abs(HaxeInt64Typedef.xor(x,y));
}
public static inline function compare(x:HaxeInt64abs,y:HaxeInt64abs):Int {
	return HaxeInt64Typedef.compare(x,y);
}
public static function ucompare(x:HaxeInt64abs,y:HaxeInt64abs):Int {
	#if ( java || cs )
		// unsigned compare library code does not work properly for these platforms 
		if(HaxeInt64Typedef.isZero(x)) {
			if(HaxeInt64Typedef.isZero(y)) {
				return 0;
			} else {
				return -1; // any value is larger than x 
			}
		}
		if(HaxeInt64Typedef.isZero(y)) { // if we are here, we know that x is non-zero
				return 1; // any value of x is larger than y 
		}
		if(!HaxeInt64Typedef.isNeg(x)) { // x +ve
			if(!HaxeInt64Typedef.isNeg(y)){ // both +ve so normal comparison
				return HaxeInt64Typedef.compare(x,y);
			}else{ // y -ve and so larger than x
				return -1;
			}
		}else { // x -ve
			if(!HaxeInt64Typedef.isNeg(y)){ // -ve x larger than +ve y
				return 1;
			}else{ // both are -ve so the normal comparison
				return HaxeInt64Typedef.compare(x,y); //eg -1::-7 gives -1--7 = +6 meaning -1 > -7 which is correct for unsigned
			}
		}
	#else
	 	return HaxeInt64Typedef.ucompare(x,y);
	#end
}
}

#if ( java || cs )
// this class required to allow load/save of this type via pointer class in Java, as lib fn casts Dynamic to Int64 via Int
// also required in c# to avoid integer overflow errors, probably because of a related problem
// TODO consider ways to optimize

class GOint64  { 
private var i64:HaxeInt64abs;

private inline function new(v:HaxeInt64abs) {
	i64=v;
}
public inline function toString():String {
	return HaxeInt64abs.toStr(i64);
}

public static inline function make(h:Int,l:Int):GOint64 {
	return new GOint64(HaxeInt64abs.make(h,l));
}
public static inline function toInt(v:GOint64):Int {
	return HaxeInt64abs.toInt(v.i64);
}
public static inline function toFloat(v:GOint64):Float{
	return HaxeInt64abs.toFloat(v.i64);
}
public static inline function toUFloat(v:GOint64):Float{
	return HaxeInt64abs.toUFloat(v.i64);
}
public static inline function toStr(v:GOint64):String {
	return HaxeInt64abs.toStr(v.i64);
}
public static inline function ofInt(v:Int):GOint64 {
	return new GOint64(HaxeInt64abs.ofInt(v));
}
public static inline function ofFloat(v:Float):GOint64 {
	return new GOint64(HaxeInt64abs.ofFloat(v));
}
public static inline function ofUFloat(v:Float):GOint64 {
	return new GOint64(HaxeInt64abs.ofUFloat(v));
}
public static inline function neg(v:GOint64):GOint64 {
	return new GOint64(HaxeInt64abs.neg(v.i64));
}
public static inline function isZero(v:GOint64):Bool {
	return HaxeInt64abs.isZero(v.i64);
}
public static inline function isNeg(v:GOint64):Bool {
	return HaxeInt64abs.isNeg(v.i64);
}
public static inline function add(x:GOint64,y:GOint64):GOint64 {
	return new GOint64(HaxeInt64abs.add(x.i64,y.i64));
}
public static inline function and(x:GOint64,y:GOint64):GOint64 {
	return new GOint64(HaxeInt64abs.and(x.i64,y.i64));
}
public static inline function div(x:GOint64,y:GOint64,isSigned:Bool):GOint64 {
	return new GOint64(HaxeInt64abs.div(x.i64,y.i64,isSigned));
}
public static inline function mod(x:GOint64,y:GOint64,isSigned:Bool):GOint64 {
	return new GOint64(HaxeInt64abs.mod(x.i64,y.i64,isSigned));
}
public static inline function mul(x:GOint64,y:GOint64):GOint64 {
	return new GOint64(HaxeInt64abs.mul(x.i64,y.i64));
}
public static inline function or(x:GOint64,y:GOint64):GOint64 {
	return new GOint64(HaxeInt64abs.or(x.i64,y.i64));
}
public static inline function shl(x:GOint64,y:Int):GOint64 {
	return new GOint64(HaxeInt64abs.shl(x.i64,y));
}
public static inline function ushr(x:GOint64,y:Int):GOint64 {
	return new GOint64(HaxeInt64abs.ushr(x.i64,y));
}
public static inline function sub(x:GOint64,y:GOint64):GOint64 {
	return new GOint64(HaxeInt64abs.sub(x.i64,y.i64));
}
public static inline function xor(x:GOint64,y:GOint64):GOint64 {
	return new GOint64(HaxeInt64abs.xor(x.i64,y.i64));
}
public static inline function compare(x:GOint64,y:GOint64):Int {
	return HaxeInt64abs.compare(x.i64,y.i64);
}
public static inline function ucompare(x:GOint64,y:GOint64):Int {
	return HaxeInt64abs.ucompare(x.i64,y.i64);
}
}
#else
	typedef GOint64 = HaxeInt64abs;
#end

//**************** rewrite of std Haxe library function haxe.Int64 for PHP integer overflow an other errors
/*
Modify haxe.Int64.hx to work on php and fix other errors
- php integer overflow and ushr are incorrect (for 32-bits Int),
special functions now correct for these faults for Int64.
- both div and mod now have the sign correct when double-negative.
- special cases of div or mod by 0 or 1 now correct.
*/
/*
 * Copyright (C)2005-2012 Haxe Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

class Int64 { 

	var high : Int;
	var low : Int;

	inline function new(high, low) {
		this.high = i32(high);
		this.low = i32(low);
	}

	#if php
	/*
		private function to correctly handle 32-bit integer overflow on php 
		see: http://stackoverflow.com/questions/300840/force-php-integer-overflow
	*/
	private static function i32php(value:Int):Int { 
			value = (value & untyped __php__("0xFFFFFFFF"));
 		    if ( (value & untyped __php__("0x80000000"))!=0 )
		        value = -(((~value) & untyped __php__("0xFFFFFFFF")) + 1);
		    return value;
	}
	#end

	/*
		private function to correctly handle 32-bit ushr on php
		see: https://github.com/HaxeFoundation/haxe/commit/1a878aa90708040a41b0dd59f518d83b09ede209
	*/
	private static inline function ushr32(v:Int,n:Int):Int { 
		#if php
		 	return (v >> n) & (untyped __php__("0x7fffffff") >> (n-1));
		#else
			return v>>>n;
		#end
	}

	@:extern static inline function i32(i) {
		#if (js || flash8)
			return i | 0;
		#elseif php
			return i32php(i); // handle overflow of 32-bit integers correctly 
		#else
			return i;
		#end
	}

	@:extern static inline function i32mul(a:Int,b:Int) {
		#if (php || js || flash8)
		/*
			We can't simply use i32(a*b) since we might overflow (52 bits precision in doubles)
		*/
		return i32(i32((a * (b >>> 16)) << 16) + (a * (b&0xFFFF)));
		#else
		return a * b;
		#end
	}
	
	#if as3 public #end function toString() {
		if ((high|low) == 0 )
			return "0";
		var str = "";
		var neg = false;
		var i = this;
		if( isNeg(i) ) {
			neg = true;
			i = Int64.neg(i);
		}
		var ten = ofInt(10);
		while( !isZero(i) ) {
			var r = divMod(i, ten);
			str = r.modulus.low + str; 
			i = r.quotient; 
		}
		if( neg ) str = "-" + str;
		return str;
	}

	public static inline function make( high : Int, low : Int ) : Int64 {
		return new Int64(high, low); 
	}

	public static inline function ofInt( x : Int ) : Int64 {
		return new Int64(x >> 31,x);
	}

	public static function toInt( x : Int64 ) : Int {
		if( x.high != 0 ) {
			if( x.high < 0 )
				return -toInt(neg(x));
			throw "Overflow"; //NOTE go panic not used here as it is in the Haxe libary code
		}
		return x.low; 
	}

	public static function getLow( x : Int64 ) : Int {
		return x.low;
	}

	public static function getHigh( x : Int64 ) : Int {
		return x.high;
	}

	public static function add( a : Int64, b : Int64 ) : Int64 {
		var high = i32(a.high + b.high);
		var low = i32(a.low + b.low);
		if( uicompare(low,a.low) < 0 )
			high++;
		return new Int64(high, low);
	}

	public static function sub( a : Int64, b : Int64 ) : Int64 {
		var high = i32(a.high - b.high); // i32() call required to match add
		var low = i32(a.low - b.low); // i32() call required to match add
		if( uicompare(a.low,b.low) < 0 )
			high--;
		return new Int64(high, low);
	}

	public static function mul( a : Int64, b : Int64 ) : Int64 {
		var mask = 0xFFFF;
		var al = a.low & mask, ah = ushr32(a.low , 16); 
		var bl = b.low & mask, bh = ushr32(b.low , 16); 
		var p00 = al * bl;
		var p10 = ah * bl;
		var p01 = al * bh;
		var p11 = ah * bh;
		var low = p00;
		var high = i32(p11 + ushr32(p01 , 16) + ushr32(p10 , 16));
		p01 = i32(p01 << 16); low = i32(low + p01); if( uicompare(low, p01) < 0 ) high = i32(high + 1);
		p10 = i32(p10 << 16); low = i32(low + p10); if( uicompare(low, p10) < 0 ) high = i32(high + 1);
		high = i32(high + i32mul(a.low,b.high));
		high = i32(high + i32mul(a.high,b.low));
		return new Int64(high, low);
	}

	static function divMod( modulus : Int64, divisor : Int64 ) {
		var quotient = new Int64(0, 0);
		var mask = new Int64(0, 1);
		divisor = new Int64(divisor.high, divisor.low);
		while( divisor.high >= 0 ) { 
			var cmp = ucompare(divisor, modulus);
			divisor.high = i32( i32(divisor.high << 1) | ushr32(divisor.low , 31) ); 
			divisor.low = i32(divisor.low << 1); 
			mask.high = i32( i32(mask.high << 1) | ushr32(mask.low , 31) ); 
			mask.low = i32(mask.low << 1);
			if( cmp >= 0 ) break;
		}
		while( i32(mask.low | mask.high) != 0 ) { 
			if( ucompare(modulus, divisor) >= 0 ) {
				quotient.high= i32(quotient.high | mask.high); 
				quotient.low= i32(quotient.low | mask.low); 
				modulus = sub(modulus,divisor);
			}
			mask.low = i32( ushr32(mask.low , 1) | i32(mask.high << 31) ); 
			mask.high = ushr32(mask.high , 1); 

			divisor.low = i32( ushr32(divisor.low , 1) | i32(divisor.high << 31) ); 
			divisor.high = ushr32(divisor.high , 1); 
		}
		return { quotient : quotient, modulus : modulus };
	}

	public static function div( a : Int64, b : Int64 ) : Int64 { 
		if(b.high==0) // handle special cases of 0 and 1
			switch(b.low) {
			case 0:	throw "divide by zero";  //NOTE go panic not used here as it is in the Haxe libary code
			case 1: return new Int64(a.high,a.low);
			} 
		var sign = ((a.high<0) || (b.high<0)) && (!( (a.high<0) && (b.high<0))); // make sure we get the correct sign
		if( a.high < 0 ) a = neg(a);
		if( b.high < 0 ) b = neg(b);
		var q = divMod(a, b).quotient;
		return sign ? neg(q) : q;
	}

	public static function mod( a : Int64, b : Int64 ) : Int64 {
		if(b.high==0) // handle special cases of 0 and 1
			switch(b.low) {
			case 0:	throw "modulus by zero";  //NOTE go panic not used here as it is in the Haxe libary code
			case 1: return ofInt(0);
			}
		var sign = a.high<0; // the sign of a modulus is the sign of the value being mod'ed
		if( a.high < 0 ) a = neg(a);
		if( b.high < 0 ) b = neg(b);
		var m = divMod(a, b).modulus;
		return sign ? neg(m) : m;
	}

	public static inline function shl( a : Int64, b : Int ) : Int64 {
		return if( b & 63 == 0 ) a else if( b & 63 < 32 ) new Int64( (a.high << b) | ushr32(a.low, i32(32-(b&63))), a.low << b ) else new Int64( a.low << i32(b - 32), 0 );
	}

	public static inline function shr( a : Int64, b : Int ) : Int64 {
		return if( b & 63 == 0 ) a else if( b & 63 < 32 ) new Int64( a.high >> b, ushr32(a.low,b) | (a.high << i32(32 - (b&63))) ) else new Int64( a.high >> 31, a.high >> i32(b - 32) );
	}

	public static inline function ushr( a : Int64, b : Int ) : Int64 {
		return if( b & 63 == 0 ) a else if( b & 63 < 32 ) new Int64( ushr32(a.high, b), ushr32(a.low, b) | (a.high << i32(32 - (b&63))) ) else new Int64( 0, ushr32(a.high, i32(b - 32)) );
	}

	public static inline function and( a : Int64, b : Int64 ) : Int64 {
		return new Int64( a.high & b.high, a.low & b.low );
	}

	public static inline function or( a : Int64, b : Int64 ) : Int64 {
		return new Int64( a.high | b.high, a.low | b.low );
	}

	public static inline function xor( a : Int64, b : Int64 ) : Int64 {
		return new Int64( a.high ^ b.high, a.low ^ b.low );
	}

	public static inline function neg( a : Int64 ) : Int64 {
		var high = i32(~a.high); 
		var low = i32(-a.low); 
		if( low == 0 )
			high++;
		return new Int64(high,low);
	}

	public static inline function isNeg( a : Int64 ) : Bool {
		return a.high < 0;
	}

	public static inline function isZero( a : Int64 ) : Bool {
		return (a.high | a.low) == 0;
	}

	static function uicompare( a : Int, b : Int ) {
		return a < 0 ? (b < 0 ? i32(~b - ~a) : 1) : (b < 0 ? -1 : i32(a - b));
	}

	public static inline function compare( a : Int64, b : Int64 ) : Int {
		var v = i32(a.high - b.high); 
		return if( v != 0 ) v else uicompare(a.low,b.low);
	}

	/**
		Compare two Int64 in unsigned mode.
	**/
	public static inline function ucompare( a : Int64, b : Int64 ) : Int {
		var v = uicompare(a.high,b.high);
		return if( v != 0 ) v else uicompare(a.low, b.low);
	}

	public static inline function toStr( a : Int64 ) : String {
		return a.toString();
	}

}

//**************** END REWRITE of haxe.Int64 for php and to correct errors


// GoRoutine 
class StackFrameBasis
{
public var _incomplete(default,null):Bool=true;
public var _latestPH:Int=0;
public var _latestBlock:Int=0;
public var _functionPH:Int;
public var _functionName:String;
public var _goroutine(default,null):Int;
public var _bds:Array<Dynamic>; // bindings for closures
public var _deferStack:List<StackFrame>;

public function new(gr:Int,ph:Int,name:String){
	_goroutine=gr;
	_functionPH=ph;
	_functionName=name;
	_deferStack=new List<StackFrame>();
	// TODO optionally profile function entry here
}

public inline function setLatest(ph:Int,blk:Int){
	this.setPH(ph);
	_latestBlock=blk;
	// TODO optionally profile block entry here
}

public inline function setPH(ph:Int){
	_latestPH=ph;
	// TODO optionally profile instruction line entry here	
}

public inline function defer(fn:StackFrame){
	//trace("defer");
	_deferStack.add(fn); // add to the end of the list, so that runDefers() get them in the right order
}

public function runDefers(){
	//trace("runDefers");
	while(!_deferStack.isEmpty()){
		//trace("runDefers-pop");
		Scheduler.push(_goroutine,_deferStack.pop());
		//Scheduler.traceStackDump();
	}
}


}

interface StackFrame
{
public var _incomplete(default,null):Bool;
public var _latestPH:Int;
public var _latestBlock:Int;
public var _functionPH:Int;
public var _functionName:String;
public var _goroutine(default,null):Int;
public var _bds:Array<Dynamic>; // bindings for closures
public var _deferStack:List<StackFrame>;
function run():StackFrame; // function state machine (set up by each Go function Haxe class)
function res():Dynamic; // function result (set up by each Go function Haxe class)
}

class Scheduler { // NOTE this code requires a single-thread, as there is no locking 
// public
public static var doneInit:Bool=false; // flag to limit go-routines to 1 during the init() processing phase
// private
static var grStacks:Array<List<StackFrame>>=new Array<List<StackFrame>>(); 
static var grInPanic:Array<Bool>=new Array<Bool>();
static var grPanicMsg:Array<Interface>=new Array<Interface>();
static var panicStackDump:String="";
static var entryCount:Int=0; // this to be able to monitor the re-entrys into this routine for debug
static var currentGR:Int=0; // the current goroutine, used by Scheduler.panicFromHaxe(), NOTE this requires a single thread

public static function timerEventHandler(dummy:Dynamic) { // if the scheduler is being run from a timer, this is where it comes to
	runAll();
}

public static function runAll() { // this must be re-entrant, in order to allow Haxe->Go->Haxe->Go for some runtime functions
	var cg:Int=0; // reentrant current goroutine
	entryCount++;
	if(entryCount>2) { // this is the simple limit to runtime recursion  
		throw "Scheduler.runAll() entryCount exceeded - "+stackDump();
	}

	// special handling for goroutine 0, which is used in the initialisation phase and re-entrantly, where only one goroutine may operate		
	if(grStacks[0].isEmpty()) { // check if there is ever likley to be anything to do
		if(grStacks.length<=1) { 
			throw "Scheduler: there is only one goroutine and its stack is empty\n"+stackDump();		
		}
	} else { // run goroutine zero
		runOne(0,entryCount);
	}

	if(doneInit  && entryCount==1 ) {	// don't run extra goroutines when we are re-entrant or have not finished initialistion
									// NOTE this means that Haxe->Go->Haxe->Go code cannot run goroutines 
		for(cg in 1...grStacks.length) { // length may grow during a run through, NOTE goroutine 0 not run again
			if(!grStacks[cg].isEmpty()) {
				runOne(cg,entryCount);
			}
		}
		// prune the list of goroutines only at the end (goroutine numbers are in the stack frames, so can't be altered) 
		while(grStacks.length>1){
			if(grStacks[grStacks.length-1].isEmpty())
				grStacks.pop();
			else
				break;
		}
	}
	entryCount--;
}
static inline function runOne(gr:Int,entryCount:Int){ // called from above to call individual goroutines TODO: Review for multi-threading
	if(grInPanic[gr]) {
		if(entryCount!=1) { // we are in re-entrant code, so we can't panic again, as this may be part of the panic handling...
				// NOTE this means that Haxe->Go->Haxe->Go code cannot use panic() reliably 
				run1(gr);
		} else {
			while(grInPanic[gr]){
				if(grStacks[gr].isEmpty())
					throw "Panic in goroutine "+gr+"\n"+panicStackDump; // use stored stack dump
				else {
					var sf:StackFrame=grStacks[gr].pop();
					while(!sf._deferStack.isEmpty()){ 
						// NOTE this will run all of the defered code for a function, even if recover() is encountered
						// TODO go back to recover code block in SSA function struct after a recover
						var def:StackFrame=sf._deferStack.pop();
						Scheduler.push(gr,def);
						while(def._incomplete) 
							runAll(); // with entryCount >1, so run as above 
					}
				}
			}
		}
	} else {
		run1(gr);
	}
}
public static inline function run1(gr:Int){ // used by callFromRT() for every go function
		if(grStacks[gr].first()==null) { 
			throw "Panic:"+grPanicMsg+"\nScheduler: null stack entry for goroutine "+gr+"\n"+stackDump();
		} else {
			currentGR=gr;
			grStacks[gr].first().run(); // run() may call haxe which calls these routines recursively 
		}	
}
public static function makeGoroutine():Int {
	for (r in 0 ... grStacks.length)
		if(grStacks[r].isEmpty())
		{
			grInPanic[r]=false;
			grPanicMsg[r]=null;
			return r;	// reuse a previous goroutine number if possible
		}
	var l:Int=grStacks.length;
	grStacks[l]=new List<StackFrame>();
	grInPanic[l]=false;
	grPanicMsg[l]=null;
	return l;
}
public static function pop(gr:Int):StackFrame {
	if(gr>=grStacks.length||gr<0)
		throw "Scheduler.pop() invalid goroutine";
	return grStacks[gr].pop();
}
public static function push(gr:Int,sf:StackFrame){
	if(gr>=grStacks.length||gr<0)
		throw "Scheduler.push() invalid goroutine";
	grStacks[gr].push(sf);
}

public static function stackDump():String {
	var ret:String = "";
	var gr:Int;
	ret += "runAll() entryCount="+entryCount+"\n";
	for(gr in 0...grStacks.length) {
		ret += "Goroutine " + gr + " "+grPanicMsg[gr]+"\n"; //may need to unpack the interface
		if(grStacks[gr].isEmpty()) {
			ret += "Stack is empty\n";
		} else {
			ret += "Stack has " +grStacks[gr].length+ " entries:\n";
			var it=grStacks[gr].iterator();
			while(it.hasNext()) {
				var ent=it.next();
				if(ent==null) {
					ret += "\tStack entry is null\n";
				} else {
					ret += "\t"+ent._functionName+" starting at "+Go.CPos(ent._functionPH);
					ret += " latest position "+Go.CPos(ent._latestPH);
					ret += " latest block "+ent._latestBlock+"\n";
				}
			}
		}
	}
	return ret;
}

public static function traceStackDump() {trace(stackDump());}

public static function panic(gr:Int,err:Interface){
	if(gr>=grStacks.length||gr<0)
		throw "Scheduler.panic() invalid goroutine";
	if(!grInPanic[gr]) { // if we are already in a panic, keep the first message and stack-dump
		grInPanic[gr]=true;
		grPanicMsg[gr]=err;
		panicStackDump=stackDump();
	}
}
public static function recover(gr:Int):Interface{
	if(gr>=grStacks.length||gr<0)
		throw "Scheduler.recover() invalid goroutine";
	grInPanic[gr]=false;
	return grPanicMsg[gr];
}
public static function panicFromHaxe(err:String) { 
	if(currentGR>=grStacks.length||currentGR<0) 
		// if currnent goroutine is -ve, or out of range, always panics in goroutine 0
		panic(0,new Interface(TypeInfo.getId("string"),"Runtime panic, unknown goroutine, "+err+" "));
	else
		panic(currentGR,new Interface(TypeInfo.getId("string"),"Runtime panic, "+err+" "));
}
public static function bbi() {
	panicFromHaxe("bad block ID (internal phi error)");
}
public static function ioor() {
	panicFromHaxe("index out of range");
}
public static inline function NumGoroutine():Int {
	return grStacks.length;
}
}



#if (!php) private #end class Go_haxegoruntime_funcname_go extends StackFrameBasis implements StackFrame {  // goruntime.go:357:6
var p_arg0:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer) {
super(gr,419,"Go_haxegoruntime_funcname_go");
this._bds=_bds;
this.p_arg0=p_arg0;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_arg0 : Pointer) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_funcname_go(0,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_arg0 : Pointer) : String {
var _sf=new Go_haxegoruntime_funcname_go(_gr,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer) : Go_haxegoruntime_funcname_go
{return new Go_haxegoruntime_funcname_go(gr,_bds, p_arg0);
}
public function run():Go_haxegoruntime_funcname_go {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(419,0);
this.SubFn0();
this.setPH(420);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(420,-1);
 // panic t0 *ssa.Panic @ goruntime.go:358:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,"runtime.funcname_go() not yet implemented"); // _t0 = make interface{} <- string ("runtime.funcname_...":string) *ssa.MakeInterface near goruntime.go:358:7
}// end SubFn0
}
#if js @:expose("Go_utf16_IsSurrogate") #end class Go_utf16_IsSurrogate extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:30:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,472,"Go_utf16_IsSurrogate");
this._bds=_bds;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:Bool=false;
var _t1:Bool=false;
var _t2:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_r : Int) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf16_IsSurrogate(0,[], p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r : Int) : Bool {
var _sf=new Go_utf16_IsSurrogate(_gr,[], p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r : Int) : Go_utf16_IsSurrogate
{return new Go_utf16_IsSurrogate(gr,_bds, p_r);
}
public function run():Go_utf16_IsSurrogate {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(472,0);
this.SubFn0();
_Phi=0;
case 1: // binop.rhs
this.setLatest(472,1);
this.SubFn1();
_Phi=1;
case 2: // binop.done
this.setLatest(472,2);
this.setPH(473);
_t2=((_Phi==0)?false:(_Phi==1)?_t1:false); // _t2 = phi [0.entry: false:bool, 1.binop.rhs: t1] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:20
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Bool;
_t0=(55296<=p_r); // _t0 = 55296:rune <= r *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:15
_Next=_t0 ? 1 : 2; // if t0 goto 1.binop.rhs else 2.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:15
}// end SubFn0
private inline function SubFn1():Void {
_t1=(p_r<57344); // _t1 = r < 57344:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:25
_Next=2; // jump 2.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:25
}// end SubFn1
}
#if js @:expose("Go_haxegoruntime_Host") #end class Go_haxegoruntime_Host extends StackFrameBasis implements StackFrame {  // goruntime.go:130:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,192,"Go_haxegoruntime_Host");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_Host(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_haxegoruntime_Host(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_haxegoruntime_Host
{return new Go_haxegoruntime_Host(gr,_bds);
}
public function run():Go_haxegoruntime_Host {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(192,0);
_res= "Go";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "Go":string *ssa.Return @ goruntime.go:130:22

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_haxegoruntime_M2") #end class Go_haxegoruntime_M2 extends StackFrameBasis implements StackFrame {  // goruntime.go:155:6
var p_rx:Interface;
var p_typ:String;
var p_meth:String;
var p_a1:Interface;
var p_a2:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface) {
super(gr,217,"Go_haxegoruntime_M2");
this._bds=_bds;
this.p_rx=p_rx;
this.p_typ=p_typ;
this.p_meth=p_meth;
this.p_a1=p_a1;
this.p_a2=p_a2;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_M2(0,[], p_rx, p_typ, p_meth, p_a1, p_a2).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface) : Interface {
var _sf=new Go_haxegoruntime_M2(_gr,[], p_rx, p_typ, p_meth, p_a1, p_a2).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface) : Go_haxegoruntime_M2
{return new Go_haxegoruntime_M2(gr,_bds, p_rx, p_typ, p_meth, p_a1, p_a2);
}
public function run():Go_haxegoruntime_M2 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(217,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:155:93

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_meth); // _t0 = make interface{} <- string (meth) *ssa.MakeInterface near goruntime.go:155:93
}// end SubFn0
}
#if js @:expose("Go_utf8_DecodeLastRune") #end class Go_utf8_DecodeLastRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:239:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,789,"Go_utf8_DecodeLastRune");
this._bds=_bds;
this.p_p=p_p;
Scheduler.push(gr,this);
}
var _res:{r0:Int, r1:Int};
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Bool=false;
var _t2:Int=0;
var _t3:Pointer=null;
var _t4:Int=0;
var _t5:Int=0;
var _t6:Bool=false;
var _t7:Int=0;
var _t8:Bool=false;
var _t9:Int=0;
var _t10:Int=0;
var _t11:Pointer=null;
var _t12:Int=0;
var _SF1:StackFrame;
var _t13:Bool=false;
var _t14:Bool=false;
var _t15:Int=0;
var _t16:Bool=false;
var _t17:Int=0;
var _t18:Int=0;
var _t19:Slice=null;
var _SF2:StackFrame;
var _t20:{r0:Int,r1:Int}=null;
var _t21:Int=0;
var _t22:Int=0;
var _t23:Int=0;
var _t24:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_p : Slice) : {r0:Int, r1:Int} {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_DecodeLastRune(0,[], p_p).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_p : Slice) : {r0:Int, r1:Int} {
var _sf=new Go_utf8_DecodeLastRune(_gr,[], p_p).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_p : Slice) : Go_utf8_DecodeLastRune
{return new Go_utf8_DecodeLastRune(gr,_bds, p_p);
}
public function run():Go_utf8_DecodeLastRune {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(789,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(789,1);
this.setPH(792);
_res= {r0:65533,r1:0};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:242:3

case 2: // if.done
this.setLatest(792,2);
this.SubFn1();
_Phi=2;
case 3: // if.then
this.setLatest(792,3);
this.setPH(797);
_res= {r0:_t5,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:247:3

case 4: // if.done
this.setLatest(797,4);
this.SubFn2();
_Phi=4;
case 5: // if.then
this.setLatest(797,5);
this.SubFn3();
_Phi=5;
case 6: // if.done
this.setLatest(797,6);
this.setPH(802);
_t9=((_Phi==4)?_t7:(_Phi==5)?0:0); // _t9 = phi [4.if.done: t7, 5.if.then: 0:int] #lim *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:252:2
this.SubFn4();
_Phi=6;
case 7: // for.body
this.setLatest(802,7);
this.SubFn5();
this.setPH(807);
_SF1=Go_utf8_RuneStart.call(this._goroutine,[],_t12);
_Next = -1;
return this;
case -1:
this.setLatest(807,-1);
_t13=_SF1.res();
 // _t13 = RuneStart(t12) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:15
this.SubFn6();
_Phi=7;
case 8: // for.done
this.setLatest(807,8);
this.SubFn7();
_Phi=8;
case 9: // for.loop
this.setLatest(807,9);
this.setPH(794);
_t15=((_Phi==6)?_t10:(_Phi==10)?_t17:0); // _t15 = phi [6.if.done: t10, 10.if.done: t17] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:244:2
this.SubFn8();
_Phi=9;
case 10: // if.done
this.setLatest(794,10);
this.SubFn9();
_Phi=10;
case 11: // if.then
this.setLatest(794,11);
this.SubFn10();
_Phi=11;
case 12: // if.done
this.setLatest(794,12);
_t18=((_Phi==8)?_t15:(_Phi==11)?0:0); // _t18 = phi [8.for.done: t15, 11.if.then: 0:int] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:244:2
this.SubFn11();
this.setPH(814);
_SF2=Go_utf8_DecodeRune.call(this._goroutine,[],_t19);
_Next = -2;
return this;
case -2:
this.setLatest(814,-2);
_t20=_SF2.res();
 // _t20 = DecodeRune(t19) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:22
this.SubFn12();
_Phi=12;
case 13: // if.then
this.setLatest(814,13);
this.setPH(816);
_res= {r0:65533,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:266:3

case 14: // if.done
this.setLatest(816,14);
this.setPH(818);
_res= {r0:_t21,r1:_t22};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t21, t22 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:268:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t1:Bool;
this.setPH(790);
_t0=({var _v=p_p;_v==null?0:_v.len();}); // _t0 = len(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:240:12
this.setPH(791);
_t1=(_t0==0); // _t1 = t0 == 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:241:9
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:241:9
}// end SubFn0
private inline function SubFn1():Void {
var _t3:Pointer;
var _t4:Int;
var _t6:Bool;
this.setPH(794);
_t2=(_t0-1); // _t2 = t0 - 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:244:15
this.setPH(795);
if((_t2<0)||(_t2>=p_p.len())) Scheduler.ioor(); // _t3 = &p[t2] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:12 [POINTER]
_t3=p_p.addr(_t2);  // _t3 = &p[t2] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:12 [POINTER]
_t4=(_t3.load()|0); // _t4 = *t3 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:12
_t5=_t4; // _t5 = convert rune <- byte (t4) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:10
this.setPH(796);
_t6=(_t5<128); // _t6 = t5 < 128:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:246:7
_Next=_t6 ? 3 : 4; // if t6 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:246:7
}// end SubFn1
private inline function SubFn2():Void {
var _t8:Bool;
this.setPH(802);
_t7=(_t0-4); // _t7 = t0 - 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:252:13
this.setPH(803);
_t8=(_t7<0); // _t8 = t7 < 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:253:9
_Next=_t8 ? 5 : 6; // if t8 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:253:9
}// end SubFn2
private inline function SubFn3():Void {
_Next=6; // jump 6.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:253:9
}// end SubFn3
private inline function SubFn4():Void {
_t10=(_t2-1); // _t10 = t2 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:253:9
_Next=9; // jump 9.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:253:9
}// end SubFn4
private inline function SubFn5():Void {
var _t11:Pointer;
this.setPH(807);
if((_t15<0)||(_t15>=p_p.len())) Scheduler.ioor(); // _t11 = &p[t15] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17 [POINTER]
_t11=p_p.addr(_t15);  // _t11 = &p[t15] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17 [POINTER]
_t12=(_t11.load()|0); // _t12 = *t11 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17
}// end SubFn5
private inline function SubFn6():Void {
_Next=_t13 ? 8 : 10; // if t13 goto 8.for.done else 10.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17
}// end SubFn6
private inline function SubFn7():Void {
var _t14:Bool;
this.setPH(811);
_t14=(_t15<0); // _t14 = t15 < 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:261:11
_Next=_t14 ? 11 : 12; // if t14 goto 11.if.then else 12.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:261:11
}// end SubFn7
private inline function SubFn8():Void {
var _t16:Bool;
this.setPH(806);
_t16=(_t15>=_t9); // _t16 = t15 >= t9 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:256:21
_Next=_t16 ? 7 : 8; // if t16 goto 7.for.body else 8.for.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:256:21
}// end SubFn8
private inline function SubFn9():Void {
_t17=(_t15-1); // _t17 = t15 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:256:21
_Next=9; // jump 9.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:256:21
}// end SubFn9
private inline function SubFn10():Void {
_Next=12; // jump 12.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:256:21
}// end SubFn10
private inline function SubFn11():Void {
this.setPH(814);
_t19=p_p.subSlice(_t18,_t0); // _t19 = slice p[t18:t0] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:24
}// end SubFn11
private inline function SubFn12():Void {
var _t23:Int;
var _t24:Bool;
_t21=_t20.r0; // _t21 = extract t20 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:24
_t22=_t20.r1; // _t22 = extract t20 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:24
this.setPH(815);
_t23=(_t18+_t22); // _t23 = t18 + t22 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:265:10
_t24=(_t23!=_t0); // _t24 = t23 != t0 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:265:16
_Next=_t24 ? 13 : 14; // if t24 goto 13.if.then else 14.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:265:16
}// end SubFn12
}
#if js @:expose("Go_hxutil_Host") #end class Go_hxutil_Host extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:13:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1006,"Go_hxutil_Host");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_hxutil_Host(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_hxutil_Host(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_hxutil_Host
{return new Go_hxutil_Host(gr,_bds);
}
public function run():Go_hxutil_Host {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1006,0);
_res= "go";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "go":string *ssa.Return @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:13:22

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_utf16_Decode") #end class Go_utf16_Decode extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:86:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,528,"Go_utf16_Decode");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Slice=null;
var _t2:Pointer=null;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Slice=null;
var _t6:Int=0;
var _t7:Int=0;
var _t8:Int=0;
var _t9:Bool=false;
var _t10:Int=0;
var _t11:Int=0;
var _t12:Int=0;
var _t13:Pointer=null;
var _t14:Int=0;
var _t15:Int=0;
var _t16:Pointer=null;
var _t17:Int=0;
var _t18:Int=0;
var _SF1:StackFrame;
var _t19:Int=0;
var _t20:Int=0;
var _t21:Int=0;
var _t22:Pointer=null;
var _t23:Int=0;
var _t24:Bool=false;
var _t25:Int=0;
var _t26:Pointer=null;
var _t27:Int=0;
var _t28:Bool=false;
var _t29:Bool=false;
var _t30:Int=0;
var _t31:Pointer=null;
var _t32:Int=0;
var _t33:Bool=false;
var _t34:Int=0;
var _t35:Int=0;
var _t36:Bool=false;
var _t37:Bool=false;
var _t38:Pointer=null;
var _t39:Int=0;
var _t40:Int=0;
var _t41:Bool=false;
var _t42:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : Slice) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf16_Decode(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : Slice) : Slice {
var _sf=new Go_utf16_Decode(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : Slice) : Go_utf16_Decode
{return new Go_utf16_Decode(gr,_bds, p_s);
}
public function run():Go_utf16_Decode {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(528,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(528,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(528,2);
this.SubFn2();
this.setPH(549);
_res= _t5;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:107:2

case 3: // for.loop
this.setLatest(549,3);
this.setPH(530);
_t6=((_Phi==0)?0:(_Phi==4)?_t10:0); // _t6 = phi [0.entry: 0:int, 4.switch.done: t10] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:88:2
this.setPH(531);
_t7=((_Phi==0)?0:(_Phi==4)?_t12:0); // _t7 = phi [0.entry: 0:int, 4.switch.done: t12] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:6
this.SubFn3();
_Phi=3;
case 4: // switch.done
this.setLatest(531,4);
this.setPH(530);
_t10=((_Phi==5)?_t21:(_Phi==6)?_t23:(_Phi==13)?_t40:0); // _t10 = phi [5.switch.body: t21, 6.switch.body: t23, 13.switch.next: t40] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:88:2
this.setPH(531);
_t11=((_Phi==5)?_t20:(_Phi==6)?_t7:(_Phi==13)?_t7:0); // _t11 = phi [5.switch.body: t20, 6.switch.body: t7, 13.switch.next: t7] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:6
this.SubFn4();
_Phi=4;
case 5: // switch.body
this.setLatest(531,5);
this.SubFn5();
this.setPH(536);
_SF1=Go_utf16_DecodeRune.call(this._goroutine,[],_t14,_t18);
_Next = -1;
return this;
case -1:
this.setLatest(536,-1);
_t19=_SF1.res();
 // _t19 = DecodeRune(t14, t18) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:21
this.SubFn6();
_Phi=5;
case 6: // switch.body
this.setLatest(536,6);
this.SubFn7();
_Phi=6;
case 7: // switch.next
this.setLatest(536,7);
this.SubFn8();
_Phi=7;
case 8: // binop.rhs
this.setLatest(536,8);
this.SubFn9();
_Phi=8;
case 9: // binop.done
this.setLatest(536,9);
this.setPH(534);
_t29=((_Phi==1)?false:(_Phi==12)?false:(_Phi==11)?false:(_Phi==10)?false:(_Phi==8)?_t28:false); // _t29 = phi [1.for.body: false:bool, 12.cond.true: false:bool, 11.cond.true: false:bool, 10.cond.true: false:bool, 8.binop.rhs: t28] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:20
this.SubFn10();
_Phi=9;
case 10: // cond.true
this.setLatest(534,10);
this.SubFn11();
_Phi=10;
case 11: // cond.true
this.setLatest(534,11);
this.SubFn12();
_Phi=11;
case 12: // cond.true
this.setLatest(534,12);
this.SubFn13();
_Phi=12;
case 13: // switch.next
this.setLatest(534,13);
this.SubFn14();
_Phi=13;
case 14: // binop.rhs
this.setLatest(534,14);
this.SubFn15();
_Phi=14;
case 15: // binop.done
this.setLatest(534,15);
this.setPH(539);
_t42=((_Phi==7)?false:(_Phi==14)?_t41:false); // _t42 = phi [7.switch.next: false:bool, 14.binop.rhs: t41] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:19
this.SubFn16();
_Phi=15;
default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Int;
this.setPH(529);
_t0=({var _v=p_s;_v==null?0:_v.len();}); // _t0 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:87:23
_t1=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t0) _v[_i]=0; _v;}),0,_t0); // _t1 = make []rune t0 t0 *ssa.MakeSlice @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:87:11
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:87:11
}// end SubFn0
private inline function SubFn1():Void {
var _t2:Pointer;
var _t4:Bool;
this.setPH(532);
if((_t7<0)||(_t7>=p_s.len())) Scheduler.ioor(); // _t2 = &s[t7] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:90:16 [POINTER]
_t2=p_s.addr(_t7);  // _t2 = &s[t7] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:90:16 [POINTER]
_t3=(_t2.load()|0); // _t3 = *t2 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:90:16
this.setPH(533);
_t4=(Force.uintCompare(55296,_t3)<=0); // _t4 = 55296:uint16 <= t3 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:14
_Next=_t4 ? 12 : 9; // if t4 goto 12.cond.true else 9.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:14
}// end SubFn1
private inline function SubFn2():Void {
this.setPH(549);
_t5=_t1.subSlice(0,_t6); // _t5 = slice t1[0:int:t6] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:107:10
}// end SubFn2
private inline function SubFn3():Void {
var _t8:Int;
var _t9:Bool;
this.setPH(531);
_t8=({var _v=p_s;_v==null?0:_v.len();}); // _t8 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:21
_t9=(_t7<_t8); // _t9 = t7 < t8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:16
_Next=_t9 ? 1 : 2; // if t9 goto 1.for.body else 2.for.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:16
}// end SubFn3
private inline function SubFn4():Void {
_t12=(_t11+1); // _t12 = t11 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:16
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:16
}// end SubFn4
private inline function SubFn5():Void {
var _t15:Int;
var _t16:Pointer;
var _t17:Int;
this.setPH(536);
if((_t6<0)||(_t6>=_t1.len())) Scheduler.ioor(); // _t13 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:5 [POINTER]
_t13=_t1.addr(_t6);  // _t13 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:5 [POINTER]
_t14=_t3; // _t14 = convert rune <- uint16 (t3) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:26
_t15=(_t7+1); // _t15 = t7 + 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:39
if((_t15<0)||(_t15>=p_s.len())) Scheduler.ioor(); // _t16 = &s[t15] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:37 [POINTER]
_t16=p_s.addr(_t15);  // _t16 = &s[t15] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:37 [POINTER]
_t17=(_t16.load()|0); // _t17 = *t16 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:37
_t18=_t17; // _t18 = convert rune <- uint16 (t17) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:35
}// end SubFn5
private inline function SubFn6():Void {
_t13.store(_t19); // *t13 = t19 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:35
_t20=(_t7+1); // _t20 = t7 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:35
_t21=(_t6+1); // _t21 = t6 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:35
_Next=4; // jump 4.switch.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:35
}// end SubFn6
private inline function SubFn7():Void {
var _t22:Pointer;
this.setPH(541);
if((_t6<0)||(_t6>=_t1.len())) Scheduler.ioor(); // _t22 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5 [POINTER]
_t22=_t1.addr(_t6);  // _t22 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5 [POINTER]
_t22.store(65533); // *t22 = 65533:rune *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5
_t23=(_t6+1); // _t23 = t6 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5
_Next=4; // jump 4.switch.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5
}// end SubFn7
private inline function SubFn8():Void {
var _t24:Bool;
this.setPH(539);
_t24=(Force.uintCompare(55296,_t3)<=0); // _t24 = 55296:uint16 <= t3 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:14
_Next=_t24 ? 14 : 15; // if t24 goto 14.binop.rhs else 15.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:14
}// end SubFn8
private inline function SubFn9():Void {
var _t25:Int;
var _t26:Pointer;
var _t27:Int;
this.setPH(534);
_t25=(_t7+1); // _t25 = t7 + 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:26
if((_t25<0)||(_t25>=p_s.len())) Scheduler.ioor(); // _t26 = &s[t25] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:24 [POINTER]
_t26=p_s.addr(_t25);  // _t26 = &s[t25] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:24 [POINTER]
_t27=(_t26.load()|0); // _t27 = *t26 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:24
_t28=(Force.uintCompare(_t27,57344)<0); // _t28 = t27 < 57344:uint16 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:30
_Next=9; // jump 9.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:30
}// end SubFn9
private inline function SubFn10():Void {
_Next=_t29 ? 5 : 7; // if t29 goto 5.switch.body else 7.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:30
}// end SubFn10
private inline function SubFn11():Void {
var _t30:Int;
var _t31:Pointer;
var _t32:Int;
var _t33:Bool;
_t30=(_t7+1); // _t30 = t7 + 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:16
if((_t30<0)||(_t30>=p_s.len())) Scheduler.ioor(); // _t31 = &s[t30] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:14 [POINTER]
_t31=p_s.addr(_t30);  // _t31 = &s[t30] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:14 [POINTER]
_t32=(_t31.load()|0); // _t32 = *t31 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:14
_t33=(Force.uintCompare(56320,_t32)<=0); // _t33 = 56320:uint16 <= t32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:10
_Next=_t33 ? 8 : 9; // if t33 goto 8.binop.rhs else 9.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:10
}// end SubFn11
private inline function SubFn12():Void {
var _t34:Int;
var _t35:Int;
var _t36:Bool;
this.setPH(533);
_t34=(_t7+1); // _t34 = t7 + 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:36
_t35=({var _v=p_s;_v==null?0:_v.len();}); // _t35 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:44
_t36=(_t34<_t35); // _t36 = t34 < t35 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:39
_Next=_t36 ? 10 : 9; // if t36 goto 10.cond.true else 9.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:39
}// end SubFn12
private inline function SubFn13():Void {
var _t37:Bool;
_t37=(Force.uintCompare(_t3,56320)<0); // _t37 = t3 < 56320:uint16 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:24
_Next=_t37 ? 11 : 9; // if t37 goto 11.cond.true else 9.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:24
}// end SubFn13
private inline function SubFn14():Void {
var _t38:Pointer;
var _t39:Int;
this.setPH(545);
if((_t6<0)||(_t6>=_t1.len())) Scheduler.ioor(); // _t38 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:5 [POINTER]
_t38=_t1.addr(_t6);  // _t38 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:5 [POINTER]
_t39=_t3; // _t39 = convert rune <- uint16 (t3) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
_t38.store(_t39); // *t38 = t39 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
_t40=(_t6+1); // _t40 = t6 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
_Next=4; // jump 4.switch.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
}// end SubFn14
private inline function SubFn15():Void {
this.setPH(539);
_t41=(Force.uintCompare(_t3,57344)<0); // _t41 = t3 < 57344:uint16 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
_Next=15; // jump 15.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
}// end SubFn15
private inline function SubFn16():Void {
_Next=_t42 ? 6 : 13; // if t42 goto 6.switch.body else 13.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
}// end SubFn16
}
#if js @:expose("Go_utf8_RuneCount") #end class Go_utf8_RuneCount extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:367:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,917,"Go_utf8_RuneCount");
this._bds=_bds;
this.p_p=p_p;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Pointer=null;
var _t1:Int=0;
var _t2:Bool=false;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Int=0;
var _t6:Int=0;
var _t7:Bool=false;
var _t8:Int=0;
var _t9:Int=0;
var _t10:Int=0;
var _t11:Int=0;
var _t12:Slice=null;
var _SF1:StackFrame;
var _t13:{r0:Int,r1:Int}=null;
var _t15:Int=0;
var _t16:Int=0;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_p : Slice) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_RuneCount(0,[], p_p).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_p : Slice) : Int {
var _sf=new Go_utf8_RuneCount(_gr,[], p_p).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_p : Slice) : Go_utf8_RuneCount
{return new Go_utf8_RuneCount(gr,_bds, p_p);
}
public function run():Go_utf8_RuneCount {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(917,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(917,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(917,2);
this.setPH(928);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:378:2

case 3: // for.loop
this.setLatest(928,3);
this.setPH(918);
_t3=((_Phi==0)?0:(_Phi==5)?_t9:0); // _t3 = phi [0.entry: 0:int, 5.if.done: t9] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:368:2
this.setPH(919);
_t4=((_Phi==0)?0:(_Phi==5)?_t11:0); // _t4 = phi [0.entry: 0:int, 5.if.done: t11] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:369:6
this.setPH(924);
_t5=((_Phi==0)?0:(_Phi==5)?_t10:0); // _t5 = phi [0.entry: 0:int, 5.if.done: t10] #size *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:7
this.SubFn2();
_Phi=3;
case 4: // if.then
this.setLatest(924,4);
this.SubFn3();
_Phi=4;
case 5: // if.done
this.setLatest(924,5);
this.setPH(918);
_t9=((_Phi==4)?_t8:(_Phi==6)?_t16:0); // _t9 = phi [4.if.then: t8, 6.if.else: t16] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:368:2
this.setPH(924);
_t10=((_Phi==4)?_t5:(_Phi==6)?_t15:0); // _t10 = phi [4.if.then: t5, 6.if.else: t15] #size *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:7
this.SubFn4();
_Phi=5;
case 6: // if.else
this.setLatest(924,6);
this.SubFn5();
_SF1=Go_utf8_DecodeRune.call(this._goroutine,[],_t12);
_Next = -1;
return this;
case -1:
this.setLatest(924,-1);
_t13=_SF1.res();
 // _t13 = DecodeRune(t12) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:25
this.SubFn6();
_Phi=6;
default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:25
}// end SubFn0
private inline function SubFn1():Void {
var _t0:Pointer;
var _t1:Int;
var _t2:Bool;
this.setPH(921);
if((_t3<0)||(_t3>=p_p.len())) Scheduler.ioor(); // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:7 [POINTER]
_t0=p_p.addr(_t3);  // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:7 [POINTER]
_t1=(_t0.load()|0); // _t1 = *t0 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:7
_t2=(Force.uintCompare(_t1,128)<0); // _t2 = t1 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:11
_Next=_t2 ? 4 : 6; // if t2 goto 4.if.then else 6.if.else *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:11
}// end SubFn1
private inline function SubFn2():Void {
var _t6:Int;
var _t7:Bool;
this.setPH(920);
_t6=({var _v=p_p;_v==null?0:_v.len();}); // _t6 = len(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:20
_t7=(_t3<_t6); // _t7 = t3 < t6 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
_Next=_t7 ? 1 : 2; // if t7 goto 1.for.body else 2.for.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
}// end SubFn2
private inline function SubFn3():Void {
_t8=(_t3+1); // _t8 = t3 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
_Next=5; // jump 5.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
}// end SubFn3
private inline function SubFn4():Void {
_t11=(_t4+1); // _t11 = t4 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
}// end SubFn4
private inline function SubFn5():Void {
this.setPH(924);
_t12=p_p.subSlice(_t3,-1); // _t12 = slice p[t3:] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
}// end SubFn5
private inline function SubFn6():Void {
 // _t14 = extract t13 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27 [REGISTER VALUE UN-USED]
_t15=_t13.r1; // _t15 = extract t13 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
_t16=(_t3+_t15); // _t16 = t3 + t15 *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
_Next=5; // jump 5.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
}// end SubFn6
}
#if js @:expose("Go_haxegoruntime_M6") #end class Go_haxegoruntime_M6 extends StackFrameBasis implements StackFrame {  // goruntime.go:159:6
var p_rx:Interface;
var p_typ:String;
var p_meth:String;
var p_a1:Interface;
var p_a2:Interface;
var p_a3:Interface;
var p_a4:Interface;
var p_a5:Interface;
var p_a6:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface, p_a6 : Interface) {
super(gr,221,"Go_haxegoruntime_M6");
this._bds=_bds;
this.p_rx=p_rx;
this.p_typ=p_typ;
this.p_meth=p_meth;
this.p_a1=p_a1;
this.p_a2=p_a2;
this.p_a3=p_a3;
this.p_a4=p_a4;
this.p_a5=p_a5;
this.p_a6=p_a6;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface, p_a6 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_M6(0,[], p_rx, p_typ, p_meth, p_a1, p_a2, p_a3, p_a4, p_a5, p_a6).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface, p_a6 : Interface) : Interface {
var _sf=new Go_haxegoruntime_M6(_gr,[], p_rx, p_typ, p_meth, p_a1, p_a2, p_a3, p_a4, p_a5, p_a6).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface, p_a6 : Interface) : Go_haxegoruntime_M6
{return new Go_haxegoruntime_M6(gr,_bds, p_rx, p_typ, p_meth, p_a1, p_a2, p_a3, p_a4, p_a5, p_a6);
}
public function run():Go_haxegoruntime_M6 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(221,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:159:93

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_meth); // _t0 = make interface{} <- string (meth) *ssa.MakeInterface near goruntime.go:159:93
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_StringCompare") #end class Go_haxegoruntime_StringCompare extends StackFrameBasis implements StackFrame {  // goruntime.go:106:6
var p_a:String;
var p_b:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_a : String, p_b : String) {
super(gr,168,"Go_haxegoruntime_StringCompare");
this._bds=_bds;
this.p_a=p_a;
this.p_b=p_b;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Slice=null;
var _t1:Slice=null;
var _t2:Pointer=null;
var _t3:Int=0;
var _t4:Pointer=null;
var _t5:Int=0;
var _t6:Bool=false;
var _t7:Int=0;
var _t8:Int=0;
var _t9:Bool=false;
var _t10:Int=0;
var _t11:Int=0;
var _t12:Bool=false;
var _t13:Int=0;
var _t14:Bool=false;
var _t15:Pointer=null;
var _t16:Int=0;
var _t17:Pointer=null;
var _t18:Int=0;
var _t19:Bool=false;
var _t20:Int=0;
var _t21:Int=0;
var _t22:Int=0;
var _t23:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_a : String, p_b : String) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_StringCompare(0,[], p_a, p_b).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_a : String, p_b : String) : Int {
var _sf=new Go_haxegoruntime_StringCompare(_gr,[], p_a, p_b).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_a : String, p_b : String) : Go_haxegoruntime_StringCompare
{return new Go_haxegoruntime_StringCompare(gr,_bds, p_a, p_b);
}
public function run():Go_haxegoruntime_StringCompare {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(168,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(168,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(168,2);
this.SubFn2();
_Phi=2;
case 3: // for.loop
this.setLatest(168,3);
this.setPH(172);
_t10=((_Phi==0)?0:(_Phi==8)?_t20:0); // _t10 = phi [0.entry: 0:int, 8.if.done: t20] #i *ssa.Phi @ goruntime.go:110:2
this.SubFn3();
_Phi=3;
case 4: // cond.true
this.setLatest(172,4);
this.SubFn4();
_Phi=4;
case 5: // if.then
this.setLatest(172,5);
this.setPH(175);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ goruntime.go:113:4

case 6: // if.done
this.setLatest(175,6);
this.SubFn5();
_Phi=6;
case 7: // if.then
this.setLatest(175,7);
this.setPH(178);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ goruntime.go:116:4

case 8: // if.done
this.setLatest(178,8);
this.SubFn6();
_Phi=8;
case 9: // if.then
this.setLatest(178,9);
this.setPH(183);
_res= 0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int *ssa.Return @ goruntime.go:121:3

case 10: // if.done
this.setLatest(183,10);
this.SubFn7();
_Phi=10;
case 11: // if.then
this.setLatest(183,11);
this.setPH(186);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ goruntime.go:124:3

case 12: // if.done
this.setLatest(186,12);
this.setPH(188);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ goruntime.go:126:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
this.setPH(170);
_t0=Force.toUTF8slice(this._goroutine,p_a); // _t0 = convert []byte <- string (a) *ssa.Convert @ goruntime.go:108:13
this.setPH(171);
_t1=Force.toUTF8slice(this._goroutine,p_b); // _t1 = convert []byte <- string (b) *ssa.Convert @ goruntime.go:109:13
_Next=3; // jump 3.for.loop *ssa.Jump near goruntime.go:109:13
}// end SubFn0
private inline function SubFn1():Void {
var _t2:Pointer;
var _t3:Int;
var _t4:Pointer;
var _t5:Int;
var _t6:Bool;
this.setPH(174);
if((_t10<0)||(_t10>=_t0.len())) Scheduler.ioor(); // _t2 = &t0[t10] *ssa.IndexAddr @ goruntime.go:112:7 [POINTER]
_t2=_t0.addr(_t10);  // _t2 = &t0[t10] *ssa.IndexAddr @ goruntime.go:112:7 [POINTER]
_t3=(_t2.load()|0); // _t3 = *t2 *ssa.UnOp near goruntime.go:112:7
if((_t10<0)||(_t10>=_t1.len())) Scheduler.ioor(); // _t4 = &t1[t10] *ssa.IndexAddr @ goruntime.go:112:14 [POINTER]
_t4=_t1.addr(_t10);  // _t4 = &t1[t10] *ssa.IndexAddr @ goruntime.go:112:14 [POINTER]
_t5=(_t4.load()|0); // _t5 = *t4 *ssa.UnOp near goruntime.go:112:14
_t6=(Force.uintCompare(_t3,_t5)<0); // _t6 = t3 < t5 *ssa.BinOp @ goruntime.go:112:11
_Next=_t6 ? 5 : 6; // if t6 goto 5.if.then else 6.if.done *ssa.If near goruntime.go:112:11
}// end SubFn1
private inline function SubFn2():Void {
var _t7:Int;
var _t8:Int;
var _t9:Bool;
this.setPH(182);
_t7=({var _v=_t0;_v==null?0:_v.len();}); // _t7 = len(t0) *ssa.Call @ goruntime.go:120:8
_t8=({var _v=_t1;_v==null?0:_v.len();}); // _t8 = len(t1) *ssa.Call @ goruntime.go:120:18
_t9=(_t7==_t8); // _t9 = t7 == t8 *ssa.BinOp @ goruntime.go:120:12
_Next=_t9 ? 9 : 10; // if t9 goto 9.if.then else 10.if.done *ssa.If near goruntime.go:120:12
}// end SubFn2
private inline function SubFn3():Void {
var _t11:Int;
var _t12:Bool;
this.setPH(173);
_t11=({var _v=_t0;_v==null?0:_v.len();}); // _t11 = len(t0) *ssa.Call @ goruntime.go:111:14
_t12=(_t10<_t11); // _t12 = t10 < t11 *ssa.BinOp @ goruntime.go:111:9
_Next=_t12 ? 4 : 2; // if t12 goto 4.cond.true else 2.for.done *ssa.If near goruntime.go:111:9
}// end SubFn3
private inline function SubFn4():Void {
var _t13:Int;
var _t14:Bool;
_t13=({var _v=_t1;_v==null?0:_v.len();}); // _t13 = len(t1) *ssa.Call @ goruntime.go:111:30
_t14=(_t10<_t13); // _t14 = t10 < t13 *ssa.BinOp @ goruntime.go:111:25
_Next=_t14 ? 1 : 2; // if t14 goto 1.for.body else 2.for.done *ssa.If near goruntime.go:111:25
}// end SubFn4
private inline function SubFn5():Void {
var _t15:Pointer;
var _t16:Int;
var _t17:Pointer;
var _t18:Int;
var _t19:Bool;
this.setPH(177);
if((_t10<0)||(_t10>=_t0.len())) Scheduler.ioor(); // _t15 = &t0[t10] *ssa.IndexAddr @ goruntime.go:115:7 [POINTER]
_t15=_t0.addr(_t10);  // _t15 = &t0[t10] *ssa.IndexAddr @ goruntime.go:115:7 [POINTER]
_t16=(_t15.load()|0); // _t16 = *t15 *ssa.UnOp near goruntime.go:115:7
if((_t10<0)||(_t10>=_t1.len())) Scheduler.ioor(); // _t17 = &t1[t10] *ssa.IndexAddr @ goruntime.go:115:14 [POINTER]
_t17=_t1.addr(_t10);  // _t17 = &t1[t10] *ssa.IndexAddr @ goruntime.go:115:14 [POINTER]
_t18=(_t17.load()|0); // _t18 = *t17 *ssa.UnOp near goruntime.go:115:14
_t19=(Force.uintCompare(_t16,_t18)>0); // _t19 = t16 > t18 *ssa.BinOp @ goruntime.go:115:11
_Next=_t19 ? 7 : 8; // if t19 goto 7.if.then else 8.if.done *ssa.If near goruntime.go:115:11
}// end SubFn5
private inline function SubFn6():Void {
_t20=(_t10+1); // _t20 = t10 + 1:int *ssa.BinOp near goruntime.go:115:11
_Next=3; // jump 3.for.loop *ssa.Jump near goruntime.go:115:11
}// end SubFn6
private inline function SubFn7():Void {
var _t21:Int;
var _t22:Int;
var _t23:Bool;
this.setPH(185);
_t21=({var _v=_t0;_v==null?0:_v.len();}); // _t21 = len(t0) *ssa.Call @ goruntime.go:123:8
_t22=({var _v=_t1;_v==null?0:_v.len();}); // _t22 = len(t1) *ssa.Call @ goruntime.go:123:17
_t23=(_t21<_t22); // _t23 = t21 < t22 *ssa.BinOp @ goruntime.go:123:12
_Next=_t23 ? 11 : 12; // if t23 goto 11.if.then else 12.if.done *ssa.If near goruntime.go:123:12
}// end SubFn7
}
#if (!php) private #end class Go_main_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,185,"Go_main_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _t1:Channel<Array<Dynamic>>=null;
var _SF1:StackFrame;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_main_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_main_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_main_init
{return new Go_main_init(gr,_bds);
}
public function run():Go_main_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(185,0);
this.SubFn0();

case 1: // init.start
this.setLatest(185,1);
this.SubFn1();
Go_main_init_36_1.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(185,-1);
 // _t2 = init$1() *ssa.Call near goruntime.go:123:12 [REGISTER VALUE UN-USED]
this.SubFn2();

case 2: // init.done
this.setLatest(185,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near goruntime.go:123:12

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Bool;
_t0=Go.main_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near goruntime.go:123:12
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near goruntime.go:123:12
}// end SubFn0
private inline function SubFn1():Void {
var _t1:Channel<Array<Dynamic>>;
Go.main_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near goruntime.go:123:12
this.setPH(17);
_t1=new Channel<Array<Dynamic>>(100); // _t1 = make chan main.mouseEvent 100:int *ssa.MakeChan @ main.go:17:23
Go.main_mouseEvents.store(_t1); // *mouseEvents = t1 *ssa.Store near main.go:17:23
}// end SubFn1
private inline function SubFn2():Void {
_Next=2; // jump 2.init.done *ssa.Jump near main.go:17:23
}// end SubFn2
}
#if js @:expose("Go_hxutil_StringsUTF8") #end class Go_hxutil_StringsUTF8 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:27:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1020,"Go_hxutil_StringsUTF8");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:Int=0;
var _t1:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_hxutil_StringsUTF8(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : Bool {
var _sf=new Go_hxutil_StringsUTF8(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_hxutil_StringsUTF8
{return new Go_hxutil_StringsUTF8(gr,_bds);
}
public function run():Go_hxutil_StringsUTF8 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1020,0);
_t0='字'.length; // _t0 = Zilen() *ssa.Call @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:27:39
this.SubFn0();
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:27:27

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t1=(Force.uintCompare(_t0,3)==0); // _t1 = t0 == 3:uint *ssa.BinOp @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:27:42
}// end SubFn0
}
#if js @:expose("Go_utf16_DecodeRune") #end class Go_utf16_DecodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:37:6
var p_r1:Int;
var p_r2:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r1 : Int, p_r2 : Int) {
super(gr,479,"Go_utf16_DecodeRune");
this._bds=_bds;
this.p_r1=p_r1;
this.p_r2=p_r2;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Bool=false;
var _t1:Int=0;
var _t2:Int=0;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Int=0;
var _t6:Bool=false;
var _t7:Bool=false;
var _t8:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_r1 : Int, p_r2 : Int) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf16_DecodeRune(0,[], p_r1, p_r2).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r1 : Int, p_r2 : Int) : Int {
var _sf=new Go_utf16_DecodeRune(_gr,[], p_r1, p_r2).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r1 : Int, p_r2 : Int) : Go_utf16_DecodeRune
{return new Go_utf16_DecodeRune(gr,_bds, p_r1, p_r2);
}
public function run():Go_utf16_DecodeRune {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(479,0);
this.SubFn0();

case 1: // if.then
this.setLatest(479,1);
this.SubFn1();
this.setPH(481);
_res= _t5;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:3

case 2: // if.done
this.setLatest(481,2);
this.setPH(483);
_res= 65533;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:41:2

case 3: // cond.true
this.setLatest(483,3);
this.SubFn2();

case 4: // cond.true
this.setLatest(483,4);
this.SubFn3();

case 5: // cond.true
this.setLatest(483,5);
this.SubFn4();

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Bool;
this.setPH(480);
_t0=(55296<=p_r1); // _t0 = 55296:rune <= r1 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:11
_Next=_t0 ? 5 : 2; // if t0 goto 5.cond.true else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:11
}// end SubFn0
private inline function SubFn1():Void {
var _t1:Int;
var _t2:Int;
var _t3:Int;
var _t4:Int;
this.setPH(481);
_t1=Force.toInt32((p_r1-55296)); // _t1 = r1 - 55296:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:19
_t2=(_t1<<GOint64.toInt(GOint64.make(0x0,0xa))); // _t2 = t1 << 10:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:26
_t3=Force.toInt32((p_r2-56320)); // _t3 = r2 - 56320:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:43
_t4=Force.toInt32((_t2|_t3)); // _t4 = t2 | t3 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:31
_t5=Force.toInt32((_t4+65536)); // _t5 = t4 + 65536:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:52
}// end SubFn1
private inline function SubFn2():Void {
var _t6:Bool;
this.setPH(480);
_t6=(p_r2<57344); // _t6 = r2 < 57344:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:52
_Next=_t6 ? 1 : 2; // if t6 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:52
}// end SubFn2
private inline function SubFn3():Void {
var _t7:Bool;
_t7=(56320<=p_r2); // _t7 = 56320:rune <= r2 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:40
_Next=_t7 ? 3 : 2; // if t7 goto 3.cond.true else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:40
}// end SubFn3
private inline function SubFn4():Void {
var _t8:Bool;
_t8=(p_r1<56320); // _t8 = r1 < 56320:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:23
_Next=_t8 ? 4 : 2; // if t8 goto 4.cond.true else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:23
}// end SubFn4
}
#if js @:expose("Go_haxegoruntime_M3") #end class Go_haxegoruntime_M3 extends StackFrameBasis implements StackFrame {  // goruntime.go:156:6
var p_rx:Interface;
var p_typ:String;
var p_meth:String;
var p_a1:Interface;
var p_a2:Interface;
var p_a3:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface) {
super(gr,218,"Go_haxegoruntime_M3");
this._bds=_bds;
this.p_rx=p_rx;
this.p_typ=p_typ;
this.p_meth=p_meth;
this.p_a1=p_a1;
this.p_a2=p_a2;
this.p_a3=p_a3;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_M3(0,[], p_rx, p_typ, p_meth, p_a1, p_a2, p_a3).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface) : Interface {
var _sf=new Go_haxegoruntime_M3(_gr,[], p_rx, p_typ, p_meth, p_a1, p_a2, p_a3).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface) : Go_haxegoruntime_M3
{return new Go_haxegoruntime_M3(gr,_bds, p_rx, p_typ, p_meth, p_a1, p_a2, p_a3);
}
public function run():Go_haxegoruntime_M3 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(218,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:156:93

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_meth); // _t0 = make interface{} <- string (meth) *ssa.MakeInterface near goruntime.go:156:93
}// end SubFn0
}
#if (!php) private #end class Go_haxegoruntime_funcentry_go extends StackFrameBasis implements StackFrame {  // goruntime.go:361:6
var p_arg0:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer) {
super(gr,423,"Go_haxegoruntime_funcentry_go");
this._bds=_bds;
this.p_arg0=p_arg0;
Scheduler.push(gr,this);
}
var _res:Dynamic;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_arg0 : Pointer) : Dynamic {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_funcentry_go(0,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_arg0 : Pointer) : Dynamic {
var _sf=new Go_haxegoruntime_funcentry_go(_gr,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer) : Go_haxegoruntime_funcentry_go
{return new Go_haxegoruntime_funcentry_go(gr,_bds, p_arg0);
}
public function run():Go_haxegoruntime_funcentry_go {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(423,0);
this.SubFn0();
this.setPH(424);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(424,-1);
 // panic t0 *ssa.Panic @ goruntime.go:362:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,"runtime.funcentry_go() not yet implemented"); // _t0 = make interface{} <- string ("runtime.funcentry...":string) *ssa.MakeInterface near goruntime.go:362:7
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_Platform") #end class Go_haxegoruntime_Platform extends StackFrameBasis implements StackFrame {  // goruntime.go:134:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,196,"Go_haxegoruntime_Platform");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_Platform(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_haxegoruntime_Platform(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_haxegoruntime_Platform
{return new Go_haxegoruntime_Platform(gr,_bds);
}
public function run():Go_haxegoruntime_Platform {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(196,0);
_res= "go";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "go":string *ssa.Return @ goruntime.go:134:26

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_utf8_DecodeLastRuneInString") #end class Go_utf8_DecodeLastRuneInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:276:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,826,"Go_utf8_DecodeLastRuneInString");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
var _res:{r0:Int, r1:Int};
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Bool=false;
var _t2:Int=0;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:Int=0;
var _t7:Bool=false;
var _t8:Int=0;
var _t9:Int=0;
var _t10:Int=0;
var _SF1:StackFrame;
var _t11:Bool=false;
var _t12:Bool=false;
var _t13:Int=0;
var _t14:Bool=false;
var _t15:Int=0;
var _t16:Int=0;
var _t17:String="";
var _SF2:StackFrame;
var _t18:{r0:Int,r1:Int}=null;
var _t19:Int=0;
var _t20:Int=0;
var _t21:Int=0;
var _t22:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : String) : {r0:Int, r1:Int} {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_DecodeLastRuneInString(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : String) : {r0:Int, r1:Int} {
var _sf=new Go_utf8_DecodeLastRuneInString(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : String) : Go_utf8_DecodeLastRuneInString
{return new Go_utf8_DecodeLastRuneInString(gr,_bds, p_s);
}
public function run():Go_utf8_DecodeLastRuneInString {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(826,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(826,1);
this.setPH(829);
_res= {r0:65533,r1:0};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:279:3

case 2: // if.done
this.setLatest(829,2);
this.SubFn1();
_Phi=2;
case 3: // if.then
this.setLatest(829,3);
this.setPH(834);
_res= {r0:_t4,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:284:3

case 4: // if.done
this.setLatest(834,4);
this.SubFn2();
_Phi=4;
case 5: // if.then
this.setLatest(834,5);
this.SubFn3();
_Phi=5;
case 6: // if.done
this.setLatest(834,6);
this.setPH(839);
_t8=((_Phi==4)?_t6:(_Phi==5)?0:0); // _t8 = phi [4.if.done: t6, 5.if.then: 0:int] #lim *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:289:2
this.SubFn4();
_Phi=6;
case 7: // for.body
this.setLatest(839,7);
this.SubFn5();
this.setPH(844);
_SF1=Go_utf8_RuneStart.call(this._goroutine,[],_t10);
_Next = -1;
return this;
case -1:
this.setLatest(844,-1);
_t11=_SF1.res();
 // _t11 = RuneStart(t10) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:294:15
this.SubFn6();
_Phi=7;
case 8: // for.done
this.setLatest(844,8);
this.SubFn7();
_Phi=8;
case 9: // for.loop
this.setLatest(844,9);
this.setPH(831);
_t13=((_Phi==6)?_t9:(_Phi==10)?_t15:0); // _t13 = phi [6.if.done: t9, 10.if.done: t15] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:281:2
this.SubFn8();
_Phi=9;
case 10: // if.done
this.setLatest(831,10);
this.SubFn9();
_Phi=10;
case 11: // if.then
this.setLatest(831,11);
this.SubFn10();
_Phi=11;
case 12: // if.done
this.setLatest(831,12);
_t16=((_Phi==8)?_t13:(_Phi==11)?0:0); // _t16 = phi [8.for.done: t13, 11.if.then: 0:int] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:281:2
this.SubFn11();
this.setPH(851);
_SF2=Go_utf8_DecodeRuneInString.call(this._goroutine,[],_t17);
_Next = -2;
return this;
case -2:
this.setLatest(851,-2);
_t18=_SF2.res();
 // _t18 = DecodeRuneInString(t17) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:30
this.SubFn12();
_Phi=12;
case 13: // if.then
this.setLatest(851,13);
this.setPH(853);
_res= {r0:65533,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:303:3

case 14: // if.done
this.setLatest(853,14);
this.setPH(855);
_res= {r0:_t19,r1:_t20};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t19, t20 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:305:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t1:Bool;
this.setPH(827);
_t0=Force.toUTF8length(this._goroutine,p_s); // _t0 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:277:12
this.setPH(828);
_t1=(_t0==0); // _t1 = t0 == 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:278:9
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:278:9
}// end SubFn0
private inline function SubFn1():Void {
var _t3:Int;
var _t5:Bool;
this.setPH(831);
_t2=(_t0-1); // _t2 = t0 - 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:281:15
this.setPH(832);
_t3=Force.toUTF8slice(this._goroutine,p_s).getAt(_t2); // _t3 = s[t2] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:282:12
_t4=_t3; // _t4 = convert rune <- uint8 (t3) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:282:10
this.setPH(833);
_t5=(_t4<128); // _t5 = t4 < 128:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:283:7
_Next=_t5 ? 3 : 4; // if t5 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:283:7
}// end SubFn1
private inline function SubFn2():Void {
var _t7:Bool;
this.setPH(839);
_t6=(_t0-4); // _t6 = t0 - 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:289:13
this.setPH(840);
_t7=(_t6<0); // _t7 = t6 < 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:290:9
_Next=_t7 ? 5 : 6; // if t7 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:290:9
}// end SubFn2
private inline function SubFn3():Void {
_Next=6; // jump 6.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:290:9
}// end SubFn3
private inline function SubFn4():Void {
_t9=(_t2-1); // _t9 = t2 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:290:9
_Next=9; // jump 9.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:290:9
}// end SubFn4
private inline function SubFn5():Void {
this.setPH(844);
_t10=Force.toUTF8slice(this._goroutine,p_s).getAt(_t13); // _t10 = s[t13] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:294:17
}// end SubFn5
private inline function SubFn6():Void {
_Next=_t11 ? 8 : 10; // if t11 goto 8.for.done else 10.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:294:17
}// end SubFn6
private inline function SubFn7():Void {
var _t12:Bool;
this.setPH(848);
_t12=(_t13<0); // _t12 = t13 < 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:298:11
_Next=_t12 ? 11 : 12; // if t12 goto 11.if.then else 12.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:298:11
}// end SubFn7
private inline function SubFn8():Void {
var _t14:Bool;
this.setPH(843);
_t14=(_t13>=_t8); // _t14 = t13 >= t8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:293:21
_Next=_t14 ? 7 : 8; // if t14 goto 7.for.body else 8.for.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:293:21
}// end SubFn8
private inline function SubFn9():Void {
_t15=(_t13-1); // _t15 = t13 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:293:21
_Next=9; // jump 9.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:293:21
}// end SubFn9
private inline function SubFn10():Void {
_Next=12; // jump 12.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:293:21
}// end SubFn10
private inline function SubFn11():Void {
this.setPH(851);
_t17=Force.toRawString(this._goroutine,Force.toUTF8slice(this._goroutine,p_s).subSlice(_t16,_t0)); // _t17 = slice s[t16:t0] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:32
}// end SubFn11
private inline function SubFn12():Void {
var _t21:Int;
var _t22:Bool;
_t19=_t18.r0; // _t19 = extract t18 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:32
_t20=_t18.r1; // _t20 = extract t18 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:32
this.setPH(852);
_t21=(_t16+_t20); // _t21 = t16 + t20 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:302:10
_t22=(_t21!=_t0); // _t22 = t21 != t0 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:302:16
_Next=_t22 ? 13 : 14; // if t22 goto 13.if.then else 14.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:302:16
}// end SubFn12
}
#if js @:expose("Go_hxutil_Platform") #end class Go_hxutil_Platform extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:17:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1010,"Go_hxutil_Platform");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_hxutil_Platform(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_hxutil_Platform(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_hxutil_Platform
{return new Go_hxutil_Platform(gr,_bds);
}
public function run():Go_hxutil_Platform {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1010,0);
_res= "go";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "go":string *ssa.Return @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:17:26

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_utf16_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1010,"Go_utf16_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf16_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_utf16_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_utf16_init
{return new Go_utf16_init(gr,_bds);
}
public function run():Go_utf16_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1010,0);
this.SubFn0();

case 1: // init.start
this.setLatest(1010,1);
this.SubFn1();

case 2: // init.done
this.setLatest(1010,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:17:26

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Bool;
_t0=Go.utf16_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:17:26
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:17:26
}// end SubFn0
private inline function SubFn1():Void {
Go.utf16_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:17:26
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:17:26
}// end SubFn1
}
#if js @:expose("Go_hxutil_HAXE") #end class Go_hxutil_HAXE extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:10:6
var p_code:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_code : String) {
super(gr,1003,"Go_hxutil_HAXE");
this._bds=_bds;
this.p_code=p_code;
Scheduler.push(gr,this);
}
var _res:Dynamic;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( p_code : String) : Dynamic {
if(!Go.doneInit) Go.init();
var _sf=new Go_hxutil_HAXE(0,[], p_code).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_code : String) : Dynamic {
var _sf=new Go_hxutil_HAXE(_gr,[], p_code).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_code : String) : Go_hxutil_HAXE
{return new Go_hxutil_HAXE(gr,_bds, p_code);
}
public function run():Go_hxutil_HAXE {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1003,0);
_res= 0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:uintptr *ssa.Return @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:10:40

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_haxegoruntime_Runes2Raw") #end class Go_haxegoruntime_Runes2Raw extends StackFrameBasis implements StackFrame {  // goruntime.go:76:6
var p_r:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Slice) {
super(gr,138,"Go_haxegoruntime_Runes2Raw");
this._bds=_bds;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Bool=false;
var _SF1:StackFrame;
var _t2:Slice=null;
var _t3:Int=0;
var _t4:Slice=null;
var _t5:Int=0;
var _SF2:StackFrame;
var _t6:Slice=null;
var _t7:Int=0;
var _t8:Slice=null;
var _t9:Int=0;
var _t10:Bool=false;
var _t11:Int=0;
var _t12:Int=0;
var _t13:Bool=false;
var _t14:Pointer=null;
var _t15:Pointer=null;
var _t16:Int=0;
var _t17:Int=0;
var _SF3:StackFrame;
var _t19:Pointer=null;
var _t20:Slice=null;
var _t21:Int=0;
var _t22:Int=0;
var _t23:Bool=false;
var _t24:Pointer=null;
var _t25:Pointer=null;
var _t26:Int=0;
var _t27:Int=0;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_r : Slice) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_Runes2Raw(0,[], p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r : Slice) : Slice {
var _sf=new Go_haxegoruntime_Runes2Raw(_gr,[], p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r : Slice) : Go_haxegoruntime_Runes2Raw
{return new Go_haxegoruntime_Runes2Raw(gr,_bds, p_r);
}
public function run():Go_haxegoruntime_Runes2Raw {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(138,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(138,1);
this.setPH(141);
_SF1=Go_haxegoruntime_RunesToUTF16.call(this._goroutine,[],p_r);
_Next = -1;
return this;
case -1:
this.setLatest(141,-1);
_t2=_SF1.res();
 // _t2 = RunesToUTF16(r) *ssa.Call @ goruntime.go:79:29
this.SubFn1();
_Phi=1;
case 2: // switch.body
this.setLatest(141,2);
this.setPH(148);
_SF2=Go_haxegoruntime_RunesToUTF8.call(this._goroutine,[],p_r);
_Next = -2;
return this;
case -2:
this.setLatest(148,-2);
_t6=_SF2.res();
 // _t6 = RunesToUTF8(r) *ssa.Call @ goruntime.go:86:27
this.SubFn2();
_Phi=2;
case 3: // switch.next
this.setLatest(148,3);
this.SubFn3();
_Phi=3;
case 4: // rangeindex.loop
this.setLatest(148,4);
_t11=((_Phi==1)?(-1):(_Phi==5)?_t12:0); // _t11 = phi [1.switch.body: -1:int, 5.rangeindex.body: t12] *ssa.Phi near goruntime.go:86:27
this.SubFn4();
_Phi=4;
case 5: // rangeindex.body
this.setLatest(148,5);
this.SubFn5();
_Phi=5;
case 6: // rangeindex.done
this.setLatest(148,6);
this.setPH(146);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ goruntime.go:84:3

case 7: // switch.next
this.setLatest(146,7);
this.setPH(156);
throw 'goruntime.Runes2Raw() unrecognised encoding'; // _t18 = github.com/elliott5/gohaxelib/hxutil.HAXE("throw 'goruntime....":string) *ssa.Call @ goruntime.go:94:14 [REGISTER VALUE UN-USED]
this.SubFn6();
this.setPH(158);
_res= _t20;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t20 *ssa.Return @ goruntime.go:96:2

case 8: // rangeindex.loop
this.setLatest(158,8);
_t21=((_Phi==2)?(-1):(_Phi==9)?_t22:0); // _t21 = phi [2.switch.body: -1:int, 9.rangeindex.body: t22] *ssa.Phi near goruntime.go:96:2
this.SubFn7();
_Phi=8;
case 9: // rangeindex.body
this.setLatest(158,9);
this.SubFn8();
_Phi=9;
case 10: // rangeindex.done
this.setLatest(158,10);
this.setPH(153);
_res= _t8;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t8 *ssa.Return @ goruntime.go:91:3

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t1:Bool;
_t0=(Go.haxegoruntime_ZiLen.load()|0); // _t0 = *ZiLen *ssa.UnOp near goruntime.go:91:3
_t1=(Force.uintCompare(_t0,1)==0); // _t1 = t0 == 1:uint *ssa.BinOp near goruntime.go:91:3
_Next=_t1 ? 1 : 3; // if t1 goto 1.switch.body else 3.switch.next *ssa.If near goruntime.go:91:3
}// end SubFn0
private inline function SubFn1():Void {
var _t3:Int;
this.setPH(142);
_t3=({var _v=_t2;_v==null?0:_v.len();}); // _t3 = len(t2) *ssa.Call @ goruntime.go:80:39
_t4=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t3) _v[_i]=0; _v;}),0,_t3); // _t4 = make []int t3 t3 *ssa.MakeSlice @ goruntime.go:80:28
_t5=({var _v=_t2;_v==null?0:_v.len();}); // _t5 = len(t2) *ssa.Call near goruntime.go:80:28
_Next=4; // jump 4.rangeindex.loop *ssa.Jump near goruntime.go:80:28
}// end SubFn1
private inline function SubFn2():Void {
var _t7:Int;
this.setPH(149);
_t7=({var _v=_t6;_v==null?0:_v.len();}); // _t7 = len(t6) *ssa.Call @ goruntime.go:87:39
_t8=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t7) _v[_i]=0; _v;}),0,_t7); // _t8 = make []int t7 t7 *ssa.MakeSlice @ goruntime.go:87:28
_t9=({var _v=_t6;_v==null?0:_v.len();}); // _t9 = len(t6) *ssa.Call near goruntime.go:87:28
_Next=8; // jump 8.rangeindex.loop *ssa.Jump near goruntime.go:87:28
}// end SubFn2
private inline function SubFn3():Void {
var _t10:Bool;
_t10=(Force.uintCompare(_t0,3)==0); // _t10 = t0 == 3:uint *ssa.BinOp near goruntime.go:87:28
_Next=_t10 ? 2 : 7; // if t10 goto 2.switch.body else 7.switch.next *ssa.If near goruntime.go:87:28
}// end SubFn3
private inline function SubFn4():Void {
var _t13:Bool;
_t12=(_t11+1); // _t12 = t11 + 1:int *ssa.BinOp near goruntime.go:87:28
_t13=(_t12<_t5); // _t13 = t12 < t5 *ssa.BinOp near goruntime.go:87:28
_Next=_t13 ? 5 : 6; // if t13 goto 5.rangeindex.body else 6.rangeindex.done *ssa.If near goruntime.go:87:28
}// end SubFn4
private inline function SubFn5():Void {
var _t14:Pointer;
var _t15:Pointer;
var _t16:Int;
var _t17:Int;
this.setPH(144);
if((_t12<0)||(_t12>=_t4.len())) Scheduler.ioor(); // _t14 = &t4[t12] *ssa.IndexAddr @ goruntime.go:82:12 [POINTER]
_t14=_t4.addr(_t12);  // _t14 = &t4[t12] *ssa.IndexAddr @ goruntime.go:82:12 [POINTER]
if((_t12<0)||(_t12>=_t2.len())) Scheduler.ioor(); // _t15 = &t2[t12] *ssa.IndexAddr @ goruntime.go:82:36 [POINTER]
_t15=_t2.addr(_t12);  // _t15 = &t2[t12] *ssa.IndexAddr @ goruntime.go:82:36 [POINTER]
_t16=(_t15.load()|0); // _t16 = *t15 *ssa.UnOp near goruntime.go:82:36
_t17=_t16; // _t17 = convert int <- uint16 (t16) *ssa.Convert @ goruntime.go:82:25
_t14.store(_t17); // *t14 = t17 *ssa.Store near goruntime.go:82:25
_Next=4; // jump 4.rangeindex.loop *ssa.Jump near goruntime.go:82:25
}// end SubFn5
private inline function SubFn6():Void {
var _t19:Pointer;
this.setPH(158);
_t19=new Pointer({var _v=new Array<Int>();for(_vi in 0...0){_v[_vi]=0;}; _v;}); // _t19 = new [0]int (slicelit) *ssa.Alloc @ goruntime.go:96:14
_t20=new Slice(_t19,0,-1); // _t20 = slice t19[:] *ssa.Slice @ goruntime.go:96:14
}// end SubFn6
private inline function SubFn7():Void {
var _t23:Bool;
_t22=(_t21+1); // _t22 = t21 + 1:int *ssa.BinOp near goruntime.go:96:14
_t23=(_t22<_t9); // _t23 = t22 < t9 *ssa.BinOp near goruntime.go:96:14
_Next=_t23 ? 9 : 10; // if t23 goto 9.rangeindex.body else 10.rangeindex.done *ssa.If near goruntime.go:96:14
}// end SubFn7
private inline function SubFn8():Void {
var _t24:Pointer;
var _t25:Pointer;
var _t26:Int;
var _t27:Int;
this.setPH(151);
if((_t22<0)||(_t22>=_t8.len())) Scheduler.ioor(); // _t24 = &t8[t22] *ssa.IndexAddr @ goruntime.go:89:12 [POINTER]
_t24=_t8.addr(_t22);  // _t24 = &t8[t22] *ssa.IndexAddr @ goruntime.go:89:12 [POINTER]
if((_t22<0)||(_t22>=_t6.len())) Scheduler.ioor(); // _t25 = &t6[t22] *ssa.IndexAddr @ goruntime.go:89:35 [POINTER]
_t25=_t6.addr(_t22);  // _t25 = &t6[t22] *ssa.IndexAddr @ goruntime.go:89:35 [POINTER]
_t26=(_t25.load()|0); // _t26 = *t25 *ssa.UnOp near goruntime.go:89:35
_t27=_t26; // _t27 = convert int <- byte (t26) *ssa.Convert @ goruntime.go:89:25
_t24.store(_t27); // *t24 = t27 *ssa.Store near goruntime.go:89:25
_Next=8; // jump 8.rangeindex.loop *ssa.Jump near goruntime.go:89:25
}// end SubFn8
}
#if js @:expose("Go_haxegoruntime_M1") #end class Go_haxegoruntime_M1 extends StackFrameBasis implements StackFrame {  // goruntime.go:154:6
var p_rx:Interface;
var p_typ:String;
var p_meth:String;
var p_a1:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface) {
super(gr,216,"Go_haxegoruntime_M1");
this._bds=_bds;
this.p_rx=p_rx;
this.p_typ=p_typ;
this.p_meth=p_meth;
this.p_a1=p_a1;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_M1(0,[], p_rx, p_typ, p_meth, p_a1).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface) : Interface {
var _sf=new Go_haxegoruntime_M1(_gr,[], p_rx, p_typ, p_meth, p_a1).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface) : Go_haxegoruntime_M1
{return new Go_haxegoruntime_M1(gr,_bds, p_rx, p_typ, p_meth, p_a1);
}
public function run():Go_haxegoruntime_M1 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(216,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:154:93

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_meth); // _t0 = make interface{} <- string (meth) *ssa.MakeInterface near goruntime.go:154:93
}// end SubFn0
}
#if (!php) private #end class Go_haxegoruntime_funcline_go extends StackFrameBasis implements StackFrame {  // goruntime.go:353:6
var p_arg0:Pointer;
var p_arg1:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer, p_arg1 : Dynamic) {
super(gr,415,"Go_haxegoruntime_funcline_go");
this._bds=_bds;
this.p_arg0=p_arg0;
this.p_arg1=p_arg1;
Scheduler.push(gr,this);
}
var _res:{r0:String, r1:Int};
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_arg0 : Pointer, p_arg1 : Dynamic) : {r0:String, r1:Int} {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_funcline_go(0,[], p_arg0, p_arg1).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_arg0 : Pointer, p_arg1 : Dynamic) : {r0:String, r1:Int} {
var _sf=new Go_haxegoruntime_funcline_go(_gr,[], p_arg0, p_arg1).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer, p_arg1 : Dynamic) : Go_haxegoruntime_funcline_go
{return new Go_haxegoruntime_funcline_go(gr,_bds, p_arg0, p_arg1);
}
public function run():Go_haxegoruntime_funcline_go {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(415,0);
this.SubFn0();
this.setPH(416);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(416,-1);
 // panic t0 *ssa.Panic @ goruntime.go:354:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,"runtime.funcline_go() not yet implemented"); // _t0 = make interface{} <- string ("runtime.funcline_...":string) *ssa.MakeInterface near goruntime.go:354:7
}// end SubFn0
}
#if js @:expose("Go_utf8_DecodeRuneInString") #end class Go_utf8_DecodeRuneInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:229:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,779,"Go_utf8_DecodeRuneInString");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
var _res:{r0:Int, r1:Int};
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:Int,r1:Int,r2:Bool}=null;
var _t1:Int=0;
var _t2:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : String) : {r0:Int, r1:Int} {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_DecodeRuneInString(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : String) : {r0:Int, r1:Int} {
var _sf=new Go_utf8_DecodeRuneInString(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : String) : Go_utf8_DecodeRuneInString
{return new Go_utf8_DecodeRuneInString(gr,_bds, p_s);
}
public function run():Go_utf8_DecodeRuneInString {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(779,0);
this.setPH(780);
_SF1=Go_utf8_decodeRuneInStringInternal.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(780,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInStringInternal(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:230:41
this.SubFn0();
this.setPH(781);
_res= {r0:_t1,r1:_t2};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1, t2 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2
 // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2 [REGISTER VALUE UN-USED]
}// end SubFn0
}
#if (!php) private #end class Go_hxutil_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,781,"Go_hxutil_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_hxutil_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_hxutil_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_hxutil_init
{return new Go_hxutil_init(gr,_bds);
}
public function run():Go_hxutil_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(781,0);
this.SubFn0();

case 1: // init.start
this.setLatest(781,1);
this.SubFn1();

case 2: // init.done
this.setLatest(781,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Bool;
_t0=Go.hxutil_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2
}// end SubFn0
private inline function SubFn1():Void {
Go.hxutil_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2
_Next=2; // jump 2.init.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2
}// end SubFn1
}
#if js @:expose("Go_utf8_DecodeRune") #end class Go_utf8_DecodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:219:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,769,"Go_utf8_DecodeRune");
this._bds=_bds;
this.p_p=p_p;
Scheduler.push(gr,this);
}
var _res:{r0:Int, r1:Int};
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:Int,r1:Int,r2:Bool}=null;
var _t1:Int=0;
var _t2:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_p : Slice) : {r0:Int, r1:Int} {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_DecodeRune(0,[], p_p).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_p : Slice) : {r0:Int, r1:Int} {
var _sf=new Go_utf8_DecodeRune(_gr,[], p_p).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_p : Slice) : Go_utf8_DecodeRune
{return new Go_utf8_DecodeRune(gr,_bds, p_p);
}
public function run():Go_utf8_DecodeRune {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(769,0);
this.setPH(770);
_SF1=Go_utf8_decodeRuneInternal.call(this._goroutine,[],p_p);
_Next = -1;
return this;
case -1:
this.setLatest(770,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInternal(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:220:33
this.SubFn0();
this.setPH(771);
_res= {r0:_t1,r1:_t2};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1, t2 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:221:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:221:2
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:221:2
 // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:221:2 [REGISTER VALUE UN-USED]
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_Rune2Raw") #end class Go_haxegoruntime_Rune2Raw extends StackFrameBasis implements StackFrame {  // goruntime.go:99:6
var p_oneRune:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_oneRune : Int) {
super(gr,161,"Go_haxegoruntime_Rune2Raw");
this._bds=_bds;
this.p_oneRune=p_oneRune;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _t0:Slice=null;
var _t1:Pointer=null;
var _SF1:StackFrame;
var _t2:Slice=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_oneRune : Int) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_Rune2Raw(0,[], p_oneRune).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_oneRune : Int) : Slice {
var _sf=new Go_haxegoruntime_Rune2Raw(_gr,[], p_oneRune).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_oneRune : Int) : Go_haxegoruntime_Rune2Raw
{return new Go_haxegoruntime_Rune2Raw(gr,_bds, p_oneRune);
}
public function run():Go_haxegoruntime_Rune2Raw {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(161,0);
this.SubFn0();
this.setPH(164);
_SF1=Go_haxegoruntime_Runes2Raw.call(this._goroutine,[],_t0);
_Next = -1;
return this;
case -1:
this.setLatest(164,-1);
_t2=_SF1.res();
 // _t2 = Runes2Raw(t0) *ssa.Call @ goruntime.go:102:18
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ goruntime.go:102:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t1:Pointer;
this.setPH(162);
_t0=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0...1) _v[_i]=0; _v;}),0,1); // _t0 = make []rune 1:int 1:int *ssa.MakeSlice @ goruntime.go:100:11
this.setPH(163);
if((0<0)||(0>=_t0.len())) Scheduler.ioor(); // _t1 = &t0[0:int] *ssa.IndexAddr @ goruntime.go:101:3 [POINTER]
_t1=_t0.addr(0);  // _t1 = &t0[0:int] *ssa.IndexAddr @ goruntime.go:101:3 [POINTER]
_t1.store(p_oneRune); // *t1 = oneRune *ssa.Store near goruntime.go:101:3
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_SetFinalizer") #end class Go_haxegoruntime_SetFinalizer extends StackFrameBasis implements StackFrame {  // goruntime.go:350:6
var p_x:Interface;
var p_f:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_x : Interface, p_f : Interface) {
super(gr,412,"Go_haxegoruntime_SetFinalizer");
this._bds=_bds;
this.p_x=p_x;
this.p_f=p_f;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_x : Interface, p_f : Interface) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_SetFinalizer(0,[], p_x, p_f).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_x : Interface, p_f : Interface) : Void {
var _sf=new Go_haxegoruntime_SetFinalizer(_gr,[], p_x, p_f).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_x : Interface, p_f : Interface) : Go_haxegoruntime_SetFinalizer
{return new Go_haxegoruntime_SetFinalizer(gr,_bds, p_x, p_f);
}
public function run():Go_haxegoruntime_SetFinalizer {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(412,0);
this.SubFn0();
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(412,-1);
 // panic t0 *ssa.Panic @ goruntime.go:350:49

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,"runtime.SetFinalizer() not yet implemented"); // _t0 = make interface{} <- string ("runtime.SetFinali...":string) *ssa.MakeInterface near goruntime.go:350:49
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_M0") #end class Go_haxegoruntime_M0 extends StackFrameBasis implements StackFrame {  // goruntime.go:153:6
var p_rx:Interface;
var p_typ:String;
var p_meth:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String) {
super(gr,215,"Go_haxegoruntime_M0");
this._bds=_bds;
this.p_rx=p_rx;
this.p_typ=p_typ;
this.p_meth=p_meth;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_rx : Interface, p_typ : String, p_meth : String) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_M0(0,[], p_rx, p_typ, p_meth).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_rx : Interface, p_typ : String, p_meth : String) : Interface {
var _sf=new Go_haxegoruntime_M0(_gr,[], p_rx, p_typ, p_meth).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String) : Go_haxegoruntime_M0
{return new Go_haxegoruntime_M0(gr,_bds, p_rx, p_typ, p_meth);
}
public function run():Go_haxegoruntime_M0 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(215,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:153:93

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_meth); // _t0 = make interface{} <- string (meth) *ssa.MakeInterface near goruntime.go:153:93
}// end SubFn0
}
#if (!php) private #end class Go_main_handleMouse extends StackFrameBasis implements StackFrame {  // main.go:35:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,35,"Go_main_handleMouse");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Pointer=null;
var _t1:Channel<Array<Dynamic>>=null;
var _t2:Array<Dynamic>=null;
var _t3:Array<Dynamic>=null;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:Float=0.0;
var _t7:Array<Dynamic>=null;
var _t8:Float=0.0;
var _t9:Float=0.0;
var _t10:Float=0.0;
var _t11:Array<Dynamic>=null;
var _t12:Float=0.0;
var _t13:Float=0.0;
var _t14:Channel<Array<Dynamic>>=null;
var _t15:Array<Dynamic>=null;
var _t16:Array<Dynamic>=null;
var _t17:Int=0;
var _t18:Bool=false;
var _t19:Bool=false;
var _t20:Array<Dynamic>=null;
var _t21:Float=0.0;
var _t22:Float=0.0;
var _t23:Float=0.0;
var _t24:Array<Dynamic>=null;
var _t25:Float=0.0;
var _t26:Float=0.0;
var _t27:Float=0.0;
var _t28:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_main_handleMouse(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_main_handleMouse(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_main_handleMouse
{return new Go_main_handleMouse(gr,_bds);
}
public function run():Go_main_handleMouse {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(35,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(35,1);
this.SubFn1();
this.setPH(37);
_Next=-1;
return this;
case -1:
this.setLatest(37,-1);
if(_t1.hasNoContents())return this;
_t2=_t1.receive({var _v=new Array<Dynamic>();_v=[0,0.0,0.0]; _v;}).r0; // _t2 = <-t1 *ssa.UnOp @ main.go:37:8
this.SubFn2();
_Phi=1;
case 2: // switch.body
this.setLatest(37,2);
this.SubFn3();
_Phi=2;
case 3: // switch.next
this.setLatest(37,3);
this.SubFn4();
_Phi=3;
case 4: // for.body
this.setLatest(37,4);
this.SubFn5();
this.setPH(45);
_Next=-2;
return this;
case -2:
this.setLatest(45,-2);
if(_t14.hasNoContents())return this;
_t15=_t14.receive({var _v=new Array<Dynamic>();_v=[0,0.0,0.0]; _v;}).r0; // _t15 = <-t14 *ssa.UnOp @ main.go:45:9
this.SubFn6();
_Phi=4;
case 5: // for.loop
this.setLatest(45,5);
this.setPH(43);
_t19=((_Phi==2)?true:(_Phi==6)?_t19:(_Phi==7)?false:(_Phi==9)?_t19:false); // _t19 = phi [2.switch.body: true:bool, 6.switch.body: t19, 7.switch.body: false:bool, 9.switch.next: t19] #awaitingMouseUp *ssa.Phi @ main.go:43:4
this.SubFn7();
_Phi=5;
case 6: // switch.body
this.setLatest(43,6);
this.SubFn8();
_Phi=6;
case 7: // switch.body
this.setLatest(43,7);
this.SubFn9();
_Phi=7;
case 8: // switch.next
this.setLatest(43,8);
this.SubFn10();
_Phi=8;
case 9: // switch.next
this.setLatest(43,9);
this.SubFn11();
_Phi=9;
default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_Next=1; // jump 1.for.body *ssa.Jump near main.go:43:4
}// end SubFn0
private inline function SubFn1():Void {
this.setPH(37);
_t0=new Pointer({var _v=new Array<Dynamic>();_v=[0,0.0,0.0]; _v;}); // _t0 = local mouseEvent (e) *ssa.Alloc @ main.go:37:3
_t1=Go.main_mouseEvents.load(); // _t1 = *mouseEvents *ssa.UnOp near main.go:37:3
}// end SubFn1
private inline function SubFn2():Void {
var _t3:Array<Dynamic>;
var _t4:Int;
var _t5:Bool;
_t0.store(_t2); // *t0 = t2 *ssa.Store near main.go:37:3
_t3=_t0.load(); // _t3 = *t0 *ssa.UnOp near main.go:37:3
this.setPH(38);
_t4=_t3[0]; // _t4 = t3.event [#0] *ssa.Field @ main.go:38:12
_t5=(_t4==1); // _t5 = t4 == 1:int *ssa.BinOp near main.go:38:12
_Next=_t5 ? 2 : 3; // if t5 goto 2.switch.body else 3.switch.next *ssa.If near main.go:38:12
}// end SubFn2
private inline function SubFn3():Void {
var _t6:Float;
var _t7:Array<Dynamic>;
var _t8:Float;
var _t9:Float;
var _t10:Float;
var _t11:Array<Dynamic>;
var _t12:Float;
var _t13:Float;
Go.main_Status.store("MOUSE_DOWN"); // *Status = "MOUSE_DOWN":string *ssa.Store near main.go:38:12
_t6=Go.main_SpriteX.load(); // _t6 = *SpriteX *ssa.UnOp near main.go:38:12
_t7=_t0.load(); // _t7 = *t0 *ssa.UnOp near main.go:38:12
this.setPH(41);
_t8=_t7[1]; // _t8 = t7.x [#1] *ssa.Field @ main.go:41:31
_t9=(Force.toFloat(_t6)-Force.toFloat(_t8)); // _t9 = t6 - t8 *ssa.BinOp @ main.go:41:27
Go.main_cacheOffsetX.store(_t9); // *cacheOffsetX = t9 *ssa.Store near main.go:41:27
_t10=Go.main_SpriteY.load(); // _t10 = *SpriteY *ssa.UnOp near main.go:41:27
_t11=_t0.load(); // _t11 = *t0 *ssa.UnOp near main.go:41:27
this.setPH(42);
_t12=_t11[2]; // _t12 = t11.y [#2] *ssa.Field @ main.go:42:31
_t13=(Force.toFloat(_t10)-Force.toFloat(_t12)); // _t13 = t10 - t12 *ssa.BinOp @ main.go:42:27
Go.main_cacheOffsetY.store(_t13); // *cacheOffsetY = t13 *ssa.Store near main.go:42:27
_Next=5; // jump 5.for.loop *ssa.Jump near main.go:42:27
}// end SubFn3
private inline function SubFn4():Void {
Go.main_Status.store("awaiting MOUSE_DOWN"); // *Status = "awaiting MOUSE_DOWN":string *ssa.Store near main.go:42:27
_Next=1; // jump 1.for.body *ssa.Jump near main.go:42:27
}// end SubFn4
private inline function SubFn5():Void {
_t14=Go.main_mouseEvents.load(); // _t14 = *mouseEvents *ssa.UnOp near main.go:42:27
}// end SubFn5
private inline function SubFn6():Void {
var _t16:Array<Dynamic>;
var _t18:Bool;
_t0.store(_t15); // *t0 = t15 *ssa.Store near main.go:42:27
_t16=_t0.load(); // _t16 = *t0 *ssa.UnOp near main.go:42:27
this.setPH(46);
_t17=_t16[0]; // _t17 = t16.event [#0] *ssa.Field @ main.go:46:14
_t18=(_t17==2); // _t18 = t17 == 2:int *ssa.BinOp near main.go:46:14
_Next=_t18 ? 6 : 8; // if t18 goto 6.switch.body else 8.switch.next *ssa.If near main.go:46:14
}// end SubFn6
private inline function SubFn7():Void {
_Next=_t19 ? 4 : 1; // if t19 goto 4.for.body else 1.for.body *ssa.If near main.go:46:14
}// end SubFn7
private inline function SubFn8():Void {
var _t20:Array<Dynamic>;
var _t21:Float;
var _t22:Float;
var _t23:Float;
var _t24:Array<Dynamic>;
var _t25:Float;
var _t26:Float;
var _t27:Float;
Go.main_Status.store("MOUSE_MOVE"); // *Status = "MOUSE_MOVE":string *ssa.Store near main.go:46:14
_t20=_t0.load(); // _t20 = *t0 *ssa.UnOp near main.go:46:14
this.setPH(49);
_t21=_t20[1]; // _t21 = t20.x [#1] *ssa.Field @ main.go:49:18
_t22=Go.main_cacheOffsetX.load(); // _t22 = *cacheOffsetX *ssa.UnOp near main.go:49:18
_t23=(Force.toFloat(_t21)+Force.toFloat(_t22)); // _t23 = t21 + t22 *ssa.BinOp @ main.go:49:20
Go.main_SpriteX.store(_t23); // *SpriteX = t23 *ssa.Store near main.go:49:20
_t24=_t0.load(); // _t24 = *t0 *ssa.UnOp near main.go:49:20
this.setPH(50);
_t25=_t24[2]; // _t25 = t24.y [#2] *ssa.Field @ main.go:50:18
_t26=Go.main_cacheOffsetY.load(); // _t26 = *cacheOffsetY *ssa.UnOp near main.go:50:18
_t27=(Force.toFloat(_t25)+Force.toFloat(_t26)); // _t27 = t25 + t26 *ssa.BinOp @ main.go:50:20
Go.main_SpriteY.store(_t27); // *SpriteY = t27 *ssa.Store near main.go:50:20
_Next=5; // jump 5.for.loop *ssa.Jump near main.go:50:20
}// end SubFn8
private inline function SubFn9():Void {
Go.main_Status.store("MOUSE_UP"); // *Status = "MOUSE_UP":string *ssa.Store near main.go:50:20
_Next=5; // jump 5.for.loop *ssa.Jump near main.go:50:20
}// end SubFn9
private inline function SubFn10():Void {
var _t28:Bool;
_t28=(_t17==0); // _t28 = t17 == 0:int *ssa.BinOp near main.go:50:20
_Next=_t28 ? 7 : 9; // if t28 goto 7.switch.body else 9.switch.next *ssa.If near main.go:50:20
}// end SubFn10
private inline function SubFn11():Void {
Go.main_Status.store("awaiting MOUSE_UP"); // *Status = "awaiting MOUSE_UP":string *ssa.Store near main.go:50:20
_Next=5; // jump 5.for.loop *ssa.Jump near main.go:50:20
}// end SubFn11
}
#if js @:expose("Go_haxegoruntime_C5") #end class Go_haxegoruntime_C5 extends StackFrameBasis implements StackFrame {  // goruntime.go:147:6
var p_funcName:String;
var p_a1:Interface;
var p_a2:Interface;
var p_a3:Interface;
var p_a4:Interface;
var p_a5:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface) {
super(gr,209,"Go_haxegoruntime_C5");
this._bds=_bds;
this.p_funcName=p_funcName;
this.p_a1=p_a1;
this.p_a2=p_a2;
this.p_a3=p_a3;
this.p_a4=p_a4;
this.p_a5=p_a5;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_C5(0,[], p_funcName, p_a1, p_a2, p_a3, p_a4, p_a5).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface) : Interface {
var _sf=new Go_haxegoruntime_C5(_gr,[], p_funcName, p_a1, p_a2, p_a3, p_a4, p_a5).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface) : Go_haxegoruntime_C5
{return new Go_haxegoruntime_C5(gr,_bds, p_funcName, p_a1, p_a2, p_a3, p_a4, p_a5);
}
public function run():Go_haxegoruntime_C5 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(209,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:147:76

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_funcName); // _t0 = make interface{} <- string (funcName) *ssa.MakeInterface near goruntime.go:147:76
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_Callers") #end class Go_haxegoruntime_Callers extends StackFrameBasis implements StackFrame {  // goruntime.go:348:6
var p_skip:Int;
var p_pc:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_skip : Int, p_pc : Slice) {
super(gr,410,"Go_haxegoruntime_Callers");
this._bds=_bds;
this.p_skip=p_skip;
this.p_pc=p_pc;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_skip : Int, p_pc : Slice) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_Callers(0,[], p_skip, p_pc).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_skip : Int, p_pc : Slice) : Int {
var _sf=new Go_haxegoruntime_Callers(_gr,[], p_skip, p_pc).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_skip : Int, p_pc : Slice) : Go_haxegoruntime_Callers
{return new Go_haxegoruntime_Callers(gr,_bds, p_skip, p_pc);
}
public function run():Go_haxegoruntime_Callers {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(410,0);
this.SubFn0();
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(410,-1);
 // panic t0 *ssa.Panic @ goruntime.go:348:49

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,"runtime.Callers() not yet implemented"); // _t0 = make interface{} <- string ("runtime.Callers()...":string) *ssa.MakeInterface near goruntime.go:348:49
}// end SubFn0
}
#if (!php) private #end class Go_haxegoruntime_init_36_1 extends StackFrameBasis implements StackFrame {  // goruntime.go:17:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,79,"Go_haxegoruntime_init_36_1");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t0:Dynamic=null;
var _t1:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_init_36_1(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_haxegoruntime_init_36_1(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_haxegoruntime_init_36_1
{return new Go_haxegoruntime_init_36_1(gr,_bds);
}
public function run():Go_haxegoruntime_init_36_1 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(79,0);
this.setPH(80);
_t0='字'.length; // _t0 = github.com/elliott5/gohaxelib/hxutil.HAXE("'字'.length;":string) *ssa.Call @ goruntime.go:18:26
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near goruntime.go:18:26

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t1:Int;
_t1=cast(_t0,Int); // _t1 = convert uint <- uintptr (t0) *ssa.Convert @ goruntime.go:18:14
Go.haxegoruntime_ZiLen.store(_t1); // *ZiLen = t1 *ssa.Store near goruntime.go:18:14
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_C1") #end class Go_haxegoruntime_C1 extends StackFrameBasis implements StackFrame {  // goruntime.go:143:6
var p_funcName:String;
var p_a1:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface) {
super(gr,205,"Go_haxegoruntime_C1");
this._bds=_bds;
this.p_funcName=p_funcName;
this.p_a1=p_a1;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_funcName : String, p_a1 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_C1(0,[], p_funcName, p_a1).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_funcName : String, p_a1 : Interface) : Interface {
var _sf=new Go_haxegoruntime_C1(_gr,[], p_funcName, p_a1).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface) : Go_haxegoruntime_C1
{return new Go_haxegoruntime_C1(gr,_bds, p_funcName, p_a1);
}
public function run():Go_haxegoruntime_C1 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(205,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:143:76

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_funcName); // _t0 = make interface{} <- string (funcName) *ssa.MakeInterface near goruntime.go:143:76
}// end SubFn0
}
#if (!php) private #end class Go_main_init_36_1 extends StackFrameBasis implements StackFrame {  // main.go:30:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,30,"Go_main_init_36_1");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_main_init_36_1(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_main_init_36_1(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_main_init_36_1
{return new Go_main_init_36_1(gr,_bds);
}
public function run():Go_main_init_36_1 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(30,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near goruntime.go:143:76

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
Go.main_SpriteX.store(100); // *SpriteX = 100:float64 *ssa.Store near goruntime.go:143:76
Go.main_SpriteY.store(150); // *SpriteY = 150:float64 *ssa.Store near goruntime.go:143:76
}// end SubFn0
}
#if js @:expose("Go_main_MouseMove") #end class Go_main_MouseMove extends StackFrameBasis implements StackFrame {  // main.go:21:6
var p_x:Float;
var p_y:Float;
public function new(gr:Int,_bds:Array<Dynamic>, p_x : Float, p_y : Float) {
super(gr,21,"Go_main_MouseMove");
this._bds=_bds;
this.p_x=p_x;
this.p_y=p_y;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Channel<Array<Dynamic>>=null;
var _t1:Pointer=null;
var _t2:Pointer=null;
var _t3:Pointer=null;
var _t4:Pointer=null;
var _t5:Array<Dynamic>=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_x : Float, p_y : Float) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_main_MouseMove(0,[], p_x, p_y).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_x : Float, p_y : Float) : Void {
var _sf=new Go_main_MouseMove(_gr,[], p_x, p_y).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_x : Float, p_y : Float) : Go_main_MouseMove
{return new Go_main_MouseMove(gr,_bds, p_x, p_y);
}
public function run():Go_main_MouseMove {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(21,0);
this.SubFn0();
_Next=-1;
return this;
case -1:
this.setLatest(21,-1);
if(!_t0.hasSpace())return this;
_t0.send(_t5); // send t0 <- t5 *ssa.Send @ main.go:21:44
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near main.go:21:44

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t1:Pointer;
var _t2:Pointer;
var _t3:Pointer;
var _t4:Pointer;
_t0=Go.main_mouseEvents.load(); // _t0 = *mouseEvents *ssa.UnOp near main.go:21:44
_t1=new Pointer({var _v=new Array<Dynamic>();_v=[0,0.0,0.0]; _v;}); // _t1 = local mouseEvent (complit) *ssa.Alloc @ main.go:21:57
_t2=_t1.addr(0);  // _t2 = &t1.event [#0] *ssa.FieldAddr near main.go:21:57 [POINTER]
_t2.store(2); // *t2 = 2:int *ssa.Store near main.go:21:57
_t3=_t1.addr(1);  // _t3 = &t1.x [#1] *ssa.FieldAddr near main.go:21:57 [POINTER]
_t3.store(p_x); // *t3 = x *ssa.Store near main.go:21:57
_t4=_t1.addr(2);  // _t4 = &t1.y [#2] *ssa.FieldAddr near main.go:21:57 [POINTER]
_t4.store(p_y); // *t4 = y *ssa.Store near main.go:21:57
_t5=_t1.load(); // _t5 = *t1 *ssa.UnOp near main.go:21:57
}// end SubFn0
}
#if js @:expose("Go_utf8_FullRune") #end class Go_utf8_FullRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:203:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,753,"Go_utf8_FullRune");
this._bds=_bds;
this.p_p=p_p;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:Int,r1:Int,r2:Bool}=null;
var _t3:Bool=false;
var _t4:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_p : Slice) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_FullRune(0,[], p_p).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_p : Slice) : Bool {
var _sf=new Go_utf8_FullRune(_gr,[], p_p).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_p : Slice) : Go_utf8_FullRune
{return new Go_utf8_FullRune(gr,_bds, p_p);
}
public function run():Go_utf8_FullRune {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(753,0);
this.setPH(754);
_SF1=Go_utf8_decodeRuneInternal.call(this._goroutine,[],p_p);
_Next = -1;
return this;
case -1:
this.setLatest(754,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInternal(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:204:35
this.SubFn0();
this.setPH(755);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:205:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
 // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:205:2 [REGISTER VALUE UN-USED]
 // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:205:2 [REGISTER VALUE UN-USED]
_t3=_t0.r2; // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:205:2
_t4=(!_t3); // _t4 = !t3 *ssa.UnOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:205:9
}// end SubFn0
}
#if js @:expose("Go_utf8_ValidString") #end class Go_utf8_ValidString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:415:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,965,"Go_utf8_ValidString");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:Dynamic=null;
var _t1:{r0:Bool,r1:Int,r2:Int}=null;
var _t2:Bool=false;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:String="";
var _SF1:StackFrame;
var _t7:{r0:Int,r1:Int}=null;
var _t9:Int=0;
var _t10:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : String) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_ValidString(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : String) : Bool {
var _sf=new Go_utf8_ValidString(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : String) : Go_utf8_ValidString
{return new Go_utf8_ValidString(gr,_bds, p_s);
}
public function run():Go_utf8_ValidString {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(965,0);
this.SubFn0();

case 1: // rangeiter.loop
this.setLatest(965,1);
this.SubFn1();

case 2: // rangeiter.body
this.setLatest(965,2);
this.SubFn2();

case 3: // rangeiter.done
this.setLatest(965,3);
this.setPH(978);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:428:2

case 4: // if.then
this.setLatest(978,4);
this.SubFn3();
this.setPH(972);
_SF1=Go_utf8_DecodeRuneInString.call(this._goroutine,[],_t6);
_Next = -1;
return this;
case -1:
this.setLatest(972,-1);
_t7=_SF1.res();
 // _t7 = DecodeRuneInString(t6) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:33
this.SubFn4();

case 5: // if.then
this.setLatest(972,5);
this.setPH(974);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:424:5

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
this.setPH(966);
_t0={k:0,v:Force.toUTF8slice(this._goroutine,p_s)}; // _t0 = range s *ssa.Range @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
_Next=1; // jump 1.rangeiter.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
}// end SubFn0
private inline function SubFn1():Void {
var _t2:Bool;
_t1={var _thisK:Int=_t0.k;if(_t0.k>=_t0.v.len()){r0:false,r1:0,r2:0};else {var _dr:{r0:Int,r1:Int}=Go_utf8_DecodeRune.callFromRT(this._goroutine,_t0.v.subSlice(_thisK,-1));_t0.k+=_dr.r1;{r0:true,r1:cast(_thisK,Int),r2:cast(_dr.r0,Int)};}}; // _t1 = next t0 *ssa.Next near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
_t2=_t1.r0; // _t2 = extract t1 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
_Next=_t2 ? 2 : 3; // if t2 goto 2.rangeiter.body else 3.rangeiter.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
}// end SubFn1
private inline function SubFn2():Void {
var _t5:Bool;
_t3=_t1.r1; // _t3 = extract t1 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
_t4=_t1.r2; // _t4 = extract t1 #2 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
this.setPH(967);
_t5=(_t4==65533); // _t5 = t4 == 65533:int32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:417:8
_Next=_t5 ? 4 : 1; // if t5 goto 4.if.then else 1.rangeiter.loop *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:417:8
}// end SubFn2
private inline function SubFn3():Void {
this.setPH(972);
_t6=Force.toRawString(this._goroutine,Force.toUTF8slice(this._goroutine,p_s).subSlice(_t3,-1)); // _t6 = slice s[t3:] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:35
}// end SubFn3
private inline function SubFn4():Void {
var _t10:Bool;
 // _t8 = extract t7 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:35 [REGISTER VALUE UN-USED]
_t9=_t7.r1; // _t9 = extract t7 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:35
this.setPH(973);
_t10=(_t9==1); // _t10 = t9 == 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:423:12
_Next=_t10 ? 5 : 1; // if t10 goto 5.if.then else 1.rangeiter.loop *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:423:12
}// end SubFn4
}
#if js @:expose("Go_haxegoruntime_C2") #end class Go_haxegoruntime_C2 extends StackFrameBasis implements StackFrame {  // goruntime.go:144:6
var p_funcName:String;
var p_a1:Interface;
var p_a2:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface, p_a2 : Interface) {
super(gr,206,"Go_haxegoruntime_C2");
this._bds=_bds;
this.p_funcName=p_funcName;
this.p_a1=p_a1;
this.p_a2=p_a2;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_funcName : String, p_a1 : Interface, p_a2 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_C2(0,[], p_funcName, p_a1, p_a2).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_funcName : String, p_a1 : Interface, p_a2 : Interface) : Interface {
var _sf=new Go_haxegoruntime_C2(_gr,[], p_funcName, p_a1, p_a2).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface, p_a2 : Interface) : Go_haxegoruntime_C2
{return new Go_haxegoruntime_C2(gr,_bds, p_funcName, p_a1, p_a2);
}
public function run():Go_haxegoruntime_C2 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(206,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:144:76

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_funcName); // _t0 = make interface{} <- string (funcName) *ssa.MakeInterface near goruntime.go:144:76
}// end SubFn0
}
#if (!php) private #end class Go_utf8_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,206,"Go_utf8_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_utf8_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_utf8_init
{return new Go_utf8_init(gr,_bds);
}
public function run():Go_utf8_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(206,0);
this.SubFn0();

case 1: // init.start
this.setLatest(206,1);
this.SubFn1();

case 2: // init.done
this.setLatest(206,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near goruntime.go:144:76

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Bool;
_t0=Go.utf8_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near goruntime.go:144:76
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near goruntime.go:144:76
}// end SubFn0
private inline function SubFn1():Void {
Go.utf8_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near goruntime.go:144:76
_Next=2; // jump 2.init.done *ssa.Jump near goruntime.go:144:76
}// end SubFn1
}
#if js @:expose("Go_haxegoruntime_UTF8toRunes") #end class Go_haxegoruntime_UTF8toRunes extends StackFrameBasis implements StackFrame {  // goruntime.go:24:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,86,"Go_haxegoruntime_UTF8toRunes");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:Int=0;
var _t1:Slice=null;
var _t2:Int=0;
var _t3:Int=0;
var _t4:Slice=null;
var _t5:Int=0;
var _t6:Int=0;
var _t7:Int=0;
var _t8:Bool=false;
var _t9:Int=0;
var _t10:Bool=false;
var _t11:Pointer=null;
var _t12:Int=0;
var _t13:Pointer=null;
var _t14:Int=0;
var _t15:Int=0;
var _SF2:StackFrame;
var _t16:{r0:Int,r1:Int}=null;
var _t17:Int=0;
var _t18:Int=0;
var _t19:Pointer=null;
var _t20:Int=0;
var _t21:Int=0;
var _t22:Int=0;
var _t23:Int=0;
var _t24:Int=0;
var _t25:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : Slice) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_UTF8toRunes(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : Slice) : Slice {
var _sf=new Go_haxegoruntime_UTF8toRunes(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : Slice) : Go_haxegoruntime_UTF8toRunes
{return new Go_haxegoruntime_UTF8toRunes(gr,_bds, p_s);
}
public function run():Go_haxegoruntime_UTF8toRunes {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(86,0);
this.setPH(87);
_SF1=Go_utf8_RuneCount.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(87,-1);
_t0=_SF1.res();
 // _t0 = unicode/utf8.RuneCount(s) *ssa.Call @ goruntime.go:25:36
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(87,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(87,2);
this.setPH(98);
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ goruntime.go:36:2

case 3: // for.loop
this.setLatest(98,3);
this.setPH(88);
_t5=((_Phi==0)?0:(_Phi==6)?_t20:0); // _t5 = phi [0.entry: 0:int, 6.for.done: t20] #si *ssa.Phi @ goruntime.go:26:2
this.setPH(89);
_t6=((_Phi==0)?0:(_Phi==6)?_t21:0); // _t6 = phi [0.entry: 0:int, 6.for.done: t21] #ri *ssa.Phi @ goruntime.go:27:6
this.SubFn2();
_Phi=3;
case 4: // cond.true
this.setLatest(89,4);
this.SubFn3();
_Phi=4;
case 5: // for.body
this.setLatest(89,5);
this.SubFn4();
_Phi=5;
case 6: // for.done
this.setLatest(89,6);
this.setPH(94);
_SF2=Go_utf8_DecodeRune.call(this._goroutine,[],_t4);
_Next = -2;
return this;
case -2:
this.setLatest(94,-2);
_t16=_SF2.res();
 // _t16 = unicode/utf8.DecodeRune(t4) *ssa.Call @ goruntime.go:32:33
this.SubFn5();
_Phi=6;
case 7: // for.loop
this.setLatest(94,7);
this.setPH(91);
_t22=((_Phi==1)?0:(_Phi==5)?_t15:0); // _t22 = phi [1.for.body: 0:int, 5.for.body: t15] #j *ssa.Phi @ goruntime.go:29:7
this.SubFn6();
_Phi=7;
default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
this.setPH(87);
_t1=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t0) _v[_i]=0; _v;}),0,_t0); // _t1 = make []rune t0 t0 *ssa.MakeSlice @ goruntime.go:25:13
_Next=3; // jump 3.for.loop *ssa.Jump near goruntime.go:25:13
}// end SubFn0
private inline function SubFn1():Void {
var _t2:Int;
var _t3:Int;
this.setPH(90);
_t2=({var _v=p_s;_v==null?0:_v.len();}); // _t2 = len(s) *ssa.Call @ goruntime.go:28:24
_t3=(_t2-_t5); // _t3 = t2 - t5 *ssa.BinOp @ goruntime.go:28:27
_t4=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t3) _v[_i]=0; _v;}),0,_t3); // _t4 = make []byte t3 t3 *ssa.MakeSlice @ goruntime.go:28:12
_Next=7; // jump 7.for.loop *ssa.Jump near goruntime.go:28:12
}// end SubFn1
private inline function SubFn2():Void {
var _t7:Int;
var _t8:Bool;
this.setPH(89);
_t7=({var _v=p_s;_v==null?0:_v.len();}); // _t7 = len(s) *ssa.Call @ goruntime.go:27:23
_t8=(_t5<_t7); // _t8 = t5 < t7 *ssa.BinOp @ goruntime.go:27:18
_Next=_t8 ? 4 : 2; // if t8 goto 4.cond.true else 2.for.done *ssa.If near goruntime.go:27:18
}// end SubFn2
private inline function SubFn3():Void {
var _t9:Int;
var _t10:Bool;
_t9=({var _v=_t1;_v==null?0:_v.len();}); // _t9 = len(t1) *ssa.Call @ goruntime.go:27:38
_t10=(_t6<_t9); // _t10 = t6 < t9 *ssa.BinOp @ goruntime.go:27:33
_Next=_t10 ? 1 : 2; // if t10 goto 1.for.body else 2.for.done *ssa.If near goruntime.go:27:33
}// end SubFn3
private inline function SubFn4():Void {
var _t11:Pointer;
var _t12:Int;
var _t13:Pointer;
var _t14:Int;
this.setPH(92);
if((_t22<0)||(_t22>=_t4.len())) Scheduler.ioor(); // _t11 = &t4[t22] *ssa.IndexAddr @ goruntime.go:30:5 [POINTER]
_t11=_t4.addr(_t22);  // _t11 = &t4[t22] *ssa.IndexAddr @ goruntime.go:30:5 [POINTER]
_t12=(_t5+_t22); // _t12 = t5 + t22 *ssa.BinOp @ goruntime.go:30:15
if((_t12<0)||(_t12>=p_s.len())) Scheduler.ioor(); // _t13 = &s[t12] *ssa.IndexAddr @ goruntime.go:30:12 [POINTER]
_t13=p_s.addr(_t12);  // _t13 = &s[t12] *ssa.IndexAddr @ goruntime.go:30:12 [POINTER]
_t14=(_t13.load()|0); // _t14 = *t13 *ssa.UnOp near goruntime.go:30:12
_t11.store(_t14); // *t11 = t14 *ssa.Store near goruntime.go:30:12
_t15=(_t22+1); // _t15 = t22 + 1:int *ssa.BinOp near goruntime.go:30:12
_Next=7; // jump 7.for.loop *ssa.Jump near goruntime.go:30:12
}// end SubFn4
private inline function SubFn5():Void {
var _t19:Pointer;
_t17=_t16.r0; // _t17 = extract t16 #0 *ssa.Extract near goruntime.go:30:12
_t18=_t16.r1; // _t18 = extract t16 #1 *ssa.Extract near goruntime.go:30:12
this.setPH(95);
if((_t6<0)||(_t6>=_t1.len())) Scheduler.ioor(); // _t19 = &t1[t6] *ssa.IndexAddr @ goruntime.go:33:6 [POINTER]
_t19=_t1.addr(_t6);  // _t19 = &t1[t6] *ssa.IndexAddr @ goruntime.go:33:6 [POINTER]
_t19.store(_t17); // *t19 = t17 *ssa.Store near goruntime.go:33:6
_t20=(_t5+_t18); // _t20 = t5 + t18 *ssa.BinOp near goruntime.go:33:6
_t21=(_t6+1); // _t21 = t6 + 1:int *ssa.BinOp near goruntime.go:33:6
_Next=3; // jump 3.for.loop *ssa.Jump near goruntime.go:33:6
}// end SubFn5
private inline function SubFn6():Void {
var _t23:Int;
var _t24:Int;
var _t25:Bool;
this.setPH(91);
_t23=({var _v=p_s;_v==null?0:_v.len();}); // _t23 = len(s) *ssa.Call @ goruntime.go:29:23
_t24=(_t23-_t5); // _t24 = t23 - t5 *ssa.BinOp @ goruntime.go:29:27
_t25=(_t22<_t24); // _t25 = t22 < t24 *ssa.BinOp @ goruntime.go:29:17
_Next=_t25 ? 5 : 6; // if t25 goto 5.for.body else 6.for.done *ssa.If near goruntime.go:29:17
}// end SubFn6
}
#if js @:expose("Go_haxegoruntime_RunesToUTF8") #end class Go_haxegoruntime_RunesToUTF8 extends StackFrameBasis implements StackFrame {  // goruntime.go:64:6
var p_r:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Slice) {
super(gr,126,"Go_haxegoruntime_RunesToUTF8");
this._bds=_bds;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _t0:Slice=null;
var _t1:Int=0;
var _t2:Slice=null;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:Pointer=null;
var _t7:Int=0;
var _SF1:StackFrame;
var _t8:Int=0;
var _t9:Slice=null;
var _t10:Pointer=null;
var _t11:Int=0;
var _SF2:StackFrame;
var _t13:Slice=null;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_r : Slice) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_RunesToUTF8(0,[], p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r : Slice) : Slice {
var _sf=new Go_haxegoruntime_RunesToUTF8(_gr,[], p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r : Slice) : Go_haxegoruntime_RunesToUTF8
{return new Go_haxegoruntime_RunesToUTF8(gr,_bds, p_r);
}
public function run():Go_haxegoruntime_RunesToUTF8 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(126,0);
this.SubFn0();
_Phi=0;
case 1: // rangeindex.loop
this.setLatest(126,1);
this.setPH(127);
_t2=((_Phi==0)?_t0:(_Phi==2)?_t13:new Slice(new Pointer(new Array<Int>()),0,0)); // _t2 = phi [0.entry: t0, 2.rangeindex.body: t13] #ret *ssa.Phi @ goruntime.go:65:6
_t3=((_Phi==0)?(-1):(_Phi==2)?_t4:0); // _t3 = phi [0.entry: -1:int, 2.rangeindex.body: t4] *ssa.Phi near goruntime.go:65:6
this.SubFn1();
_Phi=1;
case 2: // rangeindex.body
this.setLatest(127,2);
this.SubFn2();
this.setPH(130);
_SF1=Go_utf8_RuneLen.call(this._goroutine,[],_t7);
_Next = -1;
return this;
case -1:
this.setLatest(130,-1);
_t8=_SF1.res();
 // _t8 = unicode/utf8.RuneLen(t7) *ssa.Call @ goruntime.go:68:35
this.SubFn3();
this.setPH(131);
Go_utf8_EncodeRune.call(this._goroutine,[],_t9,_t11);
_Next = -2;
return this;
case -2:
this.setLatest(131,-2);
 // _t12 = unicode/utf8.EncodeRune(t9, t11) *ssa.Call @ goruntime.go:69:18 [REGISTER VALUE UN-USED]
this.SubFn4();
_Phi=2;
case 3: // rangeindex.done
this.setLatest(131,3);
this.setPH(134);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ goruntime.go:72:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
this.setPH(128);
_t0=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0...0) _v[_i]=0; _v;}),0,0); // _t0 = make []byte 0:int 0:int *ssa.MakeSlice @ goruntime.go:66:12
_t1=({var _v=p_r;_v==null?0:_v.len();}); // _t1 = len(r) *ssa.Call near goruntime.go:66:12
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near goruntime.go:66:12
}// end SubFn0
private inline function SubFn1():Void {
var _t5:Bool;
_t4=(_t3+1); // _t4 = t3 + 1:int *ssa.BinOp near goruntime.go:66:12
_t5=(_t4<_t1); // _t5 = t4 < t1 *ssa.BinOp near goruntime.go:66:12
_Next=_t5 ? 2 : 3; // if t5 goto 2.rangeindex.body else 3.rangeindex.done *ssa.If near goruntime.go:66:12
}// end SubFn1
private inline function SubFn2():Void {
var _t6:Pointer;
this.setPH(130);
if((_t4<0)||(_t4>=p_r.len())) Scheduler.ioor(); // _t6 = &r[t4] *ssa.IndexAddr @ goruntime.go:68:37 [POINTER]
_t6=p_r.addr(_t4);  // _t6 = &r[t4] *ssa.IndexAddr @ goruntime.go:68:37 [POINTER]
_t7=(_t6.load()|0); // _t7 = *t6 *ssa.UnOp near goruntime.go:68:37
}// end SubFn2
private inline function SubFn3():Void {
var _t10:Pointer;
_t9=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t8) _v[_i]=0; _v;}),0,_t8); // _t9 = make []byte t8 t8 *ssa.MakeSlice @ goruntime.go:68:14
this.setPH(131);
if((_t4<0)||(_t4>=p_r.len())) Scheduler.ioor(); // _t10 = &r[t4] *ssa.IndexAddr @ goruntime.go:69:25 [POINTER]
_t10=p_r.addr(_t4);  // _t10 = &r[t4] *ssa.IndexAddr @ goruntime.go:69:25 [POINTER]
_t11=(_t10.load()|0); // _t11 = *t10 *ssa.UnOp near goruntime.go:69:25
}// end SubFn3
private inline function SubFn4():Void {
this.setPH(132);
_t13={var _v:Slice;if(_t2==null) _v=_t9;else if(_t2.len()==0) _v=_t9;else if(_t9==null) _v=_t2;else if(_t9.len()==0) _v=_t2;else {var l0:Int=_t2.len();_v=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t2.len()+_t9.len()) _v[_i]=0; _v;}),0,_t2.len()+_t9.len());for(_i in 0...l0) _v.setAt(_i,Deep.copy(_t2.getAt(_i)));for(_i in 0..._t9.len()) _v.setAt(_i+l0,Deep.copy(_t9.getAt(_i)));};_v;}; // _t13 = append(t2, t9...) *ssa.Call @ goruntime.go:70:15
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near goruntime.go:70:15
}// end SubFn4
}
#if (!php) private #end class Go_haxegoruntime_runtime_Gosched extends StackFrameBasis implements StackFrame {  // goruntime.go:340:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,402,"Go_haxegoruntime_runtime_Gosched");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_runtime_Gosched(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_haxegoruntime_runtime_Gosched(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_haxegoruntime_runtime_Gosched
{return new Go_haxegoruntime_runtime_Gosched(gr,_bds);
}
public function run():Go_haxegoruntime_runtime_Gosched {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(402,0);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near goruntime.go:70:15

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_main_main extends StackFrameBasis implements StackFrame {  // main.go:3:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,3,"Go_main_main");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_main_main(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_main_main(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_main_main
{return new Go_main_main(gr,_bds);
}
public function run():Go_main_main {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(3,0);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near goruntime.go:70:15

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_utf8_RuneCountInString") #end class Go_utf8_RuneCountInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,932,"Go_utf8_RuneCountInString");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Dynamic=null;
var _t1:Int=0;
var _t2:{r0:Bool,r1:Dynamic,r2:Dynamic}=null;
var _t3:Bool=false;
var _t4:Int=0;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : String) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_RuneCountInString(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : String) : Int {
var _sf=new Go_utf8_RuneCountInString(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : String) : Go_utf8_RuneCountInString
{return new Go_utf8_RuneCountInString(gr,_bds, p_s);
}
public function run():Go_utf8_RuneCountInString {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(932,0);
this.SubFn0();
_Phi=0;
case 1: // rangeiter.loop
this.setLatest(932,1);
_t1=((_Phi==0)?0:(_Phi==2)?_t4:0); // _t1 = phi [0.entry: 0:int, 2.rangeiter.body: t4] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:382:35
this.SubFn1();
_Phi=1;
case 2: // rangeiter.body
this.setLatest(932,2);
this.SubFn2();
_Phi=2;
case 3: // rangeiter.done
this.setLatest(932,3);
this.setPH(936);
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:386:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
this.setPH(933);
_t0={k:0,v:Force.toUTF8slice(this._goroutine,p_s)}; // _t0 = range s *ssa.Range @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
_Next=1; // jump 1.rangeiter.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
}// end SubFn0
private inline function SubFn1():Void {
var _t2:{r0:Bool,r1:Dynamic,r2:Dynamic};
var _t3:Bool;
_t2={var _thisK:Int=_t0.k;if(_t0.k>=_t0.v.len()){r0:false,r1:0,r2:0};else {var _dr:{r0:Int,r1:Int}=Go_utf8_DecodeRune.callFromRT(this._goroutine,_t0.v.subSlice(_thisK,-1));_t0.k+=_dr.r1;{r0:true,r1:cast(_thisK,Int),r2:cast(_dr.r0,Int)};}}; // _t2 = next t0 *ssa.Next near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
_t3=_t2.r0; // _t3 = extract t2 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
_Next=_t3 ? 2 : 3; // if t3 goto 2.rangeiter.body else 3.rangeiter.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
}// end SubFn1
private inline function SubFn2():Void {
_t4=(_t1+1); // _t4 = t1 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
_Next=1; // jump 1.rangeiter.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
}// end SubFn2
}
#if js @:expose("Go_hxutil_StringsUTF16") #end class Go_hxutil_StringsUTF16 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:30:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1023,"Go_hxutil_StringsUTF16");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:Int=0;
var _t1:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_hxutil_StringsUTF16(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : Bool {
var _sf=new Go_hxutil_StringsUTF16(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_hxutil_StringsUTF16
{return new Go_hxutil_StringsUTF16(gr,_bds);
}
public function run():Go_hxutil_StringsUTF16 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1023,0);
_t0='字'.length; // _t0 = Zilen() *ssa.Call @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:30:40
this.SubFn0();
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:30:28

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t1=(Force.uintCompare(_t0,1)==0); // _t1 = t0 == 1:uint *ssa.BinOp @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:30:43
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_FuncForPC") #end class Go_haxegoruntime_FuncForPC extends StackFrameBasis implements StackFrame {  // goruntime.go:349:6
var p_pc:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_pc : Dynamic) {
super(gr,411,"Go_haxegoruntime_FuncForPC");
this._bds=_bds;
this.p_pc=p_pc;
Scheduler.push(gr,this);
}
var _res:Pointer;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_pc : Dynamic) : Pointer {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_FuncForPC(0,[], p_pc).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_pc : Dynamic) : Pointer {
var _sf=new Go_haxegoruntime_FuncForPC(_gr,[], p_pc).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_pc : Dynamic) : Go_haxegoruntime_FuncForPC
{return new Go_haxegoruntime_FuncForPC(gr,_bds, p_pc);
}
public function run():Go_haxegoruntime_FuncForPC {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(411,0);
this.SubFn0();
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(411,-1);
 // panic t0 *ssa.Panic @ goruntime.go:349:49

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,"runtime.FuncForPC() not yet implemented"); // _t0 = make interface{} <- string ("runtime.FuncForPC...":string) *ssa.MakeInterface near goruntime.go:349:49
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_RunesToUTF16") #end class Go_haxegoruntime_RunesToUTF16 extends StackFrameBasis implements StackFrame {  // goruntime.go:61:6
var p_r:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Slice) {
super(gr,123,"Go_haxegoruntime_RunesToUTF16");
this._bds=_bds;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:Slice=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_r : Slice) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_RunesToUTF16(0,[], p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r : Slice) : Slice {
var _sf=new Go_haxegoruntime_RunesToUTF16(_gr,[], p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r : Slice) : Go_haxegoruntime_RunesToUTF16
{return new Go_haxegoruntime_RunesToUTF16(gr,_bds, p_r);
}
public function run():Go_haxegoruntime_RunesToUTF16 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(123,0);
this.setPH(124);
_SF1=Go_utf16_Encode.call(this._goroutine,[],p_r);
_Next = -1;
return this;
case -1:
this.setLatest(124,-1);
_t0=_SF1.res();
 // _t0 = unicode/utf16.Encode(r) *ssa.Call @ goruntime.go:62:21
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:62:2

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_haxegoruntime_C6") #end class Go_haxegoruntime_C6 extends StackFrameBasis implements StackFrame {  // goruntime.go:148:6
var p_funcName:String;
var p_a1:Interface;
var p_a2:Interface;
var p_a3:Interface;
var p_a4:Interface;
var p_a5:Interface;
var p_a6:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface, p_a6 : Interface) {
super(gr,210,"Go_haxegoruntime_C6");
this._bds=_bds;
this.p_funcName=p_funcName;
this.p_a1=p_a1;
this.p_a2=p_a2;
this.p_a3=p_a3;
this.p_a4=p_a4;
this.p_a5=p_a5;
this.p_a6=p_a6;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface, p_a6 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_C6(0,[], p_funcName, p_a1, p_a2, p_a3, p_a4, p_a5, p_a6).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface, p_a6 : Interface) : Interface {
var _sf=new Go_haxegoruntime_C6(_gr,[], p_funcName, p_a1, p_a2, p_a3, p_a4, p_a5, p_a6).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface, p_a6 : Interface) : Go_haxegoruntime_C6
{return new Go_haxegoruntime_C6(gr,_bds, p_funcName, p_a1, p_a2, p_a3, p_a4, p_a5, p_a6);
}
public function run():Go_haxegoruntime_C6 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(210,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:148:76

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_funcName); // _t0 = make interface{} <- string (funcName) *ssa.MakeInterface near goruntime.go:148:76
}// end SubFn0
}
#if js @:expose("Go_main_MouseGoroutine") #end class Go_main_MouseGoroutine extends StackFrameBasis implements StackFrame {  // main.go:23:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,23,"Go_main_MouseGoroutine");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_main_MouseGoroutine(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_main_MouseGoroutine(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_main_MouseGoroutine
{return new Go_main_MouseGoroutine(gr,_bds);
}
public function run():Go_main_MouseGoroutine {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(23,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near goruntime.go:148:76

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
this.setPH(24);
Go_main_handleMouse.call(Scheduler.makeGoroutine(),[]);  // go handleMouse() *ssa.Go @ main.go:24:2
}// end SubFn0
}
#if js @:expose("Go_utf8_ValidRune") #end class Go_utf8_ValidRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:433:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,983,"Go_utf8_ValidRune");
this._bds=_bds;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:Bool=false;
var _t1:Bool=false;
var _t2:Bool=false;
var _t3:Bool=false;
var _t4:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_r : Int) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_ValidRune(0,[], p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r : Int) : Bool {
var _sf=new Go_utf8_ValidRune(_gr,[], p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r : Int) : Go_utf8_ValidRune
{return new Go_utf8_ValidRune(gr,_bds, p_r);
}
public function run():Go_utf8_ValidRune {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(983,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(983,1);
this.setPH(986);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:436:3

case 2: // switch.body
this.setLatest(986,2);
this.setPH(988);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:438:3

case 3: // switch.next
this.setLatest(988,3);
this.SubFn1();
_Phi=3;
case 4: // switch.body
this.setLatest(988,4);
this.setPH(990);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:440:3

case 5: // switch.next
this.setLatest(990,5);
this.SubFn2();
_Phi=5;
case 6: // binop.rhs
this.setLatest(990,6);
this.SubFn3();
_Phi=6;
case 7: // binop.done
this.setLatest(990,7);
this.setPH(987);
_t4=((_Phi==3)?false:(_Phi==6)?_t3:false); // _t4 = phi [3.switch.next: false:bool, 6.binop.rhs: t3] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:25
this.SubFn4();
_Phi=7;
case 8: // switch.next
this.setLatest(987,8);
this.setPH(992);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:442:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Bool;
this.setPH(985);
_t0=(p_r<0); // _t0 = r < 0:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:435:9
_Next=_t0 ? 1 : 3; // if t0 goto 1.switch.body else 3.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:435:9
}// end SubFn0
private inline function SubFn1():Void {
var _t1:Bool;
this.setPH(987);
_t1=(55296<=p_r); // _t1 = 55296:rune <= r *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:20
_Next=_t1 ? 6 : 7; // if t1 goto 6.binop.rhs else 7.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:20
}// end SubFn1
private inline function SubFn2():Void {
var _t2:Bool;
this.setPH(989);
_t2=(p_r>1114111); // _t2 = r > 1114111:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:439:9
_Next=_t2 ? 4 : 8; // if t2 goto 4.switch.body else 8.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:439:9
}// end SubFn2
private inline function SubFn3():Void {
this.setPH(987);
_t3=(p_r<=57343); // _t3 = r <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
_Next=7; // jump 7.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
}// end SubFn3
private inline function SubFn4():Void {
_Next=_t4 ? 2 : 5; // if t4 goto 2.switch.body else 5.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
}// end SubFn4
}
#if js @:expose("Go_utf8_FullRuneInString") #end class Go_utf8_FullRuneInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:209:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,759,"Go_utf8_FullRuneInString");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:Int,r1:Int,r2:Bool}=null;
var _t3:Bool=false;
var _t4:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : String) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_FullRuneInString(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : String) : Bool {
var _sf=new Go_utf8_FullRuneInString(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : String) : Go_utf8_FullRuneInString
{return new Go_utf8_FullRuneInString(gr,_bds, p_s);
}
public function run():Go_utf8_FullRuneInString {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(759,0);
this.setPH(760);
_SF1=Go_utf8_decodeRuneInStringInternal.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(760,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInStringInternal(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:210:43
this.SubFn0();
this.setPH(761);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
 // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:2 [REGISTER VALUE UN-USED]
 // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:2 [REGISTER VALUE UN-USED]
_t3=_t0.r2; // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:2
_t4=(!_t3); // _t4 = !t3 *ssa.UnOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:9
}// end SubFn0
}
#if (!php) private #end class Go_haxegoruntime_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,761,"Go_haxegoruntime_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _SF1:StackFrame;
var _SF2:StackFrame;
var _SF3:StackFrame;
var _SF4:StackFrame;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_haxegoruntime_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_haxegoruntime_init
{return new Go_haxegoruntime_init(gr,_bds);
}
public function run():Go_haxegoruntime_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(761,0);
this.SubFn0();

case 1: // init.start
this.setLatest(761,1);
this.SubFn1();
Go_utf16_init.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(761,-1);
 // _t1 = unicode/utf16.init() *ssa.Call near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:9 [REGISTER VALUE UN-USED]
Go_utf8_init.call(this._goroutine,[]);
_Next = -2;
return this;
case -2:
this.setLatest(761,-2);
 // _t2 = unicode/utf8.init() *ssa.Call near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:9 [REGISTER VALUE UN-USED]
Go_hxutil_init.call(this._goroutine,[]);
_Next = -3;
return this;
case -3:
this.setLatest(761,-3);
 // _t3 = github.com/elliott5/gohaxelib/hxutil.init() *ssa.Call near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:9 [REGISTER VALUE UN-USED]
Go_haxegoruntime_init_36_1.call(this._goroutine,[]);
_Next = -4;
return this;
case -4:
this.setLatest(761,-4);
 // _t4 = init$1() *ssa.Call near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:9 [REGISTER VALUE UN-USED]
this.SubFn2();

case 2: // init.done
this.setLatest(761,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:9

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Bool;
_t0=Go.haxegoruntime_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:9
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:9
}// end SubFn0
private inline function SubFn1():Void {
Go.haxegoruntime_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:9
}// end SubFn1
private inline function SubFn2():Void {
_Next=2; // jump 2.init.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:9
}// end SubFn2
}
#if js @:expose("Go_haxegoruntime_Goexit") #end class Go_haxegoruntime_Goexit extends StackFrameBasis implements StackFrame {  // goruntime.go:347:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,409,"Go_haxegoruntime_Goexit");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_Goexit(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_haxegoruntime_Goexit(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_haxegoruntime_Goexit
{return new Go_haxegoruntime_Goexit(gr,_bds);
}
public function run():Go_haxegoruntime_Goexit {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(409,0);
this.SubFn0();
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(409,-1);
 // panic t0 *ssa.Panic @ goruntime.go:347:49

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,"runtime.Goexit() not yet implemented"); // _t0 = make interface{} <- string ("runtime.Goexit() ...":string) *ssa.MakeInterface near goruntime.go:347:49
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_C4") #end class Go_haxegoruntime_C4 extends StackFrameBasis implements StackFrame {  // goruntime.go:146:6
var p_funcName:String;
var p_a1:Interface;
var p_a2:Interface;
var p_a3:Interface;
var p_a4:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface) {
super(gr,208,"Go_haxegoruntime_C4");
this._bds=_bds;
this.p_funcName=p_funcName;
this.p_a1=p_a1;
this.p_a2=p_a2;
this.p_a3=p_a3;
this.p_a4=p_a4;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_C4(0,[], p_funcName, p_a1, p_a2, p_a3, p_a4).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface) : Interface {
var _sf=new Go_haxegoruntime_C4(_gr,[], p_funcName, p_a1, p_a2, p_a3, p_a4).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface) : Go_haxegoruntime_C4
{return new Go_haxegoruntime_C4(gr,_bds, p_funcName, p_a1, p_a2, p_a3, p_a4);
}
public function run():Go_haxegoruntime_C4 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(208,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:146:76

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_funcName); // _t0 = make interface{} <- string (funcName) *ssa.MakeInterface near goruntime.go:146:76
}// end SubFn0
}
#if js @:expose("Go_main_MouseDown") #end class Go_main_MouseDown extends StackFrameBasis implements StackFrame {  // main.go:20:6
var p_x:Float;
var p_y:Float;
public function new(gr:Int,_bds:Array<Dynamic>, p_x : Float, p_y : Float) {
super(gr,20,"Go_main_MouseDown");
this._bds=_bds;
this.p_x=p_x;
this.p_y=p_y;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Channel<Array<Dynamic>>=null;
var _t1:Pointer=null;
var _t2:Pointer=null;
var _t3:Pointer=null;
var _t4:Pointer=null;
var _t5:Array<Dynamic>=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_x : Float, p_y : Float) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_main_MouseDown(0,[], p_x, p_y).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_x : Float, p_y : Float) : Void {
var _sf=new Go_main_MouseDown(_gr,[], p_x, p_y).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_x : Float, p_y : Float) : Go_main_MouseDown
{return new Go_main_MouseDown(gr,_bds, p_x, p_y);
}
public function run():Go_main_MouseDown {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(20,0);
this.SubFn0();
_Next=-1;
return this;
case -1:
this.setLatest(20,-1);
if(!_t0.hasSpace())return this;
_t0.send(_t5); // send t0 <- t5 *ssa.Send @ main.go:20:44
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near main.go:20:44

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t1:Pointer;
var _t2:Pointer;
var _t3:Pointer;
var _t4:Pointer;
_t0=Go.main_mouseEvents.load(); // _t0 = *mouseEvents *ssa.UnOp near main.go:20:44
_t1=new Pointer({var _v=new Array<Dynamic>();_v=[0,0.0,0.0]; _v;}); // _t1 = local mouseEvent (complit) *ssa.Alloc @ main.go:20:57
_t2=_t1.addr(0);  // _t2 = &t1.event [#0] *ssa.FieldAddr near main.go:20:57 [POINTER]
_t2.store(1); // *t2 = 1:int *ssa.Store near main.go:20:57
_t3=_t1.addr(1);  // _t3 = &t1.x [#1] *ssa.FieldAddr near main.go:20:57 [POINTER]
_t3.store(p_x); // *t3 = x *ssa.Store near main.go:20:57
_t4=_t1.addr(2);  // _t4 = &t1.y [#2] *ssa.FieldAddr near main.go:20:57 [POINTER]
_t4.store(p_y); // *t4 = y *ssa.Store near main.go:20:57
_t5=_t1.load(); // _t5 = *t1 *ssa.UnOp near main.go:20:57
}// end SubFn0
}
#if (!php) private #end class Go_utf8_decodeRuneInStringInternal extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:123:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,673,"Go_utf8_decodeRuneInStringInternal");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
var _res:{r0:Int, r1:Int, r2:Bool};
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Bool=false;
var _t2:Int=0;
var _t3:Bool=false;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:Bool=false;
var _t7:Int=0;
var _t8:Bool=false;
var _t9:Bool=false;
var _t10:Bool=false;
var _t11:Int=0;
var _t12:Int=0;
var _t13:Int=0;
var _t14:Int=0;
var _t15:Int=0;
var _t16:Int=0;
var _t17:Bool=false;
var _t18:Bool=false;
var _t19:Int=0;
var _t20:Bool=false;
var _t21:Bool=false;
var _t22:Bool=false;
var _t23:Int=0;
var _t24:Int=0;
var _t25:Int=0;
var _t26:Int=0;
var _t27:Int=0;
var _t28:Int=0;
var _t29:Int=0;
var _t30:Int=0;
var _t31:Int=0;
var _t32:Int=0;
var _t33:Bool=false;
var _t34:Bool=false;
var _t35:Bool=false;
var _t36:Bool=false;
var _t37:Int=0;
var _t38:Bool=false;
var _t39:Bool=false;
var _t40:Bool=false;
var _t41:Int=0;
var _t42:Int=0;
var _t43:Int=0;
var _t44:Int=0;
var _t45:Int=0;
var _t46:Int=0;
var _t47:Int=0;
var _t48:Int=0;
var _t49:Int=0;
var _t50:Int=0;
var _t51:Int=0;
var _t52:Int=0;
var _t53:Int=0;
var _t54:Int=0;
var _t55:Bool=false;
var _t56:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : String) : {r0:Int, r1:Int, r2:Bool} {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_decodeRuneInStringInternal(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : String) : {r0:Int, r1:Int, r2:Bool} {
var _sf=new Go_utf8_decodeRuneInStringInternal(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : String) : Go_utf8_decodeRuneInStringInternal
{return new Go_utf8_decodeRuneInStringInternal(gr,_bds, p_s);
}
public function run():Go_utf8_decodeRuneInStringInternal {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(673,0);
this.SubFn0();

case 1: // if.then
this.setLatest(673,1);
this.setPH(676);
_res= {r0:65533,r1:0,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:126:3

case 2: // if.done
this.setLatest(676,2);
this.SubFn1();

case 3: // if.then
this.setLatest(676,3);
this.SubFn2();
this.setPH(682);
_res= {r0:_t4,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:132:3

case 4: // if.done
this.setLatest(682,4);
this.SubFn3();

case 5: // if.then
this.setLatest(682,5);
this.setPH(687);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:137:3

case 6: // if.done
this.setLatest(687,6);
this.SubFn4();

case 7: // if.then
this.setLatest(687,7);
this.setPH(692);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:142:3

case 8: // if.done
this.setLatest(692,8);
this.SubFn5();

case 9: // if.then
this.setLatest(692,9);
this.setPH(696);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:146:3

case 10: // if.done
this.setLatest(696,10);
this.SubFn6();

case 11: // cond.false
this.setLatest(696,11);
this.SubFn7();

case 12: // if.then
this.setLatest(696,12);
this.SubFn8();

case 13: // if.done
this.setLatest(696,13);
this.SubFn9();

case 14: // if.then
this.setLatest(696,14);
this.setPH(703);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:153:4

case 15: // if.done
this.setLatest(703,15);
this.setPH(705);
_res= {r0:_t16,r1:2,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t16, 2:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:155:3

case 16: // if.then
this.setLatest(705,16);
this.setPH(710);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:160:3

case 17: // if.done
this.setLatest(710,17);
this.SubFn10();

case 18: // if.then
this.setLatest(710,18);
this.setPH(714);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:164:3

case 19: // if.done
this.setLatest(714,19);
this.SubFn11();

case 20: // cond.false
this.setLatest(714,20);
this.SubFn12();

case 21: // if.then
this.setLatest(714,21);
this.SubFn13();

case 22: // if.done
this.setLatest(714,22);
this.SubFn14();

case 23: // if.then
this.setLatest(714,23);
this.setPH(721);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:171:4

case 24: // if.done
this.setLatest(721,24);
this.SubFn15();

case 25: // if.then
this.setLatest(721,25);
this.setPH(724);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:174:4

case 26: // if.done
this.setLatest(724,26);
this.setPH(726);
_res= {r0:_t32,r1:3,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t32, 3:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:176:3

case 27: // cond.true
this.setLatest(726,27);
this.SubFn16();

case 28: // if.then
this.setLatest(726,28);
this.setPH(731);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:181:3

case 29: // if.done
this.setLatest(731,29);
this.SubFn17();

case 30: // if.then
this.setLatest(731,30);
this.setPH(735);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:185:3

case 31: // if.done
this.setLatest(735,31);
this.SubFn18();

case 32: // cond.false
this.setLatest(735,32);
this.SubFn19();

case 33: // if.then
this.setLatest(735,33);
this.SubFn20();

case 34: // if.done
this.setLatest(735,34);
this.setPH(748);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:198:2

case 35: // if.then
this.setLatest(748,35);
this.setPH(742);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:192:4

case 36: // if.done
this.setLatest(742,36);
this.setPH(744);
_res= {r0:_t54,r1:4,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t54, 4:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:194:3

case 37: // cond.false
this.setLatest(744,37);
this.SubFn21();

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t1:Bool;
this.setPH(674);
_t0=Force.toUTF8length(this._goroutine,p_s); // _t0 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:124:10
this.setPH(675);
_t1=(_t0<1); // _t1 = t0 < 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:125:7
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:125:7
}// end SubFn0
private inline function SubFn1():Void {
var _t3:Bool;
this.setPH(678);
_t2=Force.toUTF8slice(this._goroutine,p_s).getAt(0); // _t2 = s[0:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:128:9
this.setPH(681);
_t3=(Force.uintCompare(_t2,128)<0); // _t3 = t2 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:131:8
_Next=_t3 ? 3 : 4; // if t3 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:131:8
}// end SubFn1
private inline function SubFn2():Void {
this.setPH(682);
_t4=_t2; // _t4 = convert rune <- uint8 (t2) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:132:14
}// end SubFn2
private inline function SubFn3():Void {
var _t5:Bool;
this.setPH(686);
_t5=(Force.uintCompare(_t2,192)<0); // _t5 = t2 < 192:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:136:8
_Next=_t5 ? 5 : 6; // if t5 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:136:8
}// end SubFn3
private inline function SubFn4():Void {
var _t6:Bool;
this.setPH(691);
_t6=(_t0<2); // _t6 = t0 < 2:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:141:7
_Next=_t6 ? 7 : 8; // if t6 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:141:7
}// end SubFn4
private inline function SubFn5():Void {
var _t8:Bool;
this.setPH(694);
_t7=Force.toUTF8slice(this._goroutine,p_s).getAt(1); // _t7 = s[1:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:144:9
this.setPH(695);
_t8=(Force.uintCompare(_t7,128)<0); // _t8 = t7 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:145:8
_Next=_t8 ? 9 : 11; // if t8 goto 9.if.then else 11.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:145:8
}// end SubFn5
private inline function SubFn6():Void {
var _t9:Bool;
this.setPH(700);
_t9=(Force.uintCompare(_t2,224)<0); // _t9 = t2 < 224:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:150:8
_Next=_t9 ? 12 : 13; // if t9 goto 12.if.then else 13.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:150:8
}// end SubFn6
private inline function SubFn7():Void {
var _t10:Bool;
this.setPH(695);
_t10=(Force.uintCompare(192,_t7)<=0); // _t10 = 192:uint8 <= t7 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:145:19
_Next=_t10 ? 9 : 10; // if t10 goto 9.if.then else 10.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:145:19
}// end SubFn7
private inline function SubFn8():Void {
var _t11:Int;
var _t12:Int;
var _t13:Int;
var _t14:Int;
var _t15:Int;
var _t17:Bool;
this.setPH(701);
_t11=Force.toUint8((_t2&31)); // _t11 = t2 & 31:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:14
_t12=_t11; // _t12 = convert rune <- uint8 (t11) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:11
_t13=(_t12<<GOint64.toInt(GOint64.make(0x0,0x6))); // _t13 = t12 << 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:21
_t14=Force.toUint8((_t7&63)); // _t14 = t7 & 63:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:34
_t15=_t14; // _t15 = convert rune <- uint8 (t14) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:31
_t16=Force.toInt32((_t13|_t15)); // _t16 = t13 | t15 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:25
this.setPH(702);
_t17=(_t16<=127); // _t17 = t16 <= 127:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:152:8
_Next=_t17 ? 14 : 15; // if t17 goto 14.if.then else 15.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:152:8
}// end SubFn8
private inline function SubFn9():Void {
var _t18:Bool;
this.setPH(709);
_t18=(_t0<3); // _t18 = t0 < 3:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:159:7
_Next=_t18 ? 16 : 17; // if t18 goto 16.if.then else 17.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:159:7
}// end SubFn9
private inline function SubFn10():Void {
var _t20:Bool;
this.setPH(712);
_t19=Force.toUTF8slice(this._goroutine,p_s).getAt(2); // _t19 = s[2:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:162:9
this.setPH(713);
_t20=(Force.uintCompare(_t19,128)<0); // _t20 = t19 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:163:8
_Next=_t20 ? 18 : 20; // if t20 goto 18.if.then else 20.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:163:8
}// end SubFn10
private inline function SubFn11():Void {
var _t21:Bool;
this.setPH(718);
_t21=(Force.uintCompare(_t2,240)<0); // _t21 = t2 < 240:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:168:8
_Next=_t21 ? 21 : 22; // if t21 goto 21.if.then else 22.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:168:8
}// end SubFn11
private inline function SubFn12():Void {
var _t22:Bool;
this.setPH(713);
_t22=(Force.uintCompare(192,_t19)<=0); // _t22 = 192:uint8 <= t19 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:163:19
_Next=_t22 ? 18 : 19; // if t22 goto 18.if.then else 19.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:163:19
}// end SubFn12
private inline function SubFn13():Void {
var _t23:Int;
var _t24:Int;
var _t25:Int;
var _t26:Int;
var _t27:Int;
var _t28:Int;
var _t29:Int;
var _t30:Int;
var _t31:Int;
var _t33:Bool;
this.setPH(719);
_t23=Force.toUint8((_t2&15)); // _t23 = t2 & 15:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:169:14
_t24=_t23; // _t24 = convert rune <- uint8 (t23) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:169:11
_t25=(_t24<<GOint64.toInt(GOint64.make(0x0,0xc))); // _t25 = t24 << 12:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:169:21
_t26=Force.toUint8((_t7&63)); // _t26 = t7 & 63:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:169:35
_t27=_t26; // _t27 = convert rune <- uint8 (t26) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:169:32
_t28=(_t27<<GOint64.toInt(GOint64.make(0x0,0x6))); // _t28 = t27 << 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:169:42
_t29=Force.toInt32((_t25|_t28)); // _t29 = t25 | t28 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:169:26
_t30=Force.toUint8((_t19&63)); // _t30 = t19 & 63:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:169:55
_t31=_t30; // _t31 = convert rune <- uint8 (t30) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:169:52
_t32=Force.toInt32((_t29|_t31)); // _t32 = t29 | t31 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:169:46
this.setPH(720);
_t33=(_t32<=2047); // _t33 = t32 <= 2047:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:170:8
_Next=_t33 ? 23 : 24; // if t33 goto 23.if.then else 24.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:170:8
}// end SubFn13
private inline function SubFn14():Void {
var _t34:Bool;
this.setPH(730);
_t34=(_t0<4); // _t34 = t0 < 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:180:7
_Next=_t34 ? 28 : 29; // if t34 goto 28.if.then else 29.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:180:7
}// end SubFn14
private inline function SubFn15():Void {
var _t35:Bool;
this.setPH(723);
_t35=(55296<=_t32); // _t35 = 55296:rune <= t32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:173:19
_Next=_t35 ? 27 : 26; // if t35 goto 27.cond.true else 26.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:173:19
}// end SubFn15
private inline function SubFn16():Void {
var _t36:Bool;
_t36=(_t32<=57343); // _t36 = t32 <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:173:29
_Next=_t36 ? 25 : 26; // if t36 goto 25.if.then else 26.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:173:29
}// end SubFn16
private inline function SubFn17():Void {
var _t38:Bool;
this.setPH(733);
_t37=Force.toUTF8slice(this._goroutine,p_s).getAt(3); // _t37 = s[3:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:183:9
this.setPH(734);
_t38=(Force.uintCompare(_t37,128)<0); // _t38 = t37 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:184:8
_Next=_t38 ? 30 : 32; // if t38 goto 30.if.then else 32.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:184:8
}// end SubFn17
private inline function SubFn18():Void {
var _t39:Bool;
this.setPH(739);
_t39=(Force.uintCompare(_t2,248)<0); // _t39 = t2 < 248:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:189:8
_Next=_t39 ? 33 : 34; // if t39 goto 33.if.then else 34.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:189:8
}// end SubFn18
private inline function SubFn19():Void {
var _t40:Bool;
this.setPH(734);
_t40=(Force.uintCompare(192,_t37)<=0); // _t40 = 192:uint8 <= t37 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:184:19
_Next=_t40 ? 30 : 31; // if t40 goto 30.if.then else 31.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:184:19
}// end SubFn19
private inline function SubFn20():Void {
var _t41:Int;
var _t42:Int;
var _t43:Int;
var _t44:Int;
var _t45:Int;
var _t46:Int;
var _t47:Int;
var _t48:Int;
var _t49:Int;
var _t50:Int;
var _t51:Int;
var _t52:Int;
var _t53:Int;
var _t55:Bool;
this.setPH(740);
_t41=Force.toUint8((_t2&7)); // _t41 = t2 & 7:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:14
_t42=_t41; // _t42 = convert rune <- uint8 (t41) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:11
_t43=(_t42<<GOint64.toInt(GOint64.make(0x0,0x12))); // _t43 = t42 << 18:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:21
_t44=Force.toUint8((_t7&63)); // _t44 = t7 & 63:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:35
_t45=_t44; // _t45 = convert rune <- uint8 (t44) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:32
_t46=(_t45<<GOint64.toInt(GOint64.make(0x0,0xc))); // _t46 = t45 << 12:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:42
_t47=Force.toInt32((_t43|_t46)); // _t47 = t43 | t46 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:26
_t48=Force.toUint8((_t19&63)); // _t48 = t19 & 63:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:56
_t49=_t48; // _t49 = convert rune <- uint8 (t48) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:53
_t50=(_t49<<GOint64.toInt(GOint64.make(0x0,0x6))); // _t50 = t49 << 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:63
_t51=Force.toInt32((_t47|_t50)); // _t51 = t47 | t50 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:47
_t52=Force.toUint8((_t37&63)); // _t52 = t37 & 63:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:76
_t53=_t52; // _t53 = convert rune <- uint8 (t52) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:73
_t54=Force.toInt32((_t51|_t53)); // _t54 = t51 | t53 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:190:67
this.setPH(741);
_t55=(_t54<=65535); // _t55 = t54 <= 65535:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:8
_Next=_t55 ? 35 : 37; // if t55 goto 35.if.then else 37.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:8
}// end SubFn20
private inline function SubFn21():Void {
var _t56:Bool;
_t56=(1114111<_t54); // _t56 = 1114111:rune < t54 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:31
_Next=_t56 ? 35 : 36; // if t56 goto 35.if.then else 36.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:31
}// end SubFn21
}
#if js @:expose("Go_utf8_Valid") #end class Go_utf8_Valid extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:395:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,945,"Go_utf8_Valid");
this._bds=_bds;
this.p_p=p_p;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:Pointer=null;
var _t1:Int=0;
var _t2:Bool=false;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:Int=0;
var _t7:Slice=null;
var _SF1:StackFrame;
var _t8:{r0:Int,r1:Int}=null;
var _t10:Int=0;
var _t11:Bool=false;
var _t12:Int=0;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_p : Slice) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_Valid(0,[], p_p).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_p : Slice) : Bool {
var _sf=new Go_utf8_Valid(_gr,[], p_p).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_p : Slice) : Go_utf8_Valid
{return new Go_utf8_Valid(gr,_bds, p_p);
}
public function run():Go_utf8_Valid {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(945,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(945,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(945,2);
this.setPH(961);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:411:2

case 3: // for.loop
this.setLatest(961,3);
this.setPH(946);
_t3=((_Phi==0)?0:(_Phi==4)?_t6:(_Phi==7)?_t12:0); // _t3 = phi [0.entry: 0:int, 4.if.then: t6, 7.if.done: t12] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:396:2
this.SubFn2();
_Phi=3;
case 4: // if.then
this.setLatest(946,4);
this.SubFn3();
_Phi=4;
case 5: // if.else
this.setLatest(946,5);
this.SubFn4();
this.setPH(951);
_SF1=Go_utf8_DecodeRune.call(this._goroutine,[],_t7);
_Next = -1;
return this;
case -1:
this.setLatest(951,-1);
_t8=_SF1.res();
 // _t8 = DecodeRune(t7) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:25
this.SubFn5();
_Phi=5;
case 6: // if.then
this.setLatest(951,6);
this.setPH(956);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:406:5

case 7: // if.done
this.setLatest(956,7);
this.SubFn6();
_Phi=7;
default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:406:5
}// end SubFn0
private inline function SubFn1():Void {
var _t0:Pointer;
var _t1:Int;
var _t2:Bool;
this.setPH(948);
if((_t3<0)||(_t3>=p_p.len())) Scheduler.ioor(); // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:7 [POINTER]
_t0=p_p.addr(_t3);  // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:7 [POINTER]
_t1=(_t0.load()|0); // _t1 = *t0 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:7
_t2=(Force.uintCompare(_t1,128)<0); // _t2 = t1 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:11
_Next=_t2 ? 4 : 5; // if t2 goto 4.if.then else 5.if.else *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:11
}// end SubFn1
private inline function SubFn2():Void {
var _t4:Int;
var _t5:Bool;
this.setPH(947);
_t4=({var _v=p_p;_v==null?0:_v.len();}); // _t4 = len(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:13
_t5=(_t3<_t4); // _t5 = t3 < t4 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
_Next=_t5 ? 1 : 2; // if t5 goto 1.for.body else 2.for.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
}// end SubFn2
private inline function SubFn3():Void {
_t6=(_t3+1); // _t6 = t3 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
}// end SubFn3
private inline function SubFn4():Void {
this.setPH(951);
_t7=p_p.subSlice(_t3,-1); // _t7 = slice p[t3:] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:27
}// end SubFn4
private inline function SubFn5():Void {
var _t11:Bool;
 // _t9 = extract t8 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:27 [REGISTER VALUE UN-USED]
_t10=_t8.r1; // _t10 = extract t8 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:27
this.setPH(952);
_t11=(_t10==1); // _t11 = t10 == 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
_Next=_t11 ? 6 : 7; // if t11 goto 6.if.then else 7.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
}// end SubFn5
private inline function SubFn6():Void {
_t12=(_t3+_t10); // _t12 = t3 + t10 *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
}// end SubFn6
}
#if js @:expose("Go_hxutil_NumGoroutine") #end class Go_hxutil_NumGoroutine extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:40:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1033,"Go_hxutil_NumGoroutine");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:Dynamic=null;
var _t1:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_hxutil_NumGoroutine(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : Int {
var _sf=new Go_hxutil_NumGoroutine(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_hxutil_NumGoroutine
{return new Go_hxutil_NumGoroutine(gr,_bds);
}
public function run():Go_hxutil_NumGoroutine {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1033,0);
_t0=Scheduler.NumGoroutine(); // _t0 = HAXE("Scheduler.NumGoro...":string) *ssa.Call @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:40:42
this.SubFn0();
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:40:27

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t1=cast(_t0,Int); // _t1 = convert int <- uintptr (t0) *ssa.Convert @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:40:37
}// end SubFn0
}
#if js @:expose("Go_utf16_Encode") #end class Go_utf16_Encode extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:56:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,498,"Go_utf16_Encode");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Int=0;
var _t2:Int=0;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:Pointer=null;
var _t7:Int=0;
var _t8:Bool=false;
var _t9:Slice=null;
var _t10:Int=0;
var _t11:Int=0;
var _t12:Int=0;
var _t13:Int=0;
var _t14:Int=0;
var _t15:Bool=false;
var _t16:Pointer=null;
var _t17:Int=0;
var _t18:Bool=false;
var _t19:Slice=null;
var _t20:Int=0;
var _t21:Pointer=null;
var _t22:Int=0;
var _t23:Int=0;
var _t24:Bool=false;
var _t25:Bool=false;
var _t26:Bool=false;
var _t27:Bool=false;
var _t28:Bool=false;
var _SF1:StackFrame;
var _t29:{r0:Int,r1:Int}=null;
var _t30:Int=0;
var _t31:Int=0;
var _t32:Pointer=null;
var _t33:Int=0;
var _t34:Int=0;
var _t35:Pointer=null;
var _t36:Int=0;
var _t37:Int=0;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : Slice) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf16_Encode(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : Slice) : Slice {
var _sf=new Go_utf16_Encode(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : Slice) : Go_utf16_Encode
{return new Go_utf16_Encode(gr,_bds, p_s);
}
public function run():Go_utf16_Encode {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(498,0);
this.SubFn0();
_Phi=0;
case 1: // rangeindex.loop
this.setLatest(498,1);
this.setPH(499);
_t2=((_Phi==0)?_t0:(_Phi==2)?_t2:(_Phi==4)?_t11:0); // _t2 = phi [0.entry: t0, 2.rangeindex.body: t2, 4.if.then: t11] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
_t3=((_Phi==0)?(-1):(_Phi==2)?_t4:(_Phi==4)?_t4:0); // _t3 = phi [0.entry: -1:int, 2.rangeindex.body: t4, 4.if.then: t4] *ssa.Phi near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
this.SubFn1();
_Phi=1;
case 2: // rangeindex.body
this.setLatest(499,2);
this.SubFn2();
_Phi=2;
case 3: // rangeindex.done
this.setLatest(499,3);
this.SubFn3();
_Phi=3;
case 4: // if.then
this.setLatest(499,4);
this.SubFn4();
_Phi=4;
case 5: // rangeindex.loop
this.setLatest(499,5);
_t12=((_Phi==3)?0:(_Phi==9)?_t23:(_Phi==15)?_t37:0); // _t12 = phi [3.rangeindex.done: 0:int, 9.switch.body: t23, 15.switch.next: t37] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
_t13=((_Phi==3)?(-1):(_Phi==9)?_t14:(_Phi==15)?_t14:0); // _t13 = phi [3.rangeindex.done: -1:int, 9.switch.body: t14, 15.switch.next: t14] *ssa.Phi near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
this.SubFn5();
_Phi=5;
case 6: // rangeindex.body
this.setLatest(499,6);
this.SubFn6();
_Phi=6;
case 7: // rangeindex.done
this.setLatest(499,7);
this.SubFn7();
this.setPH(523);
_res= _t19;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t19 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:81:2

case 8: // switch.body
this.setLatest(523,8);
this.SubFn8();
_Phi=8;
case 9: // switch.body
this.setLatest(523,9);
this.setPH(508);
_t20=((_Phi==8)?65533:(_Phi==14)?_t17:0); // _t20 = phi [8.switch.body: 65533:rune, 14.switch.next: t17] #v *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:66:9
this.SubFn9();
_Phi=9;
case 10: // switch.next
this.setLatest(508,10);
this.SubFn10();
_Phi=10;
case 11: // switch.next
this.setLatest(508,11);
this.SubFn11();
_Phi=11;
case 12: // binop.rhs
this.setLatest(508,12);
this.SubFn12();
_Phi=12;
case 13: // binop.done
this.setLatest(508,13);
this.setPH(510);
_t27=((_Phi==10)?false:(_Phi==12)?_t26:false); // _t27 = phi [10.switch.next: false:bool, 12.binop.rhs: t26] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:26
this.SubFn13();
_Phi=13;
case 14: // switch.next
this.setLatest(510,14);
this.SubFn14();
_Phi=14;
case 15: // switch.next
this.setLatest(510,15);
this.setPH(517);
_SF1=Go_utf16_EncodeRune.call(this._goroutine,[],_t17);
_Next = -1;
return this;
case -1:
this.setLatest(517,-1);
_t29=_SF1.res();
 // _t29 = EncodeRune(t17) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:75:24
this.SubFn15();
_Phi=15;
default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
this.setPH(499);
_t0=({var _v=p_s;_v==null?0:_v.len();}); // _t0 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
_t1=({var _v=p_s;_v==null?0:_v.len();}); // _t1 = len(s) *ssa.Call near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
}// end SubFn0
private inline function SubFn1():Void {
var _t5:Bool;
_t4=(_t3+1); // _t4 = t3 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
_t5=(_t4<_t1); // _t5 = t4 < t1 *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
_Next=_t5 ? 2 : 3; // if t5 goto 2.rangeindex.body else 3.rangeindex.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
}// end SubFn1
private inline function SubFn2():Void {
var _t6:Pointer;
var _t8:Bool;
if((_t4<0)||(_t4>=p_s.len())) Scheduler.ioor(); // _t6 = &s[t4] *ssa.IndexAddr near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10 [POINTER]
_t6=p_s.addr(_t4);  // _t6 = &s[t4] *ssa.IndexAddr near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10 [POINTER]
_t7=(_t6.load()|0); // _t7 = *t6 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
this.setPH(501);
_t8=(_t7>=65536); // _t8 = t7 >= 65536:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:59:8
_Next=_t8 ? 4 : 1; // if t8 goto 4.if.then else 1.rangeindex.loop *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:59:8
}// end SubFn2
private inline function SubFn3():Void {
this.setPH(506);
_t9=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t2) _v[_i]=0; _v;}),0,_t2); // _t9 = make []uint16 t2 t2 *ssa.MakeSlice @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
_t10=({var _v=p_s;_v==null?0:_v.len();}); // _t10 = len(s) *ssa.Call near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
_Next=5; // jump 5.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
}// end SubFn3
private inline function SubFn4():Void {
_t11=(_t2+1); // _t11 = t2 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
}// end SubFn4
private inline function SubFn5():Void {
var _t15:Bool;
_t14=(_t13+1); // _t14 = t13 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
_t15=(_t14<_t10); // _t15 = t14 < t10 *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
_Next=_t15 ? 6 : 7; // if t15 goto 6.rangeindex.body else 7.rangeindex.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
}// end SubFn5
private inline function SubFn6():Void {
var _t16:Pointer;
var _t18:Bool;
if((_t14<0)||(_t14>=p_s.len())) Scheduler.ioor(); // _t16 = &s[t14] *ssa.IndexAddr near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11 [POINTER]
_t16=p_s.addr(_t14);  // _t16 = &s[t14] *ssa.IndexAddr near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11 [POINTER]
_t17=(_t16.load()|0); // _t17 = *t16 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
this.setPH(510);
_t18=(_t17<0); // _t18 = t17 < 0:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:10
_Next=_t18 ? 8 : 10; // if t18 goto 8.switch.body else 10.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:10
}// end SubFn6
private inline function SubFn7():Void {
this.setPH(523);
_t19=_t9.subSlice(0,_t12); // _t19 = slice t9[0:int:t12] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:81:10
}// end SubFn7
private inline function SubFn8():Void {
_Next=9; // jump 9.switch.body *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:81:10
}// end SubFn8
private inline function SubFn9():Void {
var _t21:Pointer;
var _t22:Int;
this.setPH(514);
if((_t12<0)||(_t12>=_t9.len())) Scheduler.ioor(); // _t21 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:5 [POINTER]
_t21=_t9.addr(_t12);  // _t21 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:5 [POINTER]
_t22=_t20; // _t22 = convert uint16 <- rune (t20) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
_t21.store(_t22); // *t21 = t22 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
_t23=(_t12+1); // _t23 = t12 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
_Next=5; // jump 5.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
}// end SubFn9
private inline function SubFn10():Void {
var _t24:Bool;
this.setPH(510);
_t24=(55296<=_t17); // _t24 = 55296:rune <= t17 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:21
_Next=_t24 ? 12 : 13; // if t24 goto 12.binop.rhs else 13.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:21
}// end SubFn10
private inline function SubFn11():Void {
var _t25:Bool;
_t25=(_t17>1114111); // _t25 = t17 > 1114111:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:42
_Next=_t25 ? 8 : 14; // if t25 goto 8.switch.body else 14.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:42
}// end SubFn11
private inline function SubFn12():Void {
_t26=(_t17<57344); // _t26 = t17 < 57344:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:31
_Next=13; // jump 13.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:31
}// end SubFn12
private inline function SubFn13():Void {
_Next=_t27 ? 8 : 11; // if t27 goto 8.switch.body else 11.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:31
}// end SubFn13
private inline function SubFn14():Void {
var _t28:Bool;
this.setPH(513);
_t28=(_t17<65536); // _t28 = t17 < 65536:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:71:10
_Next=_t28 ? 9 : 15; // if t28 goto 9.switch.body else 15.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:71:10
}// end SubFn14
private inline function SubFn15():Void {
var _t32:Pointer;
var _t33:Int;
var _t34:Int;
var _t35:Pointer;
var _t36:Int;
_t30=_t29.r0; // _t30 = extract t29 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf16/utf16.go:71:10
_t31=_t29.r1; // _t31 = extract t29 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf16/utf16.go:71:10
this.setPH(518);
if((_t12<0)||(_t12>=_t9.len())) Scheduler.ioor(); // _t32 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:5 [POINTER]
_t32=_t9.addr(_t12);  // _t32 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:5 [POINTER]
_t33=_t30; // _t33 = convert uint16 <- rune (t30) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:17
_t32.store(_t33); // *t32 = t33 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:17
this.setPH(519);
_t34=(_t12+1); // _t34 = t12 + 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:7
if((_t34<0)||(_t34>=_t9.len())) Scheduler.ioor(); // _t35 = &t9[t34] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:5 [POINTER]
_t35=_t9.addr(_t34);  // _t35 = &t9[t34] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:5 [POINTER]
_t36=_t31; // _t36 = convert uint16 <- rune (t31) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
_t35.store(_t36); // *t35 = t36 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
_t37=(_t12+2); // _t37 = t12 + 2:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
_Next=5; // jump 5.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
}// end SubFn15
}
#if js @:expose("Go_haxegoruntime_M5") #end class Go_haxegoruntime_M5 extends StackFrameBasis implements StackFrame {  // goruntime.go:158:6
var p_rx:Interface;
var p_typ:String;
var p_meth:String;
var p_a1:Interface;
var p_a2:Interface;
var p_a3:Interface;
var p_a4:Interface;
var p_a5:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface) {
super(gr,220,"Go_haxegoruntime_M5");
this._bds=_bds;
this.p_rx=p_rx;
this.p_typ=p_typ;
this.p_meth=p_meth;
this.p_a1=p_a1;
this.p_a2=p_a2;
this.p_a3=p_a3;
this.p_a4=p_a4;
this.p_a5=p_a5;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_M5(0,[], p_rx, p_typ, p_meth, p_a1, p_a2, p_a3, p_a4, p_a5).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface) : Interface {
var _sf=new Go_haxegoruntime_M5(_gr,[], p_rx, p_typ, p_meth, p_a1, p_a2, p_a3, p_a4, p_a5).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface, p_a5 : Interface) : Go_haxegoruntime_M5
{return new Go_haxegoruntime_M5(gr,_bds, p_rx, p_typ, p_meth, p_a1, p_a2, p_a3, p_a4, p_a5);
}
public function run():Go_haxegoruntime_M5 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(220,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:158:93

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_meth); // _t0 = make interface{} <- string (meth) *ssa.MakeInterface near goruntime.go:158:93
}// end SubFn0
}
#if (!php) private #end class Go_haxegoruntime_getgoroot extends StackFrameBasis implements StackFrame {  // goruntime.go:373:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,435,"Go_haxegoruntime_getgoroot");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_getgoroot(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_haxegoruntime_getgoroot(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_haxegoruntime_getgoroot
{return new Go_haxegoruntime_getgoroot(gr,_bds);
}
public function run():Go_haxegoruntime_getgoroot {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(435,0);
this.SubFn0();
this.setPH(436);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(436,-1);
 // panic t0 *ssa.Panic @ goruntime.go:374:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,"runtime.getgoroot() not yet implemented"); // _t0 = make interface{} <- string ("runtime.getgoroot...":string) *ssa.MakeInterface near goruntime.go:374:7
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_C0") #end class Go_haxegoruntime_C0 extends StackFrameBasis implements StackFrame {  // goruntime.go:142:6
var p_funcName:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_funcName : String) {
super(gr,204,"Go_haxegoruntime_C0");
this._bds=_bds;
this.p_funcName=p_funcName;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_funcName : String) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_C0(0,[], p_funcName).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_funcName : String) : Interface {
var _sf=new Go_haxegoruntime_C0(_gr,[], p_funcName).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_funcName : String) : Go_haxegoruntime_C0
{return new Go_haxegoruntime_C0(gr,_bds, p_funcName);
}
public function run():Go_haxegoruntime_C0 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(204,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:142:76

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_funcName); // _t0 = make interface{} <- string (funcName) *ssa.MakeInterface near goruntime.go:142:76
}// end SubFn0
}
#if js @:expose("Go_utf8_EncodeRune") #end class Go_utf8_EncodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:330:6
var p_p:Slice;
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice, p_r : Int) {
super(gr,880,"Go_utf8_EncodeRune");
this._bds=_bds;
this.p_p=p_p;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Bool=false;
var _t2:Pointer=null;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:Pointer=null;
var _t7:Int=0;
var _t8:Int=0;
var _t9:Int=0;
var _t10:Pointer=null;
var _t11:Int=0;
var _t12:Int=0;
var _t13:Int=0;
var _t14:Int=0;
var _t15:Bool=false;
var _t16:Int=0;
var _t17:Bool=false;
var _t18:Int=0;
var _t19:Int=0;
var _t20:Bool=false;
var _t21:Bool=false;
var _t22:Pointer=null;
var _t23:Int=0;
var _t24:Int=0;
var _t25:Int=0;
var _t26:Pointer=null;
var _t27:Int=0;
var _t28:Int=0;
var _t29:Int=0;
var _t30:Int=0;
var _t31:Pointer=null;
var _t32:Int=0;
var _t33:Int=0;
var _t34:Int=0;
var _t35:Pointer=null;
var _t36:Int=0;
var _t37:Int=0;
var _t38:Int=0;
var _t39:Pointer=null;
var _t40:Int=0;
var _t41:Int=0;
var _t42:Int=0;
var _t43:Int=0;
var _t44:Pointer=null;
var _t45:Int=0;
var _t46:Int=0;
var _t47:Int=0;
var _t48:Int=0;
var _t49:Pointer=null;
var _t50:Int=0;
var _t51:Int=0;
var _t52:Int=0;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_p : Slice, p_r : Int) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_EncodeRune(0,[], p_p, p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_p : Slice, p_r : Int) : Int {
var _sf=new Go_utf8_EncodeRune(_gr,[], p_p, p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_p : Slice, p_r : Int) : Go_utf8_EncodeRune
{return new Go_utf8_EncodeRune(gr,_bds, p_p, p_r);
}
public function run():Go_utf8_EncodeRune {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(880,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(880,1);
this.SubFn1();
this.setPH(884);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:334:3

case 2: // if.done
this.setLatest(884,2);
this.SubFn2();
_Phi=2;
case 3: // if.then
this.setLatest(884,3);
this.SubFn3();
this.setPH(890);
_res= 2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 2:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:340:3

case 4: // if.done
this.setLatest(890,4);
this.SubFn4();
_Phi=4;
case 5: // if.then
this.setLatest(890,5);
this.SubFn5();
_Phi=5;
case 6: // if.done
this.setLatest(890,6);
this.setPH(880);
_t16=((_Phi==4)?p_r:(_Phi==5)?65533:0); // _t16 = phi [4.if.done: r, 5.if.then: 65533:rune] #r *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:330:27
this.SubFn6();
_Phi=6;
case 7: // if.then
this.setLatest(880,7);
this.SubFn7();
_Phi=7;
case 8: // if.done
this.setLatest(880,8);
_t18=((_Phi==6)?_t16:(_Phi==9)?_t16:(_Phi==7)?65533:0); // _t18 = phi [6.if.done: t16, 9.cond.true: t16, 7.if.then: 65533:rune] #r *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:330:27
this.SubFn8();
_Phi=8;
case 9: // cond.true
this.setLatest(880,9);
this.SubFn9();
_Phi=9;
case 10: // if.then
this.setLatest(880,10);
this.SubFn10();
this.setPH(905);
_res= 3;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 3:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:355:3

case 11: // if.done
this.setLatest(905,11);
this.SubFn11();
this.setPH(912);
_res= 4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 4:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:362:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Int;
var _t1:Bool;
this.setPH(882);
_t0=p_r; // _t0 = convert uint32 <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:332:11
_t1=(Force.uintCompare(_t0,127)<=0); // _t1 = t0 <= 127:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:332:15
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:332:15
}// end SubFn0
private inline function SubFn1():Void {
var _t2:Pointer;
var _t3:Int;
this.setPH(883);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:4 [POINTER]
_t2=p_p.addr(0);  // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:4 [POINTER]
_t3=p_r; // _t3 = convert byte <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:14
_t2.store(_t3); // *t2 = t3 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:14
}// end SubFn1
private inline function SubFn2():Void {
var _t4:Int;
var _t5:Bool;
this.setPH(887);
_t4=p_r; // _t4 = convert uint32 <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:337:11
_t5=(Force.uintCompare(_t4,2047)<=0); // _t5 = t4 <= 2047:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:337:15
_Next=_t5 ? 3 : 4; // if t5 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:337:15
}// end SubFn2
private inline function SubFn3():Void {
var _t6:Pointer;
var _t7:Int;
var _t8:Int;
var _t9:Int;
var _t10:Pointer;
var _t11:Int;
var _t12:Int;
var _t13:Int;
this.setPH(888);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t6 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:4 [POINTER]
_t6=p_p.addr(0);  // _t6 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:4 [POINTER]
_t7=(p_r>>GOint64.toInt(GOint64.make(0x0,0x6))); // _t7 = r >> 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:21
_t8=_t7; // _t8 = convert byte <- rune (t7) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:19
_t9=Force.toUint8((192|_t8)); // _t9 = 192:byte | t8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:13
_t6.store(_t9); // *t6 = t9 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:13
this.setPH(889);
if((1<0)||(1>=p_p.len())) Scheduler.ioor(); // _t10 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:4 [POINTER]
_t10=p_p.addr(1);  // _t10 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:4 [POINTER]
_t11=p_r; // _t11 = convert byte <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:19
_t12=Force.toUint8((_t11&63)); // _t12 = t11 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:22
_t13=Force.toUint8((128|_t12)); // _t13 = 128:byte | t12 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:13
_t10.store(_t13); // *t10 = t13 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:13
}// end SubFn3
private inline function SubFn4():Void {
var _t14:Int;
var _t15:Bool;
this.setPH(893);
_t14=p_r; // _t14 = convert uint32 <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:11
_t15=(Force.uintCompare(_t14,1114111)>0); // _t15 = t14 > 1114111:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:15
_Next=_t15 ? 5 : 6; // if t15 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:15
}// end SubFn4
private inline function SubFn5():Void {
_Next=6; // jump 6.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:15
}// end SubFn5
private inline function SubFn6():Void {
var _t17:Bool;
this.setPH(897);
_t17=(55296<=_t16); // _t17 = 55296:rune <= t16 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:18
_Next=_t17 ? 9 : 8; // if t17 goto 9.cond.true else 8.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:18
}// end SubFn6
private inline function SubFn7():Void {
_Next=8; // jump 8.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:18
}// end SubFn7
private inline function SubFn8():Void {
var _t19:Int;
var _t20:Bool;
this.setPH(901);
_t19=_t18; // _t19 = convert uint32 <- rune (t18) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:351:11
_t20=(Force.uintCompare(_t19,65535)<=0); // _t20 = t19 <= 65535:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:351:15
_Next=_t20 ? 10 : 11; // if t20 goto 10.if.then else 11.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:351:15
}// end SubFn8
private inline function SubFn9():Void {
var _t21:Bool;
this.setPH(897);
_t21=(_t16<=57343); // _t21 = t16 <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:28
_Next=_t21 ? 7 : 8; // if t21 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:28
}// end SubFn9
private inline function SubFn10():Void {
var _t22:Pointer;
var _t23:Int;
var _t24:Int;
var _t25:Int;
var _t26:Pointer;
var _t27:Int;
var _t28:Int;
var _t29:Int;
var _t30:Int;
var _t31:Pointer;
var _t32:Int;
var _t33:Int;
var _t34:Int;
this.setPH(902);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t22 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:4 [POINTER]
_t22=p_p.addr(0);  // _t22 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:4 [POINTER]
_t23=(_t18>>GOint64.toInt(GOint64.make(0x0,0xc))); // _t23 = t18 >> 12:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:21
_t24=_t23; // _t24 = convert byte <- rune (t23) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:19
_t25=Force.toUint8((224|_t24)); // _t25 = 224:byte | t24 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:13
_t22.store(_t25); // *t22 = t25 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:13
this.setPH(903);
if((1<0)||(1>=p_p.len())) Scheduler.ioor(); // _t26 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:4 [POINTER]
_t26=p_p.addr(1);  // _t26 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:4 [POINTER]
_t27=(_t18>>GOint64.toInt(GOint64.make(0x0,0x6))); // _t27 = t18 >> 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:21
_t28=_t27; // _t28 = convert byte <- rune (t27) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:19
_t29=Force.toUint8((_t28&63)); // _t29 = t28 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:25
_t30=Force.toUint8((128|_t29)); // _t30 = 128:byte | t29 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:13
_t26.store(_t30); // *t26 = t30 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:13
this.setPH(904);
if((2<0)||(2>=p_p.len())) Scheduler.ioor(); // _t31 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:4 [POINTER]
_t31=p_p.addr(2);  // _t31 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:4 [POINTER]
_t32=_t18; // _t32 = convert byte <- rune (t18) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:19
_t33=Force.toUint8((_t32&63)); // _t33 = t32 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:22
_t34=Force.toUint8((128|_t33)); // _t34 = 128:byte | t33 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:13
_t31.store(_t34); // *t31 = t34 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:13
}// end SubFn10
private inline function SubFn11():Void {
var _t35:Pointer;
var _t36:Int;
var _t37:Int;
var _t38:Int;
var _t39:Pointer;
var _t40:Int;
var _t41:Int;
var _t42:Int;
var _t43:Int;
var _t44:Pointer;
var _t45:Int;
var _t46:Int;
var _t47:Int;
var _t48:Int;
var _t49:Pointer;
var _t50:Int;
var _t51:Int;
var _t52:Int;
this.setPH(908);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t35 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:3 [POINTER]
_t35=p_p.addr(0);  // _t35 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:3 [POINTER]
_t36=(_t18>>GOint64.toInt(GOint64.make(0x0,0x12))); // _t36 = t18 >> 18:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:20
_t37=_t36; // _t37 = convert byte <- rune (t36) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:18
_t38=Force.toUint8((240|_t37)); // _t38 = 240:byte | t37 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:12
_t35.store(_t38); // *t35 = t38 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:12
this.setPH(909);
if((1<0)||(1>=p_p.len())) Scheduler.ioor(); // _t39 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:3 [POINTER]
_t39=p_p.addr(1);  // _t39 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:3 [POINTER]
_t40=(_t18>>GOint64.toInt(GOint64.make(0x0,0xc))); // _t40 = t18 >> 12:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:20
_t41=_t40; // _t41 = convert byte <- rune (t40) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:18
_t42=Force.toUint8((_t41&63)); // _t42 = t41 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:25
_t43=Force.toUint8((128|_t42)); // _t43 = 128:byte | t42 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:12
_t39.store(_t43); // *t39 = t43 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:12
this.setPH(910);
if((2<0)||(2>=p_p.len())) Scheduler.ioor(); // _t44 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:3 [POINTER]
_t44=p_p.addr(2);  // _t44 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:3 [POINTER]
_t45=(_t18>>GOint64.toInt(GOint64.make(0x0,0x6))); // _t45 = t18 >> 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:20
_t46=_t45; // _t46 = convert byte <- rune (t45) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:18
_t47=Force.toUint8((_t46&63)); // _t47 = t46 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:24
_t48=Force.toUint8((128|_t47)); // _t48 = 128:byte | t47 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:12
_t44.store(_t48); // *t44 = t48 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:12
this.setPH(911);
if((3<0)||(3>=p_p.len())) Scheduler.ioor(); // _t49 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:3 [POINTER]
_t49=p_p.addr(3);  // _t49 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:3 [POINTER]
_t50=_t18; // _t50 = convert byte <- rune (t18) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:18
_t51=Force.toUint8((_t50&63)); // _t51 = t50 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:21
_t52=Force.toUint8((128|_t51)); // _t52 = 128:byte | t51 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:12
_t49.store(_t52); // *t49 = t52 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:12
}// end SubFn11
}
#if js @:expose("Go_hxutil_Zilen") #end class Go_hxutil_Zilen extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:24:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1017,"Go_hxutil_Zilen");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_hxutil_Zilen(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : Int {
var _sf=new Go_hxutil_Zilen(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_hxutil_Zilen
{return new Go_hxutil_Zilen(gr,_bds);
}
public function run():Go_hxutil_Zilen {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1017,0);
_res= 3;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 3:uint *ssa.Return @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:24:21

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_haxegoruntime_UTF16toRunes") #end class Go_haxegoruntime_UTF16toRunes extends StackFrameBasis implements StackFrame {  // goruntime.go:21:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,83,"Go_haxegoruntime_UTF16toRunes");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:Slice=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : Slice) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_UTF16toRunes(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : Slice) : Slice {
var _sf=new Go_haxegoruntime_UTF16toRunes(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : Slice) : Go_haxegoruntime_UTF16toRunes
{return new Go_haxegoruntime_UTF16toRunes(gr,_bds, p_s);
}
public function run():Go_haxegoruntime_UTF16toRunes {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(83,0);
this.setPH(84);
_SF1=Go_utf16_Decode.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(84,-1);
_t0=_SF1.res();
 // _t0 = unicode/utf16.Decode(s) *ssa.Call @ goruntime.go:22:21
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:22:2

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_haxegoruntime_CPos") #end class Go_haxegoruntime_CPos extends StackFrameBasis implements StackFrame {  // goruntime.go:136:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,198,"Go_haxegoruntime_CPos");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_CPos(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_haxegoruntime_CPos(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_haxegoruntime_CPos
{return new Go_haxegoruntime_CPos(gr,_bds);
}
public function run():Go_haxegoruntime_CPos {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(198,0);
_res= "<<code pos>>";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "<<code pos>>":string *ssa.Return @ goruntime.go:136:22

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_haxegoruntime_C3") #end class Go_haxegoruntime_C3 extends StackFrameBasis implements StackFrame {  // goruntime.go:145:6
var p_funcName:String;
var p_a1:Interface;
var p_a2:Interface;
var p_a3:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface) {
super(gr,207,"Go_haxegoruntime_C3");
this._bds=_bds;
this.p_funcName=p_funcName;
this.p_a1=p_a1;
this.p_a2=p_a2;
this.p_a3=p_a3;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_C3(0,[], p_funcName, p_a1, p_a2, p_a3).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface) : Interface {
var _sf=new Go_haxegoruntime_C3(_gr,[], p_funcName, p_a1, p_a2, p_a3).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_funcName : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface) : Go_haxegoruntime_C3
{return new Go_haxegoruntime_C3(gr,_bds, p_funcName, p_a1, p_a2, p_a3);
}
public function run():Go_haxegoruntime_C3 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(207,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:145:76

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_funcName); // _t0 = make interface{} <- string (funcName) *ssa.MakeInterface near goruntime.go:145:76
}// end SubFn0
}
#if (!php) private #end class Go_utf8_decodeRuneInternal extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:45:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,595,"Go_utf8_decodeRuneInternal");
this._bds=_bds;
this.p_p=p_p;
Scheduler.push(gr,this);
}
var _res:{r0:Int, r1:Int, r2:Bool};
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Bool=false;
var _t2:Pointer=null;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Int=0;
var _t6:Bool=false;
var _t7:Bool=false;
var _t8:Pointer=null;
var _t9:Int=0;
var _t10:Bool=false;
var _t11:Bool=false;
var _t12:Bool=false;
var _t13:Int=0;
var _t14:Int=0;
var _t15:Int=0;
var _t16:Int=0;
var _t17:Int=0;
var _t18:Int=0;
var _t19:Bool=false;
var _t20:Bool=false;
var _t21:Pointer=null;
var _t22:Int=0;
var _t23:Bool=false;
var _t24:Bool=false;
var _t25:Bool=false;
var _t26:Int=0;
var _t27:Int=0;
var _t28:Int=0;
var _t29:Int=0;
var _t30:Int=0;
var _t31:Int=0;
var _t32:Int=0;
var _t33:Int=0;
var _t34:Int=0;
var _t35:Int=0;
var _t36:Bool=false;
var _t37:Bool=false;
var _t38:Bool=false;
var _t39:Bool=false;
var _t40:Pointer=null;
var _t41:Int=0;
var _t42:Bool=false;
var _t43:Bool=false;
var _t44:Bool=false;
var _t45:Int=0;
var _t46:Int=0;
var _t47:Int=0;
var _t48:Int=0;
var _t49:Int=0;
var _t50:Int=0;
var _t51:Int=0;
var _t52:Int=0;
var _t53:Int=0;
var _t54:Int=0;
var _t55:Int=0;
var _t56:Int=0;
var _t57:Int=0;
var _t58:Int=0;
var _t59:Bool=false;
var _t60:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_p : Slice) : {r0:Int, r1:Int, r2:Bool} {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_decodeRuneInternal(0,[], p_p).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_p : Slice) : {r0:Int, r1:Int, r2:Bool} {
var _sf=new Go_utf8_decodeRuneInternal(_gr,[], p_p).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_p : Slice) : Go_utf8_decodeRuneInternal
{return new Go_utf8_decodeRuneInternal(gr,_bds, p_p);
}
public function run():Go_utf8_decodeRuneInternal {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(595,0);
this.SubFn0();

case 1: // if.then
this.setLatest(595,1);
this.setPH(598);
_res= {r0:65533,r1:0,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:48:3

case 2: // if.done
this.setLatest(598,2);
this.SubFn1();

case 3: // if.then
this.setLatest(598,3);
this.SubFn2();
this.setPH(604);
_res= {r0:_t5,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:54:3

case 4: // if.done
this.setLatest(604,4);
this.SubFn3();

case 5: // if.then
this.setLatest(604,5);
this.setPH(609);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:59:3

case 6: // if.done
this.setLatest(609,6);
this.SubFn4();

case 7: // if.then
this.setLatest(609,7);
this.setPH(614);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:64:3

case 8: // if.done
this.setLatest(614,8);
this.SubFn5();

case 9: // if.then
this.setLatest(614,9);
this.setPH(618);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:68:3

case 10: // if.done
this.setLatest(618,10);
this.SubFn6();

case 11: // cond.false
this.setLatest(618,11);
this.SubFn7();

case 12: // if.then
this.setLatest(618,12);
this.SubFn8();

case 13: // if.done
this.setLatest(618,13);
this.SubFn9();

case 14: // if.then
this.setLatest(618,14);
this.setPH(625);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:75:4

case 15: // if.done
this.setLatest(625,15);
this.setPH(627);
_res= {r0:_t18,r1:2,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t18, 2:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:77:3

case 16: // if.then
this.setLatest(627,16);
this.setPH(632);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:82:3

case 17: // if.done
this.setLatest(632,17);
this.SubFn10();

case 18: // if.then
this.setLatest(632,18);
this.setPH(636);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:86:3

case 19: // if.done
this.setLatest(636,19);
this.SubFn11();

case 20: // cond.false
this.setLatest(636,20);
this.SubFn12();

case 21: // if.then
this.setLatest(636,21);
this.SubFn13();

case 22: // if.done
this.setLatest(636,22);
this.SubFn14();

case 23: // if.then
this.setLatest(636,23);
this.setPH(643);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:93:4

case 24: // if.done
this.setLatest(643,24);
this.SubFn15();

case 25: // if.then
this.setLatest(643,25);
this.setPH(646);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:96:4

case 26: // if.done
this.setLatest(646,26);
this.setPH(648);
_res= {r0:_t35,r1:3,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t35, 3:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:98:3

case 27: // cond.true
this.setLatest(648,27);
this.SubFn16();

case 28: // if.then
this.setLatest(648,28);
this.setPH(653);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:103:3

case 29: // if.done
this.setLatest(653,29);
this.SubFn17();

case 30: // if.then
this.setLatest(653,30);
this.setPH(657);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:107:3

case 31: // if.done
this.setLatest(657,31);
this.SubFn18();

case 32: // cond.false
this.setLatest(657,32);
this.SubFn19();

case 33: // if.then
this.setLatest(657,33);
this.SubFn20();

case 34: // if.done
this.setLatest(657,34);
this.setPH(670);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:120:2

case 35: // if.then
this.setLatest(670,35);
this.setPH(664);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:114:4

case 36: // if.done
this.setLatest(664,36);
this.setPH(666);
_res= {r0:_t58,r1:4,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t58, 4:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:116:3

case 37: // cond.false
this.setLatest(666,37);
this.SubFn21();

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t1:Bool;
this.setPH(596);
_t0=({var _v=p_p;_v==null?0:_v.len();}); // _t0 = len(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:46:10
this.setPH(597);
_t1=(_t0<1); // _t1 = t0 < 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:47:7
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:47:7
}// end SubFn0
private inline function SubFn1():Void {
var _t2:Pointer;
var _t4:Bool;
this.setPH(600);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:50:9 [POINTER]
_t2=p_p.addr(0);  // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:50:9 [POINTER]
_t3=(_t2.load()|0); // _t3 = *t2 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:50:9
this.setPH(603);
_t4=(Force.uintCompare(_t3,128)<0); // _t4 = t3 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:53:8
_Next=_t4 ? 3 : 4; // if t4 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:53:8
}// end SubFn1
private inline function SubFn2():Void {
this.setPH(604);
_t5=_t3; // _t5 = convert rune <- byte (t3) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:54:14
}// end SubFn2
private inline function SubFn3():Void {
var _t6:Bool;
this.setPH(608);
_t6=(Force.uintCompare(_t3,192)<0); // _t6 = t3 < 192:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:58:8
_Next=_t6 ? 5 : 6; // if t6 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:58:8
}// end SubFn3
private inline function SubFn4():Void {
var _t7:Bool;
this.setPH(613);
_t7=(_t0<2); // _t7 = t0 < 2:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:63:7
_Next=_t7 ? 7 : 8; // if t7 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:63:7
}// end SubFn4
private inline function SubFn5():Void {
var _t8:Pointer;
var _t10:Bool;
this.setPH(616);
if((1<0)||(1>=p_p.len())) Scheduler.ioor(); // _t8 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:66:9 [POINTER]
_t8=p_p.addr(1);  // _t8 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:66:9 [POINTER]
_t9=(_t8.load()|0); // _t9 = *t8 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:66:9
this.setPH(617);
_t10=(Force.uintCompare(_t9,128)<0); // _t10 = t9 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:67:8
_Next=_t10 ? 9 : 11; // if t10 goto 9.if.then else 11.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:67:8
}// end SubFn5
private inline function SubFn6():Void {
var _t11:Bool;
this.setPH(622);
_t11=(Force.uintCompare(_t3,224)<0); // _t11 = t3 < 224:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:72:8
_Next=_t11 ? 12 : 13; // if t11 goto 12.if.then else 13.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:72:8
}// end SubFn6
private inline function SubFn7():Void {
var _t12:Bool;
this.setPH(617);
_t12=(Force.uintCompare(192,_t9)<=0); // _t12 = 192:byte <= t9 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:67:19
_Next=_t12 ? 9 : 10; // if t12 goto 9.if.then else 10.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:67:19
}// end SubFn7
private inline function SubFn8():Void {
var _t13:Int;
var _t14:Int;
var _t15:Int;
var _t16:Int;
var _t17:Int;
var _t19:Bool;
this.setPH(623);
_t13=Force.toUint8((_t3&31)); // _t13 = t3 & 31:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:14
_t14=_t13; // _t14 = convert rune <- byte (t13) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:11
_t15=(_t14<<GOint64.toInt(GOint64.make(0x0,0x6))); // _t15 = t14 << 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:21
_t16=Force.toUint8((_t9&63)); // _t16 = t9 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:34
_t17=_t16; // _t17 = convert rune <- byte (t16) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:31
_t18=Force.toInt32((_t15|_t17)); // _t18 = t15 | t17 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:25
this.setPH(624);
_t19=(_t18<=127); // _t19 = t18 <= 127:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:74:8
_Next=_t19 ? 14 : 15; // if t19 goto 14.if.then else 15.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:74:8
}// end SubFn8
private inline function SubFn9():Void {
var _t20:Bool;
this.setPH(631);
_t20=(_t0<3); // _t20 = t0 < 3:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:81:7
_Next=_t20 ? 16 : 17; // if t20 goto 16.if.then else 17.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:81:7
}// end SubFn9
private inline function SubFn10():Void {
var _t21:Pointer;
var _t23:Bool;
this.setPH(634);
if((2<0)||(2>=p_p.len())) Scheduler.ioor(); // _t21 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:84:9 [POINTER]
_t21=p_p.addr(2);  // _t21 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:84:9 [POINTER]
_t22=(_t21.load()|0); // _t22 = *t21 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:84:9
this.setPH(635);
_t23=(Force.uintCompare(_t22,128)<0); // _t23 = t22 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:85:8
_Next=_t23 ? 18 : 20; // if t23 goto 18.if.then else 20.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:85:8
}// end SubFn10
private inline function SubFn11():Void {
var _t24:Bool;
this.setPH(640);
_t24=(Force.uintCompare(_t3,240)<0); // _t24 = t3 < 240:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:90:8
_Next=_t24 ? 21 : 22; // if t24 goto 21.if.then else 22.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:90:8
}// end SubFn11
private inline function SubFn12():Void {
var _t25:Bool;
this.setPH(635);
_t25=(Force.uintCompare(192,_t22)<=0); // _t25 = 192:byte <= t22 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:85:19
_Next=_t25 ? 18 : 19; // if t25 goto 18.if.then else 19.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:85:19
}// end SubFn12
private inline function SubFn13():Void {
var _t26:Int;
var _t27:Int;
var _t28:Int;
var _t29:Int;
var _t30:Int;
var _t31:Int;
var _t32:Int;
var _t33:Int;
var _t34:Int;
var _t36:Bool;
this.setPH(641);
_t26=Force.toUint8((_t3&15)); // _t26 = t3 & 15:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:91:14
_t27=_t26; // _t27 = convert rune <- byte (t26) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:91:11
_t28=(_t27<<GOint64.toInt(GOint64.make(0x0,0xc))); // _t28 = t27 << 12:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:91:21
_t29=Force.toUint8((_t9&63)); // _t29 = t9 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:91:35
_t30=_t29; // _t30 = convert rune <- byte (t29) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:91:32
_t31=(_t30<<GOint64.toInt(GOint64.make(0x0,0x6))); // _t31 = t30 << 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:91:42
_t32=Force.toInt32((_t28|_t31)); // _t32 = t28 | t31 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:91:26
_t33=Force.toUint8((_t22&63)); // _t33 = t22 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:91:55
_t34=_t33; // _t34 = convert rune <- byte (t33) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:91:52
_t35=Force.toInt32((_t32|_t34)); // _t35 = t32 | t34 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:91:46
this.setPH(642);
_t36=(_t35<=2047); // _t36 = t35 <= 2047:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:92:8
_Next=_t36 ? 23 : 24; // if t36 goto 23.if.then else 24.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:92:8
}// end SubFn13
private inline function SubFn14():Void {
var _t37:Bool;
this.setPH(652);
_t37=(_t0<4); // _t37 = t0 < 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:102:7
_Next=_t37 ? 28 : 29; // if t37 goto 28.if.then else 29.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:102:7
}// end SubFn14
private inline function SubFn15():Void {
var _t38:Bool;
this.setPH(645);
_t38=(55296<=_t35); // _t38 = 55296:rune <= t35 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:95:19
_Next=_t38 ? 27 : 26; // if t38 goto 27.cond.true else 26.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:95:19
}// end SubFn15
private inline function SubFn16():Void {
var _t39:Bool;
_t39=(_t35<=57343); // _t39 = t35 <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:95:29
_Next=_t39 ? 25 : 26; // if t39 goto 25.if.then else 26.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:95:29
}// end SubFn16
private inline function SubFn17():Void {
var _t40:Pointer;
var _t42:Bool;
this.setPH(655);
if((3<0)||(3>=p_p.len())) Scheduler.ioor(); // _t40 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:105:9 [POINTER]
_t40=p_p.addr(3);  // _t40 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:105:9 [POINTER]
_t41=(_t40.load()|0); // _t41 = *t40 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:105:9
this.setPH(656);
_t42=(Force.uintCompare(_t41,128)<0); // _t42 = t41 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:106:8
_Next=_t42 ? 30 : 32; // if t42 goto 30.if.then else 32.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:106:8
}// end SubFn17
private inline function SubFn18():Void {
var _t43:Bool;
this.setPH(661);
_t43=(Force.uintCompare(_t3,248)<0); // _t43 = t3 < 248:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:111:8
_Next=_t43 ? 33 : 34; // if t43 goto 33.if.then else 34.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:111:8
}// end SubFn18
private inline function SubFn19():Void {
var _t44:Bool;
this.setPH(656);
_t44=(Force.uintCompare(192,_t41)<=0); // _t44 = 192:byte <= t41 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:106:19
_Next=_t44 ? 30 : 31; // if t44 goto 30.if.then else 31.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:106:19
}// end SubFn19
private inline function SubFn20():Void {
var _t45:Int;
var _t46:Int;
var _t47:Int;
var _t48:Int;
var _t49:Int;
var _t50:Int;
var _t51:Int;
var _t52:Int;
var _t53:Int;
var _t54:Int;
var _t55:Int;
var _t56:Int;
var _t57:Int;
var _t59:Bool;
this.setPH(662);
_t45=Force.toUint8((_t3&7)); // _t45 = t3 & 7:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:14
_t46=_t45; // _t46 = convert rune <- byte (t45) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:11
_t47=(_t46<<GOint64.toInt(GOint64.make(0x0,0x12))); // _t47 = t46 << 18:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:21
_t48=Force.toUint8((_t9&63)); // _t48 = t9 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:35
_t49=_t48; // _t49 = convert rune <- byte (t48) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:32
_t50=(_t49<<GOint64.toInt(GOint64.make(0x0,0xc))); // _t50 = t49 << 12:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:42
_t51=Force.toInt32((_t47|_t50)); // _t51 = t47 | t50 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:26
_t52=Force.toUint8((_t22&63)); // _t52 = t22 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:56
_t53=_t52; // _t53 = convert rune <- byte (t52) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:53
_t54=(_t53<<GOint64.toInt(GOint64.make(0x0,0x6))); // _t54 = t53 << 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:63
_t55=Force.toInt32((_t51|_t54)); // _t55 = t51 | t54 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:47
_t56=Force.toUint8((_t41&63)); // _t56 = t41 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:76
_t57=_t56; // _t57 = convert rune <- byte (t56) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:73
_t58=Force.toInt32((_t55|_t57)); // _t58 = t55 | t57 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:112:67
this.setPH(663);
_t59=(_t58<=65535); // _t59 = t58 <= 65535:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:8
_Next=_t59 ? 35 : 37; // if t59 goto 35.if.then else 37.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:8
}// end SubFn20
private inline function SubFn21():Void {
var _t60:Bool;
_t60=(1114111<_t58); // _t60 = 1114111:rune < t58 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:31
_Next=_t60 ? 35 : 36; // if t60 goto 35.if.then else 36.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:31
}// end SubFn21
}
#if (!php) private #end class Go_haxegoruntime_runtime_NumGoroutine extends StackFrameBasis implements StackFrame {  // goruntime.go:341:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,403,"Go_haxegoruntime_runtime_NumGoroutine");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:Dynamic=null;
var _t1:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_runtime_NumGoroutine(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : Int {
var _sf=new Go_haxegoruntime_runtime_NumGoroutine(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_haxegoruntime_runtime_NumGoroutine
{return new Go_haxegoruntime_runtime_NumGoroutine(gr,_bds);
}
public function run():Go_haxegoruntime_runtime_NumGoroutine {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(403,0);
_t0=Scheduler.NumGoroutine(); // _t0 = github.com/elliott5/gohaxelib/hxutil.HAXE("Scheduler.NumGoro...":string) *ssa.Call @ goruntime.go:341:57
this.SubFn0();
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ goruntime.go:341:35

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t1=cast(_t0,Int); // _t1 = convert int <- uintptr (t0) *ssa.Convert @ goruntime.go:341:45
}// end SubFn0
}
#if js @:expose("Go_main_MouseUp") #end class Go_main_MouseUp extends StackFrameBasis implements StackFrame {  // main.go:19:6
var p_x:Float;
var p_y:Float;
public function new(gr:Int,_bds:Array<Dynamic>, p_x : Float, p_y : Float) {
super(gr,19,"Go_main_MouseUp");
this._bds=_bds;
this.p_x=p_x;
this.p_y=p_y;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Channel<Array<Dynamic>>=null;
var _t1:Pointer=null;
var _t2:Pointer=null;
var _t3:Pointer=null;
var _t4:Pointer=null;
var _t5:Array<Dynamic>=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_x : Float, p_y : Float) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_main_MouseUp(0,[], p_x, p_y).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_x : Float, p_y : Float) : Void {
var _sf=new Go_main_MouseUp(_gr,[], p_x, p_y).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_x : Float, p_y : Float) : Go_main_MouseUp
{return new Go_main_MouseUp(gr,_bds, p_x, p_y);
}
public function run():Go_main_MouseUp {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(19,0);
this.SubFn0();
_Next=-1;
return this;
case -1:
this.setLatest(19,-1);
if(!_t0.hasSpace())return this;
_t0.send(_t5); // send t0 <- t5 *ssa.Send @ main.go:19:44
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near main.go:19:44

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t1:Pointer;
var _t2:Pointer;
var _t3:Pointer;
var _t4:Pointer;
_t0=Go.main_mouseEvents.load(); // _t0 = *mouseEvents *ssa.UnOp near main.go:19:44
_t1=new Pointer({var _v=new Array<Dynamic>();_v=[0,0.0,0.0]; _v;}); // _t1 = local mouseEvent (complit) *ssa.Alloc @ main.go:19:57
_t2=_t1.addr(0);  // _t2 = &t1.event [#0] *ssa.FieldAddr near main.go:19:57 [POINTER]
_t2.store(0); // *t2 = 0:int *ssa.Store near main.go:19:57
_t3=_t1.addr(1);  // _t3 = &t1.x [#1] *ssa.FieldAddr near main.go:19:57 [POINTER]
_t3.store(p_x); // *t3 = x *ssa.Store near main.go:19:57
_t4=_t1.addr(2);  // _t4 = &t1.y [#2] *ssa.FieldAddr near main.go:19:57 [POINTER]
_t4.store(p_y); // *t4 = y *ssa.Store near main.go:19:57
_t5=_t1.load(); // _t5 = *t1 *ssa.UnOp near main.go:19:57
}// end SubFn0
}
#if js @:expose("Go_utf8_RuneStart") #end class Go_utf8_RuneStart extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:392:6
var p_b:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_b : Int) {
super(gr,942,"Go_utf8_RuneStart");
this._bds=_bds;
this.p_b=p_b;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_b : Int) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_RuneStart(0,[], p_b).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_b : Int) : Bool {
var _sf=new Go_utf8_RuneStart(_gr,[], p_b).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_b : Int) : Go_utf8_RuneStart
{return new Go_utf8_RuneStart(gr,_bds, p_b);
}
public function run():Go_utf8_RuneStart {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(942,0);
this.SubFn0();
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:392:31

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Int;
_t0=Force.toUint8((p_b&192)); // _t0 = b & 192:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:392:39
_t1=(Force.uintCompare(_t0,128)!=0); // _t1 = t0 != 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:392:45
}// end SubFn0
}
#if js @:expose("Go_hxutil_Gosched") #end class Go_hxutil_Gosched extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:37:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1030,"Go_hxutil_Gosched");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_hxutil_Gosched(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_hxutil_Gosched(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_hxutil_Gosched
{return new Go_hxutil_Gosched(gr,_bds);
}
public function run():Go_hxutil_Gosched {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1030,0);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/unicode/utf8/utf8.go:392:45

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_haxegoruntime_M4") #end class Go_haxegoruntime_M4 extends StackFrameBasis implements StackFrame {  // goruntime.go:157:6
var p_rx:Interface;
var p_typ:String;
var p_meth:String;
var p_a1:Interface;
var p_a2:Interface;
var p_a3:Interface;
var p_a4:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface) {
super(gr,219,"Go_haxegoruntime_M4");
this._bds=_bds;
this.p_rx=p_rx;
this.p_typ=p_typ;
this.p_meth=p_meth;
this.p_a1=p_a1;
this.p_a2=p_a2;
this.p_a3=p_a3;
this.p_a4=p_a4;
Scheduler.push(gr,this);
}
var _res:Interface;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface) : Interface {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_M4(0,[], p_rx, p_typ, p_meth, p_a1, p_a2, p_a3, p_a4).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface) : Interface {
var _sf=new Go_haxegoruntime_M4(_gr,[], p_rx, p_typ, p_meth, p_a1, p_a2, p_a3, p_a4).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_rx : Interface, p_typ : String, p_meth : String, p_a1 : Interface, p_a2 : Interface, p_a3 : Interface, p_a4 : Interface) : Go_haxegoruntime_M4
{return new Go_haxegoruntime_M4(gr,_bds, p_rx, p_typ, p_meth, p_a1, p_a2, p_a3, p_a4);
}
public function run():Go_haxegoruntime_M4 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(219,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ goruntime.go:157:93

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,p_meth); // _t0 = make interface{} <- string (meth) *ssa.MakeInterface near goruntime.go:157:93
}// end SubFn0
}
#if js @:expose("Go_utf16_EncodeRune") #end class Go_utf16_EncodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:47:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,489,"Go_utf16_EncodeRune");
this._bds=_bds;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:{r0:Int, r1:Int};
public inline function res():Dynamic {return _res;}
var _t0:Bool=false;
var _t1:Int=0;
var _t2:Int=0;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Int=0;
var _t6:Int=0;
var _SF1:StackFrame;
var _t7:Bool=false;
var _t8:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_r : Int) : {r0:Int, r1:Int} {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf16_EncodeRune(0,[], p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r : Int) : {r0:Int, r1:Int} {
var _sf=new Go_utf16_EncodeRune(_gr,[], p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r : Int) : Go_utf16_EncodeRune
{return new Go_utf16_EncodeRune(gr,_bds, p_r);
}
public function run():Go_utf16_EncodeRune {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(489,0);
this.SubFn0();

case 1: // if.then
this.setLatest(489,1);
this.setPH(491);
_res= {r0:65533,r1:65533};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 65533:rune *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:49:3

case 2: // if.done
this.setLatest(491,2);
this.SubFn1();
this.setPH(494);
_res= {r0:_t4,r1:_t6};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4, t6 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:2

case 3: // cond.false
this.setLatest(494,3);
this.setPH(490);
_SF1=Go_utf16_IsSurrogate.call(this._goroutine,[],p_r);
_Next = -1;
return this;
case -1:
this.setLatest(490,-1);
_t7=_SF1.res();
 // _t7 = IsSurrogate(r) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:47
this.SubFn2();

case 4: // cond.false
this.setLatest(490,4);
this.SubFn3();

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Bool;
_t0=(p_r<65536); // _t0 = r < 65536:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:7
_Next=_t0 ? 1 : 4; // if t0 goto 1.if.then else 4.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:7
}// end SubFn0
private inline function SubFn1():Void {
var _t2:Int;
var _t3:Int;
var _t5:Int;
_t1=Force.toInt32((p_r-65536)); // _t1 = r - 65536:rune *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:7
this.setPH(494);
_t2=(_t1>>GOint64.toInt(GOint64.make(0x0,0xa))); // _t2 = t1 >> 10:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:19
_t3=Force.toInt32((_t2&1023)); // _t3 = t2 & 1023:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:24
_t4=Force.toInt32((55296+_t3)); // _t4 = 55296:rune + t3 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:15
_t5=Force.toInt32((_t1&1023)); // _t5 = t1 & 1023:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:41
_t6=Force.toInt32((56320+_t5)); // _t6 = 56320:rune + t5 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:38
}// end SubFn1
private inline function SubFn2():Void {
_Next=_t7 ? 1 : 2; // if t7 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:38
}// end SubFn2
private inline function SubFn3():Void {
var _t8:Bool;
this.setPH(490);
_t8=(p_r>1114111); // _t8 = r > 1114111:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:23
_Next=_t8 ? 1 : 3; // if t8 goto 1.if.then else 3.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:23
}// end SubFn3
}
#if js @:expose("Go_utf8_RuneLen") #end class Go_utf8_RuneLen extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:310:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,860,"Go_utf8_RuneLen");
this._bds=_bds;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Bool=false;
var _t1:Bool=false;
var _t2:Bool=false;
var _t3:Bool=false;
var _t4:Bool=false;
var _t5:Bool=false;
var _t6:Bool=false;
var _t7:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_r : Int) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_utf8_RuneLen(0,[], p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r : Int) : Int {
var _sf=new Go_utf8_RuneLen(_gr,[], p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r : Int) : Go_utf8_RuneLen
{return new Go_utf8_RuneLen(gr,_bds, p_r);
}
public function run():Go_utf8_RuneLen {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(860,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(860,1);
this.setPH(863);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:313:3

case 2: // switch.body
this.setLatest(863,2);
this.setPH(865);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:315:3

case 3: // switch.next
this.setLatest(865,3);
this.SubFn1();
_Phi=3;
case 4: // switch.body
this.setLatest(865,4);
this.setPH(867);
_res= 2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 2:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:317:3

case 5: // switch.next
this.setLatest(867,5);
this.SubFn2();
_Phi=5;
case 6: // switch.body
this.setLatest(867,6);
this.setPH(869);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:319:3

case 7: // switch.next
this.setLatest(869,7);
this.SubFn3();
_Phi=7;
case 8: // switch.body
this.setLatest(869,8);
this.setPH(871);
_res= 3;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 3:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:321:3

case 9: // switch.next
this.setLatest(871,9);
this.SubFn4();
_Phi=9;
case 10: // binop.rhs
this.setLatest(871,10);
this.SubFn5();
_Phi=10;
case 11: // binop.done
this.setLatest(871,11);
this.setPH(868);
_t6=((_Phi==7)?false:(_Phi==10)?_t5:false); // _t6 = phi [7.switch.next: false:bool, 10.binop.rhs: t5] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:25
this.SubFn6();
_Phi=11;
case 12: // switch.body
this.setLatest(868,12);
this.setPH(873);
_res= 4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 4:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:323:3

case 13: // switch.next
this.setLatest(873,13);
this.SubFn7();
_Phi=13;
case 14: // switch.next
this.setLatest(873,14);
this.setPH(875);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:325:2

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t0:Bool;
this.setPH(862);
_t0=(p_r<0); // _t0 = r < 0:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:312:9
_Next=_t0 ? 1 : 3; // if t0 goto 1.switch.body else 3.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:312:9
}// end SubFn0
private inline function SubFn1():Void {
var _t1:Bool;
this.setPH(864);
_t1=(p_r<=127); // _t1 = r <= 127:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:314:9
_Next=_t1 ? 2 : 5; // if t1 goto 2.switch.body else 5.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:314:9
}// end SubFn1
private inline function SubFn2():Void {
var _t2:Bool;
this.setPH(866);
_t2=(p_r<=2047); // _t2 = r <= 2047:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:316:9
_Next=_t2 ? 4 : 7; // if t2 goto 4.switch.body else 7.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:316:9
}// end SubFn2
private inline function SubFn3():Void {
var _t3:Bool;
this.setPH(868);
_t3=(55296<=p_r); // _t3 = 55296:rune <= r *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:20
_Next=_t3 ? 10 : 11; // if t3 goto 10.binop.rhs else 11.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:20
}// end SubFn3
private inline function SubFn4():Void {
var _t4:Bool;
this.setPH(870);
_t4=(p_r<=65535); // _t4 = r <= 65535:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:320:9
_Next=_t4 ? 8 : 13; // if t4 goto 8.switch.body else 13.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:320:9
}// end SubFn4
private inline function SubFn5():Void {
this.setPH(868);
_t5=(p_r<=57343); // _t5 = r <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:30
_Next=11; // jump 11.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:30
}// end SubFn5
private inline function SubFn6():Void {
_Next=_t6 ? 6 : 9; // if t6 goto 6.switch.body else 9.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:30
}// end SubFn6
private inline function SubFn7():Void {
var _t7:Bool;
this.setPH(872);
_t7=(p_r<=1114111); // _t7 = r <= 1114111:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:322:9
_Next=_t7 ? 12 : 14; // if t7 goto 12.switch.body else 14.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:322:9
}// end SubFn7
}
#if js @:expose("Go_haxegoruntime_Raw2Runes") #end class Go_haxegoruntime_Raw2Runes extends StackFrameBasis implements StackFrame {  // goruntime.go:40:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,102,"Go_haxegoruntime_Raw2Runes");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Bool=false;
var _t2:Int=0;
var _t3:Slice=null;
var _t4:Int=0;
var _t5:Int=0;
var _t6:Slice=null;
var _t7:Int=0;
var _t8:Bool=false;
var _t9:Int=0;
var _t10:Int=0;
var _t11:Bool=false;
var _t12:Pointer=null;
var _t13:Pointer=null;
var _t14:Int=0;
var _t15:Int=0;
var _SF1:StackFrame;
var _t16:Slice=null;
var _SF2:StackFrame;
var _t18:Pointer=null;
var _t19:Slice=null;
var _t20:Int=0;
var _t21:Int=0;
var _t22:Bool=false;
var _t23:Pointer=null;
var _t24:Pointer=null;
var _t25:Int=0;
var _t26:Int=0;
var _SF3:StackFrame;
var _t27:Slice=null;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : Slice) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_Raw2Runes(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : Slice) : Slice {
var _sf=new Go_haxegoruntime_Raw2Runes(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : Slice) : Go_haxegoruntime_Raw2Runes
{return new Go_haxegoruntime_Raw2Runes(gr,_bds, p_s);
}
public function run():Go_haxegoruntime_Raw2Runes {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(102,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(102,1);
this.SubFn1();
_Phi=1;
case 2: // switch.body
this.setLatest(102,2);
this.SubFn2();
_Phi=2;
case 3: // switch.next
this.setLatest(102,3);
this.SubFn3();
_Phi=3;
case 4: // rangeindex.loop
this.setLatest(102,4);
_t9=((_Phi==1)?(-1):(_Phi==5)?_t10:0); // _t9 = phi [1.switch.body: -1:int, 5.rangeindex.body: t10] *ssa.Phi near /usr/local/go/src/pkg/unicode/utf8/utf8.go:322:9
this.SubFn4();
_Phi=4;
case 5: // rangeindex.body
this.setLatest(102,5);
this.SubFn5();
_Phi=5;
case 6: // rangeindex.done
this.setLatest(102,6);
this.setPH(109);
_SF1=Go_haxegoruntime_UTF16toRunes.call(this._goroutine,[],_t3);
_Next = -1;
return this;
case -1:
this.setLatest(109,-1);
_t16=_SF1.res();
 // _t16 = UTF16toRunes(t3) *ssa.Call @ goruntime.go:47:22
_res= _t16;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t16 *ssa.Return @ goruntime.go:47:3

case 7: // switch.next
this.setLatest(109,7);
this.setPH(118);
throw 'goruntime.Runes2String() unrecognised encoding'; // _t17 = github.com/elliott5/gohaxelib/hxutil.HAXE("throw 'goruntime....":string) *ssa.Call @ goruntime.go:56:14 [REGISTER VALUE UN-USED]
this.SubFn6();
this.setPH(120);
_res= _t19;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t19 *ssa.Return @ goruntime.go:58:2

case 8: // rangeindex.loop
this.setLatest(120,8);
_t20=((_Phi==2)?(-1):(_Phi==9)?_t21:0); // _t20 = phi [2.switch.body: -1:int, 9.rangeindex.body: t21] *ssa.Phi near goruntime.go:58:2
this.SubFn7();
_Phi=8;
case 9: // rangeindex.body
this.setLatest(120,9);
this.SubFn8();
_Phi=9;
case 10: // rangeindex.done
this.setLatest(120,10);
this.setPH(115);
_SF3=Go_haxegoruntime_UTF8toRunes.call(this._goroutine,[],_t6);
_Next = -3;
return this;
case -3:
this.setLatest(115,-3);
_t27=_SF3.res();
 // _t27 = UTF8toRunes(t6) *ssa.Call @ goruntime.go:53:21
_res= _t27;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t27 *ssa.Return @ goruntime.go:53:3

default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
var _t1:Bool;
_t0=(Go.haxegoruntime_ZiLen.load()|0); // _t0 = *ZiLen *ssa.UnOp near goruntime.go:53:3
_t1=(Force.uintCompare(_t0,1)==0); // _t1 = t0 == 1:uint *ssa.BinOp near goruntime.go:53:3
_Next=_t1 ? 1 : 3; // if t1 goto 1.switch.body else 3.switch.next *ssa.If near goruntime.go:53:3
}// end SubFn0
private inline function SubFn1():Void {
var _t2:Int;
this.setPH(105);
_t2=({var _v=p_s;_v==null?0:_v.len();}); // _t2 = len(s) *ssa.Call @ goruntime.go:43:40
_t3=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t2) _v[_i]=0; _v;}),0,_t2); // _t3 = make []uint16 t2 t2 *ssa.MakeSlice @ goruntime.go:43:26
_t4=({var _v=p_s;_v==null?0:_v.len();}); // _t4 = len(s) *ssa.Call near goruntime.go:43:26
_Next=4; // jump 4.rangeindex.loop *ssa.Jump near goruntime.go:43:26
}// end SubFn1
private inline function SubFn2():Void {
var _t5:Int;
this.setPH(111);
_t5=({var _v=p_s;_v==null?0:_v.len();}); // _t5 = len(s) *ssa.Call @ goruntime.go:49:36
_t6=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t5) _v[_i]=0; _v;}),0,_t5); // _t6 = make []byte t5 t5 *ssa.MakeSlice @ goruntime.go:49:24
_t7=({var _v=p_s;_v==null?0:_v.len();}); // _t7 = len(s) *ssa.Call near goruntime.go:49:24
_Next=8; // jump 8.rangeindex.loop *ssa.Jump near goruntime.go:49:24
}// end SubFn2
private inline function SubFn3():Void {
var _t8:Bool;
_t8=(Force.uintCompare(_t0,3)==0); // _t8 = t0 == 3:uint *ssa.BinOp near goruntime.go:49:24
_Next=_t8 ? 2 : 7; // if t8 goto 2.switch.body else 7.switch.next *ssa.If near goruntime.go:49:24
}// end SubFn3
private inline function SubFn4():Void {
var _t11:Bool;
_t10=(_t9+1); // _t10 = t9 + 1:int *ssa.BinOp near goruntime.go:49:24
_t11=(_t10<_t4); // _t11 = t10 < t4 *ssa.BinOp near goruntime.go:49:24
_Next=_t11 ? 5 : 6; // if t11 goto 5.rangeindex.body else 6.rangeindex.done *ssa.If near goruntime.go:49:24
}// end SubFn4
private inline function SubFn5():Void {
var _t12:Pointer;
var _t13:Pointer;
var _t14:Int;
var _t15:Int;
this.setPH(107);
if((_t10<0)||(_t10>=_t3.len())) Scheduler.ioor(); // _t12 = &t3[t10] *ssa.IndexAddr @ goruntime.go:45:7 [POINTER]
_t12=_t3.addr(_t10);  // _t12 = &t3[t10] *ssa.IndexAddr @ goruntime.go:45:7 [POINTER]
if((_t10<0)||(_t10>=p_s.len())) Scheduler.ioor(); // _t13 = &s[t10] *ssa.IndexAddr @ goruntime.go:45:21 [POINTER]
_t13=p_s.addr(_t10);  // _t13 = &s[t10] *ssa.IndexAddr @ goruntime.go:45:21 [POINTER]
_t14=(_t13.load()|0); // _t14 = *t13 *ssa.UnOp near goruntime.go:45:21
_t15=_t14; // _t15 = convert uint16 <- int (t14) *ssa.Convert @ goruntime.go:45:19
_t12.store(_t15); // *t12 = t15 *ssa.Store near goruntime.go:45:19
_Next=4; // jump 4.rangeindex.loop *ssa.Jump near goruntime.go:45:19
}// end SubFn5
private inline function SubFn6():Void {
var _t18:Pointer;
this.setPH(120);
_t18=new Pointer({var _v=new Array<Int>();for(_vi in 0...0){_v[_vi]=0;}; _v;}); // _t18 = new [0]rune (slicelit) *ssa.Alloc @ goruntime.go:58:15
_t19=new Slice(_t18,0,-1); // _t19 = slice t18[:] *ssa.Slice @ goruntime.go:58:15
}// end SubFn6
private inline function SubFn7():Void {
var _t22:Bool;
_t21=(_t20+1); // _t21 = t20 + 1:int *ssa.BinOp near goruntime.go:58:15
_t22=(_t21<_t7); // _t22 = t21 < t7 *ssa.BinOp near goruntime.go:58:15
_Next=_t22 ? 9 : 10; // if t22 goto 9.rangeindex.body else 10.rangeindex.done *ssa.If near goruntime.go:58:15
}// end SubFn7
private inline function SubFn8():Void {
var _t23:Pointer;
var _t24:Pointer;
var _t25:Int;
var _t26:Int;
this.setPH(113);
if((_t21<0)||(_t21>=_t6.len())) Scheduler.ioor(); // _t23 = &t6[t21] *ssa.IndexAddr @ goruntime.go:51:7 [POINTER]
_t23=_t6.addr(_t21);  // _t23 = &t6[t21] *ssa.IndexAddr @ goruntime.go:51:7 [POINTER]
if((_t21<0)||(_t21>=p_s.len())) Scheduler.ioor(); // _t24 = &s[t21] *ssa.IndexAddr @ goruntime.go:51:19 [POINTER]
_t24=p_s.addr(_t21);  // _t24 = &s[t21] *ssa.IndexAddr @ goruntime.go:51:19 [POINTER]
_t25=(_t24.load()|0); // _t25 = *t24 *ssa.UnOp near goruntime.go:51:19
_t26=_t25; // _t26 = convert byte <- int (t25) *ssa.Convert @ goruntime.go:51:17
_t23.store(_t26); // *t23 = t26 *ssa.Store near goruntime.go:51:17
_Next=8; // jump 8.rangeindex.loop *ssa.Jump near goruntime.go:51:17
}// end SubFn8
}
#if (!php) private #end class Go_haxegoruntime_cstringToGo extends StackFrameBasis implements StackFrame {  // goruntime.go:368:6
var p_arg0:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_arg0 : Dynamic) {
super(gr,430,"Go_haxegoruntime_cstringToGo");
this._bds=_bds;
this.p_arg0=p_arg0;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_arg0 : Dynamic) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_haxegoruntime_cstringToGo(0,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_arg0 : Dynamic) : String {
var _sf=new Go_haxegoruntime_cstringToGo(_gr,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_arg0 : Dynamic) : Go_haxegoruntime_cstringToGo
{return new Go_haxegoruntime_cstringToGo(gr,_bds, p_arg0);
}
public function run():Go_haxegoruntime_cstringToGo {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(430,0);
this.SubFn0();
this.setPH(431);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(431,-1);
 // panic t0 *ssa.Panic @ goruntime.go:369:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline function SubFn0():Void {
_t0=new Interface(0,"runtime.cstringToGo() not yet implemented"); // _t0 = make interface{} <- string ("runtime.cstringTo...":string) *ssa.MakeInterface near goruntime.go:369:7
}// end SubFn0
}
#if js @:expose("Go_hxutil_CPos") #end class Go_hxutil_CPos extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:20:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1013,"Go_hxutil_CPos");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_hxutil_CPos(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_hxutil_CPos(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_hxutil_CPos
{return new Go_hxutil_CPos(gr,_bds);
}
public function run():Go_hxutil_CPos {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1013,0);
_res= "<<go code pos>>";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "<<go code pos>>":string *ssa.Return @ /Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:20:22

default: Scheduler.bbi();}}}
}

#if js
@:expose("Go")
#end
class Go
{

	public static function Platform():String { // codes returned the same as used by Haxe 
    #if flash
    	return "flash";
    #elseif js
    	return "js";
    #elseif cpp
    	return "cpp";
    #elseif java
    	return "java";
    #elseif cs
    	return "cs";
    #elseif php
    	return "php";
    #elseif neko
    	return "neko";
    #else 
        #error "Only the js, flash, cpp (C++), java, cs (C#), php and neko Haxe targets are supported as a Go platform" 
    #end
	}

public static var main_MOUSE_UP:Int = 0;
public static var main_MOUSE_MOVE:Int = 2;
public static var main_MOUSE_DOWN:Int = 1;
public static var utf8_RuneError:Int = 65533;
public static var utf8_MaxRune:Int = 1114111;
public static var utf8_UTFMax:Int = 4;
public static var utf8_RuneSelf:Int = 128;
public static var haxegoruntime_init_36_guard:Pointer=new Pointer(false); 
public static var haxegoruntime_ZiLen:Pointer=new Pointer(0);  // goruntime.go:15:5
public static var main_cacheOffsetX:Pointer=new Pointer(0.0);  // main.go:27:23
public static var main_init_36_guard:Pointer=new Pointer(false); 
public static var main_SpriteY:Pointer=new Pointer(0.0);  // main.go:27:14
public static var main_Status:Pointer=new Pointer("");  // main.go:28:5
public static var main_SpriteX:Pointer=new Pointer(0.0);  // main.go:27:5
public static var main_mouseEvents:Pointer=new Pointer(null);  // main.go:17:5
public static var main_cacheOffsetY:Pointer=new Pointer(0.0);  // main.go:27:37
public static var utf16_init_36_guard:Pointer=new Pointer(false); 
public static var utf8_init_36_guard:Pointer=new Pointer(false); 
public static var hxutil_init_36_guard:Pointer=new Pointer(false); 
public static var doneInit:Bool=false;

public static function init() : Void {
doneInit=true;
var gr:Int=Scheduler.makeGoroutine();
if(gr!=0) throw "non-zero goroutine number in init";
var _sfgr=new Go_haxegoruntime_init(gr,[]).run();
while(_sfgr._incomplete) Scheduler.runAll();
var _sf=new Go_main_init(gr,[]).run();
while(_sf._incomplete) Scheduler.runAll();
Scheduler.doneInit=true;
}

public static function main() : Void {
Go_main_main.callFromHaxe();
}
public static function CPos(pos:Int):String {
var prefix:String="";
if (pos==0) return "(pogo.NoPosHash)";
if (pos<0) { pos = -pos; prefix= "near ";}
if(pos>993) return prefix+"/Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:"+Std.string(pos-993);
else if(pos>550) return prefix+"/usr/local/go/src/pkg/unicode/utf8/utf8.go:"+Std.string(pos-550);
else if(pos>442) return prefix+"/usr/local/go/src/pkg/unicode/utf16/utf16.go:"+Std.string(pos-442);
else if(pos>62) return prefix+"goruntime.go:"+Std.string(pos-62);
else if(pos>0) return prefix+"main.go:"+Std.string(pos-0);
else return "(invalid pogo.PosHash:"+Std.string(pos)+")";}
} // end Go class
class TypeInfo{
public static function getName(id:Int):String {
switch(id){
case 0: return "string";
default: return "UNKNOWN";}}
public static function typeString(i:Interface):String {
return getName(i.typ);
}
public static function getId(name:String):Int {
switch(name){
case "string": return 0;
default: return -1;}}
public static function isAssignableTo(v:Int,t:Int):Bool {
if(v==t) return true;
switch(v){
case 0: switch(t){
default: return false;}
default: return false;}}
public static function isIdentical(v:Int,t:Int):Bool {
if(v==t) return true;
switch(v){
case 0: switch(t){
default: return false;}
default: return false;}}
public static function isConcrete(t:Int):Bool {
switch(t){
case 0: return true;
default: return false;}}
public static function zeroValue(t:Int):Dynamic {
switch(t){
case 0: return "";
default: return null;}}
public static function method(t:Int,m:String):Dynamic {
switch(t){
default:}
 Scheduler.panicFromHaxe( "no method found!"); return null;}
}

 // Warning: *ssa.Call @ goruntime.go:94:14 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ goruntime.go:69:18 (pogo) The result from a function call is not used
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: temp var declaration (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: temp var declaration (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: *ssa.Next near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: *ssa.Next near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: *ssa.Call @ goruntime.go:56:14 (pogo) The result from a function call is not used
 // Package List:
 //  package goruntime
 //  package main
 //  package unicode/utf16
 //  package unicode/utf8
 //  package github.com/elliott5/gohaxelib/hxutil
