package tardis;
// This code generated using the TARDIS Go tool, elements are
// Copyright 2014 Elliott Stoneham and The TARDIS Go Authors
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file at https://github.com/tardisgo/tardisgo


class Deep { 
	//**** This class adapted from https://gist.github.com/Asmageddon/4013485 @author Asmageddon
	//** 
	//** Deep copy of anything using reflection (so don't hope for much performance)
	//** 
	// TODO this should not be a separate haxe class, as no non-pogo code needs access to it
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
		else if(Std.is( v, Array )) { // array 
			var result = Type.createInstance(Type.getClass(v), []); 
			untyped { 
				for( ii in 0...v.length ) {
					result.push(copy(v[ii]));
				}
			} 
			return result;
		}
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

class Force { // TODO maybe this should not be a separate haxe class, as no non-Go code needs access to it

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



#if js @:expose("Go_haxegoruntime_RunesToUTF8") #end class Go_haxegoruntime_RunesToUTF8 extends StackFrameBasis implements StackFrame {  // langgoruntime.go:79:6
var p_r:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Slice) {
super(gr,562,"Go_haxegoruntime_RunesToUTF8");
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
this.setLatest(562,0);
this.SubFn0();
_Phi=0;
case 1: // rangeindex.loop
this.setLatest(562,1);
this.setPH(563);
_t2=((_Phi==0)?_t0:(_Phi==2)?_t13:new Slice(new Pointer(new Array<Int>()),0,0)); // _t2 = phi [0.entry: t0, 2.rangeindex.body: t13] #ret *ssa.Phi @ langgoruntime.go:80:6
_t3=((_Phi==0)?(-1):(_Phi==2)?_t4:0); // _t3 = phi [0.entry: -1:int, 2.rangeindex.body: t4] *ssa.Phi near langgoruntime.go:80:6
this.SubFn1();
_Phi=1;
case 2: // rangeindex.body
this.setLatest(563,2);
this.SubFn2();
this.setPH(566);
_SF1=Go_utf8_RuneLen.call(this._goroutine,[],_t7);
_Next = -1;
return this;
case -1:
this.setLatest(566,-1);
_t8=_SF1.res();
 // _t8 = unicode/utf8.RuneLen(t7) *ssa.Call @ langgoruntime.go:83:35
this.SubFn3();
this.setPH(567);
Go_utf8_EncodeRune.call(this._goroutine,[],_t9,_t11);
_Next = -2;
return this;
case -2:
this.setLatest(567,-2);
 // _t12 = unicode/utf8.EncodeRune(t9, t11) *ssa.Call @ langgoruntime.go:84:18 [REGISTER VALUE UN-USED]
this.SubFn4();
_Phi=2;
case 3: // rangeindex.done
this.setLatest(567,3);
this.setPH(570);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ langgoruntime.go:87:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(564);
_t0=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0...0) _v[_i]=0; _v;}),0,0); // _t0 = make []byte 0:int 0:int *ssa.MakeSlice @ langgoruntime.go:81:12
_t1=({var _v=p_r;_v==null?0:_v.len();}); // _t1 = len(r) *ssa.Call near langgoruntime.go:81:12
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near langgoruntime.go:81:12
}// end SubFn0
private inline  function SubFn1():Void {
var _t5:Bool;
_t4=(_t3+1); // _t4 = t3 + 1:int *ssa.BinOp near langgoruntime.go:81:12
_t5=(_t4<_t1); // _t5 = t4 < t1 *ssa.BinOp near langgoruntime.go:81:12
_Next=_t5 ? 2 : 3; // if t5 goto 2.rangeindex.body else 3.rangeindex.done *ssa.If near langgoruntime.go:81:12
}// end SubFn1
private inline  function SubFn2():Void {
var _t6:Pointer;
this.setPH(566);
if((_t4<0)||(_t4>=p_r.len())) Scheduler.ioor(); // _t6 = &r[t4] *ssa.IndexAddr @ langgoruntime.go:83:37 [POINTER]
_t6=p_r.addr(_t4);  // _t6 = &r[t4] *ssa.IndexAddr @ langgoruntime.go:83:37 [POINTER]
_t7=(_t6.load()|0); // _t7 = *t6 *ssa.UnOp near langgoruntime.go:83:37
}// end SubFn2
private inline  function SubFn3():Void {
var _t10:Pointer;
_t9=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t8) _v[_i]=0; _v;}),0,_t8); // _t9 = make []byte t8 t8 *ssa.MakeSlice @ langgoruntime.go:83:14
this.setPH(567);
if((_t4<0)||(_t4>=p_r.len())) Scheduler.ioor(); // _t10 = &r[t4] *ssa.IndexAddr @ langgoruntime.go:84:25 [POINTER]
_t10=p_r.addr(_t4);  // _t10 = &r[t4] *ssa.IndexAddr @ langgoruntime.go:84:25 [POINTER]
_t11=(_t10.load()|0); // _t11 = *t10 *ssa.UnOp near langgoruntime.go:84:25
}// end SubFn3
private inline  function SubFn4():Void {
this.setPH(568);
_t13={var _v:Slice;if(_t2==null) _v=_t9;else if(_t2.len()==0) _v=_t9;else if(_t9==null) _v=_t2;else if(_t9.len()==0) _v=_t2;else {var l0:Int=_t2.len();_v=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t2.len()+_t9.len()) _v[_i]=0; _v;}),0,_t2.len()+_t9.len());for(_i in 0...l0) _v.setAt(_i,Deep.copy(_t2.getAt(_i)));for(_i in 0..._t9.len()) _v.setAt(_i+l0,Deep.copy(_t9.getAt(_i)));};_v;}; // _t13 = append(t2, t9...) *ssa.Call @ langgoruntime.go:85:15
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near langgoruntime.go:85:15
}// end SubFn4
}
#if js @:expose("Go_atomic_AddUintptr") #end class Go_atomic_AddUintptr extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:130:6
var p_addr:Pointer;
var p_delta:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : Dynamic) {
super(gr,251,"Go_atomic_AddUintptr");
this._bds=_bds;
this.p_addr=p_addr;
this.p_delta=p_delta;
Scheduler.push(gr,this);
}
var _res:Dynamic;
public inline function res():Dynamic {return _res;}
var _t0:Dynamic=null;
var _t1:Dynamic=null;
var _t2:Dynamic=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_delta : Dynamic) : Dynamic {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_AddUintptr(0,[], p_addr, p_delta).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_delta : Dynamic) : Dynamic {
var _sf=new Go_atomic_AddUintptr(_gr,[], p_addr, p_delta).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : Dynamic) : Go_atomic_AddUintptr
{return new Go_atomic_AddUintptr(gr,_bds, p_addr, p_delta);
}
public function run():Go_atomic_AddUintptr {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(251,0);
this.SubFn0();
this.setPH(253);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:132:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Dynamic;
var _t1:Dynamic;
this.setPH(252);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:131:2
_t1=((_t0|0)+(p_delta|0)); // _t1 = t0 + delta *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:131:2
p_addr.store(_t1); // *addr = t1 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:131:2
this.setPH(253);
_t2=p_addr.load(); // _t2 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:132:9
}// end SubFn0
}
#if js @:expose("Go_tardisgolib_StringsUTF16") #end class Go_tardisgolib_StringsUTF16 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:32:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,473,"Go_tardisgolib_StringsUTF16");
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
var _sf=new Go_tardisgolib_StringsUTF16(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : Bool {
var _sf=new Go_tardisgolib_StringsUTF16(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_tardisgolib_StringsUTF16
{return new Go_tardisgolib_StringsUTF16(gr,_bds);
}
public function run():Go_tardisgolib_StringsUTF16 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(473,0);
_t0='字'.length; // _t0 = Zilen() *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:32:40
this.SubFn0();
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:32:28

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=(Force.uintCompare(_t0,1)==0); // _t1 = t0 == 1:uint *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:32:43
}// end SubFn0
}
#if js @:expose("Go_utf8_FullRuneInString") #end class Go_utf8_FullRuneInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:209:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,941,"Go_utf8_FullRuneInString");
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
this.setLatest(941,0);
this.setPH(942);
_SF1=Go_utf8_decodeRuneInStringInternal.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(942,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInStringInternal(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:210:43
this.SubFn0();
this.setPH(943);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
 // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:2 [REGISTER VALUE UN-USED]
 // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:2 [REGISTER VALUE UN-USED]
_t3=_t0.r2; // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:2
_t4=(!_t3); // _t4 = !t3 *ssa.UnOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:211:9
}// end SubFn0
}
#if js @:expose("Go_utf8_ValidRune") #end class Go_utf8_ValidRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:433:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,1165,"Go_utf8_ValidRune");
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
this.setLatest(1165,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(1165,1);
this.setPH(1168);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:436:3

case 2: // switch.body
this.setLatest(1168,2);
this.setPH(1170);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:438:3

case 3: // switch.next
this.setLatest(1170,3);
this.SubFn1();
_Phi=3;
case 4: // switch.body
this.setLatest(1170,4);
this.setPH(1172);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:440:3

case 5: // switch.next
this.setLatest(1172,5);
this.SubFn2();
_Phi=5;
case 6: // binop.rhs
this.setLatest(1172,6);
this.SubFn3();
_Phi=6;
case 7: // binop.done
this.setLatest(1172,7);
this.setPH(1169);
_t4=((_Phi==3)?false:(_Phi==6)?_t3:false); // _t4 = phi [3.switch.next: false:bool, 6.binop.rhs: t3] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:25
this.SubFn4();
_Phi=7;
case 8: // switch.next
this.setLatest(1169,8);
this.setPH(1174);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:442:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(1167);
_t0=(p_r<0); // _t0 = r < 0:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:435:9
_Next=_t0 ? 1 : 3; // if t0 goto 1.switch.body else 3.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:435:9
}// end SubFn0
private inline  function SubFn1():Void {
var _t1:Bool;
this.setPH(1169);
_t1=(55296<=p_r); // _t1 = 55296:rune <= r *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:20
_Next=_t1 ? 6 : 7; // if t1 goto 6.binop.rhs else 7.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:20
}// end SubFn1
private inline  function SubFn2():Void {
var _t2:Bool;
this.setPH(1171);
_t2=(p_r>1114111); // _t2 = r > 1114111:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:439:9
_Next=_t2 ? 4 : 8; // if t2 goto 4.switch.body else 8.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:439:9
}// end SubFn2
private inline  function SubFn3():Void {
this.setPH(1169);
_t3=(p_r<=57343); // _t3 = r <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
_Next=7; // jump 7.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
}// end SubFn3
private inline  function SubFn4():Void {
_Next=_t4 ? 2 : 5; // if t4 goto 2.switch.body else 5.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
}// end SubFn4
}
#if (!php) private #end class Go_utf8_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1169,"Go_utf8_init");
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
this.setLatest(1169,0);
this.SubFn0();

case 1: // init.start
this.setLatest(1169,1);
this.SubFn1();

case 2: // init.done
this.setLatest(1169,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.utf8_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
}// end SubFn0
private inline  function SubFn1():Void {
Go.utf8_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
_Next=2; // jump 2.init.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
}// end SubFn1
}
#if js @:expose("Go_tardisgolib_NumGoroutine") #end class Go_tardisgolib_NumGoroutine extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:42:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,483,"Go_tardisgolib_NumGoroutine");
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
var _sf=new Go_tardisgolib_NumGoroutine(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : Int {
var _sf=new Go_tardisgolib_NumGoroutine(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_tardisgolib_NumGoroutine
{return new Go_tardisgolib_NumGoroutine(gr,_bds);
}
public function run():Go_tardisgolib_NumGoroutine {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(483,0);
_t0=Scheduler.NumGoroutine(); // _t0 = HAXE("Scheduler.NumGoro...":string) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:42:42
this.SubFn0();
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:42:27

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=cast(_t0,Int); // _t1 = convert int <- uintptr (t0) *ssa.Convert @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:42:37
}// end SubFn0
}
#if js @:expose("Go_utf8_RuneCountInString") #end class Go_utf8_RuneCountInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,1114,"Go_utf8_RuneCountInString");
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
this.setLatest(1114,0);
this.SubFn0();
_Phi=0;
case 1: // rangeiter.loop
this.setLatest(1114,1);
_t1=((_Phi==0)?0:(_Phi==2)?_t4:0); // _t1 = phi [0.entry: 0:int, 2.rangeiter.body: t4] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:382:35
this.SubFn1();
_Phi=1;
case 2: // rangeiter.body
this.setLatest(1114,2);
this.SubFn2();
_Phi=2;
case 3: // rangeiter.done
this.setLatest(1114,3);
this.setPH(1118);
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:386:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(1115);
_t0={k:0,v:Force.toUTF8slice(this._goroutine,p_s)}; // _t0 = range s *ssa.Range @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
_Next=1; // jump 1.rangeiter.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:{r0:Bool,r1:Dynamic,r2:Dynamic};
var _t3:Bool;
_t2={var _thisK:Int=_t0.k;if(_t0.k>=_t0.v.len()){r0:false,r1:0,r2:0};else {var _dr:{r0:Int,r1:Int}=Go_utf8_DecodeRune.callFromRT(this._goroutine,_t0.v.subSlice(_thisK,-1));_t0.k+=_dr.r1;{r0:true,r1:cast(_thisK,Int),r2:cast(_dr.r0,Int)};}}; // _t2 = next t0 *ssa.Next near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
_t3=_t2.r0; // _t3 = extract t2 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
_Next=_t3 ? 2 : 3; // if t3 goto 2.rangeiter.body else 3.rangeiter.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
}// end SubFn1
private inline  function SubFn2():Void {
_t4=(_t1+1); // _t4 = t1 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
_Next=1; // jump 1.rangeiter.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2
}// end SubFn2
}
#if js @:expose("Go_utf16_DecodeRune") #end class Go_utf16_DecodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:37:6
var p_r1:Int;
var p_r2:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r1 : Int, p_r2 : Int) {
super(gr,661,"Go_utf16_DecodeRune");
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
this.setLatest(661,0);
this.SubFn0();

case 1: // if.then
this.setLatest(661,1);
this.SubFn1();
this.setPH(663);
_res= _t5;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:3

case 2: // if.done
this.setLatest(663,2);
this.setPH(665);
_res= 65533;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:41:2

case 3: // cond.true
this.setLatest(665,3);
this.SubFn2();

case 4: // cond.true
this.setLatest(665,4);
this.SubFn3();

case 5: // cond.true
this.setLatest(665,5);
this.SubFn4();

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(662);
_t0=(55296<=p_r1); // _t0 = 55296:rune <= r1 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:11
_Next=_t0 ? 5 : 2; // if t0 goto 5.cond.true else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:11
}// end SubFn0
private inline  function SubFn1():Void {
var _t1:Int;
var _t2:Int;
var _t3:Int;
var _t4:Int;
this.setPH(663);
_t1=Force.toInt32((p_r1-55296)); // _t1 = r1 - 55296:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:19
_t2=(_t1<<GOint64.toInt(GOint64.make(0x0,0xa))); // _t2 = t1 << 10:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:26
_t3=Force.toInt32((p_r2-56320)); // _t3 = r2 - 56320:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:43
_t4=Force.toInt32((_t2|_t3)); // _t4 = t2 | t3 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:31
_t5=Force.toInt32((_t4+65536)); // _t5 = t4 + 65536:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:52
}// end SubFn1
private inline  function SubFn2():Void {
var _t6:Bool;
this.setPH(662);
_t6=(p_r2<57344); // _t6 = r2 < 57344:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:52
_Next=_t6 ? 1 : 2; // if t6 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:52
}// end SubFn2
private inline  function SubFn3():Void {
var _t7:Bool;
_t7=(56320<=p_r2); // _t7 = 56320:rune <= r2 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:40
_Next=_t7 ? 3 : 2; // if t7 goto 3.cond.true else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:40
}// end SubFn3
private inline  function SubFn4():Void {
var _t8:Bool;
_t8=(p_r1<56320); // _t8 = r1 < 56320:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:23
_Next=_t8 ? 4 : 2; // if t8 goto 4.cond.true else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:23
}// end SubFn4
}
#if js @:expose("Go_atomic_StoreUintptr") #end class Go_atomic_StoreUintptr extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:166:6
var p_addr:Pointer;
var p_val:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : Dynamic) {
super(gr,287,"Go_atomic_StoreUintptr");
this._bds=_bds;
this.p_addr=p_addr;
this.p_val=p_val;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_val : Dynamic) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_StoreUintptr(0,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_val : Dynamic) : Void {
var _sf=new Go_atomic_StoreUintptr(_gr,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : Dynamic) : Go_atomic_StoreUintptr
{return new Go_atomic_StoreUintptr(gr,_bds, p_addr, p_val);
}
public function run():Go_atomic_StoreUintptr {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(287,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:23

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:166:49
}// end SubFn0
}
#if (!php) private #end class Go_atomic_panic64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/sync/atomic/doc.go:149:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,439,"Go_atomic_panic64");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_panic64(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_atomic_panic64(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_atomic_panic64
{return new Go_atomic_panic64(gr,_bds);
}
public function run():Go_atomic_panic64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(439,0);
this.SubFn0();
this.setPH(440);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(440,-1);
 // panic t0 *ssa.Panic @ /usr/local/go/src/pkg/sync/atomic/doc.go:150:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"sync/atomic: broken 64-bit atomic operations (buggy QEMU)"); // _t0 = make interface{} <- string ("sync/atomic: brok...":string) *ssa.MakeInterface near /usr/local/go/src/pkg/sync/atomic/doc.go:150:7
}// end SubFn0
}
#if js @:expose("Go_tardisgolib_Zilen") #end class Go_tardisgolib_Zilen extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:26:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,467,"Go_tardisgolib_Zilen");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_tardisgolib_Zilen(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : Int {
var _sf=new Go_tardisgolib_Zilen(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_tardisgolib_Zilen
{return new Go_tardisgolib_Zilen(gr,_bds);
}
public function run():Go_tardisgolib_Zilen {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(467,0);
_res= 3;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 3:uint *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:26:21

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_utf8_DecodeLastRuneInString") #end class Go_utf8_DecodeLastRuneInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:276:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,1008,"Go_utf8_DecodeLastRuneInString");
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
this.setLatest(1008,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(1008,1);
this.setPH(1011);
_res= {r0:65533,r1:0};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:279:3

case 2: // if.done
this.setLatest(1011,2);
this.SubFn1();
_Phi=2;
case 3: // if.then
this.setLatest(1011,3);
this.setPH(1016);
_res= {r0:_t4,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:284:3

case 4: // if.done
this.setLatest(1016,4);
this.SubFn2();
_Phi=4;
case 5: // if.then
this.setLatest(1016,5);
this.SubFn3();
_Phi=5;
case 6: // if.done
this.setLatest(1016,6);
this.setPH(1021);
_t8=((_Phi==4)?_t6:(_Phi==5)?0:0); // _t8 = phi [4.if.done: t6, 5.if.then: 0:int] #lim *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:289:2
this.SubFn4();
_Phi=6;
case 7: // for.body
this.setLatest(1021,7);
this.SubFn5();
this.setPH(1026);
_SF1=Go_utf8_RuneStart.call(this._goroutine,[],_t10);
_Next = -1;
return this;
case -1:
this.setLatest(1026,-1);
_t11=_SF1.res();
 // _t11 = RuneStart(t10) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:294:15
this.SubFn6();
_Phi=7;
case 8: // for.done
this.setLatest(1026,8);
this.SubFn7();
_Phi=8;
case 9: // for.loop
this.setLatest(1026,9);
this.setPH(1013);
_t13=((_Phi==6)?_t9:(_Phi==10)?_t15:0); // _t13 = phi [6.if.done: t9, 10.if.done: t15] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:281:2
this.SubFn8();
_Phi=9;
case 10: // if.done
this.setLatest(1013,10);
this.SubFn9();
_Phi=10;
case 11: // if.then
this.setLatest(1013,11);
this.SubFn10();
_Phi=11;
case 12: // if.done
this.setLatest(1013,12);
_t16=((_Phi==8)?_t13:(_Phi==11)?0:0); // _t16 = phi [8.for.done: t13, 11.if.then: 0:int] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:281:2
this.SubFn11();
this.setPH(1033);
_SF2=Go_utf8_DecodeRuneInString.call(this._goroutine,[],_t17);
_Next = -2;
return this;
case -2:
this.setLatest(1033,-2);
_t18=_SF2.res();
 // _t18 = DecodeRuneInString(t17) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:30
this.SubFn12();
_Phi=12;
case 13: // if.then
this.setLatest(1033,13);
this.setPH(1035);
_res= {r0:65533,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:303:3

case 14: // if.done
this.setLatest(1035,14);
this.setPH(1037);
_res= {r0:_t19,r1:_t20};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t19, t20 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:305:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Bool;
this.setPH(1009);
_t0=Force.toUTF8length(this._goroutine,p_s); // _t0 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:277:12
this.setPH(1010);
_t1=(_t0==0); // _t1 = t0 == 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:278:9
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:278:9
}// end SubFn0
private inline  function SubFn1():Void {
var _t3:Int;
var _t5:Bool;
this.setPH(1013);
_t2=(_t0-1); // _t2 = t0 - 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:281:15
this.setPH(1014);
_t3=Force.toUTF8slice(this._goroutine,p_s).getAt(_t2); // _t3 = s[t2] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:282:12
_t4=_t3; // _t4 = convert rune <- uint8 (t3) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:282:10
this.setPH(1015);
_t5=(_t4<128); // _t5 = t4 < 128:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:283:7
_Next=_t5 ? 3 : 4; // if t5 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:283:7
}// end SubFn1
private inline  function SubFn2():Void {
var _t7:Bool;
this.setPH(1021);
_t6=(_t0-4); // _t6 = t0 - 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:289:13
this.setPH(1022);
_t7=(_t6<0); // _t7 = t6 < 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:290:9
_Next=_t7 ? 5 : 6; // if t7 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:290:9
}// end SubFn2
private inline  function SubFn3():Void {
_Next=6; // jump 6.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:290:9
}// end SubFn3
private inline  function SubFn4():Void {
_t9=(_t2-1); // _t9 = t2 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:290:9
_Next=9; // jump 9.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:290:9
}// end SubFn4
private inline  function SubFn5():Void {
this.setPH(1026);
_t10=Force.toUTF8slice(this._goroutine,p_s).getAt(_t13); // _t10 = s[t13] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:294:17
}// end SubFn5
private inline  function SubFn6():Void {
_Next=_t11 ? 8 : 10; // if t11 goto 8.for.done else 10.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:294:17
}// end SubFn6
private inline  function SubFn7():Void {
var _t12:Bool;
this.setPH(1030);
_t12=(_t13<0); // _t12 = t13 < 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:298:11
_Next=_t12 ? 11 : 12; // if t12 goto 11.if.then else 12.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:298:11
}// end SubFn7
private inline  function SubFn8():Void {
var _t14:Bool;
this.setPH(1025);
_t14=(_t13>=_t8); // _t14 = t13 >= t8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:293:21
_Next=_t14 ? 7 : 8; // if t14 goto 7.for.body else 8.for.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:293:21
}// end SubFn8
private inline  function SubFn9():Void {
_t15=(_t13-1); // _t15 = t13 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:293:21
_Next=9; // jump 9.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:293:21
}// end SubFn9
private inline  function SubFn10():Void {
_Next=12; // jump 12.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:293:21
}// end SubFn10
private inline  function SubFn11():Void {
this.setPH(1033);
_t17=Force.toRawString(this._goroutine,Force.toUTF8slice(this._goroutine,p_s).subSlice(_t16,_t0)); // _t17 = slice s[t16:t0] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:32
}// end SubFn11
private inline  function SubFn12():Void {
var _t21:Int;
var _t22:Bool;
_t19=_t18.r0; // _t19 = extract t18 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:32
_t20=_t18.r1; // _t20 = extract t18 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:32
this.setPH(1034);
_t21=(_t16+_t20); // _t21 = t16 + t20 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:302:10
_t22=(_t21!=_t0); // _t22 = t21 != t0 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:302:16
_Next=_t22 ? 13 : 14; // if t22 goto 13.if.then else 14.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:302:16
}// end SubFn12
}
#if js @:expose("Go_atomic_StorePointer") #end class Go_atomic_StorePointer extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:169:6
var p_addr:Pointer;
var p_val:UnsafePointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : UnsafePointer) {
super(gr,290,"Go_atomic_StorePointer");
this._bds=_bds;
this.p_addr=p_addr;
this.p_val=p_val;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_val : UnsafePointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_StorePointer(0,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_val : UnsafePointer) : Void {
var _sf=new Go_atomic_StorePointer(_gr,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : UnsafePointer) : Go_atomic_StorePointer
{return new Go_atomic_StorePointer(gr,_bds, p_addr, p_val);
}
public function run():Go_atomic_StorePointer {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(290,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/unicode/utf8/utf8.go:302:16

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:169:63
}// end SubFn0
}
#if js @:expose("Go_atomic_StoreInt32") #end class Go_atomic_StoreInt32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:154:6
var p_addr:Pointer;
var p_val:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : Int) {
super(gr,275,"Go_atomic_StoreInt32");
this._bds=_bds;
this.p_addr=p_addr;
this.p_val=p_val;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_val : Int) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_StoreInt32(0,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_val : Int) : Void {
var _sf=new Go_atomic_StoreInt32(_gr,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : Int) : Go_atomic_StoreInt32
{return new Go_atomic_StoreInt32(gr,_bds, p_addr, p_val);
}
public function run():Go_atomic_StoreInt32 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(275,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:169:63

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:154:43
}// end SubFn0
}
#if js @:expose("Go_tardisgolib_Gosched") #end class Go_tardisgolib_Gosched extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:39:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,480,"Go_tardisgolib_Gosched");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_tardisgolib_Gosched(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_tardisgolib_Gosched(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_tardisgolib_Gosched
{return new Go_tardisgolib_Gosched(gr,_bds);
}
public function run():Go_tardisgolib_Gosched {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(480,0);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:154:43

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_utf8_decodeRuneInternal extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:45:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,777,"Go_utf8_decodeRuneInternal");
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
this.setLatest(777,0);
this.SubFn0();

case 1: // if.then
this.setLatest(777,1);
this.setPH(780);
_res= {r0:65533,r1:0,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:48:3

case 2: // if.done
this.setLatest(780,2);
this.SubFn1();

case 3: // if.then
this.setLatest(780,3);
this.SubFn2();
this.setPH(786);
_res= {r0:_t5,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:54:3

case 4: // if.done
this.setLatest(786,4);
this.SubFn3();

case 5: // if.then
this.setLatest(786,5);
this.setPH(791);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:59:3

case 6: // if.done
this.setLatest(791,6);
this.SubFn4();

case 7: // if.then
this.setLatest(791,7);
this.setPH(796);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:64:3

case 8: // if.done
this.setLatest(796,8);
this.SubFn5();

case 9: // if.then
this.setLatest(796,9);
this.setPH(800);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:68:3

case 10: // if.done
this.setLatest(800,10);
this.SubFn6();

case 11: // cond.false
this.setLatest(800,11);
this.SubFn7();

case 12: // if.then
this.setLatest(800,12);
this.SubFn8();

case 13: // if.done
this.setLatest(800,13);
this.SubFn9();

case 14: // if.then
this.setLatest(800,14);
this.setPH(807);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:75:4

case 15: // if.done
this.setLatest(807,15);
this.setPH(809);
_res= {r0:_t18,r1:2,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t18, 2:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:77:3

case 16: // if.then
this.setLatest(809,16);
this.setPH(814);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:82:3

case 17: // if.done
this.setLatest(814,17);
this.SubFn10();

case 18: // if.then
this.setLatest(814,18);
this.setPH(818);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:86:3

case 19: // if.done
this.setLatest(818,19);
this.SubFn11();

case 20: // cond.false
this.setLatest(818,20);
this.SubFn12();

case 21: // if.then
this.setLatest(818,21);
this.SubFn13();

case 22: // if.done
this.setLatest(818,22);
this.SubFn14();

case 23: // if.then
this.setLatest(818,23);
this.setPH(825);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:93:4

case 24: // if.done
this.setLatest(825,24);
this.SubFn15();

case 25: // if.then
this.setLatest(825,25);
this.setPH(828);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:96:4

case 26: // if.done
this.setLatest(828,26);
this.setPH(830);
_res= {r0:_t35,r1:3,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t35, 3:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:98:3

case 27: // cond.true
this.setLatest(830,27);
this.SubFn16();

case 28: // if.then
this.setLatest(830,28);
this.setPH(835);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:103:3

case 29: // if.done
this.setLatest(835,29);
this.SubFn17();

case 30: // if.then
this.setLatest(835,30);
this.setPH(839);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:107:3

case 31: // if.done
this.setLatest(839,31);
this.SubFn18();

case 32: // cond.false
this.setLatest(839,32);
this.SubFn19();

case 33: // if.then
this.setLatest(839,33);
this.SubFn20();

case 34: // if.done
this.setLatest(839,34);
this.setPH(852);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:120:2

case 35: // if.then
this.setLatest(852,35);
this.setPH(846);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:114:4

case 36: // if.done
this.setLatest(846,36);
this.setPH(848);
_res= {r0:_t58,r1:4,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t58, 4:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:116:3

case 37: // cond.false
this.setLatest(848,37);
this.SubFn21();

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Bool;
this.setPH(778);
_t0=({var _v=p_p;_v==null?0:_v.len();}); // _t0 = len(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:46:10
this.setPH(779);
_t1=(_t0<1); // _t1 = t0 < 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:47:7
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:47:7
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Pointer;
var _t4:Bool;
this.setPH(782);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:50:9 [POINTER]
_t2=p_p.addr(0);  // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:50:9 [POINTER]
_t3=(_t2.load()|0); // _t3 = *t2 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:50:9
this.setPH(785);
_t4=(Force.uintCompare(_t3,128)<0); // _t4 = t3 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:53:8
_Next=_t4 ? 3 : 4; // if t4 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:53:8
}// end SubFn1
private inline  function SubFn2():Void {
this.setPH(786);
_t5=_t3; // _t5 = convert rune <- byte (t3) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:54:14
}// end SubFn2
private inline  function SubFn3():Void {
var _t6:Bool;
this.setPH(790);
_t6=(Force.uintCompare(_t3,192)<0); // _t6 = t3 < 192:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:58:8
_Next=_t6 ? 5 : 6; // if t6 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:58:8
}// end SubFn3
private inline  function SubFn4():Void {
var _t7:Bool;
this.setPH(795);
_t7=(_t0<2); // _t7 = t0 < 2:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:63:7
_Next=_t7 ? 7 : 8; // if t7 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:63:7
}// end SubFn4
private inline  function SubFn5():Void {
var _t8:Pointer;
var _t10:Bool;
this.setPH(798);
if((1<0)||(1>=p_p.len())) Scheduler.ioor(); // _t8 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:66:9 [POINTER]
_t8=p_p.addr(1);  // _t8 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:66:9 [POINTER]
_t9=(_t8.load()|0); // _t9 = *t8 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:66:9
this.setPH(799);
_t10=(Force.uintCompare(_t9,128)<0); // _t10 = t9 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:67:8
_Next=_t10 ? 9 : 11; // if t10 goto 9.if.then else 11.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:67:8
}// end SubFn5
private inline  function SubFn6():Void {
var _t11:Bool;
this.setPH(804);
_t11=(Force.uintCompare(_t3,224)<0); // _t11 = t3 < 224:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:72:8
_Next=_t11 ? 12 : 13; // if t11 goto 12.if.then else 13.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:72:8
}// end SubFn6
private inline  function SubFn7():Void {
var _t12:Bool;
this.setPH(799);
_t12=(Force.uintCompare(192,_t9)<=0); // _t12 = 192:byte <= t9 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:67:19
_Next=_t12 ? 9 : 10; // if t12 goto 9.if.then else 10.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:67:19
}// end SubFn7
private inline  function SubFn8():Void {
var _t13:Int;
var _t14:Int;
var _t15:Int;
var _t16:Int;
var _t17:Int;
var _t19:Bool;
this.setPH(805);
_t13=Force.toUint8((_t3&31)); // _t13 = t3 & 31:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:14
_t14=_t13; // _t14 = convert rune <- byte (t13) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:11
_t15=(_t14<<GOint64.toInt(GOint64.make(0x0,0x6))); // _t15 = t14 << 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:21
_t16=Force.toUint8((_t9&63)); // _t16 = t9 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:34
_t17=_t16; // _t17 = convert rune <- byte (t16) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:31
_t18=Force.toInt32((_t15|_t17)); // _t18 = t15 | t17 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:25
this.setPH(806);
_t19=(_t18<=127); // _t19 = t18 <= 127:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:74:8
_Next=_t19 ? 14 : 15; // if t19 goto 14.if.then else 15.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:74:8
}// end SubFn8
private inline  function SubFn9():Void {
var _t20:Bool;
this.setPH(813);
_t20=(_t0<3); // _t20 = t0 < 3:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:81:7
_Next=_t20 ? 16 : 17; // if t20 goto 16.if.then else 17.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:81:7
}// end SubFn9
private inline  function SubFn10():Void {
var _t21:Pointer;
var _t23:Bool;
this.setPH(816);
if((2<0)||(2>=p_p.len())) Scheduler.ioor(); // _t21 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:84:9 [POINTER]
_t21=p_p.addr(2);  // _t21 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:84:9 [POINTER]
_t22=(_t21.load()|0); // _t22 = *t21 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:84:9
this.setPH(817);
_t23=(Force.uintCompare(_t22,128)<0); // _t23 = t22 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:85:8
_Next=_t23 ? 18 : 20; // if t23 goto 18.if.then else 20.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:85:8
}// end SubFn10
private inline  function SubFn11():Void {
var _t24:Bool;
this.setPH(822);
_t24=(Force.uintCompare(_t3,240)<0); // _t24 = t3 < 240:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:90:8
_Next=_t24 ? 21 : 22; // if t24 goto 21.if.then else 22.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:90:8
}// end SubFn11
private inline  function SubFn12():Void {
var _t25:Bool;
this.setPH(817);
_t25=(Force.uintCompare(192,_t22)<=0); // _t25 = 192:byte <= t22 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:85:19
_Next=_t25 ? 18 : 19; // if t25 goto 18.if.then else 19.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:85:19
}// end SubFn12
private inline  function SubFn13():Void {
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
this.setPH(823);
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
this.setPH(824);
_t36=(_t35<=2047); // _t36 = t35 <= 2047:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:92:8
_Next=_t36 ? 23 : 24; // if t36 goto 23.if.then else 24.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:92:8
}// end SubFn13
private inline  function SubFn14():Void {
var _t37:Bool;
this.setPH(834);
_t37=(_t0<4); // _t37 = t0 < 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:102:7
_Next=_t37 ? 28 : 29; // if t37 goto 28.if.then else 29.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:102:7
}// end SubFn14
private inline  function SubFn15():Void {
var _t38:Bool;
this.setPH(827);
_t38=(55296<=_t35); // _t38 = 55296:rune <= t35 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:95:19
_Next=_t38 ? 27 : 26; // if t38 goto 27.cond.true else 26.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:95:19
}// end SubFn15
private inline  function SubFn16():Void {
var _t39:Bool;
_t39=(_t35<=57343); // _t39 = t35 <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:95:29
_Next=_t39 ? 25 : 26; // if t39 goto 25.if.then else 26.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:95:29
}// end SubFn16
private inline  function SubFn17():Void {
var _t40:Pointer;
var _t42:Bool;
this.setPH(837);
if((3<0)||(3>=p_p.len())) Scheduler.ioor(); // _t40 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:105:9 [POINTER]
_t40=p_p.addr(3);  // _t40 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:105:9 [POINTER]
_t41=(_t40.load()|0); // _t41 = *t40 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:105:9
this.setPH(838);
_t42=(Force.uintCompare(_t41,128)<0); // _t42 = t41 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:106:8
_Next=_t42 ? 30 : 32; // if t42 goto 30.if.then else 32.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:106:8
}// end SubFn17
private inline  function SubFn18():Void {
var _t43:Bool;
this.setPH(843);
_t43=(Force.uintCompare(_t3,248)<0); // _t43 = t3 < 248:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:111:8
_Next=_t43 ? 33 : 34; // if t43 goto 33.if.then else 34.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:111:8
}// end SubFn18
private inline  function SubFn19():Void {
var _t44:Bool;
this.setPH(838);
_t44=(Force.uintCompare(192,_t41)<=0); // _t44 = 192:byte <= t41 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:106:19
_Next=_t44 ? 30 : 31; // if t44 goto 30.if.then else 31.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:106:19
}// end SubFn19
private inline  function SubFn20():Void {
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
this.setPH(844);
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
this.setPH(845);
_t59=(_t58<=65535); // _t59 = t58 <= 65535:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:8
_Next=_t59 ? 35 : 37; // if t59 goto 35.if.then else 37.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:8
}// end SubFn20
private inline  function SubFn21():Void {
var _t60:Bool;
_t60=(1114111<_t58); // _t60 = 1114111:rune < t58 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:31
_Next=_t60 ? 35 : 36; // if t60 goto 35.if.then else 36.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:31
}// end SubFn21
}
#if js @:expose("Go_haxegoruntime_Raw2Runes") #end class Go_haxegoruntime_Raw2Runes extends StackFrameBasis implements StackFrame {  // langgoruntime.go:55:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,538,"Go_haxegoruntime_Raw2Runes");
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
var _t17:Pointer=null;
var _t18:Slice=null;
var _t19:Int=0;
var _t20:Int=0;
var _t21:Bool=false;
var _t22:Pointer=null;
var _t23:Pointer=null;
var _t24:Int=0;
var _t25:Int=0;
var _SF2:StackFrame;
var _t26:Slice=null;
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
this.setLatest(538,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(538,1);
this.SubFn1();
_Phi=1;
case 2: // switch.body
this.setLatest(538,2);
this.SubFn2();
_Phi=2;
case 3: // switch.next
this.setLatest(538,3);
this.SubFn3();
_Phi=3;
case 4: // rangeindex.loop
this.setLatest(538,4);
_t9=((_Phi==1)?(-1):(_Phi==5)?_t10:0); // _t9 = phi [1.switch.body: -1:int, 5.rangeindex.body: t10] *ssa.Phi near /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:31
this.SubFn4();
_Phi=4;
case 5: // rangeindex.body
this.setLatest(538,5);
this.SubFn5();
_Phi=5;
case 6: // rangeindex.done
this.setLatest(538,6);
this.setPH(545);
_SF1=Go_haxegoruntime_UTF16toRunes.call(this._goroutine,[],_t3);
_Next = -1;
return this;
case -1:
this.setLatest(545,-1);
_t16=_SF1.res();
 // _t16 = UTF16toRunes(t3) *ssa.Call @ langgoruntime.go:62:22
_res= _t16;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t16 *ssa.Return @ langgoruntime.go:62:3

case 7: // switch.next
this.setLatest(545,7);
this.SubFn6();
this.setPH(555);
_res= _t18;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t18 *ssa.Return @ langgoruntime.go:72:2

case 8: // rangeindex.loop
this.setLatest(555,8);
_t19=((_Phi==2)?(-1):(_Phi==9)?_t20:0); // _t19 = phi [2.switch.body: -1:int, 9.rangeindex.body: t20] *ssa.Phi near langgoruntime.go:72:2
this.SubFn7();
_Phi=8;
case 9: // rangeindex.body
this.setLatest(555,9);
this.SubFn8();
_Phi=9;
case 10: // rangeindex.done
this.setLatest(555,10);
this.setPH(551);
_SF2=Go_haxegoruntime_UTF8toRunes.call(this._goroutine,[],_t6);
_Next = -2;
return this;
case -2:
this.setLatest(551,-2);
_t26=_SF2.res();
 // _t26 = UTF8toRunes(t6) *ssa.Call @ langgoruntime.go:68:21
_res= _t26;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t26 *ssa.Return @ langgoruntime.go:68:3

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Bool;
_t0=(Go.haxegoruntime_ZiLen.load()|0); // _t0 = *ZiLen *ssa.UnOp near langgoruntime.go:68:3
_t1=(Force.uintCompare(_t0,1)==0); // _t1 = t0 == 1:uint *ssa.BinOp near langgoruntime.go:68:3
_Next=_t1 ? 1 : 3; // if t1 goto 1.switch.body else 3.switch.next *ssa.If near langgoruntime.go:68:3
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Int;
this.setPH(541);
_t2=({var _v=p_s;_v==null?0:_v.len();}); // _t2 = len(s) *ssa.Call @ langgoruntime.go:58:40
_t3=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t2) _v[_i]=0; _v;}),0,_t2); // _t3 = make []uint16 t2 t2 *ssa.MakeSlice @ langgoruntime.go:58:26
_t4=({var _v=p_s;_v==null?0:_v.len();}); // _t4 = len(s) *ssa.Call near langgoruntime.go:58:26
_Next=4; // jump 4.rangeindex.loop *ssa.Jump near langgoruntime.go:58:26
}// end SubFn1
private inline  function SubFn2():Void {
var _t5:Int;
this.setPH(547);
_t5=({var _v=p_s;_v==null?0:_v.len();}); // _t5 = len(s) *ssa.Call @ langgoruntime.go:64:36
_t6=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t5) _v[_i]=0; _v;}),0,_t5); // _t6 = make []byte t5 t5 *ssa.MakeSlice @ langgoruntime.go:64:24
_t7=({var _v=p_s;_v==null?0:_v.len();}); // _t7 = len(s) *ssa.Call near langgoruntime.go:64:24
_Next=8; // jump 8.rangeindex.loop *ssa.Jump near langgoruntime.go:64:24
}// end SubFn2
private inline  function SubFn3():Void {
var _t8:Bool;
_t8=(Force.uintCompare(_t0,3)==0); // _t8 = t0 == 3:uint *ssa.BinOp near langgoruntime.go:64:24
_Next=_t8 ? 2 : 7; // if t8 goto 2.switch.body else 7.switch.next *ssa.If near langgoruntime.go:64:24
}// end SubFn3
private inline  function SubFn4():Void {
var _t11:Bool;
_t10=(_t9+1); // _t10 = t9 + 1:int *ssa.BinOp near langgoruntime.go:64:24
_t11=(_t10<_t4); // _t11 = t10 < t4 *ssa.BinOp near langgoruntime.go:64:24
_Next=_t11 ? 5 : 6; // if t11 goto 5.rangeindex.body else 6.rangeindex.done *ssa.If near langgoruntime.go:64:24
}// end SubFn4
private inline  function SubFn5():Void {
var _t12:Pointer;
var _t13:Pointer;
var _t14:Int;
var _t15:Int;
this.setPH(543);
if((_t10<0)||(_t10>=_t3.len())) Scheduler.ioor(); // _t12 = &t3[t10] *ssa.IndexAddr @ langgoruntime.go:60:7 [POINTER]
_t12=_t3.addr(_t10);  // _t12 = &t3[t10] *ssa.IndexAddr @ langgoruntime.go:60:7 [POINTER]
if((_t10<0)||(_t10>=p_s.len())) Scheduler.ioor(); // _t13 = &s[t10] *ssa.IndexAddr @ langgoruntime.go:60:21 [POINTER]
_t13=p_s.addr(_t10);  // _t13 = &s[t10] *ssa.IndexAddr @ langgoruntime.go:60:21 [POINTER]
_t14=(_t13.load()|0); // _t14 = *t13 *ssa.UnOp near langgoruntime.go:60:21
_t15=_t14; // _t15 = convert uint16 <- int (t14) *ssa.Convert @ langgoruntime.go:60:19
_t12.store(_t15); // *t12 = t15 *ssa.Store near langgoruntime.go:60:19
_Next=4; // jump 4.rangeindex.loop *ssa.Jump near langgoruntime.go:60:19
}// end SubFn5
private inline  function SubFn6():Void {
var _t17:Pointer;
this.setPH(555);
_t17=new Pointer({var _v=new Array<Int>();for(_vi in 0...0){_v[_vi]=0;}; _v;}); // _t17 = new [0]rune (slicelit) *ssa.Alloc @ langgoruntime.go:72:15
_t18=new Slice(_t17,0,-1); // _t18 = slice t17[:] *ssa.Slice @ langgoruntime.go:72:15
}// end SubFn6
private inline  function SubFn7():Void {
var _t21:Bool;
_t20=(_t19+1); // _t20 = t19 + 1:int *ssa.BinOp near langgoruntime.go:72:15
_t21=(_t20<_t7); // _t21 = t20 < t7 *ssa.BinOp near langgoruntime.go:72:15
_Next=_t21 ? 9 : 10; // if t21 goto 9.rangeindex.body else 10.rangeindex.done *ssa.If near langgoruntime.go:72:15
}// end SubFn7
private inline  function SubFn8():Void {
var _t22:Pointer;
var _t23:Pointer;
var _t24:Int;
var _t25:Int;
this.setPH(549);
if((_t20<0)||(_t20>=_t6.len())) Scheduler.ioor(); // _t22 = &t6[t20] *ssa.IndexAddr @ langgoruntime.go:66:7 [POINTER]
_t22=_t6.addr(_t20);  // _t22 = &t6[t20] *ssa.IndexAddr @ langgoruntime.go:66:7 [POINTER]
if((_t20<0)||(_t20>=p_s.len())) Scheduler.ioor(); // _t23 = &s[t20] *ssa.IndexAddr @ langgoruntime.go:66:19 [POINTER]
_t23=p_s.addr(_t20);  // _t23 = &s[t20] *ssa.IndexAddr @ langgoruntime.go:66:19 [POINTER]
_t24=(_t23.load()|0); // _t24 = *t23 *ssa.UnOp near langgoruntime.go:66:19
_t25=_t24; // _t25 = convert byte <- int (t24) *ssa.Convert @ langgoruntime.go:66:17
_t22.store(_t25); // *t22 = t25 *ssa.Store near langgoruntime.go:66:17
_Next=8; // jump 8.rangeindex.loop *ssa.Jump near langgoruntime.go:66:17
}// end SubFn8
}
#if js @:expose("Go_atomic_CompareAndSwapPointer") #end class Go_atomic_CompareAndSwapPointer extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:97:6
var p_addr:Pointer;
var p_old:UnsafePointer;
var p_new:UnsafePointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : UnsafePointer, p_new : UnsafePointer) {
super(gr,218,"Go_atomic_CompareAndSwapPointer");
this._bds=_bds;
this.p_addr=p_addr;
this.p_old=p_old;
this.p_new=p_new;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:UnsafePointer=null;
var _t1:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_old : UnsafePointer, p_new : UnsafePointer) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_CompareAndSwapPointer(0,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_old : UnsafePointer, p_new : UnsafePointer) : Bool {
var _sf=new Go_atomic_CompareAndSwapPointer(_gr,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : UnsafePointer, p_new : UnsafePointer) : Go_atomic_CompareAndSwapPointer
{return new Go_atomic_CompareAndSwapPointer(gr,_bds, p_addr, p_old, p_new);
}
public function run():Go_atomic_CompareAndSwapPointer {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(218,0);
this.SubFn0();

case 1: // if.then
this.setLatest(218,1);
this.SubFn1();
this.setPH(221);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:100:3

case 2: // if.done
this.setLatest(221,2);
this.setPH(223);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:102:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:UnsafePointer;
var _t1:Bool;
this.setPH(219);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:98:5
_t1=(_t0==p_old); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:98:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:98:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(220);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:99:3
}// end SubFn1
}
#if js @:expose("Go_atomic_StoreUint32") #end class Go_atomic_StoreUint32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:6
var p_addr:Pointer;
var p_val:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : Int) {
super(gr,281,"Go_atomic_StoreUint32");
this._bds=_bds;
this.p_addr=p_addr;
this.p_val=p_val;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_val : Int) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_StoreUint32(0,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_val : Int) : Void {
var _sf=new Go_atomic_StoreUint32(_gr,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : Int) : Go_atomic_StoreUint32
{return new Go_atomic_StoreUint32(gr,_bds, p_addr, p_val);
}
public function run():Go_atomic_StoreUint32 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(281,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:99:3

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:46
}// end SubFn0
}
#if (!php) private #end class Go_main_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,281,"Go_main_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _SF1:StackFrame;
var _SF2:StackFrame;
var _SF3:StackFrame;
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
this.setLatest(281,0);
this.SubFn0();

case 1: // init.start
this.setLatest(281,1);
this.SubFn1();
Go_atomic_init.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(281,-1);
 // _t1 = github.com/tardisgo/tardisgo/golibruntime/sync/atomic.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:46 [REGISTER VALUE UN-USED]
Go_atomic_init.call(this._goroutine,[]);
_Next = -2;
return this;
case -2:
this.setLatest(281,-2);
 // _t2 = sync/atomic.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:46 [REGISTER VALUE UN-USED]
Go_tardisgolib_init.call(this._goroutine,[]);
_Next = -3;
return this;
case -3:
this.setLatest(281,-3);
 // _t3 = github.com/tardisgo/tardisgo/tardisgolib.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:46 [REGISTER VALUE UN-USED]
this.SubFn2();

case 2: // init.done
this.setLatest(281,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:46

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.main_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:46
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:46
}// end SubFn0
private inline  function SubFn1():Void {
Go.main_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:46
}// end SubFn1
private inline  function SubFn2():Void {
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:46
}// end SubFn2
}
#if js @:expose("Go_utf8_RuneStart") #end class Go_utf8_RuneStart extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:392:6
var p_b:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_b : Int) {
super(gr,1124,"Go_utf8_RuneStart");
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
this.setLatest(1124,0);
this.SubFn0();
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:392:31

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
_t0=Force.toUint8((p_b&192)); // _t0 = b & 192:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:392:39
_t1=(Force.uintCompare(_t0,128)!=0); // _t1 = t0 != 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:392:45
}// end SubFn0
}
#if js @:expose("Go_utf8_RuneLen") #end class Go_utf8_RuneLen extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:310:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,1042,"Go_utf8_RuneLen");
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
this.setLatest(1042,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(1042,1);
this.setPH(1045);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:313:3

case 2: // switch.body
this.setLatest(1045,2);
this.setPH(1047);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:315:3

case 3: // switch.next
this.setLatest(1047,3);
this.SubFn1();
_Phi=3;
case 4: // switch.body
this.setLatest(1047,4);
this.setPH(1049);
_res= 2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 2:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:317:3

case 5: // switch.next
this.setLatest(1049,5);
this.SubFn2();
_Phi=5;
case 6: // switch.body
this.setLatest(1049,6);
this.setPH(1051);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:319:3

case 7: // switch.next
this.setLatest(1051,7);
this.SubFn3();
_Phi=7;
case 8: // switch.body
this.setLatest(1051,8);
this.setPH(1053);
_res= 3;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 3:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:321:3

case 9: // switch.next
this.setLatest(1053,9);
this.SubFn4();
_Phi=9;
case 10: // binop.rhs
this.setLatest(1053,10);
this.SubFn5();
_Phi=10;
case 11: // binop.done
this.setLatest(1053,11);
this.setPH(1050);
_t6=((_Phi==7)?false:(_Phi==10)?_t5:false); // _t6 = phi [7.switch.next: false:bool, 10.binop.rhs: t5] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:25
this.SubFn6();
_Phi=11;
case 12: // switch.body
this.setLatest(1050,12);
this.setPH(1055);
_res= 4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 4:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:323:3

case 13: // switch.next
this.setLatest(1055,13);
this.SubFn7();
_Phi=13;
case 14: // switch.next
this.setLatest(1055,14);
this.setPH(1057);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:325:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(1044);
_t0=(p_r<0); // _t0 = r < 0:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:312:9
_Next=_t0 ? 1 : 3; // if t0 goto 1.switch.body else 3.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:312:9
}// end SubFn0
private inline  function SubFn1():Void {
var _t1:Bool;
this.setPH(1046);
_t1=(p_r<=127); // _t1 = r <= 127:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:314:9
_Next=_t1 ? 2 : 5; // if t1 goto 2.switch.body else 5.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:314:9
}// end SubFn1
private inline  function SubFn2():Void {
var _t2:Bool;
this.setPH(1048);
_t2=(p_r<=2047); // _t2 = r <= 2047:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:316:9
_Next=_t2 ? 4 : 7; // if t2 goto 4.switch.body else 7.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:316:9
}// end SubFn2
private inline  function SubFn3():Void {
var _t3:Bool;
this.setPH(1050);
_t3=(55296<=p_r); // _t3 = 55296:rune <= r *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:20
_Next=_t3 ? 10 : 11; // if t3 goto 10.binop.rhs else 11.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:20
}// end SubFn3
private inline  function SubFn4():Void {
var _t4:Bool;
this.setPH(1052);
_t4=(p_r<=65535); // _t4 = r <= 65535:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:320:9
_Next=_t4 ? 8 : 13; // if t4 goto 8.switch.body else 13.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:320:9
}// end SubFn4
private inline  function SubFn5():Void {
this.setPH(1050);
_t5=(p_r<=57343); // _t5 = r <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:30
_Next=11; // jump 11.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:30
}// end SubFn5
private inline  function SubFn6():Void {
_Next=_t6 ? 6 : 9; // if t6 goto 6.switch.body else 9.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:30
}// end SubFn6
private inline  function SubFn7():Void {
var _t7:Bool;
this.setPH(1054);
_t7=(p_r<=1114111); // _t7 = r <= 1114111:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:322:9
_Next=_t7 ? 12 : 14; // if t7 goto 12.switch.body else 14.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:322:9
}// end SubFn7
}
#if js @:expose("Go_utf16_EncodeRune") #end class Go_utf16_EncodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:47:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,671,"Go_utf16_EncodeRune");
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
this.setLatest(671,0);
this.SubFn0();

case 1: // if.then
this.setLatest(671,1);
this.setPH(673);
_res= {r0:65533,r1:65533};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 65533:rune *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:49:3

case 2: // if.done
this.setLatest(673,2);
this.SubFn1();
this.setPH(676);
_res= {r0:_t4,r1:_t6};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4, t6 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:2

case 3: // cond.false
this.setLatest(676,3);
this.setPH(672);
_SF1=Go_utf16_IsSurrogate.call(this._goroutine,[],p_r);
_Next = -1;
return this;
case -1:
this.setLatest(672,-1);
_t7=_SF1.res();
 // _t7 = IsSurrogate(r) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:47
this.SubFn2();

case 4: // cond.false
this.setLatest(672,4);
this.SubFn3();

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=(p_r<65536); // _t0 = r < 65536:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:7
_Next=_t0 ? 1 : 4; // if t0 goto 1.if.then else 4.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:7
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Int;
var _t3:Int;
var _t5:Int;
_t1=Force.toInt32((p_r-65536)); // _t1 = r - 65536:rune *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:7
this.setPH(676);
_t2=(_t1>>GOint64.toInt(GOint64.make(0x0,0xa))); // _t2 = t1 >> 10:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:19
_t3=Force.toInt32((_t2&1023)); // _t3 = t2 & 1023:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:24
_t4=Force.toInt32((55296+_t3)); // _t4 = 55296:rune + t3 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:15
_t5=Force.toInt32((_t1&1023)); // _t5 = t1 & 1023:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:41
_t6=Force.toInt32((56320+_t5)); // _t6 = 56320:rune + t5 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:38
}// end SubFn1
private inline  function SubFn2():Void {
_Next=_t7 ? 1 : 2; // if t7 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:38
}// end SubFn2
private inline  function SubFn3():Void {
var _t8:Bool;
this.setPH(672);
_t8=(p_r>1114111); // _t8 = r > 1114111:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:23
_Next=_t8 ? 1 : 3; // if t8 goto 1.if.then else 3.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:23
}// end SubFn3
}
#if (!php) private #end class Go_haxegoruntime_init_36_1 extends StackFrameBasis implements StackFrame {  // langgoruntime.go:14:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,497,"Go_haxegoruntime_init_36_1");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _SF2:StackFrame;
var _SF3:StackFrame;
var _SF4:StackFrame;
var _SF5:StackFrame;
var _SF6:StackFrame;
var _SF7:StackFrame;
var _SF8:StackFrame;
var _SF9:StackFrame;
var _SF10:StackFrame;
var _SF11:StackFrame;
var _t11:{r0:Int,r1:Int}=null;
var _SF12:StackFrame;
var _SF13:StackFrame;
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
this.setLatest(497,0);
this.SubFn0();
this.setPH(499);
Go_haxegoruntime_UTF16toRunes.call(this._goroutine,[],null);
_Next = -1;
return this;
case -1:
this.setLatest(499,-1);
 // _t1 = UTF16toRunes(nil:[]uint16) *ssa.Call @ langgoruntime.go:16:18 [REGISTER VALUE UN-USED]
this.setPH(500);
Go_haxegoruntime_UTF8toRunes.call(this._goroutine,[],null);
_Next = -2;
return this;
case -2:
this.setLatest(500,-2);
 // _t2 = UTF8toRunes(nil:[]byte) *ssa.Call @ langgoruntime.go:17:17 [REGISTER VALUE UN-USED]
this.setPH(501);
Go_haxegoruntime_Raw2Runes.call(this._goroutine,[],null);
_Next = -3;
return this;
case -3:
this.setLatest(501,-3);
 // _t3 = Raw2Runes(nil:[]int) *ssa.Call @ langgoruntime.go:18:15 [REGISTER VALUE UN-USED]
this.setPH(502);
Go_haxegoruntime_RunesToUTF16.call(this._goroutine,[],null);
_Next = -4;
return this;
case -4:
this.setLatest(502,-4);
 // _t4 = RunesToUTF16(nil:[]rune) *ssa.Call @ langgoruntime.go:19:18 [REGISTER VALUE UN-USED]
this.setPH(503);
Go_haxegoruntime_RunesToUTF8.call(this._goroutine,[],null);
_Next = -5;
return this;
case -5:
this.setLatest(503,-5);
 // _t5 = RunesToUTF8(nil:[]rune) *ssa.Call @ langgoruntime.go:20:17 [REGISTER VALUE UN-USED]
this.setPH(504);
Go_haxegoruntime_Runes2Raw.call(this._goroutine,[],null);
_Next = -6;
return this;
case -6:
this.setLatest(504,-6);
 // _t6 = Runes2Raw(nil:[]rune) *ssa.Call @ langgoruntime.go:21:15 [REGISTER VALUE UN-USED]
this.setPH(505);
Go_haxegoruntime_Rune2Raw.call(this._goroutine,[],42);
_Next = -7;
return this;
case -7:
this.setLatest(505,-7);
 // _t7 = Rune2Raw(42:rune) *ssa.Call @ langgoruntime.go:22:14 [REGISTER VALUE UN-USED]
this.setPH(506);
Go_haxegoruntime_StringCompare.call(this._goroutine,[],"X","Y");
_Next = -8;
return this;
case -8:
this.setLatest(506,-8);
 // _t8 = StringCompare("X":string, "Y":string) *ssa.Call @ langgoruntime.go:23:19 [REGISTER VALUE UN-USED]
this.setPH(508);
Go_utf16_Decode.call(this._goroutine,[],null);
_Next = -9;
return this;
case -9:
this.setLatest(508,-9);
 // _t9 = unicode/utf16.Decode(nil:[]uint16) *ssa.Call @ langgoruntime.go:25:18 [REGISTER VALUE UN-USED]
this.setPH(509);
Go_utf8_RuneCount.call(this._goroutine,[],null);
_Next = -10;
return this;
case -10:
this.setLatest(509,-10);
 // _t10 = unicode/utf8.RuneCount(nil:[]byte) *ssa.Call @ langgoruntime.go:26:20 [REGISTER VALUE UN-USED]
this.setPH(510);
_SF11=Go_utf8_DecodeRune.call(this._goroutine,[],null);
_Next = -11;
return this;
case -11:
this.setLatest(510,-11);
_t11=_SF11.res();
 // _t11 = unicode/utf8.DecodeRune(nil:[]byte) *ssa.Call @ langgoruntime.go:27:23
this.SubFn1();
this.setPH(511);
Go_utf16_Encode.call(this._goroutine,[],null);
_Next = -12;
return this;
case -12:
this.setLatest(511,-12);
 // _t14 = unicode/utf16.Encode(nil:[]rune) *ssa.Call @ langgoruntime.go:28:18 [REGISTER VALUE UN-USED]
this.setPH(512);
Go_utf8_RuneLen.call(this._goroutine,[],42);
_Next = -13;
return this;
case -13:
this.setLatest(512,-13);
 // _t15 = unicode/utf8.RuneLen(42:rune) *ssa.Call @ langgoruntime.go:29:18 [REGISTER VALUE UN-USED]
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near langgoruntime.go:29:18

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
 // _t0 = *ZiLen *ssa.UnOp near langgoruntime.go:29:18 [REGISTER VALUE UN-USED]
}// end SubFn0
private inline  function SubFn1():Void {
 // _t12 = extract t11 #0 *ssa.Extract near langgoruntime.go:29:18 [REGISTER VALUE UN-USED]
 // _t13 = extract t11 #1 *ssa.Extract near langgoruntime.go:29:18 [REGISTER VALUE UN-USED]
}// end SubFn1
}
#if js @:expose("Go_atomic_LoadUintptr") #end class Go_atomic_LoadUintptr extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:148:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,269,"Go_atomic_LoadUintptr");
this._bds=_bds;
this.p_addr=p_addr;
Scheduler.push(gr,this);
}
var _res:Dynamic;
public inline function res():Dynamic {return _res;}
var _t0:Dynamic=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer) : Dynamic {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_LoadUintptr(0,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer) : Dynamic {
var _sf=new Go_atomic_LoadUintptr(_gr,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) : Go_atomic_LoadUintptr
{return new Go_atomic_LoadUintptr(gr,_bds, p_addr);
}
public function run():Go_atomic_LoadUintptr {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(269,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:148:49

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:148:56
}// end SubFn0
}
#if js @:expose("Go_atomic_StoreUint64") #end class Go_atomic_StoreUint64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:163:6
var p_addr:Pointer;
var p_val:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : GOint64) {
super(gr,284,"Go_atomic_StoreUint64");
this._bds=_bds;
this.p_addr=p_addr;
this.p_val=p_val;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_val : GOint64) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_StoreUint64(0,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_val : GOint64) : Void {
var _sf=new Go_atomic_StoreUint64(_gr,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : GOint64) : Go_atomic_StoreUint64
{return new Go_atomic_StoreUint64(gr,_bds, p_addr, p_val);
}
public function run():Go_atomic_StoreUint64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(284,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:148:56

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:163:46
}// end SubFn0
}
#if js @:expose("Go_atomic_CompareAndSwapUint64") #end class Go_atomic_CompareAndSwapUint64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:79:6
var p_addr:Pointer;
var p_old:GOint64;
var p_new:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : GOint64, p_new : GOint64) {
super(gr,200,"Go_atomic_CompareAndSwapUint64");
this._bds=_bds;
this.p_addr=p_addr;
this.p_old=p_old;
this.p_new=p_new;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:GOint64=null;
var _t1:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_old : GOint64, p_new : GOint64) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_CompareAndSwapUint64(0,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_old : GOint64, p_new : GOint64) : Bool {
var _sf=new Go_atomic_CompareAndSwapUint64(_gr,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : GOint64, p_new : GOint64) : Go_atomic_CompareAndSwapUint64
{return new Go_atomic_CompareAndSwapUint64(gr,_bds, p_addr, p_old, p_new);
}
public function run():Go_atomic_CompareAndSwapUint64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(200,0);
this.SubFn0();

case 1: // if.then
this.setLatest(200,1);
this.SubFn1();
this.setPH(203);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:82:3

case 2: // if.done
this.setLatest(203,2);
this.setPH(205);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:84:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:GOint64;
var _t1:Bool;
this.setPH(201);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:80:5
_t1=(GOint64.ucompare(_t0,p_old)==0); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:80:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:80:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(202);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:81:3
}// end SubFn1
}
#if js @:expose("Go_atomic_LoadInt32") #end class Go_atomic_LoadInt32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:136:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,257,"Go_atomic_LoadInt32");
this._bds=_bds;
this.p_addr=p_addr;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_LoadInt32(0,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer) : Int {
var _sf=new Go_atomic_LoadInt32(_gr,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) : Go_atomic_LoadInt32
{return new Go_atomic_LoadInt32(gr,_bds, p_addr);
}
public function run():Go_atomic_LoadInt32 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(257,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:136:43

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=(p_addr.load()|0); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:136:50
}// end SubFn0
}
#if (!php) private #end class Go_main_func_64_83_dot_6 extends StackFrameBasis implements StackFrame {  // stateful.go:83:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,83,"Go_main_func_64_83_dot_6");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Pointer=null;
var _t1:Pointer=null;
var _SF1:StackFrame;
var _t2:Dynamic=null;
var _t3:Int=0;
var _t4:Pointer=null;
var _t5:Channel<Int>=null;
var _t6:Channel<Pointer>=null;
var _t7:Pointer=null;
var _t8:Channel<Int>=null;
var _SF4:StackFrame;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_main_func_64_83_dot_6(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_main_func_64_83_dot_6(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_main_func_64_83_dot_6
{return new Go_main_func_64_83_dot_6(gr,_bds);
}
public function run():Go_main_func_64_83_dot_6 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(83,0);
this.SubFn0();

case 1: // for.body
this.setLatest(83,1);
this.SubFn1();
this.setPH(86);
_t2=Std.random(5); // _t2 = github.com/tardisgo/tardisgo/tardisgolib.HAXE("Std.random(5);":string) *ssa.Call @ stateful.go:86:32
this.SubFn2();
this.setPH(88);
_Next=-2;
return this;
case -2:
this.setLatest(88,-2);
if(!_t6.hasSpace())return this;
_t6.send(_t0); // send t6 <- t0 *ssa.Send @ stateful.go:88:11
this.SubFn3();
this.setPH(89);
_Next=-3;
return this;
case -3:
this.setLatest(89,-3);
if(_t8.hasNoContents())return this;
_t8.receive(0).r0; // _t9 = <-t8 *ssa.UnOp @ stateful.go:89:5 [REGISTER VALUE UN-USED]
this.setPH(90);
Go_atomic_AddInt64.call(this._goroutine,[],_bds[1],GOint64.make(0x0,0x1));
_Next = -4;
return this;
case -4:
this.setLatest(90,-4);
 // _t10 = sync/atomic.AddInt64(ops, 1:int64) *ssa.Call @ stateful.go:90:20 [REGISTER VALUE UN-USED]
this.SubFn4();

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_Next=1; // jump 1.for.body *ssa.Jump near stateful.go:90:20
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(85);
_t0=new Pointer({var _v=new Array<Dynamic>();_v=[0,new Channel<Int>(1)]; _v;}); // _t0 = new readOp (complit) *ssa.Alloc @ stateful.go:85:20
_t1=_t0.addr(0);  // _t1 = &t0.key [#0] *ssa.FieldAddr near stateful.go:85:20 [POINTER]
}// end SubFn1
private inline  function SubFn2():Void {
var _t3:Int;
var _t4:Pointer;
var _t5:Channel<Int>;
this.setPH(86);
_t3=cast(_t2,Int); // _t3 = convert int <- uintptr (t2) *ssa.Convert @ stateful.go:86:15
_t1.store(_t3); // *t1 = t3 *ssa.Store near stateful.go:86:15
_t4=_t0.addr(1);  // _t4 = &t0.resp [#1] *ssa.FieldAddr near stateful.go:86:15 [POINTER]
this.setPH(87);
_t5=new Channel<Int>(0); // _t5 = make chan int 0:int *ssa.MakeChan @ stateful.go:87:16
_t4.store(_t5); // *t4 = t5 *ssa.Store near stateful.go:87:16
_t6=_bds[0].load(); // _t6 = *reads *ssa.UnOp near stateful.go:87:16
}// end SubFn2
private inline  function SubFn3():Void {
var _t7:Pointer;
this.setPH(89);
_t7=_t0.addr(1);  // _t7 = &t0.resp [#1] *ssa.FieldAddr @ stateful.go:89:12 [POINTER]
_t8=_t7.load(); // _t8 = *t7 *ssa.UnOp near stateful.go:89:12
}// end SubFn3
private inline  function SubFn4():Void {
_Next=1; // jump 1.for.body *ssa.Jump near stateful.go:89:12
}// end SubFn4
}
#if js @:expose("Go_utf8_DecodeRuneInString") #end class Go_utf8_DecodeRuneInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:229:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,961,"Go_utf8_DecodeRuneInString");
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
this.setLatest(961,0);
this.setPH(962);
_SF1=Go_utf8_decodeRuneInStringInternal.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(962,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInStringInternal(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:230:41
this.SubFn0();
this.setPH(963);
_res= {r0:_t1,r1:_t2};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1, t2 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2
 // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:231:2 [REGISTER VALUE UN-USED]
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_UTF8toRunes") #end class Go_haxegoruntime_UTF8toRunes extends StackFrameBasis implements StackFrame {  // langgoruntime.go:39:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,522,"Go_haxegoruntime_UTF8toRunes");
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
this.setLatest(522,0);
this.setPH(523);
_SF1=Go_utf8_RuneCount.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(523,-1);
_t0=_SF1.res();
 // _t0 = unicode/utf8.RuneCount(s) *ssa.Call @ langgoruntime.go:40:36
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(523,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(523,2);
this.setPH(534);
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ langgoruntime.go:51:2

case 3: // for.loop
this.setLatest(534,3);
this.setPH(524);
_t5=((_Phi==0)?0:(_Phi==6)?_t20:0); // _t5 = phi [0.entry: 0:int, 6.for.done: t20] #si *ssa.Phi @ langgoruntime.go:41:2
this.setPH(525);
_t6=((_Phi==0)?0:(_Phi==6)?_t21:0); // _t6 = phi [0.entry: 0:int, 6.for.done: t21] #ri *ssa.Phi @ langgoruntime.go:42:6
this.SubFn2();
_Phi=3;
case 4: // cond.true
this.setLatest(525,4);
this.SubFn3();
_Phi=4;
case 5: // for.body
this.setLatest(525,5);
this.SubFn4();
_Phi=5;
case 6: // for.done
this.setLatest(525,6);
this.setPH(530);
_SF2=Go_utf8_DecodeRune.call(this._goroutine,[],_t4);
_Next = -2;
return this;
case -2:
this.setLatest(530,-2);
_t16=_SF2.res();
 // _t16 = unicode/utf8.DecodeRune(t4) *ssa.Call @ langgoruntime.go:47:33
this.SubFn5();
_Phi=6;
case 7: // for.loop
this.setLatest(530,7);
this.setPH(527);
_t22=((_Phi==1)?0:(_Phi==5)?_t15:0); // _t22 = phi [1.for.body: 0:int, 5.for.body: t15] #j *ssa.Phi @ langgoruntime.go:44:7
this.SubFn6();
_Phi=7;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(523);
_t1=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t0) _v[_i]=0; _v;}),0,_t0); // _t1 = make []rune t0 t0 *ssa.MakeSlice @ langgoruntime.go:40:13
_Next=3; // jump 3.for.loop *ssa.Jump near langgoruntime.go:40:13
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Int;
var _t3:Int;
this.setPH(526);
_t2=({var _v=p_s;_v==null?0:_v.len();}); // _t2 = len(s) *ssa.Call @ langgoruntime.go:43:24
_t3=(_t2-_t5); // _t3 = t2 - t5 *ssa.BinOp @ langgoruntime.go:43:27
_t4=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t3) _v[_i]=0; _v;}),0,_t3); // _t4 = make []byte t3 t3 *ssa.MakeSlice @ langgoruntime.go:43:12
_Next=7; // jump 7.for.loop *ssa.Jump near langgoruntime.go:43:12
}// end SubFn1
private inline  function SubFn2():Void {
var _t7:Int;
var _t8:Bool;
this.setPH(525);
_t7=({var _v=p_s;_v==null?0:_v.len();}); // _t7 = len(s) *ssa.Call @ langgoruntime.go:42:23
_t8=(_t5<_t7); // _t8 = t5 < t7 *ssa.BinOp @ langgoruntime.go:42:18
_Next=_t8 ? 4 : 2; // if t8 goto 4.cond.true else 2.for.done *ssa.If near langgoruntime.go:42:18
}// end SubFn2
private inline  function SubFn3():Void {
var _t9:Int;
var _t10:Bool;
_t9=({var _v=_t1;_v==null?0:_v.len();}); // _t9 = len(t1) *ssa.Call @ langgoruntime.go:42:38
_t10=(_t6<_t9); // _t10 = t6 < t9 *ssa.BinOp @ langgoruntime.go:42:33
_Next=_t10 ? 1 : 2; // if t10 goto 1.for.body else 2.for.done *ssa.If near langgoruntime.go:42:33
}// end SubFn3
private inline  function SubFn4():Void {
var _t11:Pointer;
var _t12:Int;
var _t13:Pointer;
var _t14:Int;
this.setPH(528);
if((_t22<0)||(_t22>=_t4.len())) Scheduler.ioor(); // _t11 = &t4[t22] *ssa.IndexAddr @ langgoruntime.go:45:5 [POINTER]
_t11=_t4.addr(_t22);  // _t11 = &t4[t22] *ssa.IndexAddr @ langgoruntime.go:45:5 [POINTER]
_t12=(_t5+_t22); // _t12 = t5 + t22 *ssa.BinOp @ langgoruntime.go:45:15
if((_t12<0)||(_t12>=p_s.len())) Scheduler.ioor(); // _t13 = &s[t12] *ssa.IndexAddr @ langgoruntime.go:45:12 [POINTER]
_t13=p_s.addr(_t12);  // _t13 = &s[t12] *ssa.IndexAddr @ langgoruntime.go:45:12 [POINTER]
_t14=(_t13.load()|0); // _t14 = *t13 *ssa.UnOp near langgoruntime.go:45:12
_t11.store(_t14); // *t11 = t14 *ssa.Store near langgoruntime.go:45:12
_t15=(_t22+1); // _t15 = t22 + 1:int *ssa.BinOp near langgoruntime.go:45:12
_Next=7; // jump 7.for.loop *ssa.Jump near langgoruntime.go:45:12
}// end SubFn4
private inline  function SubFn5():Void {
var _t19:Pointer;
_t17=_t16.r0; // _t17 = extract t16 #0 *ssa.Extract near langgoruntime.go:45:12
_t18=_t16.r1; // _t18 = extract t16 #1 *ssa.Extract near langgoruntime.go:45:12
this.setPH(531);
if((_t6<0)||(_t6>=_t1.len())) Scheduler.ioor(); // _t19 = &t1[t6] *ssa.IndexAddr @ langgoruntime.go:48:6 [POINTER]
_t19=_t1.addr(_t6);  // _t19 = &t1[t6] *ssa.IndexAddr @ langgoruntime.go:48:6 [POINTER]
_t19.store(_t17); // *t19 = t17 *ssa.Store near langgoruntime.go:48:6
_t20=(_t5+_t18); // _t20 = t5 + t18 *ssa.BinOp near langgoruntime.go:48:6
_t21=(_t6+1); // _t21 = t6 + 1:int *ssa.BinOp near langgoruntime.go:48:6
_Next=3; // jump 3.for.loop *ssa.Jump near langgoruntime.go:48:6
}// end SubFn5
private inline  function SubFn6():Void {
var _t23:Int;
var _t24:Int;
var _t25:Bool;
this.setPH(527);
_t23=({var _v=p_s;_v==null?0:_v.len();}); // _t23 = len(s) *ssa.Call @ langgoruntime.go:44:23
_t24=(_t23-_t5); // _t24 = t23 - t5 *ssa.BinOp @ langgoruntime.go:44:27
_t25=(_t22<_t24); // _t25 = t22 < t24 *ssa.BinOp @ langgoruntime.go:44:17
_Next=_t25 ? 5 : 6; // if t25 goto 5.for.body else 6.for.done *ssa.If near langgoruntime.go:44:17
}// end SubFn6
}
#if js @:expose("Go_utf16_IsSurrogate") #end class Go_utf16_IsSurrogate extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:30:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,654,"Go_utf16_IsSurrogate");
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
this.setLatest(654,0);
this.SubFn0();
_Phi=0;
case 1: // binop.rhs
this.setLatest(654,1);
this.SubFn1();
_Phi=1;
case 2: // binop.done
this.setLatest(654,2);
this.setPH(655);
_t2=((_Phi==0)?false:(_Phi==1)?_t1:false); // _t2 = phi [0.entry: false:bool, 1.binop.rhs: t1] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:20
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=(55296<=p_r); // _t0 = 55296:rune <= r *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:15
_Next=_t0 ? 1 : 2; // if t0 goto 1.binop.rhs else 2.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:15
}// end SubFn0
private inline  function SubFn1():Void {
_t1=(p_r<57344); // _t1 = r < 57344:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:25
_Next=2; // jump 2.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:25
}// end SubFn1
}
#if js @:expose("Go_atomic_LoadUint64") #end class Go_atomic_LoadUint64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:145:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,266,"Go_atomic_LoadUint64");
this._bds=_bds;
this.p_addr=p_addr;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _t0:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_LoadUint64(0,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer) : GOint64 {
var _sf=new Go_atomic_LoadUint64(_gr,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) : Go_atomic_LoadUint64
{return new Go_atomic_LoadUint64(gr,_bds, p_addr);
}
public function run():Go_atomic_LoadUint64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(266,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:145:46

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:145:53
}// end SubFn0
}
#if js @:expose("Go_atomic_CompareAndSwapUintptr") #end class Go_atomic_CompareAndSwapUintptr extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:88:6
var p_addr:Pointer;
var p_old:Dynamic;
var p_new:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : Dynamic, p_new : Dynamic) {
super(gr,209,"Go_atomic_CompareAndSwapUintptr");
this._bds=_bds;
this.p_addr=p_addr;
this.p_old=p_old;
this.p_new=p_new;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:Dynamic=null;
var _t1:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_old : Dynamic, p_new : Dynamic) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_CompareAndSwapUintptr(0,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_old : Dynamic, p_new : Dynamic) : Bool {
var _sf=new Go_atomic_CompareAndSwapUintptr(_gr,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : Dynamic, p_new : Dynamic) : Go_atomic_CompareAndSwapUintptr
{return new Go_atomic_CompareAndSwapUintptr(gr,_bds, p_addr, p_old, p_new);
}
public function run():Go_atomic_CompareAndSwapUintptr {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(209,0);
this.SubFn0();

case 1: // if.then
this.setLatest(209,1);
this.SubFn1();
this.setPH(212);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:91:3

case 2: // if.done
this.setLatest(212,2);
this.setPH(214);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:93:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Dynamic;
var _t1:Bool;
this.setPH(210);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:89:5
_t1=(Force.uintCompare((_t0|0),(p_old|0))==0); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:89:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:89:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(211);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:90:3
}// end SubFn1
}
#if (!php) private #end class Go_main_main extends StackFrameBasis implements StackFrame {  // stateful.go:44:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,44,"Go_main_main");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Pointer=null;
var _t1:Pointer=null;
var _t2:Channel<Pointer>=null;
var _t3:Pointer=null;
var _t4:Channel<Pointer>=null;
var _t5:Closure=null;
var _t6:Closure=null;
var _t7:Int=0;
var _t8:Int=0;
var _t9:Bool=false;
var _t10:Closure=null;
var _t11:Int=0;
var _t12:Int=0;
var _t13:Bool=false;
var _SF1:StackFrame;
var _t15:Int=0;
var _SF2:StackFrame;
var _t16:GOint64=null;
var _t18:Int=0;
var _t19:Bool=false;
var _Phi:Int=0;
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
this.setLatest(44,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(44,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(44,2);
this.SubFn2();
_Phi=2;
case 3: // for.loop
this.setLatest(44,3);
this.setPH(82);
_t8=((_Phi==0)?0:(_Phi==1)?_t7:0); // _t8 = phi [0.entry: 0:int, 1.for.body: t7] #r *ssa.Phi @ stateful.go:82:6
this.SubFn3();
_Phi=3;
case 4: // for.body
this.setLatest(82,4);
this.SubFn4();
_Phi=4;
case 5: // for.done
this.setLatest(82,5);
this.SubFn5();
_Phi=5;
case 6: // for.loop
this.setLatest(82,6);
this.setPH(97);
_t12=((_Phi==2)?0:(_Phi==4)?_t11:0); // _t12 = phi [2.for.done: 0:int, 4.for.body: t11] #w *ssa.Phi @ stateful.go:97:6
this.SubFn6();
_Phi=6;
case 7: // for.body
this.setLatest(97,7);
this.setPH(114);
Go_tardisgolib_Gosched.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(114,-1);
 // _t14 = github.com/tardisgo/tardisgo/tardisgolib.Gosched() *ssa.Call @ stateful.go:114:22 [REGISTER VALUE UN-USED]
this.SubFn7();
_Phi=7;
case 8: // for.done
this.setLatest(114,8);
this.setPH(118);
_SF2=Go_atomic_LoadInt64.call(this._goroutine,[],_t0);
_Next = -2;
return this;
case -2:
this.setLatest(118,-2);
_t16=_SF2.res();
 // _t16 = sync/atomic.LoadInt64(t0) *ssa.Call @ stateful.go:118:30
this.SubFn8();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near stateful.go:118:30

case 9: // for.loop
this.setLatest(118,9);
this.setPH(113);
_t18=((_Phi==5)?0:(_Phi==7)?_t15:0); // _t18 = phi [5.for.done: 0:int, 7.for.body: t15] #i *ssa.Phi @ stateful.go:113:6
this.SubFn9();
_Phi=9;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t2:Channel<Pointer>;
var _t4:Channel<Pointer>;
var _t5:Closure;
this.setPH(47);
_t0=new Pointer(GOint64.make(0,0)); // _t0 = new int64 (ops) *ssa.Alloc @ stateful.go:47:6
_t0.store(GOint64.make(0x0,0x0)); // *t0 = 0:int64 *ssa.Store near stateful.go:47:6
this.setPH(52);
_t1=new Pointer(new Channel<Pointer>(1)); // _t1 = new chan *readOp (reads) *ssa.Alloc @ stateful.go:52:2
_t2=new Channel<Pointer>(0); // _t2 = make chan *main.readOp 0:int *ssa.MakeChan @ stateful.go:52:15
_t1.store(_t2); // *t1 = t2 *ssa.Store near stateful.go:52:15
this.setPH(53);
_t3=new Pointer(new Channel<Pointer>(1)); // _t3 = new chan *writeOp (writes) *ssa.Alloc @ stateful.go:53:2
_t4=new Channel<Pointer>(0); // _t4 = make chan *main.writeOp 0:int *ssa.MakeChan @ stateful.go:53:16
_t3.store(_t4); // *t3 = t4 *ssa.Store near stateful.go:53:16
_t5= new Closure(new Closure(Go_main_func_64_64_dot_5.call,[]),[_t1,_t3]); // _t5 = make closure func@64.5 [t1, t3] *ssa.MakeClosure near stateful.go:53:16
this.setPH(64);
Go_main_func_64_64_dot_5.call(Scheduler.makeGoroutine(),_t5.bds);  // go t5() *ssa.Go @ stateful.go:64:2
_Next=3; // jump 3.for.loop *ssa.Jump near stateful.go:64:2
}// end SubFn0
private inline  function SubFn1():Void {
var _t6:Closure;
_t6= new Closure(new Closure(Go_main_func_64_83_dot_6.call,[]),[_t1,_t0]); // _t6 = make closure func@83.6 [t1, t0] *ssa.MakeClosure near stateful.go:64:2
this.setPH(83);
Go_main_func_64_83_dot_6.call(Scheduler.makeGoroutine(),_t6.bds);  // go t6() *ssa.Go @ stateful.go:83:3
_t7=(_t8+1); // _t7 = t8 + 1:int *ssa.BinOp near stateful.go:83:3
_Next=3; // jump 3.for.loop *ssa.Jump near stateful.go:83:3
}// end SubFn1
private inline  function SubFn2():Void {
_Next=6; // jump 6.for.loop *ssa.Jump near stateful.go:83:3
}// end SubFn2
private inline  function SubFn3():Void {
var _t9:Bool;
this.setPH(82);
_t9=(_t8<100); // _t9 = t8 < 100:int *ssa.BinOp @ stateful.go:82:16
_Next=_t9 ? 1 : 2; // if t9 goto 1.for.body else 2.for.done *ssa.If near stateful.go:82:16
}// end SubFn3
private inline  function SubFn4():Void {
var _t10:Closure;
_t10= new Closure(new Closure(Go_main_func_64_98_dot_6.call,[]),[_t3,_t0]); // _t10 = make closure func@98.6 [t3, t0] *ssa.MakeClosure near stateful.go:82:16
this.setPH(98);
Go_main_func_64_98_dot_6.call(Scheduler.makeGoroutine(),_t10.bds);  // go t10() *ssa.Go @ stateful.go:98:3
_t11=(_t12+1); // _t11 = t12 + 1:int *ssa.BinOp near stateful.go:98:3
_Next=6; // jump 6.for.loop *ssa.Jump near stateful.go:98:3
}// end SubFn4
private inline  function SubFn5():Void {
_Next=9; // jump 9.for.loop *ssa.Jump near stateful.go:98:3
}// end SubFn5
private inline  function SubFn6():Void {
var _t13:Bool;
this.setPH(97);
_t13=(_t12<10); // _t13 = t12 < 10:int *ssa.BinOp @ stateful.go:97:16
_Next=_t13 ? 4 : 5; // if t13 goto 4.for.body else 5.for.done *ssa.If near stateful.go:97:16
}// end SubFn6
private inline  function SubFn7():Void {
_t15=(_t18+1); // _t15 = t18 + 1:int *ssa.BinOp near stateful.go:97:16
_Next=9; // jump 9.for.loop *ssa.Jump near stateful.go:97:16
}// end SubFn7
private inline  function SubFn8():Void {
this.setPH(120);
trace(Go.CPos(120),"ops:",_t16); // _t17 = println("ops:":string, t16) *ssa.Call @ stateful.go:120:9 [REGISTER VALUE UN-USED]
}// end SubFn8
private inline  function SubFn9():Void {
var _t19:Bool;
this.setPH(113);
_t19=(_t18<1000); // _t19 = t18 < 1000:int *ssa.BinOp @ stateful.go:113:16
_Next=_t19 ? 7 : 8; // if t19 goto 7.for.body else 8.for.done *ssa.If near stateful.go:113:16
}// end SubFn9
}
#if js @:expose("Go_utf8_DecodeLastRune") #end class Go_utf8_DecodeLastRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:239:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,971,"Go_utf8_DecodeLastRune");
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
this.setLatest(971,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(971,1);
this.setPH(974);
_res= {r0:65533,r1:0};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:242:3

case 2: // if.done
this.setLatest(974,2);
this.SubFn1();
_Phi=2;
case 3: // if.then
this.setLatest(974,3);
this.setPH(979);
_res= {r0:_t5,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:247:3

case 4: // if.done
this.setLatest(979,4);
this.SubFn2();
_Phi=4;
case 5: // if.then
this.setLatest(979,5);
this.SubFn3();
_Phi=5;
case 6: // if.done
this.setLatest(979,6);
this.setPH(984);
_t9=((_Phi==4)?_t7:(_Phi==5)?0:0); // _t9 = phi [4.if.done: t7, 5.if.then: 0:int] #lim *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:252:2
this.SubFn4();
_Phi=6;
case 7: // for.body
this.setLatest(984,7);
this.SubFn5();
this.setPH(989);
_SF1=Go_utf8_RuneStart.call(this._goroutine,[],_t12);
_Next = -1;
return this;
case -1:
this.setLatest(989,-1);
_t13=_SF1.res();
 // _t13 = RuneStart(t12) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:15
this.SubFn6();
_Phi=7;
case 8: // for.done
this.setLatest(989,8);
this.SubFn7();
_Phi=8;
case 9: // for.loop
this.setLatest(989,9);
this.setPH(976);
_t15=((_Phi==6)?_t10:(_Phi==10)?_t17:0); // _t15 = phi [6.if.done: t10, 10.if.done: t17] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:244:2
this.SubFn8();
_Phi=9;
case 10: // if.done
this.setLatest(976,10);
this.SubFn9();
_Phi=10;
case 11: // if.then
this.setLatest(976,11);
this.SubFn10();
_Phi=11;
case 12: // if.done
this.setLatest(976,12);
_t18=((_Phi==8)?_t15:(_Phi==11)?0:0); // _t18 = phi [8.for.done: t15, 11.if.then: 0:int] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:244:2
this.SubFn11();
this.setPH(996);
_SF2=Go_utf8_DecodeRune.call(this._goroutine,[],_t19);
_Next = -2;
return this;
case -2:
this.setLatest(996,-2);
_t20=_SF2.res();
 // _t20 = DecodeRune(t19) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:22
this.SubFn12();
_Phi=12;
case 13: // if.then
this.setLatest(996,13);
this.setPH(998);
_res= {r0:65533,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:266:3

case 14: // if.done
this.setLatest(998,14);
this.setPH(1000);
_res= {r0:_t21,r1:_t22};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t21, t22 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:268:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Bool;
this.setPH(972);
_t0=({var _v=p_p;_v==null?0:_v.len();}); // _t0 = len(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:240:12
this.setPH(973);
_t1=(_t0==0); // _t1 = t0 == 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:241:9
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:241:9
}// end SubFn0
private inline  function SubFn1():Void {
var _t3:Pointer;
var _t4:Int;
var _t6:Bool;
this.setPH(976);
_t2=(_t0-1); // _t2 = t0 - 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:244:15
this.setPH(977);
if((_t2<0)||(_t2>=p_p.len())) Scheduler.ioor(); // _t3 = &p[t2] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:12 [POINTER]
_t3=p_p.addr(_t2);  // _t3 = &p[t2] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:12 [POINTER]
_t4=(_t3.load()|0); // _t4 = *t3 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:12
_t5=_t4; // _t5 = convert rune <- byte (t4) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:10
this.setPH(978);
_t6=(_t5<128); // _t6 = t5 < 128:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:246:7
_Next=_t6 ? 3 : 4; // if t6 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:246:7
}// end SubFn1
private inline  function SubFn2():Void {
var _t8:Bool;
this.setPH(984);
_t7=(_t0-4); // _t7 = t0 - 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:252:13
this.setPH(985);
_t8=(_t7<0); // _t8 = t7 < 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:253:9
_Next=_t8 ? 5 : 6; // if t8 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:253:9
}// end SubFn2
private inline  function SubFn3():Void {
_Next=6; // jump 6.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:253:9
}// end SubFn3
private inline  function SubFn4():Void {
_t10=(_t2-1); // _t10 = t2 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:253:9
_Next=9; // jump 9.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:253:9
}// end SubFn4
private inline  function SubFn5():Void {
var _t11:Pointer;
this.setPH(989);
if((_t15<0)||(_t15>=p_p.len())) Scheduler.ioor(); // _t11 = &p[t15] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17 [POINTER]
_t11=p_p.addr(_t15);  // _t11 = &p[t15] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17 [POINTER]
_t12=(_t11.load()|0); // _t12 = *t11 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17
}// end SubFn5
private inline  function SubFn6():Void {
_Next=_t13 ? 8 : 10; // if t13 goto 8.for.done else 10.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17
}// end SubFn6
private inline  function SubFn7():Void {
var _t14:Bool;
this.setPH(993);
_t14=(_t15<0); // _t14 = t15 < 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:261:11
_Next=_t14 ? 11 : 12; // if t14 goto 11.if.then else 12.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:261:11
}// end SubFn7
private inline  function SubFn8():Void {
var _t16:Bool;
this.setPH(988);
_t16=(_t15>=_t9); // _t16 = t15 >= t9 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:256:21
_Next=_t16 ? 7 : 8; // if t16 goto 7.for.body else 8.for.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:256:21
}// end SubFn8
private inline  function SubFn9():Void {
_t17=(_t15-1); // _t17 = t15 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:256:21
_Next=9; // jump 9.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:256:21
}// end SubFn9
private inline  function SubFn10():Void {
_Next=12; // jump 12.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:256:21
}// end SubFn10
private inline  function SubFn11():Void {
this.setPH(996);
_t19=p_p.subSlice(_t18,_t0); // _t19 = slice p[t18:t0] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:24
}// end SubFn11
private inline  function SubFn12():Void {
var _t23:Int;
var _t24:Bool;
_t21=_t20.r0; // _t21 = extract t20 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:24
_t22=_t20.r1; // _t22 = extract t20 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:24
this.setPH(997);
_t23=(_t18+_t22); // _t23 = t18 + t22 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:265:10
_t24=(_t23!=_t0); // _t24 = t23 != t0 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:265:16
_Next=_t24 ? 13 : 14; // if t24 goto 13.if.then else 14.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:265:16
}// end SubFn12
}
#if js @:expose("Go_utf8_EncodeRune") #end class Go_utf8_EncodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:330:6
var p_p:Slice;
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice, p_r : Int) {
super(gr,1062,"Go_utf8_EncodeRune");
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
this.setLatest(1062,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(1062,1);
this.SubFn1();
this.setPH(1066);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:334:3

case 2: // if.done
this.setLatest(1066,2);
this.SubFn2();
_Phi=2;
case 3: // if.then
this.setLatest(1066,3);
this.SubFn3();
this.setPH(1072);
_res= 2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 2:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:340:3

case 4: // if.done
this.setLatest(1072,4);
this.SubFn4();
_Phi=4;
case 5: // if.then
this.setLatest(1072,5);
this.SubFn5();
_Phi=5;
case 6: // if.done
this.setLatest(1072,6);
this.setPH(1062);
_t16=((_Phi==4)?p_r:(_Phi==5)?65533:0); // _t16 = phi [4.if.done: r, 5.if.then: 65533:rune] #r *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:330:27
this.SubFn6();
_Phi=6;
case 7: // if.then
this.setLatest(1062,7);
this.SubFn7();
_Phi=7;
case 8: // if.done
this.setLatest(1062,8);
_t18=((_Phi==6)?_t16:(_Phi==9)?_t16:(_Phi==7)?65533:0); // _t18 = phi [6.if.done: t16, 9.cond.true: t16, 7.if.then: 65533:rune] #r *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:330:27
this.SubFn8();
_Phi=8;
case 9: // cond.true
this.setLatest(1062,9);
this.SubFn9();
_Phi=9;
case 10: // if.then
this.setLatest(1062,10);
this.SubFn10();
this.setPH(1087);
_res= 3;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 3:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:355:3

case 11: // if.done
this.setLatest(1087,11);
this.SubFn11();
this.setPH(1094);
_res= 4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 4:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:362:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
var _t1:Bool;
this.setPH(1064);
_t0=p_r; // _t0 = convert uint32 <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:332:11
_t1=(Force.uintCompare(_t0,127)<=0); // _t1 = t0 <= 127:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:332:15
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:332:15
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Pointer;
var _t3:Int;
this.setPH(1065);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:4 [POINTER]
_t2=p_p.addr(0);  // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:4 [POINTER]
_t3=p_r; // _t3 = convert byte <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:14
_t2.store(_t3); // *t2 = t3 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:14
}// end SubFn1
private inline  function SubFn2():Void {
var _t4:Int;
var _t5:Bool;
this.setPH(1069);
_t4=p_r; // _t4 = convert uint32 <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:337:11
_t5=(Force.uintCompare(_t4,2047)<=0); // _t5 = t4 <= 2047:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:337:15
_Next=_t5 ? 3 : 4; // if t5 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:337:15
}// end SubFn2
private inline  function SubFn3():Void {
var _t6:Pointer;
var _t7:Int;
var _t8:Int;
var _t9:Int;
var _t10:Pointer;
var _t11:Int;
var _t12:Int;
var _t13:Int;
this.setPH(1070);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t6 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:4 [POINTER]
_t6=p_p.addr(0);  // _t6 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:4 [POINTER]
_t7=(p_r>>GOint64.toInt(GOint64.make(0x0,0x6))); // _t7 = r >> 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:21
_t8=_t7; // _t8 = convert byte <- rune (t7) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:19
_t9=Force.toUint8((192|_t8)); // _t9 = 192:byte | t8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:13
_t6.store(_t9); // *t6 = t9 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:13
this.setPH(1071);
if((1<0)||(1>=p_p.len())) Scheduler.ioor(); // _t10 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:4 [POINTER]
_t10=p_p.addr(1);  // _t10 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:4 [POINTER]
_t11=p_r; // _t11 = convert byte <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:19
_t12=Force.toUint8((_t11&63)); // _t12 = t11 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:22
_t13=Force.toUint8((128|_t12)); // _t13 = 128:byte | t12 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:13
_t10.store(_t13); // *t10 = t13 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:339:13
}// end SubFn3
private inline  function SubFn4():Void {
var _t14:Int;
var _t15:Bool;
this.setPH(1075);
_t14=p_r; // _t14 = convert uint32 <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:11
_t15=(Force.uintCompare(_t14,1114111)>0); // _t15 = t14 > 1114111:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:15
_Next=_t15 ? 5 : 6; // if t15 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:15
}// end SubFn4
private inline  function SubFn5():Void {
_Next=6; // jump 6.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:15
}// end SubFn5
private inline  function SubFn6():Void {
var _t17:Bool;
this.setPH(1079);
_t17=(55296<=_t16); // _t17 = 55296:rune <= t16 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:18
_Next=_t17 ? 9 : 8; // if t17 goto 9.cond.true else 8.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:18
}// end SubFn6
private inline  function SubFn7():Void {
_Next=8; // jump 8.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:18
}// end SubFn7
private inline  function SubFn8():Void {
var _t19:Int;
var _t20:Bool;
this.setPH(1083);
_t19=_t18; // _t19 = convert uint32 <- rune (t18) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:351:11
_t20=(Force.uintCompare(_t19,65535)<=0); // _t20 = t19 <= 65535:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:351:15
_Next=_t20 ? 10 : 11; // if t20 goto 10.if.then else 11.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:351:15
}// end SubFn8
private inline  function SubFn9():Void {
var _t21:Bool;
this.setPH(1079);
_t21=(_t16<=57343); // _t21 = t16 <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:28
_Next=_t21 ? 7 : 8; // if t21 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:28
}// end SubFn9
private inline  function SubFn10():Void {
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
this.setPH(1084);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t22 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:4 [POINTER]
_t22=p_p.addr(0);  // _t22 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:4 [POINTER]
_t23=(_t18>>GOint64.toInt(GOint64.make(0x0,0xc))); // _t23 = t18 >> 12:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:21
_t24=_t23; // _t24 = convert byte <- rune (t23) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:19
_t25=Force.toUint8((224|_t24)); // _t25 = 224:byte | t24 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:13
_t22.store(_t25); // *t22 = t25 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:13
this.setPH(1085);
if((1<0)||(1>=p_p.len())) Scheduler.ioor(); // _t26 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:4 [POINTER]
_t26=p_p.addr(1);  // _t26 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:4 [POINTER]
_t27=(_t18>>GOint64.toInt(GOint64.make(0x0,0x6))); // _t27 = t18 >> 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:21
_t28=_t27; // _t28 = convert byte <- rune (t27) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:19
_t29=Force.toUint8((_t28&63)); // _t29 = t28 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:25
_t30=Force.toUint8((128|_t29)); // _t30 = 128:byte | t29 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:13
_t26.store(_t30); // *t26 = t30 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:13
this.setPH(1086);
if((2<0)||(2>=p_p.len())) Scheduler.ioor(); // _t31 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:4 [POINTER]
_t31=p_p.addr(2);  // _t31 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:4 [POINTER]
_t32=_t18; // _t32 = convert byte <- rune (t18) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:19
_t33=Force.toUint8((_t32&63)); // _t33 = t32 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:22
_t34=Force.toUint8((128|_t33)); // _t34 = 128:byte | t33 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:13
_t31.store(_t34); // *t31 = t34 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:354:13
}// end SubFn10
private inline  function SubFn11():Void {
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
this.setPH(1090);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t35 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:3 [POINTER]
_t35=p_p.addr(0);  // _t35 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:3 [POINTER]
_t36=(_t18>>GOint64.toInt(GOint64.make(0x0,0x12))); // _t36 = t18 >> 18:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:20
_t37=_t36; // _t37 = convert byte <- rune (t36) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:18
_t38=Force.toUint8((240|_t37)); // _t38 = 240:byte | t37 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:12
_t35.store(_t38); // *t35 = t38 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:12
this.setPH(1091);
if((1<0)||(1>=p_p.len())) Scheduler.ioor(); // _t39 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:3 [POINTER]
_t39=p_p.addr(1);  // _t39 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:3 [POINTER]
_t40=(_t18>>GOint64.toInt(GOint64.make(0x0,0xc))); // _t40 = t18 >> 12:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:20
_t41=_t40; // _t41 = convert byte <- rune (t40) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:18
_t42=Force.toUint8((_t41&63)); // _t42 = t41 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:25
_t43=Force.toUint8((128|_t42)); // _t43 = 128:byte | t42 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:12
_t39.store(_t43); // *t39 = t43 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:12
this.setPH(1092);
if((2<0)||(2>=p_p.len())) Scheduler.ioor(); // _t44 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:3 [POINTER]
_t44=p_p.addr(2);  // _t44 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:3 [POINTER]
_t45=(_t18>>GOint64.toInt(GOint64.make(0x0,0x6))); // _t45 = t18 >> 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:20
_t46=_t45; // _t46 = convert byte <- rune (t45) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:18
_t47=Force.toUint8((_t46&63)); // _t47 = t46 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:24
_t48=Force.toUint8((128|_t47)); // _t48 = 128:byte | t47 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:12
_t44.store(_t48); // *t44 = t48 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:12
this.setPH(1093);
if((3<0)||(3>=p_p.len())) Scheduler.ioor(); // _t49 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:3 [POINTER]
_t49=p_p.addr(3);  // _t49 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:3 [POINTER]
_t50=_t18; // _t50 = convert byte <- rune (t18) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:18
_t51=Force.toUint8((_t50&63)); // _t51 = t50 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:21
_t52=Force.toUint8((128|_t51)); // _t52 = 128:byte | t51 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:12
_t49.store(_t52); // *t49 = t52 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:12
}// end SubFn11
}
#if js @:expose("Go_utf16_Encode") #end class Go_utf16_Encode extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:56:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,680,"Go_utf16_Encode");
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
this.setLatest(680,0);
this.SubFn0();
_Phi=0;
case 1: // rangeindex.loop
this.setLatest(680,1);
this.setPH(681);
_t2=((_Phi==0)?_t0:(_Phi==2)?_t2:(_Phi==4)?_t11:0); // _t2 = phi [0.entry: t0, 2.rangeindex.body: t2, 4.if.then: t11] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
_t3=((_Phi==0)?(-1):(_Phi==2)?_t4:(_Phi==4)?_t4:0); // _t3 = phi [0.entry: -1:int, 2.rangeindex.body: t4, 4.if.then: t4] *ssa.Phi near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
this.SubFn1();
_Phi=1;
case 2: // rangeindex.body
this.setLatest(681,2);
this.SubFn2();
_Phi=2;
case 3: // rangeindex.done
this.setLatest(681,3);
this.SubFn3();
_Phi=3;
case 4: // if.then
this.setLatest(681,4);
this.SubFn4();
_Phi=4;
case 5: // rangeindex.loop
this.setLatest(681,5);
_t12=((_Phi==3)?0:(_Phi==9)?_t23:(_Phi==15)?_t37:0); // _t12 = phi [3.rangeindex.done: 0:int, 9.switch.body: t23, 15.switch.next: t37] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
_t13=((_Phi==3)?(-1):(_Phi==9)?_t14:(_Phi==15)?_t14:0); // _t13 = phi [3.rangeindex.done: -1:int, 9.switch.body: t14, 15.switch.next: t14] *ssa.Phi near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
this.SubFn5();
_Phi=5;
case 6: // rangeindex.body
this.setLatest(681,6);
this.SubFn6();
_Phi=6;
case 7: // rangeindex.done
this.setLatest(681,7);
this.SubFn7();
this.setPH(705);
_res= _t19;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t19 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:81:2

case 8: // switch.body
this.setLatest(705,8);
this.SubFn8();
_Phi=8;
case 9: // switch.body
this.setLatest(705,9);
this.setPH(690);
_t20=((_Phi==8)?65533:(_Phi==14)?_t17:0); // _t20 = phi [8.switch.body: 65533:rune, 14.switch.next: t17] #v *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:66:9
this.SubFn9();
_Phi=9;
case 10: // switch.next
this.setLatest(690,10);
this.SubFn10();
_Phi=10;
case 11: // switch.next
this.setLatest(690,11);
this.SubFn11();
_Phi=11;
case 12: // binop.rhs
this.setLatest(690,12);
this.SubFn12();
_Phi=12;
case 13: // binop.done
this.setLatest(690,13);
this.setPH(692);
_t27=((_Phi==10)?false:(_Phi==12)?_t26:false); // _t27 = phi [10.switch.next: false:bool, 12.binop.rhs: t26] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:26
this.SubFn13();
_Phi=13;
case 14: // switch.next
this.setLatest(692,14);
this.SubFn14();
_Phi=14;
case 15: // switch.next
this.setLatest(692,15);
this.setPH(699);
_SF1=Go_utf16_EncodeRune.call(this._goroutine,[],_t17);
_Next = -1;
return this;
case -1:
this.setLatest(699,-1);
_t29=_SF1.res();
 // _t29 = EncodeRune(t17) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:75:24
this.SubFn15();
_Phi=15;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(681);
_t0=({var _v=p_s;_v==null?0:_v.len();}); // _t0 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
_t1=({var _v=p_s;_v==null?0:_v.len();}); // _t1 = len(s) *ssa.Call near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
}// end SubFn0
private inline  function SubFn1():Void {
var _t5:Bool;
_t4=(_t3+1); // _t4 = t3 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
_t5=(_t4<_t1); // _t5 = t4 < t1 *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
_Next=_t5 ? 2 : 3; // if t5 goto 2.rangeindex.body else 3.rangeindex.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
}// end SubFn1
private inline  function SubFn2():Void {
var _t6:Pointer;
var _t8:Bool;
if((_t4<0)||(_t4>=p_s.len())) Scheduler.ioor(); // _t6 = &s[t4] *ssa.IndexAddr near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10 [POINTER]
_t6=p_s.addr(_t4);  // _t6 = &s[t4] *ssa.IndexAddr near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10 [POINTER]
_t7=(_t6.load()|0); // _t7 = *t6 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:10
this.setPH(683);
_t8=(_t7>=65536); // _t8 = t7 >= 65536:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:59:8
_Next=_t8 ? 4 : 1; // if t8 goto 4.if.then else 1.rangeindex.loop *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:59:8
}// end SubFn2
private inline  function SubFn3():Void {
this.setPH(688);
_t9=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t2) _v[_i]=0; _v;}),0,_t2); // _t9 = make []uint16 t2 t2 *ssa.MakeSlice @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
_t10=({var _v=p_s;_v==null?0:_v.len();}); // _t10 = len(s) *ssa.Call near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
_Next=5; // jump 5.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
}// end SubFn3
private inline  function SubFn4():Void {
_t11=(_t2+1); // _t11 = t2 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
}// end SubFn4
private inline  function SubFn5():Void {
var _t15:Bool;
_t14=(_t13+1); // _t14 = t13 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
_t15=(_t14<_t10); // _t15 = t14 < t10 *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
_Next=_t15 ? 6 : 7; // if t15 goto 6.rangeindex.body else 7.rangeindex.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
}// end SubFn5
private inline  function SubFn6():Void {
var _t16:Pointer;
var _t18:Bool;
if((_t14<0)||(_t14>=p_s.len())) Scheduler.ioor(); // _t16 = &s[t14] *ssa.IndexAddr near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11 [POINTER]
_t16=p_s.addr(_t14);  // _t16 = &s[t14] *ssa.IndexAddr near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11 [POINTER]
_t17=(_t16.load()|0); // _t17 = *t16 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:64:11
this.setPH(692);
_t18=(_t17<0); // _t18 = t17 < 0:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:10
_Next=_t18 ? 8 : 10; // if t18 goto 8.switch.body else 10.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:10
}// end SubFn6
private inline  function SubFn7():Void {
this.setPH(705);
_t19=_t9.subSlice(0,_t12); // _t19 = slice t9[0:int:t12] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:81:10
}// end SubFn7
private inline  function SubFn8():Void {
_Next=9; // jump 9.switch.body *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:81:10
}// end SubFn8
private inline  function SubFn9():Void {
var _t21:Pointer;
var _t22:Int;
this.setPH(696);
if((_t12<0)||(_t12>=_t9.len())) Scheduler.ioor(); // _t21 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:5 [POINTER]
_t21=_t9.addr(_t12);  // _t21 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:5 [POINTER]
_t22=_t20; // _t22 = convert uint16 <- rune (t20) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
_t21.store(_t22); // *t21 = t22 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
_t23=(_t12+1); // _t23 = t12 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
_Next=5; // jump 5.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
}// end SubFn9
private inline  function SubFn10():Void {
var _t24:Bool;
this.setPH(692);
_t24=(55296<=_t17); // _t24 = 55296:rune <= t17 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:21
_Next=_t24 ? 12 : 13; // if t24 goto 12.binop.rhs else 13.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:21
}// end SubFn10
private inline  function SubFn11():Void {
var _t25:Bool;
_t25=(_t17>1114111); // _t25 = t17 > 1114111:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:42
_Next=_t25 ? 8 : 14; // if t25 goto 8.switch.body else 14.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:42
}// end SubFn11
private inline  function SubFn12():Void {
_t26=(_t17<57344); // _t26 = t17 < 57344:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:31
_Next=13; // jump 13.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:31
}// end SubFn12
private inline  function SubFn13():Void {
_Next=_t27 ? 8 : 11; // if t27 goto 8.switch.body else 11.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:31
}// end SubFn13
private inline  function SubFn14():Void {
var _t28:Bool;
this.setPH(695);
_t28=(_t17<65536); // _t28 = t17 < 65536:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:71:10
_Next=_t28 ? 9 : 15; // if t28 goto 9.switch.body else 15.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:71:10
}// end SubFn14
private inline  function SubFn15():Void {
var _t32:Pointer;
var _t33:Int;
var _t34:Int;
var _t35:Pointer;
var _t36:Int;
_t30=_t29.r0; // _t30 = extract t29 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf16/utf16.go:71:10
_t31=_t29.r1; // _t31 = extract t29 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf16/utf16.go:71:10
this.setPH(700);
if((_t12<0)||(_t12>=_t9.len())) Scheduler.ioor(); // _t32 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:5 [POINTER]
_t32=_t9.addr(_t12);  // _t32 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:5 [POINTER]
_t33=_t30; // _t33 = convert uint16 <- rune (t30) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:17
_t32.store(_t33); // *t32 = t33 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:17
this.setPH(701);
_t34=(_t12+1); // _t34 = t12 + 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:7
if((_t34<0)||(_t34>=_t9.len())) Scheduler.ioor(); // _t35 = &t9[t34] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:5 [POINTER]
_t35=_t9.addr(_t34);  // _t35 = &t9[t34] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:5 [POINTER]
_t36=_t31; // _t36 = convert uint16 <- rune (t31) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
_t35.store(_t36); // *t35 = t36 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
_t37=(_t12+2); // _t37 = t12 + 2:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
_Next=5; // jump 5.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
}// end SubFn15
}
#if js @:expose("Go_atomic_LoadPointer") #end class Go_atomic_LoadPointer extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:151:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,272,"Go_atomic_LoadPointer");
this._bds=_bds;
this.p_addr=p_addr;
Scheduler.push(gr,this);
}
var _res:UnsafePointer;
public inline function res():Dynamic {return _res;}
var _t0:UnsafePointer=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer) : UnsafePointer {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_LoadPointer(0,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer) : UnsafePointer {
var _sf=new Go_atomic_LoadPointer(_gr,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) : Go_atomic_LoadPointer
{return new Go_atomic_LoadPointer(gr,_bds, p_addr);
}
public function run():Go_atomic_LoadPointer {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(272,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:151:63

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:151:70
}// end SubFn0
}
#if js @:expose("Go_atomic_CompareAndSwapUint32") #end class Go_atomic_CompareAndSwapUint32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:70:6
var p_addr:Pointer;
var p_old:Int;
var p_new:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : Int, p_new : Int) {
super(gr,191,"Go_atomic_CompareAndSwapUint32");
this._bds=_bds;
this.p_addr=p_addr;
this.p_old=p_old;
this.p_new=p_new;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_old : Int, p_new : Int) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_CompareAndSwapUint32(0,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_old : Int, p_new : Int) : Bool {
var _sf=new Go_atomic_CompareAndSwapUint32(_gr,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : Int, p_new : Int) : Go_atomic_CompareAndSwapUint32
{return new Go_atomic_CompareAndSwapUint32(gr,_bds, p_addr, p_old, p_new);
}
public function run():Go_atomic_CompareAndSwapUint32 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(191,0);
this.SubFn0();

case 1: // if.then
this.setLatest(191,1);
this.SubFn1();
this.setPH(194);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:73:3

case 2: // if.done
this.setLatest(194,2);
this.setPH(196);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:75:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
var _t1:Bool;
this.setPH(192);
_t0=(p_addr.load()|0); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:71:5
_t1=(Force.uintCompare(_t0,p_old)==0); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:71:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:71:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(193);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:72:3
}// end SubFn1
}
#if (!php) private #end class Go_main_func_64_98_dot_6 extends StackFrameBasis implements StackFrame {  // stateful.go:98:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,98,"Go_main_func_64_98_dot_6");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Pointer=null;
var _t1:Pointer=null;
var _SF1:StackFrame;
var _t2:Dynamic=null;
var _t3:Int=0;
var _t4:Pointer=null;
var _SF2:StackFrame;
var _t5:Dynamic=null;
var _t6:Int=0;
var _t7:Pointer=null;
var _t8:Channel<Bool>=null;
var _t9:Channel<Pointer>=null;
var _t10:Pointer=null;
var _t11:Channel<Bool>=null;
var _SF5:StackFrame;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_main_func_64_98_dot_6(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_main_func_64_98_dot_6(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_main_func_64_98_dot_6
{return new Go_main_func_64_98_dot_6(gr,_bds);
}
public function run():Go_main_func_64_98_dot_6 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(98,0);
this.SubFn0();

case 1: // for.body
this.setLatest(98,1);
this.SubFn1();
this.setPH(101);
_t2=Std.random(5); // _t2 = github.com/tardisgo/tardisgo/tardisgolib.HAXE("Std.random(5);":string) *ssa.Call @ stateful.go:101:32
this.SubFn2();
this.setPH(102);
_t5=Std.random(100); // _t5 = github.com/tardisgo/tardisgo/tardisgolib.HAXE("Std.random(100);":string) *ssa.Call @ stateful.go:102:32
this.SubFn3();
this.setPH(104);
_Next=-3;
return this;
case -3:
this.setLatest(104,-3);
if(!_t9.hasSpace())return this;
_t9.send(_t0); // send t9 <- t0 *ssa.Send @ stateful.go:104:12
this.SubFn4();
this.setPH(105);
_Next=-4;
return this;
case -4:
this.setLatest(105,-4);
if(_t11.hasNoContents())return this;
_t11.receive(false).r0; // _t12 = <-t11 *ssa.UnOp @ stateful.go:105:5 [REGISTER VALUE UN-USED]
this.setPH(106);
Go_atomic_AddInt64.call(this._goroutine,[],_bds[1],GOint64.make(0x0,0x1));
_Next = -5;
return this;
case -5:
this.setLatest(106,-5);
 // _t13 = sync/atomic.AddInt64(ops, 1:int64) *ssa.Call @ stateful.go:106:20 [REGISTER VALUE UN-USED]
this.SubFn5();

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_Next=1; // jump 1.for.body *ssa.Jump near stateful.go:106:20
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(100);
_t0=new Pointer({var _v=new Array<Dynamic>();_v=[0,0,new Channel<Bool>(1)]; _v;}); // _t0 = new writeOp (complit) *ssa.Alloc @ stateful.go:100:22
_t1=_t0.addr(0);  // _t1 = &t0.key [#0] *ssa.FieldAddr near stateful.go:100:22 [POINTER]
}// end SubFn1
private inline  function SubFn2():Void {
var _t3:Int;
this.setPH(101);
_t3=cast(_t2,Int); // _t3 = convert int <- uintptr (t2) *ssa.Convert @ stateful.go:101:15
_t1.store(_t3); // *t1 = t3 *ssa.Store near stateful.go:101:15
_t4=_t0.addr(1);  // _t4 = &t0.val [#1] *ssa.FieldAddr near stateful.go:101:15 [POINTER]
}// end SubFn2
private inline  function SubFn3():Void {
var _t6:Int;
var _t7:Pointer;
var _t8:Channel<Bool>;
this.setPH(102);
_t6=cast(_t5,Int); // _t6 = convert int <- uintptr (t5) *ssa.Convert @ stateful.go:102:15
_t4.store(_t6); // *t4 = t6 *ssa.Store near stateful.go:102:15
_t7=_t0.addr(2);  // _t7 = &t0.resp [#2] *ssa.FieldAddr near stateful.go:102:15 [POINTER]
this.setPH(103);
_t8=new Channel<Bool>(0); // _t8 = make chan bool 0:int *ssa.MakeChan @ stateful.go:103:16
_t7.store(_t8); // *t7 = t8 *ssa.Store near stateful.go:103:16
_t9=_bds[0].load(); // _t9 = *writes *ssa.UnOp near stateful.go:103:16
}// end SubFn3
private inline  function SubFn4():Void {
var _t10:Pointer;
this.setPH(105);
_t10=_t0.addr(2);  // _t10 = &t0.resp [#2] *ssa.FieldAddr @ stateful.go:105:13 [POINTER]
_t11=_t10.load(); // _t11 = *t10 *ssa.UnOp near stateful.go:105:13
}// end SubFn4
private inline  function SubFn5():Void {
_Next=1; // jump 1.for.body *ssa.Jump near stateful.go:105:13
}// end SubFn5
}
#if js @:expose("Go_haxegoruntime_Runes2Raw") #end class Go_haxegoruntime_Runes2Raw extends StackFrameBasis implements StackFrame {  // langgoruntime.go:91:6
var p_r:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Slice) {
super(gr,574,"Go_haxegoruntime_Runes2Raw");
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
var _t18:Pointer=null;
var _t19:Slice=null;
var _t20:Int=0;
var _t21:Int=0;
var _t22:Bool=false;
var _t23:Pointer=null;
var _t24:Pointer=null;
var _t25:Int=0;
var _t26:Int=0;
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
this.setLatest(574,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(574,1);
this.setPH(577);
_SF1=Go_haxegoruntime_RunesToUTF16.call(this._goroutine,[],p_r);
_Next = -1;
return this;
case -1:
this.setLatest(577,-1);
_t2=_SF1.res();
 // _t2 = RunesToUTF16(r) *ssa.Call @ langgoruntime.go:94:29
this.SubFn1();
_Phi=1;
case 2: // switch.body
this.setLatest(577,2);
this.setPH(584);
_SF2=Go_haxegoruntime_RunesToUTF8.call(this._goroutine,[],p_r);
_Next = -2;
return this;
case -2:
this.setLatest(584,-2);
_t6=_SF2.res();
 // _t6 = RunesToUTF8(r) *ssa.Call @ langgoruntime.go:101:27
this.SubFn2();
_Phi=2;
case 3: // switch.next
this.setLatest(584,3);
this.SubFn3();
_Phi=3;
case 4: // rangeindex.loop
this.setLatest(584,4);
_t11=((_Phi==1)?(-1):(_Phi==5)?_t12:0); // _t11 = phi [1.switch.body: -1:int, 5.rangeindex.body: t12] *ssa.Phi near langgoruntime.go:101:27
this.SubFn4();
_Phi=4;
case 5: // rangeindex.body
this.setLatest(584,5);
this.SubFn5();
_Phi=5;
case 6: // rangeindex.done
this.setLatest(584,6);
this.setPH(582);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ langgoruntime.go:99:3

case 7: // switch.next
this.setLatest(582,7);
this.SubFn6();
this.setPH(593);
_res= _t19;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t19 *ssa.Return @ langgoruntime.go:110:2

case 8: // rangeindex.loop
this.setLatest(593,8);
_t20=((_Phi==2)?(-1):(_Phi==9)?_t21:0); // _t20 = phi [2.switch.body: -1:int, 9.rangeindex.body: t21] *ssa.Phi near langgoruntime.go:110:2
this.SubFn7();
_Phi=8;
case 9: // rangeindex.body
this.setLatest(593,9);
this.SubFn8();
_Phi=9;
case 10: // rangeindex.done
this.setLatest(593,10);
this.setPH(589);
_res= _t8;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t8 *ssa.Return @ langgoruntime.go:106:3

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Bool;
_t0=(Go.haxegoruntime_ZiLen.load()|0); // _t0 = *ZiLen *ssa.UnOp near langgoruntime.go:106:3
_t1=(Force.uintCompare(_t0,1)==0); // _t1 = t0 == 1:uint *ssa.BinOp near langgoruntime.go:106:3
_Next=_t1 ? 1 : 3; // if t1 goto 1.switch.body else 3.switch.next *ssa.If near langgoruntime.go:106:3
}// end SubFn0
private inline  function SubFn1():Void {
var _t3:Int;
this.setPH(578);
_t3=({var _v=_t2;_v==null?0:_v.len();}); // _t3 = len(t2) *ssa.Call @ langgoruntime.go:95:39
_t4=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t3) _v[_i]=0; _v;}),0,_t3); // _t4 = make []int t3 t3 *ssa.MakeSlice @ langgoruntime.go:95:28
_t5=({var _v=_t2;_v==null?0:_v.len();}); // _t5 = len(t2) *ssa.Call near langgoruntime.go:95:28
_Next=4; // jump 4.rangeindex.loop *ssa.Jump near langgoruntime.go:95:28
}// end SubFn1
private inline  function SubFn2():Void {
var _t7:Int;
this.setPH(585);
_t7=({var _v=_t6;_v==null?0:_v.len();}); // _t7 = len(t6) *ssa.Call @ langgoruntime.go:102:39
_t8=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t7) _v[_i]=0; _v;}),0,_t7); // _t8 = make []int t7 t7 *ssa.MakeSlice @ langgoruntime.go:102:28
_t9=({var _v=_t6;_v==null?0:_v.len();}); // _t9 = len(t6) *ssa.Call near langgoruntime.go:102:28
_Next=8; // jump 8.rangeindex.loop *ssa.Jump near langgoruntime.go:102:28
}// end SubFn2
private inline  function SubFn3():Void {
var _t10:Bool;
_t10=(Force.uintCompare(_t0,3)==0); // _t10 = t0 == 3:uint *ssa.BinOp near langgoruntime.go:102:28
_Next=_t10 ? 2 : 7; // if t10 goto 2.switch.body else 7.switch.next *ssa.If near langgoruntime.go:102:28
}// end SubFn3
private inline  function SubFn4():Void {
var _t13:Bool;
_t12=(_t11+1); // _t12 = t11 + 1:int *ssa.BinOp near langgoruntime.go:102:28
_t13=(_t12<_t5); // _t13 = t12 < t5 *ssa.BinOp near langgoruntime.go:102:28
_Next=_t13 ? 5 : 6; // if t13 goto 5.rangeindex.body else 6.rangeindex.done *ssa.If near langgoruntime.go:102:28
}// end SubFn4
private inline  function SubFn5():Void {
var _t14:Pointer;
var _t15:Pointer;
var _t16:Int;
var _t17:Int;
this.setPH(580);
if((_t12<0)||(_t12>=_t4.len())) Scheduler.ioor(); // _t14 = &t4[t12] *ssa.IndexAddr @ langgoruntime.go:97:12 [POINTER]
_t14=_t4.addr(_t12);  // _t14 = &t4[t12] *ssa.IndexAddr @ langgoruntime.go:97:12 [POINTER]
if((_t12<0)||(_t12>=_t2.len())) Scheduler.ioor(); // _t15 = &t2[t12] *ssa.IndexAddr @ langgoruntime.go:97:36 [POINTER]
_t15=_t2.addr(_t12);  // _t15 = &t2[t12] *ssa.IndexAddr @ langgoruntime.go:97:36 [POINTER]
_t16=(_t15.load()|0); // _t16 = *t15 *ssa.UnOp near langgoruntime.go:97:36
_t17=_t16; // _t17 = convert int <- uint16 (t16) *ssa.Convert @ langgoruntime.go:97:25
_t14.store(_t17); // *t14 = t17 *ssa.Store near langgoruntime.go:97:25
_Next=4; // jump 4.rangeindex.loop *ssa.Jump near langgoruntime.go:97:25
}// end SubFn5
private inline  function SubFn6():Void {
var _t18:Pointer;
this.setPH(593);
_t18=new Pointer({var _v=new Array<Int>();for(_vi in 0...0){_v[_vi]=0;}; _v;}); // _t18 = new [0]int (slicelit) *ssa.Alloc @ langgoruntime.go:110:14
_t19=new Slice(_t18,0,-1); // _t19 = slice t18[:] *ssa.Slice @ langgoruntime.go:110:14
}// end SubFn6
private inline  function SubFn7():Void {
var _t22:Bool;
_t21=(_t20+1); // _t21 = t20 + 1:int *ssa.BinOp near langgoruntime.go:110:14
_t22=(_t21<_t9); // _t22 = t21 < t9 *ssa.BinOp near langgoruntime.go:110:14
_Next=_t22 ? 9 : 10; // if t22 goto 9.rangeindex.body else 10.rangeindex.done *ssa.If near langgoruntime.go:110:14
}// end SubFn7
private inline  function SubFn8():Void {
var _t23:Pointer;
var _t24:Pointer;
var _t25:Int;
var _t26:Int;
this.setPH(587);
if((_t21<0)||(_t21>=_t8.len())) Scheduler.ioor(); // _t23 = &t8[t21] *ssa.IndexAddr @ langgoruntime.go:104:12 [POINTER]
_t23=_t8.addr(_t21);  // _t23 = &t8[t21] *ssa.IndexAddr @ langgoruntime.go:104:12 [POINTER]
if((_t21<0)||(_t21>=_t6.len())) Scheduler.ioor(); // _t24 = &t6[t21] *ssa.IndexAddr @ langgoruntime.go:104:35 [POINTER]
_t24=_t6.addr(_t21);  // _t24 = &t6[t21] *ssa.IndexAddr @ langgoruntime.go:104:35 [POINTER]
_t25=(_t24.load()|0); // _t25 = *t24 *ssa.UnOp near langgoruntime.go:104:35
_t26=_t25; // _t26 = convert int <- byte (t25) *ssa.Convert @ langgoruntime.go:104:25
_t23.store(_t26); // *t23 = t26 *ssa.Store near langgoruntime.go:104:25
_Next=8; // jump 8.rangeindex.loop *ssa.Jump near langgoruntime.go:104:25
}// end SubFn8
}
#if js @:expose("Go_atomic_LoadInt64") #end class Go_atomic_LoadInt64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:139:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,260,"Go_atomic_LoadInt64");
this._bds=_bds;
this.p_addr=p_addr;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _t0:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_LoadInt64(0,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer) : GOint64 {
var _sf=new Go_atomic_LoadInt64(_gr,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) : Go_atomic_LoadInt64
{return new Go_atomic_LoadInt64(gr,_bds, p_addr);
}
public function run():Go_atomic_LoadInt64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(260,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:139:43

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:139:50
}// end SubFn0
}
#if (!php) private #end class Go_atomic_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,260,"Go_atomic_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_atomic_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_atomic_init
{return new Go_atomic_init(gr,_bds);
}
public function run():Go_atomic_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(260,0);
this.SubFn0();

case 1: // init.start
this.setLatest(260,1);
this.SubFn1();

case 2: // init.done
this.setLatest(260,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:139:50

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.atomic_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:139:50
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:139:50
}// end SubFn0
private inline  function SubFn1():Void {
Go.atomic_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:139:50
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:139:50
}// end SubFn1
}
#if js @:expose("Go_tardisgolib_Platform") #end class Go_tardisgolib_Platform extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:19:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,460,"Go_tardisgolib_Platform");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_tardisgolib_Platform(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_tardisgolib_Platform(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_tardisgolib_Platform
{return new Go_tardisgolib_Platform(gr,_bds);
}
public function run():Go_tardisgolib_Platform {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(460,0);
_res= "go";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "go":string *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:19:26

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_utf16_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,460,"Go_utf16_init");
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
this.setLatest(460,0);
this.SubFn0();

case 1: // init.start
this.setLatest(460,1);
this.SubFn1();

case 2: // init.done
this.setLatest(460,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:19:26

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.utf16_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:19:26
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:19:26
}// end SubFn0
private inline  function SubFn1():Void {
Go.utf16_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:19:26
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:19:26
}// end SubFn1
}
#if js @:expose("Go_atomic_CompareAndSwapInt32") #end class Go_atomic_CompareAndSwapInt32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:52:6
var p_addr:Pointer;
var p_old:Int;
var p_new:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : Int, p_new : Int) {
super(gr,173,"Go_atomic_CompareAndSwapInt32");
this._bds=_bds;
this.p_addr=p_addr;
this.p_old=p_old;
this.p_new=p_new;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_old : Int, p_new : Int) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_CompareAndSwapInt32(0,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_old : Int, p_new : Int) : Bool {
var _sf=new Go_atomic_CompareAndSwapInt32(_gr,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : Int, p_new : Int) : Go_atomic_CompareAndSwapInt32
{return new Go_atomic_CompareAndSwapInt32(gr,_bds, p_addr, p_old, p_new);
}
public function run():Go_atomic_CompareAndSwapInt32 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(173,0);
this.SubFn0();

case 1: // if.then
this.setLatest(173,1);
this.SubFn1();
this.setPH(176);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:55:3

case 2: // if.done
this.setLatest(176,2);
this.setPH(178);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:57:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
var _t1:Bool;
this.setPH(174);
_t0=(p_addr.load()|0); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:53:5
_t1=(_t0==p_old); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:53:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:53:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(175);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:54:3
}// end SubFn1
}
#if js @:expose("Go_atomic_AddInt64") #end class Go_atomic_AddInt64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:118:6
var p_addr:Pointer;
var p_delta:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : GOint64) {
super(gr,239,"Go_atomic_AddInt64");
this._bds=_bds;
this.p_addr=p_addr;
this.p_delta=p_delta;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _t0:GOint64=null;
var _t1:GOint64=null;
var _t2:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_delta : GOint64) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_AddInt64(0,[], p_addr, p_delta).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_delta : GOint64) : GOint64 {
var _sf=new Go_atomic_AddInt64(_gr,[], p_addr, p_delta).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : GOint64) : Go_atomic_AddInt64
{return new Go_atomic_AddInt64(gr,_bds, p_addr, p_delta);
}
public function run():Go_atomic_AddInt64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(239,0);
this.SubFn0();
this.setPH(241);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:120:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:GOint64;
var _t1:GOint64;
this.setPH(240);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:119:2
_t1=Force.toInt64(GOint64.add(_t0,p_delta)); // _t1 = t0 + delta *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:119:2
p_addr.store(_t1); // *addr = t1 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:119:2
this.setPH(241);
_t2=p_addr.load(); // _t2 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:120:9
}// end SubFn0
}
#if js @:expose("Go_utf8_DecodeRune") #end class Go_utf8_DecodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:219:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,951,"Go_utf8_DecodeRune");
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
this.setLatest(951,0);
this.setPH(952);
_SF1=Go_utf8_decodeRuneInternal.call(this._goroutine,[],p_p);
_Next = -1;
return this;
case -1:
this.setLatest(952,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInternal(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:220:33
this.SubFn0();
this.setPH(953);
_res= {r0:_t1,r1:_t2};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1, t2 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:221:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:221:2
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:221:2
 // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:221:2 [REGISTER VALUE UN-USED]
}// end SubFn0
}
#if js @:expose("Go_atomic_CompareAndSwapInt64") #end class Go_atomic_CompareAndSwapInt64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:61:6
var p_addr:Pointer;
var p_old:GOint64;
var p_new:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : GOint64, p_new : GOint64) {
super(gr,182,"Go_atomic_CompareAndSwapInt64");
this._bds=_bds;
this.p_addr=p_addr;
this.p_old=p_old;
this.p_new=p_new;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:GOint64=null;
var _t1:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_old : GOint64, p_new : GOint64) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_CompareAndSwapInt64(0,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_old : GOint64, p_new : GOint64) : Bool {
var _sf=new Go_atomic_CompareAndSwapInt64(_gr,[], p_addr, p_old, p_new).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : GOint64, p_new : GOint64) : Go_atomic_CompareAndSwapInt64
{return new Go_atomic_CompareAndSwapInt64(gr,_bds, p_addr, p_old, p_new);
}
public function run():Go_atomic_CompareAndSwapInt64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(182,0);
this.SubFn0();

case 1: // if.then
this.setLatest(182,1);
this.SubFn1();
this.setPH(185);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:64:3

case 2: // if.done
this.setLatest(185,2);
this.setPH(187);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:66:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:GOint64;
var _t1:Bool;
this.setPH(183);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:62:5
_t1=(GOint64.compare(_t0,p_old)==0); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:62:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:62:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(184);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:63:3
}// end SubFn1
}
#if js @:expose("Go_tardisgolib_HAXE") #end class Go_tardisgolib_HAXE extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:12:6
var p_code:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_code : String) {
super(gr,453,"Go_tardisgolib_HAXE");
this._bds=_bds;
this.p_code=p_code;
Scheduler.push(gr,this);
}
var _res:Dynamic;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( p_code : String) : Dynamic {
if(!Go.doneInit) Go.init();
var _sf=new Go_tardisgolib_HAXE(0,[], p_code).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_code : String) : Dynamic {
var _sf=new Go_tardisgolib_HAXE(_gr,[], p_code).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_code : String) : Go_tardisgolib_HAXE
{return new Go_tardisgolib_HAXE(gr,_bds, p_code);
}
public function run():Go_tardisgolib_HAXE {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(453,0);
_res= 0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:uintptr *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:12:40

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_main_func_64_64_dot_5 extends StackFrameBasis implements StackFrame {  // stateful.go:64:5
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,64,"Go_main_func_64_64_dot_5");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Pointer=null;
var _t1:Channel<Pointer>=null;
var _t2:Channel<Pointer>=null;
var _t3:{r0:Int,r1:Bool,r2:Pointer,r3:Pointer}=null;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:Pointer=null;
var _t7:Pointer=null;
var _t8:Channel<Int>=null;
var _t9:Array<Int>=null;
var _t10:Pointer=null;
var _t11:Int=0;
var _t12:Int=0;
var _t13:Bool=false;
var _t14:Pointer=null;
var _t15:Pointer=null;
var _t16:Int=0;
var _t17:Pointer=null;
var _t18:Pointer=null;
var _t19:Int=0;
var _t20:Pointer=null;
var _t21:Channel<Bool>=null;
var _t22:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_main_func_64_64_dot_5(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_main_func_64_64_dot_5(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_main_func_64_64_dot_5
{return new Go_main_func_64_64_dot_5(gr,_bds);
}
public function run():Go_main_func_64_64_dot_5 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(64,0);
this.SubFn0();

case 1: // for.body
this.setLatest(64,1);
this.SubFn1();
this.setPH(67);
_Next=-1;
return this;
case -1:
this.setLatest(67,-1);
_t3={r0:0,r1:false,r2:new Pointer(null),r3:new Pointer(null)};
_t3.r0= -1;
{ var _states:Array<Bool> = new Array(); var _rnd=Std.random(2);
_states[0]=_t1.hasContents();
_states[1]=_t2.hasContents();
for(_s in 0...2) {var _i=(_s+_rnd)%2; if(_states[_i]) {_t3.r0=_i; break;};}
switch(_t3.r0){case 0:
{ var _v=_t1.receive(new Pointer(null)); _t3.r2= _v.r0; _t3.r1= _v.r1; }
case 1:
{ var _v=_t2.receive(new Pointer(null)); _t3.r3= _v.r0; _t3.r1= _v.r1; }
};}
if(_t3.r0 == -1) return this;
 // _t3 = select blocking [<-t1, <-t2] *ssa.Select @ stateful.go:67:4
this.SubFn2();

case 2: // select.body
this.setLatest(67,2);
this.SubFn3();
this.setPH(69);
_Next=-2;
return this;
case -2:
this.setLatest(69,-2);
if(!_t8.hasSpace())return this;
_t8.send(_t12); // send t8 <- t12 *ssa.Send @ stateful.go:69:15
this.SubFn4();

case 3: // select.next
this.setLatest(69,3);
this.SubFn5();

case 4: // select.body
this.setLatest(69,4);
this.SubFn6();
this.setPH(72);
_Next=-3;
return this;
case -3:
this.setLatest(72,-3);
if(!_t21.hasSpace())return this;
_t21.send(true); // send t21 <- true:bool *ssa.Send @ stateful.go:72:16
this.SubFn7();

case 5: // select.next
this.setLatest(72,5);
this.SubFn8();
Scheduler.panic(this._goroutine,_t22);_Next = -4;
return this;
case -4:
this.setLatest(72,-4);
 // panic t22 *ssa.Panic near stateful.go:72:16

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(65);
_t0=new Pointer({var _v=new Array<Int>();for(_vi in 0...100){_v[_vi]=0;}; _v;}); // _t0 = local [100]int (state) *ssa.Alloc @ stateful.go:65:7
_Next=1; // jump 1.for.body *ssa.Jump near stateful.go:65:7
}// end SubFn0
private inline  function SubFn1():Void {
_t1=_bds[0].load(); // _t1 = *reads *ssa.UnOp near stateful.go:65:7
_t2=_bds[1].load(); // _t2 = *writes *ssa.UnOp near stateful.go:65:7
}// end SubFn1
private inline  function SubFn2():Void {
var _t5:Bool;
_t4=_t3.r0; // _t4 = extract t3 #0 *ssa.Extract near stateful.go:65:7
_t5=(_t4==0); // _t5 = t4 == 0:int *ssa.BinOp near stateful.go:65:7
_Next=_t5 ? 2 : 3; // if t5 goto 2.select.body else 3.select.next *ssa.If near stateful.go:65:7
}// end SubFn2
private inline  function SubFn3():Void {
var _t7:Pointer;
var _t9:Array<Int>;
var _t10:Pointer;
var _t11:Int;
_t6=_t3.r2; // _t6 = extract t3 #2 *ssa.Extract near stateful.go:65:7
this.setPH(69);
_t7=_t6.addr(1);  // _t7 = &t6.resp [#1] *ssa.FieldAddr @ stateful.go:69:10 [POINTER]
_t8=_t7.load(); // _t8 = *t7 *ssa.UnOp near stateful.go:69:10
_t9=_t0.load(); // _t9 = *t0 *ssa.UnOp near stateful.go:69:10
_t10=_t6.addr(0);  // _t10 = &t6.key [#0] *ssa.FieldAddr @ stateful.go:69:29 [POINTER]
_t11=(_t10.load()|0); // _t11 = *t10 *ssa.UnOp near stateful.go:69:29
if((_t11<0)||(_t11>=100)) Scheduler.ioor();
_t12=_t9[_t11]; // _t12 = t9[t11] *ssa.Index @ stateful.go:69:23
}// end SubFn3
private inline  function SubFn4():Void {
_Next=1; // jump 1.for.body *ssa.Jump near stateful.go:69:23
}// end SubFn4
private inline  function SubFn5():Void {
var _t13:Bool;
_t13=(_t4==1); // _t13 = t4 == 1:int *ssa.BinOp near stateful.go:69:23
_Next=_t13 ? 4 : 5; // if t13 goto 4.select.body else 5.select.next *ssa.If near stateful.go:69:23
}// end SubFn5
private inline  function SubFn6():Void {
var _t15:Pointer;
var _t16:Int;
var _t17:Pointer;
var _t18:Pointer;
var _t19:Int;
var _t20:Pointer;
_t14=_t3.r3; // _t14 = extract t3 #3 *ssa.Extract near stateful.go:69:23
this.setPH(71);
_t15=_t14.addr(0);  // _t15 = &t14.key [#0] *ssa.FieldAddr @ stateful.go:71:17 [POINTER]
_t16=(_t15.load()|0); // _t16 = *t15 *ssa.UnOp near stateful.go:71:17
if((_t16<0)||(_t16>=100)) Scheduler.ioor(); // _t17 = &t0[t16] *ssa.IndexAddr @ stateful.go:71:10 [POINTER]
_t17=_t0.addr(_t16);  // _t17 = &t0[t16] *ssa.IndexAddr @ stateful.go:71:10 [POINTER]
_t18=_t14.addr(1);  // _t18 = &t14.val [#1] *ssa.FieldAddr @ stateful.go:71:30 [POINTER]
_t19=(_t18.load()|0); // _t19 = *t18 *ssa.UnOp near stateful.go:71:30
_t17.store(_t19); // *t17 = t19 *ssa.Store near stateful.go:71:30
this.setPH(72);
_t20=_t14.addr(2);  // _t20 = &t14.resp [#2] *ssa.FieldAddr @ stateful.go:72:11 [POINTER]
_t21=_t20.load(); // _t21 = *t20 *ssa.UnOp near stateful.go:72:11
}// end SubFn6
private inline  function SubFn7():Void {
_Next=1; // jump 1.for.body *ssa.Jump near stateful.go:72:11
}// end SubFn7
private inline  function SubFn8():Void {
_t22=new Interface(0,"blocking select matched no case"); // _t22 = make interface{} <- string ("blocking select m...":string) *ssa.MakeInterface near stateful.go:72:11
}// end SubFn8
}
#if js @:expose("Go_atomic_LoadUint32") #end class Go_atomic_LoadUint32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:142:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,263,"Go_atomic_LoadUint32");
this._bds=_bds;
this.p_addr=p_addr;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_LoadUint32(0,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer) : Int {
var _sf=new Go_atomic_LoadUint32(_gr,[], p_addr).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) : Go_atomic_LoadUint32
{return new Go_atomic_LoadUint32(gr,_bds, p_addr);
}
public function run():Go_atomic_LoadUint32 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(263,0);
this.SubFn0();
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:142:46

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=(p_addr.load()|0); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:142:53
}// end SubFn0
}
#if js @:expose("Go_tardisgolib_CPos") #end class Go_tardisgolib_CPos extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:22:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,463,"Go_tardisgolib_CPos");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_tardisgolib_CPos(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_tardisgolib_CPos(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_tardisgolib_CPos
{return new Go_tardisgolib_CPos(gr,_bds);
}
public function run():Go_tardisgolib_CPos {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(463,0);
_res= "<<go code pos>>";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "<<go code pos>>":string *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:22:22

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_haxegoruntime_RunesToUTF16") #end class Go_haxegoruntime_RunesToUTF16 extends StackFrameBasis implements StackFrame {  // langgoruntime.go:75:6
var p_r:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Slice) {
super(gr,558,"Go_haxegoruntime_RunesToUTF16");
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
this.setLatest(558,0);
this.setPH(559);
_SF1=Go_utf16_Encode.call(this._goroutine,[],p_r);
_Next = -1;
return this;
case -1:
this.setLatest(559,-1);
_t0=_SF1.res();
 // _t0 = unicode/utf16.Encode(r) *ssa.Call @ langgoruntime.go:76:21
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ langgoruntime.go:76:2

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_atomic_AddInt32") #end class Go_atomic_AddInt32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:106:6
var p_addr:Pointer;
var p_delta:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : Int) {
super(gr,227,"Go_atomic_AddInt32");
this._bds=_bds;
this.p_addr=p_addr;
this.p_delta=p_delta;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Int=0;
var _t2:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_delta : Int) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_AddInt32(0,[], p_addr, p_delta).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_delta : Int) : Int {
var _sf=new Go_atomic_AddInt32(_gr,[], p_addr, p_delta).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : Int) : Go_atomic_AddInt32
{return new Go_atomic_AddInt32(gr,_bds, p_addr, p_delta);
}
public function run():Go_atomic_AddInt32 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(227,0);
this.SubFn0();
this.setPH(229);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:108:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
var _t1:Int;
this.setPH(228);
_t0=(p_addr.load()|0); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:107:2
_t1=Force.toInt32((_t0+p_delta)); // _t1 = t0 + delta *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:107:2
p_addr.store(_t1); // *addr = t1 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:107:2
this.setPH(229);
_t2=(p_addr.load()|0); // _t2 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:108:9
}// end SubFn0
}
#if js @:expose("Go_atomic_AddUint64") #end class Go_atomic_AddUint64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:124:6
var p_addr:Pointer;
var p_delta:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : GOint64) {
super(gr,245,"Go_atomic_AddUint64");
this._bds=_bds;
this.p_addr=p_addr;
this.p_delta=p_delta;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _t0:GOint64=null;
var _t1:GOint64=null;
var _t2:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_delta : GOint64) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_AddUint64(0,[], p_addr, p_delta).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_delta : GOint64) : GOint64 {
var _sf=new Go_atomic_AddUint64(_gr,[], p_addr, p_delta).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : GOint64) : Go_atomic_AddUint64
{return new Go_atomic_AddUint64(gr,_bds, p_addr, p_delta);
}
public function run():Go_atomic_AddUint64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(245,0);
this.SubFn0();
this.setPH(247);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:126:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:GOint64;
var _t1:GOint64;
this.setPH(246);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:125:2
_t1=Force.toUint64(GOint64.add(_t0,p_delta)); // _t1 = t0 + delta *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:125:2
p_addr.store(_t1); // *addr = t1 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:125:2
this.setPH(247);
_t2=p_addr.load(); // _t2 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:126:9
}// end SubFn0
}
#if js @:expose("Go_tardisgolib_StringsUTF8") #end class Go_tardisgolib_StringsUTF8 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:29:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,470,"Go_tardisgolib_StringsUTF8");
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
var _sf=new Go_tardisgolib_StringsUTF8(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : Bool {
var _sf=new Go_tardisgolib_StringsUTF8(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_tardisgolib_StringsUTF8
{return new Go_tardisgolib_StringsUTF8(gr,_bds);
}
public function run():Go_tardisgolib_StringsUTF8 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(470,0);
_t0='字'.length; // _t0 = Zilen() *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:29:39
this.SubFn0();
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:29:27

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=(Force.uintCompare(_t0,3)==0); // _t1 = t0 == 3:uint *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:29:42
}// end SubFn0
}
#if js @:expose("Go_utf8_ValidString") #end class Go_utf8_ValidString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:415:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,1147,"Go_utf8_ValidString");
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
this.setLatest(1147,0);
this.SubFn0();

case 1: // rangeiter.loop
this.setLatest(1147,1);
this.SubFn1();

case 2: // rangeiter.body
this.setLatest(1147,2);
this.SubFn2();

case 3: // rangeiter.done
this.setLatest(1147,3);
this.setPH(1160);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:428:2

case 4: // if.then
this.setLatest(1160,4);
this.SubFn3();
this.setPH(1154);
_SF1=Go_utf8_DecodeRuneInString.call(this._goroutine,[],_t6);
_Next = -1;
return this;
case -1:
this.setLatest(1154,-1);
_t7=_SF1.res();
 // _t7 = DecodeRuneInString(t6) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:33
this.SubFn4();

case 5: // if.then
this.setLatest(1154,5);
this.setPH(1156);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:424:5

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(1148);
_t0={k:0,v:Force.toUTF8slice(this._goroutine,p_s)}; // _t0 = range s *ssa.Range @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
_Next=1; // jump 1.rangeiter.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Bool;
_t1={var _thisK:Int=_t0.k;if(_t0.k>=_t0.v.len()){r0:false,r1:0,r2:0};else {var _dr:{r0:Int,r1:Int}=Go_utf8_DecodeRune.callFromRT(this._goroutine,_t0.v.subSlice(_thisK,-1));_t0.k+=_dr.r1;{r0:true,r1:cast(_thisK,Int),r2:cast(_dr.r0,Int)};}}; // _t1 = next t0 *ssa.Next near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
_t2=_t1.r0; // _t2 = extract t1 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
_Next=_t2 ? 2 : 3; // if t2 goto 2.rangeiter.body else 3.rangeiter.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
}// end SubFn1
private inline  function SubFn2():Void {
var _t5:Bool;
_t3=_t1.r1; // _t3 = extract t1 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
_t4=_t1.r2; // _t4 = extract t1 #2 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:416:2
this.setPH(1149);
_t5=(_t4==65533); // _t5 = t4 == 65533:int32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:417:8
_Next=_t5 ? 4 : 1; // if t5 goto 4.if.then else 1.rangeiter.loop *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:417:8
}// end SubFn2
private inline  function SubFn3():Void {
this.setPH(1154);
_t6=Force.toRawString(this._goroutine,Force.toUTF8slice(this._goroutine,p_s).subSlice(_t3,-1)); // _t6 = slice s[t3:] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:35
}// end SubFn3
private inline  function SubFn4():Void {
var _t10:Bool;
 // _t8 = extract t7 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:35 [REGISTER VALUE UN-USED]
_t9=_t7.r1; // _t9 = extract t7 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:35
this.setPH(1155);
_t10=(_t9==1); // _t10 = t9 == 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:423:12
_Next=_t10 ? 5 : 1; // if t10 goto 5.if.then else 1.rangeiter.loop *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:423:12
}// end SubFn4
}
#if js @:expose("Go_utf8_FullRune") #end class Go_utf8_FullRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:203:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,935,"Go_utf8_FullRune");
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
this.setLatest(935,0);
this.setPH(936);
_SF1=Go_utf8_decodeRuneInternal.call(this._goroutine,[],p_p);
_Next = -1;
return this;
case -1:
this.setLatest(936,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInternal(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:204:35
this.SubFn0();
this.setPH(937);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:205:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
 // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:205:2 [REGISTER VALUE UN-USED]
 // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:205:2 [REGISTER VALUE UN-USED]
_t3=_t0.r2; // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:205:2
_t4=(!_t3); // _t4 = !t3 *ssa.UnOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:205:9
}// end SubFn0
}
#if js @:expose("Go_utf8_RuneCount") #end class Go_utf8_RuneCount extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:367:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,1099,"Go_utf8_RuneCount");
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
this.setLatest(1099,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(1099,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(1099,2);
this.setPH(1110);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:378:2

case 3: // for.loop
this.setLatest(1110,3);
this.setPH(1100);
_t3=((_Phi==0)?0:(_Phi==5)?_t9:0); // _t3 = phi [0.entry: 0:int, 5.if.done: t9] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:368:2
this.setPH(1101);
_t4=((_Phi==0)?0:(_Phi==5)?_t11:0); // _t4 = phi [0.entry: 0:int, 5.if.done: t11] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:369:6
this.setPH(1106);
_t5=((_Phi==0)?0:(_Phi==5)?_t10:0); // _t5 = phi [0.entry: 0:int, 5.if.done: t10] #size *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:7
this.SubFn2();
_Phi=3;
case 4: // if.then
this.setLatest(1106,4);
this.SubFn3();
_Phi=4;
case 5: // if.done
this.setLatest(1106,5);
this.setPH(1100);
_t9=((_Phi==4)?_t8:(_Phi==6)?_t16:0); // _t9 = phi [4.if.then: t8, 6.if.else: t16] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:368:2
this.setPH(1106);
_t10=((_Phi==4)?_t5:(_Phi==6)?_t15:0); // _t10 = phi [4.if.then: t5, 6.if.else: t15] #size *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:7
this.SubFn4();
_Phi=5;
case 6: // if.else
this.setLatest(1106,6);
this.SubFn5();
_SF1=Go_utf8_DecodeRune.call(this._goroutine,[],_t12);
_Next = -1;
return this;
case -1:
this.setLatest(1106,-1);
_t13=_SF1.res();
 // _t13 = DecodeRune(t12) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:25
this.SubFn6();
_Phi=6;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:25
}// end SubFn0
private inline  function SubFn1():Void {
var _t0:Pointer;
var _t1:Int;
var _t2:Bool;
this.setPH(1103);
if((_t3<0)||(_t3>=p_p.len())) Scheduler.ioor(); // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:7 [POINTER]
_t0=p_p.addr(_t3);  // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:7 [POINTER]
_t1=(_t0.load()|0); // _t1 = *t0 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:7
_t2=(Force.uintCompare(_t1,128)<0); // _t2 = t1 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:11
_Next=_t2 ? 4 : 6; // if t2 goto 4.if.then else 6.if.else *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:11
}// end SubFn1
private inline  function SubFn2():Void {
var _t6:Int;
var _t7:Bool;
this.setPH(1102);
_t6=({var _v=p_p;_v==null?0:_v.len();}); // _t6 = len(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:20
_t7=(_t3<_t6); // _t7 = t3 < t6 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
_Next=_t7 ? 1 : 2; // if t7 goto 1.for.body else 2.for.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
}// end SubFn2
private inline  function SubFn3():Void {
_t8=(_t3+1); // _t8 = t3 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
_Next=5; // jump 5.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
}// end SubFn3
private inline  function SubFn4():Void {
_t11=(_t4+1); // _t11 = t4 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:370:15
}// end SubFn4
private inline  function SubFn5():Void {
this.setPH(1106);
_t12=p_p.subSlice(_t3,-1); // _t12 = slice p[t3:] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
}// end SubFn5
private inline  function SubFn6():Void {
 // _t14 = extract t13 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27 [REGISTER VALUE UN-USED]
_t15=_t13.r1; // _t15 = extract t13 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
_t16=(_t3+_t15); // _t16 = t3 + t15 *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
_Next=5; // jump 5.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
}// end SubFn6
}
#if js @:expose("Go_utf16_Decode") #end class Go_utf16_Decode extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:86:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,710,"Go_utf16_Decode");
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
this.setLatest(710,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(710,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(710,2);
this.SubFn2();
this.setPH(731);
_res= _t5;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:107:2

case 3: // for.loop
this.setLatest(731,3);
this.setPH(712);
_t6=((_Phi==0)?0:(_Phi==4)?_t10:0); // _t6 = phi [0.entry: 0:int, 4.switch.done: t10] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:88:2
this.setPH(713);
_t7=((_Phi==0)?0:(_Phi==4)?_t12:0); // _t7 = phi [0.entry: 0:int, 4.switch.done: t12] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:6
this.SubFn3();
_Phi=3;
case 4: // switch.done
this.setLatest(713,4);
this.setPH(712);
_t10=((_Phi==5)?_t21:(_Phi==6)?_t23:(_Phi==13)?_t40:0); // _t10 = phi [5.switch.body: t21, 6.switch.body: t23, 13.switch.next: t40] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:88:2
this.setPH(713);
_t11=((_Phi==5)?_t20:(_Phi==6)?_t7:(_Phi==13)?_t7:0); // _t11 = phi [5.switch.body: t20, 6.switch.body: t7, 13.switch.next: t7] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:6
this.SubFn4();
_Phi=4;
case 5: // switch.body
this.setLatest(713,5);
this.SubFn5();
this.setPH(718);
_SF1=Go_utf16_DecodeRune.call(this._goroutine,[],_t14,_t18);
_Next = -1;
return this;
case -1:
this.setLatest(718,-1);
_t19=_SF1.res();
 // _t19 = DecodeRune(t14, t18) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:21
this.SubFn6();
_Phi=5;
case 6: // switch.body
this.setLatest(718,6);
this.SubFn7();
_Phi=6;
case 7: // switch.next
this.setLatest(718,7);
this.SubFn8();
_Phi=7;
case 8: // binop.rhs
this.setLatest(718,8);
this.SubFn9();
_Phi=8;
case 9: // binop.done
this.setLatest(718,9);
this.setPH(716);
_t29=((_Phi==1)?false:(_Phi==12)?false:(_Phi==11)?false:(_Phi==10)?false:(_Phi==8)?_t28:false); // _t29 = phi [1.for.body: false:bool, 12.cond.true: false:bool, 11.cond.true: false:bool, 10.cond.true: false:bool, 8.binop.rhs: t28] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:20
this.SubFn10();
_Phi=9;
case 10: // cond.true
this.setLatest(716,10);
this.SubFn11();
_Phi=10;
case 11: // cond.true
this.setLatest(716,11);
this.SubFn12();
_Phi=11;
case 12: // cond.true
this.setLatest(716,12);
this.SubFn13();
_Phi=12;
case 13: // switch.next
this.setLatest(716,13);
this.SubFn14();
_Phi=13;
case 14: // binop.rhs
this.setLatest(716,14);
this.SubFn15();
_Phi=14;
case 15: // binop.done
this.setLatest(716,15);
this.setPH(721);
_t42=((_Phi==7)?false:(_Phi==14)?_t41:false); // _t42 = phi [7.switch.next: false:bool, 14.binop.rhs: t41] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:19
this.SubFn16();
_Phi=15;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
this.setPH(711);
_t0=({var _v=p_s;_v==null?0:_v.len();}); // _t0 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:87:23
_t1=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t0) _v[_i]=0; _v;}),0,_t0); // _t1 = make []rune t0 t0 *ssa.MakeSlice @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:87:11
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:87:11
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Pointer;
var _t4:Bool;
this.setPH(714);
if((_t7<0)||(_t7>=p_s.len())) Scheduler.ioor(); // _t2 = &s[t7] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:90:16 [POINTER]
_t2=p_s.addr(_t7);  // _t2 = &s[t7] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:90:16 [POINTER]
_t3=(_t2.load()|0); // _t3 = *t2 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:90:16
this.setPH(715);
_t4=(Force.uintCompare(55296,_t3)<=0); // _t4 = 55296:uint16 <= t3 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:14
_Next=_t4 ? 12 : 9; // if t4 goto 12.cond.true else 9.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:14
}// end SubFn1
private inline  function SubFn2():Void {
this.setPH(731);
_t5=_t1.subSlice(0,_t6); // _t5 = slice t1[0:int:t6] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:107:10
}// end SubFn2
private inline  function SubFn3():Void {
var _t8:Int;
var _t9:Bool;
this.setPH(713);
_t8=({var _v=p_s;_v==null?0:_v.len();}); // _t8 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:21
_t9=(_t7<_t8); // _t9 = t7 < t8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:16
_Next=_t9 ? 1 : 2; // if t9 goto 1.for.body else 2.for.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:16
}// end SubFn3
private inline  function SubFn4():Void {
_t12=(_t11+1); // _t12 = t11 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:16
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:16
}// end SubFn4
private inline  function SubFn5():Void {
var _t15:Int;
var _t16:Pointer;
var _t17:Int;
this.setPH(718);
if((_t6<0)||(_t6>=_t1.len())) Scheduler.ioor(); // _t13 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:5 [POINTER]
_t13=_t1.addr(_t6);  // _t13 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:5 [POINTER]
_t14=_t3; // _t14 = convert rune <- uint16 (t3) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:26
_t15=(_t7+1); // _t15 = t7 + 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:39
if((_t15<0)||(_t15>=p_s.len())) Scheduler.ioor(); // _t16 = &s[t15] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:37 [POINTER]
_t16=p_s.addr(_t15);  // _t16 = &s[t15] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:37 [POINTER]
_t17=(_t16.load()|0); // _t17 = *t16 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:37
_t18=_t17; // _t18 = convert rune <- uint16 (t17) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:35
}// end SubFn5
private inline  function SubFn6():Void {
_t13.store(_t19); // *t13 = t19 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:35
_t20=(_t7+1); // _t20 = t7 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:35
_t21=(_t6+1); // _t21 = t6 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:35
_Next=4; // jump 4.switch.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:35
}// end SubFn6
private inline  function SubFn7():Void {
var _t22:Pointer;
this.setPH(723);
if((_t6<0)||(_t6>=_t1.len())) Scheduler.ioor(); // _t22 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5 [POINTER]
_t22=_t1.addr(_t6);  // _t22 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5 [POINTER]
_t22.store(65533); // *t22 = 65533:rune *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5
_t23=(_t6+1); // _t23 = t6 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5
_Next=4; // jump 4.switch.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5
}// end SubFn7
private inline  function SubFn8():Void {
var _t24:Bool;
this.setPH(721);
_t24=(Force.uintCompare(55296,_t3)<=0); // _t24 = 55296:uint16 <= t3 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:14
_Next=_t24 ? 14 : 15; // if t24 goto 14.binop.rhs else 15.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:14
}// end SubFn8
private inline  function SubFn9():Void {
var _t25:Int;
var _t26:Pointer;
var _t27:Int;
this.setPH(716);
_t25=(_t7+1); // _t25 = t7 + 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:26
if((_t25<0)||(_t25>=p_s.len())) Scheduler.ioor(); // _t26 = &s[t25] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:24 [POINTER]
_t26=p_s.addr(_t25);  // _t26 = &s[t25] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:24 [POINTER]
_t27=(_t26.load()|0); // _t27 = *t26 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:24
_t28=(Force.uintCompare(_t27,57344)<0); // _t28 = t27 < 57344:uint16 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:30
_Next=9; // jump 9.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:30
}// end SubFn9
private inline  function SubFn10():Void {
_Next=_t29 ? 5 : 7; // if t29 goto 5.switch.body else 7.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:30
}// end SubFn10
private inline  function SubFn11():Void {
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
private inline  function SubFn12():Void {
var _t34:Int;
var _t35:Int;
var _t36:Bool;
this.setPH(715);
_t34=(_t7+1); // _t34 = t7 + 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:36
_t35=({var _v=p_s;_v==null?0:_v.len();}); // _t35 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:44
_t36=(_t34<_t35); // _t36 = t34 < t35 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:39
_Next=_t36 ? 10 : 9; // if t36 goto 10.cond.true else 9.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:39
}// end SubFn12
private inline  function SubFn13():Void {
var _t37:Bool;
_t37=(Force.uintCompare(_t3,56320)<0); // _t37 = t3 < 56320:uint16 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:24
_Next=_t37 ? 11 : 9; // if t37 goto 11.cond.true else 9.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:24
}// end SubFn13
private inline  function SubFn14():Void {
var _t38:Pointer;
var _t39:Int;
this.setPH(727);
if((_t6<0)||(_t6>=_t1.len())) Scheduler.ioor(); // _t38 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:5 [POINTER]
_t38=_t1.addr(_t6);  // _t38 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:5 [POINTER]
_t39=_t3; // _t39 = convert rune <- uint16 (t3) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
_t38.store(_t39); // *t38 = t39 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
_t40=(_t6+1); // _t40 = t6 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
_Next=4; // jump 4.switch.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
}// end SubFn14
private inline  function SubFn15():Void {
this.setPH(721);
_t41=(Force.uintCompare(_t3,57344)<0); // _t41 = t3 < 57344:uint16 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
_Next=15; // jump 15.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
}// end SubFn15
private inline  function SubFn16():Void {
_Next=_t42 ? 6 : 13; // if t42 goto 6.switch.body else 13.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
}// end SubFn16
}
#if (!php) private #end class Go_haxegoruntime_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,721,"Go_haxegoruntime_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _SF1:StackFrame;
var _SF2:StackFrame;
var _SF3:StackFrame;
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
this.setLatest(721,0);
this.SubFn0();

case 1: // init.start
this.setLatest(721,1);
this.SubFn1();
Go_utf16_init.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(721,-1);
 // _t1 = unicode/utf16.init() *ssa.Call near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24 [REGISTER VALUE UN-USED]
Go_utf8_init.call(this._goroutine,[]);
_Next = -2;
return this;
case -2:
this.setLatest(721,-2);
 // _t2 = unicode/utf8.init() *ssa.Call near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24 [REGISTER VALUE UN-USED]
Go_haxegoruntime_init_36_1.call(this._goroutine,[]);
_Next = -3;
return this;
case -3:
this.setLatest(721,-3);
 // _t3 = init$1() *ssa.Call near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24 [REGISTER VALUE UN-USED]
this.SubFn2();

case 2: // init.done
this.setLatest(721,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.haxegoruntime_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
}// end SubFn0
private inline  function SubFn1():Void {
Go.haxegoruntime_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
}// end SubFn1
private inline  function SubFn2():Void {
_Next=2; // jump 2.init.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
}// end SubFn2
}
#if js @:expose("Go_haxegoruntime_Rune2Raw") #end class Go_haxegoruntime_Rune2Raw extends StackFrameBasis implements StackFrame {  // langgoruntime.go:113:6
var p_oneRune:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_oneRune : Int) {
super(gr,596,"Go_haxegoruntime_Rune2Raw");
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
this.setLatest(596,0);
this.SubFn0();
this.setPH(599);
_SF1=Go_haxegoruntime_Runes2Raw.call(this._goroutine,[],_t0);
_Next = -1;
return this;
case -1:
this.setLatest(599,-1);
_t2=_SF1.res();
 // _t2 = Runes2Raw(t0) *ssa.Call @ langgoruntime.go:116:18
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ langgoruntime.go:116:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Pointer;
this.setPH(597);
_t0=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0...1) _v[_i]=0; _v;}),0,1); // _t0 = make []rune 1:int 1:int *ssa.MakeSlice @ langgoruntime.go:114:11
this.setPH(598);
if((0<0)||(0>=_t0.len())) Scheduler.ioor(); // _t1 = &t0[0:int] *ssa.IndexAddr @ langgoruntime.go:115:3 [POINTER]
_t1=_t0.addr(0);  // _t1 = &t0[0:int] *ssa.IndexAddr @ langgoruntime.go:115:3 [POINTER]
_t1.store(p_oneRune); // *t1 = oneRune *ssa.Store near langgoruntime.go:115:3
}// end SubFn0
}
#if js @:expose("Go_atomic_StoreInt64") #end class Go_atomic_StoreInt64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:157:6
var p_addr:Pointer;
var p_val:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : GOint64) {
super(gr,278,"Go_atomic_StoreInt64");
this._bds=_bds;
this.p_addr=p_addr;
this.p_val=p_val;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_val : GOint64) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_StoreInt64(0,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_val : GOint64) : Void {
var _sf=new Go_atomic_StoreInt64(_gr,[], p_addr, p_val).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : GOint64) : Go_atomic_StoreInt64
{return new Go_atomic_StoreInt64(gr,_bds, p_addr, p_val);
}
public function run():Go_atomic_StoreInt64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(278,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near langgoruntime.go:115:3

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:157:43
}// end SubFn0
}
#if js @:expose("Go_tardisgolib_Host") #end class Go_tardisgolib_Host extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:15:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,456,"Go_tardisgolib_Host");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_tardisgolib_Host(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_tardisgolib_Host(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_tardisgolib_Host
{return new Go_tardisgolib_Host(gr,_bds);
}
public function run():Go_tardisgolib_Host {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(456,0);
_res= "go";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "go":string *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:15:22

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_haxegoruntime_UTF16toRunes") #end class Go_haxegoruntime_UTF16toRunes extends StackFrameBasis implements StackFrame {  // langgoruntime.go:35:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,518,"Go_haxegoruntime_UTF16toRunes");
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
this.setLatest(518,0);
this.setPH(519);
_SF1=Go_utf16_Decode.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(519,-1);
_t0=_SF1.res();
 // _t0 = unicode/utf16.Decode(s) *ssa.Call @ langgoruntime.go:36:21
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ langgoruntime.go:36:2

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_haxegoruntime_StringCompare") #end class Go_haxegoruntime_StringCompare extends StackFrameBasis implements StackFrame {  // langgoruntime.go:120:6
var p_a:String;
var p_b:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_a : String, p_b : String) {
super(gr,603,"Go_haxegoruntime_StringCompare");
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
this.setLatest(603,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(603,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(603,2);
this.SubFn2();
_Phi=2;
case 3: // for.loop
this.setLatest(603,3);
this.setPH(607);
_t10=((_Phi==0)?0:(_Phi==8)?_t20:0); // _t10 = phi [0.entry: 0:int, 8.if.done: t20] #i *ssa.Phi @ langgoruntime.go:124:2
this.SubFn3();
_Phi=3;
case 4: // cond.true
this.setLatest(607,4);
this.SubFn4();
_Phi=4;
case 5: // if.then
this.setLatest(607,5);
this.setPH(610);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ langgoruntime.go:127:4

case 6: // if.done
this.setLatest(610,6);
this.SubFn5();
_Phi=6;
case 7: // if.then
this.setLatest(610,7);
this.setPH(613);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ langgoruntime.go:130:4

case 8: // if.done
this.setLatest(613,8);
this.SubFn6();
_Phi=8;
case 9: // if.then
this.setLatest(613,9);
this.setPH(618);
_res= 0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int *ssa.Return @ langgoruntime.go:135:3

case 10: // if.done
this.setLatest(618,10);
this.SubFn7();
_Phi=10;
case 11: // if.then
this.setLatest(618,11);
this.setPH(621);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ langgoruntime.go:138:3

case 12: // if.done
this.setLatest(621,12);
this.setPH(623);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ langgoruntime.go:140:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(605);
_t0=Force.toUTF8slice(this._goroutine,p_a); // _t0 = convert []byte <- string (a) *ssa.Convert @ langgoruntime.go:122:13
this.setPH(606);
_t1=Force.toUTF8slice(this._goroutine,p_b); // _t1 = convert []byte <- string (b) *ssa.Convert @ langgoruntime.go:123:13
_Next=3; // jump 3.for.loop *ssa.Jump near langgoruntime.go:123:13
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Pointer;
var _t3:Int;
var _t4:Pointer;
var _t5:Int;
var _t6:Bool;
this.setPH(609);
if((_t10<0)||(_t10>=_t0.len())) Scheduler.ioor(); // _t2 = &t0[t10] *ssa.IndexAddr @ langgoruntime.go:126:7 [POINTER]
_t2=_t0.addr(_t10);  // _t2 = &t0[t10] *ssa.IndexAddr @ langgoruntime.go:126:7 [POINTER]
_t3=(_t2.load()|0); // _t3 = *t2 *ssa.UnOp near langgoruntime.go:126:7
if((_t10<0)||(_t10>=_t1.len())) Scheduler.ioor(); // _t4 = &t1[t10] *ssa.IndexAddr @ langgoruntime.go:126:14 [POINTER]
_t4=_t1.addr(_t10);  // _t4 = &t1[t10] *ssa.IndexAddr @ langgoruntime.go:126:14 [POINTER]
_t5=(_t4.load()|0); // _t5 = *t4 *ssa.UnOp near langgoruntime.go:126:14
_t6=(Force.uintCompare(_t3,_t5)<0); // _t6 = t3 < t5 *ssa.BinOp @ langgoruntime.go:126:11
_Next=_t6 ? 5 : 6; // if t6 goto 5.if.then else 6.if.done *ssa.If near langgoruntime.go:126:11
}// end SubFn1
private inline  function SubFn2():Void {
var _t7:Int;
var _t8:Int;
var _t9:Bool;
this.setPH(617);
_t7=({var _v=_t0;_v==null?0:_v.len();}); // _t7 = len(t0) *ssa.Call @ langgoruntime.go:134:8
_t8=({var _v=_t1;_v==null?0:_v.len();}); // _t8 = len(t1) *ssa.Call @ langgoruntime.go:134:18
_t9=(_t7==_t8); // _t9 = t7 == t8 *ssa.BinOp @ langgoruntime.go:134:12
_Next=_t9 ? 9 : 10; // if t9 goto 9.if.then else 10.if.done *ssa.If near langgoruntime.go:134:12
}// end SubFn2
private inline  function SubFn3():Void {
var _t11:Int;
var _t12:Bool;
this.setPH(608);
_t11=({var _v=_t0;_v==null?0:_v.len();}); // _t11 = len(t0) *ssa.Call @ langgoruntime.go:125:14
_t12=(_t10<_t11); // _t12 = t10 < t11 *ssa.BinOp @ langgoruntime.go:125:9
_Next=_t12 ? 4 : 2; // if t12 goto 4.cond.true else 2.for.done *ssa.If near langgoruntime.go:125:9
}// end SubFn3
private inline  function SubFn4():Void {
var _t13:Int;
var _t14:Bool;
_t13=({var _v=_t1;_v==null?0:_v.len();}); // _t13 = len(t1) *ssa.Call @ langgoruntime.go:125:30
_t14=(_t10<_t13); // _t14 = t10 < t13 *ssa.BinOp @ langgoruntime.go:125:25
_Next=_t14 ? 1 : 2; // if t14 goto 1.for.body else 2.for.done *ssa.If near langgoruntime.go:125:25
}// end SubFn4
private inline  function SubFn5():Void {
var _t15:Pointer;
var _t16:Int;
var _t17:Pointer;
var _t18:Int;
var _t19:Bool;
this.setPH(612);
if((_t10<0)||(_t10>=_t0.len())) Scheduler.ioor(); // _t15 = &t0[t10] *ssa.IndexAddr @ langgoruntime.go:129:7 [POINTER]
_t15=_t0.addr(_t10);  // _t15 = &t0[t10] *ssa.IndexAddr @ langgoruntime.go:129:7 [POINTER]
_t16=(_t15.load()|0); // _t16 = *t15 *ssa.UnOp near langgoruntime.go:129:7
if((_t10<0)||(_t10>=_t1.len())) Scheduler.ioor(); // _t17 = &t1[t10] *ssa.IndexAddr @ langgoruntime.go:129:14 [POINTER]
_t17=_t1.addr(_t10);  // _t17 = &t1[t10] *ssa.IndexAddr @ langgoruntime.go:129:14 [POINTER]
_t18=(_t17.load()|0); // _t18 = *t17 *ssa.UnOp near langgoruntime.go:129:14
_t19=(Force.uintCompare(_t16,_t18)>0); // _t19 = t16 > t18 *ssa.BinOp @ langgoruntime.go:129:11
_Next=_t19 ? 7 : 8; // if t19 goto 7.if.then else 8.if.done *ssa.If near langgoruntime.go:129:11
}// end SubFn5
private inline  function SubFn6():Void {
_t20=(_t10+1); // _t20 = t10 + 1:int *ssa.BinOp near langgoruntime.go:129:11
_Next=3; // jump 3.for.loop *ssa.Jump near langgoruntime.go:129:11
}// end SubFn6
private inline  function SubFn7():Void {
var _t21:Int;
var _t22:Int;
var _t23:Bool;
this.setPH(620);
_t21=({var _v=_t0;_v==null?0:_v.len();}); // _t21 = len(t0) *ssa.Call @ langgoruntime.go:137:8
_t22=({var _v=_t1;_v==null?0:_v.len();}); // _t22 = len(t1) *ssa.Call @ langgoruntime.go:137:17
_t23=(_t21<_t22); // _t23 = t21 < t22 *ssa.BinOp @ langgoruntime.go:137:12
_Next=_t23 ? 11 : 12; // if t23 goto 11.if.then else 12.if.done *ssa.If near langgoruntime.go:137:12
}// end SubFn7
}
#if js @:expose("Go_atomic_AddUint32") #end class Go_atomic_AddUint32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:112:6
var p_addr:Pointer;
var p_delta:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : Int) {
super(gr,233,"Go_atomic_AddUint32");
this._bds=_bds;
this.p_addr=p_addr;
this.p_delta=p_delta;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Int=0;
var _t2:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_addr : Pointer, p_delta : Int) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_atomic_AddUint32(0,[], p_addr, p_delta).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_addr : Pointer, p_delta : Int) : Int {
var _sf=new Go_atomic_AddUint32(_gr,[], p_addr, p_delta).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : Int) : Go_atomic_AddUint32
{return new Go_atomic_AddUint32(gr,_bds, p_addr, p_delta);
}
public function run():Go_atomic_AddUint32 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(233,0);
this.SubFn0();
this.setPH(235);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:114:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
var _t1:Int;
this.setPH(234);
_t0=(p_addr.load()|0); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:113:2
_t1=Force.toUint32((_t0+p_delta)); // _t1 = t0 + delta *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:113:2
p_addr.store(_t1); // *addr = t1 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:113:2
this.setPH(235);
_t2=(p_addr.load()|0); // _t2 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:114:9
}// end SubFn0
}
#if (!php) private #end class Go_tardisgolib_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,400,"Go_tardisgolib_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_tardisgolib_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_tardisgolib_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_tardisgolib_init
{return new Go_tardisgolib_init(gr,_bds);
}
public function run():Go_tardisgolib_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(400,0);
this.SubFn0();

case 1: // init.start
this.setLatest(400,1);
this.SubFn1();

case 2: // init.done
this.setLatest(400,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:114:9

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.tardisgolib_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:114:9
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:114:9
}// end SubFn0
private inline  function SubFn1():Void {
Go.tardisgolib_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:114:9
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:114:9
}// end SubFn1
}
#if (!php) private #end class Go_utf8_decodeRuneInStringInternal extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:123:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,855,"Go_utf8_decodeRuneInStringInternal");
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
this.setLatest(855,0);
this.SubFn0();

case 1: // if.then
this.setLatest(855,1);
this.setPH(858);
_res= {r0:65533,r1:0,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:126:3

case 2: // if.done
this.setLatest(858,2);
this.SubFn1();

case 3: // if.then
this.setLatest(858,3);
this.SubFn2();
this.setPH(864);
_res= {r0:_t4,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:132:3

case 4: // if.done
this.setLatest(864,4);
this.SubFn3();

case 5: // if.then
this.setLatest(864,5);
this.setPH(869);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:137:3

case 6: // if.done
this.setLatest(869,6);
this.SubFn4();

case 7: // if.then
this.setLatest(869,7);
this.setPH(874);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:142:3

case 8: // if.done
this.setLatest(874,8);
this.SubFn5();

case 9: // if.then
this.setLatest(874,9);
this.setPH(878);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:146:3

case 10: // if.done
this.setLatest(878,10);
this.SubFn6();

case 11: // cond.false
this.setLatest(878,11);
this.SubFn7();

case 12: // if.then
this.setLatest(878,12);
this.SubFn8();

case 13: // if.done
this.setLatest(878,13);
this.SubFn9();

case 14: // if.then
this.setLatest(878,14);
this.setPH(885);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:153:4

case 15: // if.done
this.setLatest(885,15);
this.setPH(887);
_res= {r0:_t16,r1:2,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t16, 2:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:155:3

case 16: // if.then
this.setLatest(887,16);
this.setPH(892);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:160:3

case 17: // if.done
this.setLatest(892,17);
this.SubFn10();

case 18: // if.then
this.setLatest(892,18);
this.setPH(896);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:164:3

case 19: // if.done
this.setLatest(896,19);
this.SubFn11();

case 20: // cond.false
this.setLatest(896,20);
this.SubFn12();

case 21: // if.then
this.setLatest(896,21);
this.SubFn13();

case 22: // if.done
this.setLatest(896,22);
this.SubFn14();

case 23: // if.then
this.setLatest(896,23);
this.setPH(903);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:171:4

case 24: // if.done
this.setLatest(903,24);
this.SubFn15();

case 25: // if.then
this.setLatest(903,25);
this.setPH(906);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:174:4

case 26: // if.done
this.setLatest(906,26);
this.setPH(908);
_res= {r0:_t32,r1:3,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t32, 3:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:176:3

case 27: // cond.true
this.setLatest(908,27);
this.SubFn16();

case 28: // if.then
this.setLatest(908,28);
this.setPH(913);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:181:3

case 29: // if.done
this.setLatest(913,29);
this.SubFn17();

case 30: // if.then
this.setLatest(913,30);
this.setPH(917);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:185:3

case 31: // if.done
this.setLatest(917,31);
this.SubFn18();

case 32: // cond.false
this.setLatest(917,32);
this.SubFn19();

case 33: // if.then
this.setLatest(917,33);
this.SubFn20();

case 34: // if.done
this.setLatest(917,34);
this.setPH(930);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:198:2

case 35: // if.then
this.setLatest(930,35);
this.setPH(924);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:192:4

case 36: // if.done
this.setLatest(924,36);
this.setPH(926);
_res= {r0:_t54,r1:4,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t54, 4:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:194:3

case 37: // cond.false
this.setLatest(926,37);
this.SubFn21();

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Bool;
this.setPH(856);
_t0=Force.toUTF8length(this._goroutine,p_s); // _t0 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:124:10
this.setPH(857);
_t1=(_t0<1); // _t1 = t0 < 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:125:7
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:125:7
}// end SubFn0
private inline  function SubFn1():Void {
var _t3:Bool;
this.setPH(860);
_t2=Force.toUTF8slice(this._goroutine,p_s).getAt(0); // _t2 = s[0:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:128:9
this.setPH(863);
_t3=(Force.uintCompare(_t2,128)<0); // _t3 = t2 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:131:8
_Next=_t3 ? 3 : 4; // if t3 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:131:8
}// end SubFn1
private inline  function SubFn2():Void {
this.setPH(864);
_t4=_t2; // _t4 = convert rune <- uint8 (t2) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:132:14
}// end SubFn2
private inline  function SubFn3():Void {
var _t5:Bool;
this.setPH(868);
_t5=(Force.uintCompare(_t2,192)<0); // _t5 = t2 < 192:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:136:8
_Next=_t5 ? 5 : 6; // if t5 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:136:8
}// end SubFn3
private inline  function SubFn4():Void {
var _t6:Bool;
this.setPH(873);
_t6=(_t0<2); // _t6 = t0 < 2:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:141:7
_Next=_t6 ? 7 : 8; // if t6 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:141:7
}// end SubFn4
private inline  function SubFn5():Void {
var _t8:Bool;
this.setPH(876);
_t7=Force.toUTF8slice(this._goroutine,p_s).getAt(1); // _t7 = s[1:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:144:9
this.setPH(877);
_t8=(Force.uintCompare(_t7,128)<0); // _t8 = t7 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:145:8
_Next=_t8 ? 9 : 11; // if t8 goto 9.if.then else 11.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:145:8
}// end SubFn5
private inline  function SubFn6():Void {
var _t9:Bool;
this.setPH(882);
_t9=(Force.uintCompare(_t2,224)<0); // _t9 = t2 < 224:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:150:8
_Next=_t9 ? 12 : 13; // if t9 goto 12.if.then else 13.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:150:8
}// end SubFn6
private inline  function SubFn7():Void {
var _t10:Bool;
this.setPH(877);
_t10=(Force.uintCompare(192,_t7)<=0); // _t10 = 192:uint8 <= t7 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:145:19
_Next=_t10 ? 9 : 10; // if t10 goto 9.if.then else 10.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:145:19
}// end SubFn7
private inline  function SubFn8():Void {
var _t11:Int;
var _t12:Int;
var _t13:Int;
var _t14:Int;
var _t15:Int;
var _t17:Bool;
this.setPH(883);
_t11=Force.toUint8((_t2&31)); // _t11 = t2 & 31:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:14
_t12=_t11; // _t12 = convert rune <- uint8 (t11) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:11
_t13=(_t12<<GOint64.toInt(GOint64.make(0x0,0x6))); // _t13 = t12 << 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:21
_t14=Force.toUint8((_t7&63)); // _t14 = t7 & 63:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:34
_t15=_t14; // _t15 = convert rune <- uint8 (t14) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:31
_t16=Force.toInt32((_t13|_t15)); // _t16 = t13 | t15 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:25
this.setPH(884);
_t17=(_t16<=127); // _t17 = t16 <= 127:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:152:8
_Next=_t17 ? 14 : 15; // if t17 goto 14.if.then else 15.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:152:8
}// end SubFn8
private inline  function SubFn9():Void {
var _t18:Bool;
this.setPH(891);
_t18=(_t0<3); // _t18 = t0 < 3:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:159:7
_Next=_t18 ? 16 : 17; // if t18 goto 16.if.then else 17.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:159:7
}// end SubFn9
private inline  function SubFn10():Void {
var _t20:Bool;
this.setPH(894);
_t19=Force.toUTF8slice(this._goroutine,p_s).getAt(2); // _t19 = s[2:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:162:9
this.setPH(895);
_t20=(Force.uintCompare(_t19,128)<0); // _t20 = t19 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:163:8
_Next=_t20 ? 18 : 20; // if t20 goto 18.if.then else 20.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:163:8
}// end SubFn10
private inline  function SubFn11():Void {
var _t21:Bool;
this.setPH(900);
_t21=(Force.uintCompare(_t2,240)<0); // _t21 = t2 < 240:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:168:8
_Next=_t21 ? 21 : 22; // if t21 goto 21.if.then else 22.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:168:8
}// end SubFn11
private inline  function SubFn12():Void {
var _t22:Bool;
this.setPH(895);
_t22=(Force.uintCompare(192,_t19)<=0); // _t22 = 192:uint8 <= t19 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:163:19
_Next=_t22 ? 18 : 19; // if t22 goto 18.if.then else 19.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:163:19
}// end SubFn12
private inline  function SubFn13():Void {
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
this.setPH(901);
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
this.setPH(902);
_t33=(_t32<=2047); // _t33 = t32 <= 2047:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:170:8
_Next=_t33 ? 23 : 24; // if t33 goto 23.if.then else 24.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:170:8
}// end SubFn13
private inline  function SubFn14():Void {
var _t34:Bool;
this.setPH(912);
_t34=(_t0<4); // _t34 = t0 < 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:180:7
_Next=_t34 ? 28 : 29; // if t34 goto 28.if.then else 29.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:180:7
}// end SubFn14
private inline  function SubFn15():Void {
var _t35:Bool;
this.setPH(905);
_t35=(55296<=_t32); // _t35 = 55296:rune <= t32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:173:19
_Next=_t35 ? 27 : 26; // if t35 goto 27.cond.true else 26.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:173:19
}// end SubFn15
private inline  function SubFn16():Void {
var _t36:Bool;
_t36=(_t32<=57343); // _t36 = t32 <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:173:29
_Next=_t36 ? 25 : 26; // if t36 goto 25.if.then else 26.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:173:29
}// end SubFn16
private inline  function SubFn17():Void {
var _t38:Bool;
this.setPH(915);
_t37=Force.toUTF8slice(this._goroutine,p_s).getAt(3); // _t37 = s[3:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:183:9
this.setPH(916);
_t38=(Force.uintCompare(_t37,128)<0); // _t38 = t37 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:184:8
_Next=_t38 ? 30 : 32; // if t38 goto 30.if.then else 32.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:184:8
}// end SubFn17
private inline  function SubFn18():Void {
var _t39:Bool;
this.setPH(921);
_t39=(Force.uintCompare(_t2,248)<0); // _t39 = t2 < 248:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:189:8
_Next=_t39 ? 33 : 34; // if t39 goto 33.if.then else 34.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:189:8
}// end SubFn18
private inline  function SubFn19():Void {
var _t40:Bool;
this.setPH(916);
_t40=(Force.uintCompare(192,_t37)<=0); // _t40 = 192:uint8 <= t37 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:184:19
_Next=_t40 ? 30 : 31; // if t40 goto 30.if.then else 31.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:184:19
}// end SubFn19
private inline  function SubFn20():Void {
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
this.setPH(922);
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
this.setPH(923);
_t55=(_t54<=65535); // _t55 = t54 <= 65535:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:8
_Next=_t55 ? 35 : 37; // if t55 goto 35.if.then else 37.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:8
}// end SubFn20
private inline  function SubFn21():Void {
var _t56:Bool;
_t56=(1114111<_t54); // _t56 = 1114111:rune < t54 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:31
_Next=_t56 ? 35 : 36; // if t56 goto 35.if.then else 36.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:31
}// end SubFn21
}
#if js @:expose("Go_utf8_Valid") #end class Go_utf8_Valid extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:395:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,1127,"Go_utf8_Valid");
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
this.setLatest(1127,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(1127,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(1127,2);
this.setPH(1143);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:411:2

case 3: // for.loop
this.setLatest(1143,3);
this.setPH(1128);
_t3=((_Phi==0)?0:(_Phi==4)?_t6:(_Phi==7)?_t12:0); // _t3 = phi [0.entry: 0:int, 4.if.then: t6, 7.if.done: t12] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:396:2
this.SubFn2();
_Phi=3;
case 4: // if.then
this.setLatest(1128,4);
this.SubFn3();
_Phi=4;
case 5: // if.else
this.setLatest(1128,5);
this.SubFn4();
this.setPH(1133);
_SF1=Go_utf8_DecodeRune.call(this._goroutine,[],_t7);
_Next = -1;
return this;
case -1:
this.setLatest(1133,-1);
_t8=_SF1.res();
 // _t8 = DecodeRune(t7) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:25
this.SubFn5();
_Phi=5;
case 6: // if.then
this.setLatest(1133,6);
this.setPH(1138);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:406:5

case 7: // if.done
this.setLatest(1138,7);
this.SubFn6();
_Phi=7;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:406:5
}// end SubFn0
private inline  function SubFn1():Void {
var _t0:Pointer;
var _t1:Int;
var _t2:Bool;
this.setPH(1130);
if((_t3<0)||(_t3>=p_p.len())) Scheduler.ioor(); // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:7 [POINTER]
_t0=p_p.addr(_t3);  // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:7 [POINTER]
_t1=(_t0.load()|0); // _t1 = *t0 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:7
_t2=(Force.uintCompare(_t1,128)<0); // _t2 = t1 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:11
_Next=_t2 ? 4 : 5; // if t2 goto 4.if.then else 5.if.else *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:11
}// end SubFn1
private inline  function SubFn2():Void {
var _t4:Int;
var _t5:Bool;
this.setPH(1129);
_t4=({var _v=p_p;_v==null?0:_v.len();}); // _t4 = len(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:13
_t5=(_t3<_t4); // _t5 = t3 < t4 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
_Next=_t5 ? 1 : 2; // if t5 goto 1.for.body else 2.for.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
}// end SubFn2
private inline  function SubFn3():Void {
_t6=(_t3+1); // _t6 = t3 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
}// end SubFn3
private inline  function SubFn4():Void {
this.setPH(1133);
_t7=p_p.subSlice(_t3,-1); // _t7 = slice p[t3:] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:27
}// end SubFn4
private inline  function SubFn5():Void {
var _t11:Bool;
 // _t9 = extract t8 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:27 [REGISTER VALUE UN-USED]
_t10=_t8.r1; // _t10 = extract t8 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:27
this.setPH(1134);
_t11=(_t10==1); // _t11 = t10 == 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
_Next=_t11 ? 6 : 7; // if t11 goto 6.if.then else 7.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
}// end SubFn5
private inline  function SubFn6():Void {
_t12=(_t3+_t10); // _t12 = t3 + t10 *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
}// end SubFn6
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

public static var utf8_UTFMax:Int = 4;
public static var utf8_RuneSelf:Int = 128;
public static var utf8_RuneError:Int = 65533;
public static var utf8_MaxRune:Int = 1114111;
public static var haxegoruntime_init_36_guard:Pointer=new Pointer(false); 
public static var haxegoruntime_ZiLen:Pointer=new Pointer(0);  // langgoruntime.go:33:5
public static var atomic_init_36_guard:Pointer=new Pointer(false); 
public static var tardisgolib_init_36_guard:Pointer=new Pointer(false); 
public static var main_init_36_guard:Pointer=new Pointer(false); 
public static var utf16_init_36_guard:Pointer=new Pointer(false); 
public static var utf8_init_36_guard:Pointer=new Pointer(false); 
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
Go.haxegoruntime_ZiLen.store('字'.length);
}

public static function main() : Void {
Go_main_main.callFromHaxe();
}
public static function CPos(pos:Int):String {
var prefix:String="";
if (pos==0) return "(pogo.NoPosHash)";
if (pos<0) { pos = -pos; prefix= "near ";}
if(pos>732) return prefix+"/usr/local/go/src/pkg/unicode/utf8/utf8.go:"+Std.string(pos-732);
else if(pos>624) return prefix+"/usr/local/go/src/pkg/unicode/utf16/utf16.go:"+Std.string(pos-624);
else if(pos>483) return prefix+"langgoruntime.go:"+Std.string(pos-483);
else if(pos>441) return prefix+"/Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:"+Std.string(pos-441);
else if(pos>290) return prefix+"/usr/local/go/src/pkg/sync/atomic/doc.go:"+Std.string(pos-290);
else if(pos>121) return prefix+"/Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:"+Std.string(pos-121);
else if(pos>0) return prefix+"stateful.go:"+Std.string(pos-0);
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

 // Warning: *ssa.Call @ langgoruntime.go:84:18 (pogo) The result from a function call is not used
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: temp var declaration (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: temp var declaration (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: *ssa.Next near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: *ssa.Next near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: *ssa.Call @ langgoruntime.go:16:18 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ langgoruntime.go:17:17 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ langgoruntime.go:18:15 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ langgoruntime.go:19:18 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ langgoruntime.go:20:17 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ langgoruntime.go:21:15 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ langgoruntime.go:22:14 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ langgoruntime.go:23:19 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ langgoruntime.go:25:18 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ langgoruntime.go:26:20 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ langgoruntime.go:28:18 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ langgoruntime.go:29:18 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ stateful.go:90:20 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ stateful.go:106:20 (pogo) The result from a function call is not used
 // Package List:
 //  package goruntime
 //  package github.com/tardisgo/tardisgo/golibruntime/sync/atomic
 //  package sync/atomic
 //  package github.com/tardisgo/tardisgo/tardisgolib
 //  package main
 //  package unicode/utf16
 //  package unicode/utf8
