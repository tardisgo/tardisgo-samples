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



#if js @:expose("Go_utf8_FullRuneInString") #end class Go_utf8_FullRuneInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:209:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,3281,"Go_utf8_FullRuneInString");
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
this.setLatest(3281,0);
this.setPH(3282);
_SF1=Go_utf8_decodeRuneInStringInternal.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(3282,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInStringInternal(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:210:43
this.SubFn0();
this.setPH(3283);
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
#if (!php) private #end class Go_sync_runtime_Syncsemrelease extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:46:6
var p_s:Pointer;
var p_n:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Pointer, p_n : Int) {
super(gr,573,"Go_sync_runtime_Syncsemrelease");
this._bds=_bds;
this.p_s=p_s;
this.p_n=p_n;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : Pointer, p_n : Int) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_sync_runtime_Syncsemrelease(0,[], p_s, p_n).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_s : Pointer, p_n : Int) : Void {
var _sf=new Go_sync_runtime_Syncsemrelease(_gr,[], p_s, p_n).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : Pointer, p_n : Int) : Go_sync_runtime_Syncsemrelease
{return new Go_sync_runtime_Syncsemrelease(gr,_bds, p_s, p_n);
}
public function run():Go_sync_runtime_Syncsemrelease {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(573,0);
this.SubFn0();
this.setPH(574);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(574,-1);
 // panic t0 *ssa.Panic @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:47:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"runtime_Syncsemrelease not yet implemented"); // _t0 = make interface{} <- string ("runtime_Syncsemre...":string) *ssa.MakeInterface near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:47:7
}// end SubFn0
}
#if js @:expose("Go_tardisgolib_Gosched") #end class Go_tardisgolib_Gosched extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:39:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,502,"Go_tardisgolib_Gosched");
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
this.setLatest(502,0);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:47:7

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_utf16_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,502,"Go_utf16_init");
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
this.setLatest(502,0);
this.SubFn0();

case 1: // init.start
this.setLatest(502,1);
this.SubFn1();

case 2: // init.done
this.setLatest(502,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:47:7

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.utf16_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:47:7
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:47:7
}// end SubFn0
private inline  function SubFn1():Void {
Go.utf16_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:47:7
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:47:7
}// end SubFn1
}
#if js @:expose("Go_utf8_DecodeRune") #end class Go_utf8_DecodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:219:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,3291,"Go_utf8_DecodeRune");
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
this.setLatest(3291,0);
this.setPH(3292);
_SF1=Go_utf8_decodeRuneInternal.call(this._goroutine,[],p_p);
_Next = -1;
return this;
case -1:
this.setLatest(3292,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInternal(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:220:33
this.SubFn0();
this.setPH(3293);
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
#if js @:expose("Go_utf8_FullRune") #end class Go_utf8_FullRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:203:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,3275,"Go_utf8_FullRune");
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
this.setLatest(3275,0);
this.setPH(3276);
_SF1=Go_utf8_decodeRuneInternal.call(this._goroutine,[],p_p);
_Next = -1;
return this;
case -1:
this.setLatest(3276,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInternal(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:204:35
this.SubFn0();
this.setPH(3277);
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
#if js @:expose("Go_tardisgolib_Zilen") #end class Go_tardisgolib_Zilen extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:26:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,489,"Go_tardisgolib_Zilen");
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
this.setLatest(489,0);
_res= 3;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 3:uint *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:26:21

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_runtime_fsub64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:250:6
var p_f:GOint64;
var p_g:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64) {
super(gr,1609,"Go_runtime_fsub64");
this._bds=_bds;
this.p_f=p_f;
this.p_g=p_g;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:GOint64=null;
var _SF2:StackFrame;
var _t1:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_g : GOint64) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fsub64(0,[], p_f, p_g).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_g : GOint64) : GOint64 {
var _sf=new Go_runtime_fsub64(_gr,[], p_f, p_g).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64) : Go_runtime_fsub64
{return new Go_runtime_fsub64(gr,_bds, p_f, p_g);
}
public function run():Go_runtime_fsub64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1609,0);
this.setPH(1610);
_SF1=Go_runtime_fneg64.call(this._goroutine,[],p_g);
_Next = -1;
return this;
case -1:
this.setLatest(1610,-1);
_t0=_SF1.res();
 // _t0 = fneg64(g) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:251:25
_SF2=Go_runtime_fadd64.call(this._goroutine,[],p_f,_t0);
_Next = -2;
return this;
case -2:
this.setLatest(1610,-2);
_t1=_SF2.res();
 // _t1 = fadd64(f, t0) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:251:15
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:251:2

default: Scheduler.bbi();}}}
}
#if js @:expose("Go__star_runtime_dot_MemProfileRecord_InUseBytes") #end class Go__star_runtime_dot_MemProfileRecord_InUseBytes extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/debug.go:60:28
var p_r:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Pointer) {
super(gr,1140,"Go__star_runtime_dot_MemProfileRecord_InUseBytes");
this._bds=_bds;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _t0:Pointer=null;
var _t1:GOint64=null;
var _t2:Pointer=null;
var _t3:GOint64=null;
var _t4:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_r : Pointer) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_MemProfileRecord_InUseBytes(0,[], p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r : Pointer) : GOint64 {
var _sf=new Go__star_runtime_dot_MemProfileRecord_InUseBytes(_gr,[], p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r : Pointer) : Go__star_runtime_dot_MemProfileRecord_InUseBytes
{return new Go__star_runtime_dot_MemProfileRecord_InUseBytes(gr,_bds, p_r);
}
public function run():Go__star_runtime_dot_MemProfileRecord_InUseBytes {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1140,0);
this.SubFn0();
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ /usr/local/go/src/pkg/runtime/debug.go:60:49

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Pointer;
var _t1:GOint64;
var _t2:Pointer;
var _t3:GOint64;
_t0=p_r.addr(0);  // _t0 = &r.AllocBytes [#0] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/debug.go:60:58 [POINTER]
_t1=_t0.load(); // _t1 = *t0 *ssa.UnOp near /usr/local/go/src/pkg/runtime/debug.go:60:58
_t2=p_r.addr(1);  // _t2 = &r.FreeBytes [#1] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/debug.go:60:73 [POINTER]
_t3=_t2.load(); // _t3 = *t2 *ssa.UnOp near /usr/local/go/src/pkg/runtime/debug.go:60:73
_t4=Force.toInt64(GOint64.sub(_t1,_t3)); // _t4 = t1 - t3 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/debug.go:60:69
}// end SubFn0
}
#if js @:expose("Go_utf8_RuneCount") #end class Go_utf8_RuneCount extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:367:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,3439,"Go_utf8_RuneCount");
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
this.setLatest(3439,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(3439,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(3439,2);
this.setPH(3450);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:378:2

case 3: // for.loop
this.setLatest(3450,3);
this.setPH(3440);
_t3=((_Phi==0)?0:(_Phi==5)?_t9:0); // _t3 = phi [0.entry: 0:int, 5.if.done: t9] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:368:2
this.setPH(3441);
_t4=((_Phi==0)?0:(_Phi==5)?_t11:0); // _t4 = phi [0.entry: 0:int, 5.if.done: t11] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:369:6
this.setPH(3446);
_t5=((_Phi==0)?0:(_Phi==5)?_t10:0); // _t5 = phi [0.entry: 0:int, 5.if.done: t10] #size *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:7
this.SubFn2();
_Phi=3;
case 4: // if.then
this.setLatest(3446,4);
this.SubFn3();
_Phi=4;
case 5: // if.done
this.setLatest(3446,5);
this.setPH(3440);
_t9=((_Phi==4)?_t8:(_Phi==6)?_t16:0); // _t9 = phi [4.if.then: t8, 6.if.else: t16] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:368:2
this.setPH(3446);
_t10=((_Phi==4)?_t5:(_Phi==6)?_t15:0); // _t10 = phi [4.if.then: t5, 6.if.else: t15] #size *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:7
this.SubFn4();
_Phi=5;
case 6: // if.else
this.setLatest(3446,6);
this.SubFn5();
_SF1=Go_utf8_DecodeRune.call(this._goroutine,[],_t12);
_Next = -1;
return this;
case -1:
this.setLatest(3446,-1);
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
this.setPH(3443);
if((_t3<0)||(_t3>=p_p.len())) Scheduler.ioor(); // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:7 [POINTER]
_t0=p_p.addr(_t3);  // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:7 [POINTER]
_t1=(_t0.load()|0); // _t1 = *t0 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:7
_t2=(Force.uintCompare(_t1,128)<0); // _t2 = t1 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:11
_Next=_t2 ? 4 : 6; // if t2 goto 4.if.then else 6.if.else *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:371:11
}// end SubFn1
private inline  function SubFn2():Void {
var _t6:Int;
var _t7:Bool;
this.setPH(3442);
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
this.setPH(3446);
_t12=p_p.subSlice(_t3,-1); // _t12 = slice p[t3:] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
}// end SubFn5
private inline  function SubFn6():Void {
 // _t14 = extract t13 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27 [REGISTER VALUE UN-USED]
_t15=_t13.r1; // _t15 = extract t13 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
_t16=(_t3+_t15); // _t16 = t3 + t15 *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
_Next=5; // jump 5.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:374:27
}// end SubFn6
}
#if js @:expose("Go_runtime_GOROOT") #end class Go_runtime_GOROOT extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/extern.go:166:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1057,"Go_runtime_GOROOT");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:String="";
var _t1:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_GOROOT(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_runtime_GOROOT(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_runtime_GOROOT
{return new Go_runtime_GOROOT(gr,_bds);
}
public function run():Go_runtime_GOROOT {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1057,0);
this.setPH(1058);
_SF1=Go_runtime_getgoroot.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(1058,-1);
_t0=_SF1.res();
 // _t0 = getgoroot() *ssa.Call @ /usr/local/go/src/pkg/runtime/extern.go:167:16
this.SubFn0();

case 1: // if.then
this.setLatest(1058,1);
this.setPH(1060);
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ /usr/local/go/src/pkg/runtime/extern.go:169:3

case 2: // if.done
this.setLatest(1060,2);
this.setPH(1062);
_res= "/usr/local/go";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "/usr/local/go":string *ssa.Return @ /usr/local/go/src/pkg/runtime/extern.go:171:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Bool;
this.setPH(1059);
_t1=(_t0!=""); // _t1 = t0 != "":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/extern.go:168:7
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/runtime/extern.go:168:7
}// end SubFn0
}
#if (!php) private #end class Go_runtime_f64to32 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:317:6
var p_f:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64) {
super(gr,1676,"Go_runtime_f64to32");
this._bds=_bds;
this.p_f=p_f;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:GOint64,r1:GOint64,r2:Int,r3:Bool,r4:Bool}=null;
var _t1:GOint64=null;
var _t2:GOint64=null;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Bool=false;
var _t6:GOint64=null;
var _t7:Int=0;
var _t8:Int=0;
var _t9:GOint64=null;
var _t10:Int=0;
var _t11:Int=0;
var _t12:GOint64=null;
var _t13:Int=0;
var _SF2:StackFrame;
var _t14:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_f64to32(0,[], p_f).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : GOint64) : Int {
var _sf=new Go_runtime_f64to32(_gr,[], p_f).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64) : Go_runtime_f64to32
{return new Go_runtime_f64to32(gr,_bds, p_f);
}
public function run():Go_runtime_f64to32 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1676,0);
this.setPH(1677);
_SF1=Go_runtime_funpack64.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(1677,-1);
_t0=_SF1.res();
 // _t0 = funpack64(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:318:33
this.SubFn0();

case 1: // if.then
this.setLatest(1677,1);
this.setPH(1679);
_res= 2139095041;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 2139095041:uint32 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:320:3

case 2: // if.done
this.setLatest(1679,2);
this.SubFn1();

case 3: // if.then
this.setLatest(1679,3);
this.SubFn2();
this.setPH(1683);
_res= _t8;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t8 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:324:3

case 4: // if.done
this.setLatest(1683,4);
this.SubFn3();
this.setPH(1686);
_SF2=Go_runtime_fpack32.call(this._goroutine,[],_t7,_t10,_t11,_t13);
_Next = -2;
return this;
case -2:
this.setLatest(1686,-2);
_t14=_SF2.res();
 // _t14 = fpack32(t7, t10, t11, t13) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:327:16
_res= _t14;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t14 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:327:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:327:2
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:327:2
_t3=_t0.r2; // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:327:2
_t4=_t0.r3; // _t4 = extract t0 #3 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:327:2
_t5=_t0.r4; // _t5 = extract t0 #4 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:327:2
_Next=_t5 ? 1 : 2; // if t5 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:327:2
}// end SubFn0
private inline  function SubFn1():Void {
var _t6:GOint64;
this.setPH(1681);
_t6=Force.toUint64(GOint64.ushr(_t1,GOint64.toInt(GOint64.make(0x0,0x20)))); // _t6 = t1 >> 32:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:322:20
_t7=Force.toUint32(GOint64.toInt(_t6)); // _t7 = convert uint32 <- uint64 (t6) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:322:16
_Next=_t4 ? 3 : 4; // if t4 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:322:16
}// end SubFn1
private inline  function SubFn2():Void {
this.setPH(1683);
_t8=Force.toUint32((_t7^2139095040)); // _t8 = t7 ^ 2139095040:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:324:15
}// end SubFn2
private inline  function SubFn3():Void {
var _t9:GOint64;
var _t12:GOint64;
this.setPH(1686);
_t9=Force.toUint64(GOint64.ushr(_t2,28)); // _t9 = t2 >> 28:uint *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:327:32
_t10=Force.toUint32(GOint64.toInt(_t9)); // _t10 = convert uint32 <- uint64 (t9) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:327:29
_t11=(_t3-1); // _t11 = t3 - 1:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:327:40
_t12=Force.toUint64(GOint64.and(_t2,GOint64.make(0x0,0xfffffff))); // _t12 = t2 & 268435455:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:327:53
_t13=Force.toUint32(GOint64.toInt(_t12)); // _t13 = convert uint32 <- uint64 (t12) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:327:50
}// end SubFn3
}
#if js @:expose("Go_utf16_IsSurrogate") #end class Go_utf16_IsSurrogate extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:30:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,2994,"Go_utf16_IsSurrogate");
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
this.setLatest(2994,0);
this.SubFn0();
_Phi=0;
case 1: // binop.rhs
this.setLatest(2994,1);
this.SubFn1();
_Phi=1;
case 2: // binop.done
this.setLatest(2994,2);
this.setPH(2995);
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
#if (!php) private #end class Go_atomic_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,2995,"Go_atomic_init");
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
this.setLatest(2995,0);
this.SubFn0();

case 1: // init.start
this.setLatest(2995,1);
this.SubFn1();

case 2: // init.done
this.setLatest(2995,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:25

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.atomic_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:25
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:25
}// end SubFn0
private inline  function SubFn1():Void {
Go.atomic_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:25
_Next=2; // jump 2.init.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:31:25
}// end SubFn1
}
#if js @:expose("Go_runtime_Gosched") #end class Go_runtime_Gosched extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,429,"Go_runtime_Gosched");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_Gosched(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_runtime_Gosched(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_runtime_Gosched
{return new Go_runtime_Gosched(gr,_bds);
}
public function run():Go_runtime_Gosched {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(429,0);
Go_tardisgolib_Gosched.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(429,-1);
 // _t0 = github.com/tardisgo/tardisgo/tardisgolib.Gosched() *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46 [REGISTER VALUE UN-USED]
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_golibruntime_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,429,"Go_golibruntime_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _SF1:StackFrame;
var _SF2:StackFrame;
var _SF3:StackFrame;
var _SF4:StackFrame;
var _SF5:StackFrame;
var _SF6:StackFrame;
var _SF7:StackFrame;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_golibruntime_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_golibruntime_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_golibruntime_init
{return new Go_golibruntime_init(gr,_bds);
}
public function run():Go_golibruntime_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(429,0);
this.SubFn0();

case 1: // init.start
this.setLatest(429,1);
this.SubFn1();
Go_bytes_init.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(429,-1);
 // _t1 = github.com/tardisgo/tardisgo/golibruntime/bytes.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46 [REGISTER VALUE UN-USED]
Go_math_init.call(this._goroutine,[]);
_Next = -2;
return this;
case -2:
this.setLatest(429,-2);
 // _t2 = github.com/tardisgo/tardisgo/golibruntime/math.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46 [REGISTER VALUE UN-USED]
Go_runtime_init.call(this._goroutine,[]);
_Next = -3;
return this;
case -3:
this.setLatest(429,-3);
 // _t3 = github.com/tardisgo/tardisgo/golibruntime/runtime.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46 [REGISTER VALUE UN-USED]
Go_strings_init.call(this._goroutine,[]);
_Next = -4;
return this;
case -4:
this.setLatest(429,-4);
 // _t4 = github.com/tardisgo/tardisgo/golibruntime/strings.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46 [REGISTER VALUE UN-USED]
Go_sync_init.call(this._goroutine,[]);
_Next = -5;
return this;
case -5:
this.setLatest(429,-5);
 // _t5 = github.com/tardisgo/tardisgo/golibruntime/sync.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46 [REGISTER VALUE UN-USED]
Go_atomic_init.call(this._goroutine,[]);
_Next = -6;
return this;
case -6:
this.setLatest(429,-6);
 // _t6 = github.com/tardisgo/tardisgo/golibruntime/sync/atomic.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46 [REGISTER VALUE UN-USED]
Go_runtime_init.call(this._goroutine,[]);
_Next = -7;
return this;
case -7:
this.setLatest(429,-7);
 // _t7 = runtime.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46 [REGISTER VALUE UN-USED]
this.SubFn2();

case 2: // init.done
this.setLatest(429,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.golibruntime_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46
}// end SubFn0
private inline  function SubFn1():Void {
Go.golibruntime_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46
}// end SubFn1
private inline  function SubFn2():Void {
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:12:46
}// end SubFn2
}
#if (!php) private #end class Go_runtime_fadd64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:195:6
var p_f:GOint64;
var p_g:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64) {
super(gr,1554,"Go_runtime_fadd64");
this._bds=_bds;
this.p_f=p_f;
this.p_g=p_g;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:GOint64,r1:GOint64,r2:Int,r3:Bool,r4:Bool}=null;
var _t1:GOint64=null;
var _t2:GOint64=null;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Bool=false;
var _SF2:StackFrame;
var _t6:{r0:GOint64,r1:GOint64,r2:Int,r3:Bool,r4:Bool}=null;
var _t7:GOint64=null;
var _t8:GOint64=null;
var _t9:Int=0;
var _t10:Bool=false;
var _t11:Bool=false;
var _t12:Bool=false;
var _t13:Bool=false;
var _t14:Bool=false;
var _t15:Bool=false;
var _t16:Bool=false;
var _t17:Bool=false;
var _t18:Bool=false;
var _t19:Bool=false;
var _t20:Bool=false;
var _t21:Bool=false;
var _t22:Bool=false;
var _t23:GOint64=null;
var _t24:GOint64=null;
var _t25:Bool=false;
var _t26:GOint64=null;
var _t27:GOint64=null;
var _t28:Int=0;
var _t29:GOint64=null;
var _t30:GOint64=null;
var _t31:Int=0;
var _t32:Int=0;
var _t33:Int=0;
var _t34:GOint64=null;
var _t35:GOint64=null;
var _t36:GOint64=null;
var _t37:GOint64=null;
var _t38:GOint64=null;
var _t39:GOint64=null;
var _t40:GOint64=null;
var _t41:Bool=false;
var _t42:Bool=false;
var _t43:Bool=false;
var _t44:GOint64=null;
var _t45:GOint64=null;
var _t46:Bool=false;
var _t47:GOint64=null;
var _t48:Bool=false;
var _t49:GOint64=null;
var _t50:GOint64=null;
var _t51:Int=0;
var _SF3:StackFrame;
var _t52:GOint64=null;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_g : GOint64) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fadd64(0,[], p_f, p_g).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_g : GOint64) : GOint64 {
var _sf=new Go_runtime_fadd64(_gr,[], p_f, p_g).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64) : Go_runtime_fadd64
{return new Go_runtime_fadd64(gr,_bds, p_f, p_g);
}
public function run():Go_runtime_fadd64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1554,0);
this.setPH(1555);
_SF1=Go_runtime_funpack64.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(1555,-1);
_t0=_SF1.res();
 // _t0 = funpack64(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:196:33
this.SubFn0();
this.setPH(1556);
_SF2=Go_runtime_funpack64.call(this._goroutine,[],p_g);
_Next = -2;
return this;
case -2:
this.setLatest(1556,-2);
_t6=_SF2.res();
 // _t6 = funpack64(g) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:197:33
this.SubFn1();
_Phi=0;
case 1: // switch.body
this.setLatest(1556,1);
this.setPH(1561);
_res= GOint64.make(0x7ff00000,0x1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 9218868437227405313:uint64 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:202:3

case 2: // switch.body
this.setLatest(1561,2);
this.setPH(1564);
_res= GOint64.make(0x7ff00000,0x1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 9218868437227405313:uint64 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:205:3

case 3: // switch.next
this.setLatest(1564,3);
this.SubFn2();
_Phi=3;
case 4: // binop.rhs
this.setLatest(1564,4);
this.SubFn3();
_Phi=4;
case 5: // binop.done
this.setLatest(1564,5);
this.setPH(1560);
_t12=((_Phi==0)?true:(_Phi==4)?_t11:false); // _t12 = phi [0.entry: true:bool, 4.binop.rhs: t11] #|| *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:201:10
this.SubFn4();
_Phi=5;
case 6: // switch.body
this.setLatest(1560,6);
this.setPH(1567);
_res= p_f;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return f *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:208:3

case 7: // switch.next
this.setLatest(1567,7);
this.SubFn5();
_Phi=7;
case 8: // binop.rhs
this.setLatest(1567,8);
this.SubFn6();
_Phi=8;
case 9: // binop.done
this.setLatest(1567,9);
this.setPH(1563);
_t14=((_Phi==3)?false:(_Phi==10)?false:(_Phi==8)?_t13:false); // _t14 = phi [3.switch.next: false:bool, 10.cond.true: false:bool, 8.binop.rhs: t13] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:204:16
this.SubFn7();
_Phi=9;
case 10: // cond.true
this.setLatest(1563,10);
this.SubFn8();
_Phi=10;
case 11: // switch.body
this.setLatest(1563,11);
this.setPH(1570);
_res= p_g;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return g *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:211:3

case 12: // switch.next
this.setLatest(1570,12);
this.SubFn9();
_Phi=12;
case 13: // switch.body
this.setLatest(1570,13);
this.setPH(1573);
_res= p_f;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return f *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:214:3

case 14: // switch.next
this.setLatest(1573,14);
this.SubFn10();
_Phi=14;
case 15: // switch.body
this.setLatest(1573,15);
this.SubFn11();
_Phi=15;
case 16: // switch.next
this.setLatest(1573,16);
this.SubFn12();
_Phi=16;
case 17: // binop.rhs
this.setLatest(1573,17);
this.SubFn13();
_Phi=17;
case 18: // binop.done
this.setLatest(1573,18);
this.setPH(1572);
_t19=((_Phi==14)?false:(_Phi==20)?false:(_Phi==19)?false:(_Phi==17)?_t18:false); // _t19 = phi [14.switch.next: false:bool, 20.cond.true: false:bool, 19.cond.true: false:bool, 17.binop.rhs: t18] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:213:37
this.SubFn14();
_Phi=18;
case 19: // cond.true
this.setLatest(1572,19);
this.SubFn15();
_Phi=19;
case 20: // cond.true
this.setLatest(1572,20);
this.SubFn16();
_Phi=20;
case 21: // switch.body
this.setLatest(1572,21);
this.setPH(1582);
_res= p_f;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return f *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:223:3

case 22: // switch.next
this.setLatest(1582,22);
this.SubFn17();
_Phi=22;
case 23: // if.then
this.setLatest(1582,23);
this.SubFn18();
_Phi=23;
case 24: // if.done
this.setLatest(1582,24);
this.setPH(1554);
_t24=((_Phi==15)?p_g:(_Phi==23)?_t23:GOint64.make(0,0)); // _t24 = phi [15.switch.body: g, 23.if.then: t23] #g *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:195:16
this.setPH(1579);
_res= _t24;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t24 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:220:3

case 25: // switch.next
this.setLatest(1579,25);
this.SubFn19();
_Phi=25;
case 26: // if.then
this.setLatest(1579,26);
this.SubFn20();
_Phi=26;
case 27: // if.done
this.setLatest(1579,27);
this.setPH(1555);
_t26=((_Phi==28)?_t1:(_Phi==29)?_t1:(_Phi==26)?_t7:GOint64.make(0,0)); // _t26 = phi [28.cond.false: t1, 29.cond.true: t1, 26.if.then: t7] #fs *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:196:2
_t27=((_Phi==28)?_t2:(_Phi==29)?_t2:(_Phi==26)?_t8:GOint64.make(0,0)); // _t27 = phi [28.cond.false: t2, 29.cond.true: t2, 26.if.then: t8] #fm *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:196:6
_t28=((_Phi==28)?_t3:(_Phi==29)?_t3:(_Phi==26)?_t9:0); // _t28 = phi [28.cond.false: t3, 29.cond.true: t3, 26.if.then: t9] #fe *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:196:10
this.setPH(1556);
_t29=((_Phi==28)?_t7:(_Phi==29)?_t7:(_Phi==26)?_t1:GOint64.make(0,0)); // _t29 = phi [28.cond.false: t7, 29.cond.true: t7, 26.if.then: t1] #gs *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:197:2
_t30=((_Phi==28)?_t8:(_Phi==29)?_t8:(_Phi==26)?_t2:GOint64.make(0,0)); // _t30 = phi [28.cond.false: t8, 29.cond.true: t8, 26.if.then: t2] #gm *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:197:6
_t31=((_Phi==28)?_t9:(_Phi==29)?_t9:(_Phi==26)?_t3:0); // _t31 = phi [28.cond.false: t9, 29.cond.true: t9, 26.if.then: t3] #ge *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:197:10
this.SubFn21();
_Phi=27;
case 28: // cond.false
this.setLatest(1556,28);
this.SubFn22();
_Phi=28;
case 29: // cond.true
this.setLatest(1556,29);
this.SubFn23();
_Phi=29;
case 30: // if.then
this.setLatest(1556,30);
this.SubFn24();
_Phi=30;
case 31: // if.done
this.setLatest(1556,31);
this.setPH(1555);
_t45=((_Phi==30)?_t44:(_Phi==32)?_t47:(_Phi==33)?_t49:GOint64.make(0,0)); // _t45 = phi [30.if.then: t44, 32.if.else: t47, 33.if.then: t49] #fm *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:196:6
this.SubFn25();
_Phi=31;
case 32: // if.else
this.setLatest(1555,32);
this.SubFn26();
_Phi=32;
case 33: // if.then
this.setLatest(1555,33);
this.SubFn27();
_Phi=33;
case 34: // if.then
this.setLatest(1555,34);
this.SubFn28();
_Phi=34;
case 35: // if.done
this.setLatest(1555,35);
_t50=((_Phi==31)?_t26:(_Phi==34)?GOint64.make(0x0,0x0):GOint64.make(0,0)); // _t50 = phi [31.if.done: t26, 34.if.then: 0:uint64] #fs *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:196:2
this.SubFn29();
this.setPH(1606);
_SF3=Go_runtime_fpack64.call(this._goroutine,[],_t50,_t45,_t51,_t38);
_Next = -3;
return this;
case -3:
this.setLatest(1606,-3);
_t52=_SF3.res();
 // _t52 = fpack64(t50, t45, t51, t38) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:247:16
_res= _t52;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t52 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:247:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
_t3=_t0.r2; // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
_t4=_t0.r3; // _t4 = extract t0 #3 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
_t5=_t0.r4; // _t5 = extract t0 #4 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
}// end SubFn0
private inline  function SubFn1():Void {
_t7=_t6.r0; // _t7 = extract t6 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
_t8=_t6.r1; // _t8 = extract t6 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
_t9=_t6.r2; // _t9 = extract t6 #2 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
_t10=_t6.r3; // _t10 = extract t6 #3 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
_t11=_t6.r4; // _t11 = extract t6 #4 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
_Next=_t5 ? 5 : 4; // if t5 goto 5.binop.done else 4.binop.rhs *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
}// end SubFn1
private inline  function SubFn2():Void {
_Next=_t4 ? 10 : 9; // if t4 goto 10.cond.true else 9.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
}// end SubFn2
private inline  function SubFn3():Void {
_Next=5; // jump 5.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
}// end SubFn3
private inline  function SubFn4():Void {
_Next=_t12 ? 1 : 3; // if t12 goto 1.switch.body else 3.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
}// end SubFn4
private inline  function SubFn5():Void {
_Next=_t4 ? 6 : 12; // if t4 goto 6.switch.body else 12.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:247:2
}// end SubFn5
private inline  function SubFn6():Void {
this.setPH(1563);
_t13=(GOint64.ucompare(_t1,_t7)!=0); // _t13 = t1 != t7 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:204:22
_Next=9; // jump 9.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:204:22
}// end SubFn6
private inline  function SubFn7():Void {
_Next=_t14 ? 2 : 7; // if t14 goto 2.switch.body else 7.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:204:22
}// end SubFn7
private inline  function SubFn8():Void {
_Next=_t10 ? 8 : 9; // if t10 goto 8.binop.rhs else 9.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:204:22
}// end SubFn8
private inline  function SubFn9():Void {
_Next=_t10 ? 11 : 14; // if t10 goto 11.switch.body else 14.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:204:22
}// end SubFn9
private inline  function SubFn10():Void {
var _t15:Bool;
this.setPH(1572);
_t15=(GOint64.ucompare(_t2,GOint64.make(0x0,0x0))==0); // _t15 = t2 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:213:10
_Next=_t15 ? 20 : 18; // if t15 goto 20.cond.true else 18.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:213:10
}// end SubFn10
private inline  function SubFn11():Void {
var _t16:Bool;
this.setPH(1576);
_t16=(GOint64.ucompare(_t8,GOint64.make(0x0,0x0))==0); // _t16 = t8 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:217:9
_Next=_t16 ? 23 : 24; // if t16 goto 23.if.then else 24.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:217:9
}// end SubFn11
private inline  function SubFn12():Void {
var _t17:Bool;
this.setPH(1575);
_t17=(GOint64.ucompare(_t2,GOint64.make(0x0,0x0))==0); // _t17 = t2 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:216:10
_Next=_t17 ? 15 : 22; // if t17 goto 15.switch.body else 22.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:216:10
}// end SubFn12
private inline  function SubFn13():Void {
this.setPH(1572);
_t18=(GOint64.ucompare(_t7,GOint64.make(0x0,0x0))!=0); // _t18 = t7 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:213:43
_Next=18; // jump 18.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:213:43
}// end SubFn13
private inline  function SubFn14():Void {
_Next=_t19 ? 13 : 16; // if t19 goto 13.switch.body else 16.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:213:43
}// end SubFn14
private inline  function SubFn15():Void {
var _t20:Bool;
_t20=(GOint64.ucompare(_t1,GOint64.make(0x0,0x0))!=0); // _t20 = t1 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:213:32
_Next=_t20 ? 17 : 18; // if t20 goto 17.binop.rhs else 18.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:213:32
}// end SubFn15
private inline  function SubFn16():Void {
var _t21:Bool;
_t21=(GOint64.ucompare(_t8,GOint64.make(0x0,0x0))==0); // _t21 = t8 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:213:21
_Next=_t21 ? 19 : 18; // if t21 goto 19.cond.true else 18.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:213:21
}// end SubFn16
private inline  function SubFn17():Void {
var _t22:Bool;
this.setPH(1581);
_t22=(GOint64.ucompare(_t8,GOint64.make(0x0,0x0))==0); // _t22 = t8 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:222:10
_Next=_t22 ? 21 : 25; // if t22 goto 21.switch.body else 25.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:222:10
}// end SubFn17
private inline  function SubFn18():Void {
_t23=Force.toUint64(GOint64.xor(p_g,_t7)); // _t23 = g ^ t7 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:222:10
_Next=24; // jump 24.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:222:10
}// end SubFn18
private inline  function SubFn19():Void {
var _t25:Bool;
this.setPH(1586);
_t25=(_t3<_t9); // _t25 = t3 < t9 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:227:8
_Next=_t25 ? 26 : 28; // if t25 goto 26.if.then else 28.cond.false *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:227:8
}// end SubFn19
private inline  function SubFn20():Void {
_Next=27; // jump 27.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:227:8
}// end SubFn20
private inline  function SubFn21():Void {
var _t32:Int;
var _t36:GOint64;
var _t37:GOint64;
var _t39:GOint64;
var _t41:Bool;
this.setPH(1590);
_t32=(_t28-_t31); // _t32 = t28 - t31 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:231:19
_t33=_t32; // _t33 = convert uint <- int (t32) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:231:15
_t34=Force.toUint64(GOint64.shl(_t27,GOint64.toInt(GOint64.make(0x0,0x2)))); // _t34 = t27 << 2:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:231:15
_t35=Force.toUint64(GOint64.shl(_t30,GOint64.toInt(GOint64.make(0x0,0x2)))); // _t35 = t30 << 2:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:231:15
this.setPH(1593);
_t36=Force.toUint64(GOint64.shl(GOint64.make(0x0,0x1),_t33)); // _t36 = 1:uint64 << t33 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:234:18
_t37=Force.toUint64(GOint64.sub(_t36,GOint64.make(0x0,0x1))); // _t37 = t36 - 1:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:234:26
_t38=Force.toUint64(GOint64.and(_t35,_t37)); // _t38 = t35 & t37 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:234:14
_t39=GOint64.ofInt(_t33); // _t39 = convert uint64 <- uint (t33) *ssa.Convert near /usr/local/go/src/pkg/runtime/softfloat64.go:234:14
_t40=Force.toUint64(GOint64.ushr(_t35,GOint64.toInt(_t39))); // _t40 = t35 >> t39 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:234:14
this.setPH(1595);
_t41=(GOint64.ucompare(_t26,_t29)==0); // _t41 = t26 == t29 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:236:8
_Next=_t41 ? 30 : 32; // if t41 goto 30.if.then else 32.if.else *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:236:8
}// end SubFn21
private inline  function SubFn22():Void {
var _t42:Bool;
this.setPH(1586);
_t42=(_t3==_t9); // _t42 = t3 == t9 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:227:19
_Next=_t42 ? 29 : 27; // if t42 goto 29.cond.true else 27.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:227:19
}// end SubFn22
private inline  function SubFn23():Void {
var _t43:Bool;
_t43=(GOint64.ucompare(_t2,_t8)<0); // _t43 = t2 < t8 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:227:31
_Next=_t43 ? 26 : 27; // if t43 goto 26.if.then else 27.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:227:31
}// end SubFn23
private inline  function SubFn24():Void {
_t44=Force.toUint64(GOint64.add(_t34,_t40)); // _t44 = t34 + t40 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:227:31
_Next=31; // jump 31.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:227:31
}// end SubFn24
private inline  function SubFn25():Void {
var _t46:Bool;
this.setPH(1603);
_t46=(GOint64.ucompare(_t45,GOint64.make(0x0,0x0))==0); // _t46 = t45 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:244:8
_Next=_t46 ? 34 : 35; // if t46 goto 34.if.then else 35.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:244:8
}// end SubFn25
private inline  function SubFn26():Void {
var _t48:Bool;
_t47=Force.toUint64(GOint64.sub(_t34,_t40)); // _t47 = t34 - t40 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:244:8
this.setPH(1599);
_t48=(GOint64.ucompare(_t38,GOint64.make(0x0,0x0))!=0); // _t48 = t38 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:240:12
_Next=_t48 ? 33 : 31; // if t48 goto 33.if.then else 31.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:240:12
}// end SubFn26
private inline  function SubFn27():Void {
_t49=Force.toUint64(GOint64.sub(_t47,GOint64.make(0x0,0x1))); // _t49 = t47 - 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:240:12
_Next=31; // jump 31.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:240:12
}// end SubFn27
private inline  function SubFn28():Void {
_Next=35; // jump 35.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:240:12
}// end SubFn28
private inline  function SubFn29():Void {
this.setPH(1606);
_t51=(_t28-2); // _t51 = t28 - 2:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:247:27
}// end SubFn29
}
#if js @:expose("Go__star_runtime_dot_MemProfileRecord_InUseObjects") #end class Go__star_runtime_dot_MemProfileRecord_InUseObjects extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/debug.go:63:28
var p_r:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Pointer) {
super(gr,1143,"Go__star_runtime_dot_MemProfileRecord_InUseObjects");
this._bds=_bds;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _t0:Pointer=null;
var _t1:GOint64=null;
var _t2:Pointer=null;
var _t3:GOint64=null;
var _t4:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_r : Pointer) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_MemProfileRecord_InUseObjects(0,[], p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r : Pointer) : GOint64 {
var _sf=new Go__star_runtime_dot_MemProfileRecord_InUseObjects(_gr,[], p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r : Pointer) : Go__star_runtime_dot_MemProfileRecord_InUseObjects
{return new Go__star_runtime_dot_MemProfileRecord_InUseObjects(gr,_bds, p_r);
}
public function run():Go__star_runtime_dot_MemProfileRecord_InUseObjects {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1143,0);
this.SubFn0();
this.setPH(1144);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ /usr/local/go/src/pkg/runtime/debug.go:64:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Pointer;
var _t1:GOint64;
var _t2:Pointer;
var _t3:GOint64;
_t0=p_r.addr(2);  // _t0 = &r.AllocObjects [#2] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/debug.go:64:11 [POINTER]
_t1=_t0.load(); // _t1 = *t0 *ssa.UnOp near /usr/local/go/src/pkg/runtime/debug.go:64:11
_t2=p_r.addr(3);  // _t2 = &r.FreeObjects [#3] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/debug.go:64:28 [POINTER]
_t3=_t2.load(); // _t3 = *t2 *ssa.UnOp near /usr/local/go/src/pkg/runtime/debug.go:64:28
_t4=Force.toInt64(GOint64.sub(_t1,_t3)); // _t4 = t1 - t3 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/debug.go:64:24
}// end SubFn0
}
#if js @:expose("Go_utf8_DecodeRuneInString") #end class Go_utf8_DecodeRuneInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:229:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,3301,"Go_utf8_DecodeRuneInString");
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
this.setLatest(3301,0);
this.setPH(3302);
_SF1=Go_utf8_decodeRuneInStringInternal.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(3302,-1);
_t0=_SF1.res();
 // _t0 = decodeRuneInStringInternal(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:230:41
this.SubFn0();
this.setPH(3303);
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
#if (!php) private #end class Go_runtime_fpack64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:93:6
var p_sign:GOint64;
var p_mant:GOint64;
var p_exp:Int;
var p_trunc:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_sign : GOint64, p_mant : GOint64, p_exp : Int, p_trunc : GOint64) {
super(gr,1452,"Go_runtime_fpack64");
this._bds=_bds;
this.p_sign=p_sign;
this.p_mant=p_mant;
this.p_exp=p_exp;
this.p_trunc=p_trunc;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _t0:Bool=false;
var _t1:GOint64=null;
var _t2:Int=0;
var _t3:GOint64=null;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:GOint64=null;
var _t7:GOint64=null;
var _t8:GOint64=null;
var _t9:Int=0;
var _t10:Bool=false;
var _t11:GOint64=null;
var _t12:Int=0;
var _t13:GOint64=null;
var _t14:Bool=false;
var _t15:GOint64=null;
var _t16:Bool=false;
var _t17:GOint64=null;
var _t18:Int=0;
var _t19:Bool=false;
var _t20:GOint64=null;
var _t21:Bool=false;
var _t22:GOint64=null;
var _t23:Int=0;
var _t24:GOint64=null;
var _t25:Int=0;
var _t26:Bool=false;
var _t27:GOint64=null;
var _t28:Bool=false;
var _t29:GOint64=null;
var _t30:Int=0;
var _t31:GOint64=null;
var _t32:Bool=false;
var _t33:Bool=false;
var _t34:GOint64=null;
var _t35:Int=0;
var _t36:Int=0;
var _t37:GOint64=null;
var _t38:GOint64=null;
var _t39:GOint64=null;
var _t40:GOint64=null;
var _t41:GOint64=null;
var _t42:GOint64=null;
var _t43:GOint64=null;
var _t44:GOint64=null;
var _t45:GOint64=null;
var _t46:Int=0;
var _t47:GOint64=null;
var _t48:Bool=false;
var _t49:GOint64=null;
var _t50:Int=0;
var _t51:GOint64=null;
var _t52:Bool=false;
var _t53:GOint64=null;
var _t54:GOint64=null;
var _t55:GOint64=null;
var _t56:Int=0;
var _t57:Bool=false;
var _t58:Bool=false;
var _t59:GOint64=null;
var _t60:Bool=false;
var _t61:GOint64=null;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_sign : GOint64, p_mant : GOint64, p_exp : Int, p_trunc : GOint64) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fpack64(0,[], p_sign, p_mant, p_exp, p_trunc).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_sign : GOint64, p_mant : GOint64, p_exp : Int, p_trunc : GOint64) : GOint64 {
var _sf=new Go_runtime_fpack64(_gr,[], p_sign, p_mant, p_exp, p_trunc).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_sign : GOint64, p_mant : GOint64, p_exp : Int, p_trunc : GOint64) : Go_runtime_fpack64
{return new Go_runtime_fpack64(gr,_bds, p_sign, p_mant, p_exp, p_trunc);
}
public function run():Go_runtime_fpack64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1452,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(1452,1);
this.setPH(1455);
_res= p_sign;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return sign *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:96:3

case 2: // for.body
this.setLatest(1455,2);
this.SubFn1();
_Phi=2;
case 3: // for.loop
this.setLatest(1455,3);
this.setPH(1452);
_t3=((_Phi==0)?p_mant:(_Phi==2)?_t1:GOint64.make(0,0)); // _t3 = phi [0.entry: mant, 2.for.body: t1] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:20
_t4=((_Phi==0)?p_exp:(_Phi==2)?_t2:0); // _t4 = phi [0.entry: exp, 2.for.body: t2] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:33
this.SubFn2();
_Phi=3;
case 4: // for.body
this.setLatest(1452,4);
this.SubFn3();
_Phi=4;
case 5: // for.done
this.setLatest(1452,5);
this.SubFn4();
_Phi=5;
case 6: // for.loop
this.setLatest(1452,6);
_t11=((_Phi==3)?_t3:(_Phi==4)?_t8:GOint64.make(0,0)); // _t11 = phi [3.for.loop: t3, 4.for.body: t8] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:20
_t12=((_Phi==3)?_t4:(_Phi==4)?_t9:0); // _t12 = phi [3.for.loop: t4, 4.for.body: t9] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:33
_t13=((_Phi==3)?p_trunc:(_Phi==4)?_t7:GOint64.make(0,0)); // _t13 = phi [3.for.loop: trunc, 4.for.body: t7] #trunc *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:42
this.SubFn5();
_Phi=6;
case 7: // if.then
this.setLatest(1452,7);
this.SubFn6();
_Phi=7;
case 8: // if.done
this.setLatest(1452,8);
_t17=((_Phi==5)?_t11:(_Phi==10)?_t24:GOint64.make(0,0)); // _t17 = phi [5.for.done: t11, 10.if.done: t24] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:20
_t18=((_Phi==5)?_t12:(_Phi==10)?_t25:0); // _t18 = phi [5.for.done: t12, 10.if.done: t25] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:33
this.SubFn7();
_Phi=8;
case 9: // if.then
this.setLatest(1452,9);
this.SubFn8();
_Phi=9;
case 10: // if.done
this.setLatest(1452,10);
_t22=((_Phi==7)?_t11:(_Phi==12)?_t11:(_Phi==9)?_t20:(_Phi==13)?_t29:GOint64.make(0,0)); // _t22 = phi [7.if.then: t11, 12.cond.false: t11, 9.if.then: t20, 13.if.then: t29] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:20
_t23=((_Phi==7)?_t12:(_Phi==12)?_t12:(_Phi==9)?_t12:(_Phi==13)?_t30:0); // _t23 = phi [7.if.then: t12, 12.cond.false: t12, 9.if.then: t12, 13.if.then: t30] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:33
this.SubFn9();
_Phi=10;
case 11: // cond.true
this.setLatest(1452,11);
this.SubFn10();
_Phi=11;
case 12: // cond.false
this.setLatest(1452,12);
this.SubFn11();
_Phi=12;
case 13: // if.then
this.setLatest(1452,13);
this.SubFn12();
_Phi=13;
case 14: // if.then
this.setLatest(1452,14);
this.SubFn13();
this.setPH(1478);
_res= _t31;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t31 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:119:3

case 15: // if.done
this.setLatest(1478,15);
this.SubFn14();
_Phi=15;
case 16: // if.then
this.setLatest(1478,16);
this.SubFn15();
_Phi=16;
case 17: // if.done
this.setLatest(1478,17);
this.setPH(1452);
_t34=((_Phi==15)?_t17:(_Phi==24)?_t55:GOint64.make(0,0)); // _t34 = phi [15.if.done: t17, 24.if.done: t55] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:20
_t35=((_Phi==15)?_t18:(_Phi==24)?_t56:0); // _t35 = phi [15.if.done: t18, 24.if.done: t56] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:33
this.SubFn16();
this.setPH(1500);
_res= _t41;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t41 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:141:2

case 18: // if.then
this.setLatest(1500,18);
this.SubFn17();
this.setPH(1482);
_res= _t42;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t42 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:123:4

case 19: // if.done
this.setLatest(1482,19);
this.SubFn18();
_Phi=19;
case 20: // for.body
this.setLatest(1482,20);
this.SubFn19();
_Phi=20;
case 21: // for.done
this.setLatest(1482,21);
this.SubFn20();
_Phi=21;
case 22: // for.loop
this.setLatest(1482,22);
this.setPH(1452);
_t49=((_Phi==19)?p_mant:(_Phi==20)?_t45:GOint64.make(0,0)); // _t49 = phi [19.if.done: mant, 20.for.body: t45] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:20
_t50=((_Phi==19)?p_exp:(_Phi==20)?_t46:0); // _t50 = phi [19.if.done: exp, 20.for.body: t46] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:33
_t51=((_Phi==19)?p_trunc:(_Phi==20)?_t44:GOint64.make(0,0)); // _t51 = phi [19.if.done: trunc, 20.for.body: t44] #trunc *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:42
this.SubFn21();
_Phi=22;
case 23: // if.then
this.setLatest(1452,23);
this.SubFn22();
_Phi=23;
case 24: // if.done
this.setLatest(1452,24);
_t54=((_Phi==21)?_t49:(_Phi==26)?_t49:(_Phi==23)?_t53:GOint64.make(0,0)); // _t54 = phi [21.for.done: t49, 26.cond.false: t49, 23.if.then: t53] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:93:20
this.SubFn23();
_Phi=24;
case 25: // cond.true
this.setLatest(1452,25);
this.SubFn24();
_Phi=25;
case 26: // cond.false
this.setLatest(1452,26);
this.SubFn25();
_Phi=26;
case 27: // if.then
this.setLatest(1452,27);
this.SubFn26();
this.setPH(1497);
_res= _t61;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t61 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:138:4

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(1454);
_t0=(GOint64.ucompare(p_mant,GOint64.make(0x0,0x0))==0); // _t0 = mant == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:95:10
_Next=_t0 ? 1 : 3; // if t0 goto 1.if.then else 3.for.loop *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:95:10
}// end SubFn0
private inline  function SubFn1():Void {
_t1=Force.toUint64(GOint64.shl(_t3,GOint64.toInt(GOint64.make(0x0,0x1)))); // _t1 = t3 << 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:95:10
_t2=(_t4-1); // _t2 = t4 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:95:10
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:95:10
}// end SubFn1
private inline  function SubFn2():Void {
var _t5:Bool;
this.setPH(1457);
_t5=(GOint64.ucompare(_t3,GOint64.make(0x100000,0x0))<0); // _t5 = t3 < 4503599627370496:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:98:11
_Next=_t5 ? 2 : 6; // if t5 goto 2.for.body else 6.for.loop *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:98:11
}// end SubFn2
private inline  function SubFn3():Void {
var _t6:GOint64;
this.setPH(1462);
_t6=Force.toUint64(GOint64.and(_t11,GOint64.make(0x0,0x1))); // _t6 = t11 & 1:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:103:17
_t7=Force.toUint64(GOint64.or(_t13,_t6)); // _t7 = t13 | t6 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:103:17
_t8=Force.toUint64(GOint64.ushr(_t11,GOint64.toInt(GOint64.make(0x0,0x1)))); // _t8 = t11 >> 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:103:17
_t9=(_t12+1); // _t9 = t12 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:103:17
_Next=6; // jump 6.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:103:17
}// end SubFn3
private inline  function SubFn4():Void {
var _t10:Bool;
this.setPH(1466);
_t10=(GOint64.ucompare(_t11,GOint64.make(0x200000,0x0))>=0); // _t10 = t11 >= 9007199254740992:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:107:10
_Next=_t10 ? 7 : 8; // if t10 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:107:10
}// end SubFn4
private inline  function SubFn5():Void {
var _t14:Bool;
this.setPH(1461);
_t14=(GOint64.ucompare(_t11,GOint64.make(0x400000,0x0))>=0); // _t14 = t11 >= 18014398509481984:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:102:11
_Next=_t14 ? 4 : 5; // if t14 goto 4.for.body else 5.for.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:102:11
}// end SubFn5
private inline  function SubFn6():Void {
var _t15:GOint64;
var _t16:Bool;
this.setPH(1467);
_t15=Force.toUint64(GOint64.and(_t11,GOint64.make(0x0,0x1))); // _t15 = t11 & 1:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:108:10
_t16=(GOint64.ucompare(_t15,GOint64.make(0x0,0x0))!=0); // _t16 = t15 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:108:13
_Next=_t16 ? 11 : 10; // if t16 goto 11.cond.true else 10.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:108:13
}// end SubFn6
private inline  function SubFn7():Void {
var _t19:Bool;
this.setPH(1477);
_t19=(_t18>=1024); // _t19 = t18 >= 1024:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:118:9
_Next=_t19 ? 14 : 15; // if t19 goto 14.if.then else 15.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:118:9
}// end SubFn7
private inline  function SubFn8():Void {
var _t21:Bool;
_t20=Force.toUint64(GOint64.add(_t11,GOint64.make(0x0,0x1))); // _t20 = t11 + 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:118:9
this.setPH(1469);
_t21=(GOint64.ucompare(_t20,GOint64.make(0x400000,0x0))>=0); // _t21 = t20 >= 18014398509481984:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:110:12
_Next=_t21 ? 13 : 10; // if t21 goto 13.if.then else 10.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:110:12
}// end SubFn8
private inline  function SubFn9():Void {
_t24=Force.toUint64(GOint64.ushr(_t22,GOint64.toInt(GOint64.make(0x0,0x1)))); // _t24 = t22 >> 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:110:12
_t25=(_t23+1); // _t25 = t23 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:110:12
_Next=8; // jump 8.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:110:12
}// end SubFn9
private inline  function SubFn10():Void {
var _t26:Bool;
this.setPH(1467);
_t26=(GOint64.ucompare(_t13,GOint64.make(0x0,0x0))!=0); // _t26 = t13 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:108:28
_Next=_t26 ? 9 : 12; // if t26 goto 9.if.then else 12.cond.false *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:108:28
}// end SubFn10
private inline  function SubFn11():Void {
var _t27:GOint64;
var _t28:Bool;
_t27=Force.toUint64(GOint64.and(_t11,GOint64.make(0x0,0x2))); // _t27 = t11 & 2:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:108:40
_t28=(GOint64.ucompare(_t27,GOint64.make(0x0,0x0))!=0); // _t28 = t27 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:108:43
_Next=_t28 ? 9 : 10; // if t28 goto 9.if.then else 10.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:108:43
}// end SubFn11
private inline  function SubFn12():Void {
_t29=Force.toUint64(GOint64.ushr(_t20,GOint64.toInt(GOint64.make(0x0,0x1)))); // _t29 = t20 >> 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:108:43
_t30=(_t12+1); // _t30 = t12 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:108:43
_Next=10; // jump 10.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:108:43
}// end SubFn12
private inline  function SubFn13():Void {
this.setPH(1478);
_t31=Force.toUint64(GOint64.xor(p_sign,GOint64.make(0x7ff00000,0x0))); // _t31 = sign ^ 9218868437227405312:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:119:15
}// end SubFn13
private inline  function SubFn14():Void {
var _t32:Bool;
this.setPH(1480);
_t32=(_t18<(-1022)); // _t32 = t18 < -1022:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:121:9
_Next=_t32 ? 16 : 17; // if t32 goto 16.if.then else 17.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:121:9
}// end SubFn14
private inline  function SubFn15():Void {
var _t33:Bool;
this.setPH(1481);
_t33=(_t18<(-1075)); // _t33 = t18 < -1075:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:122:10
_Next=_t33 ? 18 : 19; // if t33 goto 18.if.then else 19.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:122:10
}// end SubFn15
private inline  function SubFn16():Void {
var _t36:Int;
var _t37:GOint64;
var _t38:GOint64;
var _t39:GOint64;
var _t40:GOint64;
this.setPH(1500);
_t36=(_t35-(-1023)); // _t36 = t35 - -1023:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:141:26
_t37=GOint64.ofInt(_t36); // _t37 = convert uint64 <- int (t36) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:141:22
_t38=Force.toUint64(GOint64.shl(_t37,52)); // _t38 = t37 << 52:uint *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:141:34
_t39=Force.toUint64(GOint64.or(p_sign,_t38)); // _t39 = sign | t38 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:141:14
_t40=Force.toUint64(GOint64.and(_t34,GOint64.make(0xfffff,0xffffffff))); // _t40 = t34 & 4503599627370495:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:141:53
_t41=Force.toUint64(GOint64.or(_t39,_t40)); // _t41 = t39 | t40 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:141:47
}// end SubFn16
private inline  function SubFn17():Void {
this.setPH(1482);
_t42=Force.toUint64(GOint64.or(p_sign,GOint64.make(0x0,0x0))); // _t42 = sign | 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:123:16
}// end SubFn17
private inline  function SubFn18():Void {
_Next=22; // jump 22.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:123:16
}// end SubFn18
private inline  function SubFn19():Void {
var _t43:GOint64;
this.setPH(1487);
_t43=Force.toUint64(GOint64.and(_t49,GOint64.make(0x0,0x1))); // _t43 = t49 & 1:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:128:18
_t44=Force.toUint64(GOint64.or(_t51,_t43)); // _t44 = t51 | t43 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:128:18
_t45=Force.toUint64(GOint64.ushr(_t49,GOint64.toInt(GOint64.make(0x0,0x1)))); // _t45 = t49 >> 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:128:18
_t46=(_t50+1); // _t46 = t50 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:128:18
_Next=22; // jump 22.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:128:18
}// end SubFn19
private inline  function SubFn20():Void {
var _t47:GOint64;
var _t48:Bool;
this.setPH(1491);
_t47=Force.toUint64(GOint64.and(_t49,GOint64.make(0x0,0x1))); // _t47 = t49 & 1:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:132:10
_t48=(GOint64.ucompare(_t47,GOint64.make(0x0,0x0))!=0); // _t48 = t47 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:132:13
_Next=_t48 ? 25 : 24; // if t48 goto 25.cond.true else 24.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:132:13
}// end SubFn20
private inline  function SubFn21():Void {
var _t52:Bool;
this.setPH(1486);
_t52=(_t50<(-1023)); // _t52 = t50 < -1023:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:127:11
_Next=_t52 ? 20 : 21; // if t52 goto 20.for.body else 21.for.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:127:11
}// end SubFn21
private inline  function SubFn22():Void {
_t53=Force.toUint64(GOint64.add(_t49,GOint64.make(0x0,0x1))); // _t53 = t49 + 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:127:11
_Next=24; // jump 24.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:127:11
}// end SubFn22
private inline  function SubFn23():Void {
var _t57:Bool;
_t55=Force.toUint64(GOint64.ushr(_t54,GOint64.toInt(GOint64.make(0x0,0x1)))); // _t55 = t54 >> 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:127:11
_t56=(_t50+1); // _t56 = t50 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:127:11
this.setPH(1496);
_t57=(GOint64.ucompare(_t55,GOint64.make(0x100000,0x0))<0); // _t57 = t55 < 4503599627370496:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:137:11
_Next=_t57 ? 27 : 17; // if t57 goto 27.if.then else 17.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:137:11
}// end SubFn23
private inline  function SubFn24():Void {
var _t58:Bool;
this.setPH(1491);
_t58=(GOint64.ucompare(_t51,GOint64.make(0x0,0x0))!=0); // _t58 = t51 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:132:28
_Next=_t58 ? 23 : 26; // if t58 goto 23.if.then else 26.cond.false *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:132:28
}// end SubFn24
private inline  function SubFn25():Void {
var _t59:GOint64;
var _t60:Bool;
_t59=Force.toUint64(GOint64.and(_t49,GOint64.make(0x0,0x2))); // _t59 = t49 & 2:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:132:40
_t60=(GOint64.ucompare(_t59,GOint64.make(0x0,0x0))!=0); // _t60 = t59 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:132:43
_Next=_t60 ? 23 : 24; // if t60 goto 23.if.then else 24.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:132:43
}// end SubFn25
private inline  function SubFn26():Void {
this.setPH(1497);
_t61=Force.toUint64(GOint64.or(p_sign,_t55)); // _t61 = sign | t55 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:138:16
}// end SubFn26
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
#if js @:expose("Go_tardisgolib_NumGoroutine") #end class Go_tardisgolib_NumGoroutine extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:42:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,505,"Go_tardisgolib_NumGoroutine");
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
this.setLatest(505,0);
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
#if js @:expose("Go_utf8_DecodeLastRune") #end class Go_utf8_DecodeLastRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:239:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,3311,"Go_utf8_DecodeLastRune");
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
this.setLatest(3311,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(3311,1);
this.setPH(3314);
_res= {r0:65533,r1:0};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:242:3

case 2: // if.done
this.setLatest(3314,2);
this.SubFn1();
_Phi=2;
case 3: // if.then
this.setLatest(3314,3);
this.setPH(3319);
_res= {r0:_t5,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:247:3

case 4: // if.done
this.setLatest(3319,4);
this.SubFn2();
_Phi=4;
case 5: // if.then
this.setLatest(3319,5);
this.SubFn3();
_Phi=5;
case 6: // if.done
this.setLatest(3319,6);
this.setPH(3324);
_t9=((_Phi==4)?_t7:(_Phi==5)?0:0); // _t9 = phi [4.if.done: t7, 5.if.then: 0:int] #lim *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:252:2
this.SubFn4();
_Phi=6;
case 7: // for.body
this.setLatest(3324,7);
this.SubFn5();
this.setPH(3329);
_SF1=Go_utf8_RuneStart.call(this._goroutine,[],_t12);
_Next = -1;
return this;
case -1:
this.setLatest(3329,-1);
_t13=_SF1.res();
 // _t13 = RuneStart(t12) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:15
this.SubFn6();
_Phi=7;
case 8: // for.done
this.setLatest(3329,8);
this.SubFn7();
_Phi=8;
case 9: // for.loop
this.setLatest(3329,9);
this.setPH(3316);
_t15=((_Phi==6)?_t10:(_Phi==10)?_t17:0); // _t15 = phi [6.if.done: t10, 10.if.done: t17] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:244:2
this.SubFn8();
_Phi=9;
case 10: // if.done
this.setLatest(3316,10);
this.SubFn9();
_Phi=10;
case 11: // if.then
this.setLatest(3316,11);
this.SubFn10();
_Phi=11;
case 12: // if.done
this.setLatest(3316,12);
_t18=((_Phi==8)?_t15:(_Phi==11)?0:0); // _t18 = phi [8.for.done: t15, 11.if.then: 0:int] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:244:2
this.SubFn11();
this.setPH(3336);
_SF2=Go_utf8_DecodeRune.call(this._goroutine,[],_t19);
_Next = -2;
return this;
case -2:
this.setLatest(3336,-2);
_t20=_SF2.res();
 // _t20 = DecodeRune(t19) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:22
this.SubFn12();
_Phi=12;
case 13: // if.then
this.setLatest(3336,13);
this.setPH(3338);
_res= {r0:65533,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:266:3

case 14: // if.done
this.setLatest(3338,14);
this.setPH(3340);
_res= {r0:_t21,r1:_t22};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t21, t22 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:268:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Bool;
this.setPH(3312);
_t0=({var _v=p_p;_v==null?0:_v.len();}); // _t0 = len(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:240:12
this.setPH(3313);
_t1=(_t0==0); // _t1 = t0 == 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:241:9
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:241:9
}// end SubFn0
private inline  function SubFn1():Void {
var _t3:Pointer;
var _t4:Int;
var _t6:Bool;
this.setPH(3316);
_t2=(_t0-1); // _t2 = t0 - 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:244:15
this.setPH(3317);
if((_t2<0)||(_t2>=p_p.len())) Scheduler.ioor(); // _t3 = &p[t2] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:12 [POINTER]
_t3=p_p.addr(_t2);  // _t3 = &p[t2] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:12 [POINTER]
_t4=(_t3.load()|0); // _t4 = *t3 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:12
_t5=_t4; // _t5 = convert rune <- byte (t4) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:245:10
this.setPH(3318);
_t6=(_t5<128); // _t6 = t5 < 128:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:246:7
_Next=_t6 ? 3 : 4; // if t6 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:246:7
}// end SubFn1
private inline  function SubFn2():Void {
var _t8:Bool;
this.setPH(3324);
_t7=(_t0-4); // _t7 = t0 - 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:252:13
this.setPH(3325);
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
this.setPH(3329);
if((_t15<0)||(_t15>=p_p.len())) Scheduler.ioor(); // _t11 = &p[t15] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17 [POINTER]
_t11=p_p.addr(_t15);  // _t11 = &p[t15] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17 [POINTER]
_t12=(_t11.load()|0); // _t12 = *t11 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17
}// end SubFn5
private inline  function SubFn6():Void {
_Next=_t13 ? 8 : 10; // if t13 goto 8.for.done else 10.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:257:17
}// end SubFn6
private inline  function SubFn7():Void {
var _t14:Bool;
this.setPH(3333);
_t14=(_t15<0); // _t14 = t15 < 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:261:11
_Next=_t14 ? 11 : 12; // if t14 goto 11.if.then else 12.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:261:11
}// end SubFn7
private inline  function SubFn8():Void {
var _t16:Bool;
this.setPH(3328);
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
this.setPH(3336);
_t19=p_p.subSlice(_t18,_t0); // _t19 = slice p[t18:t0] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:24
}// end SubFn11
private inline  function SubFn12():Void {
var _t23:Int;
var _t24:Bool;
_t21=_t20.r0; // _t21 = extract t20 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:24
_t22=_t20.r1; // _t22 = extract t20 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:264:24
this.setPH(3337);
_t23=(_t18+_t22); // _t23 = t18 + t22 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:265:10
_t24=(_t23!=_t0); // _t24 = t23 != t0 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:265:16
_Next=_t24 ? 13 : 14; // if t24 goto 13.if.then else 14.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:265:16
}// end SubFn12
}
#if (!php) private #end class Go_sync_runtime_Semacquire extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:22:6
var p_s:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Pointer) {
super(gr,549,"Go_sync_runtime_Semacquire");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t1:Int=0;
var _t2:Int=0;
var _t3:Int=0;
var _t4:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_sync_runtime_Semacquire(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_s : Pointer) : Void {
var _sf=new Go_sync_runtime_Semacquire(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : Pointer) : Go_sync_runtime_Semacquire
{return new Go_sync_runtime_Semacquire(gr,_bds, p_s);
}
public function run():Go_sync_runtime_Semacquire {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(549,0);
this.SubFn0();

case 1: // for.body
this.setLatest(549,1);
this.setPH(551);
Go_sync_runtime_Syncsemcheck.call(this._goroutine,[],0);
_Next = -1;
return this;
case -1:
this.setLatest(551,-1);
 // _t0 = runtime_Syncsemcheck(0:uintptr) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:24:23 [REGISTER VALUE UN-USED]
this.SubFn1();

case 2: // for.done
this.setLatest(551,2);
this.SubFn2();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:24:23

case 3: // for.loop
this.setLatest(551,3);
this.SubFn3();

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_Next=3; // jump 3.for.loop *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:24:23
}// end SubFn0
private inline  function SubFn1():Void {
_Next=3; // jump 3.for.loop *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:24:23
}// end SubFn1
private inline  function SubFn2():Void {
var _t1:Int;
var _t2:Int;
this.setPH(553);
_t1=(p_s.load()|0); // _t1 = *s *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:26:2
_t2=Force.toUint32((_t1-1)); // _t2 = t1 - 1:uint32 *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:26:2
p_s.store(_t2); // *s = t2 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:26:2
}// end SubFn2
private inline  function SubFn3():Void {
var _t3:Int;
var _t4:Bool;
this.setPH(550);
_t3=(p_s.load()|0); // _t3 = *s *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:23:6
_t4=(Force.uintCompare(_t3,0)==0); // _t4 = t3 == 0:uint32 *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:23:9
_Next=_t4 ? 1 : 2; // if t4 goto 1.for.body else 2.for.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:23:9
}// end SubFn3
}
#if js @:expose("Go_utf16_Encode") #end class Go_utf16_Encode extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:56:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,3020,"Go_utf16_Encode");
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
this.setLatest(3020,0);
this.SubFn0();
_Phi=0;
case 1: // rangeindex.loop
this.setLatest(3020,1);
this.setPH(3021);
_t2=((_Phi==0)?_t0:(_Phi==2)?_t2:(_Phi==4)?_t11:0); // _t2 = phi [0.entry: t0, 2.rangeindex.body: t2, 4.if.then: t11] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
_t3=((_Phi==0)?(-1):(_Phi==2)?_t4:(_Phi==4)?_t4:0); // _t3 = phi [0.entry: -1:int, 2.rangeindex.body: t4, 4.if.then: t4] *ssa.Phi near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
this.SubFn1();
_Phi=1;
case 2: // rangeindex.body
this.setLatest(3021,2);
this.SubFn2();
_Phi=2;
case 3: // rangeindex.done
this.setLatest(3021,3);
this.SubFn3();
_Phi=3;
case 4: // if.then
this.setLatest(3021,4);
this.SubFn4();
_Phi=4;
case 5: // rangeindex.loop
this.setLatest(3021,5);
_t12=((_Phi==3)?0:(_Phi==9)?_t23:(_Phi==15)?_t37:0); // _t12 = phi [3.rangeindex.done: 0:int, 9.switch.body: t23, 15.switch.next: t37] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
_t13=((_Phi==3)?(-1):(_Phi==9)?_t14:(_Phi==15)?_t14:0); // _t13 = phi [3.rangeindex.done: -1:int, 9.switch.body: t14, 15.switch.next: t14] *ssa.Phi near /usr/local/go/src/pkg/unicode/utf16/utf16.go:57:2
this.SubFn5();
_Phi=5;
case 6: // rangeindex.body
this.setLatest(3021,6);
this.SubFn6();
_Phi=6;
case 7: // rangeindex.done
this.setLatest(3021,7);
this.SubFn7();
this.setPH(3045);
_res= _t19;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t19 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:81:2

case 8: // switch.body
this.setLatest(3045,8);
this.SubFn8();
_Phi=8;
case 9: // switch.body
this.setLatest(3045,9);
this.setPH(3030);
_t20=((_Phi==8)?65533:(_Phi==14)?_t17:0); // _t20 = phi [8.switch.body: 65533:rune, 14.switch.next: t17] #v *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:66:9
this.SubFn9();
_Phi=9;
case 10: // switch.next
this.setLatest(3030,10);
this.SubFn10();
_Phi=10;
case 11: // switch.next
this.setLatest(3030,11);
this.SubFn11();
_Phi=11;
case 12: // binop.rhs
this.setLatest(3030,12);
this.SubFn12();
_Phi=12;
case 13: // binop.done
this.setLatest(3030,13);
this.setPH(3032);
_t27=((_Phi==10)?false:(_Phi==12)?_t26:false); // _t27 = phi [10.switch.next: false:bool, 12.binop.rhs: t26] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:26
this.SubFn13();
_Phi=13;
case 14: // switch.next
this.setLatest(3032,14);
this.SubFn14();
_Phi=14;
case 15: // switch.next
this.setLatest(3032,15);
this.setPH(3039);
_SF1=Go_utf16_EncodeRune.call(this._goroutine,[],_t17);
_Next = -1;
return this;
case -1:
this.setLatest(3039,-1);
_t29=_SF1.res();
 // _t29 = EncodeRune(t17) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:75:24
this.SubFn15();
_Phi=15;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(3021);
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
this.setPH(3023);
_t8=(_t7>=65536); // _t8 = t7 >= 65536:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:59:8
_Next=_t8 ? 4 : 1; // if t8 goto 4.if.then else 1.rangeindex.loop *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:59:8
}// end SubFn2
private inline  function SubFn3():Void {
this.setPH(3028);
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
this.setPH(3032);
_t18=(_t17<0); // _t18 = t17 < 0:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:10
_Next=_t18 ? 8 : 10; // if t18 goto 8.switch.body else 10.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:68:10
}// end SubFn6
private inline  function SubFn7():Void {
this.setPH(3045);
_t19=_t9.subSlice(0,_t12); // _t19 = slice t9[0:int:t12] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:81:10
}// end SubFn7
private inline  function SubFn8():Void {
_Next=9; // jump 9.switch.body *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:81:10
}// end SubFn8
private inline  function SubFn9():Void {
var _t21:Pointer;
var _t22:Int;
this.setPH(3036);
if((_t12<0)||(_t12>=_t9.len())) Scheduler.ioor(); // _t21 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:5 [POINTER]
_t21=_t9.addr(_t12);  // _t21 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:5 [POINTER]
_t22=_t20; // _t22 = convert uint16 <- rune (t20) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
_t21.store(_t22); // *t21 = t22 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
_t23=(_t12+1); // _t23 = t12 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
_Next=5; // jump 5.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:72:17
}// end SubFn9
private inline  function SubFn10():Void {
var _t24:Bool;
this.setPH(3032);
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
this.setPH(3035);
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
this.setPH(3040);
if((_t12<0)||(_t12>=_t9.len())) Scheduler.ioor(); // _t32 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:5 [POINTER]
_t32=_t9.addr(_t12);  // _t32 = &t9[t12] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:5 [POINTER]
_t33=_t30; // _t33 = convert uint16 <- rune (t30) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:17
_t32.store(_t33); // *t32 = t33 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:76:17
this.setPH(3041);
_t34=(_t12+1); // _t34 = t12 + 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:7
if((_t34<0)||(_t34>=_t9.len())) Scheduler.ioor(); // _t35 = &t9[t34] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:5 [POINTER]
_t35=_t9.addr(_t34);  // _t35 = &t9[t34] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:5 [POINTER]
_t36=_t31; // _t36 = convert uint16 <- rune (t31) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
_t35.store(_t36); // *t35 = t36 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
_t37=(_t12+2); // _t37 = t12 + 2:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
_Next=5; // jump 5.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
}// end SubFn15
}
#if js @:expose("Go__star_runtime_dot_MemProfileRecord_Stack") #end class Go__star_runtime_dot_MemProfileRecord_Stack extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/debug.go:69:28
var p_r:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Pointer) {
super(gr,1149,"Go__star_runtime_dot_MemProfileRecord_Stack");
this._bds=_bds;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _t0:Pointer=null;
var _t1:Array<Dynamic>=null;
var _t2:Int=0;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Dynamic=null;
var _t6:Bool=false;
var _t7:Pointer=null;
var _t8:Slice=null;
var _t9:Pointer=null;
var _t10:Slice=null;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_r : Pointer) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_MemProfileRecord_Stack(0,[], p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r : Pointer) : Slice {
var _sf=new Go__star_runtime_dot_MemProfileRecord_Stack(_gr,[], p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r : Pointer) : Go__star_runtime_dot_MemProfileRecord_Stack
{return new Go__star_runtime_dot_MemProfileRecord_Stack(gr,_bds, p_r);
}
public function run():Go__star_runtime_dot_MemProfileRecord_Stack {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1149,0);
this.SubFn0();
_Phi=0;
case 1: // rangeindex.loop
this.setLatest(1149,1);
_t2=((_Phi==0)?(-1):(_Phi==2)?_t3:0); // _t2 = phi [0.entry: -1:int, 2.rangeindex.body: t3] *ssa.Phi near /usr/local/go/src/pkg/unicode/utf16/utf16.go:77:19
this.SubFn1();
_Phi=1;
case 2: // rangeindex.body
this.setLatest(1149,2);
this.SubFn2();
_Phi=2;
case 3: // rangeindex.done
this.setLatest(1149,3);
this.SubFn3();
this.setPH(1155);
_res= _t8;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t8 *ssa.Return @ /usr/local/go/src/pkg/runtime/debug.go:75:2

case 4: // if.then
this.setLatest(1155,4);
this.SubFn4();
this.setPH(1152);
_res= _t10;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t10 *ssa.Return @ /usr/local/go/src/pkg/runtime/debug.go:72:4

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Pointer;
this.setPH(1150);
_t0=p_r.addr(4);  // _t0 = &r.Stack0 [#4] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/debug.go:70:22 [POINTER]
_t1=_t0.load(); // _t1 = *t0 *ssa.UnOp near /usr/local/go/src/pkg/runtime/debug.go:70:22
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/debug.go:70:22
}// end SubFn0
private inline  function SubFn1():Void {
var _t4:Bool;
_t3=(_t2+1); // _t3 = t2 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/debug.go:70:22
_t4=(_t3<32); // _t4 = t3 < 32:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/debug.go:70:22
_Next=_t4 ? 2 : 3; // if t4 goto 2.rangeindex.body else 3.rangeindex.done *ssa.If near /usr/local/go/src/pkg/runtime/debug.go:70:22
}// end SubFn1
private inline  function SubFn2():Void {
var _t6:Bool;
if((_t3<0)||(_t3>=32)) Scheduler.ioor();
_t5=_t1[_t3]; // _t5 = t1[t3] *ssa.Index near /usr/local/go/src/pkg/runtime/debug.go:70:22
this.setPH(1151);
_t6=(Force.uintCompare((_t5|0),(0|0))==0); // _t6 = t5 == 0:uintptr *ssa.BinOp @ /usr/local/go/src/pkg/runtime/debug.go:71:8
_Next=_t6 ? 4 : 1; // if t6 goto 4.if.then else 1.rangeindex.loop *ssa.If near /usr/local/go/src/pkg/runtime/debug.go:71:8
}// end SubFn2
private inline  function SubFn3():Void {
var _t7:Pointer;
this.setPH(1155);
_t7=p_r.addr(4);  // _t7 = &r.Stack0 [#4] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/debug.go:75:11 [POINTER]
_t8=new Slice(_t7,0,-1); // _t8 = slice t7[0:int:] *ssa.Slice @ /usr/local/go/src/pkg/runtime/debug.go:75:17
}// end SubFn3
private inline  function SubFn4():Void {
var _t9:Pointer;
this.setPH(1152);
_t9=p_r.addr(4);  // _t9 = &r.Stack0 [#4] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/debug.go:72:13 [POINTER]
_t10=new Slice(_t9,0,_t3); // _t10 = slice t9[0:int:t3] *ssa.Slice @ /usr/local/go/src/pkg/runtime/debug.go:72:19
}// end SubFn4
}
#if js @:expose("Go_runtime_Callers") #end class Go_runtime_Callers extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:18:6
var p_skip:Int;
var p_pc:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_skip : Int, p_pc : Slice) {
super(gr,435,"Go_runtime_Callers");
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
var _sf=new Go_runtime_Callers(0,[], p_skip, p_pc).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_skip : Int, p_pc : Slice) : Int {
var _sf=new Go_runtime_Callers(_gr,[], p_skip, p_pc).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_skip : Int, p_pc : Slice) : Go_runtime_Callers
{return new Go_runtime_Callers(gr,_bds, p_skip, p_pc);
}
public function run():Go_runtime_Callers {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(435,0);
this.SubFn0();
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(435,-1);
 // panic t0 *ssa.Panic @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:18:49

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"runtime.Callers() not yet implemented"); // _t0 = make interface{} <- string ("runtime.Callers()...":string) *ssa.MakeInterface near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:18:49
}// end SubFn0
}
#if js @:expose("Go_utf16_Decode") #end class Go_utf16_Decode extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:86:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,3050,"Go_utf16_Decode");
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
this.setLatest(3050,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(3050,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(3050,2);
this.SubFn2();
this.setPH(3071);
_res= _t5;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:107:2

case 3: // for.loop
this.setLatest(3071,3);
this.setPH(3052);
_t6=((_Phi==0)?0:(_Phi==4)?_t10:0); // _t6 = phi [0.entry: 0:int, 4.switch.done: t10] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:88:2
this.setPH(3053);
_t7=((_Phi==0)?0:(_Phi==4)?_t12:0); // _t7 = phi [0.entry: 0:int, 4.switch.done: t12] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:6
this.SubFn3();
_Phi=3;
case 4: // switch.done
this.setLatest(3053,4);
this.setPH(3052);
_t10=((_Phi==5)?_t21:(_Phi==6)?_t23:(_Phi==13)?_t40:0); // _t10 = phi [5.switch.body: t21, 6.switch.body: t23, 13.switch.next: t40] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:88:2
this.setPH(3053);
_t11=((_Phi==5)?_t20:(_Phi==6)?_t7:(_Phi==13)?_t7:0); // _t11 = phi [5.switch.body: t20, 6.switch.body: t7, 13.switch.next: t7] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:89:6
this.SubFn4();
_Phi=4;
case 5: // switch.body
this.setLatest(3053,5);
this.SubFn5();
this.setPH(3058);
_SF1=Go_utf16_DecodeRune.call(this._goroutine,[],_t14,_t18);
_Next = -1;
return this;
case -1:
this.setLatest(3058,-1);
_t19=_SF1.res();
 // _t19 = DecodeRune(t14, t18) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:94:21
this.SubFn6();
_Phi=5;
case 6: // switch.body
this.setLatest(3058,6);
this.SubFn7();
_Phi=6;
case 7: // switch.next
this.setLatest(3058,7);
this.SubFn8();
_Phi=7;
case 8: // binop.rhs
this.setLatest(3058,8);
this.SubFn9();
_Phi=8;
case 9: // binop.done
this.setLatest(3058,9);
this.setPH(3056);
_t29=((_Phi==1)?false:(_Phi==12)?false:(_Phi==11)?false:(_Phi==10)?false:(_Phi==8)?_t28:false); // _t29 = phi [1.for.body: false:bool, 12.cond.true: false:bool, 11.cond.true: false:bool, 10.cond.true: false:bool, 8.binop.rhs: t28] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:92:20
this.SubFn10();
_Phi=9;
case 10: // cond.true
this.setLatest(3056,10);
this.SubFn11();
_Phi=10;
case 11: // cond.true
this.setLatest(3056,11);
this.SubFn12();
_Phi=11;
case 12: // cond.true
this.setLatest(3056,12);
this.SubFn13();
_Phi=12;
case 13: // switch.next
this.setLatest(3056,13);
this.SubFn14();
_Phi=13;
case 14: // binop.rhs
this.setLatest(3056,14);
this.SubFn15();
_Phi=14;
case 15: // binop.done
this.setLatest(3056,15);
this.setPH(3061);
_t42=((_Phi==7)?false:(_Phi==14)?_t41:false); // _t42 = phi [7.switch.next: false:bool, 14.binop.rhs: t41] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:19
this.SubFn16();
_Phi=15;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
this.setPH(3051);
_t0=({var _v=p_s;_v==null?0:_v.len();}); // _t0 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:87:23
_t1=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t0) _v[_i]=0; _v;}),0,_t0); // _t1 = make []rune t0 t0 *ssa.MakeSlice @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:87:11
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:87:11
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Pointer;
var _t4:Bool;
this.setPH(3054);
if((_t7<0)||(_t7>=p_s.len())) Scheduler.ioor(); // _t2 = &s[t7] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:90:16 [POINTER]
_t2=p_s.addr(_t7);  // _t2 = &s[t7] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:90:16 [POINTER]
_t3=(_t2.load()|0); // _t3 = *t2 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:90:16
this.setPH(3055);
_t4=(Force.uintCompare(55296,_t3)<=0); // _t4 = 55296:uint16 <= t3 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:14
_Next=_t4 ? 12 : 9; // if t4 goto 12.cond.true else 9.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:91:14
}// end SubFn1
private inline  function SubFn2():Void {
this.setPH(3071);
_t5=_t1.subSlice(0,_t6); // _t5 = slice t1[0:int:t6] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:107:10
}// end SubFn2
private inline  function SubFn3():Void {
var _t8:Int;
var _t9:Bool;
this.setPH(3053);
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
this.setPH(3058);
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
this.setPH(3063);
if((_t6<0)||(_t6>=_t1.len())) Scheduler.ioor(); // _t22 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5 [POINTER]
_t22=_t1.addr(_t6);  // _t22 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5 [POINTER]
_t22.store(65533); // *t22 = 65533:rune *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5
_t23=(_t6+1); // _t23 = t6 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5
_Next=4; // jump 4.switch.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:99:5
}// end SubFn7
private inline  function SubFn8():Void {
var _t24:Bool;
this.setPH(3061);
_t24=(Force.uintCompare(55296,_t3)<=0); // _t24 = 55296:uint16 <= t3 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:14
_Next=_t24 ? 14 : 15; // if t24 goto 14.binop.rhs else 15.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:14
}// end SubFn8
private inline  function SubFn9():Void {
var _t25:Int;
var _t26:Pointer;
var _t27:Int;
this.setPH(3056);
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
this.setPH(3055);
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
this.setPH(3067);
if((_t6<0)||(_t6>=_t1.len())) Scheduler.ioor(); // _t38 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:5 [POINTER]
_t38=_t1.addr(_t6);  // _t38 = &t1[t6] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:5 [POINTER]
_t39=_t3; // _t39 = convert rune <- uint16 (t3) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
_t38.store(_t39); // *t38 = t39 *ssa.Store near /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
_t40=(_t6+1); // _t40 = t6 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
_Next=4; // jump 4.switch.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:103:15
}// end SubFn14
private inline  function SubFn15():Void {
this.setPH(3061);
_t41=(Force.uintCompare(_t3,57344)<0); // _t41 = t3 < 57344:uint16 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
_Next=15; // jump 15.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
}// end SubFn15
private inline  function SubFn16():Void {
_Next=_t42 ? 6 : 13; // if t42 goto 6.switch.body else 13.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24
}// end SubFn16
}
#if js @:expose("Go_atomic_StorePointer") #end class Go_atomic_StorePointer extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:169:6
var p_addr:Pointer;
var p_val:UnsafePointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : UnsafePointer) {
super(gr,755,"Go_atomic_StorePointer");
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
this.setLatest(755,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/unicode/utf16/utf16.go:97:24

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:169:63
}// end SubFn0
}
#if (!php) private #end class Go_runtime_printany extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:103:6
var p_i:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_i : Interface) {
super(gr,871,"Go_runtime_printany");
this._bds=_bds;
this.p_i=p_i;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _t2:{r0:Interface,r1:Bool}=null;
var _t3:Interface=null;
var _t4:Bool=false;
var _SF1:StackFrame;
var _t5:String="";
var _t7:{r0:Interface,r1:Bool}=null;
var _t8:Interface=null;
var _t9:Bool=false;
var _SF2:StackFrame;
var _t10:String="";
var _t12:{r0:Int,r1:Bool}=null;
var _t13:Int=0;
var _t14:Bool=false;
var _t16:{r0:String,r1:Bool}=null;
var _t17:String="";
var _t18:Bool=false;
var _SF3:StackFrame;
var _t20:String="";
var _Next:Int=0;
public static inline function callFromHaxe( p_i : Interface) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_printany(0,[], p_i).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_i : Interface) : Void {
var _sf=new Go_runtime_printany(_gr,[], p_i).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_i : Interface) : Go_runtime_printany
{return new Go_runtime_printany(gr,_bds, p_i);
}
public function run():Go_runtime_printany {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(871,0);
this.SubFn0();

case 1: // typeswitch.done
this.setLatest(871,1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:169:63

case 2: // typeswitch.body
this.setLatest(871,2);
this.SubFn1();

case 3: // typeswitch.next
this.setLatest(871,3);
this.SubFn2();

case 4: // typeswitch.body
this.setLatest(871,4);
this.setPH(876);
_SF1=Interface.invoke(_t3,"String",[this._goroutine,[],_t3.val]);_Next = -1;
return this;
case -1:
this.setLatest(876,-1);
_t5=_SF1.res();
 // _t5 = invoke t3.String() *ssa.Call @ /usr/local/go/src/pkg/runtime/error.go:108:17
this.SubFn3();

case 5: // typeswitch.next
this.setLatest(876,5);
this.SubFn4();

case 6: // typeswitch.body
this.setLatest(876,6);
this.setPH(878);
_SF2=Interface.invoke(_t8,"Error",[this._goroutine,[],_t8.val]);_Next = -2;
return this;
case -2:
this.setLatest(878,-2);
_t10=_SF2.res();
 // _t10 = invoke t8.Error() *ssa.Call @ /usr/local/go/src/pkg/runtime/error.go:110:16
this.SubFn5();

case 7: // typeswitch.next
this.setLatest(878,7);
this.SubFn6();

case 8: // typeswitch.body
this.setLatest(878,8);
this.SubFn7();

case 9: // typeswitch.next
this.setLatest(878,9);
this.SubFn8();

case 10: // typeswitch.body
this.setLatest(878,10);
this.SubFn9();

case 11: // typeswitch.next
this.setLatest(878,11);
this.setPH(884);
_t20=TypeInfo.typeString(p_i); // _t20 = typestring(i) *ssa.Call @ /usr/local/go/src/pkg/runtime/error.go:116:24
this.SubFn10();

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Interface.isEqual(p_i,null); // _t0 = i == nil:interface{} *ssa.BinOp near /usr/local/go/src/pkg/runtime/error.go:116:24
_Next=_t0 ? 2 : 3; // if t0 goto 2.typeswitch.body else 3.typeswitch.next *ssa.If near /usr/local/go/src/pkg/runtime/error.go:116:24
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(874);
trace(Go.CPos(874),"nil"); // _t1 = print("nil":string) *ssa.Call @ /usr/local/go/src/pkg/runtime/error.go:106:8 [REGISTER VALUE UN-USED]
_Next=1; // jump 1.typeswitch.done *ssa.Jump near /usr/local/go/src/pkg/runtime/error.go:106:8
}// end SubFn1
private inline  function SubFn2():Void {
var _t2:{r0:Interface,r1:Bool};
var _t4:Bool;
this.setPH(875);
_t2=Interface.assertOk(1,p_i); // _t2 = typeassert,ok i.(stringer) *ssa.TypeAssert @ /usr/local/go/src/pkg/runtime/error.go:107:2
_t3=_t2.r0; // _t3 = extract t2 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/error.go:107:2
_t4=_t2.r1; // _t4 = extract t2 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/error.go:107:2
_Next=_t4 ? 4 : 5; // if t4 goto 4.typeswitch.body else 5.typeswitch.next *ssa.If near /usr/local/go/src/pkg/runtime/error.go:107:2
}// end SubFn2
private inline  function SubFn3():Void {
this.setPH(876);
trace(Go.CPos(876),_t5); // _t6 = print(t5) *ssa.Call @ /usr/local/go/src/pkg/runtime/error.go:108:8 [REGISTER VALUE UN-USED]
_Next=1; // jump 1.typeswitch.done *ssa.Jump near /usr/local/go/src/pkg/runtime/error.go:108:8
}// end SubFn3
private inline  function SubFn4():Void {
var _t7:{r0:Interface,r1:Bool};
var _t9:Bool;
this.setPH(877);
_t7=Interface.assertOk(2,p_i); // _t7 = typeassert,ok i.(error) *ssa.TypeAssert @ /usr/local/go/src/pkg/runtime/error.go:109:2
_t8=_t7.r0; // _t8 = extract t7 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/error.go:109:2
_t9=_t7.r1; // _t9 = extract t7 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/error.go:109:2
_Next=_t9 ? 6 : 7; // if t9 goto 6.typeswitch.body else 7.typeswitch.next *ssa.If near /usr/local/go/src/pkg/runtime/error.go:109:2
}// end SubFn4
private inline  function SubFn5():Void {
this.setPH(878);
trace(Go.CPos(878),_t10); // _t11 = print(t10) *ssa.Call @ /usr/local/go/src/pkg/runtime/error.go:110:8 [REGISTER VALUE UN-USED]
_Next=1; // jump 1.typeswitch.done *ssa.Jump near /usr/local/go/src/pkg/runtime/error.go:110:8
}// end SubFn5
private inline  function SubFn6():Void {
var _t12:{r0:Int,r1:Bool};
var _t14:Bool;
this.setPH(879);
_t12=Interface.assertOk(3,p_i); // _t12 = typeassert,ok i.(int) *ssa.TypeAssert @ /usr/local/go/src/pkg/runtime/error.go:111:2
_t13=_t12.r0; // _t13 = extract t12 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/error.go:111:2
_t14=_t12.r1; // _t14 = extract t12 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/error.go:111:2
_Next=_t14 ? 8 : 9; // if t14 goto 8.typeswitch.body else 9.typeswitch.next *ssa.If near /usr/local/go/src/pkg/runtime/error.go:111:2
}// end SubFn6
private inline  function SubFn7():Void {
this.setPH(880);
trace(Go.CPos(880),_t13); // _t15 = print(t13) *ssa.Call @ /usr/local/go/src/pkg/runtime/error.go:112:8 [REGISTER VALUE UN-USED]
_Next=1; // jump 1.typeswitch.done *ssa.Jump near /usr/local/go/src/pkg/runtime/error.go:112:8
}// end SubFn7
private inline  function SubFn8():Void {
var _t16:{r0:String,r1:Bool};
var _t18:Bool;
this.setPH(881);
_t16=Interface.assertOk(0,p_i); // _t16 = typeassert,ok i.(string) *ssa.TypeAssert @ /usr/local/go/src/pkg/runtime/error.go:113:2
_t17=_t16.r0; // _t17 = extract t16 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/error.go:113:2
_t18=_t16.r1; // _t18 = extract t16 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/error.go:113:2
_Next=_t18 ? 10 : 11; // if t18 goto 10.typeswitch.body else 11.typeswitch.next *ssa.If near /usr/local/go/src/pkg/runtime/error.go:113:2
}// end SubFn8
private inline  function SubFn9():Void {
this.setPH(882);
trace(Go.CPos(882),_t17); // _t19 = print(t17) *ssa.Call @ /usr/local/go/src/pkg/runtime/error.go:114:8 [REGISTER VALUE UN-USED]
_Next=1; // jump 1.typeswitch.done *ssa.Jump near /usr/local/go/src/pkg/runtime/error.go:114:8
}// end SubFn9
private inline  function SubFn10():Void {
this.setPH(884);
trace(Go.CPos(884),"(",_t20,") ",p_i); // _t21 = print("(":string, t20, ") ":string, i) *ssa.Call @ /usr/local/go/src/pkg/runtime/error.go:116:8 [REGISTER VALUE UN-USED]
_Next=1; // jump 1.typeswitch.done *ssa.Jump near /usr/local/go/src/pkg/runtime/error.go:116:8
}// end SubFn10
}
#if (!php) private #end class Go_runtime_funpack32 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:61:6
var p_f:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : Int) {
super(gr,1420,"Go_runtime_funpack32");
this._bds=_bds;
this.p_f=p_f;
Scheduler.push(gr,this);
}
var _res:{r0:Int, r1:Int, r2:Int, r3:Bool, r4:Bool};
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Int=0;
var _t2:Int=0;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:Int=0;
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
var _t17:Int=0;
var _t18:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : Int) : {r0:Int, r1:Int, r2:Int, r3:Bool, r4:Bool} {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_funpack32(0,[], p_f).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : Int) : {r0:Int, r1:Int, r2:Int, r3:Bool, r4:Bool} {
var _sf=new Go_runtime_funpack32(_gr,[], p_f).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : Int) : Go_runtime_funpack32
{return new Go_runtime_funpack32(gr,_bds, p_f);
}
public function run():Go_runtime_funpack32 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1420,0);
this.SubFn0();
_Phi=0;
case 1: // switch.done
this.setLatest(1420,1);
_t6=((_Phi==3)?_t1:(_Phi==7)?_t11:(_Phi==10)?_t16:0); // _t6 = phi [3.switch.body: t1, 7.switch.next: t11, 10.for.loop: t16] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:61:33
_t7=((_Phi==3)?_t4:(_Phi==7)?_t12:(_Phi==10)?_t17:0); // _t7 = phi [3.switch.body: t4, 7.switch.next: t12, 10.for.loop: t17] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:61:46
this.setPH(1449);
_res= {r0:_t0,r1:_t6,r2:_t7,r3:false,r4:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0, t6, t7, false:bool, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:90:2

case 2: // switch.body
this.setLatest(1449,2);
this.SubFn1();
_Phi=2;
case 3: // switch.body
this.setLatest(1449,3);
this.SubFn2();
_Phi=3;
case 4: // switch.next
this.setLatest(1449,4);
this.SubFn3();
_Phi=4;
case 5: // if.then
this.setLatest(1449,5);
this.setPH(1429);
_res= {r0:_t0,r1:_t1,r2:_t4,r3:false,r4:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0, t1, t4, false:bool, true:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:70:4

case 6: // if.done
this.setLatest(1429,6);
this.setPH(1432);
_res= {r0:_t0,r1:_t1,r2:_t4,r3:true,r4:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0, t1, t4, true:bool, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:73:3

case 7: // switch.next
this.setLatest(1432,7);
this.SubFn4();
_Phi=7;
case 8: // if.then
this.setLatest(1432,8);
this.SubFn5();
_Phi=8;
case 9: // for.body
this.setLatest(1432,9);
this.SubFn6();
_Phi=9;
case 10: // for.loop
this.setLatest(1432,10);
this.setPH(1420);
_t16=((_Phi==8)?_t1:(_Phi==9)?_t14:0); // _t16 = phi [8.if.then: t1, 9.for.body: t14] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:61:33
_t17=((_Phi==8)?_t13:(_Phi==9)?_t15:0); // _t17 = phi [8.if.then: t13, 9.for.body: t15] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:61:46
this.SubFn7();
_Phi=10;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t2:Int;
var _t3:Int;
var _t5:Bool;
this.setPH(1421);
_t0=Force.toUint32((p_f&(-2147483648))); // _t0 = f & 2147483648:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:62:11
this.setPH(1422);
_t1=Force.toUint32((p_f&8388607)); // _t1 = f & 8388607:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:63:11
this.setPH(1423);
_t2=(p_f>>23); // _t2 = f >> 23:uint *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:64:13
_t3=_t2; // _t3 = convert int <- uint32 (t2) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:64:11
_t4=(_t3&255); // _t4 = t3 & 255:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:64:27
_t5=(_t4==255); // _t5 = t4 == 255:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:64:27
_Next=_t5 ? 2 : 4; // if t5 goto 2.switch.body else 4.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:64:27
}// end SubFn0
private inline  function SubFn1():Void {
var _t8:Bool;
this.setPH(1427);
_t8=(Force.uintCompare(_t1,0)!=0); // _t8 = t1 != 0:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:68:11
_Next=_t8 ? 5 : 6; // if t8 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:68:11
}// end SubFn1
private inline  function SubFn2():Void {
var _t9:Bool;
this.setPH(1436);
_t9=(Force.uintCompare(_t1,0)!=0); // _t9 = t1 != 0:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
_Next=_t9 ? 8 : 1; // if t9 goto 8.if.then else 1.switch.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
}// end SubFn2
private inline  function SubFn3():Void {
var _t10:Bool;
_t10=(_t4==0); // _t10 = t4 == 0:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
_Next=_t10 ? 3 : 7; // if t10 goto 3.switch.body else 7.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
}// end SubFn3
private inline  function SubFn4():Void {
_t11=Force.toUint32((_t1|8388608)); // _t11 = t1 | 8388608:uint32 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
_t12=(_t4+(-127)); // _t12 = t4 + -127:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
_Next=1; // jump 1.switch.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
}// end SubFn4
private inline  function SubFn5():Void {
_t13=(_t4+(-126)); // _t13 = t4 + -126:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
_Next=10; // jump 10.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
}// end SubFn5
private inline  function SubFn6():Void {
_t14=(_t16<<1); // _t14 = t16 << 1:uint32 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
_t15=(_t17-1); // _t15 = t17 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
_Next=10; // jump 10.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:77:11
}// end SubFn6
private inline  function SubFn7():Void {
var _t18:Bool;
this.setPH(1438);
_t18=(Force.uintCompare(_t16,8388608)<0); // _t18 = t16 < 8388608:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:79:13
_Next=_t18 ? 9 : 1; // if t18 goto 9.for.body else 1.switch.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:79:13
}// end SubFn7
}
#if js @:expose("Go_runtime_NumGoroutine") #end class Go_runtime_NumGoroutine extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:13:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,430,"Go_runtime_NumGoroutine");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_NumGoroutine(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : Int {
var _sf=new Go_runtime_NumGoroutine(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_runtime_NumGoroutine
{return new Go_runtime_NumGoroutine(gr,_bds);
}
public function run():Go_runtime_NumGoroutine {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(430,0);
_SF1=Go_tardisgolib_NumGoroutine.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(430,-1);
_t0=_SF1.res();
 // _t0 = github.com/tardisgo/tardisgo/tardisgolib.NumGoroutine() *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:13:58
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:13:27

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_utf16_DecodeRune") #end class Go_utf16_DecodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:37:6
var p_r1:Int;
var p_r2:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r1 : Int, p_r2 : Int) {
super(gr,3001,"Go_utf16_DecodeRune");
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
this.setLatest(3001,0);
this.SubFn0();

case 1: // if.then
this.setLatest(3001,1);
this.SubFn1();
this.setPH(3003);
_res= _t5;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:3

case 2: // if.done
this.setLatest(3003,2);
this.setPH(3005);
_res= 65533;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:41:2

case 3: // cond.true
this.setLatest(3005,3);
this.SubFn2();

case 4: // cond.true
this.setLatest(3005,4);
this.SubFn3();

case 5: // cond.true
this.setLatest(3005,5);
this.SubFn4();

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(3002);
_t0=(55296<=p_r1); // _t0 = 55296:rune <= r1 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:11
_Next=_t0 ? 5 : 2; // if t0 goto 5.cond.true else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:38:11
}// end SubFn0
private inline  function SubFn1():Void {
var _t1:Int;
var _t2:Int;
var _t3:Int;
var _t4:Int;
this.setPH(3003);
_t1=Force.toInt32((p_r1-55296)); // _t1 = r1 - 55296:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:19
_t2=(_t1<<GOint64.toInt(GOint64.make(0x0,0xa))); // _t2 = t1 << 10:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:26
_t3=Force.toInt32((p_r2-56320)); // _t3 = r2 - 56320:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:43
_t4=Force.toInt32((_t2|_t3)); // _t4 = t2 | t3 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:31
_t5=Force.toInt32((_t4+65536)); // _t5 = t4 + 65536:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:39:52
}// end SubFn1
private inline  function SubFn2():Void {
var _t6:Bool;
this.setPH(3002);
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
#if (!php) private #end class Go_runtime_f64tointc extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:498:6
var p_f:GOint64;
var p_ret:Pointer;
var p_retok:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_ret : Pointer, p_retok : Pointer) {
super(gr,1857,"Go_runtime_f64tointc");
this._bds=_bds;
this.p_f=p_f;
this.p_ret=p_ret;
this.p_retok=p_retok;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t0:{r0:GOint64,r1:Bool}=null;
var _t1:GOint64=null;
var _t2:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_ret : Pointer, p_retok : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_f64tointc(0,[], p_f, p_ret, p_retok).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_ret : Pointer, p_retok : Pointer) : Void {
var _sf=new Go_runtime_f64tointc(_gr,[], p_f, p_ret, p_retok).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_ret : Pointer, p_retok : Pointer) : Go_runtime_f64tointc
{return new Go_runtime_f64tointc(gr,_bds, p_f, p_ret, p_retok);
}
public function run():Go_runtime_f64tointc {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1857,0);
_SF1=Go_runtime_f64toint.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(1857,-1);
_t0=_SF1.res();
 // _t0 = f64toint(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:498:76
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:498:76

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:GOint64;
var _t2:Bool;
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:498:76
p_ret.store(_t1); // *ret = t1 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:498:53
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:498:53
p_retok.store(_t2); // *retok = t2 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:498:59
}// end SubFn0
}
#if js @:expose("Go_utf16_EncodeRune") #end class Go_utf16_EncodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf16/utf16.go:47:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,3011,"Go_utf16_EncodeRune");
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
this.setLatest(3011,0);
this.SubFn0();

case 1: // if.then
this.setLatest(3011,1);
this.setPH(3013);
_res= {r0:65533,r1:65533};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 65533:rune *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:49:3

case 2: // if.done
this.setLatest(3013,2);
this.SubFn1();
this.setPH(3016);
_res= {r0:_t4,r1:_t6};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4, t6 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:52:2

case 3: // cond.false
this.setLatest(3016,3);
this.setPH(3012);
_SF1=Go_utf16_IsSurrogate.call(this._goroutine,[],p_r);
_Next = -1;
return this;
case -1:
this.setLatest(3012,-1);
_t7=_SF1.res();
 // _t7 = IsSurrogate(r) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:47
this.SubFn2();

case 4: // cond.false
this.setLatest(3012,4);
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
this.setPH(3016);
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
this.setPH(3012);
_t8=(p_r>1114111); // _t8 = r > 1114111:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:23
_Next=_t8 ? 1 : 3; // if t8 goto 1.if.then else 3.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:23
}// end SubFn3
}
#if (!php) private #end class Go_runtime_gc_itab_ptr extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/mgc0.go:13:6
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_ret : Pointer) {
super(gr,1352,"Go_runtime_gc_itab_ptr");
this._bds=_bds;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_gc_itab_ptr(0,[], p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_ret : Pointer) : Void {
var _sf=new Go_runtime_gc_itab_ptr(_gr,[], p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_ret : Pointer) : Go_runtime_gc_itab_ptr
{return new Go_runtime_gc_itab_ptr(gr,_bds, p_ret);
}
public function run():Go_runtime_gc_itab_ptr {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1352,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:23

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Interface;
_t0=new Interface(4,null); // _t0 = make interface{} <- *itab (nil:*itab) *ssa.MakeInterface near /usr/local/go/src/pkg/unicode/utf16/utf16.go:48:23
this.setPH(1353);
p_ret.store(_t0); // *ret = t0 *ssa.Store @ /usr/local/go/src/pkg/runtime/mgc0.go:14:2
}// end SubFn0
}
#if (!php) private #end class Go_runtime_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1104,"Go_runtime_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _SF1:StackFrame;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_runtime_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_runtime_init
{return new Go_runtime_init(gr,_bds);
}
public function run():Go_runtime_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1104,0);
this.SubFn0();

case 1: // init.start
this.setLatest(1104,1);
this.SubFn1();
Go_runtime_init_36_1.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(1104,-1);
 // _t1 = init$1() *ssa.Call near /usr/local/go/src/pkg/runtime/mgc0.go:14:2 [REGISTER VALUE UN-USED]
this.SubFn2();

case 2: // init.done
this.setLatest(1104,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/mgc0.go:14:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.runtime_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /usr/local/go/src/pkg/runtime/mgc0.go:14:2
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /usr/local/go/src/pkg/runtime/mgc0.go:14:2
}// end SubFn0
private inline  function SubFn1():Void {
Go.runtime_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /usr/local/go/src/pkg/runtime/mgc0.go:14:2
Go.runtime_MemProfileRate.store(524288); // *MemProfileRate = 524288:int *ssa.Store near /usr/local/go/src/pkg/runtime/mgc0.go:14:2
}// end SubFn1
private inline  function SubFn2():Void {
_Next=2; // jump 2.init.done *ssa.Jump near /usr/local/go/src/pkg/runtime/mgc0.go:14:2
}// end SubFn2
}
#if (!php) private #end class Go_utf8_decodeRuneInternal extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:45:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,3117,"Go_utf8_decodeRuneInternal");
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
this.setLatest(3117,0);
this.SubFn0();

case 1: // if.then
this.setLatest(3117,1);
this.setPH(3120);
_res= {r0:65533,r1:0,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:48:3

case 2: // if.done
this.setLatest(3120,2);
this.SubFn1();

case 3: // if.then
this.setLatest(3120,3);
this.SubFn2();
this.setPH(3126);
_res= {r0:_t5,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t5, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:54:3

case 4: // if.done
this.setLatest(3126,4);
this.SubFn3();

case 5: // if.then
this.setLatest(3126,5);
this.setPH(3131);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:59:3

case 6: // if.done
this.setLatest(3131,6);
this.SubFn4();

case 7: // if.then
this.setLatest(3131,7);
this.setPH(3136);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:64:3

case 8: // if.done
this.setLatest(3136,8);
this.SubFn5();

case 9: // if.then
this.setLatest(3136,9);
this.setPH(3140);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:68:3

case 10: // if.done
this.setLatest(3140,10);
this.SubFn6();

case 11: // cond.false
this.setLatest(3140,11);
this.SubFn7();

case 12: // if.then
this.setLatest(3140,12);
this.SubFn8();

case 13: // if.done
this.setLatest(3140,13);
this.SubFn9();

case 14: // if.then
this.setLatest(3140,14);
this.setPH(3147);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:75:4

case 15: // if.done
this.setLatest(3147,15);
this.setPH(3149);
_res= {r0:_t18,r1:2,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t18, 2:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:77:3

case 16: // if.then
this.setLatest(3149,16);
this.setPH(3154);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:82:3

case 17: // if.done
this.setLatest(3154,17);
this.SubFn10();

case 18: // if.then
this.setLatest(3154,18);
this.setPH(3158);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:86:3

case 19: // if.done
this.setLatest(3158,19);
this.SubFn11();

case 20: // cond.false
this.setLatest(3158,20);
this.SubFn12();

case 21: // if.then
this.setLatest(3158,21);
this.SubFn13();

case 22: // if.done
this.setLatest(3158,22);
this.SubFn14();

case 23: // if.then
this.setLatest(3158,23);
this.setPH(3165);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:93:4

case 24: // if.done
this.setLatest(3165,24);
this.SubFn15();

case 25: // if.then
this.setLatest(3165,25);
this.setPH(3168);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:96:4

case 26: // if.done
this.setLatest(3168,26);
this.setPH(3170);
_res= {r0:_t35,r1:3,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t35, 3:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:98:3

case 27: // cond.true
this.setLatest(3170,27);
this.SubFn16();

case 28: // if.then
this.setLatest(3170,28);
this.setPH(3175);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:103:3

case 29: // if.done
this.setLatest(3175,29);
this.SubFn17();

case 30: // if.then
this.setLatest(3175,30);
this.setPH(3179);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:107:3

case 31: // if.done
this.setLatest(3179,31);
this.SubFn18();

case 32: // cond.false
this.setLatest(3179,32);
this.SubFn19();

case 33: // if.then
this.setLatest(3179,33);
this.SubFn20();

case 34: // if.done
this.setLatest(3179,34);
this.setPH(3192);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:120:2

case 35: // if.then
this.setLatest(3192,35);
this.setPH(3186);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:114:4

case 36: // if.done
this.setLatest(3186,36);
this.setPH(3188);
_res= {r0:_t58,r1:4,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t58, 4:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:116:3

case 37: // cond.false
this.setLatest(3188,37);
this.SubFn21();

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Bool;
this.setPH(3118);
_t0=({var _v=p_p;_v==null?0:_v.len();}); // _t0 = len(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:46:10
this.setPH(3119);
_t1=(_t0<1); // _t1 = t0 < 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:47:7
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:47:7
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Pointer;
var _t4:Bool;
this.setPH(3122);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:50:9 [POINTER]
_t2=p_p.addr(0);  // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:50:9 [POINTER]
_t3=(_t2.load()|0); // _t3 = *t2 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:50:9
this.setPH(3125);
_t4=(Force.uintCompare(_t3,128)<0); // _t4 = t3 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:53:8
_Next=_t4 ? 3 : 4; // if t4 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:53:8
}// end SubFn1
private inline  function SubFn2():Void {
this.setPH(3126);
_t5=_t3; // _t5 = convert rune <- byte (t3) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:54:14
}// end SubFn2
private inline  function SubFn3():Void {
var _t6:Bool;
this.setPH(3130);
_t6=(Force.uintCompare(_t3,192)<0); // _t6 = t3 < 192:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:58:8
_Next=_t6 ? 5 : 6; // if t6 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:58:8
}// end SubFn3
private inline  function SubFn4():Void {
var _t7:Bool;
this.setPH(3135);
_t7=(_t0<2); // _t7 = t0 < 2:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:63:7
_Next=_t7 ? 7 : 8; // if t7 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:63:7
}// end SubFn4
private inline  function SubFn5():Void {
var _t8:Pointer;
var _t10:Bool;
this.setPH(3138);
if((1<0)||(1>=p_p.len())) Scheduler.ioor(); // _t8 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:66:9 [POINTER]
_t8=p_p.addr(1);  // _t8 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:66:9 [POINTER]
_t9=(_t8.load()|0); // _t9 = *t8 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:66:9
this.setPH(3139);
_t10=(Force.uintCompare(_t9,128)<0); // _t10 = t9 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:67:8
_Next=_t10 ? 9 : 11; // if t10 goto 9.if.then else 11.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:67:8
}// end SubFn5
private inline  function SubFn6():Void {
var _t11:Bool;
this.setPH(3144);
_t11=(Force.uintCompare(_t3,224)<0); // _t11 = t3 < 224:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:72:8
_Next=_t11 ? 12 : 13; // if t11 goto 12.if.then else 13.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:72:8
}// end SubFn6
private inline  function SubFn7():Void {
var _t12:Bool;
this.setPH(3139);
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
this.setPH(3145);
_t13=Force.toUint8((_t3&31)); // _t13 = t3 & 31:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:14
_t14=_t13; // _t14 = convert rune <- byte (t13) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:11
_t15=(_t14<<GOint64.toInt(GOint64.make(0x0,0x6))); // _t15 = t14 << 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:21
_t16=Force.toUint8((_t9&63)); // _t16 = t9 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:34
_t17=_t16; // _t17 = convert rune <- byte (t16) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:31
_t18=Force.toInt32((_t15|_t17)); // _t18 = t15 | t17 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:73:25
this.setPH(3146);
_t19=(_t18<=127); // _t19 = t18 <= 127:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:74:8
_Next=_t19 ? 14 : 15; // if t19 goto 14.if.then else 15.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:74:8
}// end SubFn8
private inline  function SubFn9():Void {
var _t20:Bool;
this.setPH(3153);
_t20=(_t0<3); // _t20 = t0 < 3:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:81:7
_Next=_t20 ? 16 : 17; // if t20 goto 16.if.then else 17.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:81:7
}// end SubFn9
private inline  function SubFn10():Void {
var _t21:Pointer;
var _t23:Bool;
this.setPH(3156);
if((2<0)||(2>=p_p.len())) Scheduler.ioor(); // _t21 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:84:9 [POINTER]
_t21=p_p.addr(2);  // _t21 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:84:9 [POINTER]
_t22=(_t21.load()|0); // _t22 = *t21 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:84:9
this.setPH(3157);
_t23=(Force.uintCompare(_t22,128)<0); // _t23 = t22 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:85:8
_Next=_t23 ? 18 : 20; // if t23 goto 18.if.then else 20.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:85:8
}// end SubFn10
private inline  function SubFn11():Void {
var _t24:Bool;
this.setPH(3162);
_t24=(Force.uintCompare(_t3,240)<0); // _t24 = t3 < 240:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:90:8
_Next=_t24 ? 21 : 22; // if t24 goto 21.if.then else 22.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:90:8
}// end SubFn11
private inline  function SubFn12():Void {
var _t25:Bool;
this.setPH(3157);
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
this.setPH(3163);
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
this.setPH(3164);
_t36=(_t35<=2047); // _t36 = t35 <= 2047:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:92:8
_Next=_t36 ? 23 : 24; // if t36 goto 23.if.then else 24.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:92:8
}// end SubFn13
private inline  function SubFn14():Void {
var _t37:Bool;
this.setPH(3174);
_t37=(_t0<4); // _t37 = t0 < 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:102:7
_Next=_t37 ? 28 : 29; // if t37 goto 28.if.then else 29.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:102:7
}// end SubFn14
private inline  function SubFn15():Void {
var _t38:Bool;
this.setPH(3167);
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
this.setPH(3177);
if((3<0)||(3>=p_p.len())) Scheduler.ioor(); // _t40 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:105:9 [POINTER]
_t40=p_p.addr(3);  // _t40 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:105:9 [POINTER]
_t41=(_t40.load()|0); // _t41 = *t40 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:105:9
this.setPH(3178);
_t42=(Force.uintCompare(_t41,128)<0); // _t42 = t41 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:106:8
_Next=_t42 ? 30 : 32; // if t42 goto 30.if.then else 32.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:106:8
}// end SubFn17
private inline  function SubFn18():Void {
var _t43:Bool;
this.setPH(3183);
_t43=(Force.uintCompare(_t3,248)<0); // _t43 = t3 < 248:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:111:8
_Next=_t43 ? 33 : 34; // if t43 goto 33.if.then else 34.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:111:8
}// end SubFn18
private inline  function SubFn19():Void {
var _t44:Bool;
this.setPH(3178);
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
this.setPH(3184);
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
this.setPH(3185);
_t59=(_t58<=65535); // _t59 = t58 <= 65535:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:8
_Next=_t59 ? 35 : 37; // if t59 goto 35.if.then else 37.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:8
}// end SubFn20
private inline  function SubFn21():Void {
var _t60:Bool;
_t60=(1114111<_t58); // _t60 = 1114111:rune < t58 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:31
_Next=_t60 ? 35 : 36; // if t60 goto 35.if.then else 36.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:113:31
}// end SubFn21
}
#if (!php) private #end class Go_runtime_fcmp64c extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:496:6
var p_f:GOint64;
var p_g:GOint64;
var p_ret:Pointer;
var p_retnan:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64, p_ret : Pointer, p_retnan : Pointer) {
super(gr,1855,"Go_runtime_fcmp64c");
this._bds=_bds;
this.p_f=p_f;
this.p_g=p_g;
this.p_ret=p_ret;
this.p_retnan=p_retnan;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t0:{r0:Int,r1:Bool}=null;
var _t1:Int=0;
var _t2:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_g : GOint64, p_ret : Pointer, p_retnan : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fcmp64c(0,[], p_f, p_g, p_ret, p_retnan).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_g : GOint64, p_ret : Pointer, p_retnan : Pointer) : Void {
var _sf=new Go_runtime_fcmp64c(_gr,[], p_f, p_g, p_ret, p_retnan).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64, p_ret : Pointer, p_retnan : Pointer) : Go_runtime_fcmp64c
{return new Go_runtime_fcmp64c(gr,_bds, p_f, p_g, p_ret, p_retnan);
}
public function run():Go_runtime_fcmp64c {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1855,0);
_SF1=Go_runtime_fcmp64.call(this._goroutine,[],p_f,p_g);
_Next = -1;
return this;
case -1:
this.setLatest(1855,-1);
_t0=_SF1.res();
 // _t0 = fcmp64(f, g) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:496:75
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:496:75

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Int;
var _t2:Bool;
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:496:75
p_ret.store(_t1); // *ret = t1 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:496:53
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:496:53
p_retnan.store(_t2); // *retnan = t2 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:496:59
}// end SubFn0
}
#if (!php) private #end class Go_utf8_decodeRuneInStringInternal extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:123:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,3195,"Go_utf8_decodeRuneInStringInternal");
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
this.setLatest(3195,0);
this.SubFn0();

case 1: // if.then
this.setLatest(3195,1);
this.setPH(3198);
_res= {r0:65533,r1:0,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:126:3

case 2: // if.done
this.setLatest(3198,2);
this.SubFn1();

case 3: // if.then
this.setLatest(3198,3);
this.SubFn2();
this.setPH(3204);
_res= {r0:_t4,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:132:3

case 4: // if.done
this.setLatest(3204,4);
this.SubFn3();

case 5: // if.then
this.setLatest(3204,5);
this.setPH(3209);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:137:3

case 6: // if.done
this.setLatest(3209,6);
this.SubFn4();

case 7: // if.then
this.setLatest(3209,7);
this.setPH(3214);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:142:3

case 8: // if.done
this.setLatest(3214,8);
this.SubFn5();

case 9: // if.then
this.setLatest(3214,9);
this.setPH(3218);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:146:3

case 10: // if.done
this.setLatest(3218,10);
this.SubFn6();

case 11: // cond.false
this.setLatest(3218,11);
this.SubFn7();

case 12: // if.then
this.setLatest(3218,12);
this.SubFn8();

case 13: // if.done
this.setLatest(3218,13);
this.SubFn9();

case 14: // if.then
this.setLatest(3218,14);
this.setPH(3225);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:153:4

case 15: // if.done
this.setLatest(3225,15);
this.setPH(3227);
_res= {r0:_t16,r1:2,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t16, 2:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:155:3

case 16: // if.then
this.setLatest(3227,16);
this.setPH(3232);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:160:3

case 17: // if.done
this.setLatest(3232,17);
this.SubFn10();

case 18: // if.then
this.setLatest(3232,18);
this.setPH(3236);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:164:3

case 19: // if.done
this.setLatest(3236,19);
this.SubFn11();

case 20: // cond.false
this.setLatest(3236,20);
this.SubFn12();

case 21: // if.then
this.setLatest(3236,21);
this.SubFn13();

case 22: // if.done
this.setLatest(3236,22);
this.SubFn14();

case 23: // if.then
this.setLatest(3236,23);
this.setPH(3243);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:171:4

case 24: // if.done
this.setLatest(3243,24);
this.SubFn15();

case 25: // if.then
this.setLatest(3243,25);
this.setPH(3246);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:174:4

case 26: // if.done
this.setLatest(3246,26);
this.setPH(3248);
_res= {r0:_t32,r1:3,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t32, 3:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:176:3

case 27: // cond.true
this.setLatest(3248,27);
this.SubFn16();

case 28: // if.then
this.setLatest(3248,28);
this.setPH(3253);
_res= {r0:65533,r1:1,r2:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:181:3

case 29: // if.done
this.setLatest(3253,29);
this.SubFn17();

case 30: // if.then
this.setLatest(3253,30);
this.setPH(3257);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:185:3

case 31: // if.done
this.setLatest(3257,31);
this.SubFn18();

case 32: // cond.false
this.setLatest(3257,32);
this.SubFn19();

case 33: // if.then
this.setLatest(3257,33);
this.SubFn20();

case 34: // if.done
this.setLatest(3257,34);
this.setPH(3270);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:198:2

case 35: // if.then
this.setLatest(3270,35);
this.setPH(3264);
_res= {r0:65533,r1:1,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:192:4

case 36: // if.done
this.setLatest(3264,36);
this.setPH(3266);
_res= {r0:_t54,r1:4,r2:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t54, 4:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:194:3

case 37: // cond.false
this.setLatest(3266,37);
this.SubFn21();

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Bool;
this.setPH(3196);
_t0=Force.toUTF8length(this._goroutine,p_s); // _t0 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:124:10
this.setPH(3197);
_t1=(_t0<1); // _t1 = t0 < 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:125:7
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:125:7
}// end SubFn0
private inline  function SubFn1():Void {
var _t3:Bool;
this.setPH(3200);
_t2=Force.toUTF8slice(this._goroutine,p_s).getAt(0); // _t2 = s[0:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:128:9
this.setPH(3203);
_t3=(Force.uintCompare(_t2,128)<0); // _t3 = t2 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:131:8
_Next=_t3 ? 3 : 4; // if t3 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:131:8
}// end SubFn1
private inline  function SubFn2():Void {
this.setPH(3204);
_t4=_t2; // _t4 = convert rune <- uint8 (t2) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:132:14
}// end SubFn2
private inline  function SubFn3():Void {
var _t5:Bool;
this.setPH(3208);
_t5=(Force.uintCompare(_t2,192)<0); // _t5 = t2 < 192:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:136:8
_Next=_t5 ? 5 : 6; // if t5 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:136:8
}// end SubFn3
private inline  function SubFn4():Void {
var _t6:Bool;
this.setPH(3213);
_t6=(_t0<2); // _t6 = t0 < 2:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:141:7
_Next=_t6 ? 7 : 8; // if t6 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:141:7
}// end SubFn4
private inline  function SubFn5():Void {
var _t8:Bool;
this.setPH(3216);
_t7=Force.toUTF8slice(this._goroutine,p_s).getAt(1); // _t7 = s[1:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:144:9
this.setPH(3217);
_t8=(Force.uintCompare(_t7,128)<0); // _t8 = t7 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:145:8
_Next=_t8 ? 9 : 11; // if t8 goto 9.if.then else 11.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:145:8
}// end SubFn5
private inline  function SubFn6():Void {
var _t9:Bool;
this.setPH(3222);
_t9=(Force.uintCompare(_t2,224)<0); // _t9 = t2 < 224:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:150:8
_Next=_t9 ? 12 : 13; // if t9 goto 12.if.then else 13.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:150:8
}// end SubFn6
private inline  function SubFn7():Void {
var _t10:Bool;
this.setPH(3217);
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
this.setPH(3223);
_t11=Force.toUint8((_t2&31)); // _t11 = t2 & 31:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:14
_t12=_t11; // _t12 = convert rune <- uint8 (t11) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:11
_t13=(_t12<<GOint64.toInt(GOint64.make(0x0,0x6))); // _t13 = t12 << 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:21
_t14=Force.toUint8((_t7&63)); // _t14 = t7 & 63:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:34
_t15=_t14; // _t15 = convert rune <- uint8 (t14) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:31
_t16=Force.toInt32((_t13|_t15)); // _t16 = t13 | t15 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:151:25
this.setPH(3224);
_t17=(_t16<=127); // _t17 = t16 <= 127:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:152:8
_Next=_t17 ? 14 : 15; // if t17 goto 14.if.then else 15.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:152:8
}// end SubFn8
private inline  function SubFn9():Void {
var _t18:Bool;
this.setPH(3231);
_t18=(_t0<3); // _t18 = t0 < 3:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:159:7
_Next=_t18 ? 16 : 17; // if t18 goto 16.if.then else 17.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:159:7
}// end SubFn9
private inline  function SubFn10():Void {
var _t20:Bool;
this.setPH(3234);
_t19=Force.toUTF8slice(this._goroutine,p_s).getAt(2); // _t19 = s[2:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:162:9
this.setPH(3235);
_t20=(Force.uintCompare(_t19,128)<0); // _t20 = t19 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:163:8
_Next=_t20 ? 18 : 20; // if t20 goto 18.if.then else 20.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:163:8
}// end SubFn10
private inline  function SubFn11():Void {
var _t21:Bool;
this.setPH(3240);
_t21=(Force.uintCompare(_t2,240)<0); // _t21 = t2 < 240:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:168:8
_Next=_t21 ? 21 : 22; // if t21 goto 21.if.then else 22.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:168:8
}// end SubFn11
private inline  function SubFn12():Void {
var _t22:Bool;
this.setPH(3235);
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
this.setPH(3241);
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
this.setPH(3242);
_t33=(_t32<=2047); // _t33 = t32 <= 2047:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:170:8
_Next=_t33 ? 23 : 24; // if t33 goto 23.if.then else 24.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:170:8
}// end SubFn13
private inline  function SubFn14():Void {
var _t34:Bool;
this.setPH(3252);
_t34=(_t0<4); // _t34 = t0 < 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:180:7
_Next=_t34 ? 28 : 29; // if t34 goto 28.if.then else 29.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:180:7
}// end SubFn14
private inline  function SubFn15():Void {
var _t35:Bool;
this.setPH(3245);
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
this.setPH(3255);
_t37=Force.toUTF8slice(this._goroutine,p_s).getAt(3); // _t37 = s[3:int] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:183:9
this.setPH(3256);
_t38=(Force.uintCompare(_t37,128)<0); // _t38 = t37 < 128:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:184:8
_Next=_t38 ? 30 : 32; // if t38 goto 30.if.then else 32.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:184:8
}// end SubFn17
private inline  function SubFn18():Void {
var _t39:Bool;
this.setPH(3261);
_t39=(Force.uintCompare(_t2,248)<0); // _t39 = t2 < 248:uint8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:189:8
_Next=_t39 ? 33 : 34; // if t39 goto 33.if.then else 34.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:189:8
}// end SubFn18
private inline  function SubFn19():Void {
var _t40:Bool;
this.setPH(3256);
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
this.setPH(3262);
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
this.setPH(3263);
_t55=(_t54<=65535); // _t55 = t54 <= 65535:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:8
_Next=_t55 ? 35 : 37; // if t55 goto 35.if.then else 37.cond.false *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:8
}// end SubFn20
private inline  function SubFn21():Void {
var _t56:Bool;
_t56=(1114111<_t54); // _t56 = 1114111:rune < t54 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:31
_Next=_t56 ? 35 : 36; // if t56 goto 35.if.then else 36.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:191:31
}// end SubFn21
}
#if js @:expose("Go_haxegoruntime_StringCompare") #end class Go_haxegoruntime_StringCompare extends StackFrameBasis implements StackFrame {  // langgoruntime.go:120:6
var p_a:String;
var p_b:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_a : String, p_b : String) {
super(gr,2943,"Go_haxegoruntime_StringCompare");
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
this.setLatest(2943,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(2943,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(2943,2);
this.SubFn2();
_Phi=2;
case 3: // for.loop
this.setLatest(2943,3);
this.setPH(2947);
_t10=((_Phi==0)?0:(_Phi==8)?_t20:0); // _t10 = phi [0.entry: 0:int, 8.if.done: t20] #i *ssa.Phi @ langgoruntime.go:124:2
this.SubFn3();
_Phi=3;
case 4: // cond.true
this.setLatest(2947,4);
this.SubFn4();
_Phi=4;
case 5: // if.then
this.setLatest(2947,5);
this.setPH(2950);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ langgoruntime.go:127:4

case 6: // if.done
this.setLatest(2950,6);
this.SubFn5();
_Phi=6;
case 7: // if.then
this.setLatest(2950,7);
this.setPH(2953);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ langgoruntime.go:130:4

case 8: // if.done
this.setLatest(2953,8);
this.SubFn6();
_Phi=8;
case 9: // if.then
this.setLatest(2953,9);
this.setPH(2958);
_res= 0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int *ssa.Return @ langgoruntime.go:135:3

case 10: // if.done
this.setLatest(2958,10);
this.SubFn7();
_Phi=10;
case 11: // if.then
this.setLatest(2958,11);
this.setPH(2961);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ langgoruntime.go:138:3

case 12: // if.done
this.setLatest(2961,12);
this.setPH(2963);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ langgoruntime.go:140:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(2945);
_t0=Force.toUTF8slice(this._goroutine,p_a); // _t0 = convert []byte <- string (a) *ssa.Convert @ langgoruntime.go:122:13
this.setPH(2946);
_t1=Force.toUTF8slice(this._goroutine,p_b); // _t1 = convert []byte <- string (b) *ssa.Convert @ langgoruntime.go:123:13
_Next=3; // jump 3.for.loop *ssa.Jump near langgoruntime.go:123:13
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Pointer;
var _t3:Int;
var _t4:Pointer;
var _t5:Int;
var _t6:Bool;
this.setPH(2949);
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
this.setPH(2957);
_t7=({var _v=_t0;_v==null?0:_v.len();}); // _t7 = len(t0) *ssa.Call @ langgoruntime.go:134:8
_t8=({var _v=_t1;_v==null?0:_v.len();}); // _t8 = len(t1) *ssa.Call @ langgoruntime.go:134:18
_t9=(_t7==_t8); // _t9 = t7 == t8 *ssa.BinOp @ langgoruntime.go:134:12
_Next=_t9 ? 9 : 10; // if t9 goto 9.if.then else 10.if.done *ssa.If near langgoruntime.go:134:12
}// end SubFn2
private inline  function SubFn3():Void {
var _t11:Int;
var _t12:Bool;
this.setPH(2948);
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
this.setPH(2952);
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
this.setPH(2960);
_t21=({var _v=_t0;_v==null?0:_v.len();}); // _t21 = len(t0) *ssa.Call @ langgoruntime.go:137:8
_t22=({var _v=_t1;_v==null?0:_v.len();}); // _t22 = len(t1) *ssa.Call @ langgoruntime.go:137:17
_t23=(_t21<_t22); // _t23 = t21 < t22 *ssa.BinOp @ langgoruntime.go:137:12
_Next=_t23 ? 11 : 12; // if t23 goto 11.if.then else 12.if.done *ssa.If near langgoruntime.go:137:12
}// end SubFn7
}
#if (!php) private #end class Go_runtime_fdiv64c extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:492:6
var p_f:GOint64;
var p_g:GOint64;
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64, p_ret : Pointer) {
super(gr,1851,"Go_runtime_fdiv64c");
this._bds=_bds;
this.p_f=p_f;
this.p_g=p_g;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t0:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fdiv64c(0,[], p_f, p_g, p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Void {
var _sf=new Go_runtime_fdiv64c(_gr,[], p_f, p_g, p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Go_runtime_fdiv64c
{return new Go_runtime_fdiv64c(gr,_bds, p_f, p_g, p_ret);
}
public function run():Go_runtime_fdiv64c {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1851,0);
_SF1=Go_runtime_fdiv64.call(this._goroutine,[],p_f,p_g);
_Next = -1;
return this;
case -1:
this.setLatest(1851,-1);
_t0=_SF1.res();
 // _t0 = fdiv64(f, g) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:492:66
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:492:66

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_ret.store(_t0); // *ret = t0 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:492:53
}// end SubFn0
}
#if (!php) private #end class Go_runtime_gc_m_ptr extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/mgc0.go:8:6
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_ret : Pointer) {
super(gr,1347,"Go_runtime_gc_m_ptr");
this._bds=_bds;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_gc_m_ptr(0,[], p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_ret : Pointer) : Void {
var _sf=new Go_runtime_gc_m_ptr(_gr,[], p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_ret : Pointer) : Go_runtime_gc_m_ptr
{return new Go_runtime_gc_m_ptr(gr,_bds, p_ret);
}
public function run():Go_runtime_gc_m_ptr {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1347,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:492:53

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Interface;
_t0=new Interface(5,null); // _t0 = make interface{} <- *m (nil:*m) *ssa.MakeInterface near /usr/local/go/src/pkg/runtime/softfloat64.go:492:53
this.setPH(1348);
p_ret.store(_t0); // *ret = t0 *ssa.Store @ /usr/local/go/src/pkg/runtime/mgc0.go:9:2
}// end SubFn0
}
#if js @:expose("Go_runtime_FuncForPC") #end class Go_runtime_FuncForPC extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:19:6
var p_pc:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_pc : Dynamic) {
super(gr,436,"Go_runtime_FuncForPC");
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
var _sf=new Go_runtime_FuncForPC(0,[], p_pc).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_pc : Dynamic) : Pointer {
var _sf=new Go_runtime_FuncForPC(_gr,[], p_pc).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_pc : Dynamic) : Go_runtime_FuncForPC
{return new Go_runtime_FuncForPC(gr,_bds, p_pc);
}
public function run():Go_runtime_FuncForPC {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(436,0);
this.SubFn0();
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(436,-1);
 // panic t0 *ssa.Panic @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:19:49

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"runtime.FuncForPC() not yet implemented"); // _t0 = make interface{} <- string ("runtime.FuncForPC...":string) *ssa.MakeInterface near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:19:49
}// end SubFn0
}
#if (!php) private #end class Go_runtime_f64to32c extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:495:6
var p_f:GOint64;
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_ret : Pointer) {
super(gr,1854,"Go_runtime_f64to32c");
this._bds=_bds;
this.p_f=p_f;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t0:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_f64to32c(0,[], p_f, p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_ret : Pointer) : Void {
var _sf=new Go_runtime_f64to32c(_gr,[], p_f, p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_ret : Pointer) : Go_runtime_f64to32c
{return new Go_runtime_f64to32c(gr,_bds, p_f, p_ret);
}
public function run():Go_runtime_f64to32c {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1854,0);
_SF1=Go_runtime_f64to32.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(1854,-1);
_t0=_SF1.res();
 // _t0 = f64to32(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:495:67
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:495:67

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_ret.store(_t0); // *ret = t0 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:495:53
}// end SubFn0
}
#if js @:expose("Go_runtime_Version") #end class Go_runtime_Version extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/extern.go:179:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1070,"Go_runtime_Version");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_Version(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_runtime_Version(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_runtime_Version
{return new Go_runtime_Version(gr,_bds);
}
public function run():Go_runtime_Version {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1070,0);
this.setPH(1071);
_res= "go1.2";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "go1.2":string *ssa.Return @ /usr/local/go/src/pkg/runtime/extern.go:180:2

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_runtime_SetFinalizer") #end class Go_runtime_SetFinalizer extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:20:6
var p_x:Interface;
var p_f:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_x : Interface, p_f : Interface) {
super(gr,437,"Go_runtime_SetFinalizer");
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
var _sf=new Go_runtime_SetFinalizer(0,[], p_x, p_f).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_x : Interface, p_f : Interface) : Void {
var _sf=new Go_runtime_SetFinalizer(_gr,[], p_x, p_f).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_x : Interface, p_f : Interface) : Go_runtime_SetFinalizer
{return new Go_runtime_SetFinalizer(gr,_bds, p_x, p_f);
}
public function run():Go_runtime_SetFinalizer {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(437,0);
this.SubFn0();
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(437,-1);
 // panic t0 *ssa.Panic @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:20:49

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"runtime.SetFinalizer() not yet implemented"); // _t0 = make interface{} <- string ("runtime.SetFinali...":string) *ssa.MakeInterface near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:20:49
}// end SubFn0
}
#if (!php) private #end class Go_utf8_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,437,"Go_utf8_init");
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
this.setLatest(437,0);
this.SubFn0();

case 1: // init.start
this.setLatest(437,1);
this.SubFn1();

case 2: // init.done
this.setLatest(437,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:20:49

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.utf8_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:20:49
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:20:49
}// end SubFn0
private inline  function SubFn1():Void {
Go.utf8_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:20:49
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:20:49
}// end SubFn1
}
#if (!php) private #end class Go_runtime_fintto64c extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:497:6
var p_val:GOint64;
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_val : GOint64, p_ret : Pointer) {
super(gr,1856,"Go_runtime_fintto64c");
this._bds=_bds;
this.p_val=p_val;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t0:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_val : GOint64, p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fintto64c(0,[], p_val, p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_val : GOint64, p_ret : Pointer) : Void {
var _sf=new Go_runtime_fintto64c(_gr,[], p_val, p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_val : GOint64, p_ret : Pointer) : Go_runtime_fintto64c
{return new Go_runtime_fintto64c(gr,_bds, p_val, p_ret);
}
public function run():Go_runtime_fintto64c {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1856,0);
_SF1=Go_runtime_fintto64.call(this._goroutine,[],p_val);
_Next = -1;
return this;
case -1:
this.setLatest(1856,-1);
_t0=_SF1.res();
 // _t0 = fintto64(val) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:497:68
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:497:68

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_ret.store(_t0); // *ret = t0 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:497:53
}// end SubFn0
}
#if js @:expose("Go_tardisgolib_StringsUTF16") #end class Go_tardisgolib_StringsUTF16 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:32:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,495,"Go_tardisgolib_StringsUTF16");
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
this.setLatest(495,0);
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
#if (!php) private #end class Go_runtime_funpack64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:29:6
var p_f:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64) {
super(gr,1388,"Go_runtime_funpack64");
this._bds=_bds;
this.p_f=p_f;
Scheduler.push(gr,this);
}
var _res:{r0:GOint64, r1:GOint64, r2:Int, r3:Bool, r4:Bool};
public inline function res():Dynamic {return _res;}
var _t0:GOint64=null;
var _t1:GOint64=null;
var _t2:GOint64=null;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:GOint64=null;
var _t7:Int=0;
var _t8:Bool=false;
var _t9:Bool=false;
var _t10:Bool=false;
var _t11:GOint64=null;
var _t12:Int=0;
var _t13:Int=0;
var _t14:GOint64=null;
var _t15:Int=0;
var _t16:GOint64=null;
var _t17:Int=0;
var _t18:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64) : {r0:GOint64, r1:GOint64, r2:Int, r3:Bool, r4:Bool} {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_funpack64(0,[], p_f).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : GOint64) : {r0:GOint64, r1:GOint64, r2:Int, r3:Bool, r4:Bool} {
var _sf=new Go_runtime_funpack64(_gr,[], p_f).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64) : Go_runtime_funpack64
{return new Go_runtime_funpack64(gr,_bds, p_f);
}
public function run():Go_runtime_funpack64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1388,0);
this.SubFn0();
_Phi=0;
case 1: // switch.done
this.setLatest(1388,1);
_t6=((_Phi==3)?_t1:(_Phi==7)?_t11:(_Phi==10)?_t16:GOint64.make(0,0)); // _t6 = phi [3.switch.body: t1, 7.switch.next: t11, 10.for.loop: t16] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:29:33
_t7=((_Phi==3)?_t4:(_Phi==7)?_t12:(_Phi==10)?_t17:0); // _t7 = phi [3.switch.body: t4, 7.switch.next: t12, 10.for.loop: t17] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:29:46
this.setPH(1417);
_res= {r0:_t0,r1:_t6,r2:_t7,r3:false,r4:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0, t6, t7, false:bool, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:58:2

case 2: // switch.body
this.setLatest(1417,2);
this.SubFn1();
_Phi=2;
case 3: // switch.body
this.setLatest(1417,3);
this.SubFn2();
_Phi=3;
case 4: // switch.next
this.setLatest(1417,4);
this.SubFn3();
_Phi=4;
case 5: // if.then
this.setLatest(1417,5);
this.setPH(1397);
_res= {r0:_t0,r1:_t1,r2:_t4,r3:false,r4:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0, t1, t4, false:bool, true:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:38:4

case 6: // if.done
this.setLatest(1397,6);
this.setPH(1400);
_res= {r0:_t0,r1:_t1,r2:_t4,r3:true,r4:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0, t1, t4, true:bool, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:41:3

case 7: // switch.next
this.setLatest(1400,7);
this.SubFn4();
_Phi=7;
case 8: // if.then
this.setLatest(1400,8);
this.SubFn5();
_Phi=8;
case 9: // for.body
this.setLatest(1400,9);
this.SubFn6();
_Phi=9;
case 10: // for.loop
this.setLatest(1400,10);
this.setPH(1388);
_t16=((_Phi==8)?_t1:(_Phi==9)?_t14:GOint64.make(0,0)); // _t16 = phi [8.if.then: t1, 9.for.body: t14] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:29:33
_t17=((_Phi==8)?_t13:(_Phi==9)?_t15:0); // _t17 = phi [8.if.then: t13, 9.for.body: t15] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:29:46
this.SubFn7();
_Phi=10;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t2:GOint64;
var _t3:Int;
var _t5:Bool;
this.setPH(1389);
_t0=Force.toUint64(GOint64.and(p_f,GOint64.make(0x80000000,0x0))); // _t0 = f & 9223372036854775808:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:30:11
this.setPH(1390);
_t1=Force.toUint64(GOint64.and(p_f,GOint64.make(0xfffff,0xffffffff))); // _t1 = f & 4503599627370495:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:31:11
this.setPH(1391);
_t2=Force.toUint64(GOint64.ushr(p_f,52)); // _t2 = f >> 52:uint *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:32:13
_t3=GOint64.toInt(_t2); // _t3 = convert int <- uint64 (t2) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:32:11
_t4=(_t3&2047); // _t4 = t3 & 2047:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:32:27
_t5=(_t4==2047); // _t5 = t4 == 2047:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:32:27
_Next=_t5 ? 2 : 4; // if t5 goto 2.switch.body else 4.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:32:27
}// end SubFn0
private inline  function SubFn1():Void {
var _t8:Bool;
this.setPH(1395);
_t8=(GOint64.ucompare(_t1,GOint64.make(0x0,0x0))!=0); // _t8 = t1 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:36:11
_Next=_t8 ? 5 : 6; // if t8 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:36:11
}// end SubFn1
private inline  function SubFn2():Void {
var _t9:Bool;
this.setPH(1404);
_t9=(GOint64.ucompare(_t1,GOint64.make(0x0,0x0))!=0); // _t9 = t1 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
_Next=_t9 ? 8 : 1; // if t9 goto 8.if.then else 1.switch.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
}// end SubFn2
private inline  function SubFn3():Void {
var _t10:Bool;
_t10=(_t4==0); // _t10 = t4 == 0:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
_Next=_t10 ? 3 : 7; // if t10 goto 3.switch.body else 7.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
}// end SubFn3
private inline  function SubFn4():Void {
_t11=Force.toUint64(GOint64.or(_t1,GOint64.make(0x100000,0x0))); // _t11 = t1 | 4503599627370496:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
_t12=(_t4+(-1023)); // _t12 = t4 + -1023:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
_Next=1; // jump 1.switch.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
}// end SubFn4
private inline  function SubFn5():Void {
_t13=(_t4+(-1022)); // _t13 = t4 + -1022:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
_Next=10; // jump 10.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
}// end SubFn5
private inline  function SubFn6():Void {
_t14=Force.toUint64(GOint64.shl(_t16,GOint64.toInt(GOint64.make(0x0,0x1)))); // _t14 = t16 << 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
_t15=(_t17-1); // _t15 = t17 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
_Next=10; // jump 10.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:45:11
}// end SubFn6
private inline  function SubFn7():Void {
var _t18:Bool;
this.setPH(1406);
_t18=(GOint64.ucompare(_t16,GOint64.make(0x100000,0x0))<0); // _t18 = t16 < 4503599627370496:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:47:13
_Next=_t18 ? 9 : 1; // if t18 goto 9.for.body else 1.switch.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:47:13
}// end SubFn7
}
#if (!php) private #end class Go_runtime_fneg64c extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:493:6
var p_f:GOint64;
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_ret : Pointer) {
super(gr,1852,"Go_runtime_fneg64c");
this._bds=_bds;
this.p_f=p_f;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t0:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fneg64c(0,[], p_f, p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_ret : Pointer) : Void {
var _sf=new Go_runtime_fneg64c(_gr,[], p_f, p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_ret : Pointer) : Go_runtime_fneg64c
{return new Go_runtime_fneg64c(gr,_bds, p_f, p_ret);
}
public function run():Go_runtime_fneg64c {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1852,0);
_SF1=Go_runtime_fneg64.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(1852,-1);
_t0=_SF1.res();
 // _t0 = fneg64(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:493:66
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:493:66

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_ret.store(_t0); // *ret = t0 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:493:53
}// end SubFn0
}
#if (!php) private #end class Go_sync_runtime_Syncsemcheck extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:51:6
var p_size:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_size : Dynamic) {
super(gr,578,"Go_sync_runtime_Syncsemcheck");
this._bds=_bds;
this.p_size=p_size;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( p_size : Dynamic) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_sync_runtime_Syncsemcheck(0,[], p_size).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_size : Dynamic) : Void {
var _sf=new Go_sync_runtime_Syncsemcheck(_gr,[], p_size).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_size : Dynamic) : Go_sync_runtime_Syncsemcheck
{return new Go_sync_runtime_Syncsemcheck(gr,_bds, p_size);
}
public function run():Go_sync_runtime_Syncsemcheck {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(578,0);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:493:53

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_runtime_newTypeAssertionError extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:45:6
var p_ps1:Pointer;
var p_ps2:Pointer;
var p_ps3:Pointer;
var p_pmeth:Pointer;
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_ps1 : Pointer, p_ps2 : Pointer, p_ps3 : Pointer, p_pmeth : Pointer, p_ret : Pointer) {
super(gr,813,"Go_runtime_newTypeAssertionError");
this._bds=_bds;
this.p_ps1=p_ps1;
this.p_ps2=p_ps2;
this.p_ps3=p_ps3;
this.p_pmeth=p_pmeth;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _t1:String="";
var _t2:String="";
var _t3:Bool=false;
var _t4:String="";
var _t5:String="";
var _t6:Bool=false;
var _t7:String="";
var _t8:String="";
var _t9:Bool=false;
var _t10:String="";
var _t11:String="";
var _t12:Pointer=null;
var _t13:Pointer=null;
var _t14:Pointer=null;
var _t15:Pointer=null;
var _t16:Pointer=null;
var _t17:Interface=null;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_ps1 : Pointer, p_ps2 : Pointer, p_ps3 : Pointer, p_pmeth : Pointer, p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_newTypeAssertionError(0,[], p_ps1, p_ps2, p_ps3, p_pmeth, p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_ps1 : Pointer, p_ps2 : Pointer, p_ps3 : Pointer, p_pmeth : Pointer, p_ret : Pointer) : Void {
var _sf=new Go_runtime_newTypeAssertionError(_gr,[], p_ps1, p_ps2, p_ps3, p_pmeth, p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_ps1 : Pointer, p_ps2 : Pointer, p_ps3 : Pointer, p_pmeth : Pointer, p_ret : Pointer) : Go_runtime_newTypeAssertionError
{return new Go_runtime_newTypeAssertionError(gr,_bds, p_ps1, p_ps2, p_ps3, p_pmeth, p_ret);
}
public function run():Go_runtime_newTypeAssertionError {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(813,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(813,1);
this.SubFn1();
_Phi=1;
case 2: // if.done
this.setLatest(813,2);
this.setPH(814);
_t2=((_Phi==0)?"":(_Phi==1)?_t1:""); // _t2 = phi [0.entry: "":string, 1.if.then: t1] #s1 *ssa.Phi @ /usr/local/go/src/pkg/runtime/error.go:46:6
this.SubFn2();
_Phi=2;
case 3: // if.then
this.setLatest(814,3);
this.SubFn3();
_Phi=3;
case 4: // if.done
this.setLatest(814,4);
_t5=((_Phi==2)?"":(_Phi==3)?_t4:""); // _t5 = phi [2.if.done: "":string, 3.if.then: t4] #s2 *ssa.Phi @ /usr/local/go/src/pkg/runtime/error.go:46:10
this.SubFn4();
_Phi=4;
case 5: // if.then
this.setLatest(814,5);
this.SubFn5();
_Phi=5;
case 6: // if.done
this.setLatest(814,6);
_t8=((_Phi==4)?"":(_Phi==5)?_t7:""); // _t8 = phi [4.if.done: "":string, 5.if.then: t7] #s3 *ssa.Phi @ /usr/local/go/src/pkg/runtime/error.go:46:14
this.SubFn6();
_Phi=6;
case 7: // if.then
this.setLatest(814,7);
this.SubFn7();
_Phi=7;
case 8: // if.done
this.setLatest(814,8);
_t11=((_Phi==6)?"":(_Phi==7)?_t10:""); // _t11 = phi [6.if.done: "":string, 7.if.then: t10] #meth *ssa.Phi @ /usr/local/go/src/pkg/runtime/error.go:46:18
this.SubFn8();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/error.go:46:18

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(816);
_t0=(p_ps1!=null); // _t0 = ps1 != nil:*string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:48:9
_Next=_t0 ? 1 : 2; // if t0 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/runtime/error.go:48:9
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(817);
_t1=p_ps1.load(); // _t1 = *ps1 *ssa.UnOp @ /usr/local/go/src/pkg/runtime/error.go:49:8
_Next=2; // jump 2.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/error.go:49:8
}// end SubFn1
private inline  function SubFn2():Void {
var _t3:Bool;
this.setPH(819);
_t3=(p_ps2!=null); // _t3 = ps2 != nil:*string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:51:9
_Next=_t3 ? 3 : 4; // if t3 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/runtime/error.go:51:9
}// end SubFn2
private inline  function SubFn3():Void {
this.setPH(820);
_t4=p_ps2.load(); // _t4 = *ps2 *ssa.UnOp @ /usr/local/go/src/pkg/runtime/error.go:52:8
_Next=4; // jump 4.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/error.go:52:8
}// end SubFn3
private inline  function SubFn4():Void {
var _t6:Bool;
this.setPH(822);
_t6=(p_ps3!=null); // _t6 = ps3 != nil:*string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:54:9
_Next=_t6 ? 5 : 6; // if t6 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/runtime/error.go:54:9
}// end SubFn4
private inline  function SubFn5():Void {
this.setPH(823);
_t7=p_ps3.load(); // _t7 = *ps3 *ssa.UnOp @ /usr/local/go/src/pkg/runtime/error.go:55:8
_Next=6; // jump 6.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/error.go:55:8
}// end SubFn5
private inline  function SubFn6():Void {
var _t9:Bool;
this.setPH(825);
_t9=(p_pmeth!=null); // _t9 = pmeth != nil:*string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:57:11
_Next=_t9 ? 7 : 8; // if t9 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/runtime/error.go:57:11
}// end SubFn6
private inline  function SubFn7():Void {
this.setPH(826);
_t10=p_pmeth.load(); // _t10 = *pmeth *ssa.UnOp @ /usr/local/go/src/pkg/runtime/error.go:58:10
_Next=8; // jump 8.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/error.go:58:10
}// end SubFn7
private inline  function SubFn8():Void {
var _t12:Pointer;
var _t13:Pointer;
var _t14:Pointer;
var _t15:Pointer;
var _t16:Pointer;
var _t17:Interface;
this.setPH(828);
_t12=new Pointer({var _v=new Array<Dynamic>();_v=["","","",""]; _v;}); // _t12 = new TypeAssertionError (complit) *ssa.Alloc @ /usr/local/go/src/pkg/runtime/error.go:60:28
_t13=_t12.addr(0);  // _t13 = &t12.interfaceString [#0] *ssa.FieldAddr near /usr/local/go/src/pkg/runtime/error.go:60:28 [POINTER]
_t13.store(_t2); // *t13 = t2 *ssa.Store near /usr/local/go/src/pkg/runtime/error.go:60:28
_t14=_t12.addr(1);  // _t14 = &t12.concreteString [#1] *ssa.FieldAddr near /usr/local/go/src/pkg/runtime/error.go:60:28 [POINTER]
_t14.store(_t5); // *t14 = t5 *ssa.Store near /usr/local/go/src/pkg/runtime/error.go:60:28
_t15=_t12.addr(2);  // _t15 = &t12.assertedString [#2] *ssa.FieldAddr near /usr/local/go/src/pkg/runtime/error.go:60:28 [POINTER]
_t15.store(_t8); // *t15 = t8 *ssa.Store near /usr/local/go/src/pkg/runtime/error.go:60:28
_t16=_t12.addr(3);  // _t16 = &t12.missingMethod [#3] *ssa.FieldAddr near /usr/local/go/src/pkg/runtime/error.go:60:28 [POINTER]
_t16.store(_t11); // *t16 = t11 *ssa.Store near /usr/local/go/src/pkg/runtime/error.go:60:28
_t17=new Interface(6,_t12); // _t17 = make interface{} <- *TypeAssertionError (t12) *ssa.MakeInterface near /usr/local/go/src/pkg/runtime/error.go:60:28
p_ret.store(_t17); // *ret = t17 *ssa.Store @ /usr/local/go/src/pkg/runtime/error.go:60:2
}// end SubFn8
}
#if (!php) private #end class Go_runtime_newErrorString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:73:6
var p_s:String;
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String, p_ret : Pointer) {
super(gr,841,"Go_runtime_newErrorString");
this._bds=_bds;
this.p_s=p_s;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:String="";
var _t1:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : String, p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_newErrorString(0,[], p_s, p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_s : String, p_ret : Pointer) : Void {
var _sf=new Go_runtime_newErrorString(_gr,[], p_s, p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : String, p_ret : Pointer) : Go_runtime_newErrorString
{return new Go_runtime_newErrorString(gr,_bds, p_s, p_ret);
}
public function run():Go_runtime_newErrorString {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(841,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/error.go:60:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:String;
var _t1:Interface;
this.setPH(842);
_t0=p_s; // _t0 = changetype errorString <- string (s) *ssa.ChangeType @ /usr/local/go/src/pkg/runtime/error.go:74:20
_t1=new Interface(7,_t0); // _t1 = make interface{} <- errorString (t0) *ssa.MakeInterface near /usr/local/go/src/pkg/runtime/error.go:74:20
p_ret.store(_t1); // *ret = t1 *ssa.Store @ /usr/local/go/src/pkg/runtime/error.go:74:2
}// end SubFn0
}
#if js @:expose("Go_atomic_CompareAndSwapInt64") #end class Go_atomic_CompareAndSwapInt64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:61:6
var p_addr:Pointer;
var p_old:GOint64;
var p_new:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : GOint64, p_new : GOint64) {
super(gr,647,"Go_atomic_CompareAndSwapInt64");
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
this.setLatest(647,0);
this.SubFn0();

case 1: // if.then
this.setLatest(647,1);
this.SubFn1();
this.setPH(650);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:64:3

case 2: // if.done
this.setLatest(650,2);
this.setPH(652);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:66:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:GOint64;
var _t1:Bool;
this.setPH(648);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:62:5
_t1=(GOint64.compare(_t0,p_old)==0); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:62:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:62:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(649);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:63:3
}// end SubFn1
}
#if js @:expose("Go_atomic_LoadUint64") #end class Go_atomic_LoadUint64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:145:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,731,"Go_atomic_LoadUint64");
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
this.setLatest(731,0);
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
#if (!php) private #end class Go_strings_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,963,"Go_strings_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_strings_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_strings_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_strings_init
{return new Go_strings_init(gr,_bds);
}
public function run():Go_strings_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(963,0);
this.SubFn0();

case 1: // init.start
this.setLatest(963,1);
this.SubFn1();

case 2: // init.done
this.setLatest(963,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:145:53

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.strings_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:145:53
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:145:53
}// end SubFn0
private inline  function SubFn1():Void {
Go.strings_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:145:53
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:145:53
}// end SubFn1
}
#if js @:expose("Go_haxegoruntime_UTF8toRunes") #end class Go_haxegoruntime_UTF8toRunes extends StackFrameBasis implements StackFrame {  // langgoruntime.go:39:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,2862,"Go_haxegoruntime_UTF8toRunes");
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
this.setLatest(2862,0);
this.setPH(2863);
_SF1=Go_utf8_RuneCount.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(2863,-1);
_t0=_SF1.res();
 // _t0 = unicode/utf8.RuneCount(s) *ssa.Call @ langgoruntime.go:40:36
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(2863,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(2863,2);
this.setPH(2874);
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ langgoruntime.go:51:2

case 3: // for.loop
this.setLatest(2874,3);
this.setPH(2864);
_t5=((_Phi==0)?0:(_Phi==6)?_t20:0); // _t5 = phi [0.entry: 0:int, 6.for.done: t20] #si *ssa.Phi @ langgoruntime.go:41:2
this.setPH(2865);
_t6=((_Phi==0)?0:(_Phi==6)?_t21:0); // _t6 = phi [0.entry: 0:int, 6.for.done: t21] #ri *ssa.Phi @ langgoruntime.go:42:6
this.SubFn2();
_Phi=3;
case 4: // cond.true
this.setLatest(2865,4);
this.SubFn3();
_Phi=4;
case 5: // for.body
this.setLatest(2865,5);
this.SubFn4();
_Phi=5;
case 6: // for.done
this.setLatest(2865,6);
this.setPH(2870);
_SF2=Go_utf8_DecodeRune.call(this._goroutine,[],_t4);
_Next = -2;
return this;
case -2:
this.setLatest(2870,-2);
_t16=_SF2.res();
 // _t16 = unicode/utf8.DecodeRune(t4) *ssa.Call @ langgoruntime.go:47:33
this.SubFn5();
_Phi=6;
case 7: // for.loop
this.setLatest(2870,7);
this.setPH(2867);
_t22=((_Phi==1)?0:(_Phi==5)?_t15:0); // _t22 = phi [1.for.body: 0:int, 5.for.body: t15] #j *ssa.Phi @ langgoruntime.go:44:7
this.SubFn6();
_Phi=7;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(2863);
_t1=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t0) _v[_i]=0; _v;}),0,_t0); // _t1 = make []rune t0 t0 *ssa.MakeSlice @ langgoruntime.go:40:13
_Next=3; // jump 3.for.loop *ssa.Jump near langgoruntime.go:40:13
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Int;
var _t3:Int;
this.setPH(2866);
_t2=({var _v=p_s;_v==null?0:_v.len();}); // _t2 = len(s) *ssa.Call @ langgoruntime.go:43:24
_t3=(_t2-_t5); // _t3 = t2 - t5 *ssa.BinOp @ langgoruntime.go:43:27
_t4=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t3) _v[_i]=0; _v;}),0,_t3); // _t4 = make []byte t3 t3 *ssa.MakeSlice @ langgoruntime.go:43:12
_Next=7; // jump 7.for.loop *ssa.Jump near langgoruntime.go:43:12
}// end SubFn1
private inline  function SubFn2():Void {
var _t7:Int;
var _t8:Bool;
this.setPH(2865);
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
this.setPH(2868);
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
this.setPH(2871);
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
this.setPH(2867);
_t23=({var _v=p_s;_v==null?0:_v.len();}); // _t23 = len(s) *ssa.Call @ langgoruntime.go:44:23
_t24=(_t23-_t5); // _t24 = t23 - t5 *ssa.BinOp @ langgoruntime.go:44:27
_t25=(_t22<_t24); // _t25 = t22 < t24 *ssa.BinOp @ langgoruntime.go:44:17
_Next=_t25 ? 5 : 6; // if t25 goto 5.for.body else 6.for.done *ssa.If near langgoruntime.go:44:17
}// end SubFn6
}
#if js @:expose("Go_atomic_LoadPointer") #end class Go_atomic_LoadPointer extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:151:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,737,"Go_atomic_LoadPointer");
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
this.setLatest(737,0);
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
#if js @:expose("Go__star_runtime_dot_TypeAssertionError_Error") #end class Go__star_runtime_dot_TypeAssertionError_Error extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:28:30
var p_e:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_e : Pointer) {
super(gr,796,"Go__star_runtime_dot_TypeAssertionError_Error");
this._bds=_bds;
this.p_e=p_e;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _t0:Pointer=null;
var _t1:String="";
var _t2:Bool=false;
var _t3:String="";
var _t4:Pointer=null;
var _t5:String="";
var _t6:Bool=false;
var _t7:String="";
var _t8:String="";
var _t9:Pointer=null;
var _t10:String="";
var _t11:String="";
var _t12:Pointer=null;
var _t13:String="";
var _t14:Bool=false;
var _t15:String="";
var _t16:String="";
var _t17:Pointer=null;
var _t18:String="";
var _t19:String="";
var _t20:String="";
var _t21:Pointer=null;
var _t22:String="";
var _t23:String="";
var _t24:Pointer=null;
var _t25:String="";
var _t26:String="";
var _t27:String="";
var _t28:Pointer=null;
var _t29:String="";
var _t30:String="";
var _t31:String="";
var _t32:Pointer=null;
var _t33:String="";
var _t34:String="";
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_e : Pointer) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_TypeAssertionError_Error(0,[], p_e).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_e : Pointer) : String {
var _sf=new Go__star_runtime_dot_TypeAssertionError_Error(_gr,[], p_e).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_e : Pointer) : Go__star_runtime_dot_TypeAssertionError_Error
{return new Go__star_runtime_dot_TypeAssertionError_Error(gr,_bds, p_e);
}
public function run():Go__star_runtime_dot_TypeAssertionError_Error {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(796,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(796,1);
this.SubFn1();
_Phi=1;
case 2: // if.done
this.setLatest(796,2);
this.setPH(797);
_t3=((_Phi==0)?_t1:(_Phi==1)?"interface":""); // _t3 = phi [0.entry: t1, 1.if.then: "interface":string] #inter *ssa.Phi @ /usr/local/go/src/pkg/runtime/error.go:29:2
this.SubFn2();
_Phi=2;
case 3: // if.then
this.setLatest(797,3);
this.SubFn3();
this.setPH(802);
_res= _t11;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t11 *ssa.Return @ /usr/local/go/src/pkg/runtime/error.go:34:3

case 4: // if.done
this.setLatest(802,4);
this.SubFn4();
_Phi=4;
case 5: // if.then
this.setLatest(802,5);
this.SubFn5();
this.setPH(805);
_res= _t23;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t23 *ssa.Return @ /usr/local/go/src/pkg/runtime/error.go:37:3

case 6: // if.done
this.setLatest(805,6);
this.SubFn6();
this.setPH(808);
_res= _t34;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t34 *ssa.Return @ /usr/local/go/src/pkg/runtime/error.go:40:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Pointer;
var _t2:Bool;
this.setPH(797);
_t0=p_e.addr(0);  // _t0 = &e.interfaceString [#0] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/error.go:29:13 [POINTER]
_t1=_t0.load(); // _t1 = *t0 *ssa.UnOp near /usr/local/go/src/pkg/runtime/error.go:29:13
this.setPH(798);
_t2=(_t1==""); // _t2 = t1 == "":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:30:11
_Next=_t2 ? 1 : 2; // if t2 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/runtime/error.go:30:11
}// end SubFn0
private inline  function SubFn1():Void {
_Next=2; // jump 2.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/error.go:30:11
}// end SubFn1
private inline  function SubFn2():Void {
var _t4:Pointer;
var _t5:String;
var _t6:Bool;
this.setPH(801);
_t4=p_e.addr(1);  // _t4 = &e.concreteString [#1] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/error.go:33:7 [POINTER]
_t5=_t4.load(); // _t5 = *t4 *ssa.UnOp near /usr/local/go/src/pkg/runtime/error.go:33:7
_t6=(_t5==""); // _t6 = t5 == "":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:33:22
_Next=_t6 ? 3 : 4; // if t6 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/runtime/error.go:33:22
}// end SubFn2
private inline  function SubFn3():Void {
var _t7:String;
var _t8:String;
var _t9:Pointer;
var _t10:String;
this.setPH(802);
_t7=("interface conversion: "+_t3); // _t7 = "interface convers...":string + t3 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:34:35
_t8=(_t7+" is nil, not "); // _t8 = t7 + " is nil, not ":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:34:43
_t9=p_e.addr(2);  // _t9 = &e.assertedString [#2] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/error.go:34:65 [POINTER]
_t10=_t9.load(); // _t10 = *t9 *ssa.UnOp near /usr/local/go/src/pkg/runtime/error.go:34:65
_t11=(_t8+_t10); // _t11 = t8 + t10 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:34:61
}// end SubFn3
private inline  function SubFn4():Void {
var _t12:Pointer;
var _t13:String;
var _t14:Bool;
this.setPH(804);
_t12=p_e.addr(3);  // _t12 = &e.missingMethod [#3] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/error.go:36:7 [POINTER]
_t13=_t12.load(); // _t13 = *t12 *ssa.UnOp near /usr/local/go/src/pkg/runtime/error.go:36:7
_t14=(_t13==""); // _t14 = t13 == "":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:36:21
_Next=_t14 ? 5 : 6; // if t14 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/runtime/error.go:36:21
}// end SubFn4
private inline  function SubFn5():Void {
var _t15:String;
var _t16:String;
var _t17:Pointer;
var _t18:String;
var _t19:String;
var _t20:String;
var _t21:Pointer;
var _t22:String;
this.setPH(805);
_t15=("interface conversion: "+_t3); // _t15 = "interface convers...":string + t3 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:37:35
_t16=(_t15+" is "); // _t16 = t15 + " is ":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:37:43
_t17=p_e.addr(1);  // _t17 = &e.concreteString [#1] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/error.go:37:56 [POINTER]
_t18=_t17.load(); // _t18 = *t17 *ssa.UnOp near /usr/local/go/src/pkg/runtime/error.go:37:56
_t19=(_t16+_t18); // _t19 = t16 + t18 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:37:52
_t20=(_t19+", not "); // _t20 = t19 + ", not ":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:37:71
this.setPH(806);
_t21=p_e.addr(2);  // _t21 = &e.assertedString [#2] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/error.go:38:17 [POINTER]
_t22=_t21.load(); // _t22 = *t21 *ssa.UnOp near /usr/local/go/src/pkg/runtime/error.go:38:17
_t23=(_t20+_t22); // _t23 = t20 + t22 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:38:13
}// end SubFn5
private inline  function SubFn6():Void {
var _t24:Pointer;
var _t25:String;
var _t26:String;
var _t27:String;
var _t28:Pointer;
var _t29:String;
var _t30:String;
var _t31:String;
var _t32:Pointer;
var _t33:String;
this.setPH(808);
_t24=p_e.addr(1);  // _t24 = &e.concreteString [#1] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/error.go:40:38 [POINTER]
_t25=_t24.load(); // _t25 = *t24 *ssa.UnOp near /usr/local/go/src/pkg/runtime/error.go:40:38
_t26=("interface conversion: "+_t25); // _t26 = "interface convers...":string + t25 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:40:34
_t27=(_t26+" is not "); // _t27 = t26 + " is not ":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:40:53
_t28=p_e.addr(2);  // _t28 = &e.assertedString [#2] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/error.go:40:70 [POINTER]
_t29=_t28.load(); // _t29 = *t28 *ssa.UnOp near /usr/local/go/src/pkg/runtime/error.go:40:70
_t30=(_t27+_t29); // _t30 = t27 + t29 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:40:66
_t31=(_t30+": missing method "); // _t31 = t30 + ": missing method ":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:40:85
this.setPH(809);
_t32=p_e.addr(3);  // _t32 = &e.missingMethod [#3] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/error.go:41:27 [POINTER]
_t33=_t32.load(); // _t33 = *t32 *ssa.UnOp near /usr/local/go/src/pkg/runtime/error.go:41:27
_t34=(_t31+_t33); // _t34 = t31 + t33 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:41:23
}// end SubFn6
}
#if js @:expose("Go_atomic_LoadUintptr") #end class Go_atomic_LoadUintptr extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:148:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,734,"Go_atomic_LoadUintptr");
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
this.setLatest(734,0);
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
#if js @:expose("Go_haxegoruntime_RunesToUTF8") #end class Go_haxegoruntime_RunesToUTF8 extends StackFrameBasis implements StackFrame {  // langgoruntime.go:79:6
var p_r:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Slice) {
super(gr,2902,"Go_haxegoruntime_RunesToUTF8");
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
this.setLatest(2902,0);
this.SubFn0();
_Phi=0;
case 1: // rangeindex.loop
this.setLatest(2902,1);
this.setPH(2903);
_t2=((_Phi==0)?_t0:(_Phi==2)?_t13:new Slice(new Pointer(new Array<Int>()),0,0)); // _t2 = phi [0.entry: t0, 2.rangeindex.body: t13] #ret *ssa.Phi @ langgoruntime.go:80:6
_t3=((_Phi==0)?(-1):(_Phi==2)?_t4:0); // _t3 = phi [0.entry: -1:int, 2.rangeindex.body: t4] *ssa.Phi near langgoruntime.go:80:6
this.SubFn1();
_Phi=1;
case 2: // rangeindex.body
this.setLatest(2903,2);
this.SubFn2();
this.setPH(2906);
_SF1=Go_utf8_RuneLen.call(this._goroutine,[],_t7);
_Next = -1;
return this;
case -1:
this.setLatest(2906,-1);
_t8=_SF1.res();
 // _t8 = unicode/utf8.RuneLen(t7) *ssa.Call @ langgoruntime.go:83:35
this.SubFn3();
this.setPH(2907);
Go_utf8_EncodeRune.call(this._goroutine,[],_t9,_t11);
_Next = -2;
return this;
case -2:
this.setLatest(2907,-2);
 // _t12 = unicode/utf8.EncodeRune(t9, t11) *ssa.Call @ langgoruntime.go:84:18 [REGISTER VALUE UN-USED]
this.SubFn4();
_Phi=2;
case 3: // rangeindex.done
this.setLatest(2907,3);
this.setPH(2910);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ langgoruntime.go:87:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(2904);
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
this.setPH(2906);
if((_t4<0)||(_t4>=p_r.len())) Scheduler.ioor(); // _t6 = &r[t4] *ssa.IndexAddr @ langgoruntime.go:83:37 [POINTER]
_t6=p_r.addr(_t4);  // _t6 = &r[t4] *ssa.IndexAddr @ langgoruntime.go:83:37 [POINTER]
_t7=(_t6.load()|0); // _t7 = *t6 *ssa.UnOp near langgoruntime.go:83:37
}// end SubFn2
private inline  function SubFn3():Void {
var _t10:Pointer;
_t9=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t8) _v[_i]=0; _v;}),0,_t8); // _t9 = make []byte t8 t8 *ssa.MakeSlice @ langgoruntime.go:83:14
this.setPH(2907);
if((_t4<0)||(_t4>=p_r.len())) Scheduler.ioor(); // _t10 = &r[t4] *ssa.IndexAddr @ langgoruntime.go:84:25 [POINTER]
_t10=p_r.addr(_t4);  // _t10 = &r[t4] *ssa.IndexAddr @ langgoruntime.go:84:25 [POINTER]
_t11=(_t10.load()|0); // _t11 = *t10 *ssa.UnOp near langgoruntime.go:84:25
}// end SubFn3
private inline  function SubFn4():Void {
this.setPH(2908);
_t13={var _v:Slice;if(_t2==null) _v=_t9;else if(_t2.len()==0) _v=_t9;else if(_t9==null) _v=_t2;else if(_t9.len()==0) _v=_t2;else {var l0:Int=_t2.len();_v=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t2.len()+_t9.len()) _v[_i]=0; _v;}),0,_t2.len()+_t9.len());for(_i in 0...l0) _v.setAt(_i,Deep.copy(_t2.getAt(_i)));for(_i in 0..._t9.len()) _v.setAt(_i+l0,Deep.copy(_t9.getAt(_i)));};_v;}; // _t13 = append(t2, t9...) *ssa.Call @ langgoruntime.go:85:15
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near langgoruntime.go:85:15
}// end SubFn4
}
#if js @:expose("Go__star_runtime_dot_errorCString_RuntimeError") #end class Go__star_runtime_dot_errorCString_RuntimeError extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:80:23
var p_recv:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_recv : Pointer) {
super(gr,848,"Go__star_runtime_dot_errorCString_RuntimeError");
this._bds=_bds;
this.p_recv=p_recv;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Dynamic=null;
var _SF1:StackFrame;
var _Next:Int=0;
public static inline function callFromHaxe( p_recv : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_errorCString_RuntimeError(0,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_recv : Pointer) : Void {
var _sf=new Go__star_runtime_dot_errorCString_RuntimeError(_gr,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_recv : Pointer) : Go__star_runtime_dot_errorCString_RuntimeError
{return new Go__star_runtime_dot_errorCString_RuntimeError(gr,_bds, p_recv);
}
public function run():Go__star_runtime_dot_errorCString_RuntimeError {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(848,0);
this.SubFn0();
Go_runtime_dot_errorCString_RuntimeError.call(this._goroutine,[],_t0);
_Next = -1;
return this;
case -1:
this.setLatest(848,-1);
 // _t1 = (runtime.errorCString).RuntimeError(t0) *ssa.Call near langgoruntime.go:85:15 [REGISTER VALUE UN-USED]
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near langgoruntime.go:85:15

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=p_recv.load(); // _t0 = *recv *ssa.UnOp near langgoruntime.go:85:15
}// end SubFn0
}
#if js @:expose("Go_atomic_CompareAndSwapUintptr") #end class Go_atomic_CompareAndSwapUintptr extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:88:6
var p_addr:Pointer;
var p_old:Dynamic;
var p_new:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : Dynamic, p_new : Dynamic) {
super(gr,674,"Go_atomic_CompareAndSwapUintptr");
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
this.setLatest(674,0);
this.SubFn0();

case 1: // if.then
this.setLatest(674,1);
this.SubFn1();
this.setPH(677);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:91:3

case 2: // if.done
this.setLatest(677,2);
this.setPH(679);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:93:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Dynamic;
var _t1:Bool;
this.setPH(675);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:89:5
_t1=(Force.uintCompare((_t0|0),(p_old|0))==0); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:89:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:89:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(676);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:90:3
}// end SubFn1
}
#if js @:expose("Go_atomic_LoadInt32") #end class Go_atomic_LoadInt32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:136:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,722,"Go_atomic_LoadInt32");
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
this.setLatest(722,0);
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
#if js @:expose("Go_utf8_ValidRune") #end class Go_utf8_ValidRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:433:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,3505,"Go_utf8_ValidRune");
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
this.setLatest(3505,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(3505,1);
this.setPH(3508);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:436:3

case 2: // switch.body
this.setLatest(3508,2);
this.setPH(3510);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:438:3

case 3: // switch.next
this.setLatest(3510,3);
this.SubFn1();
_Phi=3;
case 4: // switch.body
this.setLatest(3510,4);
this.setPH(3512);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:440:3

case 5: // switch.next
this.setLatest(3512,5);
this.SubFn2();
_Phi=5;
case 6: // binop.rhs
this.setLatest(3512,6);
this.SubFn3();
_Phi=6;
case 7: // binop.done
this.setLatest(3512,7);
this.setPH(3509);
_t4=((_Phi==3)?false:(_Phi==6)?_t3:false); // _t4 = phi [3.switch.next: false:bool, 6.binop.rhs: t3] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:25
this.SubFn4();
_Phi=7;
case 8: // switch.next
this.setLatest(3509,8);
this.setPH(3514);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:442:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(3507);
_t0=(p_r<0); // _t0 = r < 0:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:435:9
_Next=_t0 ? 1 : 3; // if t0 goto 1.switch.body else 3.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:435:9
}// end SubFn0
private inline  function SubFn1():Void {
var _t1:Bool;
this.setPH(3509);
_t1=(55296<=p_r); // _t1 = 55296:rune <= r *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:20
_Next=_t1 ? 6 : 7; // if t1 goto 6.binop.rhs else 7.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:20
}// end SubFn1
private inline  function SubFn2():Void {
var _t2:Bool;
this.setPH(3511);
_t2=(p_r>1114111); // _t2 = r > 1114111:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:439:9
_Next=_t2 ? 4 : 8; // if t2 goto 4.switch.body else 8.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:439:9
}// end SubFn2
private inline  function SubFn3():Void {
this.setPH(3509);
_t3=(p_r<=57343); // _t3 = r <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
_Next=7; // jump 7.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
}// end SubFn3
private inline  function SubFn4():Void {
_Next=_t4 ? 2 : 5; // if t4 goto 2.switch.body else 5.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
}// end SubFn4
}
#if js @:expose("Go__star_runtime_dot_errorString_Error") #end class Go__star_runtime_dot_errorString_Error extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:68:22
var p_recv:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_recv : Pointer) {
super(gr,836,"Go__star_runtime_dot_errorString_Error");
this._bds=_bds;
this.p_recv=p_recv;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _t0:String="";
var _SF1:StackFrame;
var _t1:String="";
var _Next:Int=0;
public static inline function callFromHaxe( p_recv : Pointer) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_errorString_Error(0,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_recv : Pointer) : String {
var _sf=new Go__star_runtime_dot_errorString_Error(_gr,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_recv : Pointer) : Go__star_runtime_dot_errorString_Error
{return new Go__star_runtime_dot_errorString_Error(gr,_bds, p_recv);
}
public function run():Go__star_runtime_dot_errorString_Error {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(836,0);
this.SubFn0();
_SF1=Go_runtime_dot_errorString_Error.call(this._goroutine,[],_t0);
_Next = -1;
return this;
case -1:
this.setLatest(836,-1);
_t1=_SF1.res();
 // _t1 = (runtime.errorString).Error(t0) *ssa.Call near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=p_recv.load(); // _t0 = *recv *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:437:30
}// end SubFn0
}
#if js @:expose("Go_atomic_AddUintptr") #end class Go_atomic_AddUintptr extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:130:6
var p_addr:Pointer;
var p_delta:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : Dynamic) {
super(gr,716,"Go_atomic_AddUintptr");
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
this.setLatest(716,0);
this.SubFn0();
this.setPH(718);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:132:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Dynamic;
var _t1:Dynamic;
this.setPH(717);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:131:2
_t1=((_t0|0)+(p_delta|0)); // _t1 = t0 + delta *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:131:2
p_addr.store(_t1); // *addr = t1 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:131:2
this.setPH(718);
_t2=p_addr.load(); // _t2 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:132:9
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_Runes2Raw") #end class Go_haxegoruntime_Runes2Raw extends StackFrameBasis implements StackFrame {  // langgoruntime.go:91:6
var p_r:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Slice) {
super(gr,2914,"Go_haxegoruntime_Runes2Raw");
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
this.setLatest(2914,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(2914,1);
this.setPH(2917);
_SF1=Go_haxegoruntime_RunesToUTF16.call(this._goroutine,[],p_r);
_Next = -1;
return this;
case -1:
this.setLatest(2917,-1);
_t2=_SF1.res();
 // _t2 = RunesToUTF16(r) *ssa.Call @ langgoruntime.go:94:29
this.SubFn1();
_Phi=1;
case 2: // switch.body
this.setLatest(2917,2);
this.setPH(2924);
_SF2=Go_haxegoruntime_RunesToUTF8.call(this._goroutine,[],p_r);
_Next = -2;
return this;
case -2:
this.setLatest(2924,-2);
_t6=_SF2.res();
 // _t6 = RunesToUTF8(r) *ssa.Call @ langgoruntime.go:101:27
this.SubFn2();
_Phi=2;
case 3: // switch.next
this.setLatest(2924,3);
this.SubFn3();
_Phi=3;
case 4: // rangeindex.loop
this.setLatest(2924,4);
_t11=((_Phi==1)?(-1):(_Phi==5)?_t12:0); // _t11 = phi [1.switch.body: -1:int, 5.rangeindex.body: t12] *ssa.Phi near langgoruntime.go:101:27
this.SubFn4();
_Phi=4;
case 5: // rangeindex.body
this.setLatest(2924,5);
this.SubFn5();
_Phi=5;
case 6: // rangeindex.done
this.setLatest(2924,6);
this.setPH(2922);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ langgoruntime.go:99:3

case 7: // switch.next
this.setLatest(2922,7);
this.SubFn6();
this.setPH(2933);
_res= _t19;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t19 *ssa.Return @ langgoruntime.go:110:2

case 8: // rangeindex.loop
this.setLatest(2933,8);
_t20=((_Phi==2)?(-1):(_Phi==9)?_t21:0); // _t20 = phi [2.switch.body: -1:int, 9.rangeindex.body: t21] *ssa.Phi near langgoruntime.go:110:2
this.SubFn7();
_Phi=8;
case 9: // rangeindex.body
this.setLatest(2933,9);
this.SubFn8();
_Phi=9;
case 10: // rangeindex.done
this.setLatest(2933,10);
this.setPH(2929);
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
this.setPH(2918);
_t3=({var _v=_t2;_v==null?0:_v.len();}); // _t3 = len(t2) *ssa.Call @ langgoruntime.go:95:39
_t4=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t3) _v[_i]=0; _v;}),0,_t3); // _t4 = make []int t3 t3 *ssa.MakeSlice @ langgoruntime.go:95:28
_t5=({var _v=_t2;_v==null?0:_v.len();}); // _t5 = len(t2) *ssa.Call near langgoruntime.go:95:28
_Next=4; // jump 4.rangeindex.loop *ssa.Jump near langgoruntime.go:95:28
}// end SubFn1
private inline  function SubFn2():Void {
var _t7:Int;
this.setPH(2925);
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
this.setPH(2920);
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
this.setPH(2933);
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
this.setPH(2927);
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
#if js @:expose("Go__star_runtime_dot_TypeAssertionError_RuntimeError") #end class Go__star_runtime_dot_TypeAssertionError_RuntimeError extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:26:28
var p_arg0:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer) {
super(gr,794,"Go__star_runtime_dot_TypeAssertionError_RuntimeError");
this._bds=_bds;
this.p_arg0=p_arg0;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( p_arg0 : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_TypeAssertionError_RuntimeError(0,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_arg0 : Pointer) : Void {
var _sf=new Go__star_runtime_dot_TypeAssertionError_RuntimeError(_gr,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer) : Go__star_runtime_dot_TypeAssertionError_RuntimeError
{return new Go__star_runtime_dot_TypeAssertionError_RuntimeError(gr,_bds, p_arg0);
}
public function run():Go__star_runtime_dot_TypeAssertionError_RuntimeError {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(794,0);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near langgoruntime.go:104:25

default: Scheduler.bbi();}}}
}
#if js @:expose("Go__star_runtime_dot_errorString_RuntimeError") #end class Go__star_runtime_dot_errorString_RuntimeError extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:66:22
var p_recv:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_recv : Pointer) {
super(gr,834,"Go__star_runtime_dot_errorString_RuntimeError");
this._bds=_bds;
this.p_recv=p_recv;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:String="";
var _SF1:StackFrame;
var _Next:Int=0;
public static inline function callFromHaxe( p_recv : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_errorString_RuntimeError(0,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_recv : Pointer) : Void {
var _sf=new Go__star_runtime_dot_errorString_RuntimeError(_gr,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_recv : Pointer) : Go__star_runtime_dot_errorString_RuntimeError
{return new Go__star_runtime_dot_errorString_RuntimeError(gr,_bds, p_recv);
}
public function run():Go__star_runtime_dot_errorString_RuntimeError {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(834,0);
this.SubFn0();
Go_runtime_dot_errorString_RuntimeError.call(this._goroutine,[],_t0);
_Next = -1;
return this;
case -1:
this.setLatest(834,-1);
 // _t1 = (runtime.errorString).RuntimeError(t0) *ssa.Call near langgoruntime.go:104:25 [REGISTER VALUE UN-USED]
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near langgoruntime.go:104:25

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=p_recv.load(); // _t0 = *recv *ssa.UnOp near langgoruntime.go:104:25
}// end SubFn0
}
#if js @:expose("Go_runtime_Goexit") #end class Go_runtime_Goexit extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:17:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,434,"Go_runtime_Goexit");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_Goexit(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_runtime_Goexit(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_runtime_Goexit
{return new Go_runtime_Goexit(gr,_bds);
}
public function run():Go_runtime_Goexit {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(434,0);
this.SubFn0();
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(434,-1);
 // panic t0 *ssa.Panic @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:17:49

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"runtime.Goexit() not yet implemented"); // _t0 = make interface{} <- string ("runtime.Goexit() ...":string) *ssa.MakeInterface near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:17:49
}// end SubFn0
}
#if js @:expose("Go_atomic_LoadUint32") #end class Go_atomic_LoadUint32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:142:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,728,"Go_atomic_LoadUint32");
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
this.setLatest(728,0);
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
#if js @:expose("Go_atomic_CompareAndSwapUint32") #end class Go_atomic_CompareAndSwapUint32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:70:6
var p_addr:Pointer;
var p_old:Int;
var p_new:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : Int, p_new : Int) {
super(gr,656,"Go_atomic_CompareAndSwapUint32");
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
this.setLatest(656,0);
this.SubFn0();

case 1: // if.then
this.setLatest(656,1);
this.SubFn1();
this.setPH(659);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:73:3

case 2: // if.done
this.setLatest(659,2);
this.setPH(661);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:75:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
var _t1:Bool;
this.setPH(657);
_t0=(p_addr.load()|0); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:71:5
_t1=(Force.uintCompare(_t0,p_old)==0); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:71:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:71:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(658);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:72:3
}// end SubFn1
}
#if (!php) private #end class Go_runtime_panicwrap extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:121:6
var p_pkg:String;
var p_typ:String;
var p_meth:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_pkg : String, p_typ : String, p_meth : String) {
super(gr,889,"Go_runtime_panicwrap");
this._bds=_bds;
this.p_pkg=p_pkg;
this.p_typ=p_typ;
this.p_meth=p_meth;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:String="";
var _t1:String="";
var _t2:String="";
var _t3:String="";
var _t4:String="";
var _t5:String="";
var _t6:String="";
var _t7:String="";
var _t8:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_pkg : String, p_typ : String, p_meth : String) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_panicwrap(0,[], p_pkg, p_typ, p_meth).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_pkg : String, p_typ : String, p_meth : String) : Void {
var _sf=new Go_runtime_panicwrap(_gr,[], p_pkg, p_typ, p_meth).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_pkg : String, p_typ : String, p_meth : String) : Go_runtime_panicwrap
{return new Go_runtime_panicwrap(gr,_bds, p_pkg, p_typ, p_meth);
}
public function run():Go_runtime_panicwrap {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(889,0);
this.SubFn0();
this.setPH(890);
Scheduler.panic(this._goroutine,_t8);_Next = -1;
return this;
case -1:
this.setLatest(890,-1);
 // panic t8 *ssa.Panic @ /usr/local/go/src/pkg/runtime/error.go:122:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:String;
var _t1:String;
var _t2:String;
var _t3:String;
var _t4:String;
var _t5:String;
var _t6:String;
var _t7:String;
_t0=("value method "+p_pkg); // _t0 = "value method ":string + pkg *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:122:24
_t1=(_t0+"."); // _t1 = t0 + ".":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:122:30
_t2=(_t1+p_typ); // _t2 = t1 + typ *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:122:36
_t3=(_t2+"."); // _t3 = t2 + ".":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:122:42
_t4=(_t3+p_meth); // _t4 = t3 + meth *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:122:48
_t5=(_t4+" called using nil *"); // _t5 = t4 + " called using nil *":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:122:55
_t6=(_t5+p_typ); // _t6 = t5 + typ *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:122:79
_t7=(_t6+" pointer"); // _t7 = t6 + " pointer":string *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:122:85
_t8=new Interface(0,_t7); // _t8 = make interface{} <- string (t7) *ssa.MakeInterface near /usr/local/go/src/pkg/runtime/error.go:122:85
}// end SubFn0
}
#if js @:expose("Go_atomic_LoadInt64") #end class Go_atomic_LoadInt64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:139:6
var p_addr:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer) {
super(gr,725,"Go_atomic_LoadInt64");
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
this.setLatest(725,0);
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
#if js @:expose("Go_atomic_CompareAndSwapPointer") #end class Go_atomic_CompareAndSwapPointer extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:97:6
var p_addr:Pointer;
var p_old:UnsafePointer;
var p_new:UnsafePointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : UnsafePointer, p_new : UnsafePointer) {
super(gr,683,"Go_atomic_CompareAndSwapPointer");
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
this.setLatest(683,0);
this.SubFn0();

case 1: // if.then
this.setLatest(683,1);
this.SubFn1();
this.setPH(686);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:100:3

case 2: // if.done
this.setLatest(686,2);
this.setPH(688);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:102:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:UnsafePointer;
var _t1:Bool;
this.setPH(684);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:98:5
_t1=(_t0==p_old); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:98:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:98:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(685);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:99:3
}// end SubFn1
}
#if js @:expose("Go_atomic_StoreUintptr") #end class Go_atomic_StoreUintptr extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:166:6
var p_addr:Pointer;
var p_val:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : Dynamic) {
super(gr,752,"Go_atomic_StoreUintptr");
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
this.setLatest(752,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:99:3

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:166:49
}// end SubFn0
}
#if js @:expose("Go_atomic_AddUint32") #end class Go_atomic_AddUint32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:112:6
var p_addr:Pointer;
var p_delta:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : Int) {
super(gr,698,"Go_atomic_AddUint32");
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
this.setLatest(698,0);
this.SubFn0();
this.setPH(700);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:114:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
var _t1:Int;
this.setPH(699);
_t0=(p_addr.load()|0); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:113:2
_t1=Force.toUint32((_t0+p_delta)); // _t1 = t0 + delta *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:113:2
p_addr.store(_t1); // *addr = t1 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:113:2
this.setPH(700);
_t2=(p_addr.load()|0); // _t2 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:114:9
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
#if js @:expose("Go_atomic_StoreUint64") #end class Go_atomic_StoreUint64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:163:6
var p_addr:Pointer;
var p_val:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : GOint64) {
super(gr,749,"Go_atomic_StoreUint64");
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
this.setLatest(749,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near stateful.go:89:12

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:163:46
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_RunesToUTF16") #end class Go_haxegoruntime_RunesToUTF16 extends StackFrameBasis implements StackFrame {  // langgoruntime.go:75:6
var p_r:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Slice) {
super(gr,2898,"Go_haxegoruntime_RunesToUTF16");
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
this.setLatest(2898,0);
this.setPH(2899);
_SF1=Go_utf16_Encode.call(this._goroutine,[],p_r);
_Next = -1;
return this;
case -1:
this.setLatest(2899,-1);
_t0=_SF1.res();
 // _t0 = unicode/utf16.Encode(r) *ssa.Call @ langgoruntime.go:76:21
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ langgoruntime.go:76:2

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_runtime_divlu extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:439:6
var p_u1:GOint64;
var p_u0:GOint64;
var p_v:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_u1 : GOint64, p_u0 : GOint64, p_v : GOint64) {
super(gr,1798,"Go_runtime_divlu");
this._bds=_bds;
this.p_u1=p_u1;
this.p_u0=p_u0;
this.p_v=p_v;
Scheduler.push(gr,this);
}
var _res:{r0:GOint64, r1:GOint64};
public inline function res():Dynamic {return _res;}
var _t0:Bool=false;
var _t1:Int=0;
var _t2:GOint64=null;
var _t3:GOint64=null;
var _t4:GOint64=null;
var _t5:GOint64=null;
var _t6:Int=0;
var _t7:GOint64=null;
var _t8:GOint64=null;
var _t9:GOint64=null;
var _t10:GOint64=null;
var _t11:GOint64=null;
var _t12:GOint64=null;
var _t13:GOint64=null;
var _t14:GOint64=null;
var _t15:GOint64=null;
var _t16:Int=0;
var _t17:GOint64=null;
var _t18:Bool=false;
var _t19:GOint64=null;
var _t20:GOint64=null;
var _t21:Bool=false;
var _t22:GOint64=null;
var _t23:GOint64=null;
var _t24:Bool=false;
var _t25:GOint64=null;
var _t26:GOint64=null;
var _t27:GOint64=null;
var _t28:GOint64=null;
var _t29:GOint64=null;
var _t30:GOint64=null;
var _t31:GOint64=null;
var _t32:GOint64=null;
var _t33:GOint64=null;
var _t34:GOint64=null;
var _t35:GOint64=null;
var _t36:Bool=false;
var _t37:GOint64=null;
var _t38:GOint64=null;
var _t39:Bool=false;
var _t40:GOint64=null;
var _t41:GOint64=null;
var _t42:Bool=false;
var _t43:GOint64=null;
var _t44:GOint64=null;
var _t45:GOint64=null;
var _t46:GOint64=null;
var _t47:GOint64=null;
var _t48:GOint64=null;
var _t49:GOint64=null;
var _t50:GOint64=null;
var _t51:GOint64=null;
var _t52:GOint64=null;
var _t53:GOint64=null;
var _t54:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_u1 : GOint64, p_u0 : GOint64, p_v : GOint64) : {r0:GOint64, r1:GOint64} {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_divlu(0,[], p_u1, p_u0, p_v).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_u1 : GOint64, p_u0 : GOint64, p_v : GOint64) : {r0:GOint64, r1:GOint64} {
var _sf=new Go_runtime_divlu(_gr,[], p_u1, p_u0, p_v).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_u1 : GOint64, p_u0 : GOint64, p_v : GOint64) : Go_runtime_divlu
{return new Go_runtime_divlu(gr,_bds, p_u1, p_u0, p_v);
}
public function run():Go_runtime_divlu {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1798,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(1798,1);
this.setPH(1802);
_res= {r0:GOint64.make(0xffffffff,0xffffffff),r1:GOint64.make(0xffffffff,0xffffffff)};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 18446744073709551615:uint64, 18446744073709551615:uint64 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:443:3

case 2: // if.done
this.setLatest(1802,2);
this.SubFn1();
_Phi=2;
case 3: // for.body
this.setLatest(1802,3);
this.SubFn2();
_Phi=3;
case 4: // for.done
this.setLatest(1802,4);
this.SubFn3();
_Phi=4;
case 5: // for.loop
this.setLatest(1802,5);
this.setPH(1798);
_t15=((_Phi==2)?p_v:(_Phi==3)?_t2:GOint64.make(0,0)); // _t15 = phi [2.if.done: v, 3.for.body: t2] #v *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:439:20
this.setPH(1806);
_t16=((_Phi==2)?0:(_Phi==3)?_t1:0); // _t16 = phi [2.if.done: 0:uint, 3.for.body: t1] #s *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:447:2
this.SubFn4();
_Phi=5;
case 6: // again1
this.setLatest(1806,6);
this.setPH(1818);
_t19=((_Phi==4)?_t12:(_Phi==7)?_t22:GOint64.make(0,0)); // _t19 = phi [4.for.done: t12, 7.if.then: t22] #q1 *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:459:2
this.setPH(1819);
_t20=((_Phi==4)?_t14:(_Phi==7)?_t23:GOint64.make(0,0)); // _t20 = phi [4.for.done: t14, 7.if.then: t23] #rhat *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:460:2
this.SubFn5();
_Phi=6;
case 7: // if.then
this.setLatest(1819,7);
this.SubFn6();
_Phi=7;
case 8: // if.done
this.setLatest(1819,8);
this.setPH(1818);
_t25=((_Phi==9)?_t19:(_Phi==7)?_t22:GOint64.make(0,0)); // _t25 = phi [9.cond.false: t19, 7.if.then: t22] #q1 *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:459:2
this.SubFn7();
_Phi=8;
case 9: // cond.false
this.setLatest(1818,9);
this.SubFn8();
_Phi=9;
case 10: // again2
this.setLatest(1818,10);
this.setPH(1819);
_t37=((_Phi==8)?_t32:(_Phi==11)?_t41:GOint64.make(0,0)); // _t37 = phi [8.if.done: t32, 11.if.then: t41] #rhat *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:460:2
this.setPH(1831);
_t38=((_Phi==8)?_t30:(_Phi==11)?_t40:GOint64.make(0,0)); // _t38 = phi [8.if.done: t30, 11.if.then: t40] #q0 *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:472:2
this.SubFn9();
_Phi=10;
case 11: // if.then
this.setLatest(1831,11);
this.SubFn10();
_Phi=11;
case 12: // if.done
this.setLatest(1831,12);
_t43=((_Phi==13)?_t38:(_Phi==11)?_t40:GOint64.make(0,0)); // _t43 = phi [13.cond.false: t38, 11.if.then: t40] #q0 *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:472:2
this.SubFn11();
this.setPH(1843);
_res= {r0:_t45,r1:_t50};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t45, t50 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:484:2

case 13: // cond.false
this.setLatest(1843,13);
this.SubFn12();
_Phi=13;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(1801);
_t0=(GOint64.ucompare(p_u1,p_v)>=0); // _t0 = u1 >= v *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:442:8
_Next=_t0 ? 1 : 2; // if t0 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:442:8
}// end SubFn0
private inline  function SubFn1():Void {
_Next=5; // jump 5.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:442:8
}// end SubFn1
private inline  function SubFn2():Void {
_t1=(_t16+1); // _t1 = t16 + 1:uint *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:442:8
_t2=Force.toUint64(GOint64.shl(_t15,GOint64.toInt(GOint64.make(0x0,0x1)))); // _t2 = t15 << 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:442:8
_Next=5; // jump 5.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:442:8
}// end SubFn2
private inline  function SubFn3():Void {
var _t5:GOint64;
var _t6:Int;
var _t7:GOint64;
var _t13:GOint64;
this.setPH(1812);
_t3=Force.toUint64(GOint64.ushr(_t15,GOint64.toInt(GOint64.make(0x0,0x20)))); // _t3 = t15 >> 32:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:453:11
this.setPH(1813);
_t4=Force.toUint64(GOint64.and(_t15,GOint64.make(0x0,0xffffffff))); // _t4 = t15 & 4294967295:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:454:11
this.setPH(1814);
_t5=Force.toUint64(GOint64.shl(p_u1,_t16)); // _t5 = u1 << t16 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:455:12
_t6=(64-_t16); // _t6 = 64:uint - t16 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:455:25
_t7=Force.toUint64(GOint64.ushr(p_u0,_t6)); // _t7 = u0 >> t6 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:455:20
_t8=Force.toUint64(GOint64.or(_t5,_t7)); // _t8 = t5 | t7 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:455:16
this.setPH(1815);
_t9=Force.toUint64(GOint64.shl(p_u0,_t16)); // _t9 = u0 << t16 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:456:13
this.setPH(1816);
_t10=Force.toUint64(GOint64.ushr(_t9,GOint64.toInt(GOint64.make(0x0,0x20)))); // _t10 = t9 >> 32:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:457:14
this.setPH(1817);
_t11=Force.toUint64(GOint64.and(_t9,GOint64.make(0x0,0xffffffff))); // _t11 = t9 & 4294967295:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:458:14
this.setPH(1818);
_t12=Force.toUint64(GOint64.div(_t8,_t3,false)); // _t12 = t8 / t3 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:459:13
this.setPH(1819);
_t13=Force.toUint64(GOint64.mul(_t12,_t3)); // _t13 = t12 * t3 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:460:19
_t14=Force.toUint64(GOint64.sub(_t8,_t13)); // _t14 = t8 - t13 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:460:15
_Next=6; // jump 6.again1 *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:460:15
}// end SubFn3
private inline  function SubFn4():Void {
var _t17:GOint64;
var _t18:Bool;
this.setPH(1807);
_t17=Force.toUint64(GOint64.and(_t15,GOint64.make(0x80000000,0x0))); // _t17 = t15 & 9223372036854775808:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:448:7
_t18=(GOint64.ucompare(_t17,GOint64.make(0x0,0x0))==0); // _t18 = t17 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:448:16
_Next=_t18 ? 3 : 4; // if t18 goto 3.for.body else 4.for.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:448:16
}// end SubFn4
private inline  function SubFn5():Void {
var _t21:Bool;
this.setPH(1822);
_t21=(GOint64.ucompare(_t19,GOint64.make(0x1,0x0))>=0); // _t21 = t19 >= 4294967296:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:463:8
_Next=_t21 ? 7 : 9; // if t21 goto 7.if.then else 9.cond.false *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:463:8
}// end SubFn5
private inline  function SubFn6():Void {
var _t24:Bool;
_t22=Force.toUint64(GOint64.sub(_t19,GOint64.make(0x0,0x1))); // _t22 = t19 - 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:463:8
_t23=Force.toUint64(GOint64.add(_t20,_t3)); // _t23 = t20 + t3 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:463:8
this.setPH(1825);
_t24=(GOint64.ucompare(_t23,GOint64.make(0x1,0x0))<0); // _t24 = t23 < 4294967296:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:466:11
_Next=_t24 ? 6 : 8; // if t24 goto 6.again1 else 8.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:466:11
}// end SubFn6
private inline  function SubFn7():Void {
var _t26:GOint64;
var _t27:GOint64;
var _t28:GOint64;
var _t31:GOint64;
this.setPH(1830);
_t26=Force.toUint64(GOint64.mul(_t8,GOint64.make(0x1,0x0))); // _t26 = t8 * 4294967296:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:471:14
_t27=Force.toUint64(GOint64.add(_t26,_t10)); // _t27 = t26 + t10 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:471:17
_t28=Force.toUint64(GOint64.mul(_t25,_t15)); // _t28 = t25 * t15 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:471:27
_t29=Force.toUint64(GOint64.sub(_t27,_t28)); // _t29 = t27 - t28 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:471:23
this.setPH(1831);
_t30=Force.toUint64(GOint64.div(_t29,_t3,false)); // _t30 = t29 / t3 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:472:13
this.setPH(1832);
_t31=Force.toUint64(GOint64.mul(_t30,_t3)); // _t31 = t30 * t3 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:473:18
_t32=Force.toUint64(GOint64.sub(_t29,_t31)); // _t32 = t29 - t31 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:473:14
_Next=10; // jump 10.again2 *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:473:14
}// end SubFn7
private inline  function SubFn8():Void {
var _t33:GOint64;
var _t34:GOint64;
var _t35:GOint64;
var _t36:Bool;
this.setPH(1822);
_t33=Force.toUint64(GOint64.mul(_t19,_t4)); // _t33 = t19 * t4 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:463:18
_t34=Force.toUint64(GOint64.mul(GOint64.make(0x1,0x0),_t20)); // _t34 = 4294967296:uint64 * t20 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:463:26
_t35=Force.toUint64(GOint64.add(_t34,_t10)); // _t35 = t34 + t10 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:463:31
_t36=(GOint64.ucompare(_t33,_t35)>0); // _t36 = t33 > t35 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:463:23
_Next=_t36 ? 7 : 8; // if t36 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:463:23
}// end SubFn8
private inline  function SubFn9():Void {
var _t39:Bool;
this.setPH(1835);
_t39=(GOint64.ucompare(_t38,GOint64.make(0x1,0x0))>=0); // _t39 = t38 >= 4294967296:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:476:8
_Next=_t39 ? 11 : 13; // if t39 goto 11.if.then else 13.cond.false *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:476:8
}// end SubFn9
private inline  function SubFn10():Void {
var _t42:Bool;
_t40=Force.toUint64(GOint64.sub(_t38,GOint64.make(0x0,0x1))); // _t40 = t38 - 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:476:8
_t41=Force.toUint64(GOint64.add(_t37,_t3)); // _t41 = t37 + t3 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:476:8
this.setPH(1838);
_t42=(GOint64.ucompare(_t41,GOint64.make(0x1,0x0))<0); // _t42 = t41 < 4294967296:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:479:11
_Next=_t42 ? 10 : 12; // if t42 goto 10.again2 else 12.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:479:11
}// end SubFn10
private inline  function SubFn11():Void {
var _t44:GOint64;
var _t46:GOint64;
var _t47:GOint64;
var _t48:GOint64;
var _t49:GOint64;
this.setPH(1843);
_t44=Force.toUint64(GOint64.mul(_t25,GOint64.make(0x1,0x0))); // _t44 = t25 * 4294967296:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:484:11
_t45=Force.toUint64(GOint64.add(_t44,_t43)); // _t45 = t44 + t43 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:484:14
_t46=Force.toUint64(GOint64.mul(_t29,GOint64.make(0x1,0x0))); // _t46 = t29 * 4294967296:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:484:25
_t47=Force.toUint64(GOint64.add(_t46,_t11)); // _t47 = t46 + t11 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:484:28
_t48=Force.toUint64(GOint64.mul(_t43,_t15)); // _t48 = t43 * t15 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:484:38
_t49=Force.toUint64(GOint64.sub(_t47,_t48)); // _t49 = t47 - t48 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:484:34
_t50=Force.toUint64(GOint64.ushr(_t49,_t16)); // _t50 = t49 >> t16 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:484:42
}// end SubFn11
private inline  function SubFn12():Void {
var _t51:GOint64;
var _t52:GOint64;
var _t53:GOint64;
var _t54:Bool;
this.setPH(1835);
_t51=Force.toUint64(GOint64.mul(_t38,_t4)); // _t51 = t38 * t4 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:476:18
_t52=Force.toUint64(GOint64.mul(GOint64.make(0x1,0x0),_t37)); // _t52 = 4294967296:uint64 * t37 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:476:26
_t53=Force.toUint64(GOint64.add(_t52,_t11)); // _t53 = t52 + t11 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:476:31
_t54=(GOint64.ucompare(_t51,_t53)>0); // _t54 = t51 > t53 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:476:23
_Next=_t54 ? 11 : 12; // if t54 goto 11.if.then else 12.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:476:23
}// end SubFn12
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
#if (!php) private #end class Go_runtime_newErrorCString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:89:6
var p_s:Dynamic;
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Dynamic, p_ret : Pointer) {
super(gr,857,"Go_runtime_newErrorCString");
this._bds=_bds;
this.p_s=p_s;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Dynamic=null;
var _t1:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : Dynamic, p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_newErrorCString(0,[], p_s, p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_s : Dynamic, p_ret : Pointer) : Void {
var _sf=new Go_runtime_newErrorCString(_gr,[], p_s, p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : Dynamic, p_ret : Pointer) : Go_runtime_newErrorCString
{return new Go_runtime_newErrorCString(gr,_bds, p_s, p_ret);
}
public function run():Go_runtime_newErrorCString {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(857,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near stateful.go:105:13

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Dynamic;
var _t1:Interface;
this.setPH(858);
_t0=p_s; // _t0 = changetype errorCString <- uintptr (s) *ssa.ChangeType @ /usr/local/go/src/pkg/runtime/error.go:90:21
_t1=new Interface(8,_t0); // _t1 = make interface{} <- errorCString (t0) *ssa.MakeInterface near /usr/local/go/src/pkg/runtime/error.go:90:21
p_ret.store(_t1); // *ret = t1 *ssa.Store @ /usr/local/go/src/pkg/runtime/error.go:90:2
}// end SubFn0
}
#if js @:expose("Go__star_runtime_dot_errorCString_Error") #end class Go__star_runtime_dot_errorCString_Error extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:84:23
var p_recv:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_recv : Pointer) {
super(gr,852,"Go__star_runtime_dot_errorCString_Error");
this._bds=_bds;
this.p_recv=p_recv;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _t0:Dynamic=null;
var _SF1:StackFrame;
var _t1:String="";
var _Next:Int=0;
public static inline function callFromHaxe( p_recv : Pointer) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_errorCString_Error(0,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_recv : Pointer) : String {
var _sf=new Go__star_runtime_dot_errorCString_Error(_gr,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_recv : Pointer) : Go__star_runtime_dot_errorCString_Error
{return new Go__star_runtime_dot_errorCString_Error(gr,_bds, p_recv);
}
public function run():Go__star_runtime_dot_errorCString_Error {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(852,0);
this.SubFn0();
_SF1=Go_runtime_dot_errorCString_Error.call(this._goroutine,[],_t0);
_Next = -1;
return this;
case -1:
this.setLatest(852,-1);
_t1=_SF1.res();
 // _t1 = (runtime.errorCString).Error(t0) *ssa.Call near /usr/local/go/src/pkg/runtime/error.go:90:2
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return near /usr/local/go/src/pkg/runtime/error.go:90:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=p_recv.load(); // _t0 = *recv *ssa.UnOp near /usr/local/go/src/pkg/runtime/error.go:90:2
}// end SubFn0
}
#if js @:expose("Go_atomic_AddInt64") #end class Go_atomic_AddInt64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:118:6
var p_addr:Pointer;
var p_delta:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : GOint64) {
super(gr,704,"Go_atomic_AddInt64");
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
this.setLatest(704,0);
this.SubFn0();
this.setPH(706);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:120:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:GOint64;
var _t1:GOint64;
this.setPH(705);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:119:2
_t1=Force.toInt64(GOint64.add(_t0,p_delta)); // _t1 = t0 + delta *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:119:2
p_addr.store(_t1); // *addr = t1 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:119:2
this.setPH(706);
_t2=p_addr.load(); // _t2 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:120:9
}// end SubFn0
}
#if js @:expose("Go_runtime_dot_errorCString_Error") #end class Go_runtime_dot_errorCString_Error extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:84:23
var p_e:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_e : Dynamic) {
super(gr,852,"Go_runtime_dot_errorCString_Error");
this._bds=_bds;
this.p_e=p_e;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _t0:Dynamic=null;
var _SF1:StackFrame;
var _t1:String="";
var _t2:String="";
var _Next:Int=0;
public static inline function callFromHaxe( p_e : Dynamic) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_dot_errorCString_Error(0,[], p_e).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_e : Dynamic) : String {
var _sf=new Go_runtime_dot_errorCString_Error(_gr,[], p_e).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_e : Dynamic) : Go_runtime_dot_errorCString_Error
{return new Go_runtime_dot_errorCString_Error(gr,_bds, p_e);
}
public function run():Go_runtime_dot_errorCString_Error {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(852,0);
this.SubFn0();
this.setPH(853);
_SF1=Go_runtime_cstringToGo.call(this._goroutine,[],_t0);
_Next = -1;
return this;
case -1:
this.setLatest(853,-1);
_t1=_SF1.res();
 // _t1 = cstringToGo(t0) *ssa.Call @ /usr/local/go/src/pkg/runtime/error.go:85:40
this.SubFn1();
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /usr/local/go/src/pkg/runtime/error.go:85:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=p_e; // _t0 = changetype uintptr <- runtime.errorCString (e) *ssa.ChangeType @ /usr/local/go/src/pkg/runtime/error.go:85:48
}// end SubFn0
private inline  function SubFn1():Void {
_t2=("runtime error: "+_t1); // _t2 = "runtime error: ":string + t1 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:85:27
}// end SubFn1
}
#if js @:expose("Go__star_runtime_dot_StackRecord_Stack") #end class Go__star_runtime_dot_StackRecord_Stack extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/debug.go:99:23
var p_r:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Pointer) {
super(gr,1179,"Go__star_runtime_dot_StackRecord_Stack");
this._bds=_bds;
this.p_r=p_r;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _t0:Pointer=null;
var _t1:Array<Dynamic>=null;
var _t2:Int=0;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Dynamic=null;
var _t6:Bool=false;
var _t7:Pointer=null;
var _t8:Slice=null;
var _t9:Pointer=null;
var _t10:Slice=null;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_r : Pointer) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_StackRecord_Stack(0,[], p_r).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_r : Pointer) : Slice {
var _sf=new Go__star_runtime_dot_StackRecord_Stack(_gr,[], p_r).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_r : Pointer) : Go__star_runtime_dot_StackRecord_Stack
{return new Go__star_runtime_dot_StackRecord_Stack(gr,_bds, p_r);
}
public function run():Go__star_runtime_dot_StackRecord_Stack {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1179,0);
this.SubFn0();
_Phi=0;
case 1: // rangeindex.loop
this.setLatest(1179,1);
_t2=((_Phi==0)?(-1):(_Phi==2)?_t3:0); // _t2 = phi [0.entry: -1:int, 2.rangeindex.body: t3] *ssa.Phi near /usr/local/go/src/pkg/runtime/error.go:85:27
this.SubFn1();
_Phi=1;
case 2: // rangeindex.body
this.setLatest(1179,2);
this.SubFn2();
_Phi=2;
case 3: // rangeindex.done
this.setLatest(1179,3);
this.SubFn3();
this.setPH(1185);
_res= _t8;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t8 *ssa.Return @ /usr/local/go/src/pkg/runtime/debug.go:105:2

case 4: // if.then
this.setLatest(1185,4);
this.SubFn4();
this.setPH(1182);
_res= _t10;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t10 *ssa.Return @ /usr/local/go/src/pkg/runtime/debug.go:102:4

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Pointer;
this.setPH(1180);
_t0=p_r.addr(0);  // _t0 = &r.Stack0 [#0] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/debug.go:100:22 [POINTER]
_t1=_t0.load(); // _t1 = *t0 *ssa.UnOp near /usr/local/go/src/pkg/runtime/debug.go:100:22
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/debug.go:100:22
}// end SubFn0
private inline  function SubFn1():Void {
var _t4:Bool;
_t3=(_t2+1); // _t3 = t2 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/debug.go:100:22
_t4=(_t3<32); // _t4 = t3 < 32:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/debug.go:100:22
_Next=_t4 ? 2 : 3; // if t4 goto 2.rangeindex.body else 3.rangeindex.done *ssa.If near /usr/local/go/src/pkg/runtime/debug.go:100:22
}// end SubFn1
private inline  function SubFn2():Void {
var _t6:Bool;
if((_t3<0)||(_t3>=32)) Scheduler.ioor();
_t5=_t1[_t3]; // _t5 = t1[t3] *ssa.Index near /usr/local/go/src/pkg/runtime/debug.go:100:22
this.setPH(1181);
_t6=(Force.uintCompare((_t5|0),(0|0))==0); // _t6 = t5 == 0:uintptr *ssa.BinOp @ /usr/local/go/src/pkg/runtime/debug.go:101:8
_Next=_t6 ? 4 : 1; // if t6 goto 4.if.then else 1.rangeindex.loop *ssa.If near /usr/local/go/src/pkg/runtime/debug.go:101:8
}// end SubFn2
private inline  function SubFn3():Void {
var _t7:Pointer;
this.setPH(1185);
_t7=p_r.addr(0);  // _t7 = &r.Stack0 [#0] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/debug.go:105:11 [POINTER]
_t8=new Slice(_t7,0,-1); // _t8 = slice t7[0:int:] *ssa.Slice @ /usr/local/go/src/pkg/runtime/debug.go:105:17
}// end SubFn3
private inline  function SubFn4():Void {
var _t9:Pointer;
this.setPH(1182);
_t9=p_r.addr(0);  // _t9 = &r.Stack0 [#0] *ssa.FieldAddr @ /usr/local/go/src/pkg/runtime/debug.go:102:13 [POINTER]
_t10=new Slice(_t9,0,_t3); // _t10 = slice t9[0:int:t3] *ssa.Slice @ /usr/local/go/src/pkg/runtime/debug.go:102:19
}// end SubFn4
}
#if (!php) private #end class Go_haxegoruntime_init_36_1 extends StackFrameBasis implements StackFrame {  // langgoruntime.go:14:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,2837,"Go_haxegoruntime_init_36_1");
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
this.setLatest(2837,0);
this.SubFn0();
this.setPH(2839);
Go_haxegoruntime_UTF16toRunes.call(this._goroutine,[],null);
_Next = -1;
return this;
case -1:
this.setLatest(2839,-1);
 // _t1 = UTF16toRunes(nil:[]uint16) *ssa.Call @ langgoruntime.go:16:18 [REGISTER VALUE UN-USED]
this.setPH(2840);
Go_haxegoruntime_UTF8toRunes.call(this._goroutine,[],null);
_Next = -2;
return this;
case -2:
this.setLatest(2840,-2);
 // _t2 = UTF8toRunes(nil:[]byte) *ssa.Call @ langgoruntime.go:17:17 [REGISTER VALUE UN-USED]
this.setPH(2841);
Go_haxegoruntime_Raw2Runes.call(this._goroutine,[],null);
_Next = -3;
return this;
case -3:
this.setLatest(2841,-3);
 // _t3 = Raw2Runes(nil:[]int) *ssa.Call @ langgoruntime.go:18:15 [REGISTER VALUE UN-USED]
this.setPH(2842);
Go_haxegoruntime_RunesToUTF16.call(this._goroutine,[],null);
_Next = -4;
return this;
case -4:
this.setLatest(2842,-4);
 // _t4 = RunesToUTF16(nil:[]rune) *ssa.Call @ langgoruntime.go:19:18 [REGISTER VALUE UN-USED]
this.setPH(2843);
Go_haxegoruntime_RunesToUTF8.call(this._goroutine,[],null);
_Next = -5;
return this;
case -5:
this.setLatest(2843,-5);
 // _t5 = RunesToUTF8(nil:[]rune) *ssa.Call @ langgoruntime.go:20:17 [REGISTER VALUE UN-USED]
this.setPH(2844);
Go_haxegoruntime_Runes2Raw.call(this._goroutine,[],null);
_Next = -6;
return this;
case -6:
this.setLatest(2844,-6);
 // _t6 = Runes2Raw(nil:[]rune) *ssa.Call @ langgoruntime.go:21:15 [REGISTER VALUE UN-USED]
this.setPH(2845);
Go_haxegoruntime_Rune2Raw.call(this._goroutine,[],42);
_Next = -7;
return this;
case -7:
this.setLatest(2845,-7);
 // _t7 = Rune2Raw(42:rune) *ssa.Call @ langgoruntime.go:22:14 [REGISTER VALUE UN-USED]
this.setPH(2846);
Go_haxegoruntime_StringCompare.call(this._goroutine,[],"X","Y");
_Next = -8;
return this;
case -8:
this.setLatest(2846,-8);
 // _t8 = StringCompare("X":string, "Y":string) *ssa.Call @ langgoruntime.go:23:19 [REGISTER VALUE UN-USED]
this.setPH(2848);
Go_utf16_Decode.call(this._goroutine,[],null);
_Next = -9;
return this;
case -9:
this.setLatest(2848,-9);
 // _t9 = unicode/utf16.Decode(nil:[]uint16) *ssa.Call @ langgoruntime.go:25:18 [REGISTER VALUE UN-USED]
this.setPH(2849);
Go_utf8_RuneCount.call(this._goroutine,[],null);
_Next = -10;
return this;
case -10:
this.setLatest(2849,-10);
 // _t10 = unicode/utf8.RuneCount(nil:[]byte) *ssa.Call @ langgoruntime.go:26:20 [REGISTER VALUE UN-USED]
this.setPH(2850);
_SF11=Go_utf8_DecodeRune.call(this._goroutine,[],null);
_Next = -11;
return this;
case -11:
this.setLatest(2850,-11);
_t11=_SF11.res();
 // _t11 = unicode/utf8.DecodeRune(nil:[]byte) *ssa.Call @ langgoruntime.go:27:23
this.SubFn1();
this.setPH(2851);
Go_utf16_Encode.call(this._goroutine,[],null);
_Next = -12;
return this;
case -12:
this.setLatest(2851,-12);
 // _t14 = unicode/utf16.Encode(nil:[]rune) *ssa.Call @ langgoruntime.go:28:18 [REGISTER VALUE UN-USED]
this.setPH(2852);
Go_utf8_RuneLen.call(this._goroutine,[],42);
_Next = -13;
return this;
case -13:
this.setLatest(2852,-13);
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
#if js @:expose("Go_runtime_dot_errorString_Error") #end class Go_runtime_dot_errorString_Error extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:68:22
var p_e:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_e : String) {
super(gr,836,"Go_runtime_dot_errorString_Error");
this._bds=_bds;
this.p_e=p_e;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _t0:String="";
var _t1:String="";
var _Next:Int=0;
public static inline function callFromHaxe( p_e : String) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_dot_errorString_Error(0,[], p_e).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_e : String) : String {
var _sf=new Go_runtime_dot_errorString_Error(_gr,[], p_e).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_e : String) : Go_runtime_dot_errorString_Error
{return new Go_runtime_dot_errorString_Error(gr,_bds, p_e);
}
public function run():Go_runtime_dot_errorString_Error {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(836,0);
this.SubFn0();
this.setPH(837);
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /usr/local/go/src/pkg/runtime/error.go:69:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:String;
_t0=p_e; // _t0 = changetype string <- runtime.errorString (e) *ssa.ChangeType @ /usr/local/go/src/pkg/runtime/error.go:69:35
_t1=("runtime error: "+_t0); // _t1 = "runtime error: ":string + t0 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/error.go:69:27
}// end SubFn0
}
#if js @:expose("Go_atomic_StoreInt32") #end class Go_atomic_StoreInt32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:154:6
var p_addr:Pointer;
var p_val:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : Int) {
super(gr,740,"Go_atomic_StoreInt32");
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
this.setLatest(740,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/error.go:69:27

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:154:43
}// end SubFn0
}
#if js @:expose("Go_atomic_CompareAndSwapInt32") #end class Go_atomic_CompareAndSwapInt32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:52:6
var p_addr:Pointer;
var p_old:Int;
var p_new:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : Int, p_new : Int) {
super(gr,638,"Go_atomic_CompareAndSwapInt32");
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
this.setLatest(638,0);
this.SubFn0();

case 1: // if.then
this.setLatest(638,1);
this.SubFn1();
this.setPH(641);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:55:3

case 2: // if.done
this.setLatest(641,2);
this.setPH(643);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:57:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
var _t1:Bool;
this.setPH(639);
_t0=(p_addr.load()|0); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:53:5
_t1=(_t0==p_old); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:53:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:53:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(640);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:54:3
}// end SubFn1
}
#if js @:expose("Go_runtime_dot_errorString_RuntimeError") #end class Go_runtime_dot_errorString_RuntimeError extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:66:22
var p_e:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_e : String) {
super(gr,834,"Go_runtime_dot_errorString_RuntimeError");
this._bds=_bds;
this.p_e=p_e;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( p_e : String) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_dot_errorString_RuntimeError(0,[], p_e).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_e : String) : Void {
var _sf=new Go_runtime_dot_errorString_RuntimeError(_gr,[], p_e).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_e : String) : Go_runtime_dot_errorString_RuntimeError
{return new Go_runtime_dot_errorString_RuntimeError(gr,_bds, p_e);
}
public function run():Go_runtime_dot_errorString_RuntimeError {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(834,0);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:54:3

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_atomic_StoreUint32") #end class Go_atomic_StoreUint32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:6
var p_addr:Pointer;
var p_val:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : Int) {
super(gr,746,"Go_atomic_StoreUint32");
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
this.setLatest(746,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:54:3

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:160:46
}// end SubFn0
}
#if js @:expose("Go_atomic_AddUint64") #end class Go_atomic_AddUint64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:124:6
var p_addr:Pointer;
var p_delta:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : GOint64) {
super(gr,710,"Go_atomic_AddUint64");
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
this.setLatest(710,0);
this.SubFn0();
this.setPH(712);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:126:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:GOint64;
var _t1:GOint64;
this.setPH(711);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:125:2
_t1=Force.toUint64(GOint64.add(_t0,p_delta)); // _t1 = t0 + delta *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:125:2
p_addr.store(_t1); // *addr = t1 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:125:2
this.setPH(712);
_t2=p_addr.load(); // _t2 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:126:9
}// end SubFn0
}
#if js @:expose("Go_runtime_dot_errorCString_RuntimeError") #end class Go_runtime_dot_errorCString_RuntimeError extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:80:23
var p_e:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_e : Dynamic) {
super(gr,848,"Go_runtime_dot_errorCString_RuntimeError");
this._bds=_bds;
this.p_e=p_e;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _Next:Int=0;
public static inline function callFromHaxe( p_e : Dynamic) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_dot_errorCString_RuntimeError(0,[], p_e).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_e : Dynamic) : Void {
var _sf=new Go_runtime_dot_errorCString_RuntimeError(_gr,[], p_e).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_e : Dynamic) : Go_runtime_dot_errorCString_RuntimeError
{return new Go_runtime_dot_errorCString_RuntimeError(gr,_bds, p_e);
}
public function run():Go_runtime_dot_errorCString_RuntimeError {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(848,0);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:126:9

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_atomic_StoreInt64") #end class Go_atomic_StoreInt64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:157:6
var p_addr:Pointer;
var p_val:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_val : GOint64) {
super(gr,743,"Go_atomic_StoreInt64");
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
this.setLatest(743,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:126:9

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_addr.store(p_val); // *addr = val *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:157:43
}// end SubFn0
}
#if js @:expose("Go_utf8_RuneLen") #end class Go_utf8_RuneLen extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:310:6
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_r : Int) {
super(gr,3382,"Go_utf8_RuneLen");
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
this.setLatest(3382,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(3382,1);
this.setPH(3385);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:313:3

case 2: // switch.body
this.setLatest(3385,2);
this.setPH(3387);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:315:3

case 3: // switch.next
this.setLatest(3387,3);
this.SubFn1();
_Phi=3;
case 4: // switch.body
this.setLatest(3387,4);
this.setPH(3389);
_res= 2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 2:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:317:3

case 5: // switch.next
this.setLatest(3389,5);
this.SubFn2();
_Phi=5;
case 6: // switch.body
this.setLatest(3389,6);
this.setPH(3391);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:319:3

case 7: // switch.next
this.setLatest(3391,7);
this.SubFn3();
_Phi=7;
case 8: // switch.body
this.setLatest(3391,8);
this.setPH(3393);
_res= 3;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 3:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:321:3

case 9: // switch.next
this.setLatest(3393,9);
this.SubFn4();
_Phi=9;
case 10: // binop.rhs
this.setLatest(3393,10);
this.SubFn5();
_Phi=10;
case 11: // binop.done
this.setLatest(3393,11);
this.setPH(3390);
_t6=((_Phi==7)?false:(_Phi==10)?_t5:false); // _t6 = phi [7.switch.next: false:bool, 10.binop.rhs: t5] #&& *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:25
this.SubFn6();
_Phi=11;
case 12: // switch.body
this.setLatest(3390,12);
this.setPH(3395);
_res= 4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 4:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:323:3

case 13: // switch.next
this.setLatest(3395,13);
this.SubFn7();
_Phi=13;
case 14: // switch.next
this.setLatest(3395,14);
this.setPH(3397);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:325:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(3384);
_t0=(p_r<0); // _t0 = r < 0:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:312:9
_Next=_t0 ? 1 : 3; // if t0 goto 1.switch.body else 3.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:312:9
}// end SubFn0
private inline  function SubFn1():Void {
var _t1:Bool;
this.setPH(3386);
_t1=(p_r<=127); // _t1 = r <= 127:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:314:9
_Next=_t1 ? 2 : 5; // if t1 goto 2.switch.body else 5.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:314:9
}// end SubFn1
private inline  function SubFn2():Void {
var _t2:Bool;
this.setPH(3388);
_t2=(p_r<=2047); // _t2 = r <= 2047:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:316:9
_Next=_t2 ? 4 : 7; // if t2 goto 4.switch.body else 7.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:316:9
}// end SubFn2
private inline  function SubFn3():Void {
var _t3:Bool;
this.setPH(3390);
_t3=(55296<=p_r); // _t3 = 55296:rune <= r *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:20
_Next=_t3 ? 10 : 11; // if t3 goto 10.binop.rhs else 11.binop.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:20
}// end SubFn3
private inline  function SubFn4():Void {
var _t4:Bool;
this.setPH(3392);
_t4=(p_r<=65535); // _t4 = r <= 65535:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:320:9
_Next=_t4 ? 8 : 13; // if t4 goto 8.switch.body else 13.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:320:9
}// end SubFn4
private inline  function SubFn5():Void {
this.setPH(3390);
_t5=(p_r<=57343); // _t5 = r <= 57343:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:30
_Next=11; // jump 11.binop.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:30
}// end SubFn5
private inline  function SubFn6():Void {
_Next=_t6 ? 6 : 9; // if t6 goto 6.switch.body else 9.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:318:30
}// end SubFn6
private inline  function SubFn7():Void {
var _t7:Bool;
this.setPH(3394);
_t7=(p_r<=1114111); // _t7 = r <= 1114111:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:322:9
_Next=_t7 ? 12 : 14; // if t7 goto 12.switch.body else 14.switch.next *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:322:9
}// end SubFn7
}
#if (!php) private #end class Go_runtime_fsub64c extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:490:6
var p_f:GOint64;
var p_g:GOint64;
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64, p_ret : Pointer) {
super(gr,1849,"Go_runtime_fsub64c");
this._bds=_bds;
this.p_f=p_f;
this.p_g=p_g;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t0:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fsub64c(0,[], p_f, p_g, p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Void {
var _sf=new Go_runtime_fsub64c(_gr,[], p_f, p_g, p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Go_runtime_fsub64c
{return new Go_runtime_fsub64c(gr,_bds, p_f, p_g, p_ret);
}
public function run():Go_runtime_fsub64c {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1849,0);
_SF1=Go_runtime_fsub64.call(this._goroutine,[],p_f,p_g);
_Next = -1;
return this;
case -1:
this.setLatest(1849,-1);
_t0=_SF1.res();
 // _t0 = fsub64(f, g) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:490:66
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:490:66

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_ret.store(_t0); // *ret = t0 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:490:53
}// end SubFn0
}
#if js @:expose("Go_utf8_RuneStart") #end class Go_utf8_RuneStart extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:392:6
var p_b:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_b : Int) {
super(gr,3464,"Go_utf8_RuneStart");
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
this.setLatest(3464,0);
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
#if js @:expose("Go_tardisgolib_StringsUTF8") #end class Go_tardisgolib_StringsUTF8 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:29:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,492,"Go_tardisgolib_StringsUTF8");
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
this.setLatest(492,0);
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
#if js @:expose("Go_haxegoruntime_Rune2Raw") #end class Go_haxegoruntime_Rune2Raw extends StackFrameBasis implements StackFrame {  // langgoruntime.go:113:6
var p_oneRune:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_oneRune : Int) {
super(gr,2936,"Go_haxegoruntime_Rune2Raw");
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
this.setLatest(2936,0);
this.SubFn0();
this.setPH(2939);
_SF1=Go_haxegoruntime_Runes2Raw.call(this._goroutine,[],_t0);
_Next = -1;
return this;
case -1:
this.setLatest(2939,-1);
_t2=_SF1.res();
 // _t2 = Runes2Raw(t0) *ssa.Call @ langgoruntime.go:116:18
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ langgoruntime.go:116:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Pointer;
this.setPH(2937);
_t0=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0...1) _v[_i]=0; _v;}),0,1); // _t0 = make []rune 1:int 1:int *ssa.MakeSlice @ langgoruntime.go:114:11
this.setPH(2938);
if((0<0)||(0>=_t0.len())) Scheduler.ioor(); // _t1 = &t0[0:int] *ssa.IndexAddr @ langgoruntime.go:115:3 [POINTER]
_t1=_t0.addr(0);  // _t1 = &t0[0:int] *ssa.IndexAddr @ langgoruntime.go:115:3 [POINTER]
_t1.store(p_oneRune); // *t1 = oneRune *ssa.Store near langgoruntime.go:115:3
}// end SubFn0
}
#if (!php) private #end class Go_runtime_fneg64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:254:6
var p_f:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64) {
super(gr,1613,"Go_runtime_fneg64");
this._bds=_bds;
this.p_f=p_f;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _t0:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fneg64(0,[], p_f).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : GOint64) : GOint64 {
var _sf=new Go_runtime_fneg64(_gr,[], p_f).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64) : Go_runtime_fneg64
{return new Go_runtime_fneg64(gr,_bds, p_f);
}
public function run():Go_runtime_fneg64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1613,0);
this.SubFn0();
this.setPH(1614);
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:255:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=Force.toUint64(GOint64.xor(p_f,GOint64.make(0x80000000,0x0))); // _t0 = f ^ 9223372036854775808:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:255:11
}// end SubFn0
}
#if (!php) private #end class Go_runtime_f32to64c extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:494:6
var p_f:Int;
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : Int, p_ret : Pointer) {
super(gr,1853,"Go_runtime_f32to64c");
this._bds=_bds;
this.p_f=p_f;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t0:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : Int, p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_f32to64c(0,[], p_f, p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_f : Int, p_ret : Pointer) : Void {
var _sf=new Go_runtime_f32to64c(_gr,[], p_f, p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : Int, p_ret : Pointer) : Go_runtime_f32to64c
{return new Go_runtime_f32to64c(gr,_bds, p_f, p_ret);
}
public function run():Go_runtime_f32to64c {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1853,0);
_SF1=Go_runtime_f32to64.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(1853,-1);
_t0=_SF1.res();
 // _t0 = f32to64(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:494:67
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:494:67

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_ret.store(_t0); // *ret = t0 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:494:53
}// end SubFn0
}
#if js @:expose("Go_utf8_DecodeLastRuneInString") #end class Go_utf8_DecodeLastRuneInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:276:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,3348,"Go_utf8_DecodeLastRuneInString");
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
this.setLatest(3348,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(3348,1);
this.setPH(3351);
_res= {r0:65533,r1:0};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 0:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:279:3

case 2: // if.done
this.setLatest(3351,2);
this.SubFn1();
_Phi=2;
case 3: // if.then
this.setLatest(3351,3);
this.setPH(3356);
_res= {r0:_t4,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:284:3

case 4: // if.done
this.setLatest(3356,4);
this.SubFn2();
_Phi=4;
case 5: // if.then
this.setLatest(3356,5);
this.SubFn3();
_Phi=5;
case 6: // if.done
this.setLatest(3356,6);
this.setPH(3361);
_t8=((_Phi==4)?_t6:(_Phi==5)?0:0); // _t8 = phi [4.if.done: t6, 5.if.then: 0:int] #lim *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:289:2
this.SubFn4();
_Phi=6;
case 7: // for.body
this.setLatest(3361,7);
this.SubFn5();
this.setPH(3366);
_SF1=Go_utf8_RuneStart.call(this._goroutine,[],_t10);
_Next = -1;
return this;
case -1:
this.setLatest(3366,-1);
_t11=_SF1.res();
 // _t11 = RuneStart(t10) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:294:15
this.SubFn6();
_Phi=7;
case 8: // for.done
this.setLatest(3366,8);
this.SubFn7();
_Phi=8;
case 9: // for.loop
this.setLatest(3366,9);
this.setPH(3353);
_t13=((_Phi==6)?_t9:(_Phi==10)?_t15:0); // _t13 = phi [6.if.done: t9, 10.if.done: t15] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:281:2
this.SubFn8();
_Phi=9;
case 10: // if.done
this.setLatest(3353,10);
this.SubFn9();
_Phi=10;
case 11: // if.then
this.setLatest(3353,11);
this.SubFn10();
_Phi=11;
case 12: // if.done
this.setLatest(3353,12);
_t16=((_Phi==8)?_t13:(_Phi==11)?0:0); // _t16 = phi [8.for.done: t13, 11.if.then: 0:int] #start *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:281:2
this.SubFn11();
this.setPH(3373);
_SF2=Go_utf8_DecodeRuneInString.call(this._goroutine,[],_t17);
_Next = -2;
return this;
case -2:
this.setLatest(3373,-2);
_t18=_SF2.res();
 // _t18 = DecodeRuneInString(t17) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:30
this.SubFn12();
_Phi=12;
case 13: // if.then
this.setLatest(3373,13);
this.setPH(3375);
_res= {r0:65533,r1:1};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 65533:rune, 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:303:3

case 14: // if.done
this.setLatest(3375,14);
this.setPH(3377);
_res= {r0:_t19,r1:_t20};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t19, t20 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:305:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t1:Bool;
this.setPH(3349);
_t0=Force.toUTF8length(this._goroutine,p_s); // _t0 = len(s) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:277:12
this.setPH(3350);
_t1=(_t0==0); // _t1 = t0 == 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:278:9
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:278:9
}// end SubFn0
private inline  function SubFn1():Void {
var _t3:Int;
var _t5:Bool;
this.setPH(3353);
_t2=(_t0-1); // _t2 = t0 - 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:281:15
this.setPH(3354);
_t3=Force.toUTF8slice(this._goroutine,p_s).getAt(_t2); // _t3 = s[t2] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:282:12
_t4=_t3; // _t4 = convert rune <- uint8 (t3) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:282:10
this.setPH(3355);
_t5=(_t4<128); // _t5 = t4 < 128:rune *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:283:7
_Next=_t5 ? 3 : 4; // if t5 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:283:7
}// end SubFn1
private inline  function SubFn2():Void {
var _t7:Bool;
this.setPH(3361);
_t6=(_t0-4); // _t6 = t0 - 4:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:289:13
this.setPH(3362);
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
this.setPH(3366);
_t10=Force.toUTF8slice(this._goroutine,p_s).getAt(_t13); // _t10 = s[t13] *ssa.Lookup @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:294:17
}// end SubFn5
private inline  function SubFn6():Void {
_Next=_t11 ? 8 : 10; // if t11 goto 8.for.done else 10.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:294:17
}// end SubFn6
private inline  function SubFn7():Void {
var _t12:Bool;
this.setPH(3370);
_t12=(_t13<0); // _t12 = t13 < 0:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:298:11
_Next=_t12 ? 11 : 12; // if t12 goto 11.if.then else 12.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:298:11
}// end SubFn7
private inline  function SubFn8():Void {
var _t14:Bool;
this.setPH(3365);
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
this.setPH(3373);
_t17=Force.toRawString(this._goroutine,Force.toUTF8slice(this._goroutine,p_s).subSlice(_t16,_t0)); // _t17 = slice s[t16:t0] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:32
}// end SubFn11
private inline  function SubFn12():Void {
var _t21:Int;
var _t22:Bool;
_t19=_t18.r0; // _t19 = extract t18 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:32
_t20=_t18.r1; // _t20 = extract t18 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:301:32
this.setPH(3374);
_t21=(_t16+_t20); // _t21 = t16 + t20 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:302:10
_t22=(_t21!=_t0); // _t22 = t21 != t0 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:302:16
_Next=_t22 ? 13 : 14; // if t22 goto 13.if.then else 14.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:302:16
}// end SubFn12
}
#if (!php) private #end class Go_runtime_fmul64c extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:491:6
var p_f:GOint64;
var p_g:GOint64;
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64, p_ret : Pointer) {
super(gr,1850,"Go_runtime_fmul64c");
this._bds=_bds;
this.p_f=p_f;
this.p_g=p_g;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t0:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fmul64c(0,[], p_f, p_g, p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Void {
var _sf=new Go_runtime_fmul64c(_gr,[], p_f, p_g, p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Go_runtime_fmul64c
{return new Go_runtime_fmul64c(gr,_bds, p_f, p_g, p_ret);
}
public function run():Go_runtime_fmul64c {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1850,0);
_SF1=Go_runtime_fmul64.call(this._goroutine,[],p_f,p_g);
_Next = -1;
return this;
case -1:
this.setLatest(1850,-1);
_t0=_SF1.res();
 // _t0 = fmul64(f, g) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:491:66
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:491:66

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_ret.store(_t0); // *ret = t0 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:491:53
}// end SubFn0
}
#if js @:expose("Go_utf8_RuneCountInString") #end class Go_utf8_RuneCountInString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,3454,"Go_utf8_RuneCountInString");
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
this.setLatest(3454,0);
this.SubFn0();
_Phi=0;
case 1: // rangeiter.loop
this.setLatest(3454,1);
_t1=((_Phi==0)?0:(_Phi==2)?_t4:0); // _t1 = phi [0.entry: 0:int, 2.rangeiter.body: t4] #n *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:382:35
this.SubFn1();
_Phi=1;
case 2: // rangeiter.body
this.setLatest(3454,2);
this.SubFn2();
_Phi=2;
case 3: // rangeiter.done
this.setLatest(3454,3);
this.setPH(3458);
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:386:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(3455);
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
#if (!php) private #end class Go_runtime_mullu extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:420:6
var p_u:GOint64;
var p_v:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_u : GOint64, p_v : GOint64) {
super(gr,1779,"Go_runtime_mullu");
this._bds=_bds;
this.p_u=p_u;
this.p_v=p_v;
Scheduler.push(gr,this);
}
var _res:{r0:GOint64, r1:GOint64};
public inline function res():Dynamic {return _res;}
var _t0:GOint64=null;
var _t1:GOint64=null;
var _t2:GOint64=null;
var _t3:GOint64=null;
var _t4:GOint64=null;
var _t5:GOint64=null;
var _t6:GOint64=null;
var _t7:GOint64=null;
var _t8:GOint64=null;
var _t9:GOint64=null;
var _t10:GOint64=null;
var _t11:GOint64=null;
var _t12:GOint64=null;
var _t13:GOint64=null;
var _t14:GOint64=null;
var _t15:GOint64=null;
var _t16:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_u : GOint64, p_v : GOint64) : {r0:GOint64, r1:GOint64} {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_mullu(0,[], p_u, p_v).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_u : GOint64, p_v : GOint64) : {r0:GOint64, r1:GOint64} {
var _sf=new Go_runtime_mullu(_gr,[], p_u, p_v).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_u : GOint64, p_v : GOint64) : Go_runtime_mullu
{return new Go_runtime_mullu(gr,_bds, p_u, p_v);
}
public function run():Go_runtime_mullu {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1779,0);
this.SubFn0();
this.setPH(1793);
_res= {r0:_t12,r1:_t16};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t12, t16 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:434:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t5:GOint64;
var _t6:GOint64;
var _t10:GOint64;
var _t13:GOint64;
var _t14:GOint64;
var _t15:GOint64;
this.setPH(1784);
_t0=Force.toUint64(GOint64.and(p_u,GOint64.make(0x0,0xffffffff))); // _t0 = u & 4294967295:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:425:10
this.setPH(1785);
_t1=Force.toUint64(GOint64.ushr(p_u,GOint64.toInt(GOint64.make(0x0,0x20)))); // _t1 = u >> 32:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:426:10
this.setPH(1786);
_t2=Force.toUint64(GOint64.and(p_v,GOint64.make(0x0,0xffffffff))); // _t2 = v & 4294967295:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:427:10
this.setPH(1787);
_t3=Force.toUint64(GOint64.ushr(p_v,GOint64.toInt(GOint64.make(0x0,0x20)))); // _t3 = v >> 32:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:428:10
this.setPH(1788);
_t4=Force.toUint64(GOint64.mul(_t0,_t2)); // _t4 = t0 * t2 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:429:11
this.setPH(1789);
_t5=Force.toUint64(GOint64.mul(_t1,_t2)); // _t5 = t1 * t2 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:430:9
_t6=Force.toUint64(GOint64.ushr(_t4,GOint64.toInt(GOint64.make(0x0,0x20)))); // _t6 = t4 >> 32:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:430:17
_t7=Force.toUint64(GOint64.add(_t5,_t6)); // _t7 = t5 + t6 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:430:13
this.setPH(1790);
_t8=Force.toUint64(GOint64.and(_t7,GOint64.make(0x0,0xffffffff))); // _t8 = t7 & 4294967295:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:431:10
this.setPH(1791);
_t9=Force.toUint64(GOint64.ushr(_t7,GOint64.toInt(GOint64.make(0x0,0x20)))); // _t9 = t7 >> 32:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:432:10
this.setPH(1792);
_t10=Force.toUint64(GOint64.mul(_t0,_t3)); // _t10 = t0 * t3 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:433:11
_t11=Force.toUint64(GOint64.add(_t8,_t10)); // _t11 = t8 + t10 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:433:11
this.setPH(1793);
_t12=Force.toUint64(GOint64.mul(p_u,p_v)); // _t12 = u * v *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:434:11
_t13=Force.toUint64(GOint64.mul(_t1,_t3)); // _t13 = t1 * t3 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:434:18
_t14=Force.toUint64(GOint64.add(_t13,_t9)); // _t14 = t13 + t9 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:434:22
_t15=Force.toUint64(GOint64.ushr(_t11,GOint64.toInt(GOint64.make(0x0,0x20)))); // _t15 = t11 >> 32:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:434:31
_t16=Force.toUint64(GOint64.add(_t14,_t15)); // _t16 = t14 + t15 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:434:27
}// end SubFn0
}
#if (!php) private #end class Go_runtime_fadd64c extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:489:6
var p_f:GOint64;
var p_g:GOint64;
var p_ret:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64, p_ret : Pointer) {
super(gr,1848,"Go_runtime_fadd64c");
this._bds=_bds;
this.p_f=p_f;
this.p_g=p_g;
this.p_ret=p_ret;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _t0:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fadd64c(0,[], p_f, p_g, p_ret).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Void {
var _sf=new Go_runtime_fadd64c(_gr,[], p_f, p_g, p_ret).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64, p_ret : Pointer) : Go_runtime_fadd64c
{return new Go_runtime_fadd64c(gr,_bds, p_f, p_g, p_ret);
}
public function run():Go_runtime_fadd64c {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1848,0);
_SF1=Go_runtime_fadd64.call(this._goroutine,[],p_f,p_g);
_Next = -1;
return this;
case -1:
this.setLatest(1848,-1);
_t0=_SF1.res();
 // _t0 = fadd64(f, g) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:489:66
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:489:66

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
p_ret.store(_t0); // *ret = t0 *ssa.Store @ /usr/local/go/src/pkg/runtime/softfloat64.go:489:53
}// end SubFn0
}
#if js @:expose("Go_atomic_AddInt32") #end class Go_atomic_AddInt32 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:106:6
var p_addr:Pointer;
var p_delta:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_delta : Int) {
super(gr,692,"Go_atomic_AddInt32");
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
this.setLatest(692,0);
this.SubFn0();
this.setPH(694);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:108:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
var _t1:Int;
this.setPH(693);
_t0=(p_addr.load()|0); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:107:2
_t1=Force.toInt32((_t0+p_delta)); // _t1 = t0 + delta *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:107:2
p_addr.store(_t1); // *addr = t1 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:107:2
this.setPH(694);
_t2=(p_addr.load()|0); // _t2 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:108:9
}// end SubFn0
}
#if js @:expose("Go_utf8_Valid") #end class Go_utf8_Valid extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:395:6
var p_p:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice) {
super(gr,3467,"Go_utf8_Valid");
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
this.setLatest(3467,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(3467,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(3467,2);
this.setPH(3483);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:411:2

case 3: // for.loop
this.setLatest(3483,3);
this.setPH(3468);
_t3=((_Phi==0)?0:(_Phi==4)?_t6:(_Phi==7)?_t12:0); // _t3 = phi [0.entry: 0:int, 4.if.then: t6, 7.if.done: t12] #i *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:396:2
this.SubFn2();
_Phi=3;
case 4: // if.then
this.setLatest(3468,4);
this.SubFn3();
_Phi=4;
case 5: // if.else
this.setLatest(3468,5);
this.SubFn4();
this.setPH(3473);
_SF1=Go_utf8_DecodeRune.call(this._goroutine,[],_t7);
_Next = -1;
return this;
case -1:
this.setLatest(3473,-1);
_t8=_SF1.res();
 // _t8 = DecodeRune(t7) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:25
this.SubFn5();
_Phi=5;
case 6: // if.then
this.setLatest(3473,6);
this.setPH(3478);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:406:5

case 7: // if.done
this.setLatest(3478,7);
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
this.setPH(3470);
if((_t3<0)||(_t3>=p_p.len())) Scheduler.ioor(); // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:7 [POINTER]
_t0=p_p.addr(_t3);  // _t0 = &p[t3] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:7 [POINTER]
_t1=(_t0.load()|0); // _t1 = *t0 *ssa.UnOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:7
_t2=(Force.uintCompare(_t1,128)<0); // _t2 = t1 < 128:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:11
_Next=_t2 ? 4 : 5; // if t2 goto 4.if.then else 5.if.else *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:398:11
}// end SubFn1
private inline  function SubFn2():Void {
var _t4:Int;
var _t5:Bool;
this.setPH(3469);
_t4=({var _v=p_p;_v==null?0:_v.len();}); // _t4 = len(p) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:13
_t5=(_t3<_t4); // _t5 = t3 < t4 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
_Next=_t5 ? 1 : 2; // if t5 goto 1.for.body else 2.for.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
}// end SubFn2
private inline  function SubFn3():Void {
_t6=(_t3+1); // _t6 = t3 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:397:8
}// end SubFn3
private inline  function SubFn4():Void {
this.setPH(3473);
_t7=p_p.subSlice(_t3,-1); // _t7 = slice p[t3:] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:27
}// end SubFn4
private inline  function SubFn5():Void {
var _t11:Bool;
 // _t9 = extract t8 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:27 [REGISTER VALUE UN-USED]
_t10=_t8.r1; // _t10 = extract t8 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:401:27
this.setPH(3474);
_t11=(_t10==1); // _t11 = t10 == 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
_Next=_t11 ? 6 : 7; // if t11 goto 6.if.then else 7.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
}// end SubFn5
private inline  function SubFn6():Void {
_t12=(_t3+_t10); // _t12 = t3 + t10 *ssa.BinOp near /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:402:12
}// end SubFn6
}
#if (!php) private #end class Go_runtime_fintto64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:409:6
var p_val:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_val : GOint64) {
super(gr,1768,"Go_runtime_fintto64");
this._bds=_bds;
this.p_val=p_val;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _t0:GOint64=null;
var _t1:GOint64=null;
var _t2:GOint64=null;
var _t3:Bool=false;
var _t4:GOint64=null;
var _t5:GOint64=null;
var _SF1:StackFrame;
var _t6:GOint64=null;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_val : GOint64) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fintto64(0,[], p_val).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_val : GOint64) : GOint64 {
var _sf=new Go_runtime_fintto64(_gr,[], p_val).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_val : GOint64) : Go_runtime_fintto64
{return new Go_runtime_fintto64(gr,_bds, p_val);
}
public function run():Go_runtime_fintto64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1768,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(1768,1);
this.SubFn1();
_Phi=1;
case 2: // if.done
this.setLatest(1768,2);
this.setPH(1770);
_t5=((_Phi==0)?_t2:(_Phi==1)?_t4:GOint64.make(0,0)); // _t5 = phi [0.entry: t2, 1.if.then: t4] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:411:2
this.setPH(1774);
_SF1=Go_runtime_fpack64.call(this._goroutine,[],_t1,_t5,52,GOint64.make(0x0,0x0));
_Next = -1;
return this;
case -1:
this.setLatest(1774,-1);
_t6=_SF1.res();
 // _t6 = fpack64(t1, t5, 52:int, 0:uint64) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:415:16
_res= _t6;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t6 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:415:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:GOint64;
var _t3:Bool;
this.setPH(1769);
_t0=p_val; // _t0 = convert uint64 <- int64 (val) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:410:14
_t1=Force.toUint64(GOint64.and(_t0,GOint64.make(0x80000000,0x0))); // _t1 = t0 & 9223372036854775808:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:410:20
this.setPH(1770);
_t2=p_val; // _t2 = convert uint64 <- int64 (val) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:411:16
this.setPH(1771);
_t3=(GOint64.ucompare(_t1,GOint64.make(0x0,0x0))!=0); // _t3 = t1 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:412:8
_Next=_t3 ? 1 : 2; // if t3 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:412:8
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(1772);
_t4=Force.toUint64(GOint64.neg(_t2)); // _t4 = -t2 *ssa.UnOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:413:10
_Next=2; // jump 2.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:413:10
}// end SubFn1
}
#if js @:expose("Go__star_runtime_dot_Func_Entry") #end class Go__star_runtime_dot_Func_Entry extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/extern.go:103:16
var p_f:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : Pointer) {
super(gr,994,"Go__star_runtime_dot_Func_Entry");
this._bds=_bds;
this.p_f=p_f;
Scheduler.push(gr,this);
}
var _res:Dynamic;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:Dynamic=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : Pointer) : Dynamic {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_Func_Entry(0,[], p_f).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : Pointer) : Dynamic {
var _sf=new Go__star_runtime_dot_Func_Entry(_gr,[], p_f).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : Pointer) : Go__star_runtime_dot_Func_Entry
{return new Go__star_runtime_dot_Func_Entry(gr,_bds, p_f);
}
public function run():Go__star_runtime_dot_Func_Entry {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(994,0);
this.setPH(995);
_SF1=Go_runtime_funcentry_go.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(995,-1);
_t0=_SF1.res();
 // _t0 = funcentry_go(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/extern.go:104:21
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ /usr/local/go/src/pkg/runtime/extern.go:104:2

default: Scheduler.bbi();}}}
}
#if js @:expose("Go__star_runtime_dot_BlockProfileRecord_Stack") #end class Go__star_runtime_dot_BlockProfileRecord_Stack extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/debug.go:99:23
var p_recv:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_recv : Pointer) {
super(gr,1179,"Go__star_runtime_dot_BlockProfileRecord_Stack");
this._bds=_bds;
this.p_recv=p_recv;
Scheduler.push(gr,this);
}
var _res:Slice;
public inline function res():Dynamic {return _res;}
var _t0:Pointer=null;
var _SF1:StackFrame;
var _t1:Slice=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_recv : Pointer) : Slice {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_BlockProfileRecord_Stack(0,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_recv : Pointer) : Slice {
var _sf=new Go__star_runtime_dot_BlockProfileRecord_Stack(_gr,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_recv : Pointer) : Go__star_runtime_dot_BlockProfileRecord_Stack
{return new Go__star_runtime_dot_BlockProfileRecord_Stack(gr,_bds, p_recv);
}
public function run():Go__star_runtime_dot_BlockProfileRecord_Stack {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1179,0);
this.SubFn0();
_SF1=Go__star_runtime_dot_StackRecord_Stack.call(this._goroutine,[],_t0);
_Next = -1;
return this;
case -1:
this.setLatest(1179,-1);
_t1=_SF1.res();
 // _t1 = (*runtime.StackRecord).Stack(t0) *ssa.Call near /usr/local/go/src/pkg/runtime/extern.go:104:2
_res= _t1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1 *ssa.Return near /usr/local/go/src/pkg/runtime/extern.go:104:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=p_recv.addr(2);  // _t0 = &recv.StackRecord [#2] *ssa.FieldAddr near /usr/local/go/src/pkg/runtime/extern.go:104:2 [POINTER]
}// end SubFn0
}
#if js @:expose("Go_utf8_ValidString") #end class Go_utf8_ValidString extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:415:6
var p_s:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String) {
super(gr,3487,"Go_utf8_ValidString");
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
this.setLatest(3487,0);
this.SubFn0();

case 1: // rangeiter.loop
this.setLatest(3487,1);
this.SubFn1();

case 2: // rangeiter.body
this.setLatest(3487,2);
this.SubFn2();

case 3: // rangeiter.done
this.setLatest(3487,3);
this.setPH(3500);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:428:2

case 4: // if.then
this.setLatest(3500,4);
this.SubFn3();
this.setPH(3494);
_SF1=Go_utf8_DecodeRuneInString.call(this._goroutine,[],_t6);
_Next = -1;
return this;
case -1:
this.setLatest(3494,-1);
_t7=_SF1.res();
 // _t7 = DecodeRuneInString(t6) *ssa.Call @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:33
this.SubFn4();

case 5: // if.then
this.setLatest(3494,5);
this.setPH(3496);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:424:5

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(3488);
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
this.setPH(3489);
_t5=(_t4==65533); // _t5 = t4 == 65533:int32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:417:8
_Next=_t5 ? 4 : 1; // if t5 goto 4.if.then else 1.rangeiter.loop *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:417:8
}// end SubFn2
private inline  function SubFn3():Void {
this.setPH(3494);
_t6=Force.toRawString(this._goroutine,Force.toUTF8slice(this._goroutine,p_s).subSlice(_t3,-1)); // _t6 = slice s[t3:] *ssa.Slice @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:35
}// end SubFn3
private inline  function SubFn4():Void {
var _t10:Bool;
 // _t8 = extract t7 #0 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:35 [REGISTER VALUE UN-USED]
_t9=_t7.r1; // _t9 = extract t7 #1 *ssa.Extract near /usr/local/go/src/pkg/unicode/utf8/utf8.go:422:35
this.setPH(3495);
_t10=(_t9==1); // _t10 = t9 == 1:int *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:423:12
_Next=_t10 ? 5 : 1; // if t10 goto 5.if.then else 1.rangeiter.loop *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:423:12
}// end SubFn4
}
#if (!php) private #end class Go_runtime_fcmp64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:343:6
var p_f:GOint64;
var p_g:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64) {
super(gr,1702,"Go_runtime_fcmp64");
this._bds=_bds;
this.p_f=p_f;
this.p_g=p_g;
Scheduler.push(gr,this);
}
var _res:{r0:Int, r1:Bool};
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:GOint64,r1:GOint64,r2:Int,r3:Bool,r4:Bool}=null;
var _t1:GOint64=null;
var _t2:GOint64=null;
var _t4:Bool=false;
var _t5:Bool=false;
var _SF2:StackFrame;
var _t6:{r0:GOint64,r1:GOint64,r2:Int,r3:Bool,r4:Bool}=null;
var _t7:GOint64=null;
var _t8:GOint64=null;
var _t10:Bool=false;
var _t11:Bool=false;
var _t12:Bool=false;
var _t13:Bool=false;
var _t14:Bool=false;
var _t15:Bool=false;
var _t16:Bool=false;
var _t17:Bool=false;
var _t18:Bool=false;
var _t19:Bool=false;
var _t20:Bool=false;
var _t21:Bool=false;
var _t22:Bool=false;
var _t23:Bool=false;
var _t24:Bool=false;
var _t25:Bool=false;
var _t26:Bool=false;
var _t27:Bool=false;
var _t28:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_g : GOint64) : {r0:Int, r1:Bool} {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fcmp64(0,[], p_f, p_g).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_g : GOint64) : {r0:Int, r1:Bool} {
var _sf=new Go_runtime_fcmp64(_gr,[], p_f, p_g).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64) : Go_runtime_fcmp64
{return new Go_runtime_fcmp64(gr,_bds, p_f, p_g);
}
public function run():Go_runtime_fcmp64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1702,0);
this.setPH(1703);
_SF1=Go_runtime_funpack64.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(1703,-1);
_t0=_SF1.res();
 // _t0 = funpack64(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:344:32
this.SubFn0();
this.setPH(1704);
_SF2=Go_runtime_funpack64.call(this._goroutine,[],p_g);
_Next = -2;
return this;
case -2:
this.setLatest(1704,-2);
_t6=_SF2.res();
 // _t6 = funpack64(g) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:345:32
this.SubFn1();
_Phi=0;
case 1: // switch.body
this.setLatest(1704,1);
this.setPH(1708);
_res= {r0:0,r1:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int, true:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:349:3

case 2: // switch.body
this.setLatest(1708,2);
this.setPH(1711);
_res= {r0:0,r1:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:352:3

case 3: // switch.next
this.setLatest(1711,3);
this.SubFn2();
_Phi=3;
case 4: // switch.next
this.setLatest(1711,4);
this.SubFn3();
_Phi=4;
case 5: // switch.body
this.setLatest(1711,5);
this.setPH(1714);
_res= {r0:(-1),r1:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:355:3

case 6: // switch.next
this.setLatest(1714,6);
this.SubFn4();
_Phi=6;
case 7: // binop.rhs
this.setLatest(1714,7);
this.SubFn5();
_Phi=7;
case 8: // binop.done
this.setLatest(1714,8);
this.setPH(1710);
_t14=((_Phi==4)?false:(_Phi==10)?false:(_Phi==9)?false:(_Phi==7)?_t13:false); // _t14 = phi [4.switch.next: false:bool, 10.cond.true: false:bool, 9.cond.true: false:bool, 7.binop.rhs: t13] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:351:29
this.SubFn6();
_Phi=8;
case 9: // cond.true
this.setLatest(1710,9);
this.SubFn7();
_Phi=9;
case 10: // cond.true
this.setLatest(1710,10);
this.SubFn8();
_Phi=10;
case 11: // switch.body
this.setLatest(1710,11);
this.setPH(1717);
_res= {r0:1,r1:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:358:3

case 12: // switch.next
this.setLatest(1717,12);
this.SubFn9();
_Phi=12;
case 13: // switch.body
this.setLatest(1717,13);
this.setPH(1723);
_res= {r0:(-1),r1:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:364:3

case 14: // switch.next
this.setLatest(1723,14);
this.SubFn10();
_Phi=14;
case 15: // switch.body
this.setLatest(1723,15);
this.setPH(1726);
_res= {r0:1,r1:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:367:3

case 16: // switch.next
this.setLatest(1726,16);
this.SubFn11();
_Phi=16;
case 17: // binop.rhs
this.setLatest(1726,17);
this.SubFn12();
_Phi=17;
case 18: // binop.done
this.setLatest(1726,18);
this.setPH(1722);
_t20=((_Phi==14)?false:(_Phi==17)?_t19:false); // _t20 = phi [14.switch.next: false:bool, 17.binop.rhs: t19] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:363:15
this.SubFn13();
_Phi=18;
case 19: // switch.next
this.setLatest(1722,19);
this.SubFn14();
_Phi=19;
case 20: // binop.rhs
this.setLatest(1722,20);
this.SubFn15();
_Phi=20;
case 21: // binop.done
this.setLatest(1722,21);
_t23=((_Phi==16)?false:(_Phi==20)?_t22:false); // _t23 = phi [16.switch.next: false:bool, 20.binop.rhs: t22] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:363:33
this.SubFn16();
_Phi=21;
case 22: // switch.next
this.setLatest(1722,22);
this.SubFn17();
_Phi=22;
case 23: // binop.rhs
this.setLatest(1722,23);
this.SubFn18();
_Phi=23;
case 24: // binop.done
this.setLatest(1722,24);
this.setPH(1725);
_t26=((_Phi==19)?false:(_Phi==23)?_t25:false); // _t26 = phi [19.switch.next: false:bool, 23.binop.rhs: t25] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:366:15
this.SubFn19();
_Phi=24;
case 25: // switch.next
this.setLatest(1725,25);
this.setPH(1730);
_res= {r0:0,r1:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:371:2

case 26: // binop.rhs
this.setLatest(1730,26);
this.SubFn20();
_Phi=26;
case 27: // binop.done
this.setLatest(1730,27);
this.setPH(1725);
_t28=((_Phi==22)?false:(_Phi==26)?_t27:false); // _t28 = phi [22.switch.next: false:bool, 26.binop.rhs: t27] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
this.SubFn21();
_Phi=27;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
 // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33 [REGISTER VALUE UN-USED]
_t4=_t0.r3; // _t4 = extract t0 #3 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
_t5=_t0.r4; // _t5 = extract t0 #4 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
}// end SubFn0
private inline  function SubFn1():Void {
_t7=_t6.r0; // _t7 = extract t6 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
_t8=_t6.r1; // _t8 = extract t6 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
 // _t9 = extract t6 #2 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33 [REGISTER VALUE UN-USED]
_t10=_t6.r3; // _t10 = extract t6 #3 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
_t11=_t6.r4; // _t11 = extract t6 #4 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
_Next=_t5 ? 1 : 3; // if t5 goto 1.switch.body else 3.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
}// end SubFn1
private inline  function SubFn2():Void {
_Next=_t11 ? 1 : 4; // if t11 goto 1.switch.body else 4.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
}// end SubFn2
private inline  function SubFn3():Void {
_Next=_t4 ? 8 : 10; // if t4 goto 8.binop.done else 10.cond.true *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:366:33
}// end SubFn3
private inline  function SubFn4():Void {
var _t12:Bool;
this.setPH(1713);
_t12=(GOint64.ucompare(_t1,_t7)>0); // _t12 = t1 > t7 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:354:10
_Next=_t12 ? 5 : 12; // if t12 goto 5.switch.body else 12.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:354:10
}// end SubFn4
private inline  function SubFn5():Void {
this.setPH(1710);
_t13=(GOint64.ucompare(_t8,GOint64.make(0x0,0x0))==0); // _t13 = t8 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:351:35
_Next=8; // jump 8.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:351:35
}// end SubFn5
private inline  function SubFn6():Void {
_Next=_t14 ? 2 : 6; // if t14 goto 2.switch.body else 6.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:351:35
}// end SubFn6
private inline  function SubFn7():Void {
var _t15:Bool;
_t15=(GOint64.ucompare(_t2,GOint64.make(0x0,0x0))==0); // _t15 = t2 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:351:24
_Next=_t15 ? 7 : 8; // if t15 goto 7.binop.rhs else 8.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:351:24
}// end SubFn7
private inline  function SubFn8():Void {
_Next=_t10 ? 8 : 9; // if t10 goto 8.binop.done else 9.cond.true *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:351:24
}// end SubFn8
private inline  function SubFn9():Void {
var _t16:Bool;
this.setPH(1716);
_t16=(GOint64.ucompare(_t1,_t7)<0); // _t16 = t1 < t7 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:357:10
_Next=_t16 ? 11 : 14; // if t16 goto 11.switch.body else 14.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:357:10
}// end SubFn9
private inline  function SubFn10():Void {
var _t17:Bool;
this.setPH(1722);
_t17=(GOint64.ucompare(_t1,GOint64.make(0x0,0x0))==0); // _t17 = t1 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:363:10
_Next=_t17 ? 17 : 18; // if t17 goto 17.binop.rhs else 18.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:363:10
}// end SubFn10
private inline  function SubFn11():Void {
var _t18:Bool;
_t18=(GOint64.ucompare(_t1,GOint64.make(0x0,0x0))!=0); // _t18 = t1 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:363:28
_Next=_t18 ? 20 : 21; // if t18 goto 20.binop.rhs else 21.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:363:28
}// end SubFn11
private inline  function SubFn12():Void {
_t19=(GOint64.ucompare(p_f,p_g)<0); // _t19 = f < g *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:363:20
_Next=18; // jump 18.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:363:20
}// end SubFn12
private inline  function SubFn13():Void {
_Next=_t20 ? 13 : 16; // if t20 goto 13.switch.body else 16.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:363:20
}// end SubFn13
private inline  function SubFn14():Void {
var _t21:Bool;
this.setPH(1725);
_t21=(GOint64.ucompare(_t1,GOint64.make(0x0,0x0))==0); // _t21 = t1 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:366:10
_Next=_t21 ? 23 : 24; // if t21 goto 23.binop.rhs else 24.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:366:10
}// end SubFn14
private inline  function SubFn15():Void {
this.setPH(1722);
_t22=(GOint64.ucompare(p_f,p_g)>0); // _t22 = f > g *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:363:38
_Next=21; // jump 21.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:363:38
}// end SubFn15
private inline  function SubFn16():Void {
_Next=_t23 ? 13 : 19; // if t23 goto 13.switch.body else 19.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:363:38
}// end SubFn16
private inline  function SubFn17():Void {
var _t24:Bool;
this.setPH(1725);
_t24=(GOint64.ucompare(_t1,GOint64.make(0x0,0x0))!=0); // _t24 = t1 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:366:28
_Next=_t24 ? 26 : 27; // if t24 goto 26.binop.rhs else 27.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:366:28
}// end SubFn17
private inline  function SubFn18():Void {
_t25=(GOint64.ucompare(p_f,p_g)>0); // _t25 = f > g *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:366:20
_Next=24; // jump 24.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:366:20
}// end SubFn18
private inline  function SubFn19():Void {
_Next=_t26 ? 15 : 22; // if t26 goto 15.switch.body else 22.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:366:20
}// end SubFn19
private inline  function SubFn20():Void {
_t27=(GOint64.ucompare(p_f,p_g)<0); // _t27 = f < g *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:366:38
_Next=27; // jump 27.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:366:38
}// end SubFn20
private inline  function SubFn21():Void {
_Next=_t28 ? 15 : 25; // if t28 goto 15.switch.body else 25.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:366:38
}// end SubFn21
}
#if (!php) private #end class Go_runtime_fmul64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:258:6
var p_f:GOint64;
var p_g:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64) {
super(gr,1617,"Go_runtime_fmul64");
this._bds=_bds;
this.p_f=p_f;
this.p_g=p_g;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:GOint64,r1:GOint64,r2:Int,r3:Bool,r4:Bool}=null;
var _t1:GOint64=null;
var _t2:GOint64=null;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Bool=false;
var _SF2:StackFrame;
var _t6:{r0:GOint64,r1:GOint64,r2:Int,r3:Bool,r4:Bool}=null;
var _t7:GOint64=null;
var _t8:GOint64=null;
var _t9:Int=0;
var _t10:Bool=false;
var _t11:Bool=false;
var _t12:GOint64=null;
var _t13:Bool=false;
var _t14:Bool=false;
var _t15:GOint64=null;
var _t16:Bool=false;
var _t17:Bool=false;
var _t18:Bool=false;
var _t19:Bool=false;
var _t20:Bool=false;
var _t21:GOint64=null;
var _t22:Bool=false;
var _SF3:StackFrame;
var _t23:{r0:GOint64,r1:GOint64}=null;
var _t24:GOint64=null;
var _t25:GOint64=null;
var _t26:GOint64=null;
var _t27:GOint64=null;
var _t28:GOint64=null;
var _t29:Int=0;
var _t30:GOint64=null;
var _t31:GOint64=null;
var _t32:GOint64=null;
var _t33:GOint64=null;
var _t34:Int=0;
var _t35:Int=0;
var _SF4:StackFrame;
var _t36:GOint64=null;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_g : GOint64) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fmul64(0,[], p_f, p_g).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_g : GOint64) : GOint64 {
var _sf=new Go_runtime_fmul64(_gr,[], p_f, p_g).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64) : Go_runtime_fmul64
{return new Go_runtime_fmul64(gr,_bds, p_f, p_g);
}
public function run():Go_runtime_fmul64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1617,0);
this.setPH(1618);
_SF1=Go_runtime_funpack64.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(1618,-1);
_t0=_SF1.res();
 // _t0 = funpack64(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:259:33
this.SubFn0();
this.setPH(1619);
_SF2=Go_runtime_funpack64.call(this._goroutine,[],p_g);
_Next = -2;
return this;
case -2:
this.setLatest(1619,-2);
_t6=_SF2.res();
 // _t6 = funpack64(g) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:260:33
this.SubFn1();
_Phi=0;
case 1: // switch.body
this.setLatest(1619,1);
this.setPH(1624);
_res= GOint64.make(0x7ff00000,0x1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 9218868437227405313:uint64 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:265:3

case 2: // switch.body
this.setLatest(1624,2);
this.SubFn2();
this.setPH(1627);
_res= _t12;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t12 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:268:3

case 3: // switch.next
this.setLatest(1627,3);
this.SubFn3();
_Phi=3;
case 4: // binop.rhs
this.setLatest(1627,4);
this.SubFn4();
_Phi=4;
case 5: // binop.done
this.setLatest(1627,5);
this.setPH(1623);
_t13=((_Phi==0)?true:(_Phi==4)?_t11:false); // _t13 = phi [0.entry: true:bool, 4.binop.rhs: t11] #|| *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:264:10
this.SubFn5();
_Phi=5;
case 6: // switch.body
this.setLatest(1623,6);
this.setPH(1630);
_res= GOint64.make(0x7ff00000,0x1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 9218868437227405313:uint64 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:271:3

case 7: // switch.next
this.setLatest(1630,7);
this.SubFn6();
_Phi=7;
case 8: // binop.rhs
this.setLatest(1630,8);
this.SubFn7();
_Phi=8;
case 9: // binop.done
this.setLatest(1630,9);
this.setPH(1626);
_t14=((_Phi==3)?false:(_Phi==8)?_t10:false); // _t14 = phi [3.switch.next: false:bool, 8.binop.rhs: t10] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:267:10
this.SubFn8();
_Phi=9;
case 10: // switch.body
this.setLatest(1626,10);
this.SubFn9();
this.setPH(1633);
_res= _t15;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t15 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:274:3

case 11: // switch.next
this.setLatest(1633,11);
this.SubFn10();
_Phi=11;
case 12: // binop.rhs
this.setLatest(1633,12);
this.SubFn11();
_Phi=12;
case 13: // binop.done
this.setLatest(1633,13);
this.setPH(1629);
_t18=((_Phi==7)?false:(_Phi==12)?_t17:false); // _t18 = phi [7.switch.next: false:bool, 12.binop.rhs: t17] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:270:10
this.SubFn12();
_Phi=13;
case 14: // switch.next
this.setLatest(1629,14);
this.SubFn13();
_Phi=14;
case 15: // binop.rhs
this.setLatest(1629,15);
this.SubFn14();
_Phi=15;
case 16: // binop.done
this.setLatest(1629,16);
_t20=((_Phi==11)?false:(_Phi==15)?_t10:false); // _t20 = phi [11.switch.next: false:bool, 15.binop.rhs: t10] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:270:30
this.SubFn15();
_Phi=16;
case 17: // switch.body
this.setLatest(1629,17);
this.SubFn16();
this.setPH(1636);
_res= _t21;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t21 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:277:3

case 18: // switch.next
this.setLatest(1636,18);
this.SubFn17();
_Phi=18;
case 19: // switch.next
this.setLatest(1636,19);
this.setPH(1640);
_SF3=Go_runtime_mullu.call(this._goroutine,[],_t2,_t8);
_Next = -3;
return this;
case -3:
this.setLatest(1640,-3);
_t23=_SF3.res();
 // _t23 = mullu(t2, t8) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:281:17
this.SubFn18();
this.setPH(1644);
_SF4=Go_runtime_fpack64.call(this._goroutine,[],_t33,_t32,_t35,_t28);
_Next = -4;
return this;
case -4:
this.setLatest(1644,-4);
_t36=_SF4.res();
 // _t36 = fpack64(t33, t32, t35, t28) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:285:16
_res= _t36;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t36 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:285:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:285:2
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:285:2
_t3=_t0.r2; // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:285:2
_t4=_t0.r3; // _t4 = extract t0 #3 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:285:2
_t5=_t0.r4; // _t5 = extract t0 #4 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:285:2
}// end SubFn0
private inline  function SubFn1():Void {
_t7=_t6.r0; // _t7 = extract t6 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:285:2
_t8=_t6.r1; // _t8 = extract t6 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:285:2
_t9=_t6.r2; // _t9 = extract t6 #2 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:285:2
_t10=_t6.r3; // _t10 = extract t6 #3 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:285:2
_t11=_t6.r4; // _t11 = extract t6 #4 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:285:2
_Next=_t5 ? 5 : 4; // if t5 goto 5.binop.done else 4.binop.rhs *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:285:2
}// end SubFn1
private inline  function SubFn2():Void {
this.setPH(1627);
_t12=Force.toUint64(GOint64.xor(p_f,_t7)); // _t12 = f ^ t7 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:268:12
}// end SubFn2
private inline  function SubFn3():Void {
_Next=_t4 ? 8 : 9; // if t4 goto 8.binop.rhs else 9.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:268:12
}// end SubFn3
private inline  function SubFn4():Void {
_Next=5; // jump 5.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:268:12
}// end SubFn4
private inline  function SubFn5():Void {
_Next=_t13 ? 1 : 3; // if t13 goto 1.switch.body else 3.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:268:12
}// end SubFn5
private inline  function SubFn6():Void {
_Next=_t4 ? 12 : 13; // if t4 goto 12.binop.rhs else 13.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:268:12
}// end SubFn6
private inline  function SubFn7():Void {
_Next=9; // jump 9.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:268:12
}// end SubFn7
private inline  function SubFn8():Void {
_Next=_t14 ? 2 : 7; // if t14 goto 2.switch.body else 7.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:268:12
}// end SubFn8
private inline  function SubFn9():Void {
this.setPH(1633);
_t15=Force.toUint64(GOint64.xor(p_f,_t7)); // _t15 = f ^ t7 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:274:12
}// end SubFn9
private inline  function SubFn10():Void {
var _t16:Bool;
this.setPH(1629);
_t16=(GOint64.ucompare(_t2,GOint64.make(0x0,0x0))==0); // _t16 = t2 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:270:25
_Next=_t16 ? 15 : 16; // if t16 goto 15.binop.rhs else 16.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:270:25
}// end SubFn10
private inline  function SubFn11():Void {
_t17=(GOint64.ucompare(_t8,GOint64.make(0x0,0x0))==0); // _t17 = t8 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:270:16
_Next=13; // jump 13.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:270:16
}// end SubFn11
private inline  function SubFn12():Void {
_Next=_t18 ? 6 : 11; // if t18 goto 6.switch.body else 11.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:270:16
}// end SubFn12
private inline  function SubFn13():Void {
var _t19:Bool;
this.setPH(1632);
_t19=(GOint64.ucompare(_t2,GOint64.make(0x0,0x0))==0); // _t19 = t2 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:273:10
_Next=_t19 ? 10 : 18; // if t19 goto 10.switch.body else 18.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:273:10
}// end SubFn13
private inline  function SubFn14():Void {
_Next=16; // jump 16.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:273:10
}// end SubFn14
private inline  function SubFn15():Void {
_Next=_t20 ? 6 : 14; // if t20 goto 6.switch.body else 14.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:273:10
}// end SubFn15
private inline  function SubFn16():Void {
this.setPH(1636);
_t21=Force.toUint64(GOint64.xor(p_g,_t1)); // _t21 = g ^ t1 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:277:12
}// end SubFn16
private inline  function SubFn17():Void {
var _t22:Bool;
this.setPH(1635);
_t22=(GOint64.ucompare(_t8,GOint64.make(0x0,0x0))==0); // _t22 = t8 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:276:10
_Next=_t22 ? 17 : 19; // if t22 goto 17.switch.body else 19.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:276:10
}// end SubFn17
private inline  function SubFn18():Void {
var _t26:GOint64;
var _t27:GOint64;
var _t29:Int;
var _t30:GOint64;
var _t31:GOint64;
var _t34:Int;
_t24=_t23.r0; // _t24 = extract t23 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:276:10
_t25=_t23.r1; // _t25 = extract t23 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:276:10
this.setPH(1642);
_t26=Force.toUint64(GOint64.shl(GOint64.make(0x0,0x1),51)); // _t26 = 1:uint64 << 51:uint *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:283:18
_t27=Force.toUint64(GOint64.sub(_t26,GOint64.make(0x0,0x1))); // _t27 = t26 - 1:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:283:26
_t28=Force.toUint64(GOint64.and(_t24,_t27)); // _t28 = t24 & t27 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:283:14
this.setPH(1643);
_t29=(64-51); // _t29 = 64:uint - 51:uint *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:284:17
_t30=Force.toUint64(GOint64.shl(_t25,_t29)); // _t30 = t25 << t29 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:284:12
_t31=Force.toUint64(GOint64.ushr(_t24,51)); // _t31 = t24 >> 51:uint *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:284:29
_t32=Force.toUint64(GOint64.or(_t30,_t31)); // _t32 = t30 | t31 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:284:25
this.setPH(1644);
_t33=Force.toUint64(GOint64.xor(_t1,_t7)); // _t33 = t1 ^ t7 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:285:19
_t34=(_t3+_t9); // _t34 = t3 + t9 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:285:32
_t35=(_t34-1); // _t35 = t34 - 1:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:285:35
}// end SubFn18
}
#if js @:expose("Go__star_runtime_dot_Func_Name") #end class Go__star_runtime_dot_Func_Name extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/extern.go:98:16
var p_f:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : Pointer) {
super(gr,989,"Go__star_runtime_dot_Func_Name");
this._bds=_bds;
this.p_f=p_f;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:String="";
var _Next:Int=0;
public static inline function callFromHaxe( p_f : Pointer) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_Func_Name(0,[], p_f).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : Pointer) : String {
var _sf=new Go__star_runtime_dot_Func_Name(_gr,[], p_f).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : Pointer) : Go__star_runtime_dot_Func_Name
{return new Go__star_runtime_dot_Func_Name(gr,_bds, p_f);
}
public function run():Go__star_runtime_dot_Func_Name {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(989,0);
this.setPH(990);
_SF1=Go_runtime_funcname_go.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(990,-1);
_t0=_SF1.res();
 // _t0 = funcname_go(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/extern.go:99:20
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ /usr/local/go/src/pkg/runtime/extern.go:99:2

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_runtime_dot_Error_RuntimeError") #end class Go_runtime_dot_Error_RuntimeError extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/error.go:15:2
var p_recv:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_recv : Interface) {
super(gr,783,"Go_runtime_dot_Error_RuntimeError");
this._bds=_bds;
this.p_recv=p_recv;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _SF1:StackFrame;
var _Next:Int=0;
public static inline function callFromHaxe( p_recv : Interface) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_dot_Error_RuntimeError(0,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_recv : Interface) : Void {
var _sf=new Go_runtime_dot_Error_RuntimeError(_gr,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_recv : Interface) : Go_runtime_dot_Error_RuntimeError
{return new Go_runtime_dot_Error_RuntimeError(gr,_bds, p_recv);
}
public function run():Go_runtime_dot_Error_RuntimeError {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(783,0);
Interface.invoke(p_recv,"RuntimeError",[this._goroutine,[],p_recv.val]);_Next = -1;
return this;
case -1:
this.setLatest(783,-1);
 // _t0 = invoke recv.RuntimeError() *ssa.Call near /usr/local/go/src/pkg/runtime/extern.go:99:2 [REGISTER VALUE UN-USED]
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/extern.go:99:2

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_utf8_EncodeRune") #end class Go_utf8_EncodeRune extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/unicode/utf8/utf8.go:330:6
var p_p:Slice;
var p_r:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_p : Slice, p_r : Int) {
super(gr,3402,"Go_utf8_EncodeRune");
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
this.setLatest(3402,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(3402,1);
this.SubFn1();
this.setPH(3406);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:334:3

case 2: // if.done
this.setLatest(3406,2);
this.SubFn2();
_Phi=2;
case 3: // if.then
this.setLatest(3406,3);
this.SubFn3();
this.setPH(3412);
_res= 2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 2:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:340:3

case 4: // if.done
this.setLatest(3412,4);
this.SubFn4();
_Phi=4;
case 5: // if.then
this.setLatest(3412,5);
this.SubFn5();
_Phi=5;
case 6: // if.done
this.setLatest(3412,6);
this.setPH(3402);
_t16=((_Phi==4)?p_r:(_Phi==5)?65533:0); // _t16 = phi [4.if.done: r, 5.if.then: 65533:rune] #r *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:330:27
this.SubFn6();
_Phi=6;
case 7: // if.then
this.setLatest(3402,7);
this.SubFn7();
_Phi=7;
case 8: // if.done
this.setLatest(3402,8);
_t18=((_Phi==6)?_t16:(_Phi==9)?_t16:(_Phi==7)?65533:0); // _t18 = phi [6.if.done: t16, 9.cond.true: t16, 7.if.then: 65533:rune] #r *ssa.Phi @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:330:27
this.SubFn8();
_Phi=8;
case 9: // cond.true
this.setLatest(3402,9);
this.SubFn9();
_Phi=9;
case 10: // if.then
this.setLatest(3402,10);
this.SubFn10();
this.setPH(3427);
_res= 3;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 3:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:355:3

case 11: // if.done
this.setLatest(3427,11);
this.SubFn11();
this.setPH(3434);
_res= 4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 4:int *ssa.Return @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:362:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
var _t1:Bool;
this.setPH(3404);
_t0=p_r; // _t0 = convert uint32 <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:332:11
_t1=(Force.uintCompare(_t0,127)<=0); // _t1 = t0 <= 127:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:332:15
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:332:15
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Pointer;
var _t3:Int;
this.setPH(3405);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:4 [POINTER]
_t2=p_p.addr(0);  // _t2 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:4 [POINTER]
_t3=p_r; // _t3 = convert byte <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:14
_t2.store(_t3); // *t2 = t3 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:333:14
}// end SubFn1
private inline  function SubFn2():Void {
var _t4:Int;
var _t5:Bool;
this.setPH(3409);
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
this.setPH(3410);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t6 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:4 [POINTER]
_t6=p_p.addr(0);  // _t6 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:4 [POINTER]
_t7=(p_r>>GOint64.toInt(GOint64.make(0x0,0x6))); // _t7 = r >> 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:21
_t8=_t7; // _t8 = convert byte <- rune (t7) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:19
_t9=Force.toUint8((192|_t8)); // _t9 = 192:byte | t8 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:13
_t6.store(_t9); // *t6 = t9 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:338:13
this.setPH(3411);
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
this.setPH(3415);
_t14=p_r; // _t14 = convert uint32 <- rune (r) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:11
_t15=(Force.uintCompare(_t14,1114111)>0); // _t15 = t14 > 1114111:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:15
_Next=_t15 ? 5 : 6; // if t15 goto 5.if.then else 6.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:15
}// end SubFn4
private inline  function SubFn5():Void {
_Next=6; // jump 6.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:343:15
}// end SubFn5
private inline  function SubFn6():Void {
var _t17:Bool;
this.setPH(3419);
_t17=(55296<=_t16); // _t17 = 55296:rune <= t16 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:18
_Next=_t17 ? 9 : 8; // if t17 goto 9.cond.true else 8.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:18
}// end SubFn6
private inline  function SubFn7():Void {
_Next=8; // jump 8.if.done *ssa.Jump near /usr/local/go/src/pkg/unicode/utf8/utf8.go:347:18
}// end SubFn7
private inline  function SubFn8():Void {
var _t19:Int;
var _t20:Bool;
this.setPH(3423);
_t19=_t18; // _t19 = convert uint32 <- rune (t18) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:351:11
_t20=(Force.uintCompare(_t19,65535)<=0); // _t20 = t19 <= 65535:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:351:15
_Next=_t20 ? 10 : 11; // if t20 goto 10.if.then else 11.if.done *ssa.If near /usr/local/go/src/pkg/unicode/utf8/utf8.go:351:15
}// end SubFn8
private inline  function SubFn9():Void {
var _t21:Bool;
this.setPH(3419);
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
this.setPH(3424);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t22 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:4 [POINTER]
_t22=p_p.addr(0);  // _t22 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:4 [POINTER]
_t23=(_t18>>GOint64.toInt(GOint64.make(0x0,0xc))); // _t23 = t18 >> 12:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:21
_t24=_t23; // _t24 = convert byte <- rune (t23) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:19
_t25=Force.toUint8((224|_t24)); // _t25 = 224:byte | t24 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:13
_t22.store(_t25); // *t22 = t25 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:352:13
this.setPH(3425);
if((1<0)||(1>=p_p.len())) Scheduler.ioor(); // _t26 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:4 [POINTER]
_t26=p_p.addr(1);  // _t26 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:4 [POINTER]
_t27=(_t18>>GOint64.toInt(GOint64.make(0x0,0x6))); // _t27 = t18 >> 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:21
_t28=_t27; // _t28 = convert byte <- rune (t27) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:19
_t29=Force.toUint8((_t28&63)); // _t29 = t28 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:25
_t30=Force.toUint8((128|_t29)); // _t30 = 128:byte | t29 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:13
_t26.store(_t30); // *t26 = t30 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:353:13
this.setPH(3426);
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
this.setPH(3430);
if((0<0)||(0>=p_p.len())) Scheduler.ioor(); // _t35 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:3 [POINTER]
_t35=p_p.addr(0);  // _t35 = &p[0:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:3 [POINTER]
_t36=(_t18>>GOint64.toInt(GOint64.make(0x0,0x12))); // _t36 = t18 >> 18:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:20
_t37=_t36; // _t37 = convert byte <- rune (t36) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:18
_t38=Force.toUint8((240|_t37)); // _t38 = 240:byte | t37 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:12
_t35.store(_t38); // *t35 = t38 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:358:12
this.setPH(3431);
if((1<0)||(1>=p_p.len())) Scheduler.ioor(); // _t39 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:3 [POINTER]
_t39=p_p.addr(1);  // _t39 = &p[1:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:3 [POINTER]
_t40=(_t18>>GOint64.toInt(GOint64.make(0x0,0xc))); // _t40 = t18 >> 12:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:20
_t41=_t40; // _t41 = convert byte <- rune (t40) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:18
_t42=Force.toUint8((_t41&63)); // _t42 = t41 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:25
_t43=Force.toUint8((128|_t42)); // _t43 = 128:byte | t42 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:12
_t39.store(_t43); // *t39 = t43 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:359:12
this.setPH(3432);
if((2<0)||(2>=p_p.len())) Scheduler.ioor(); // _t44 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:3 [POINTER]
_t44=p_p.addr(2);  // _t44 = &p[2:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:3 [POINTER]
_t45=(_t18>>GOint64.toInt(GOint64.make(0x0,0x6))); // _t45 = t18 >> 6:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:20
_t46=_t45; // _t46 = convert byte <- rune (t45) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:18
_t47=Force.toUint8((_t46&63)); // _t47 = t46 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:24
_t48=Force.toUint8((128|_t47)); // _t48 = 128:byte | t47 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:12
_t44.store(_t48); // *t44 = t48 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:360:12
this.setPH(3433);
if((3<0)||(3>=p_p.len())) Scheduler.ioor(); // _t49 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:3 [POINTER]
_t49=p_p.addr(3);  // _t49 = &p[3:int] *ssa.IndexAddr @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:3 [POINTER]
_t50=_t18; // _t50 = convert byte <- rune (t18) *ssa.Convert @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:18
_t51=Force.toUint8((_t50&63)); // _t51 = t50 & 63:byte *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:21
_t52=Force.toUint8((128|_t51)); // _t52 = 128:byte | t51 *ssa.BinOp @ /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:12
_t49.store(_t52); // *t49 = t52 *ssa.Store near /usr/local/go/src/pkg/unicode/utf8/utf8.go:361:12
}// end SubFn11
}
#if (!php) private #end class Go_runtime_f32to64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:330:6
var p_f:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : Int) {
super(gr,1689,"Go_runtime_f32to64");
this._bds=_bds;
this.p_f=p_f;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:Int,r1:Int,r2:Int,r3:Bool,r4:Bool}=null;
var _t1:Int=0;
var _t2:Int=0;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Bool=false;
var _t6:GOint64=null;
var _t7:GOint64=null;
var _t8:GOint64=null;
var _t9:GOint64=null;
var _t10:GOint64=null;
var _SF2:StackFrame;
var _t11:GOint64=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : Int) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_f32to64(0,[], p_f).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : Int) : GOint64 {
var _sf=new Go_runtime_f32to64(_gr,[], p_f).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : Int) : Go_runtime_f32to64
{return new Go_runtime_f32to64(gr,_bds, p_f);
}
public function run():Go_runtime_f32to64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1689,0);
this.setPH(1691);
_SF1=Go_runtime_funpack32.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(1691,-1);
_t0=_SF1.res();
 // _t0 = funpack32(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:332:33
this.SubFn0();

case 1: // if.then
this.setLatest(1691,1);
this.setPH(1693);
_res= GOint64.make(0x7ff00000,0x1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 9218868437227405313:uint64 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:334:3

case 2: // if.done
this.setLatest(1693,2);
this.SubFn1();

case 3: // if.then
this.setLatest(1693,3);
this.SubFn2();
this.setPH(1697);
_res= _t8;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t8 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:338:3

case 4: // if.done
this.setLatest(1697,4);
this.SubFn3();
this.setPH(1699);
_SF2=Go_runtime_fpack64.call(this._goroutine,[],_t7,_t10,_t3,GOint64.make(0x0,0x0));
_Next = -2;
return this;
case -2:
this.setLatest(1699,-2);
_t11=_SF2.res();
 // _t11 = fpack64(t7, t10, t3, 0:uint64) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:340:16
_res= _t11;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t11 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:340:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:340:2
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:340:2
_t3=_t0.r2; // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:340:2
_t4=_t0.r3; // _t4 = extract t0 #3 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:340:2
_t5=_t0.r4; // _t5 = extract t0 #4 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:340:2
_Next=_t5 ? 1 : 2; // if t5 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:340:2
}// end SubFn0
private inline  function SubFn1():Void {
var _t6:GOint64;
this.setPH(1695);
_t6=GOint64.ofInt(_t1); // _t6 = convert uint64 <- uint32 (t1) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:336:16
_t7=Force.toUint64(GOint64.shl(_t6,GOint64.toInt(GOint64.make(0x0,0x20)))); // _t7 = t6 << 32:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:336:21
_Next=_t4 ? 3 : 4; // if t4 goto 3.if.then else 4.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:336:21
}// end SubFn1
private inline  function SubFn2():Void {
this.setPH(1697);
_t8=Force.toUint64(GOint64.xor(_t7,GOint64.make(0x7ff00000,0x0))); // _t8 = t7 ^ 9218868437227405312:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:338:15
}// end SubFn2
private inline  function SubFn3():Void {
var _t9:GOint64;
this.setPH(1699);
_t9=GOint64.ofInt(_t2); // _t9 = convert uint64 <- uint32 (t2) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:340:29
_t10=Force.toUint64(GOint64.shl(_t9,29)); // _t10 = t9 << 29:uint *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:340:33
}// end SubFn3
}
#if (!php) private #end class Go_runtime_f64toint extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:374:6
var p_f:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64) {
super(gr,1733,"Go_runtime_f64toint");
this._bds=_bds;
this.p_f=p_f;
Scheduler.push(gr,this);
}
var _res:{r0:GOint64, r1:Bool};
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:GOint64,r1:GOint64,r2:Int,r3:Bool,r4:Bool}=null;
var _t1:GOint64=null;
var _t2:GOint64=null;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Bool=false;
var _t6:Bool=false;
var _t7:Bool=false;
var _t8:Bool=false;
var _t9:Bool=false;
var _t10:Bool=false;
var _t11:Int=0;
var _t12:GOint64=null;
var _t13:GOint64=null;
var _t14:Int=0;
var _t15:Bool=false;
var _t16:Int=0;
var _t17:GOint64=null;
var _t18:GOint64=null;
var _t19:Bool=false;
var _t20:GOint64=null;
var _t21:Int=0;
var _t22:Bool=false;
var _t23:GOint64=null;
var _t24:GOint64=null;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64) : {r0:GOint64, r1:Bool} {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_f64toint(0,[], p_f).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : GOint64) : {r0:GOint64, r1:Bool} {
var _sf=new Go_runtime_f64toint(_gr,[], p_f).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64) : Go_runtime_f64toint
{return new Go_runtime_f64toint(gr,_bds, p_f);
}
public function run():Go_runtime_f64toint {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1733,0);
this.setPH(1734);
_SF1=Go_runtime_funpack64.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(1734,-1);
_t0=_SF1.res();
 // _t0 = funpack64(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:375:33
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(1734,1);
this.setPH(1738);
_res= {r0:GOint64.make(0x0,0x0),r1:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int64, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:379:3

case 2: // switch.body
this.setLatest(1738,2);
this.setPH(1741);
_res= {r0:GOint64.make(0x0,0x0),r1:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int64, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:382:3

case 3: // switch.next
this.setLatest(1741,3);
this.SubFn1();
_Phi=3;
case 4: // switch.next
this.setLatest(1741,4);
this.SubFn2();
_Phi=4;
case 5: // switch.body
this.setLatest(1741,5);
this.SubFn3();
_Phi=5;
case 6: // switch.next
this.setLatest(1741,6);
this.SubFn4();
_Phi=6;
case 7: // if.then
this.setLatest(1741,7);
this.setPH(1745);
_res= {r0:GOint64.make(0x80000000,0x0),r1:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -9223372036854775808:int64, true:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:386:4

case 8: // if.done
this.setLatest(1745,8);
this.SubFn5();
_Phi=8;
case 9: // cond.true
this.setLatest(1745,9);
this.SubFn6();
_Phi=9;
case 10: // if.then
this.setLatest(1745,10);
this.setPH(1748);
_res= {r0:GOint64.make(0x0,0x0),r1:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int64, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:389:4

case 11: // if.done
this.setLatest(1748,11);
this.setPH(1750);
_res= {r0:GOint64.make(0x0,0x0),r1:false};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int64, false:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:391:3

case 12: // for.body
this.setLatest(1750,12);
this.SubFn7();
_Phi=12;
case 13: // for.loop
this.setLatest(1750,13);
this.setPH(1734);
_t13=((_Phi==6)?_t2:(_Phi==12)?_t12:GOint64.make(0,0)); // _t13 = phi [6.switch.next: t2, 12.for.body: t12] #fm *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:375:6
_t14=((_Phi==6)?_t3:(_Phi==12)?_t11:0); // _t14 = phi [6.switch.next: t3, 12.for.body: t11] #fe *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:375:10
this.SubFn8();
_Phi=13;
case 14: // for.body
this.setLatest(1734,14);
this.SubFn9();
_Phi=14;
case 15: // for.done
this.setLatest(1734,15);
this.SubFn10();
_Phi=15;
case 16: // for.loop
this.setLatest(1734,16);
_t20=((_Phi==13)?_t13:(_Phi==14)?_t17:GOint64.make(0,0)); // _t20 = phi [13.for.loop: t13, 14.for.body: t17] #fm *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:375:6
_t21=((_Phi==13)?_t14:(_Phi==14)?_t16:0); // _t21 = phi [13.for.loop: t14, 14.for.body: t16] #fe *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:375:10
this.SubFn11();
_Phi=16;
case 17: // if.then
this.setLatest(1734,17);
this.SubFn12();
_Phi=17;
case 18: // if.done
this.setLatest(1734,18);
this.setPH(1733);
_t24=((_Phi==15)?_t18:(_Phi==17)?_t23:GOint64.make(0,0)); // _t24 = phi [15.for.done: t18, 17.if.then: t23] #val *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:374:26
this.setPH(1765);
_res= {r0:_t24,r1:true};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t24, true:bool *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:406:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:406:2
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:406:2
_t3=_t0.r2; // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:406:2
_t4=_t0.r3; // _t4 = extract t0 #3 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:406:2
_t5=_t0.r4; // _t5 = extract t0 #4 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:406:2
_Next=_t4 ? 1 : 3; // if t4 goto 1.switch.body else 3.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:406:2
}// end SubFn0
private inline  function SubFn1():Void {
_Next=_t5 ? 1 : 4; // if t5 goto 1.switch.body else 4.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:406:2
}// end SubFn1
private inline  function SubFn2():Void {
var _t6:Bool;
this.setPH(1740);
_t6=(_t3<(-1)); // _t6 = t3 < -1:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:381:10
_Next=_t6 ? 2 : 6; // if t6 goto 2.switch.body else 6.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:381:10
}// end SubFn2
private inline  function SubFn3():Void {
var _t7:Bool;
this.setPH(1744);
_t7=(GOint64.ucompare(_t1,GOint64.make(0x0,0x0))!=0); // _t7 = t1 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:385:9
_Next=_t7 ? 9 : 8; // if t7 goto 9.cond.true else 8.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:385:9
}// end SubFn3
private inline  function SubFn4():Void {
var _t8:Bool;
this.setPH(1743);
_t8=(_t3>63); // _t8 = t3 > 63:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:384:10
_Next=_t8 ? 5 : 13; // if t8 goto 5.switch.body else 13.for.loop *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:384:10
}// end SubFn4
private inline  function SubFn5():Void {
var _t9:Bool;
this.setPH(1747);
_t9=(GOint64.ucompare(_t1,GOint64.make(0x0,0x0))!=0); // _t9 = t1 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:388:9
_Next=_t9 ? 10 : 11; // if t9 goto 10.if.then else 11.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:388:9
}// end SubFn5
private inline  function SubFn6():Void {
var _t10:Bool;
this.setPH(1744);
_t10=(GOint64.ucompare(_t2,GOint64.make(0x0,0x0))==0); // _t10 = t2 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:385:20
_Next=_t10 ? 7 : 8; // if t10 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:385:20
}// end SubFn6
private inline  function SubFn7():Void {
_t11=(_t14-1); // _t11 = t14 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:385:20
_t12=Force.toUint64(GOint64.shl(_t13,GOint64.toInt(GOint64.make(0x0,0x1)))); // _t12 = t13 << 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:385:20
_Next=13; // jump 13.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:385:20
}// end SubFn7
private inline  function SubFn8():Void {
var _t15:Bool;
this.setPH(1753);
_t15=(_t14>52); // _t15 = t14 > 52:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:394:9
_Next=_t15 ? 12 : 16; // if t15 goto 12.for.body else 16.for.loop *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:394:9
}// end SubFn8
private inline  function SubFn9():Void {
_t16=(_t21+1); // _t16 = t21 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:394:9
_t17=Force.toUint64(GOint64.ushr(_t20,GOint64.toInt(GOint64.make(0x0,0x1)))); // _t17 = t20 >> 1:uint64 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:394:9
_Next=16; // jump 16.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:394:9
}// end SubFn9
private inline  function SubFn10():Void {
var _t19:Bool;
this.setPH(1761);
_t18=_t20; // _t18 = convert int64 <- uint64 (t20) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:402:13
this.setPH(1762);
_t19=(GOint64.ucompare(_t1,GOint64.make(0x0,0x0))!=0); // _t19 = t1 != 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:403:8
_Next=_t19 ? 17 : 18; // if t19 goto 17.if.then else 18.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:403:8
}// end SubFn10
private inline  function SubFn11():Void {
var _t22:Bool;
this.setPH(1757);
_t22=(_t21<52); // _t22 = t21 < 52:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:398:9
_Next=_t22 ? 14 : 15; // if t22 goto 14.for.body else 15.for.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:398:9
}// end SubFn11
private inline  function SubFn12():Void {
this.setPH(1763);
_t23=Force.toInt64(GOint64.neg(_t18)); // _t23 = -t18 *ssa.UnOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:404:9
_Next=18; // jump 18.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:404:9
}// end SubFn12
}
#if js @:expose("Go_tardisgolib_HAXE") #end class Go_tardisgolib_HAXE extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:12:6
var p_code:String;
public function new(gr:Int,_bds:Array<Dynamic>, p_code : String) {
super(gr,475,"Go_tardisgolib_HAXE");
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
this.setLatest(475,0);
_res= 0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:uintptr *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:12:40

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_runtime_fdiv64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:288:6
var p_f:GOint64;
var p_g:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64) {
super(gr,1647,"Go_runtime_fdiv64");
this._bds=_bds;
this.p_f=p_f;
this.p_g=p_g;
Scheduler.push(gr,this);
}
var _res:GOint64;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:GOint64,r1:GOint64,r2:Int,r3:Bool,r4:Bool}=null;
var _t1:GOint64=null;
var _t2:GOint64=null;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Bool=false;
var _SF2:StackFrame;
var _t6:{r0:GOint64,r1:GOint64,r2:Int,r3:Bool,r4:Bool}=null;
var _t7:GOint64=null;
var _t8:GOint64=null;
var _t9:Int=0;
var _t10:Bool=false;
var _t11:Bool=false;
var _t12:Bool=false;
var _t13:Bool=false;
var _t14:GOint64=null;
var _t15:GOint64=null;
var _t16:Bool=false;
var _t17:Bool=false;
var _t18:Bool=false;
var _t19:GOint64=null;
var _t20:GOint64=null;
var _t21:Bool=false;
var _t22:Bool=false;
var _t23:Bool=false;
var _t24:Int=0;
var _t25:GOint64=null;
var _t26:GOint64=null;
var _SF3:StackFrame;
var _t27:{r0:GOint64,r1:GOint64}=null;
var _t28:GOint64=null;
var _t29:GOint64=null;
var _t30:GOint64=null;
var _t31:Int=0;
var _t32:Int=0;
var _SF4:StackFrame;
var _t33:GOint64=null;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : GOint64, p_g : GOint64) : GOint64 {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fdiv64(0,[], p_f, p_g).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : GOint64, p_g : GOint64) : GOint64 {
var _sf=new Go_runtime_fdiv64(_gr,[], p_f, p_g).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : GOint64, p_g : GOint64) : Go_runtime_fdiv64
{return new Go_runtime_fdiv64(gr,_bds, p_f, p_g);
}
public function run():Go_runtime_fdiv64 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1647,0);
this.setPH(1648);
_SF1=Go_runtime_funpack64.call(this._goroutine,[],p_f);
_Next = -1;
return this;
case -1:
this.setLatest(1648,-1);
_t0=_SF1.res();
 // _t0 = funpack64(f) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:289:33
this.SubFn0();
this.setPH(1649);
_SF2=Go_runtime_funpack64.call(this._goroutine,[],p_g);
_Next = -2;
return this;
case -2:
this.setLatest(1649,-2);
_t6=_SF2.res();
 // _t6 = funpack64(g) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:290:33
this.SubFn1();
_Phi=0;
case 1: // switch.body
this.setLatest(1649,1);
this.setPH(1654);
_res= GOint64.make(0x7ff00000,0x1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 9218868437227405313:uint64 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:295:3

case 2: // switch.body
this.setLatest(1654,2);
this.setPH(1657);
_res= GOint64.make(0x7ff00000,0x1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 9218868437227405313:uint64 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:298:3

case 3: // switch.next
this.setLatest(1657,3);
this.SubFn2();
_Phi=3;
case 4: // binop.rhs
this.setLatest(1657,4);
this.SubFn3();
_Phi=4;
case 5: // binop.done
this.setLatest(1657,5);
this.setPH(1653);
_t12=((_Phi==0)?true:(_Phi==4)?_t11:false); // _t12 = phi [0.entry: true:bool, 4.binop.rhs: t11] #|| *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:294:10
this.SubFn4();
_Phi=5;
case 6: // switch.body
this.setLatest(1653,6);
this.setPH(1660);
_res= GOint64.make(0x7ff00000,0x1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 9218868437227405313:uint64 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:301:3

case 7: // switch.next
this.setLatest(1660,7);
this.SubFn5();
_Phi=7;
case 8: // binop.rhs
this.setLatest(1660,8);
this.SubFn6();
_Phi=8;
case 9: // binop.done
this.setLatest(1660,9);
this.setPH(1656);
_t13=((_Phi==3)?false:(_Phi==8)?_t10:false); // _t13 = phi [3.switch.next: false:bool, 8.binop.rhs: t10] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:297:10
this.SubFn7();
_Phi=9;
case 10: // switch.body
this.setLatest(1656,10);
this.SubFn8();
this.setPH(1663);
_res= _t15;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t15 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:304:3

case 11: // switch.next
this.setLatest(1663,11);
this.SubFn9();
_Phi=11;
case 12: // binop.rhs
this.setLatest(1663,12);
this.SubFn10();
_Phi=12;
case 13: // binop.done
this.setLatest(1663,13);
this.setPH(1659);
_t17=((_Phi==7)?false:(_Phi==15)?false:(_Phi==14)?false:(_Phi==12)?_t16:false); // _t17 = phi [7.switch.next: false:bool, 15.cond.true: false:bool, 14.cond.true: false:bool, 12.binop.rhs: t16] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:300:29
this.SubFn11();
_Phi=13;
case 14: // cond.true
this.setLatest(1659,14);
this.SubFn12();
_Phi=14;
case 15: // cond.true
this.setLatest(1659,15);
this.SubFn13();
_Phi=15;
case 16: // switch.body
this.setLatest(1659,16);
this.SubFn14();
this.setPH(1666);
_res= _t20;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t20 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:307:3

case 17: // switch.next
this.setLatest(1666,17);
this.SubFn15();
_Phi=17;
case 18: // switch.next
this.setLatest(1666,18);
this.SubFn16();
_Phi=18;
case 19: // binop.rhs
this.setLatest(1666,19);
this.SubFn17();
_Phi=19;
case 20: // binop.done
this.setLatest(1666,20);
this.setPH(1662);
_t22=((_Phi==17)?false:(_Phi==19)?_t21:false); // _t22 = phi [17.switch.next: false:bool, 19.binop.rhs: t21] #&& *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:303:15
this.SubFn18();
_Phi=20;
case 21: // switch.next
this.setLatest(1662,21);
this.SubFn19();
_Phi=21;
case 22: // switch.next
this.setLatest(1662,22);
this.SubFn20();
this.setPH(1672);
_SF3=Go_runtime_divlu.call(this._goroutine,[],_t25,_t26,_t8);
_Next = -3;
return this;
case -3:
this.setLatest(1672,-3);
_t27=_SF3.res();
 // _t27 = divlu(t25, t26, t8) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:313:15
this.SubFn21();
this.setPH(1673);
_SF4=Go_runtime_fpack64.call(this._goroutine,[],_t30,_t28,_t32,_t29);
_Next = -4;
return this;
case -4:
this.setLatest(1673,-4);
_t33=_SF4.res();
 // _t33 = fpack64(t30, t28, t32, t29) *ssa.Call @ /usr/local/go/src/pkg/runtime/softfloat64.go:314:16
_res= _t33;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t33 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:314:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
_t3=_t0.r2; // _t3 = extract t0 #2 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
_t4=_t0.r3; // _t4 = extract t0 #3 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
_t5=_t0.r4; // _t5 = extract t0 #4 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
}// end SubFn0
private inline  function SubFn1():Void {
_t7=_t6.r0; // _t7 = extract t6 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
_t8=_t6.r1; // _t8 = extract t6 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
_t9=_t6.r2; // _t9 = extract t6 #2 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
_t10=_t6.r3; // _t10 = extract t6 #3 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
_t11=_t6.r4; // _t11 = extract t6 #4 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
_Next=_t5 ? 5 : 4; // if t5 goto 5.binop.done else 4.binop.rhs *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
}// end SubFn1
private inline  function SubFn2():Void {
_Next=_t4 ? 8 : 9; // if t4 goto 8.binop.rhs else 9.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
}// end SubFn2
private inline  function SubFn3():Void {
_Next=5; // jump 5.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
}// end SubFn3
private inline  function SubFn4():Void {
_Next=_t12 ? 1 : 3; // if t12 goto 1.switch.body else 3.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
}// end SubFn4
private inline  function SubFn5():Void {
_Next=_t4 ? 13 : 15; // if t4 goto 13.binop.done else 15.cond.true *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
}// end SubFn5
private inline  function SubFn6():Void {
_Next=9; // jump 9.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
}// end SubFn6
private inline  function SubFn7():Void {
_Next=_t13 ? 2 : 7; // if t13 goto 2.switch.body else 7.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:314:2
}// end SubFn7
private inline  function SubFn8():Void {
var _t14:GOint64;
this.setPH(1663);
_t14=Force.toUint64(GOint64.xor(_t1,_t7)); // _t14 = t1 ^ t7 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:304:13
_t15=Force.toUint64(GOint64.xor(_t14,GOint64.make(0x7ff00000,0x0))); // _t15 = t14 ^ 9218868437227405312:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:304:18
}// end SubFn8
private inline  function SubFn9():Void {
_Next=_t4 ? 10 : 17; // if t4 goto 10.switch.body else 17.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:304:18
}// end SubFn9
private inline  function SubFn10():Void {
this.setPH(1659);
_t16=(GOint64.ucompare(_t8,GOint64.make(0x0,0x0))==0); // _t16 = t8 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:300:35
_Next=13; // jump 13.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:300:35
}// end SubFn10
private inline  function SubFn11():Void {
_Next=_t17 ? 6 : 11; // if t17 goto 6.switch.body else 11.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:300:35
}// end SubFn11
private inline  function SubFn12():Void {
var _t18:Bool;
_t18=(GOint64.ucompare(_t2,GOint64.make(0x0,0x0))==0); // _t18 = t2 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:300:24
_Next=_t18 ? 12 : 13; // if t18 goto 12.binop.rhs else 13.binop.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:300:24
}// end SubFn12
private inline  function SubFn13():Void {
_Next=_t10 ? 13 : 14; // if t10 goto 13.binop.done else 14.cond.true *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:300:24
}// end SubFn13
private inline  function SubFn14():Void {
var _t19:GOint64;
this.setPH(1666);
_t19=Force.toUint64(GOint64.xor(_t1,_t7)); // _t19 = t1 ^ t7 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:307:13
_t20=Force.toUint64(GOint64.xor(_t19,GOint64.make(0x0,0x0))); // _t20 = t19 ^ 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:307:18
}// end SubFn14
private inline  function SubFn15():Void {
_Next=_t10 ? 20 : 19; // if t10 goto 20.binop.done else 19.binop.rhs *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:307:18
}// end SubFn15
private inline  function SubFn16():Void {
_Next=_t10 ? 16 : 21; // if t10 goto 16.switch.body else 21.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:307:18
}// end SubFn16
private inline  function SubFn17():Void {
this.setPH(1662);
_t21=(GOint64.ucompare(_t8,GOint64.make(0x0,0x0))==0); // _t21 = t8 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:303:21
_Next=20; // jump 20.binop.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:303:21
}// end SubFn17
private inline  function SubFn18():Void {
_Next=_t22 ? 10 : 18; // if t22 goto 10.switch.body else 18.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:303:21
}// end SubFn18
private inline  function SubFn19():Void {
var _t23:Bool;
this.setPH(1665);
_t23=(GOint64.ucompare(_t2,GOint64.make(0x0,0x0))==0); // _t23 = t2 == 0:uint64 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:306:14
_Next=_t23 ? 16 : 22; // if t23 goto 16.switch.body else 22.switch.next *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:306:14
}// end SubFn19
private inline  function SubFn20():Void {
var _t24:Int;
this.setPH(1672);
_t24=(64-54); // _t24 = 64:uint - 54:uint *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:313:23
_t25=Force.toUint64(GOint64.ushr(_t2,_t24)); // _t25 = t2 >> t24 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:313:18
_t26=Force.toUint64(GOint64.shl(_t2,54)); // _t26 = t2 << 54:uint *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:313:34
}// end SubFn20
private inline  function SubFn21():Void {
var _t31:Int;
_t28=_t27.r0; // _t28 = extract t27 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:313:34
_t29=_t27.r1; // _t29 = extract t27 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/softfloat64.go:313:34
this.setPH(1673);
_t30=Force.toUint64(GOint64.xor(_t1,_t7)); // _t30 = t1 ^ t7 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:314:19
_t31=(_t3-_t9); // _t31 = t3 - t9 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:314:29
_t32=(_t31-2); // _t32 = t31 - 2:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:314:32
}// end SubFn21
}
#if js @:expose("Go__star_runtime_dot_Func_FileLine") #end class Go__star_runtime_dot_Func_FileLine extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/extern.go:111:16
var p_f:Pointer;
var p_pc:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_f : Pointer, p_pc : Dynamic) {
super(gr,1002,"Go__star_runtime_dot_Func_FileLine");
this._bds=_bds;
this.p_f=p_f;
this.p_pc=p_pc;
Scheduler.push(gr,this);
}
var _res:{r0:String, r1:Int};
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:{r0:String,r1:Int}=null;
var _t1:String="";
var _t2:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_f : Pointer, p_pc : Dynamic) : {r0:String, r1:Int} {
if(!Go.doneInit) Go.init();
var _sf=new Go__star_runtime_dot_Func_FileLine(0,[], p_f, p_pc).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_f : Pointer, p_pc : Dynamic) : {r0:String, r1:Int} {
var _sf=new Go__star_runtime_dot_Func_FileLine(_gr,[], p_f, p_pc).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_f : Pointer, p_pc : Dynamic) : Go__star_runtime_dot_Func_FileLine
{return new Go__star_runtime_dot_Func_FileLine(gr,_bds, p_f, p_pc);
}
public function run():Go__star_runtime_dot_Func_FileLine {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1002,0);
this.setPH(1003);
_SF1=Go_runtime_funcline_go.call(this._goroutine,[],p_f,p_pc);
_Next = -1;
return this;
case -1:
this.setLatest(1003,-1);
_t0=_SF1.res();
 // _t0 = funcline_go(f, pc) *ssa.Call @ /usr/local/go/src/pkg/runtime/extern.go:112:20
this.SubFn0();
_res= {r0:_t1,r1:_t2};
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t1, t2 *ssa.Return @ /usr/local/go/src/pkg/runtime/extern.go:112:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t1=_t0.r0; // _t1 = extract t0 #0 *ssa.Extract near /usr/local/go/src/pkg/runtime/extern.go:112:2
_t2=_t0.r1; // _t2 = extract t0 #1 *ssa.Extract near /usr/local/go/src/pkg/runtime/extern.go:112:2
}// end SubFn0
}
#if js @:expose("Go_error_Error") #end class Go_error_Error extends StackFrameBasis implements StackFrame { 
var p_recv:Interface;
public function new(gr:Int,_bds:Array<Dynamic>, p_recv : Interface) {
super(gr,1003,"Go_error_Error");
this._bds=_bds;
this.p_recv=p_recv;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _SF1:StackFrame;
var _t0:String="";
var _Next:Int=0;
public static inline function callFromHaxe( p_recv : Interface) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_error_Error(0,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_recv : Interface) : String {
var _sf=new Go_error_Error(_gr,[], p_recv).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_recv : Interface) : Go_error_Error
{return new Go_error_Error(gr,_bds, p_recv);
}
public function run():Go_error_Error {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1003,0);
_SF1=Interface.invoke(p_recv,"Error",[this._goroutine,[],p_recv.val]);_Next = -1;
return this;
case -1:
this.setLatest(1003,-1);
_t0=_SF1.res();
 // _t0 = invoke recv.Error() *ssa.Call near /usr/local/go/src/pkg/runtime/extern.go:112:2
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return near /usr/local/go/src/pkg/runtime/extern.go:112:2

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_runtime_funcline_go extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:23:6
var p_arg0:Pointer;
var p_arg1:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer, p_arg1 : Dynamic) {
super(gr,440,"Go_runtime_funcline_go");
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
var _sf=new Go_runtime_funcline_go(0,[], p_arg0, p_arg1).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_arg0 : Pointer, p_arg1 : Dynamic) : {r0:String, r1:Int} {
var _sf=new Go_runtime_funcline_go(_gr,[], p_arg0, p_arg1).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer, p_arg1 : Dynamic) : Go_runtime_funcline_go
{return new Go_runtime_funcline_go(gr,_bds, p_arg0, p_arg1);
}
public function run():Go_runtime_funcline_go {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(440,0);
this.SubFn0();
this.setPH(441);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(441,-1);
 // panic t0 *ssa.Panic @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:24:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"runtime.funcline_go() not yet implemented"); // _t0 = make interface{} <- string ("runtime.funcline_...":string) *ssa.MakeInterface near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:24:7
}// end SubFn0
}
#if js @:expose("Go_tardisgolib_Host") #end class Go_tardisgolib_Host extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:15:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,478,"Go_tardisgolib_Host");
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
this.setLatest(478,0);
_res= "go";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "go":string *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:15:22

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_tardisgolib_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,478,"Go_tardisgolib_init");
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
this.setLatest(478,0);
this.SubFn0();

case 1: // init.start
this.setLatest(478,1);
this.SubFn1();

case 2: // init.done
this.setLatest(478,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:15:22

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.tardisgolib_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:15:22
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:15:22
}// end SubFn0
private inline  function SubFn1():Void {
Go.tardisgolib_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:15:22
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:15:22
}// end SubFn1
}
#if (!php) private #end class Go_runtime_cstringToGo extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:38:6
var p_arg0:Dynamic;
public function new(gr:Int,_bds:Array<Dynamic>, p_arg0 : Dynamic) {
super(gr,455,"Go_runtime_cstringToGo");
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
var _sf=new Go_runtime_cstringToGo(0,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_arg0 : Dynamic) : String {
var _sf=new Go_runtime_cstringToGo(_gr,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_arg0 : Dynamic) : Go_runtime_cstringToGo
{return new Go_runtime_cstringToGo(gr,_bds, p_arg0);
}
public function run():Go_runtime_cstringToGo {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(455,0);
this.SubFn0();
this.setPH(456);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(456,-1);
 // panic t0 *ssa.Panic @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:39:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"runtime.cstringToGo() not yet implemented"); // _t0 = make interface{} <- string ("runtime.cstringTo...":string) *ssa.MakeInterface near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:39:7
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_UTF16toRunes") #end class Go_haxegoruntime_UTF16toRunes extends StackFrameBasis implements StackFrame {  // langgoruntime.go:35:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,2858,"Go_haxegoruntime_UTF16toRunes");
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
this.setLatest(2858,0);
this.setPH(2859);
_SF1=Go_utf16_Decode.call(this._goroutine,[],p_s);
_Next = -1;
return this;
case -1:
this.setLatest(2859,-1);
_t0=_SF1.res();
 // _t0 = unicode/utf16.Decode(s) *ssa.Call @ langgoruntime.go:36:21
_res= _t0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t0 *ssa.Return @ langgoruntime.go:36:2

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_atomic_CompareAndSwapUint64") #end class Go_atomic_CompareAndSwapUint64 extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:79:6
var p_addr:Pointer;
var p_old:GOint64;
var p_new:GOint64;
public function new(gr:Int,_bds:Array<Dynamic>, p_addr : Pointer, p_old : GOint64, p_new : GOint64) {
super(gr,665,"Go_atomic_CompareAndSwapUint64");
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
this.setLatest(665,0);
this.SubFn0();

case 1: // if.then
this.setLatest(665,1);
this.SubFn1();
this.setPH(668);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:82:3

case 2: // if.done
this.setLatest(668,2);
this.setPH(670);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:84:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:GOint64;
var _t1:Bool;
this.setPH(666);
_t0=p_addr.load(); // _t0 = *addr *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:80:5
_t1=(GOint64.ucompare(_t0,p_old)==0); // _t1 = t0 == old *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:80:11
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:80:11
}// end SubFn0
private inline  function SubFn1():Void {
this.setPH(667);
p_addr.store(p_new); // *addr = new *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:81:3
}// end SubFn1
}
#if (!php) private #end class Go_runtime_init_36_1 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/mem.go:65:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1317,"Go_runtime_init_36_1");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Dynamic=null;
var _t1:Bool=false;
var _t2:Dynamic=null;
var _t4:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_init_36_1(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_runtime_init_36_1(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_runtime_init_36_1
{return new Go_runtime_init_36_1(gr,_bds);
}
public function run():Go_runtime_init_36_1 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1317,0);
this.SubFn0();

case 1: // if.then
this.setLatest(1317,1);
this.SubFn1();
this.setPH(1320);
Scheduler.panic(this._goroutine,_t4);_Next = -1;
return this;
case -1:
this.setLatest(1320,-1);
 // panic t4 *ssa.Panic @ /usr/local/go/src/pkg/runtime/mem.go:68:8

case 2: // if.done
this.setLatest(1320,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/mem.go:68:8

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Dynamic;
var _t1:Bool;
_t0=Go.runtime_sizeof_C_MStats.load(); // _t0 = *sizeof_C_MStats *ssa.UnOp near /usr/local/go/src/pkg/runtime/mem.go:68:8
this.setPH(1318);
_t1=(Force.uintCompare((_t0|0),(3712|0))!=0); // _t1 = t0 != 3712:uintptr *ssa.BinOp @ /usr/local/go/src/pkg/runtime/mem.go:66:21
_Next=_t1 ? 1 : 2; // if t1 goto 1.if.then else 2.if.done *ssa.If near /usr/local/go/src/pkg/runtime/mem.go:66:21
}// end SubFn0
private inline  function SubFn1():Void {
var _t2:Dynamic;
_t2=Go.runtime_sizeof_C_MStats.load(); // _t2 = *sizeof_C_MStats *ssa.UnOp near /usr/local/go/src/pkg/runtime/mem.go:66:21
this.setPH(1319);
trace(Go.CPos(1319),_t2,3712); // _t3 = println(t2, 3712:uintptr) *ssa.Call @ /usr/local/go/src/pkg/runtime/mem.go:67:10 [REGISTER VALUE UN-USED]
_t4=new Interface(0,"MStats vs MemStatsType size mismatch"); // _t4 = make interface{} <- string ("MStats vs MemStat...":string) *ssa.MakeInterface near /usr/local/go/src/pkg/runtime/mem.go:67:10
}// end SubFn1
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
#if (!php) private #end class Go_runtime_funcname_go extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:27:6
var p_arg0:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer) {
super(gr,444,"Go_runtime_funcname_go");
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
var _sf=new Go_runtime_funcname_go(0,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_arg0 : Pointer) : String {
var _sf=new Go_runtime_funcname_go(_gr,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer) : Go_runtime_funcname_go
{return new Go_runtime_funcname_go(gr,_bds, p_arg0);
}
public function run():Go_runtime_funcname_go {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(444,0);
this.SubFn0();
this.setPH(445);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(445,-1);
 // panic t0 *ssa.Panic @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:28:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"runtime.funcname_go() not yet implemented"); // _t0 = make interface{} <- string ("runtime.funcname_...":string) *ssa.MakeInterface near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:28:7
}// end SubFn0
}
#if (!php) private #end class Go_haxegoruntime_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,206,"Go_haxegoruntime_init");
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
this.setLatest(206,0);
this.SubFn0();

case 1: // init.start
this.setLatest(206,1);
this.SubFn1();
Go_utf16_init.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(206,-1);
 // _t1 = unicode/utf16.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:28:7 [REGISTER VALUE UN-USED]
Go_utf8_init.call(this._goroutine,[]);
_Next = -2;
return this;
case -2:
this.setLatest(206,-2);
 // _t2 = unicode/utf8.init() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:28:7 [REGISTER VALUE UN-USED]
Go_haxegoruntime_init_36_1.call(this._goroutine,[]);
_Next = -3;
return this;
case -3:
this.setLatest(206,-3);
 // _t3 = init$1() *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:28:7 [REGISTER VALUE UN-USED]
this.SubFn2();

case 2: // init.done
this.setLatest(206,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:28:7

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.haxegoruntime_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:28:7
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:28:7
}// end SubFn0
private inline  function SubFn1():Void {
Go.haxegoruntime_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:28:7
}// end SubFn1
private inline  function SubFn2():Void {
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:28:7
}// end SubFn2
}
#if js @:expose("Go_strings_IndexByte") #end class Go_strings_IndexByte extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:14:6
var p_s:String;
var p_c:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : String, p_c : Int) {
super(gr,519,"Go_strings_IndexByte");
this._bds=_bds;
this.p_s=p_s;
this.p_c=p_c;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Slice=null;
var _t1:Pointer=null;
var _t2:Int=0;
var _t3:Bool=false;
var _t4:Int=0;
var _t5:Int=0;
var _t6:Bool=false;
var _t7:Int=0;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : String, p_c : Int) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_strings_IndexByte(0,[], p_s, p_c).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : String, p_c : Int) : Int {
var _sf=new Go_strings_IndexByte(_gr,[], p_s, p_c).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : String, p_c : Int) : Go_strings_IndexByte
{return new Go_strings_IndexByte(gr,_bds, p_s, p_c);
}
public function run():Go_strings_IndexByte {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(519,0);
this.SubFn0();
_Phi=0;
case 1: // for.body
this.setLatest(519,1);
this.SubFn1();
_Phi=1;
case 2: // for.done
this.setLatest(519,2);
this.setPH(526);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:21:2

case 3: // for.loop
this.setLatest(526,3);
this.setPH(521);
_t4=((_Phi==0)?0:(_Phi==5)?_t7:0); // _t4 = phi [0.entry: 0:int, 5.if.done: t7] #i *ssa.Phi @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:16:6
this.SubFn2();
_Phi=3;
case 4: // if.then
this.setLatest(521,4);
this.setPH(523);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:18:4

case 5: // if.done
this.setLatest(523,5);
this.SubFn3();
_Phi=5;
default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
this.setPH(520);
_t0=Force.toUTF8slice(this._goroutine,p_s); // _t0 = convert []byte <- string (s) *ssa.Convert @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:15:14
_Next=3; // jump 3.for.loop *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:15:14
}// end SubFn0
private inline  function SubFn1():Void {
var _t1:Pointer;
var _t2:Int;
var _t3:Bool;
this.setPH(522);
if((_t4<0)||(_t4>=_t0.len())) Scheduler.ioor(); // _t1 = &t0[t4] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:17:8 [POINTER]
_t1=_t0.addr(_t4);  // _t1 = &t0[t4] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:17:8 [POINTER]
_t2=(_t1.load()|0); // _t2 = *t1 *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:17:8
_t3=(Force.uintCompare(_t2,p_c)==0); // _t3 = t2 == c *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:17:12
_Next=_t3 ? 4 : 5; // if t3 goto 4.if.then else 5.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:17:12
}// end SubFn1
private inline  function SubFn2():Void {
var _t5:Int;
var _t6:Bool;
this.setPH(521);
_t5=({var _v=_t0;_v==null?0:_v.len();}); // _t5 = len(t0) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:16:21
_t6=(_t4<_t5); // _t6 = t4 < t5 *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:16:16
_Next=_t6 ? 1 : 2; // if t6 goto 1.for.body else 2.for.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:16:16
}// end SubFn2
private inline  function SubFn3():Void {
_t7=(_t4+1); // _t7 = t4 + 1:int *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:16:16
_Next=3; // jump 3.for.loop *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:16:16
}// end SubFn3
}
#if js @:expose("Go_tardisgolib_Platform") #end class Go_tardisgolib_Platform extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:19:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,482,"Go_tardisgolib_Platform");
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
this.setLatest(482,0);
_res= "go";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "go":string *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:19:26

default: Scheduler.bbi();}}}
}
#if js @:expose("Go_tardisgolib_CPos") #end class Go_tardisgolib_CPos extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:22:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,485,"Go_tardisgolib_CPos");
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
this.setLatest(485,0);
_res= "<<go code pos>>";
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return "<<go code pos>>":string *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:22:22

default: Scheduler.bbi();}}}
}
#if (!php) private #end class Go_runtime_getgoroot extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:43:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,460,"Go_runtime_getgoroot");
this._bds=_bds;
Scheduler.push(gr,this);
}
var _res:String;
public inline function res():Dynamic {return _res;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( ) : String {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_getgoroot(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr) : String {
var _sf=new Go_runtime_getgoroot(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_runtime_getgoroot
{return new Go_runtime_getgoroot(gr,_bds);
}
public function run():Go_runtime_getgoroot {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(460,0);
this.SubFn0();
this.setPH(461);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(461,-1);
 // panic t0 *ssa.Panic @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:44:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"runtime.getgoroot() not yet implemented"); // _t0 = make interface{} <- string ("runtime.getgoroot...":string) *ssa.MakeInterface near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:44:7
}// end SubFn0
}
#if (!php) private #end class Go_bytes_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,461,"Go_bytes_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_bytes_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_bytes_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_bytes_init
{return new Go_bytes_init(gr,_bds);
}
public function run():Go_bytes_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(461,0);
this.SubFn0();

case 1: // init.start
this.setLatest(461,1);
this.SubFn1();

case 2: // init.done
this.setLatest(461,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:44:7

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.bytes_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:44:7
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:44:7
}// end SubFn0
private inline  function SubFn1():Void {
Go.bytes_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:44:7
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:44:7
}// end SubFn1
}
#if js @:expose("Go_bytes_IndexByte") #end class Go_bytes_IndexByte extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:16:6
var p_s:Slice;
var p_c:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice, p_c : Int) {
super(gr,304,"Go_bytes_IndexByte");
this._bds=_bds;
this.p_s=p_s;
this.p_c=p_c;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Int=0;
var _t1:Int=0;
var _t2:Int=0;
var _t3:Bool=false;
var _t4:Pointer=null;
var _t5:Int=0;
var _t6:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : Slice, p_c : Int) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_bytes_IndexByte(0,[], p_s, p_c).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_s : Slice, p_c : Int) : Int {
var _sf=new Go_bytes_IndexByte(_gr,[], p_s, p_c).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : Slice, p_c : Int) : Go_bytes_IndexByte
{return new Go_bytes_IndexByte(gr,_bds, p_s, p_c);
}
public function run():Go_bytes_IndexByte {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(304,0);
this.SubFn0();
_Phi=0;
case 1: // rangeindex.loop
this.setLatest(304,1);
_t1=((_Phi==0)?(-1):(_Phi==2)?_t2:0); // _t1 = phi [0.entry: -1:int, 2.rangeindex.body: t2] *ssa.Phi near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:44:7
this.SubFn1();
_Phi=1;
case 2: // rangeindex.body
this.setLatest(304,2);
this.SubFn2();
_Phi=2;
case 3: // rangeindex.done
this.setLatest(304,3);
this.setPH(310);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:22:2

case 4: // if.then
this.setLatest(310,4);
this.setPH(307);
_res= _t2;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t2 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:19:4

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=({var _v=p_s;_v==null?0:_v.len();}); // _t0 = len(s) *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:19:4
_Next=1; // jump 1.rangeindex.loop *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:19:4
}// end SubFn0
private inline  function SubFn1():Void {
var _t3:Bool;
_t2=(_t1+1); // _t2 = t1 + 1:int *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:19:4
_t3=(_t2<_t0); // _t3 = t2 < t0 *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:19:4
_Next=_t3 ? 2 : 3; // if t3 goto 2.rangeindex.body else 3.rangeindex.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:19:4
}// end SubFn1
private inline  function SubFn2():Void {
var _t4:Pointer;
var _t5:Int;
var _t6:Bool;
this.setPH(306);
if((_t2<0)||(_t2>=p_s.len())) Scheduler.ioor(); // _t4 = &s[t2] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:18:7 [POINTER]
_t4=p_s.addr(_t2);  // _t4 = &s[t2] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:18:7 [POINTER]
_t5=(_t4.load()|0); // _t5 = *t4 *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:18:7
_t6=(Force.uintCompare(_t5,p_c)==0); // _t6 = t5 == c *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:18:11
_Next=_t6 ? 4 : 1; // if t6 goto 4.if.then else 1.rangeindex.loop *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:18:11
}// end SubFn2
}
#if (!php) private #end class Go_sync_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,306,"Go_sync_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_sync_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_sync_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_sync_init
{return new Go_sync_init(gr,_bds);
}
public function run():Go_sync_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(306,0);
this.SubFn0();

case 1: // init.start
this.setLatest(306,1);
this.SubFn1();

case 2: // init.done
this.setLatest(306,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:18:11

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.sync_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:18:11
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:18:11
}// end SubFn0
private inline  function SubFn1():Void {
Go.sync_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:18:11
_Next=2; // jump 2.init.done *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:18:11
}// end SubFn1
}
#if (!php) private #end class Go_sync_runtime_Semrelease extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:33:6
var p_s:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Pointer) {
super(gr,560,"Go_sync_runtime_Semrelease");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Int=0;
var _t1:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_sync_runtime_Semrelease(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_s : Pointer) : Void {
var _sf=new Go_sync_runtime_Semrelease(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : Pointer) : Go_sync_runtime_Semrelease
{return new Go_sync_runtime_Semrelease(gr,_bds, p_s);
}
public function run():Go_sync_runtime_Semrelease {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(560,0);
this.SubFn0();
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:18:11

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Int;
var _t1:Int;
this.setPH(561);
_t0=(p_s.load()|0); // _t0 = *s *ssa.UnOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:34:2
_t1=Force.toUint32((_t0+1)); // _t1 = t0 + 1:uint32 *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:34:2
p_s.store(_t1); // *s = t1 *ssa.Store @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:34:2
}// end SubFn0
}
#if (!php) private #end class Go_atomic_panic64 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/sync/atomic/doc.go:149:6
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,270,"Go_atomic_panic64");
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
this.setLatest(270,0);
this.SubFn0();
this.setPH(271);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(271,-1);
 // panic t0 *ssa.Panic @ /usr/local/go/src/pkg/sync/atomic/doc.go:150:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"sync/atomic: broken 64-bit atomic operations (buggy QEMU)"); // _t0 = make interface{} <- string ("sync/atomic: brok...":string) *ssa.MakeInterface near /usr/local/go/src/pkg/sync/atomic/doc.go:150:7
}// end SubFn0
}
#if (!php) private #end class Go_main_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,271,"Go_main_init");
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
this.setLatest(271,0);
this.SubFn0();

case 1: // init.start
this.setLatest(271,1);
this.SubFn1();
Go_atomic_init.call(this._goroutine,[]);
_Next = -1;
return this;
case -1:
this.setLatest(271,-1);
 // _t1 = sync/atomic.init() *ssa.Call near /usr/local/go/src/pkg/sync/atomic/doc.go:150:7 [REGISTER VALUE UN-USED]
Go_golibruntime_init.call(this._goroutine,[]);
_Next = -2;
return this;
case -2:
this.setLatest(271,-2);
 // _t2 = github.com/tardisgo/tardisgo/golibruntime.init() *ssa.Call near /usr/local/go/src/pkg/sync/atomic/doc.go:150:7 [REGISTER VALUE UN-USED]
Go_tardisgolib_init.call(this._goroutine,[]);
_Next = -3;
return this;
case -3:
this.setLatest(271,-3);
 // _t3 = github.com/tardisgo/tardisgo/tardisgolib.init() *ssa.Call near /usr/local/go/src/pkg/sync/atomic/doc.go:150:7 [REGISTER VALUE UN-USED]
this.SubFn2();

case 2: // init.done
this.setLatest(271,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/sync/atomic/doc.go:150:7

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.main_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /usr/local/go/src/pkg/sync/atomic/doc.go:150:7
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /usr/local/go/src/pkg/sync/atomic/doc.go:150:7
}// end SubFn0
private inline  function SubFn1():Void {
Go.main_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /usr/local/go/src/pkg/sync/atomic/doc.go:150:7
}// end SubFn1
private inline  function SubFn2():Void {
_Next=2; // jump 2.init.done *ssa.Jump near /usr/local/go/src/pkg/sync/atomic/doc.go:150:7
}// end SubFn2
}
#if js @:expose("Go_bytes_Compare") #end class Go_bytes_Compare extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:56:6
var p_a:Slice;
var p_b:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_a : Slice, p_b : Slice) {
super(gr,344,"Go_bytes_Compare");
this._bds=_bds;
this.p_a=p_a;
this.p_b=p_b;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Bool=false;
var _t1:Bool=false;
var _t2:Bool=false;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Int=0;
var _t6:Bool=false;
var _t7:Pointer=null;
var _t8:Int=0;
var _t9:Pointer=null;
var _t10:Int=0;
var _t11:Bool=false;
var _t12:Int=0;
var _t13:Int=0;
var _t14:Bool=false;
var _t15:Int=0;
var _t16:Int=0;
var _t17:Bool=false;
var _t18:Int=0;
var _t19:Bool=false;
var _t20:Pointer=null;
var _t21:Int=0;
var _t22:Pointer=null;
var _t23:Int=0;
var _t24:Bool=false;
var _t25:Int=0;
var _t26:Int=0;
var _t27:Int=0;
var _t28:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_a : Slice, p_b : Slice) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_bytes_Compare(0,[], p_a, p_b).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_a : Slice, p_b : Slice) : Int {
var _sf=new Go_bytes_Compare(_gr,[], p_a, p_b).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_a : Slice, p_b : Slice) : Go_bytes_Compare
{return new Go_bytes_Compare(gr,_bds, p_a, p_b);
}
public function run():Go_bytes_Compare {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(344,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(344,1);
this.SubFn1();
_Phi=1;
case 2: // if.done
this.setLatest(344,2);
this.SubFn2();
_Phi=2;
case 3: // if.then
this.setLatest(344,3);
this.setPH(347);
_res= 0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:59:4

case 4: // if.else
this.setLatest(347,4);
this.SubFn3();
_Phi=4;
case 5: // if.then
this.setLatest(347,5);
this.setPH(350);
_res= 0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:62:5

case 6: // if.else
this.setLatest(350,6);
this.setPH(352);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:64:5

case 7: // if.then
this.setLatest(352,7);
this.SubFn4();
_Phi=7;
case 8: // if.done
this.setLatest(352,8);
this.SubFn5();
_Phi=8;
case 9: // if.then
this.setLatest(352,9);
this.setPH(358);
_res= 0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:70:4

case 10: // if.else
this.setLatest(358,10);
this.setPH(360);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:72:4

case 11: // for.body
this.setLatest(360,11);
this.SubFn6();
_Phi=11;
case 12: // for.done
this.setLatest(360,12);
this.SubFn7();
_Phi=12;
case 13: // for.loop
this.setLatest(360,13);
this.setPH(363);
_t15=((_Phi==8)?0:(_Phi==18)?_t25:0); // _t15 = phi [8.if.done: 0:int, 18.if.done: t25] #i *ssa.Phi @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:75:2
this.SubFn8();
_Phi=13;
case 14: // cond.true
this.setLatest(363,14);
this.SubFn9();
_Phi=14;
case 15: // if.then
this.setLatest(363,15);
this.setPH(366);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:78:4

case 16: // if.done
this.setLatest(366,16);
this.SubFn10();
_Phi=16;
case 17: // if.then
this.setLatest(366,17);
this.setPH(369);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:81:4

case 18: // if.done
this.setLatest(369,18);
this.SubFn11();
_Phi=18;
case 19: // if.then
this.setLatest(369,19);
this.setPH(374);
_res= 0;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 0:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:86:3

case 20: // if.done
this.setLatest(374,20);
this.SubFn12();
_Phi=20;
case 21: // if.then
this.setLatest(374,21);
this.setPH(377);
_res= (-1);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return -1:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:89:3

case 22: // if.done
this.setLatest(377,22);
this.setPH(379);
_res= 1;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return 1:int *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:91:2

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(345);
_t0=(p_a==null); // _t0 = a == nil:[]byte *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:57:7
_Next=_t0 ? 1 : 2; // if t0 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:57:7
}// end SubFn0
private inline  function SubFn1():Void {
var _t1:Bool;
this.setPH(346);
_t1=(p_b==null); // _t1 = b == nil:[]byte *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:58:8
_Next=_t1 ? 3 : 4; // if t1 goto 3.if.then else 4.if.else *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:58:8
}// end SubFn1
private inline  function SubFn2():Void {
var _t2:Bool;
this.setPH(356);
_t2=(p_b==null); // _t2 = b == nil:[]byte *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:68:7
_Next=_t2 ? 7 : 8; // if t2 goto 7.if.then else 8.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:68:7
}// end SubFn2
private inline  function SubFn3():Void {
var _t3:Int;
var _t4:Bool;
this.setPH(349);
_t3=({var _v=p_b;_v==null?0:_v.len();}); // _t3 = len(b) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:61:10
_t4=(_t3==0); // _t4 = t3 == 0:int *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:61:14
_Next=_t4 ? 5 : 6; // if t4 goto 5.if.then else 6.if.else *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:61:14
}// end SubFn3
private inline  function SubFn4():Void {
var _t5:Int;
var _t6:Bool;
this.setPH(357);
_t5=({var _v=p_a;_v==null?0:_v.len();}); // _t5 = len(a) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:69:9
_t6=(_t5==0); // _t6 = t5 == 0:int *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:69:13
_Next=_t6 ? 9 : 10; // if t6 goto 9.if.then else 10.if.else *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:69:13
}// end SubFn4
private inline  function SubFn5():Void {
_Next=13; // jump 13.for.loop *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:69:13
}// end SubFn5
private inline  function SubFn6():Void {
var _t7:Pointer;
var _t8:Int;
var _t9:Pointer;
var _t10:Int;
var _t11:Bool;
this.setPH(365);
if((_t15<0)||(_t15>=p_a.len())) Scheduler.ioor(); // _t7 = &a[t15] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:77:7 [POINTER]
_t7=p_a.addr(_t15);  // _t7 = &a[t15] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:77:7 [POINTER]
_t8=(_t7.load()|0); // _t8 = *t7 *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:77:7
if((_t15<0)||(_t15>=p_b.len())) Scheduler.ioor(); // _t9 = &b[t15] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:77:14 [POINTER]
_t9=p_b.addr(_t15);  // _t9 = &b[t15] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:77:14 [POINTER]
_t10=(_t9.load()|0); // _t10 = *t9 *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:77:14
_t11=(Force.uintCompare(_t8,_t10)<0); // _t11 = t8 < t10 *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:77:11
_Next=_t11 ? 15 : 16; // if t11 goto 15.if.then else 16.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:77:11
}// end SubFn6
private inline  function SubFn7():Void {
var _t12:Int;
var _t13:Int;
var _t14:Bool;
this.setPH(373);
_t12=({var _v=p_a;_v==null?0:_v.len();}); // _t12 = len(a) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:85:8
_t13=({var _v=p_b;_v==null?0:_v.len();}); // _t13 = len(b) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:85:18
_t14=(_t12==_t13); // _t14 = t12 == t13 *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:85:12
_Next=_t14 ? 19 : 20; // if t14 goto 19.if.then else 20.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:85:12
}// end SubFn7
private inline  function SubFn8():Void {
var _t16:Int;
var _t17:Bool;
this.setPH(364);
_t16=({var _v=p_a;_v==null?0:_v.len();}); // _t16 = len(a) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:76:14
_t17=(_t15<_t16); // _t17 = t15 < t16 *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:76:9
_Next=_t17 ? 14 : 12; // if t17 goto 14.cond.true else 12.for.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:76:9
}// end SubFn8
private inline  function SubFn9():Void {
var _t18:Int;
var _t19:Bool;
_t18=({var _v=p_b;_v==null?0:_v.len();}); // _t18 = len(b) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:76:30
_t19=(_t15<_t18); // _t19 = t15 < t18 *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:76:25
_Next=_t19 ? 11 : 12; // if t19 goto 11.for.body else 12.for.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:76:25
}// end SubFn9
private inline  function SubFn10():Void {
var _t20:Pointer;
var _t21:Int;
var _t22:Pointer;
var _t23:Int;
var _t24:Bool;
this.setPH(368);
if((_t15<0)||(_t15>=p_a.len())) Scheduler.ioor(); // _t20 = &a[t15] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:80:7 [POINTER]
_t20=p_a.addr(_t15);  // _t20 = &a[t15] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:80:7 [POINTER]
_t21=(_t20.load()|0); // _t21 = *t20 *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:80:7
if((_t15<0)||(_t15>=p_b.len())) Scheduler.ioor(); // _t22 = &b[t15] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:80:14 [POINTER]
_t22=p_b.addr(_t15);  // _t22 = &b[t15] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:80:14 [POINTER]
_t23=(_t22.load()|0); // _t23 = *t22 *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:80:14
_t24=(Force.uintCompare(_t21,_t23)>0); // _t24 = t21 > t23 *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:80:11
_Next=_t24 ? 17 : 18; // if t24 goto 17.if.then else 18.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:80:11
}// end SubFn10
private inline  function SubFn11():Void {
_t25=(_t15+1); // _t25 = t15 + 1:int *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:80:11
_Next=13; // jump 13.for.loop *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:80:11
}// end SubFn11
private inline  function SubFn12():Void {
var _t26:Int;
var _t27:Int;
var _t28:Bool;
this.setPH(376);
_t26=({var _v=p_a;_v==null?0:_v.len();}); // _t26 = len(a) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:88:8
_t27=({var _v=p_b;_v==null?0:_v.len();}); // _t27 = len(b) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:88:17
_t28=(_t26<_t27); // _t28 = t26 < t27 *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:88:12
_Next=_t28 ? 21 : 22; // if t28 goto 21.if.then else 22.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:88:12
}// end SubFn12
}
#if (!php) private #end class Go_runtime_fpack32 extends StackFrameBasis implements StackFrame {  // /usr/local/go/src/pkg/runtime/softfloat64.go:144:6
var p_sign:Int;
var p_mant:Int;
var p_exp:Int;
var p_trunc:Int;
public function new(gr:Int,_bds:Array<Dynamic>, p_sign : Int, p_mant : Int, p_exp : Int, p_trunc : Int) {
super(gr,1503,"Go_runtime_fpack32");
this._bds=_bds;
this.p_sign=p_sign;
this.p_mant=p_mant;
this.p_exp=p_exp;
this.p_trunc=p_trunc;
Scheduler.push(gr,this);
}
var _res:Int;
public inline function res():Dynamic {return _res;}
var _t0:Bool=false;
var _t1:Int=0;
var _t2:Int=0;
var _t3:Int=0;
var _t4:Int=0;
var _t5:Bool=false;
var _t6:Int=0;
var _t7:Int=0;
var _t8:Int=0;
var _t9:Int=0;
var _t10:Bool=false;
var _t11:Int=0;
var _t12:Int=0;
var _t13:Int=0;
var _t14:Bool=false;
var _t15:Int=0;
var _t16:Bool=false;
var _t17:Int=0;
var _t18:Int=0;
var _t19:Bool=false;
var _t20:Int=0;
var _t21:Bool=false;
var _t22:Int=0;
var _t23:Int=0;
var _t24:Int=0;
var _t25:Int=0;
var _t26:Bool=false;
var _t27:Int=0;
var _t28:Bool=false;
var _t29:Int=0;
var _t30:Int=0;
var _t31:Int=0;
var _t32:Bool=false;
var _t33:Bool=false;
var _t34:Int=0;
var _t35:Int=0;
var _t36:Int=0;
var _t37:Int=0;
var _t38:Int=0;
var _t39:Int=0;
var _t40:Int=0;
var _t41:Int=0;
var _t42:Int=0;
var _t43:Int=0;
var _t44:Int=0;
var _t45:Int=0;
var _t46:Int=0;
var _t47:Int=0;
var _t48:Bool=false;
var _t49:Int=0;
var _t50:Int=0;
var _t51:Int=0;
var _t52:Bool=false;
var _t53:Int=0;
var _t54:Int=0;
var _t55:Int=0;
var _t56:Int=0;
var _t57:Bool=false;
var _t58:Bool=false;
var _t59:Int=0;
var _t60:Bool=false;
var _t61:Int=0;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_sign : Int, p_mant : Int, p_exp : Int, p_trunc : Int) : Int {
if(!Go.doneInit) Go.init();
var _sf=new Go_runtime_fpack32(0,[], p_sign, p_mant, p_exp, p_trunc).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_sign : Int, p_mant : Int, p_exp : Int, p_trunc : Int) : Int {
var _sf=new Go_runtime_fpack32(_gr,[], p_sign, p_mant, p_exp, p_trunc).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_sign : Int, p_mant : Int, p_exp : Int, p_trunc : Int) : Go_runtime_fpack32
{return new Go_runtime_fpack32(gr,_bds, p_sign, p_mant, p_exp, p_trunc);
}
public function run():Go_runtime_fpack32 {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1503,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(1503,1);
this.setPH(1506);
_res= p_sign;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return sign *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:147:3

case 2: // for.body
this.setLatest(1506,2);
this.SubFn1();
_Phi=2;
case 3: // for.loop
this.setLatest(1506,3);
this.setPH(1503);
_t3=((_Phi==0)?p_mant:(_Phi==2)?_t1:0); // _t3 = phi [0.entry: mant, 2.for.body: t1] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:20
_t4=((_Phi==0)?p_exp:(_Phi==2)?_t2:0); // _t4 = phi [0.entry: exp, 2.for.body: t2] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:33
this.SubFn2();
_Phi=3;
case 4: // for.body
this.setLatest(1503,4);
this.SubFn3();
_Phi=4;
case 5: // for.done
this.setLatest(1503,5);
this.SubFn4();
_Phi=5;
case 6: // for.loop
this.setLatest(1503,6);
_t11=((_Phi==3)?_t3:(_Phi==4)?_t8:0); // _t11 = phi [3.for.loop: t3, 4.for.body: t8] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:20
_t12=((_Phi==3)?_t4:(_Phi==4)?_t9:0); // _t12 = phi [3.for.loop: t4, 4.for.body: t9] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:33
_t13=((_Phi==3)?p_trunc:(_Phi==4)?_t7:0); // _t13 = phi [3.for.loop: trunc, 4.for.body: t7] #trunc *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:42
this.SubFn5();
_Phi=6;
case 7: // if.then
this.setLatest(1503,7);
this.SubFn6();
_Phi=7;
case 8: // if.done
this.setLatest(1503,8);
_t17=((_Phi==5)?_t11:(_Phi==10)?_t24:0); // _t17 = phi [5.for.done: t11, 10.if.done: t24] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:20
_t18=((_Phi==5)?_t12:(_Phi==10)?_t25:0); // _t18 = phi [5.for.done: t12, 10.if.done: t25] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:33
this.SubFn7();
_Phi=8;
case 9: // if.then
this.setLatest(1503,9);
this.SubFn8();
_Phi=9;
case 10: // if.done
this.setLatest(1503,10);
_t22=((_Phi==7)?_t11:(_Phi==12)?_t11:(_Phi==9)?_t20:(_Phi==13)?_t29:0); // _t22 = phi [7.if.then: t11, 12.cond.false: t11, 9.if.then: t20, 13.if.then: t29] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:20
_t23=((_Phi==7)?_t12:(_Phi==12)?_t12:(_Phi==9)?_t12:(_Phi==13)?_t30:0); // _t23 = phi [7.if.then: t12, 12.cond.false: t12, 9.if.then: t12, 13.if.then: t30] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:33
this.SubFn9();
_Phi=10;
case 11: // cond.true
this.setLatest(1503,11);
this.SubFn10();
_Phi=11;
case 12: // cond.false
this.setLatest(1503,12);
this.SubFn11();
_Phi=12;
case 13: // if.then
this.setLatest(1503,13);
this.SubFn12();
_Phi=13;
case 14: // if.then
this.setLatest(1503,14);
this.SubFn13();
this.setPH(1529);
_res= _t31;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t31 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:170:3

case 15: // if.done
this.setLatest(1529,15);
this.SubFn14();
_Phi=15;
case 16: // if.then
this.setLatest(1529,16);
this.SubFn15();
_Phi=16;
case 17: // if.done
this.setLatest(1529,17);
this.setPH(1503);
_t34=((_Phi==15)?_t17:(_Phi==24)?_t55:0); // _t34 = phi [15.if.done: t17, 24.if.done: t55] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:20
_t35=((_Phi==15)?_t18:(_Phi==24)?_t56:0); // _t35 = phi [15.if.done: t18, 24.if.done: t56] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:33
this.SubFn16();
this.setPH(1551);
_res= _t41;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t41 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:192:2

case 18: // if.then
this.setLatest(1551,18);
this.SubFn17();
this.setPH(1533);
_res= _t42;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t42 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:174:4

case 19: // if.done
this.setLatest(1533,19);
this.SubFn18();
_Phi=19;
case 20: // for.body
this.setLatest(1533,20);
this.SubFn19();
_Phi=20;
case 21: // for.done
this.setLatest(1533,21);
this.SubFn20();
_Phi=21;
case 22: // for.loop
this.setLatest(1533,22);
this.setPH(1503);
_t49=((_Phi==19)?p_mant:(_Phi==20)?_t45:0); // _t49 = phi [19.if.done: mant, 20.for.body: t45] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:20
_t50=((_Phi==19)?p_exp:(_Phi==20)?_t46:0); // _t50 = phi [19.if.done: exp, 20.for.body: t46] #exp *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:33
_t51=((_Phi==19)?p_trunc:(_Phi==20)?_t44:0); // _t51 = phi [19.if.done: trunc, 20.for.body: t44] #trunc *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:42
this.SubFn21();
_Phi=22;
case 23: // if.then
this.setLatest(1503,23);
this.SubFn22();
_Phi=23;
case 24: // if.done
this.setLatest(1503,24);
_t54=((_Phi==21)?_t49:(_Phi==26)?_t49:(_Phi==23)?_t53:0); // _t54 = phi [21.for.done: t49, 26.cond.false: t49, 23.if.then: t53] #mant *ssa.Phi @ /usr/local/go/src/pkg/runtime/softfloat64.go:144:20
this.SubFn23();
_Phi=24;
case 25: // cond.true
this.setLatest(1503,25);
this.SubFn24();
_Phi=25;
case 26: // cond.false
this.setLatest(1503,26);
this.SubFn25();
_Phi=26;
case 27: // if.then
this.setLatest(1503,27);
this.SubFn26();
this.setPH(1548);
_res= _t61;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t61 *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:189:4

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(1505);
_t0=(Force.uintCompare(p_mant,0)==0); // _t0 = mant == 0:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:146:10
_Next=_t0 ? 1 : 3; // if t0 goto 1.if.then else 3.for.loop *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:146:10
}// end SubFn0
private inline  function SubFn1():Void {
_t1=(_t3<<1); // _t1 = t3 << 1:uint32 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:146:10
_t2=(_t4-1); // _t2 = t4 - 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:146:10
_Next=3; // jump 3.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:146:10
}// end SubFn1
private inline  function SubFn2():Void {
var _t5:Bool;
this.setPH(1508);
_t5=(Force.uintCompare(_t3,8388608)<0); // _t5 = t3 < 8388608:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:149:11
_Next=_t5 ? 2 : 6; // if t5 goto 2.for.body else 6.for.loop *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:149:11
}// end SubFn2
private inline  function SubFn3():Void {
var _t6:Int;
this.setPH(1513);
_t6=Force.toUint32((_t11&1)); // _t6 = t11 & 1:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:154:17
_t7=Force.toUint32((_t13|_t6)); // _t7 = t13 | t6 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:154:17
_t8=(_t11>>1); // _t8 = t11 >> 1:uint32 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:154:17
_t9=(_t12+1); // _t9 = t12 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:154:17
_Next=6; // jump 6.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:154:17
}// end SubFn3
private inline  function SubFn4():Void {
var _t10:Bool;
this.setPH(1517);
_t10=(Force.uintCompare(_t11,16777216)>=0); // _t10 = t11 >= 16777216:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:158:10
_Next=_t10 ? 7 : 8; // if t10 goto 7.if.then else 8.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:158:10
}// end SubFn4
private inline  function SubFn5():Void {
var _t14:Bool;
this.setPH(1512);
_t14=(Force.uintCompare(_t11,33554432)>=0); // _t14 = t11 >= 33554432:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:153:11
_Next=_t14 ? 4 : 5; // if t14 goto 4.for.body else 5.for.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:153:11
}// end SubFn5
private inline  function SubFn6():Void {
var _t15:Int;
var _t16:Bool;
this.setPH(1518);
_t15=Force.toUint32((_t11&1)); // _t15 = t11 & 1:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:159:10
_t16=(Force.uintCompare(_t15,0)!=0); // _t16 = t15 != 0:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:159:13
_Next=_t16 ? 11 : 10; // if t16 goto 11.cond.true else 10.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:159:13
}// end SubFn6
private inline  function SubFn7():Void {
var _t19:Bool;
this.setPH(1528);
_t19=(_t18>=128); // _t19 = t18 >= 128:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:169:9
_Next=_t19 ? 14 : 15; // if t19 goto 14.if.then else 15.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:169:9
}// end SubFn7
private inline  function SubFn8():Void {
var _t21:Bool;
_t20=Force.toUint32((_t11+1)); // _t20 = t11 + 1:uint32 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:169:9
this.setPH(1520);
_t21=(Force.uintCompare(_t20,33554432)>=0); // _t21 = t20 >= 33554432:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:161:12
_Next=_t21 ? 13 : 10; // if t21 goto 13.if.then else 10.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:161:12
}// end SubFn8
private inline  function SubFn9():Void {
_t24=(_t22>>1); // _t24 = t22 >> 1:uint32 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:161:12
_t25=(_t23+1); // _t25 = t23 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:161:12
_Next=8; // jump 8.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:161:12
}// end SubFn9
private inline  function SubFn10():Void {
var _t26:Bool;
this.setPH(1518);
_t26=(Force.uintCompare(_t13,0)!=0); // _t26 = t13 != 0:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:159:28
_Next=_t26 ? 9 : 12; // if t26 goto 9.if.then else 12.cond.false *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:159:28
}// end SubFn10
private inline  function SubFn11():Void {
var _t27:Int;
var _t28:Bool;
_t27=Force.toUint32((_t11&2)); // _t27 = t11 & 2:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:159:40
_t28=(Force.uintCompare(_t27,0)!=0); // _t28 = t27 != 0:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:159:43
_Next=_t28 ? 9 : 10; // if t28 goto 9.if.then else 10.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:159:43
}// end SubFn11
private inline  function SubFn12():Void {
_t29=(_t20>>1); // _t29 = t20 >> 1:uint32 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:159:43
_t30=(_t12+1); // _t30 = t12 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:159:43
_Next=10; // jump 10.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:159:43
}// end SubFn12
private inline  function SubFn13():Void {
this.setPH(1529);
_t31=Force.toUint32((p_sign^2139095040)); // _t31 = sign ^ 2139095040:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:170:15
}// end SubFn13
private inline  function SubFn14():Void {
var _t32:Bool;
this.setPH(1531);
_t32=(_t18<(-126)); // _t32 = t18 < -126:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:172:9
_Next=_t32 ? 16 : 17; // if t32 goto 16.if.then else 17.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:172:9
}// end SubFn14
private inline  function SubFn15():Void {
var _t33:Bool;
this.setPH(1532);
_t33=(_t18<(-150)); // _t33 = t18 < -150:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:173:10
_Next=_t33 ? 18 : 19; // if t33 goto 18.if.then else 19.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:173:10
}// end SubFn15
private inline  function SubFn16():Void {
var _t36:Int;
var _t37:Int;
var _t38:Int;
var _t39:Int;
var _t40:Int;
this.setPH(1551);
_t36=(_t35-(-127)); // _t36 = t35 - -127:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:192:26
_t37=_t36; // _t37 = convert uint32 <- int (t36) *ssa.Convert @ /usr/local/go/src/pkg/runtime/softfloat64.go:192:22
_t38=(_t37<<23); // _t38 = t37 << 23:uint *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:192:34
_t39=Force.toUint32((p_sign|_t38)); // _t39 = sign | t38 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:192:14
_t40=Force.toUint32((_t34&8388607)); // _t40 = t34 & 8388607:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:192:53
_t41=Force.toUint32((_t39|_t40)); // _t41 = t39 | t40 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:192:47
}// end SubFn16
private inline  function SubFn17():Void {
this.setPH(1533);
_t42=Force.toUint32((p_sign|0)); // _t42 = sign | 0:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:174:16
}// end SubFn17
private inline  function SubFn18():Void {
_Next=22; // jump 22.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:174:16
}// end SubFn18
private inline  function SubFn19():Void {
var _t43:Int;
this.setPH(1538);
_t43=Force.toUint32((_t49&1)); // _t43 = t49 & 1:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:179:18
_t44=Force.toUint32((_t51|_t43)); // _t44 = t51 | t43 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:179:18
_t45=(_t49>>1); // _t45 = t49 >> 1:uint32 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:179:18
_t46=(_t50+1); // _t46 = t50 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:179:18
_Next=22; // jump 22.for.loop *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:179:18
}// end SubFn19
private inline  function SubFn20():Void {
var _t47:Int;
var _t48:Bool;
this.setPH(1542);
_t47=Force.toUint32((_t49&1)); // _t47 = t49 & 1:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:183:10
_t48=(Force.uintCompare(_t47,0)!=0); // _t48 = t47 != 0:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:183:13
_Next=_t48 ? 25 : 24; // if t48 goto 25.cond.true else 24.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:183:13
}// end SubFn20
private inline  function SubFn21():Void {
var _t52:Bool;
this.setPH(1537);
_t52=(_t50<(-127)); // _t52 = t50 < -127:int *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:178:11
_Next=_t52 ? 20 : 21; // if t52 goto 20.for.body else 21.for.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:178:11
}// end SubFn21
private inline  function SubFn22():Void {
_t53=Force.toUint32((_t49+1)); // _t53 = t49 + 1:uint32 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:178:11
_Next=24; // jump 24.if.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:178:11
}// end SubFn22
private inline  function SubFn23():Void {
var _t57:Bool;
_t55=(_t54>>1); // _t55 = t54 >> 1:uint32 *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:178:11
_t56=(_t50+1); // _t56 = t50 + 1:int *ssa.BinOp near /usr/local/go/src/pkg/runtime/softfloat64.go:178:11
this.setPH(1547);
_t57=(Force.uintCompare(_t55,8388608)<0); // _t57 = t55 < 8388608:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:188:11
_Next=_t57 ? 27 : 17; // if t57 goto 27.if.then else 17.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:188:11
}// end SubFn23
private inline  function SubFn24():Void {
var _t58:Bool;
this.setPH(1542);
_t58=(Force.uintCompare(_t51,0)!=0); // _t58 = t51 != 0:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:183:28
_Next=_t58 ? 23 : 26; // if t58 goto 23.if.then else 26.cond.false *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:183:28
}// end SubFn24
private inline  function SubFn25():Void {
var _t59:Int;
var _t60:Bool;
_t59=Force.toUint32((_t49&2)); // _t59 = t49 & 2:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:183:40
_t60=(Force.uintCompare(_t59,0)!=0); // _t60 = t59 != 0:uint32 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:183:43
_Next=_t60 ? 23 : 24; // if t60 goto 23.if.then else 24.if.done *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:183:43
}// end SubFn25
private inline  function SubFn26():Void {
this.setPH(1548);
_t61=Force.toUint32((p_sign|_t55)); // _t61 = sign | t55 *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:189:16
}// end SubFn26
}
#if (!php) private #end class Go_math_init extends StackFrameBasis implements StackFrame { 
public function new(gr:Int,_bds:Array<Dynamic>) {
super(gr,1548,"Go_math_init");
this._bds=_bds;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Bool=false;
var _Next:Int=0;
public static inline function callFromHaxe( ) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_math_init(0,[]).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr) : Void {
var _sf=new Go_math_init(_gr,[]).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>) : Go_math_init
{return new Go_math_init(gr,_bds);
}
public function run():Go_math_init {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(1548,0);
this.SubFn0();

case 1: // init.start
this.setLatest(1548,1);
this.SubFn1();

case 2: // init.done
this.setLatest(1548,2);
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return *ssa.Return near /usr/local/go/src/pkg/runtime/softfloat64.go:189:16

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
_t0=Go.math_init_36_guard.load(); // _t0 = *init$guard *ssa.UnOp near /usr/local/go/src/pkg/runtime/softfloat64.go:189:16
_Next=_t0 ? 2 : 1; // if t0 goto 2.init.done else 1.init.start *ssa.If near /usr/local/go/src/pkg/runtime/softfloat64.go:189:16
}// end SubFn0
private inline  function SubFn1():Void {
Go.math_init_36_guard.store(true); // *init$guard = true:bool *ssa.Store near /usr/local/go/src/pkg/runtime/softfloat64.go:189:16
_Next=2; // jump 2.init.done *ssa.Jump near /usr/local/go/src/pkg/runtime/softfloat64.go:189:16
}// end SubFn1
}
#if (!php) private #end class Go_sync_runtime_Syncsemacquire extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:41:6
var p_s:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Pointer) {
super(gr,568,"Go_sync_runtime_Syncsemacquire");
this._bds=_bds;
this.p_s=p_s;
Scheduler.push(gr,this);
}
public inline function res():Dynamic {return null;}
var _t0:Interface=null;
var _Next:Int=0;
public static inline function callFromHaxe( p_s : Pointer) : Void {
if(!Go.doneInit) Go.init();
var _sf=new Go_sync_runtime_Syncsemacquire(0,[], p_s).run(); 
while(_sf._incomplete) Scheduler.runAll();
}
public static inline function callFromRT( _gr, p_s : Pointer) : Void {
var _sf=new Go_sync_runtime_Syncsemacquire(_gr,[], p_s).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_s : Pointer) : Go_sync_runtime_Syncsemacquire
{return new Go_sync_runtime_Syncsemacquire(gr,_bds, p_s);
}
public function run():Go_sync_runtime_Syncsemacquire {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(568,0);
this.SubFn0();
this.setPH(569);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(569,-1);
 // panic t0 *ssa.Panic @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:42:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"runtime_Syncsemacquire not yet implemented"); // _t0 = make interface{} <- string ("runtime_Syncsemac...":string) *ssa.MakeInterface near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:42:7
}// end SubFn0
}
#if js @:expose("Go_haxegoruntime_Raw2Runes") #end class Go_haxegoruntime_Raw2Runes extends StackFrameBasis implements StackFrame {  // langgoruntime.go:55:6
var p_s:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_s : Slice) {
super(gr,2878,"Go_haxegoruntime_Raw2Runes");
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
this.setLatest(2878,0);
this.SubFn0();
_Phi=0;
case 1: // switch.body
this.setLatest(2878,1);
this.SubFn1();
_Phi=1;
case 2: // switch.body
this.setLatest(2878,2);
this.SubFn2();
_Phi=2;
case 3: // switch.next
this.setLatest(2878,3);
this.SubFn3();
_Phi=3;
case 4: // rangeindex.loop
this.setLatest(2878,4);
_t9=((_Phi==1)?(-1):(_Phi==5)?_t10:0); // _t9 = phi [1.switch.body: -1:int, 5.rangeindex.body: t10] *ssa.Phi near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:42:7
this.SubFn4();
_Phi=4;
case 5: // rangeindex.body
this.setLatest(2878,5);
this.SubFn5();
_Phi=5;
case 6: // rangeindex.done
this.setLatest(2878,6);
this.setPH(2885);
_SF1=Go_haxegoruntime_UTF16toRunes.call(this._goroutine,[],_t3);
_Next = -1;
return this;
case -1:
this.setLatest(2885,-1);
_t16=_SF1.res();
 // _t16 = UTF16toRunes(t3) *ssa.Call @ langgoruntime.go:62:22
_res= _t16;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t16 *ssa.Return @ langgoruntime.go:62:3

case 7: // switch.next
this.setLatest(2885,7);
this.SubFn6();
this.setPH(2895);
_res= _t18;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t18 *ssa.Return @ langgoruntime.go:72:2

case 8: // rangeindex.loop
this.setLatest(2895,8);
_t19=((_Phi==2)?(-1):(_Phi==9)?_t20:0); // _t19 = phi [2.switch.body: -1:int, 9.rangeindex.body: t20] *ssa.Phi near langgoruntime.go:72:2
this.SubFn7();
_Phi=8;
case 9: // rangeindex.body
this.setLatest(2895,9);
this.SubFn8();
_Phi=9;
case 10: // rangeindex.done
this.setLatest(2895,10);
this.setPH(2891);
_SF2=Go_haxegoruntime_UTF8toRunes.call(this._goroutine,[],_t6);
_Next = -2;
return this;
case -2:
this.setLatest(2891,-2);
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
this.setPH(2881);
_t2=({var _v=p_s;_v==null?0:_v.len();}); // _t2 = len(s) *ssa.Call @ langgoruntime.go:58:40
_t3=new Slice(new Pointer({var _v:Array<Int>=new Array<Int>();for(_i in 0..._t2) _v[_i]=0; _v;}),0,_t2); // _t3 = make []uint16 t2 t2 *ssa.MakeSlice @ langgoruntime.go:58:26
_t4=({var _v=p_s;_v==null?0:_v.len();}); // _t4 = len(s) *ssa.Call near langgoruntime.go:58:26
_Next=4; // jump 4.rangeindex.loop *ssa.Jump near langgoruntime.go:58:26
}// end SubFn1
private inline  function SubFn2():Void {
var _t5:Int;
this.setPH(2887);
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
this.setPH(2883);
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
this.setPH(2895);
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
this.setPH(2889);
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
#if (!php) private #end class Go_runtime_funcentry_go extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:31:6
var p_arg0:Pointer;
public function new(gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer) {
super(gr,448,"Go_runtime_funcentry_go");
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
var _sf=new Go_runtime_funcentry_go(0,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_arg0 : Pointer) : Dynamic {
var _sf=new Go_runtime_funcentry_go(_gr,[], p_arg0).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_arg0 : Pointer) : Go_runtime_funcentry_go
{return new Go_runtime_funcentry_go(gr,_bds, p_arg0);
}
public function run():Go_runtime_funcentry_go {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(448,0);
this.SubFn0();
this.setPH(449);
Scheduler.panic(this._goroutine,_t0);_Next = -1;
return this;
case -1:
this.setLatest(449,-1);
 // panic t0 *ssa.Panic @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:32:7

this._incomplete=false;
Scheduler.pop(this._goroutine);
return this;default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
_t0=new Interface(0,"runtime.funcentry_go() not yet implemented"); // _t0 = make interface{} <- string ("runtime.funcentry...":string) *ssa.MakeInterface near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:32:7
}// end SubFn0
}
#if js @:expose("Go_bytes_Equal") #end class Go_bytes_Equal extends StackFrameBasis implements StackFrame {  // /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:29:6
var p_a:Slice;
var p_b:Slice;
public function new(gr:Int,_bds:Array<Dynamic>, p_a : Slice, p_b : Slice) {
super(gr,317,"Go_bytes_Equal");
this._bds=_bds;
this.p_a=p_a;
this.p_b=p_b;
Scheduler.push(gr,this);
}
var _res:Bool;
public inline function res():Dynamic {return _res;}
var _t0:Bool=false;
var _t1:Bool=false;
var _t2:Bool=false;
var _t3:Int=0;
var _t4:Bool=false;
var _t5:Int=0;
var _t6:Bool=false;
var _t7:Int=0;
var _t8:Int=0;
var _t9:Bool=false;
var _t10:Int=0;
var _t11:Int=0;
var _t12:Int=0;
var _t13:Bool=false;
var _t14:Pointer=null;
var _t15:Int=0;
var _t16:Pointer=null;
var _t17:Int=0;
var _t18:Bool=false;
var _Phi:Int=0;
var _Next:Int=0;
public static inline function callFromHaxe( p_a : Slice, p_b : Slice) : Bool {
if(!Go.doneInit) Go.init();
var _sf=new Go_bytes_Equal(0,[], p_a, p_b).run(); 
while(_sf._incomplete) Scheduler.runAll();
return _sf.res();
}
public static inline function callFromRT( _gr, p_a : Slice, p_b : Slice) : Bool {
var _sf=new Go_bytes_Equal(_gr,[], p_a, p_b).run(); 
while(_sf._incomplete) Scheduler.run1(_gr);
return _sf.res();
}
public static inline function call( gr:Int,_bds:Array<Dynamic>, p_a : Slice, p_b : Slice) : Go_bytes_Equal
{return new Go_bytes_Equal(gr,_bds, p_a, p_b);
}
public function run():Go_bytes_Equal {
while(true){
switch(_Next) {
case 0: // entry
this.setLatest(317,0);
this.SubFn0();
_Phi=0;
case 1: // if.then
this.setLatest(317,1);
this.SubFn1();
_Phi=1;
case 2: // if.done
this.setLatest(317,2);
this.SubFn2();
_Phi=2;
case 3: // if.then
this.setLatest(317,3);
this.setPH(320);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:32:4

case 4: // if.else
this.setLatest(320,4);
this.SubFn3();
this.setPH(322);
_res= _t4;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t4 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:34:4

case 5: // if.then
this.setLatest(322,5);
this.SubFn4();
this.setPH(326);
_res= _t6;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return t6 *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:38:3

case 6: // if.done
this.setLatest(326,6);
this.SubFn5();
_Phi=6;
case 7: // if.then
this.setLatest(326,7);
this.setPH(329);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:41:3

case 8: // if.done
this.setLatest(329,8);
this.SubFn6();
_Phi=8;
case 9: // rangeindex.loop
this.setLatest(329,9);
_t11=((_Phi==8)?(-1):(_Phi==10)?_t12:0); // _t11 = phi [8.if.done: -1:int, 10.rangeindex.body: t12] *ssa.Phi near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:41:3
this.SubFn7();
_Phi=9;
case 10: // rangeindex.body
this.setLatest(329,10);
this.SubFn8();
_Phi=10;
case 11: // rangeindex.done
this.setLatest(329,11);
this.setPH(336);
_res= true;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return true:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:48:2

case 12: // if.then
this.setLatest(336,12);
this.setPH(333);
_res= false;
this._incomplete=false;
Scheduler.pop(this._goroutine);
return this; // return false:bool *ssa.Return @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:45:4

default: Scheduler.bbi();}}}
private inline  function SubFn0():Void {
var _t0:Bool;
this.setPH(318);
_t0=(p_a==null); // _t0 = a == nil:[]byte *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:30:7
_Next=_t0 ? 1 : 2; // if t0 goto 1.if.then else 2.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:30:7
}// end SubFn0
private inline  function SubFn1():Void {
var _t1:Bool;
this.setPH(319);
_t1=(p_b==null); // _t1 = b == nil:[]byte *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:31:8
_Next=_t1 ? 3 : 4; // if t1 goto 3.if.then else 4.if.else *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:31:8
}// end SubFn1
private inline  function SubFn2():Void {
var _t2:Bool;
this.setPH(325);
_t2=(p_b==null); // _t2 = b == nil:[]byte *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:37:7
_Next=_t2 ? 5 : 6; // if t2 goto 5.if.then else 6.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:37:7
}// end SubFn2
private inline  function SubFn3():Void {
var _t3:Int;
this.setPH(322);
_t3=({var _v=p_b;_v==null?0:_v.len();}); // _t3 = len(b) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:34:14
_t4=(_t3==0); // _t4 = t3 == 0:int *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:34:18
}// end SubFn3
private inline  function SubFn4():Void {
var _t5:Int;
this.setPH(326);
_t5=({var _v=p_a;_v==null?0:_v.len();}); // _t5 = len(a) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:38:13
_t6=(_t5==0); // _t6 = t5 == 0:int *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:38:17
}// end SubFn4
private inline  function SubFn5():Void {
var _t7:Int;
var _t8:Int;
var _t9:Bool;
this.setPH(328);
_t7=({var _v=p_a;_v==null?0:_v.len();}); // _t7 = len(a) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:40:8
_t8=({var _v=p_b;_v==null?0:_v.len();}); // _t8 = len(b) *ssa.Call @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:40:18
_t9=(_t7!=_t8); // _t9 = t7 != t8 *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:40:12
_Next=_t9 ? 7 : 8; // if t9 goto 7.if.then else 8.if.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:40:12
}// end SubFn5
private inline  function SubFn6():Void {
_t10=({var _v=p_a;_v==null?0:_v.len();}); // _t10 = len(a) *ssa.Call near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:40:12
_Next=9; // jump 9.rangeindex.loop *ssa.Jump near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:40:12
}// end SubFn6
private inline  function SubFn7():Void {
var _t13:Bool;
_t12=(_t11+1); // _t12 = t11 + 1:int *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:40:12
_t13=(_t12<_t10); // _t13 = t12 < t10 *ssa.BinOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:40:12
_Next=_t13 ? 10 : 11; // if t13 goto 10.rangeindex.body else 11.rangeindex.done *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:40:12
}// end SubFn7
private inline  function SubFn8():Void {
var _t14:Pointer;
var _t15:Int;
var _t16:Pointer;
var _t17:Int;
var _t18:Bool;
this.setPH(332);
if((_t12<0)||(_t12>=p_a.len())) Scheduler.ioor(); // _t14 = &a[t12] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:44:7 [POINTER]
_t14=p_a.addr(_t12);  // _t14 = &a[t12] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:44:7 [POINTER]
_t15=(_t14.load()|0); // _t15 = *t14 *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:44:7
if((_t12<0)||(_t12>=p_b.len())) Scheduler.ioor(); // _t16 = &b[t12] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:44:15 [POINTER]
_t16=p_b.addr(_t12);  // _t16 = &b[t12] *ssa.IndexAddr @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:44:15 [POINTER]
_t17=(_t16.load()|0); // _t17 = *t16 *ssa.UnOp near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:44:15
_t18=(Force.uintCompare(_t15,_t17)!=0); // _t18 = t15 != t17 *ssa.BinOp @ /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:44:11
_Next=_t18 ? 12 : 9; // if t18 goto 12.if.then else 9.rangeindex.loop *ssa.If near /Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:44:11
}// end SubFn8
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

public static var utf8_RuneError:Int = 65533;
public static var utf8_MaxRune:Int = 1114111;
public static var utf8_RuneSelf:Int = 128;
public static var utf8_UTFMax:Int = 4;
public static var runtime_GOOS:String = "darwin";
public static var runtime_GOARCH:String = "amd64";
public static var runtime_Compiler:String = "gc";
public static var utf16_init_36_guard:Pointer=new Pointer(false); 
public static var bytes_init_36_guard:Pointer=new Pointer(false); 
public static var strings_init_36_guard:Pointer=new Pointer(false); 
public static var golibruntime_init_36_guard:Pointer=new Pointer(false); 
public static var utf8_init_36_guard:Pointer=new Pointer(false); 
public static var tardisgolib_init_36_guard:Pointer=new Pointer(false); 
public static var sync_init_36_guard:Pointer=new Pointer(false); 
public static var haxegoruntime_init_36_guard:Pointer=new Pointer(false); 
public static var haxegoruntime_ZiLen:Pointer=new Pointer(0);  // langgoruntime.go:33:5
public static var atomic_init_36_guard:Pointer=new Pointer(false); 
public static var math_init_36_guard:Pointer=new Pointer(false); 
public static var runtime_neginf:Pointer=new Pointer(0.0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:362:5
public static var runtime_allm:Pointer=new Pointer(new Pointer(null));  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:343:5
public static var runtime_prof:Pointer=new Pointer({var _v=new Array<Dynamic>();_v=[{var _v=new Array<Dynamic>();_v=[GOint64.make(0,0)]; _v;},null,0,{var _v=new Array<GOint64>();for(_vi in 0...100){_v[_vi]=GOint64.make(0,0);}; _v;}]; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:611:5
public static var runtime_typelink:Pointer=new Pointer({var _v=new Array<Pointer>();for(_vi in 0...0){_v[_vi]=new Pointer(null);}; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:675:5
public static var runtime_gomaxprocs:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:345:5
public static var runtime_posinf:Pointer=new Pointer(0.0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:361:5
public static var runtime_panicking:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:347:5
public static var runtime_ncpu:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:349:5
public static var runtime_sysargs:Pointer=new Pointer(null);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:351:5
public static var runtime_checking:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:492:5
public static var runtime_hash:Pointer=new Pointer({var _v=new Array<Pointer>();for(_vi in 0...1009){_v[_vi]=new Pointer(null);}; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:673:5
public static var runtime_experiment:Pointer=new Pointer({var _v=new Array<Int>();for(_vi in 0...0){_v[_vi]=0;}; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:619:5
public static var runtime_etypelink:Pointer=new Pointer({var _v=new Array<Pointer>();for(_vi in 0...0){_v[_vi]=new Pointer(null);}; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:676:5
public static var runtime_allg:Pointer=new Pointer(new Pointer(null));  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:341:5
public static var runtime_memstats:Pointer=new Pointer({var _v=new Array<Dynamic>();_v=[GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),{var _v=new Array<GOint64>();for(_vi in 0...256){_v[_vi]=GOint64.make(0,0);}; _v;},0,0,0,{var _v=new Array<Array<Dynamic>>();for(_vi in 0...61){_v[_vi]={var _v=new Array<Dynamic>();_v=[0,GOint64.make(0,0),GOint64.make(0,0)]; _v;};}; _v;}]; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:416:5
public static var runtime_scavenger:Pointer=new Pointer({var _v=new Array<Dynamic>();_v=[null]; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:595:5
public static var runtime_iscgo:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:350:5
public static var runtime_debug:Pointer=new Pointer({var _v=new Array<Dynamic>();_v=[0,0,0]; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:356:5
public static var runtime_emptystring:Pointer=new Pointer("");  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:339:5
public static var runtime_hashload:Pointer=new Pointer(0.0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:765:5
public static var runtime_nan:Pointer=new Pointer(0.0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:360:5
public static var runtime_m0:Pointer=new Pointer({var _v=new Array<Dynamic>();_v=[new Pointer(null),new UnsafePointer(null),{var _v=new Array<Dynamic>();_v=[GOint64.make(0,0),GOint64.make(0,0),new Pointer(null),GOint64.make(0,0),new UnsafePointer(null),GOint64.make(0,0)]; _v;},0,0,GOint64.make(0,0),GOint64.make(0,0),new Pointer(null),{var _v=new Array<GOint64>();for(_vi in 0...4){_v[_vi]=GOint64.make(0,0);}; _v;},null,new Pointer(null),new Pointer(null),new Pointer(null),new Pointer(null),0,0,0,0,0,0,0,0,0,0,GOint64.make(0,0),0,new Pointer(null),{var _v=new Array<Dynamic>();_v=[GOint64.make(0,0)]; _v;},new Pointer(null),new Pointer(null),0,new Pointer(null),0,0,0,{var _v=new Array<UnsafePointer>();for(_vi in 0...32){_v[_vi]=new UnsafePointer(null);}; _v;},new Pointer(null),{var _v=new Array<GOint64>();for(_vi in 0...32){_v[_vi]=GOint64.make(0,0);}; _v;},{var _v=new Array<Int>();for(_vi in 0...16){_v[_vi]=0;}; _v;},{var _v=new Array<Int>();for(_vi in 0...16){_v[_vi]=0;}; _v;},0,0,new Pointer(null),GOint64.make(0,0),0,0,{var _v=new Array<Dynamic>();_v=[GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0)]; _v;},0,0,null,new UnsafePointer(null),{var _v=new Array<GOint64>();for(_vi in 0...1024){_v[_vi]=GOint64.make(0,0);}; _v;},GOint64.make(0,0),new Pointer(null),{var _v=new Array<GOint64>();for(_vi in 0...0){_v[_vi]=GOint64.make(0,0);}; _v;}]; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:591:5
public static var runtime_startup_random_data:Pointer=new Pointer(new Pointer(null));  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:303:5
public static var runtime_worldsema:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:359:5
public static var runtime_zerobase:Pointer=new Pointer(GOint64.make(0,0));  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:340:5
public static var runtime_newprocs:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:594:5
public static var runtime_hchansize:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:353:5
public static var runtime_initdone:Pointer=new Pointer({var _v=new Array<Dynamic>();_v=[null]; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:596:5
public static var runtime_maxstring:Pointer=new Pointer(GOint64.make(0,0));  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:352:5
public static var runtime_init_36_guard:Pointer=new Pointer(false); 
public static var runtime_lastg:Pointer=new Pointer(new Pointer(null));  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:342:5
public static var runtime_extram:Pointer=new Pointer(new Pointer(null));  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:593:5
public static var runtime_algarray:Pointer=new Pointer({var _v=new Array<Array<Dynamic>>();for(_vi in 0...22){_v[_vi]={var _v=new Array<Dynamic>();_v=[null,null,null,null]; _v;};}; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:302:5
public static var runtime_g0:Pointer=new Pointer({var _v=new Array<Dynamic>();_v=[GOint64.make(0,0),GOint64.make(0,0),0,0,new Pointer(null),new Pointer(null),{var _v=new Array<Dynamic>();_v=[GOint64.make(0,0),GOint64.make(0,0),new Pointer(null),GOint64.make(0,0),new UnsafePointer(null),GOint64.make(0,0)]; _v;},GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),new Pointer(null),new UnsafePointer(null),0,GOint64.make(0,0),new Pointer(null),new Pointer(null),0,0,0,0,0,new Pointer(null),new Pointer(null),0,0,new Pointer(null),new Pointer(null),new Pointer(null),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),{var _v=new Array<GOint64>();for(_vi in 0...0){_v[_vi]=GOint64.make(0,0);}; _v;}]; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:592:5
public static var runtime_goos:Pointer=new Pointer(new Pointer(null));  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:348:5
public static var runtime_blockprofilerate:Pointer=new Pointer(GOint64.make(0,0));  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:358:5
public static var runtime_allp:Pointer=new Pointer(new Pointer(null));  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:344:5
public static var runtime_ifacelock:Pointer=new Pointer({var _v=new Array<Dynamic>();_v=[GOint64.make(0,0)]; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:674:5
public static var runtime_precisestack:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:294:5
public static var runtime_maxstacksize:Pointer=new Pointer(GOint64.make(0,0));  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:357:5
public static var runtime_empty_value:Pointer=new Pointer({var _v=new Array<Int>();for(_vi in 0...128){_v[_vi]=0;}; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:749:5
public static var runtime_sizeof_C_MStats:Pointer=new Pointer(null);  // /usr/local/go/src/pkg/runtime/mem.go:61:5
public static var runtime_needextram:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:346:5
public static var runtime_MemProfileRate:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/debug.go:49:5
public static var runtime_memStats:Pointer=new Pointer({var _v=new Array<Dynamic>();_v=[GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),GOint64.make(0,0),{var _v=new Array<GOint64>();for(_vi in 0...256){_v[_vi]=GOint64.make(0,0);}; _v;},0,false,false,{var _v=new Array<Array<Dynamic>>();for(_vi in 0...61){_v[_vi]={var _v=new Array<Dynamic>();_v=[0,GOint64.make(0,0),GOint64.make(0,0)]; _v;};}; _v;}]; _v;});  // /usr/local/go/src/pkg/runtime/mem.go:63:5
public static var runtime_class_to_allocnpages:Pointer=new Pointer({var _v=new Array<Int>();for(_vi in 0...61){_v[_vi]=0;}; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:418:5
public static var runtime_startup_random_data_len:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:304:5
public static var runtime__cgo_thread_start:Pointer=new Pointer(null);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:597:5
public static var runtime_size_to_class128:Pointer=new Pointer({var _v=new Array<Int>();for(_vi in 0...249){_v[_vi]=0;}; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:420:5
public static var runtime_size_to_class8:Pointer=new Pointer({var _v=new Array<Int>();for(_vi in 0...129){_v[_vi]=0;}; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:419:5
public static var runtime_cpuid_edx:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:355:5
public static var runtime_cpuid_ecx:Pointer=new Pointer(0);  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:354:5
public static var runtime_class_to_size:Pointer=new Pointer({var _v=new Array<Int>();for(_vi in 0...61){_v[_vi]=0;}; _v;});  // /usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:417:5
public static var main_init_36_guard:Pointer=new Pointer(false); 
public static var doneInit:Bool=false;

public static function init() : Void {
doneInit=true;
var gr:Int=Scheduler.makeGoroutine();
if(gr!=0) throw "non-zero goroutine number in init";
Go.runtime_sizeof_C_MStats.store(3712);
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
if(pos>3072) return prefix+"/usr/local/go/src/pkg/unicode/utf8/utf8.go:"+Std.string(pos-3072);
else if(pos>2964) return prefix+"/usr/local/go/src/pkg/unicode/utf16/utf16.go:"+Std.string(pos-2964);
else if(pos>2823) return prefix+"langgoruntime.go:"+Std.string(pos-2823);
else if(pos>1912) return prefix+"/usr/local/go/src/pkg/runtime/zruntime_defs_darwin_amd64.go:"+Std.string(pos-1912);
else if(pos>1857) return prefix+"/usr/local/go/src/pkg/runtime/type.go:"+Std.string(pos-1857);
else if(pos>1359) return prefix+"/usr/local/go/src/pkg/runtime/softfloat64.go:"+Std.string(pos-1359);
else if(pos>1354) return prefix+"/usr/local/go/src/pkg/runtime/zgoarch_amd64.go:"+Std.string(pos-1354);
else if(pos>1339) return prefix+"/usr/local/go/src/pkg/runtime/mgc0.go:"+Std.string(pos-1339);
else if(pos>1333) return prefix+"/usr/local/go/src/pkg/runtime/zversion.go:"+Std.string(pos-1333);
else if(pos>1328) return prefix+"/usr/local/go/src/pkg/runtime/zgoos_darwin.go:"+Std.string(pos-1328);
else if(pos>1252) return prefix+"/usr/local/go/src/pkg/runtime/mem.go:"+Std.string(pos-1252);
else if(pos>1080) return prefix+"/usr/local/go/src/pkg/runtime/debug.go:"+Std.string(pos-1080);
else if(pos>891) return prefix+"/usr/local/go/src/pkg/runtime/extern.go:"+Std.string(pos-891);
else if(pos>768) return prefix+"/usr/local/go/src/pkg/runtime/error.go:"+Std.string(pos-768);
else if(pos>755) return prefix+"/usr/local/go/src/pkg/runtime/compiler.go:"+Std.string(pos-755);
else if(pos>586) return prefix+"/Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/atomic/sync_atomic.go:"+Std.string(pos-586);
else if(pos>527) return prefix+"/Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/sync/sync.go:"+Std.string(pos-527);
else if(pos>505) return prefix+"/Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/strings/strings.go:"+Std.string(pos-505);
else if(pos>463) return prefix+"/Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:"+Std.string(pos-463);
else if(pos>417) return prefix+"/Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/runtime/runtime.go:"+Std.string(pos-417);
else if(pos>380) return prefix+"/Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/math/math.go:"+Std.string(pos-380);
else if(pos>288) return prefix+"/Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/bytes/bytes.go:"+Std.string(pos-288);
else if(pos>272) return prefix+"/Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/golibruntime.go:"+Std.string(pos-272);
else if(pos>121) return prefix+"/usr/local/go/src/pkg/sync/atomic/doc.go:"+Std.string(pos-121);
else if(pos>0) return prefix+"stateful.go:"+Std.string(pos-0);
else return "(invalid pogo.PosHash:"+Std.string(pos)+")";}
} // end Go class
class TypeInfo{
public static function getName(id:Int):String {
switch(id){
case 0: return "string";
case 5: return "*runtime.m";
case 8: return "runtime.errorCString";
case 1: return "runtime.stringer";
case 2: return "error";
case 3: return "int";
case 4: return "*runtime.itab";
case 6: return "*runtime.TypeAssertionError";
case 7: return "runtime.errorString";
default: return "UNKNOWN";}}
public static function typeString(i:Interface):String {
return getName(i.typ);
}
public static function getId(name:String):Int {
switch(name){
case "string": return 0;
case "*runtime.m": return 5;
case "runtime.errorCString": return 8;
case "runtime.stringer": return 1;
case "error": return 2;
case "int": return 3;
case "*runtime.itab": return 4;
case "*runtime.TypeAssertionError": return 6;
case "runtime.errorString": return 7;
default: return -1;}}
public static function isAssignableTo(v:Int,t:Int):Bool {
if(v==t) return true;
switch(v){
case 0: switch(t){
default: return false;}
case 5: switch(t){
default: return false;}
case 8: switch(t){
case 2: return true;
default: return false;}
case 1: switch(t){
default: return false;}
case 2: switch(t){
default: return false;}
case 3: switch(t){
default: return false;}
case 4: switch(t){
default: return false;}
case 6: switch(t){
case 2: return true;
default: return false;}
case 7: switch(t){
case 2: return true;
default: return false;}
default: return false;}}
public static function isIdentical(v:Int,t:Int):Bool {
if(v==t) return true;
switch(v){
case 0: switch(t){
default: return false;}
case 5: switch(t){
default: return false;}
case 8: switch(t){
default: return false;}
case 1: switch(t){
default: return false;}
case 2: switch(t){
default: return false;}
case 3: switch(t){
default: return false;}
case 4: switch(t){
default: return false;}
case 6: switch(t){
default: return false;}
case 7: switch(t){
default: return false;}
default: return false;}}
public static function isConcrete(t:Int):Bool {
switch(t){
case 0: return true;
case 5: return true;
case 8: return true;
case 1: return false;
case 2: return false;
case 3: return true;
case 4: return true;
case 6: return true;
case 7: return true;
default: return false;}}
public static function zeroValue(t:Int):Dynamic {
switch(t){
case 0: return "";
case 5: return new Pointer(null);
case 8: return null;
case 1: return null;
case 2: return null;
case 3: return 0;
case 4: return new Pointer(null);
case 6: return new Pointer(null);
case 7: return "";
default: return null;}}
public static function method(t:Int,m:String):Dynamic {
switch(t){
case 8: switch(m){
case "Error": return Go_runtime_dot_errorCString_Error.call; // Error 1 [1] false
case "RuntimeError": return Go_runtime_dot_errorCString_RuntimeError.call; // RuntimeError 1 [0] false
default:}
case 6: switch(m){
case "Error": return Go__star_runtime_dot_TypeAssertionError_Error.call; // Error 1 [1] true
case "RuntimeError": return Go__star_runtime_dot_TypeAssertionError_RuntimeError.call; // RuntimeError 1 [0] true
default:}
case 7: switch(m){
case "Error": return Go_runtime_dot_errorString_Error.call; // Error 1 [1] false
case "RuntimeError": return Go_runtime_dot_errorString_RuntimeError.call; // RuntimeError 1 [0] false
default:}
default:}
 Scheduler.panicFromHaxe( "no method found!"); return null;}
}

 // Warning: *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:30:11 (inexact) constant value -9223372036854775808 cannot be accurately represented in int64
 // Warning: *ssa.Call @ langgoruntime.go:84:18 (pogo) The result from a function call is not used
 // Warning: *ssa.Call @ stateful.go:90:20 (pogo) The result from a function call is not used
 // Warning: *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:443:3 (inexact) constant value -1 cannot be accurately represented in int64
 // Warning: *ssa.Return @ /usr/local/go/src/pkg/runtime/softfloat64.go:443:3 (inexact) constant value -1 cannot be accurately represented in int64
 // Warning: *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:448:7 (inexact) constant value -9223372036854775808 cannot be accurately represented in int64
 // Warning: *ssa.Call @ stateful.go:106:20 (pogo) The result from a function call is not used
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
 // Warning: *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:255:11 (inexact) constant value -9223372036854775808 cannot be accurately represented in int64
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: _t2@/usr/local/go/src/pkg/unicode/utf8/utf8.go:382:6 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: temp var declaration (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: temp var declaration (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: *ssa.Next near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: *ssa.Next near /usr/local/go/src/pkg/unicode/utf8/utf8.go:383:2 (Haxe) LangType() unrecognised basic type, Dynamic assumed
 // Warning: *ssa.BinOp @ /usr/local/go/src/pkg/runtime/softfloat64.go:410:20 (inexact) constant value -9223372036854775808 cannot be accurately represented in int64
 // Package List:
 //  package github.com/tardisgo/tardisgo/tardisgolib
 //  package github.com/tardisgo/tardisgo/golibruntime/sync
 //  package goruntime
 //  package sync/atomic
 //  package github.com/tardisgo/tardisgo/golibruntime/math
 //  package runtime
 //  package main
 //  package github.com/tardisgo/tardisgo/golibruntime/runtime
 //  package unicode/utf16
 //  package github.com/tardisgo/tardisgo/golibruntime/bytes
 //  package github.com/tardisgo/tardisgo/golibruntime/strings
 //  package github.com/tardisgo/tardisgo/golibruntime/sync/atomic
 //  package github.com/tardisgo/tardisgo/golibruntime
 //  package unicode/utf8
