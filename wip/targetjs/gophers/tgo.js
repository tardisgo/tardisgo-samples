(function ($hx_exports) { "use strict";
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
var HxOverrides = function() { };
HxOverrides.__name__ = true;
HxOverrides.dateStr = function(date) {
	var m = date.getMonth() + 1;
	var d = date.getDate();
	var h = date.getHours();
	var mi = date.getMinutes();
	var s = date.getSeconds();
	return date.getFullYear() + "-" + (m < 10?"0" + m:"" + m) + "-" + (d < 10?"0" + d:"" + d) + " " + (h < 10?"0" + h:"" + h) + ":" + (mi < 10?"0" + mi:"" + mi) + ":" + (s < 10?"0" + s:"" + s);
};
HxOverrides.cca = function(s,index) {
	var x = s.charCodeAt(index);
	if(x != x) return undefined;
	return x;
};
HxOverrides.iter = function(a) {
	return { cur : 0, arr : a, hasNext : function() {
		return this.cur < this.arr.length;
	}, next : function() {
		return this.arr[this.cur++];
	}};
};
var List = function() {
	this.length = 0;
};
List.__name__ = true;
List.prototype = {
	push: function(item) {
		var x = [item,this.h];
		this.h = x;
		if(this.q == null) this.q = x;
		this.length++;
	}
	,first: function() {
		if(this.h == null) return null; else return this.h[0];
	}
	,pop: function() {
		if(this.h == null) return null;
		var x = this.h[0];
		this.h = this.h[1];
		if(this.h == null) this.q = null;
		this.length--;
		return x;
	}
	,isEmpty: function() {
		return this.h == null;
	}
	,iterator: function() {
		return { h : this.h, hasNext : function() {
			return this.h != null;
		}, next : function() {
			if(this.h == null) return null;
			var x = this.h[0];
			this.h = this.h[1];
			return x;
		}};
	}
	,__class__: List
};
var IMap = function() { };
IMap.__name__ = true;
Math.__name__ = true;
var Reflect = function() { };
Reflect.__name__ = true;
Reflect.callMethod = function(o,func,args) {
	return func.apply(o,args);
};
Reflect.isFunction = function(f) {
	return typeof(f) == "function" && !(f.__name__ || f.__ename__);
};
Reflect.makeVarArgs = function(f) {
	return function() {
		var a = Array.prototype.slice.call(arguments);
		return f(a);
	};
};
var Std = function() { };
Std.__name__ = true;
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
};
Std.random = function(x) {
	if(x <= 0) return 0; else return Math.floor(Math.random() * x);
};
var haxe = {};
haxe.Timer = function(time_ms) {
	var me = this;
	this.id = setInterval(function() {
		me.run();
	},time_ms);
};
haxe.Timer.__name__ = true;
haxe.Timer.delay = function(f,time_ms) {
	var t = new haxe.Timer(time_ms);
	t.run = function() {
		t.stop();
		f();
	};
	return t;
};
haxe.Timer.prototype = {
	stop: function() {
		if(this.id == null) return;
		clearInterval(this.id);
		this.id = null;
	}
	,run: function() {
	}
	,__class__: haxe.Timer
};
haxe.ds = {};
haxe.ds.StringMap = function() {
	this.h = { };
};
haxe.ds.StringMap.__name__ = true;
haxe.ds.StringMap.__interfaces__ = [IMap];
haxe.ds.StringMap.prototype = {
	get: function(key) {
		return this.h["$" + key];
	}
	,keys: function() {
		var a = [];
		for( var key in this.h ) {
		if(this.h.hasOwnProperty(key)) a.push(key.substr(1));
		}
		return HxOverrides.iter(a);
	}
	,__class__: haxe.ds.StringMap
};
haxe.ds._Vector = {};
haxe.ds._Vector.Vector_Impl_ = function() { };
haxe.ds._Vector.Vector_Impl_.__name__ = true;
haxe.ds._Vector.Vector_Impl_.blit = function(src,srcPos,dest,destPos,len) {
	var _g = 0;
	while(_g < len) {
		var i = _g++;
		dest[destPos + i] = src[srcPos + i];
	}
};
var js = {};
js.Boot = function() { };
js.Boot.__name__ = true;
js.Boot.getClass = function(o) {
	if((o instanceof Array) && o.__enum__ == null) return Array; else return o.__class__;
};
js.Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ || o.__ename__)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__) {
				if(o.length == 2) return o[0];
				var str = o[0] + "(";
				s += "\t";
				var _g1 = 2;
				var _g = o.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(i != 2) str += "," + js.Boot.__string_rec(o[i],s); else str += js.Boot.__string_rec(o[i],s);
				}
				return str + ")";
			}
			var l = o.length;
			var i1;
			var str1 = "[";
			s += "\t";
			var _g2 = 0;
			while(_g2 < l) {
				var i2 = _g2++;
				str1 += (i2 > 0?",":"") + js.Boot.__string_rec(o[i2],s);
			}
			str1 += "]";
			return str1;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			return "???";
		}
		if(tostr != null && tostr != Object.toString) {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str2 = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) {
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str2.length != 2) str2 += ", \n";
		str2 += s + k + " : " + js.Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str2 += "\n" + s + "}";
		return str2;
	case "function":
		return "<function>";
	case "string":
		return o;
	default:
		return String(o);
	}
};
js.Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0;
		var _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js.Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js.Boot.__interfLoop(cc.__super__,cl);
};
js.Boot.__instanceof = function(o,cl) {
	if(cl == null) return false;
	switch(cl) {
	case Int:
		return (o|0) === o;
	case Float:
		return typeof(o) == "number";
	case Bool:
		return typeof(o) == "boolean";
	case String:
		return typeof(o) == "string";
	case Array:
		return (o instanceof Array) && o.__enum__ == null;
	case Dynamic:
		return true;
	default:
		if(o != null) {
			if(typeof(cl) == "function") {
				if(o instanceof cl) return true;
				if(js.Boot.__interfLoop(js.Boot.getClass(o),cl)) return true;
			}
		} else return false;
		if(cl == Class && o.__name__ != null) return true;
		if(cl == Enum && o.__ename__ != null) return true;
		return o.__enum__ == cl;
	}
};
js.Boot.__cast = function(o,t) {
	if(js.Boot.__instanceof(o,t)) return o; else throw "Cannot cast " + Std.string(o) + " to " + Std.string(t);
};
var tardis = {};
tardis.Force = function() { };
tardis.Force.__name__ = true;
tardis.Force.toUint32 = function(v) {
	return v >>> 0;
};
tardis.Force.toUint64 = function(v) {
	return v;
};
tardis.Force.toInt32 = function(v) {
	return v >> 0;
};
tardis.Force.uintCompare = function(x,y) {
	if(x == y) return 0;
	if(x >= 0) {
		if(y >= 0) return x - y; else return -1;
	} else if(y >= 0) return 1; else return x - y;
};
tardis.Force.floatDiv = function(x,y) {
	if(y == 0.0) tardis.Scheduler.panicFromHaxe("attempt to divide float value by 0");
	return x / y;
};
tardis.Force.toUTF8slice = function(gr,s) {
	var a = new Array();
	var _g1 = 0;
	var _g = s.length;
	while(_g1 < _g) {
		var i = _g1++;
		var t = HxOverrides.cca(s,i);
		if(t == null) tardis.Scheduler.panicFromHaxe("Haxe runtime Force.toUTF8slice() unexpected null encountered"); else a[i] = t | 0;
	}
	if("字".length == 3) {
		var sl = new tardis.Slice(new tardis.Pointer(new tardis.Object(a.length)),0,-1,a.length,1);
		var _g11 = 0;
		var _g2 = a.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			sl.baseArray.addr((i1 + sl.start) * sl.itemSize).store_uint8(a[i1]);
		}
		return sl;
	} else {
		var sl1 = new tardis.Slice(new tardis.Pointer(new tardis.Object(a.length << 1)),0,-1,a.length,2);
		var _g12 = 0;
		var _g3 = a.length;
		while(_g12 < _g3) {
			var i2 = _g12++;
			sl1.baseArray.addr((i2 + sl1.start) * sl1.itemSize).store_uint16(a[i2]);
		}
		var v1 = tardis.Go_haxegoruntime_UTF16toRunes.callFromRT(gr,sl1);
		return tardis.Go_haxegoruntime_RunesToUTF8.callFromRT(gr,v1);
	}
};
tardis.Force.toHaxeParam = function(v) {
	if(v == null) return null;
	if(js.Boot.__instanceof(v,tardis.Interface)) {
		if(js.Boot.__instanceof(v.val,tardis.Closure) && v.typ != -1) return v.val.buildCallbackFn(); else return v.val;
	}
	return v;
};
tardis.Object = function(byteSize) {
	var this1;
	this1 = new Array(1 + (byteSize >> 2));
	this.dVec4 = this1;
	var this2;
	this2 = new Array(byteSize);
	this.iVec = this2;
	this.length = byteSize;
};
tardis.Object.__name__ = true;
tardis.Object.objBlit = function(src,srcPos,dest,destPos,size) {
	haxe.ds._Vector.Vector_Impl_.blit(src.dVec4,srcPos >> 2,dest.dVec4,destPos >> 2,1 + (size >> 2));
	haxe.ds._Vector.Vector_Impl_.blit(src.iVec,srcPos,dest.iVec,destPos,size);
};
tardis.Object.str = function(v) {
	if(v == null) return ""; else return Std.string(v);
};
tardis.Object.prototype = {
	clear: function() {
		var _g1 = 0;
		var _g = this.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.iVec[i] = 0;
			if((i & 3) == 0) this.set(i,null);
		}
		return this;
	}
	,isEqual: function(off,target,tgtOff) {
		if(this.length - off != target.length - tgtOff) return false;
		var _g1 = 0;
		var _g = this.length - off;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.dVec4[i + off >> 2] != target.dVec4[i + tgtOff >> 2]) return false;
			if(this.get_uint8(i + off) != target.get_uint8(i + tgtOff)) return false;
		}
		return true;
	}
	,get_object: function(size,from) {
		var so = new tardis.Object(size);
		tardis.Object.objBlit(this,from,so,0,size);
		return so;
	}
	,set_object: function(size,to,from) {
		tardis.Object.objBlit(from,0,this,to,size);
	}
	,copy: function() {
		return this.get_object(this.length,0);
	}
	,get: function(i) {
		return this.dVec4[i >> 2];
	}
	,get_bool: function(i) {
		var r = this.iVec[i];
		if(r == null) return false; else if(r == 0) return false; else return true;
	}
	,get_int8: function(i) {
		var r = this.iVec[i];
		if(r == null) return 0; else return 0 | r;
	}
	,get_int16: function(i) {
		var r = this.iVec[i];
		if(r == null) return 0; else return 0 | r;
	}
	,get_int32: function(i) {
		var r = this.iVec[i];
		if(r == null) return 0; else return 0 | r;
	}
	,get_int64: function(i) {
		var r = this.dVec4[i >> 2];
		if(r == null) {
			var v = new tardis.Int64(0,0);
			return v;
		} else return r;
	}
	,get_uint8: function(i) {
		var r = this.iVec[i];
		if(r == null) return 0; else return 0 | r;
	}
	,get_uint16: function(i) {
		var r = this.iVec[i];
		if(r == null) return 0; else return 0 | r;
	}
	,get_uint32: function(i) {
		var r = this.iVec[i];
		if(r == null) return 0; else return 0 | r;
	}
	,get_uint64: function(i) {
		var r = this.dVec4[i >> 2];
		if(r == null) {
			var v = new tardis.Int64(0,0);
			return v;
		} else return r;
	}
	,get_uintptr: function(i) {
		return this.dVec4[i >> 2];
	}
	,get_float32: function(i) {
		var r = this.dVec4[i >> 2];
		if(r == null) return 0.0; else return r;
	}
	,get_float64: function(i) {
		var r = this.dVec4[i >> 2];
		if(r == null) return 0.0; else return r;
	}
	,get_complex64: function(i) {
		var r = this.dVec4[i >> 2];
		if(r == null) return new tardis.Complex(0.0,0.0); else return r;
	}
	,get_complex128: function(i) {
		var r = this.dVec4[i >> 2];
		if(r == null) return new tardis.Complex(0.0,0.0); else return r;
	}
	,get_string: function(i) {
		var r = this.dVec4[i >> 2];
		if(r == null) return ""; else return r;
	}
	,set: function(i,v) {
		var val = v;
		this.dVec4[i >> 2] = val;
	}
	,set_bool: function(i,v) {
		if(v) this.iVec[i] = 1; else this.iVec[i] = 0;
	}
	,set_int8: function(i,v) {
		this.iVec[i] = v;
	}
	,set_int16: function(i,v) {
		this.iVec[i] = v;
	}
	,set_int32: function(i,v) {
		this.iVec[i] = v;
	}
	,set_int64: function(i,v) {
		this.set(i,v);
	}
	,set_uint8: function(i,v) {
		this.iVec[i] = v;
	}
	,set_uint16: function(i,v) {
		this.iVec[i] = v;
	}
	,set_uint32: function(i,v) {
		this.iVec[i] = v;
	}
	,set_uint64: function(i,v) {
		this.set(i,v);
	}
	,set_uintptr: function(i,v) {
		this.set(i,v);
	}
	,set_float32: function(i,v) {
		this.set(i,v);
	}
	,set_float64: function(i,v) {
		this.set(i,v);
	}
	,set_complex64: function(i,v) {
		this.set(i,v);
	}
	,set_complex128: function(i,v) {
		this.set(i,v);
	}
	,set_string: function(i,v) {
		this.set(i,v);
	}
	,toString: function(addr,count) {
		if(count == null) count = -1;
		if(addr == null) addr = 0;
		if(count == -1) count = this.length;
		var ret = "{";
		var _g = 0;
		while(_g < count) {
			var i = _g++;
			if(i > 0) ret = ret + ",";
			if((addr & 3) == 0) ret += tardis.Object.str(this.dVec4[addr >> 2]);
			ret = ret + "<" + Std.string(this.get_uint8(addr)) + ">";
			addr = addr + 1;
		}
		return ret + "}";
	}
	,__class__: tardis.Object
};
tardis.Pointer = function(from) {
	this.obj = from;
	this.off = 0;
};
tardis.Pointer.__name__ = true;
tardis.Pointer.prototype = {
	addr: function(byteOffset) {
		var ret = new tardis.Pointer(this.obj);
		ret.off = this.off + byteOffset;
		return ret;
	}
	,fieldAddr: function(byteOffset) {
		return this.addr(byteOffset);
	}
	,copy: function() {
		return this;
	}
	,isEqual: function(other) {
		return this.obj.isEqual(this.off,other.obj,other.off);
	}
	,load_object: function(sz) {
		return this.obj.get_object(sz,this.off);
	}
	,load: function() {
		return this.obj.dVec4[this.off >> 2];
	}
	,load_bool: function() {
		return this.obj.get_bool(this.off);
	}
	,load_int8: function() {
		return this.obj.get_int8(this.off);
	}
	,load_int16: function() {
		return this.obj.get_int16(this.off);
	}
	,load_int32: function() {
		return this.obj.get_int32(this.off);
	}
	,load_int64: function() {
		return this.obj.get_int64(this.off);
	}
	,load_uint8: function() {
		return this.obj.get_uint8(this.off);
	}
	,load_uint16: function() {
		return this.obj.get_uint16(this.off);
	}
	,load_uint32: function() {
		return this.obj.get_uint32(this.off);
	}
	,load_uint64: function() {
		return this.obj.get_uint64(this.off);
	}
	,load_uintptr: function() {
		return this.obj.dVec4[this.off >> 2];
	}
	,load_float32: function() {
		return this.obj.get_float32(this.off);
	}
	,load_float64: function() {
		return this.obj.get_float64(this.off);
	}
	,load_complex64: function() {
		return this.obj.get_complex64(this.off);
	}
	,load_complex128: function() {
		return this.obj.get_complex128(this.off);
	}
	,load_string: function() {
		return this.obj.get_string(this.off);
	}
	,store_object: function(sz,v) {
		this.obj.set_object(sz,this.off,v);
	}
	,store: function(v) {
		this.obj.set(this.off,v);
	}
	,store_bool: function(v) {
		if(v) this.obj.iVec[this.off] = 1; else this.obj.iVec[this.off] = 0;
	}
	,store_int8: function(v) {
		this.obj.iVec[this.off] = v;
	}
	,store_int16: function(v) {
		this.obj.iVec[this.off] = v;
	}
	,store_int32: function(v) {
		this.obj.iVec[this.off] = v;
	}
	,store_int64: function(v) {
		this.obj.set(this.off,v);
	}
	,store_uint8: function(v) {
		this.obj.iVec[this.off] = v;
	}
	,store_uint16: function(v) {
		this.obj.iVec[this.off] = v;
	}
	,store_uint32: function(v) {
		this.obj.iVec[this.off] = v;
	}
	,store_uint64: function(v) {
		this.obj.set(this.off,v);
	}
	,store_uintptr: function(v) {
		this.obj.set(this.off,v);
	}
	,store_float32: function(v) {
		this.obj.set(this.off,v);
	}
	,store_float64: function(v) {
		this.obj.set(this.off,v);
	}
	,store_complex64: function(v) {
		this.obj.set(this.off,v);
	}
	,store_complex128: function(v) {
		this.obj.set(this.off,v);
	}
	,store_string: function(v) {
		this.obj.set(this.off,v);
	}
	,toString: function(sz) {
		if(sz == null) sz = -1;
		return " &{ " + this.obj.toString(this.off,sz) + " } ";
	}
	,__class__: tardis.Pointer
};
tardis.Slice = function(fromArray,low,high,ularraysz,isz) {
	this.baseArray = fromArray;
	this.itemSize = isz;
	if(this.baseArray == null) {
		this.start = 0;
		this.end = 0;
		this.capacity = 0;
	} else {
		if(low < 0) tardis.Scheduler.panicFromHaxe("new Slice() low bound -ve");
		this.capacity = ularraysz - low;
		if(high == -1) high = ularraysz;
		if(high > ularraysz) tardis.Scheduler.panicFromHaxe("new Slice() high bound exceeds underlying array length");
		if(low > high) tardis.Scheduler.panicFromHaxe("new Slice() low bound exceeds high bound");
		this.start = low;
		this.end = high;
	}
	this.length = this.end - this.start;
};
tardis.Slice.__name__ = true;
tardis.Slice.prototype = {
	subSlice: function(low,high) {
		if(high == -1) high = this.length;
		return new tardis.Slice(this.baseArray,low + this.start,high + this.start,this.capacity + low + this.start,this.itemSize);
	}
	,append: function(newEnt) {
		var newObj = new tardis.Object((this.length + newEnt.length) * this.itemSize);
		var _g1 = 0;
		var _g = this.length;
		while(_g1 < _g) {
			var i = _g1++;
			newObj.set_object(this.itemSize,i * this.itemSize,this.baseArray.addr((i + this.start) * this.itemSize).load_object(this.itemSize));
		}
		var _g11 = 0;
		var _g2 = newEnt.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			newObj.set_object(this.itemSize,this.length * this.itemSize + i1 * this.itemSize,newEnt.baseArray.addr((i1 + newEnt.start) * newEnt.itemSize).load_object(this.itemSize));
		}
		return new tardis.Slice(new tardis.Pointer(newObj),0,this.length + newEnt.length,this.length + newEnt.length,this.itemSize);
	}
	,copy: function(source) {
		var copySize = this.length;
		if(source.length < this.length) copySize = source.length;
		if(this.baseArray == source.baseArray) {
			if(this.start <= source.start) {
				var _g = 0;
				while(_g < copySize) {
					var i = _g++;
					this.baseArray.addr((i + this.start) * this.itemSize).store_object(this.itemSize,source.baseArray.addr((i + source.start) * source.itemSize).load_object(this.itemSize));
				}
			} else {
				var _g1 = copySize;
				while(_g1 < 0) {
					var i1 = _g1++;
					this.baseArray.addr((i1 + this.start) * this.itemSize).store_object(this.itemSize,source.baseArray.addr((i1 + source.start) * source.itemSize).load_object(this.itemSize));
				}
			}
		} else {
			var _g2 = 0;
			while(_g2 < copySize) {
				var i2 = _g2++;
				this.baseArray.addr((i2 + this.start) * this.itemSize).store_object(this.itemSize,source.baseArray.addr((i2 + source.start) * source.itemSize).load_object(this.itemSize));
			}
		}
		return copySize;
	}
	,len: function() {
		return this.length;
	}
	,cap: function() {
		return this.capacity - this.start;
	}
	,itemAddr: function(idx) {
		return this.baseArray.addr((idx + this.start) * this.itemSize);
	}
	,toString: function() {
		var ret = "Slice{" + this.start + "," + this.end + ",[";
		if(this.baseArray != null) {
			var _g1 = 0;
			var _g = this.start + this.capacity;
			while(_g1 < _g) {
				var i = _g1++;
				if(i != 0) ret += ",";
				ret += this.baseArray.addr(i * this.itemSize).toString(this.itemSize);
			}
		}
		return ret + "]}";
	}
	,__class__: tardis.Slice
};
tardis.Closure = function(f,b) {
	if(js.Boot.__instanceof(f,tardis.Closure)) {
		if(!Reflect.isFunction(f.fn)) tardis.Scheduler.panicFromHaxe("invalid function reference passed to make Closure(): " + Std.string(f.fn));
		this.fn = f.fn;
	} else {
		if(!Reflect.isFunction(f)) tardis.Scheduler.panicFromHaxe("invalid function reference passed to make Closure(): " + Std.string(f));
		this.fn = f;
	}
	if(this.fn == null) tardis.Scheduler.panicFromHaxe("new Closure() function has become null!");
	this.bds = b;
};
tardis.Closure.__name__ = true;
tardis.Closure.prototype = {
	toString: function() {
		var ret = "Closure{" + Std.string(this.fn) + ",";
		if(this.bds != null) {
			var _g1 = 0;
			var _g = this.bds.length;
			while(_g1 < _g) {
				var i = _g1++;
				if(i != 0) ret += ",";
				ret += this.bds[i];
			}
		}
		return ret + "}";
	}
	,methVal: function(t,v) {
		return this.fn.apply(null,[[],t,v]);
	}
	,callFn: function(params) {
		if(this.fn == null) tardis.Scheduler.panicFromHaxe("attempt to call null function reference in Closure.callFn()");
		if(!Reflect.isFunction(this.fn)) tardis.Scheduler.panicFromHaxe("invalid function reference in Closure(): " + Std.string(this.fn));
		return Reflect.callMethod(null,this.fn,params);
	}
	,buildCallbackFn: function() {
		var _g = this;
		var bcf = function(params) {
			if(!tardis.Go.doneInit) tardis.Go.init();
			var x = _g.bds;
			params.splice(0,0,x);
			params.splice(0,0,0);
			var SF = _g.fn.apply(null,params);
			while(SF._incomplete) tardis.Scheduler.runAll();
			return SF.res();
		};
		return Reflect.makeVarArgs(bcf);
	}
	,__class__: tardis.Closure
};
tardis.Interface = function(t,v) {
	this.typ = t;
	this.val = v;
};
tardis.Interface.__name__ = true;
tardis.Interface.prototype = {
	toString: function() {
		if(this.val == null) return "Interface{nil:" + tardis.TypeInfo.getName(this.typ) + "}"; else return "Interface{" + Std.string(this.val) + ":" + tardis.TypeInfo.getName(this.typ) + "}";
	}
	,__class__: tardis.Interface
};
tardis.Channel = function(how_many_entries) {
	if(how_many_entries <= 0) how_many_entries = 1;
	this.entries = new Array();
	this.max_entries = how_many_entries;
	this.oldest_entry = 0;
	this.num_entries = 0;
	this.closed = false;
};
tardis.Channel.__name__ = true;
tardis.Channel.prototype = {
	hasSpace: function() {
		if(this.closed) return false;
		return this.num_entries < this.max_entries;
	}
	,send: function(source) {
		if(this.closed) tardis.Scheduler.panicFromHaxe("attempt to send to closed channel");
		var next_element;
		if(this.hasSpace()) {
			next_element = (this.oldest_entry + this.num_entries) % this.max_entries;
			this.num_entries++;
			this.entries[next_element] = source;
			return true;
		} else return false;
	}
	,hasNoContents: function() {
		if(this.closed) return false; else return this.num_entries == 0;
	}
	,hasContents: function() {
		if(this.closed) return true;
		return this.num_entries != 0;
	}
	,receive: function(zero) {
		var ret = zero;
		if(this.num_entries > 0) {
			ret = this.entries[this.oldest_entry];
			this.oldest_entry = (this.oldest_entry + 1) % this.max_entries;
			this.num_entries--;
			return { r0 : ret, r1 : true};
		} else if(this.closed) return { r0 : ret, r1 : false}; else {
			tardis.Scheduler.panicFromHaxe("channel receive unreachable code!");
			return { r0 : ret, r1 : false};
		}
	}
	,__class__: tardis.Channel
};
tardis.Complex = function(r,i) {
	this.real = r;
	this.imag = i;
};
tardis.Complex.__name__ = true;
tardis.Complex.prototype = {
	__class__: tardis.Complex
};
tardis._Go = {};
tardis._Go.HaxeInt64abs_Impl_ = function() { };
tardis._Go.HaxeInt64abs_Impl_.__name__ = true;
tardis._Go.HaxeInt64abs_Impl_.toUFloat = function(vp) {
	var v = vp;
	var ret = 0.0;
	var multiplier = 1.0;
	var one;
	var v1 = new tardis.Int64(0,1);
	one = v1;
	var _g = 0;
	while(_g < 64) {
		var i = _g++;
		if(!(function($this) {
			var $r;
			var v2;
			{
				var v3 = new tardis.Int64(v.high & one.high,v.low & one.low);
				v2 = v3;
			}
			$r = (v2.high | v2.low) == 0;
			return $r;
		}(this))) ret += multiplier;
		multiplier *= 2.0;
		v = tardis._Go.HaxeInt64abs_Impl_.ushr(v,1);
	}
	return ret;
};
tardis._Go.HaxeInt64abs_Impl_.ofUFloat = function(v) {
	if(v <= 0.0) {
		var v1 = new tardis.Int64(0,0);
		return v1;
	}
	if(Math.isNaN(v)) {
		var v2 = new tardis.Int64(-2147483648,0);
		return v2;
	}
	if(v < 2147483647.0) {
		var v3 = Math.floor(v);
		var v4 = new tardis.Int64(v3 >> 31,v3);
		return v4;
	}
	if(v > 18446744073709551615.0) {
		var v5 = new tardis.Int64(-1,-1);
		return v5;
	}
	var f32 = 4294967296.0;
	var f16 = 65536.0;
	var high = Math.floor(v / f32);
	var lowFloat = Math.floor(v - high * f32);
	var lowTop16 = Math.floor(lowFloat / f16);
	var lowBot16 = Math.floor(lowFloat - lowTop16 * f16);
	var res = new tardis.Int64(high,lowBot16);
	res = tardis.Int64.or(res,tardis.Int64.shl(new tardis.Int64(0,lowTop16),16));
	return res;
};
tardis._Go.HaxeInt64abs_Impl_.ushr = function(x,y) {
	var v;
	if((y & 63) == 0) v = x; else if((y & 63) < 32) v = new tardis.Int64(x.high >>> y,x.low >>> y | x.high << (32 - (y & 63) | 0)); else v = new tardis.Int64(0,x.high >>> (y - 32 | 0));
	return v;
};
tardis._Go.HaxeInt64abs_Impl_.ucompare = function(x,y) {
	return tardis.Int64.ucompare(x,y);
};
tardis.Int64 = function(high,low) {
	this.high = high | 0;
	this.low = low | 0;
};
tardis.Int64.__name__ = true;
tardis.Int64.getLow = function(x) {
	return x.low;
};
tardis.Int64.add = function(a,b) {
	var high = a.high + b.high | 0;
	var low = a.low + b.low | 0;
	if(tardis.Int64.uicompare(low,a.low) < 0) high++;
	return new tardis.Int64(high,low);
};
tardis.Int64.shl = function(a,b) {
	if((b & 63) == 0) return a; else if((b & 63) < 32) return new tardis.Int64(a.high << b | a.low >>> (32 - (b & 63) | 0),a.low << b); else return new tardis.Int64(a.low << (b - 32 | 0),0);
};
tardis.Int64.or = function(a,b) {
	return new tardis.Int64(a.high | b.high,a.low | b.low);
};
tardis.Int64.uicompare = function(a,b) {
	if(a < 0) {
		if(b < 0) return ~b - ~a | 0; else return 1;
	} else if(b < 0) return -1; else return a - b | 0;
};
tardis.Int64.ucompare = function(a,b) {
	var v = tardis.Int64.uicompare(a.high,b.high);
	if(v != 0) return v; else return tardis.Int64.uicompare(a.low,b.low);
};
tardis.Int64.prototype = {
	__class__: tardis.Int64
};
tardis.StackFrameBasis = function(gr,ph,name) {
	this._latestBlock = 0;
	this._latestPH = 0;
	this._incomplete = true;
	this._Next = 0;
	this._goroutine = gr;
	this._functionPH = ph;
	this._functionName = name;
	this._deferStack = new List();
	this._debugVars = new haxe.ds.StringMap();
	this.setPH(ph);
};
tardis.StackFrameBasis.__name__ = true;
tardis.StackFrameBasis.prototype = {
	setPH: function(ph) {
		this._latestPH = ph;
	}
	,__class__: tardis.StackFrameBasis
};
tardis.StackFrame = function() { };
tardis.StackFrame.__name__ = true;
tardis.StackFrame.prototype = {
	__class__: tardis.StackFrame
};
tardis.Scheduler = function() { };
tardis.Scheduler.__name__ = true;
tardis.Scheduler.timerEventHandler = function(dummy) {
	if(tardis.Scheduler.runLimit < 2) tardis.Scheduler.runAll(); else tardis.Scheduler.runToStasis(tardis.Scheduler.runLimit);
};
tardis.Scheduler.runToStasis = function(cycles) {
	var lastHash = 0;
	var thisHash = tardis.Scheduler.makeStateHash();
	while(lastHash != thisHash && cycles > 0) {
		lastHash = thisHash;
		tardis.Scheduler.runAll();
		thisHash = tardis.Scheduler.makeStateHash();
		cycles -= 1;
	}
};
tardis.Scheduler.makeStateHash = function() {
	var hash = tardis.Scheduler.grStacks.length;
	var _g1 = 0;
	var _g = tardis.Scheduler.grStacks.length;
	while(_g1 < _g) {
		var gr = _g1++;
		var first = tardis.Scheduler.grStacks[gr].first();
		if(first != null) hash += first._functionPH + first._Next;
		hash <<= 1;
	}
	return hash;
};
tardis.Scheduler.runAll = function() {
	var cg = 0;
	tardis.Scheduler.entryCount++;
	if(tardis.Scheduler.entryCount > 2) throw "Scheduler.runAll() entryCount exceeded - " + tardis.Scheduler.stackDump();
	if(tardis.Scheduler.grStacks[0].isEmpty()) {
		if(tardis.Scheduler.grStacks.length <= 1) throw "Scheduler: there is only one goroutine and its stack is empty\n" + tardis.Scheduler.stackDump();
	} else tardis.Scheduler.runOne(0,tardis.Scheduler.entryCount);
	if(tardis.Scheduler.doneInit && tardis.Scheduler.entryCount == 1) {
		var _g1 = 1;
		var _g = tardis.Scheduler.grStacks.length;
		while(_g1 < _g) {
			var cg1 = _g1++;
			if(!tardis.Scheduler.grStacks[cg1].isEmpty()) tardis.Scheduler.runOne(cg1,tardis.Scheduler.entryCount);
		}
		while(tardis.Scheduler.grStacks.length > 1) if(tardis.Scheduler.grStacks[tardis.Scheduler.grStacks.length - 1].isEmpty()) tardis.Scheduler.grStacks.pop(); else break;
	}
	tardis.Scheduler.entryCount--;
};
tardis.Scheduler.runOne = function(gr,entryCount) {
	if(tardis.Scheduler.grInPanic[gr]) {
		if(entryCount != 1) {
			if(tardis.Scheduler.grStacks[gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + gr + "\n" + tardis.Scheduler.stackDump(); else {
				tardis.Scheduler.currentGR = gr;
				tardis.Scheduler.grStacks[gr].first().run();
			}
		} else while(tardis.Scheduler.grInPanic[gr]) if(tardis.Scheduler.grStacks[gr].isEmpty()) throw "Panic in goroutine " + gr + "\n" + tardis.Scheduler.panicStackDump; else {
			var sf = tardis.Scheduler.grStacks[gr].pop();
			while(!sf._deferStack.isEmpty()) {
				var def = sf._deferStack.pop();
				tardis.Scheduler.push(gr,def);
				while(def._incomplete) tardis.Scheduler.runAll();
			}
		}
	} else if(tardis.Scheduler.grStacks[gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = gr;
		tardis.Scheduler.grStacks[gr].first().run();
	}
};
tardis.Scheduler.makeGoroutine = function() {
	var _g1 = 1;
	var _g = tardis.Scheduler.grStacks.length;
	while(_g1 < _g) {
		var r = _g1++;
		if(tardis.Scheduler.grStacks[r].isEmpty()) {
			tardis.Scheduler.grInPanic[r] = false;
			tardis.Scheduler.grPanicMsg[r] = null;
			return r;
		}
	}
	var l = tardis.Scheduler.grStacks.length;
	tardis.Scheduler.grStacks[l] = new List();
	tardis.Scheduler.grInPanic[l] = false;
	tardis.Scheduler.grPanicMsg[l] = null;
	return l;
};
tardis.Scheduler.pop = function(gr) {
	if(gr >= tardis.Scheduler.grStacks.length || gr < 0) throw "Scheduler.pop() invalid goroutine";
	return tardis.Scheduler.grStacks[gr].pop();
};
tardis.Scheduler.push = function(gr,sf) {
	if(gr >= tardis.Scheduler.grStacks.length || gr < 0) throw "Scheduler.push() invalid goroutine";
	tardis.Scheduler.grStacks[gr].push(sf);
};
tardis.Scheduler.stackDump = function() {
	var ret = "";
	var gr;
	ret += "runAll() entryCount=" + tardis.Scheduler.entryCount + "\n";
	var _g1 = 0;
	var _g = tardis.Scheduler.grStacks.length;
	while(_g1 < _g) {
		var gr1 = _g1++;
		ret += "Goroutine " + gr1 + " " + Std.string(tardis.Scheduler.grPanicMsg[gr1]) + "\n";
		if(tardis.Scheduler.grStacks[gr1].isEmpty()) ret += "Stack is empty\n"; else {
			ret += "Stack has " + tardis.Scheduler.grStacks[gr1].length + " entries:\n";
			var it = tardis.Scheduler.grStacks[gr1].iterator();
			while(it.hasNext()) {
				var ent = it.next();
				if(ent == null) ret += "\tStack entry is null\n"; else {
					ret += "\t" + ent._functionName + " starting at " + tardis.Go.CPos(ent._functionPH);
					ret += " latest position " + tardis.Go.CPos(ent._latestPH);
					ret += " latest block " + ent._latestBlock + "\n";
					if(ent._debugVars != null) {
						var $it0 = ent._debugVars.keys();
						while( $it0.hasNext() ) {
							var k = $it0.next();
							if(k.indexOf(".") == -1) {
								var t = ent._debugVars.get(k);
								if(t == null) t = "nil";
								ret += "\t\tvar " + k + " = " + Std.string(t) + "\n";
							}
						}
					}
				}
			}
		}
	}
	return ret;
};
tardis.Scheduler.panic = function(gr,err) {
	if(gr >= tardis.Scheduler.grStacks.length || gr < 0) throw "Scheduler.panic() invalid goroutine";
	if(!tardis.Scheduler.grInPanic[gr]) {
		tardis.Scheduler.grInPanic[gr] = true;
		tardis.Scheduler.grPanicMsg[gr] = err;
		tardis.Scheduler.panicStackDump = tardis.Scheduler.stackDump();
	}
};
tardis.Scheduler.panicFromHaxe = function(err) {
	if(tardis.Scheduler.currentGR >= tardis.Scheduler.grStacks.length || tardis.Scheduler.currentGR < 0) tardis.Scheduler.panic(0,new tardis.Interface(tardis.TypeInfo.getId("string"),"Runtime panic, unknown goroutine, " + err + " ")); else tardis.Scheduler.panic(tardis.Scheduler.currentGR,new tardis.Interface(tardis.TypeInfo.getId("string"),"Runtime panic, " + err + " "));
	throw tardis.Scheduler.panicStackDump;
};
tardis.Scheduler.bbi = function() {
	tardis.Scheduler.panicFromHaxe("bad block ID (internal phi error)");
};
tardis.Scheduler.ioor = function() {
	tardis.Scheduler.panicFromHaxe("index out of range");
};
tardis.Scheduler.wraprangechk = function(val,sz) {
	if(val < 0 || val >= sz) tardis.Scheduler.ioor();
};
tardis._Go.Go_main_pushBooks = function(gr,_bds,p_x,p_y,p_state,p_cartLoad) {
	this._t12 = 0;
	this._t11 = null;
	tardis.StackFrameBasis.call(this,gr,93,"Go_main_pushBooks");
	this._bds = _bds;
	this.p_x = p_x;
	this.p_y = p_y;
	this.p_state = p_state;
	this.p_cartLoad = p_cartLoad;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_pushBooks.__name__ = true;
tardis._Go.Go_main_pushBooks.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_pushBooks.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_pushBooks.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g.p_state.store_int32(1);
			_g.p_x.store_float64(0);
			_g._Next = 3;
			return null;
		};
		var _Block1 = function() {
			var _t0 = 0.0;
			var _t1 = false;
			_t0 = _g.p_y.load_float64();
			_t1 = _t0 > 0;
			if(_t1) _g._Next = 4; else _g._Next = 6;
			return null;
		};
		var _Block2 = function() {
			var _t2 = 0.0;
			var _t3 = false;
			_t2 = _g.p_x.load_float64();
			_t3 = _t2 > 150;
			if(_t3) _g._Next = 7; else _g._Next = 8;
			return null;
		};
		var _Block3 = function() {
			var _t4 = 0.0;
			var _t5 = false;
			_t4 = _g.p_x.load_float64();
			_t5 = _t4 < 150;
			if(_t5) _g._Next = 1; else _g._Next = 2;
			return null;
		};
		var _Block4 = function() {
			_g.p_y.store_float64(0);
			_g._Next = 5;
			return null;
		};
		var _Block5 = function() {
			new tardis.Go_main_Gosched(_g._goroutine,[]);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			var _t7 = 0.0;
			var _t8 = 0.0;
			var _t9 = 0.0;
			var _t10 = 0.0;
			_t7 = _g.p_cartLoad;
			_t8 = tardis.Force.floatDiv(10,_t7);
			_t9 = _g.p_x.load_float64();
			_t10 = _t9 + _t8;
			_g.p_x.store_float64(_t10);
			_g._Next = 3;
			return null;
		};
		var _Block6 = function() {
			_g._t11 = new tardis.Interface(0,3);
			_g._t12 = Std.random(tardis.Force.toHaxeParam(_g._t11));
			var _t13 = 0.0;
			_t13 = _g._t12;
			_g.p_y.store_float64(_t13);
			_g._Next = 5;
			return null;
		};
		var _Block7 = function() {
			_g.p_x.store_float64(150);
			_g._Next = 8;
			return null;
		};
		var _Block8 = function() {
			_g.p_y.store_float64(0);
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_2 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_pushBooks
});
tardis._Go.Go_main_main = function(gr,_bds) {
	this._t5 = null;
	this._t4 = null;
	this._t3 = null;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,21,"Go_main_main");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_main.__name__ = true;
tardis._Go.Go_main_main.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_main.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_main_main(0,null).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
};
tardis._Go.Go_main_main.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_main.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._t0 = new tardis.Interface(0,100);
			_g._t1 = new haxe.Timer(tardis.Force.toHaxeParam(_g._t0));
			tardis.Go.main_timer.store_uintptr(_g._t1);
			tardis.Scheduler.runLimit = 10;
			_g._t3 = tardis.Go.main_timer.load_uintptr();
			_g._t4 = new tardis.Interface(1,"Scheduler.timerEventHandler");
			_g._t5 = new tardis.Interface(-1,tardis.Scheduler.timerEventHandler);
			_g._t3.run = tardis.Force.toHaxeParam(_g._t5);
			tardis.Go_main_Start.call(tardis.Scheduler.makeGoroutine(),[]);
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			return null;
		};
		var _Block_3 = function() {
			return null;
		};
		var _Block_4 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			case -3:
				retVal = _Block_3();
				break;
			case -4:
				retVal = _Block_4();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_main
});
tardis.Go_haxegoruntime_UTF16toRunes = $hx_exports.Go_haxegoruntime_UTF16toRunes = function(gr,_bds,p_s) {
	this._t0 = null;
	this._SF1 = null;
	tardis.StackFrameBasis.call(this,gr,429,"Go_haxegoruntime_UTF16toRunes");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_haxegoruntime_UTF16toRunes.__name__ = true;
tardis.Go_haxegoruntime_UTF16toRunes.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_UTF16toRunes.callFromRT = function(_gr,p_s) {
	var _sf = new tardis.Go_haxegoruntime_UTF16toRunes(_gr,null,p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
};
tardis.Go_haxegoruntime_UTF16toRunes.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_UTF16toRunes.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._SF1 = new tardis.Go_utf16_Decode(_g._goroutine,[],_g.p_s);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._t0 = _g._SF1.res();
			_g._res = _g._t0;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_haxegoruntime_UTF16toRunes
});
tardis._Go.Go_haxegoruntime_init = function(gr,_bds) {
	this._t5 = 0;
	tardis.StackFrameBasis.call(this,gr,430,"Go_haxegoruntime_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_haxegoruntime_init.__name__ = true;
tardis._Go.Go_haxegoruntime_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_haxegoruntime_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_haxegoruntime_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = tardis.Go.haxegoruntime_init_36_guard.load_bool();
			if(_t0) _g._Next = 2; else _g._Next = 1;
			return null;
		};
		var _Block1 = function() {
			tardis.Go.haxegoruntime_init_36_guard.store_bool(true);
			new tardis._Go.Go_utf16_init(_g._goroutine,[]).run();
			new tardis._Go.Go_utf8_init(_g._goroutine,[]).run();
			new tardis._Go.Go_golibruntime_init(_g._goroutine,[]);
			_g._Next = -4;
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			return null;
		};
		var _Block_3 = function() {
			return null;
		};
		var _Block_4 = function() {
			var _a = null;
			_g._t5 = "字".length;
			tardis.Go.haxegoruntime_ZiLen.store_int32(_g._t5);
			_g._Next = 2;
			return null;
		};
		var _Block2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_5 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			case -3:
				retVal = _Block_3();
				break;
			case -4:
				retVal = _Block_4();
				break;
			case -5:
				retVal = _Block_5();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_haxegoruntime_init
});
tardis._Go.Go_utf8_init = function(gr,_bds) {
	tardis.StackFrameBasis.call(this,gr,426,"Go_utf8_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_utf8_init.__name__ = true;
tardis._Go.Go_utf8_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_utf8_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_utf8_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = tardis.Go.utf8_init_36_guard.load_bool();
			if(_t0) _g._Next = 2; else _g._Next = 1;
			return null;
		};
		var _Block1 = function() {
			tardis.Go.utf8_init_36_guard.store_bool(true);
			_g._Next = 2;
			return null;
		};
		var _Block2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_utf8_init
});
tardis._Go.Go_golibruntime_init = function(gr,_bds) {
	tardis.StackFrameBasis.call(this,gr,426,"Go_golibruntime_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_golibruntime_init.__name__ = true;
tardis._Go.Go_golibruntime_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_golibruntime_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_golibruntime_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = tardis.Go.golibruntime_init_36_guard.load_bool();
			if(_t0) _g._Next = 2; else _g._Next = 1;
			return null;
		};
		var _Block1 = function() {
			tardis.Go.golibruntime_init_36_guard.store_bool(true);
			new tardis._Go.Go_tgoaddmath_init(_g._goroutine,[]);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._Next = 2;
			return null;
		};
		var _Block2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_golibruntime_init
});
tardis._Go.Go_main_makeHeadline = function(gr,_bds,p_e) {
	this._t8 = 0;
	this._t6 = "";
	this._t5 = "";
	this._t4 = "";
	this._t1 = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,205,"Go_main_makeHeadline");
	this._bds = _bds;
	this.p_e = p_e;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_makeHeadline.__name__ = true;
tardis._Go.Go_main_makeHeadline.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_makeHeadline.call = function(gr,_bds,p_e) {
	return new tardis._Go.Go_main_makeHeadline(gr,_bds,p_e);
};
tardis._Go.Go_main_makeHeadline.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_makeHeadline.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._t0 = new Date();
			_g._t1 = _g._t0.getSeconds();
			var _t2 = 0;
			var _t3 = false;
			_t2 = tardis.Go.main_lastTime.load_int32();
			_t3 = _g._t1 != _t2;
			if(_t3) _g._Next = 1; else _g._Next = 2;
			return null;
		};
		var _Block1 = function() {
			_g._t4 = HxOverrides.dateStr(_g._t0);
			_g._t5 = "Translated by TARDIS Go into JS and running live: " + _g._t4;
			_g._t6 = tardis.Go.main_lastHeading.load_string();
			new tardis._Go.Go_main_makeText(_g._goroutine,[],false,195,15,500,20,32768,_g._t6,_g._t5);
			_g._Next = -4;
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			return null;
		};
		var _Block_3 = function() {
			return null;
		};
		var _Block_4 = function() {
			_g._t8 = _g._t0.getSeconds();
			tardis.Go.main_lastTime.store_int32(_g._t8);
			tardis.Go.main_lastHeading.store_string(_g._t5);
			_g._Next = 2;
			return null;
		};
		var _Block2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_5 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			case -3:
				retVal = _Block_3();
				break;
			case -4:
				retVal = _Block_4();
				break;
			case -5:
				retVal = _Block_5();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_makeHeadline
});
tardis._Go.Go_main_replaceBitmap = function(gr,_bds,p_sprite,p_bitmap) {
	this._t11 = null;
	this._t10 = null;
	this._t9 = null;
	this._t2 = null;
	tardis.StackFrameBasis.call(this,gr,291,"Go_main_replaceBitmap");
	this._bds = _bds;
	this.p_sprite = p_sprite;
	this.p_bitmap = p_bitmap;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_replaceBitmap.__name__ = true;
tardis._Go.Go_main_replaceBitmap.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_replaceBitmap.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_replaceBitmap.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = null;
			var _t1 = null;
			var _t3 = null;
			var _t4 = null;
			var _t5 = null;
			var _t6 = 0;
			var _t7 = null;
			var _t8 = 0;
			_t0 = _g.p_sprite.addr(0);
			_t1 = _g.p_bitmap.load_uintptr();
			_t0.obj.set(_t0.off,_t1);
			_g._t2 = tardis.Go.main_context.load_uintptr();
			_t3 = _g.p_sprite.addr(0);
			_t4 = _t3.obj.dVec4[_t3.off >> 2];
			_t5 = _g.p_sprite.addr(4);
			_t6 = _t5.obj.get_int32(_t5.off);
			_t7 = _g.p_sprite.addr(8);
			_t8 = _t7.obj.get_int32(_t7.off);
			_g._t9 = new tardis.Interface(2,_t4);
			_g._t10 = new tardis.Interface(0,_t6);
			_g._t11 = new tardis.Interface(0,_t8);
			_g._t2.drawImage(tardis.Force.toHaxeParam(_g._t9),tardis.Force.toHaxeParam(_g._t10),tardis.Force.toHaxeParam(_g._t11));
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_replaceBitmap
});
tardis._Go.Go_main_delay = function(gr,_bds,p_n) {
	this._t7 = null;
	this._t5 = null;
	this._t4 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,129,"Go_main_delay");
	this._bds = _bds;
	this.p_n = p_n;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_delay.__name__ = true;
tardis._Go.Go_main_delay.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_delay.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_delay.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t1 = null;
			var _t2 = null;
			var _t3 = 0;
			_g._t0 = new tardis.Pointer(new tardis.Object(4));
			_t1 = new tardis.Channel(0);
			_g._t0.store(_t1);
			_t2 = new tardis.Closure(new tardis.Closure(tardis._Go.Go_main_delay_36_1.call,null),{ w : _g._t0});
			_t3 = _g.p_n * 250 >> 0;
			_g._t4 = new tardis.Interface(3,_t2);
			_g._t5 = new tardis.Interface(0,_t3);
			haxe.Timer.delay(tardis.Force.toHaxeParam(_g._t4),tardis.Force.toHaxeParam(_g._t5));
			_g._t7 = _g._t0.load();
			_g._Next = -2;
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			if(_g._t7.hasNoContents()) return _g;
			_g._t7.receive(new tardis.Object(0)).r0;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_delay
});
tardis.Go_main_Start_36_1 = $hx_exports.Go_main_Start_36_1 = function(gr,_bds) {
	this._t0 = null;
	this._SF1 = null;
	tardis.StackFrameBasis.call(this,gr,228,"Go_main_Start_36_1");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_main_Start_36_1.__name__ = true;
tardis.Go_main_Start_36_1.__interfaces__ = [tardis.StackFrame];
tardis.Go_main_Start_36_1.call = function(gr,_bds) {
	return new tardis.Go_main_Start_36_1(gr,_bds);
};
tardis.Go_main_Start_36_1.__super__ = tardis.StackFrameBasis;
tardis.Go_main_Start_36_1.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._SF1 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/bigpile.png");
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._t0 = _g._SF1.res();
			new tardis._Go.Go_main_makeSprite(_g._goroutine,[],_g._t0,10,20);
			_g._Next = -2;
			return _g;
		};
		var _Block_2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_main_Start_36_1
});
tardis._Go.Go_main_makeSprite_36_1 = function(gr,_bds,p_e) {
	this._t6 = null;
	this._t5 = null;
	this._t4 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,183,"Go_main_makeSprite_36_1");
	this._bds = _bds;
	this.p_e = p_e;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_makeSprite_36_1.__name__ = true;
tardis._Go.Go_main_makeSprite_36_1.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_makeSprite_36_1.call = function(gr,_bds,p_e) {
	return new tardis._Go.Go_main_makeSprite_36_1(gr,_bds,p_e);
};
tardis._Go.Go_main_makeSprite_36_1.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_makeSprite_36_1.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t1 = null;
			var _t2 = 0;
			var _t3 = 0;
			_g._t0 = tardis.Go.main_context.load_uintptr();
			_t1 = _g._bds.bitmap.load_uintptr();
			_t2 = _g._bds.x.load_int32();
			_t3 = _g._bds.y.load_int32();
			_g._t4 = new tardis.Interface(2,_t1);
			_g._t5 = new tardis.Interface(0,_t2);
			_g._t6 = new tardis.Interface(0,_t3);
			_g._t0.drawImage(tardis.Force.toHaxeParam(_g._t4),tardis.Force.toHaxeParam(_g._t5),tardis.Force.toHaxeParam(_g._t6));
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_makeSprite_36_1
});
tardis.Go_main_Start_36_2 = $hx_exports.Go_main_Start_36_2 = function(gr,_bds) {
	this._t0 = null;
	this._SF1 = null;
	tardis.StackFrameBasis.call(this,gr,230,"Go_main_Start_36_2");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_main_Start_36_2.__name__ = true;
tardis.Go_main_Start_36_2.__interfaces__ = [tardis.StackFrame];
tardis.Go_main_Start_36_2.call = function(gr,_bds) {
	return new tardis.Go_main_Start_36_2(gr,_bds);
};
tardis.Go_main_Start_36_2.__super__ = tardis.StackFrameBasis;
tardis.Go_main_Start_36_2.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._SF1 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/oven.png");
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._t0 = _g._SF1.res();
			new tardis._Go.Go_main_makeSprite(_g._goroutine,[],_g._t0,690,0);
			_g._Next = -2;
			return _g;
		};
		var _Block_2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_main_Start_36_2
});
tardis._Go.Go_tardisgolib_init = function(gr,_bds) {
	tardis.StackFrameBasis.call(this,gr,230,"Go_tardisgolib_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_tardisgolib_init.__name__ = true;
tardis._Go.Go_tardisgolib_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_tardisgolib_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_tardisgolib_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = tardis.Go.tardisgolib_init_36_guard.load_bool();
			if(_t0) _g._Next = 2; else _g._Next = 1;
			return null;
		};
		var _Block1 = function() {
			tardis.Go.tardisgolib_init_36_guard.store_bool(true);
			var _t2 = null;
			_t2 = new tardis.Channel(0);
			tardis.Go.tardisgolib_gosched_chan.store(_t2);
			_g._Next = 2;
			return null;
		};
		var _Block2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_tardisgolib_init
});
tardis.Go_utf8_RuneLen = $hx_exports.Go_utf8_RuneLen = function(gr,_bds,p_r) {
	tardis.StackFrameBasis.call(this,gr,967,"Go_utf8_RuneLen");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_utf8_RuneLen.__name__ = true;
tardis.Go_utf8_RuneLen.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_RuneLen.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_RuneLen.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _t5 = false;
		var _t6 = false;
		var _Phi = 0;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = _g.p_r < 0;
			if(_t0) _g._Next = 1; else _g._Next = 3;
			_Phi = 0;
			return null;
		};
		var _Block1 = function() {
			_g._res = -1;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block2 = function() {
			_g._res = 1;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block3 = function() {
			var _t1 = false;
			_t1 = _g.p_r <= 127;
			if(_t1) _g._Next = 2; else _g._Next = 5;
			_Phi = 3;
			return null;
		};
		var _Block4 = function() {
			_g._res = 2;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block5 = function() {
			var _t2 = false;
			_t2 = _g.p_r <= 2047;
			if(_t2) _g._Next = 4; else _g._Next = 7;
			_Phi = 5;
			return null;
		};
		var _Block6 = function() {
			_g._res = -1;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block7 = function() {
			var _t3 = false;
			_t3 = 55296 <= _g.p_r;
			if(_t3) _g._Next = 10; else _g._Next = 11;
			_Phi = 7;
			return null;
		};
		var _Block8 = function() {
			_g._res = 3;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block9 = function() {
			var _t4 = false;
			_t4 = _g.p_r <= 65535;
			if(_t4) _g._Next = 8; else _g._Next = 13;
			_Phi = 9;
			return null;
		};
		var _Block10 = function() {
			_t5 = _g.p_r <= 57343;
			_g._Next = 11;
			_Phi = 10;
			return null;
		};
		var _Block11 = function() {
			if(_Phi == 7) _t6 = false; else if(_Phi == 10) _t6 = _t5; else _t6 = false;
			if(_t6) _g._Next = 6; else _g._Next = 9;
			_Phi = 11;
			return null;
		};
		var _Block12 = function() {
			_g._res = 4;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block13 = function() {
			var _t7 = false;
			_t7 = _g.p_r <= 1114111;
			if(_t7) _g._Next = 12; else _g._Next = 14;
			_Phi = 13;
			return null;
		};
		var _Block14 = function() {
			_g._res = -1;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case 9:
				retVal = _Block9();
				break;
			case 10:
				retVal = _Block10();
				break;
			case 11:
				retVal = _Block11();
				break;
			case 12:
				retVal = _Block12();
				break;
			case 13:
				retVal = _Block13();
				break;
			case 14:
				retVal = _Block14();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_utf8_RuneLen
});
tardis.Go_main_Gosched = $hx_exports.Go_main_Gosched = function(gr,_bds) {
	tardis.StackFrameBasis.call(this,gr,380,"Go_main_Gosched");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_main_Gosched.__name__ = true;
tardis.Go_main_Gosched.__interfaces__ = [tardis.StackFrame];
tardis.Go_main_Gosched.__super__ = tardis.StackFrameBasis;
tardis.Go_main_Gosched.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			new tardis._Go.Go_main_monitor(_g._goroutine,[]);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			new tardis.Go_tardisgolib_Gosched(_g._goroutine,[]);
			_g._Next = -2;
			return _g;
		};
		var _Block_2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_main_Gosched
});
tardis._Go.Go_main_pickBooks = function(gr,_bds,p_x,p_y,p_state,p_in) {
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,86,"Go_main_pickBooks");
	this._bds = _bds;
	this.p_x = p_x;
	this.p_y = p_y;
	this.p_state = p_state;
	this.p_in = p_in;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_pickBooks.__name__ = true;
tardis._Go.Go_main_pickBooks.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_pickBooks.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_pickBooks.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g.p_state.store_int32(0);
			_g.p_x.store_float64(0);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			if(_g.p_in.hasNoContents()) return _g;
			_g._t0 = _g.p_in.receive(0).r0;
			new tardis._Go.Go_main_delay(_g._goroutine,[],_g._t0);
			_g._Next = -2;
			return _g;
		};
		var _Block_2 = function() {
			_g._res = _g._t0;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_pickBooks
});
tardis._Go.Go_main_makeText = function(gr,_bds,p_selectable,p_x,p_y,p_width,p_height,p_textColor,p_oldtext,p_text) {
	this._Phi = 0;
	this._t45 = null;
	this._t44 = null;
	this._t43 = null;
	this._t38 = null;
	this._t34 = 0;
	this._t33 = 0;
	this._t26 = null;
	this._t22 = 0;
	this._t20 = 0;
	this._t18 = null;
	this._t17 = null;
	this._t16 = null;
	this._t15 = null;
	this._t13 = null;
	this._t11 = null;
	this._t10 = null;
	this._t8 = null;
	this._t7 = null;
	this._t6 = null;
	this._t3 = null;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,148,"Go_main_makeText");
	this._bds = _bds;
	this.p_selectable = p_selectable;
	this.p_x = p_x;
	this.p_y = p_y;
	this.p_width = p_width;
	this.p_height = p_height;
	this.p_textColor = p_textColor;
	this.p_oldtext = p_oldtext;
	this.p_text = p_text;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_makeText.__name__ = true;
tardis._Go.Go_main_makeText.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_makeText.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_makeText.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._t0 = tardis.Go.main_context.load_uintptr();
			_g._t1 = "#fff";
			_g._t0.fillStyle = _g._t1;
			var _t4 = 0.0;
			var _t5 = 0.0;
			_g._t3 = tardis.Go.main_context.load_uintptr();
			_t4 = _g.p_x;
			_t5 = _g.p_y;
			_g._t6 = new tardis.Interface(1,_g.p_oldtext);
			_g._t7 = new tardis.Interface(4,_t4);
			_g._t8 = new tardis.Interface(4,_t5);
			_g._t3.fillText(tardis.Force.toHaxeParam(_g._t6),tardis.Force.toHaxeParam(_g._t7),tardis.Force.toHaxeParam(_g._t8));
			_g._t10 = tardis.Go.main_context.load_uintptr();
			_g._t11 = "#373";
			_g._t10.fillStyle = _g._t11;
			_g._t13 = tardis.Go.main_context.load_uintptr();
			_g._t13.font = "12px Arial";
			_g._t15 = new tardis.Slice(new tardis.Pointer(new tardis.Object(8)),0,1,1,8);
			_g._t16 = { k : 0, v : tardis.Force.toUTF8slice(_g._goroutine,_g.p_text)};
			_g._Next = 1;
			_g._Phi = 0;
			return null;
		};
		var _Block1 = function() {
			if(_g._Phi == 0) _g._t17 = _g._t15; else if(_g._Phi == 4) _g._t17 = _g._t26; else if(_g._Phi == 5) _g._t17 = _g._t17; else _g._t17 = new tardis.Slice(new tardis.Pointer(new tardis.Object(0)),0,0,0,8);
			var _t19 = false;
			var _thisK = _g._t16.k;
			if(_g._t16.k >= _g._t16.v.len()) _g._t18 = { r0 : false, r1 : 0, r2 : 0}; else {
				var _dr = tardis.Go_utf8_DecodeRune.callFromRT(_g._goroutine,_g._t16.v.subSlice(_thisK,-1));
				_g._t16.k += _dr.r1;
				_g._t18 = { r0 : true, r1 : js.Boot.__cast(_thisK , Int), r2 : js.Boot.__cast(_dr.r0 , Int)};
			}
			_t19 = _g._t18.r0;
			if(_t19) _g._Next = 2; else _g._Next = 3;
			_g._Phi = 1;
			return null;
		};
		var _Block2 = function() {
			var _t21 = false;
			_g._t20 = _g._t18.r2;
			_t21 = _g._t20 == 10;
			if(_t21) _g._Next = 4; else _g._Next = 5;
			_g._Phi = 2;
			return null;
		};
		var _Block3 = function() {
			var _v = _g._t17;
			if(_v == null) _g._t22 = 0; else _g._t22 = _v.length;
			_g._Next = 6;
			_g._Phi = 3;
			return null;
		};
		var _Block4 = function() {
			var _t23 = null;
			var _t24 = null;
			var _t25 = null;
			_t23 = new tardis.Pointer(new tardis.Object(8));
			_t24 = _t23.addr(0);
			_t24.obj.set(_t24.off,"");
			_t25 = new tardis.Slice(_t23,0,-1,1,8);
			_g._t26 = _g._t17.append(_t25);
			_g._Next = 1;
			_g._Phi = 4;
			return null;
		};
		var _Block5 = function() {
			var _t27 = 0;
			var _t28 = 0;
			var _t29 = null;
			var _t30 = "";
			var _t31 = "";
			var _t32 = "";
			var _v1 = _g._t17;
			if(_v1 == null) _t27 = 0; else _t27 = _v1.length;
			_t28 = _t27 - 1 >> 0;
			if(_t28 < 0 || _t28 >= _g._t17.length) tardis.Scheduler.ioor();
			_t29 = _g._t17.itemAddr(_t28);
			var _r = tardis.Go_haxegoruntime_Rune2Raw.callFromRT(_g._goroutine,_g._t20);
			_t30 = "";
			var _g2 = 0;
			var _g1 = _r.length;
			while(_g2 < _g1) {
				var _i = _g2++;
				_t30 += String.fromCharCode(_r.baseArray.addr((_i + _r.start) * _r.itemSize).load_int32());
			}
			_t31 = _t29.obj.get_string(_t29.off);
			_t32 = _t31 + _t30;
			_t29.obj.set(_t29.off,_t32);
			_g._Next = 1;
			_g._Phi = 5;
			return null;
		};
		var _Block6 = function() {
			if(_g._Phi == 3) _g._t33 = -1; else if(_g._Phi == 7) _g._t33 = _g._t34; else _g._t33 = 0;
			var _t35 = false;
			_g._t34 = _g._t33 + 1 >> 0;
			_t35 = _g._t34 < _g._t22;
			if(_t35) _g._Next = 7; else _g._Next = 8;
			_g._Phi = 6;
			return null;
		};
		var _Block7 = function() {
			var _t36 = null;
			var _t37 = "";
			var _t39 = 0.0;
			var _t40 = 0;
			var _t41 = 0;
			var _t42 = 0.0;
			tardis.Scheduler.wraprangechk(_g._t34,_g._t17.length);
			_t36 = _g._t17.itemAddr(_g._t34);
			_t37 = _t36.obj.get_string(_t36.off);
			_g._t38 = tardis.Go.main_context.load_uintptr();
			_t39 = _g.p_x;
			_t40 = 12 * _g._t34 >> 0;
			_t41 = _g.p_y + _t40 >> 0;
			_t42 = _t41;
			_g._t43 = new tardis.Interface(1,_t37);
			_g._t44 = new tardis.Interface(4,_t39);
			_g._t45 = new tardis.Interface(4,_t42);
			_g._t38.fillText(tardis.Force.toHaxeParam(_g._t43),tardis.Force.toHaxeParam(_g._t44),tardis.Force.toHaxeParam(_g._t45));
			_g._Next = 6;
			_g._Phi = 7;
			return null;
		};
		var _Block8 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			return null;
		};
		var _Block_3 = function() {
			return null;
		};
		var _Block_4 = function() {
			return null;
		};
		var _Block_5 = function() {
			return null;
		};
		var _Block_6 = function() {
			return null;
		};
		var _Block_7 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g3 = this._Next;
			switch(_g3) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			case -3:
				retVal = _Block_3();
				break;
			case -4:
				retVal = _Block_4();
				break;
			case -5:
				retVal = _Block_5();
				break;
			case -6:
				retVal = _Block_6();
				break;
			case -7:
				retVal = _Block_7();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_makeText
});
tardis.Go_utf16_IsSurrogate = $hx_exports.Go_utf16_IsSurrogate = function(gr,_bds,p_r) {
	tardis.StackFrameBasis.call(this,gr,569,"Go_utf16_IsSurrogate");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_utf16_IsSurrogate.__name__ = true;
tardis.Go_utf16_IsSurrogate.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf16_IsSurrogate.__super__ = tardis.StackFrameBasis;
tardis.Go_utf16_IsSurrogate.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _t1 = false;
		var _t2 = false;
		var _Phi = 0;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = 55296 <= _g.p_r;
			if(_t0) _g._Next = 1; else _g._Next = 2;
			_Phi = 0;
			return null;
		};
		var _Block1 = function() {
			_t1 = _g.p_r < 57344;
			_g._Next = 2;
			_Phi = 1;
			return null;
		};
		var _Block2 = function() {
			if(_Phi == 0) _t2 = false; else if(_Phi == 1) _t2 = _t1; else _t2 = false;
			_g._res = _t2;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_utf16_IsSurrogate
});
tardis.Go_utf8_EncodeRune = $hx_exports.Go_utf8_EncodeRune = function(gr,_bds,p_p,p_r) {
	tardis.StackFrameBasis.call(this,gr,987,"Go_utf8_EncodeRune");
	this._bds = _bds;
	this.p_p = p_p;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_utf8_EncodeRune.__name__ = true;
tardis.Go_utf8_EncodeRune.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_EncodeRune.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_EncodeRune.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _t0 = 0;
		var _t14 = 0;
		var _t30 = false;
		var _t31 = false;
		var _Phi = 0;
		var _Block0 = function() {
			var _t1 = false;
			_t0 = _g.p_r;
			_t1 = tardis.Force.uintCompare(_t0,127) <= 0;
			if(_t1) _g._Next = 1; else _g._Next = 3;
			_Phi = 0;
			return null;
		};
		var _Block1 = function() {
			var _t2 = null;
			var _t3 = 0;
			if(0 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t2 = _g.p_p.itemAddr(0);
			_t3 = _g.p_r;
			_t2.obj.iVec[_t2.off] = _t3;
			_g._res = 1;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block2 = function() {
			var _t4 = null;
			var _t5 = 0;
			var _t6 = 0;
			var _t7 = 0;
			var _t8 = null;
			var _t9 = 0;
			var _t10 = 0;
			var _t11 = 0;
			if(0 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t4 = _g.p_p.itemAddr(0);
			var _v1 = _g.p_r;
			var _v2;
			var v;
			var v1 = new tardis.Int64(0,6);
			v = v1;
			_v2 = tardis.Int64.getLow(v);
			if(_v2 == 0) _t5 = _v1; else _t5 = _v1 >> _v2;
			_t6 = _t5;
			_t7 = (192 | _t6) & 255;
			_t4.obj.iVec[_t4.off] = _t7;
			if(1 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t8 = _g.p_p.itemAddr(1);
			_t9 = _g.p_r;
			_t10 = _t9 & 63 & 255;
			_t11 = (128 | _t10) & 255;
			_t8.obj.iVec[_t8.off] = _t11;
			_g._res = 2;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block3 = function() {
			var _t12 = false;
			_t12 = tardis.Force.uintCompare(_t0,2047) <= 0;
			if(_t12) _g._Next = 2; else _g._Next = 5;
			_Phi = 3;
			return null;
		};
		var _Block4 = function() {
			_g._Next = 6;
			_Phi = 4;
			return null;
		};
		var _Block5 = function() {
			var _t13 = false;
			_t13 = tardis.Force.uintCompare(_t0,1114111) > 0;
			if(_t13) _g._Next = 4; else _g._Next = 7;
			_Phi = 5;
			return null;
		};
		var _Block6 = function() {
			if(_Phi == 4) _t14 = 65533; else if(_Phi == 8) _t14 = _g.p_r; else _t14 = 0;
			var _t15 = null;
			var _t16 = 0;
			var _t17 = 0;
			var _t18 = 0;
			var _t19 = null;
			var _t20 = 0;
			var _t21 = 0;
			var _t22 = 0;
			var _t23 = 0;
			var _t24 = null;
			var _t25 = 0;
			var _t26 = 0;
			var _t27 = 0;
			if(0 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t15 = _g.p_p.itemAddr(0);
			var _v11 = _t14;
			var _v21;
			var v2;
			var v3 = new tardis.Int64(0,12);
			v2 = v3;
			_v21 = tardis.Int64.getLow(v2);
			if(_v21 == 0) _t16 = _v11; else _t16 = _v11 >> _v21;
			_t17 = _t16;
			_t18 = (224 | _t17) & 255;
			_t15.obj.iVec[_t15.off] = _t18;
			if(1 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t19 = _g.p_p.itemAddr(1);
			var _v12 = _t14;
			var _v22;
			var v4;
			var v5 = new tardis.Int64(0,6);
			v4 = v5;
			_v22 = tardis.Int64.getLow(v4);
			if(_v22 == 0) _t20 = _v12; else _t20 = _v12 >> _v22;
			_t21 = _t20;
			_t22 = _t21 & 63 & 255;
			_t23 = (128 | _t22) & 255;
			_t19.obj.iVec[_t19.off] = _t23;
			if(2 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t24 = _g.p_p.itemAddr(2);
			_t25 = _t14;
			_t26 = _t25 & 63 & 255;
			_t27 = (128 | _t26) & 255;
			_t24.obj.iVec[_t24.off] = _t27;
			_g._res = 3;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block7 = function() {
			var _t28 = false;
			_t28 = tardis.Force.uintCompare(55296,_t0) <= 0;
			if(_t28) _g._Next = 9; else _g._Next = 10;
			_Phi = 7;
			return null;
		};
		var _Block8 = function() {
			var _t29 = false;
			_t29 = tardis.Force.uintCompare(_t0,65535) <= 0;
			if(_t29) _g._Next = 6; else _g._Next = 11;
			_Phi = 8;
			return null;
		};
		var _Block9 = function() {
			_t30 = tardis.Force.uintCompare(_t0,57343) <= 0;
			_g._Next = 10;
			_Phi = 9;
			return null;
		};
		var _Block10 = function() {
			if(_Phi == 7) _t31 = false; else if(_Phi == 9) _t31 = _t30; else _t31 = false;
			if(_t31) _g._Next = 4; else _g._Next = 8;
			_Phi = 10;
			return null;
		};
		var _Block11 = function() {
			var _t32 = null;
			var _t33 = 0;
			var _t34 = 0;
			var _t35 = 0;
			var _t36 = null;
			var _t37 = 0;
			var _t38 = 0;
			var _t39 = 0;
			var _t40 = 0;
			var _t41 = null;
			var _t42 = 0;
			var _t43 = 0;
			var _t44 = 0;
			var _t45 = 0;
			var _t46 = null;
			var _t47 = 0;
			var _t48 = 0;
			var _t49 = 0;
			if(0 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t32 = _g.p_p.itemAddr(0);
			var _v13 = _g.p_r;
			var _v23;
			var v6;
			var v7 = new tardis.Int64(0,18);
			v6 = v7;
			_v23 = tardis.Int64.getLow(v6);
			if(_v23 == 0) _t33 = _v13; else _t33 = _v13 >> _v23;
			_t34 = _t33;
			_t35 = (240 | _t34) & 255;
			_t32.obj.iVec[_t32.off] = _t35;
			if(1 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t36 = _g.p_p.itemAddr(1);
			var _v14 = _g.p_r;
			var _v24;
			var v8;
			var v9 = new tardis.Int64(0,12);
			v8 = v9;
			_v24 = tardis.Int64.getLow(v8);
			if(_v24 == 0) _t37 = _v14; else _t37 = _v14 >> _v24;
			_t38 = _t37;
			_t39 = _t38 & 63 & 255;
			_t40 = (128 | _t39) & 255;
			_t36.obj.iVec[_t36.off] = _t40;
			if(2 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t41 = _g.p_p.itemAddr(2);
			var _v15 = _g.p_r;
			var _v25;
			var v10;
			var v11 = new tardis.Int64(0,6);
			v10 = v11;
			_v25 = tardis.Int64.getLow(v10);
			if(_v25 == 0) _t42 = _v15; else _t42 = _v15 >> _v25;
			_t43 = _t42;
			_t44 = _t43 & 63 & 255;
			_t45 = (128 | _t44) & 255;
			_t41.obj.iVec[_t41.off] = _t45;
			if(3 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t46 = _g.p_p.itemAddr(3);
			_t47 = _g.p_r;
			_t48 = _t47 & 63 & 255;
			_t49 = (128 | _t48) & 255;
			_t46.obj.iVec[_t46.off] = _t49;
			_g._res = 4;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case 9:
				retVal = _Block9();
				break;
			case 10:
				retVal = _Block10();
				break;
			case 11:
				retVal = _Block11();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_utf8_EncodeRune
});
tardis._Go.Go_tgoaddmath_init_35_1 = function(gr,_bds) {
	tardis.StackFrameBasis.call(this,gr,1272,"Go_tgoaddmath_init_35_1");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_tgoaddmath_init_35_1.__name__ = true;
tardis._Go.Go_tgoaddmath_init_35_1.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_tgoaddmath_init_35_1.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_tgoaddmath_init_35_1.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._Next = 2;
			return null;
		};
		var _Block1 = function() {
			new tardis._Go.Go_tgoaddmath_glrFloat32bits(_g._goroutine,[],0);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			new tardis._Go.Go_tgoaddmath_glrFloat32frombits(_g._goroutine,[],0);
			_g._Next = -2;
			return _g;
		};
		var _Block_2 = function() {
			new tardis._Go.Go_tgoaddmath_glrFloat64bits(_g._goroutine,[],0).run();
			tardis._Go.Go_tgoaddmath_glrFloat64frombits.call(_g._goroutine,[],(function($this) {
				var $r;
				var v = new tardis.Int64(0,0);
				$r = v;
				return $r;
			}(this)));
			_g._Next = -4;
			return _g;
		};
		var _Block_3 = function() {
			return null;
		};
		var _Block_4 = function() {
			_g._Next = 2;
			return null;
		};
		var _Block2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			case -3:
				retVal = _Block_3();
				break;
			case -4:
				retVal = _Block_4();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_tgoaddmath_init_35_1
});
tardis._Go.Go_main_fire = function(gr,_bds) {
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,70,"Go_main_fire");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_fire.__name__ = true;
tardis._Go.Go_main_fire.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_fire.call = function(gr,_bds) {
	return new tardis._Go.Go_main_fire(gr,_bds);
};
tardis._Go.Go_main_fire.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_fire.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._Next = 1;
			return null;
		};
		var _Block1 = function() {
			_g._t0 = tardis.Go.main_oven.load();
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			if(_g._t0.hasNoContents()) return _g;
			_g._t0.receive(0).r0;
			_g._Next = 1;
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_fire
});
tardis._Go.Go_main_makeSprite = function(gr,_bds,p_bitmap,p_x,p_y) {
	this._t22 = null;
	this._t20 = null;
	this._t13 = null;
	this._t11 = null;
	this._t10 = null;
	this._t9 = null;
	this._t5 = null;
	this._t4 = false;
	this._t3 = null;
	this._t2 = null;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,179,"Go_main_makeSprite");
	this._bds = _bds;
	this.p_bitmap = p_bitmap;
	this.p_x = p_x;
	this.p_y = p_y;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_makeSprite.__name__ = true;
tardis._Go.Go_main_makeSprite.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_makeSprite.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_makeSprite.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._t0 = new tardis.Pointer(new tardis.Object(4));
			_g._t0.store_uintptr(_g.p_bitmap);
			_g._t1 = new tardis.Pointer(new tardis.Object(4));
			_g._t1.store_int32(_g.p_x);
			_g._t2 = new tardis.Pointer(new tardis.Object(4));
			_g._t2.store_int32(_g.p_y);
			_g._t3 = _g._t0.load_uintptr();
			_g._t4 = _g._t3.complete;
			if(_g._t4) _g._Next = 1; else _g._Next = 3;
			return null;
		};
		var _Block1 = function() {
			var _t6 = null;
			var _t7 = 0;
			var _t8 = 0;
			_g._t5 = tardis.Go.main_context.load_uintptr();
			_t6 = _g._t0.load_uintptr();
			_t7 = _g._t1.load_int32();
			_t8 = _g._t2.load_int32();
			_g._t9 = new tardis.Interface(2,_t6);
			_g._t10 = new tardis.Interface(0,_t7);
			_g._t11 = new tardis.Interface(0,_t8);
			_g._t5.drawImage(tardis.Force.toHaxeParam(_g._t9),tardis.Force.toHaxeParam(_g._t10),tardis.Force.toHaxeParam(_g._t11));
			_g._Next = 2;
			return null;
		};
		var _Block2 = function() {
			var _t14 = null;
			var _t15 = null;
			var _t16 = null;
			var _t17 = 0;
			var _t18 = null;
			var _t19 = 0;
			_g._t13 = new tardis.Pointer(new tardis.Object(12));
			_t14 = _g._t13.addr(0);
			_t15 = _g._t0.load_uintptr();
			_t14.obj.set(_t14.off,_t15);
			_t16 = _g._t13.addr(4);
			_t17 = _g._t1.load_int32();
			_t16.obj.iVec[_t16.off] = _t17;
			_t18 = _g._t13.addr(8);
			_t19 = _g._t2.load_int32();
			_t18.obj.iVec[_t18.off] = _t19;
			_g._res = _g._t13;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block3 = function() {
			var _t21 = null;
			_g._t20 = _g._t0.load_uintptr();
			_t21 = new tardis.Closure(new tardis.Closure(tardis._Go.Go_main_makeSprite_36_1.call,null),{ bitmap : _g._t0, x : _g._t1, y : _g._t2});
			_g._t22 = tardis.Force.toHaxeParam(new tardis.Interface(5,_t21));
			_g._t20.onload = _g._t22;
			_g._Next = 2;
			return null;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			return null;
		};
		var _Block_3 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			case -3:
				retVal = _Block_3();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_makeSprite
});
tardis.Go_haxegoruntime_Rune2Raw = $hx_exports.Go_haxegoruntime_Rune2Raw = function(gr,_bds,p_oneRune) {
	this._t2 = null;
	this._SF1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,511,"Go_haxegoruntime_Rune2Raw");
	this._bds = _bds;
	this.p_oneRune = p_oneRune;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_haxegoruntime_Rune2Raw.__name__ = true;
tardis.Go_haxegoruntime_Rune2Raw.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_Rune2Raw.callFromRT = function(_gr,p_oneRune) {
	var _sf = new tardis.Go_haxegoruntime_Rune2Raw(_gr,null,p_oneRune).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
};
tardis.Go_haxegoruntime_Rune2Raw.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_Rune2Raw.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t1 = null;
			_g._t0 = new tardis.Slice(new tardis.Pointer(new tardis.Object(4)),0,1,1,4);
			if(0 >= _g._t0.length) tardis.Scheduler.ioor();
			_t1 = _g._t0.itemAddr(0);
			_t1.obj.iVec[_t1.off] = _g.p_oneRune;
			_g._SF1 = new tardis.Go_haxegoruntime_Runes2Raw(_g._goroutine,[],_g._t0);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._t2 = _g._SF1.res();
			_g._res = _g._t2;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_haxegoruntime_Rune2Raw
});
tardis.Go_utf16_DecodeRune = $hx_exports.Go_utf16_DecodeRune = function(gr,_bds,p_r1,p_r2) {
	tardis.StackFrameBasis.call(this,gr,576,"Go_utf16_DecodeRune");
	this._bds = _bds;
	this.p_r1 = p_r1;
	this.p_r2 = p_r2;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_utf16_DecodeRune.__name__ = true;
tardis.Go_utf16_DecodeRune.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf16_DecodeRune.__super__ = tardis.StackFrameBasis;
tardis.Go_utf16_DecodeRune.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _t5 = 0;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = 55296 <= _g.p_r1;
			if(_t0) _g._Next = 5; else _g._Next = 2;
			return null;
		};
		var _Block1 = function() {
			var _t1 = 0;
			var _t2 = 0;
			var _t3 = 0;
			var _t4 = 0;
			_t1 = _g.p_r1 - 55296 >> 0;
			var _v1 = _t1;
			var _v2;
			var v;
			var v1 = new tardis.Int64(0,10);
			v = v1;
			_v2 = tardis.Int64.getLow(v);
			if(_v2 == 0) _t2 = _v1; else _t2 = _v1 << _v2;
			_t3 = _g.p_r2 - 56320 >> 0;
			_t4 = (_t2 | _t3) >> 0;
			_t5 = _t4 + 65536 >> 0;
			_g._res = _t5;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block2 = function() {
			_g._res = 65533;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block3 = function() {
			var _t6 = false;
			_t6 = _g.p_r2 < 57344;
			if(_t6) _g._Next = 1; else _g._Next = 2;
			return null;
		};
		var _Block4 = function() {
			var _t7 = false;
			_t7 = 56320 <= _g.p_r2;
			if(_t7) _g._Next = 3; else _g._Next = 2;
			return null;
		};
		var _Block5 = function() {
			var _t8 = false;
			_t8 = _g.p_r1 < 56320;
			if(_t8) _g._Next = 4; else _g._Next = 2;
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_utf16_DecodeRune
});
tardis._Go.Go_utf16_init = function(gr,_bds) {
	tardis.StackFrameBasis.call(this,gr,577,"Go_utf16_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_utf16_init.__name__ = true;
tardis._Go.Go_utf16_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_utf16_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_utf16_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = tardis.Go.utf16_init_36_guard.load_bool();
			if(_t0) _g._Next = 2; else _g._Next = 1;
			return null;
		};
		var _Block1 = function() {
			tardis.Go.utf16_init_36_guard.store_bool(true);
			_g._Next = 2;
			return null;
		};
		var _Block2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_utf16_init
});
tardis._Go.Go_tgoaddmath_pow2 = function(gr,_bds,p_c) {
	this._t7 = 0.0;
	this._t6 = null;
	tardis.StackFrameBasis.call(this,gr,1443,"Go_tgoaddmath_pow2");
	this._bds = _bds;
	this.p_c = p_c;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_tgoaddmath_pow2.__name__ = true;
tardis._Go.Go_tgoaddmath_pow2.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_tgoaddmath_pow2.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_tgoaddmath_pow2.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = 0.0;
			var _t1 = null;
			var _t2 = null;
			var _t3 = null;
			var _t4 = null;
			var _t5 = null;
			_t0 = _g.p_c;
			_t1 = new tardis.Pointer(new tardis.Object(16));
			_t2 = _t1.addr(0);
			_t3 = new tardis.Interface(4,2);
			_t2.store(_t3);
			_t4 = _t1.addr(8);
			_t5 = new tardis.Interface(4,_t0);
			_t4.store(_t5);
			_g._t6 = new tardis.Slice(_t1,0,-1,2,8);
			var _a = _g._t6;
			_g._t7 = Math.pow(_a.baseArray.addr(_a.start * _a.itemSize).load().val,_a.baseArray.addr((1 + _a.start) * _a.itemSize).load().val);
			_g._res = _g._t7;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_tgoaddmath_pow2
});
tardis._Go.Go_tgoaddmath_glrFloat64frombits = function(gr,_bds,p_b) {
	this._Phi = 0;
	this._t21 = 0.0;
	this._t19 = 0.0;
	this._SF2 = null;
	this._t18 = 0;
	this._t15 = 0.0;
	this._t14 = null;
	this._t12 = null;
	this._t11 = null;
	this._t10 = 0.0;
	this._t6 = null;
	this._t5 = null;
	this._t3 = 0.0;
	this._t0 = 0.0;
	tardis.StackFrameBasis.call(this,gr,1415,"Go_tgoaddmath_glrFloat64frombits");
	this._bds = _bds;
	this.p_b = p_b;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_tgoaddmath_glrFloat64frombits.__name__ = true;
tardis._Go.Go_tgoaddmath_glrFloat64frombits.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_tgoaddmath_glrFloat64frombits.call = function(gr,_bds,p_b) {
	return new tardis._Go.Go_tgoaddmath_glrFloat64frombits(gr,_bds,p_b);
};
tardis._Go.Go_tgoaddmath_glrFloat64frombits.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_tgoaddmath_glrFloat64frombits.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._t0 = Math.NaN;
			var _t1 = null;
			var _t2 = false;
			_t1 = tardis.Force.toUint64((function($this) {
				var $r;
				var x = _g.p_b;
				var y;
				{
					var v = new tardis.Int64(-2147483648,0);
					y = v;
				}
				$r = (function($this) {
					var $r;
					var v1 = new tardis.Int64(x.high & y.high,x.low & y.low);
					$r = v1;
					return $r;
				}($this));
				return $r;
			}(this)));
			_t2 = tardis._Go.HaxeInt64abs_Impl_.ucompare(_t1,(function($this) {
				var $r;
				var v2 = new tardis.Int64(0,0);
				$r = v2;
				return $r;
			}(this))) != 0;
			if(_t2) _g._Next = 1; else _g._Next = 2;
			_g._Phi = 0;
			return null;
		};
		var _Block1 = function() {
			_g._Next = 2;
			_g._Phi = 1;
			return null;
		};
		var _Block2 = function() {
			if(_g._Phi == 0) _g._t3 = 1; else if(_g._Phi == 1) _g._t3 = -1; else _g._t3 = 0.0;
			var _t4 = null;
			var _t7 = false;
			_t4 = tardis.Force.toUint64(tardis._Go.HaxeInt64abs_Impl_.ushr(_g.p_b,(function($this) {
				var $r;
				var v3;
				{
					var v4 = new tardis.Int64(0,52);
					v3 = v4;
				}
				$r = tardis.Int64.getLow(v3);
				return $r;
			}(this))));
			_g._t5 = tardis.Force.toUint64((function($this) {
				var $r;
				var y1;
				{
					var v5 = new tardis.Int64(0,2047);
					y1 = v5;
				}
				$r = (function($this) {
					var $r;
					var v6 = new tardis.Int64(_t4.high & y1.high,_t4.low & y1.low);
					$r = v6;
					return $r;
				}($this));
				return $r;
			}(this)));
			_g._t6 = tardis.Force.toUint64((function($this) {
				var $r;
				var x1 = _g.p_b;
				var y2;
				{
					var v7 = new tardis.Int64(1048575,-1);
					y2 = v7;
				}
				$r = (function($this) {
					var $r;
					var v8 = new tardis.Int64(x1.high & y2.high,x1.low & y2.low);
					$r = v8;
					return $r;
				}($this));
				return $r;
			}(this)));
			_t7 = tardis._Go.HaxeInt64abs_Impl_.ucompare(_g._t5,(function($this) {
				var $r;
				var v9 = new tardis.Int64(0,2047);
				$r = v9;
				return $r;
			}(this))) == 0;
			if(_t7) _g._Next = 3; else _g._Next = 4;
			_g._Phi = 2;
			return null;
		};
		var _Block3 = function() {
			var _t8 = false;
			_t8 = tardis._Go.HaxeInt64abs_Impl_.ucompare(_g._t6,(function($this) {
				var $r;
				var v10 = new tardis.Int64(0,0);
				$r = v10;
				return $r;
			}(this))) == 0;
			if(_t8) _g._Next = 5; else _g._Next = 6;
			_g._Phi = 3;
			return null;
		};
		var _Block4 = function() {
			var _t9 = false;
			_t9 = tardis._Go.HaxeInt64abs_Impl_.ucompare(_g._t5,(function($this) {
				var $r;
				var v11 = new tardis.Int64(0,0);
				$r = v11;
				return $r;
			}(this))) != 0;
			if(_t9) _g._Next = 7; else _g._Next = 8;
			_g._Phi = 4;
			return null;
		};
		var _Block5 = function() {
			_g._t10 = tardis.Force.floatDiv(_g._t3,0);
			_g._res = _g._t10;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block6 = function() {
			_g._res = _g._t0;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block7 = function() {
			_g._t11 = tardis.Force.toUint64((function($this) {
				var $r;
				var y3;
				{
					var v12 = new tardis.Int64(1048576,0);
					y3 = v12;
				}
				$r = (function($this) {
					var $r;
					var v13 = tardis.Int64.add(_g._t6,y3);
					$r = v13;
					return $r;
				}($this));
				return $r;
			}(this)));
			_g._Next = 8;
			_g._Phi = 7;
			return null;
		};
		var _Block8 = function() {
			if(_g._Phi == 4) _g._t12 = _g._t6; else if(_g._Phi == 7) _g._t12 = _g._t11; else {
				var v14 = new tardis.Int64(0,0);
				_g._t12 = v14;
			}
			var _t13 = false;
			_t13 = tardis._Go.HaxeInt64abs_Impl_.ucompare(_g._t5,(function($this) {
				var $r;
				var v15 = new tardis.Int64(0,0);
				$r = v15;
				return $r;
			}(this))) == 0;
			if(_t13) _g._Next = 9; else _g._Next = 10;
			_g._Phi = 8;
			return null;
		};
		var _Block9 = function() {
			_g._Next = 10;
			_g._Phi = 9;
			return null;
		};
		var _Block10 = function() {
			if(_g._Phi == 8) _g._t14 = _g._t5; else if(_g._Phi == 9) {
				var v16 = new tardis.Int64(0,1);
				_g._t14 = v16;
			} else {
				var v17 = new tardis.Int64(0,0);
				_g._t14 = v17;
			}
			var _t16 = 0;
			var _t17 = 0;
			_g._t15 = tardis._Go.HaxeInt64abs_Impl_.toUFloat(_g._t12);
			_t16 = tardis.Force.toInt32(tardis.Int64.getLow(_g._t14));
			_t17 = _t16 - 1023 >> 0;
			_g._t18 = _t17 - 52 >> 0;
			_g._SF2 = new tardis._Go.Go_tgoaddmath_pow2(_g._goroutine,[],_g._t18);
			_g._Next = -2;
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			_g._t19 = _g._SF2.res();
			var _t20 = 0.0;
			_t20 = _g._t15 * _g._t19;
			_g._t21 = _t20 * _g._t3;
			_g._res = _g._t21;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case 9:
				retVal = _Block9();
				break;
			case 10:
				retVal = _Block10();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_tgoaddmath_glrFloat64frombits
});
tardis.Go_haxegoruntime_RunesToUTF16 = $hx_exports.Go_haxegoruntime_RunesToUTF16 = function(gr,_bds,p_r) {
	this._t0 = null;
	this._SF1 = null;
	tardis.StackFrameBasis.call(this,gr,471,"Go_haxegoruntime_RunesToUTF16");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_haxegoruntime_RunesToUTF16.__name__ = true;
tardis.Go_haxegoruntime_RunesToUTF16.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_RunesToUTF16.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_RunesToUTF16.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._SF1 = new tardis.Go_utf16_Encode(_g._goroutine,[],_g.p_r);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._t0 = _g._SF1.res();
			_g._res = _g._t0;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_haxegoruntime_RunesToUTF16
});
tardis.Go_haxegoruntime_RunesToUTF8 = $hx_exports.Go_haxegoruntime_RunesToUTF8 = function(gr,_bds,p_r) {
	this._Phi = 0;
	this._t13 = null;
	this._t11 = 0;
	this._t9 = null;
	this._t8 = 0;
	this._SF1 = null;
	this._t7 = 0;
	this._t4 = 0;
	this._t3 = 0;
	this._t2 = null;
	this._t1 = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,476,"Go_haxegoruntime_RunesToUTF8");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_haxegoruntime_RunesToUTF8.__name__ = true;
tardis.Go_haxegoruntime_RunesToUTF8.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_RunesToUTF8.callFromRT = function(_gr,p_r) {
	var _sf = new tardis.Go_haxegoruntime_RunesToUTF8(_gr,null,p_r).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
};
tardis.Go_haxegoruntime_RunesToUTF8.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_RunesToUTF8.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._t0 = new tardis.Slice(new tardis.Pointer(new tardis.Object(0)),0,0,0,1);
			var _v = _g.p_r;
			if(_v == null) _g._t1 = 0; else _g._t1 = _v.length;
			_g._Next = 1;
			_g._Phi = 0;
			return null;
		};
		var _Block1 = function() {
			var _g1 = _g._Phi;
			switch(_g1) {
			case 2:
				_g._t2 = _g._t13;
				_g._t3 = _g._t4;
				break;
			case 0:
				_g._t2 = _g._t0;
				_g._t3 = -1;
				break;
			}
			var _t5 = false;
			_g._t4 = _g._t3 + 1 >> 0;
			_t5 = _g._t4 < _g._t1;
			if(_t5) _g._Next = 2; else _g._Next = 3;
			_g._Phi = 1;
			return null;
		};
		var _Block2 = function() {
			var _t6 = null;
			tardis.Scheduler.wraprangechk(_g._t4,_g.p_r.length);
			_t6 = _g.p_r.itemAddr(_g._t4);
			_g._t7 = _t6.obj.get_int32(_t6.off);
			_g._SF1 = new tardis.Go_utf8_RuneLen(_g._goroutine,[],_g._t7);
			_g._SF1.run();
			_g._t8 = _g._SF1.res();
			var _t10 = null;
			_g._t9 = new tardis.Slice(new tardis.Pointer(new tardis.Object(_g._t8)),0,_g._t8,_g._t8,1);
			tardis.Scheduler.wraprangechk(_g._t4,_g.p_r.length);
			_t10 = _g.p_r.itemAddr(_g._t4);
			_g._t11 = _t10.obj.get_int32(_t10.off);
			new tardis.Go_utf8_EncodeRune(_g._goroutine,[],_g._t9,_g._t11).run();
			_g._t13 = _g._t2.append(_g._t9);
			_g._Next = 1;
			_g._Phi = 2;
			return null;
		};
		var _Block3 = function() {
			_g._res = _g._t2;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g2 = this._Next;
			switch(_g2) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_haxegoruntime_RunesToUTF8
});
tardis._Go.Go_main_fireBooks = function(gr,_bds,p_x,p_y,p_state,p_cartLoad,p_out) {
	tardis.StackFrameBasis.call(this,gr,108,"Go_main_fireBooks");
	this._bds = _bds;
	this.p_x = p_x;
	this.p_y = p_y;
	this.p_state = p_state;
	this.p_cartLoad = p_cartLoad;
	this.p_out = p_out;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_fireBooks.__name__ = true;
tardis._Go.Go_main_fireBooks.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_fireBooks.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_fireBooks.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g.p_state.store_int32(2);
			new tardis._Go.Go_main_delay(_g._goroutine,[],_g.p_cartLoad);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._Next = -2;
			return _g;
		};
		var _Block_2 = function() {
			if(!_g.p_out.hasSpace()) return _g;
			_g.p_out.send(_g.p_cartLoad);
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_fireBooks
});
tardis._Go.Go_main_moreBooks = function(gr,_bds,p_x,p_y,p_state) {
	this._t10 = 0;
	this._t9 = null;
	tardis.StackFrameBasis.call(this,gr,113,"Go_main_moreBooks");
	this._bds = _bds;
	this.p_x = p_x;
	this.p_y = p_y;
	this.p_state = p_state;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_moreBooks.__name__ = true;
tardis._Go.Go_main_moreBooks.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_moreBooks.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_moreBooks.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g.p_state.store_int32(3);
			_g._Next = 3;
			return null;
		};
		var _Block1 = function() {
			var _t0 = 0.0;
			var _t1 = 0.0;
			var _t2 = 0.0;
			var _t3 = false;
			_t0 = _g.p_x.load_float64();
			_t1 = _t0 - 10;
			_g.p_x.store_float64(_t1);
			_t2 = _g.p_x.load_float64();
			_t3 = _t2 < 0;
			if(_t3) _g._Next = 4; else _g._Next = 5;
			return null;
		};
		var _Block2 = function() {
			_g.p_y.store_float64(0);
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block3 = function() {
			var _t4 = 0.0;
			var _t5 = false;
			_t4 = _g.p_x.load_float64();
			_t5 = _t4 > 0;
			if(_t5) _g._Next = 1; else _g._Next = 2;
			return null;
		};
		var _Block4 = function() {
			_g.p_x.store_float64(0);
			_g._Next = 5;
			return null;
		};
		var _Block5 = function() {
			var _t6 = 0.0;
			var _t7 = false;
			_t6 = _g.p_y.load_float64();
			_t7 = _t6 > 0;
			if(_t7) _g._Next = 6; else _g._Next = 8;
			return null;
		};
		var _Block6 = function() {
			_g.p_y.store_float64(0);
			_g._Next = 7;
			return null;
		};
		var _Block7 = function() {
			new tardis.Go_main_Gosched(_g._goroutine,[]);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._Next = 3;
			return null;
		};
		var _Block8 = function() {
			_g._t9 = new tardis.Interface(0,5);
			_g._t10 = Std.random(tardis.Force.toHaxeParam(_g._t9));
			var _t11 = 0.0;
			_t11 = _g._t10;
			_g.p_y.store_float64(_t11);
			_g._Next = 7;
			return null;
		};
		var _Block_2 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_moreBooks
});
tardis._Go.Go_tgoaddmath_glrFloat64bits = function(gr,_bds,p_f) {
	tardis.StackFrameBasis.call(this,gr,1372,"Go_tgoaddmath_glrFloat64bits");
	this._bds = _bds;
	this.p_f = p_f;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_tgoaddmath_glrFloat64bits.__name__ = true;
tardis._Go.Go_tgoaddmath_glrFloat64bits.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_tgoaddmath_glrFloat64bits.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_tgoaddmath_glrFloat64bits.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _t3 = 0.0;
		var _t4 = 0.0;
		var _t5 = null;
		var _t6 = 0.0;
		var _t8 = 0.0;
		var _t9 = 0;
		var _t11 = 0;
		var _t12 = 0;
		var _t14 = 0;
		var _t20 = null;
		var _t21 = 0.0;
		var _t22 = 0;
		var _t24 = 0.0;
		var _Phi = 0;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = _g.p_f == 0;
			if(_t0) _g._Next = 1; else _g._Next = 2;
			_Phi = 0;
			return null;
		};
		var _Block1 = function() {
			var v = new tardis.Int64(0,0);
			_g._res = v;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block2 = function() {
			var _t1 = false;
			_t1 = _g.p_f != _g.p_f;
			if(_t1) _g._Next = 3; else _g._Next = 4;
			_Phi = 2;
			return null;
		};
		var _Block3 = function() {
			var v1 = new tardis.Int64(2146959360,1);
			_g._res = v1;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block4 = function() {
			var _t2 = false;
			_t2 = _g.p_f < 0;
			if(_t2) _g._Next = 5; else _g._Next = 6;
			_Phi = 4;
			return null;
		};
		var _Block5 = function() {
			_t3 = -_g.p_f;
			_g._Next = 6;
			_Phi = 5;
			return null;
		};
		var _Block6 = function() {
			switch(_Phi) {
			case 4:
				_t4 = _g.p_f;
				var v2 = new tardis.Int64(0,0);
				_t5 = v2;
				break;
			case 5:
				_t4 = _t3;
				var v3 = new tardis.Int64(-2147483648,0);
				_t5 = v3;
				break;
			}
			_g._Next = 8;
			_Phi = 6;
			return null;
		};
		var _Block7 = function() {
			var _t7 = false;
			_t6 = tardis.Force.floatDiv(_t8,2);
			_t7 = tardis.Force.uintCompare(_t9,2047) == 0;
			if(_t7) _g._Next = 12; else _g._Next = 9;
			_Phi = 7;
			return null;
		};
		var _Block8 = function() {
			switch(_Phi) {
			case 6:
				_t8 = _t4;
				_t9 = 1075;
				break;
			case 9:
				_t8 = _t6;
				_t9 = _t11;
				break;
			}
			var _t10 = false;
			_t10 = _t8 >= 9.007199254740992e+15;
			if(_t10) _g._Next = 7; else _g._Next = 12;
			_Phi = 8;
			return null;
		};
		var _Block9 = function() {
			_t11 = _t9 + 1 >>> 0;
			_g._Next = 8;
			_Phi = 9;
			return null;
		};
		var _Block10 = function() {
			var _t13 = false;
			_t12 = _t22 - 1 >>> 0;
			_t13 = tardis.Force.uintCompare(_t12,0) == 0;
			if(_t13) _g._Next = 11; else _g._Next = 13;
			_Phi = 10;
			return null;
		};
		var _Block11 = function() {
			if(_Phi == 12) _t14 = _t22; else if(_Phi == 10) _t14 = _t12; else _t14 = 0;
			var _t15 = null;
			var _t16 = null;
			var _t17 = null;
			var _t18 = null;
			var _t19 = null;
			var v4 = new tardis.Int64(_t14 >> 31,_t14);
			_t15 = v4;
			_t16 = tardis.Force.toUint64((function($this) {
				var $r;
				var y;
				{
					var v5;
					var v6 = new tardis.Int64(0,52);
					v5 = v6;
					y = tardis.Int64.getLow(v5);
				}
				$r = y == 64?(function($this) {
					var $r;
					var v7 = new tardis.Int64(0,0);
					$r = v7;
					return $r;
				}($this)):(function($this) {
					var $r;
					var v8;
					if((y & 63) == 0) v8 = _t15; else if((y & 63) < 32) v8 = new tardis.Int64(_t15.high << y | _t15.low >>> (32 - (y & 63) | 0),_t15.low << y); else v8 = new tardis.Int64(_t15.low << (y - 32 | 0),0);
					$r = v8;
					return $r;
				}($this));
				return $r;
			}(this)));
			_t17 = tardis.Force.toUint64((function($this) {
				var $r;
				var v9 = new tardis.Int64(_t5.high | _t16.high,_t5.low | _t16.low);
				$r = v9;
				return $r;
			}(this)));
			_t18 = tardis._Go.HaxeInt64abs_Impl_.ofUFloat(_t21);
			_t19 = tardis.Force.toUint64((function($this) {
				var $r;
				var y1;
				{
					var x;
					var v10 = new tardis.Int64(1048576,0);
					x = v10;
					var y2;
					var v11 = new tardis.Int64(-1,-1);
					y2 = v11;
					var v12 = new tardis.Int64(x.high ^ y2.high,x.low ^ y2.low);
					y1 = v12;
				}
				$r = (function($this) {
					var $r;
					var v13 = new tardis.Int64(_t18.high & y1.high,_t18.low & y1.low);
					$r = v13;
					return $r;
				}($this));
				return $r;
			}(this)));
			_t20 = tardis.Force.toUint64((function($this) {
				var $r;
				var v14 = new tardis.Int64(_t17.high | _t19.high,_t17.low | _t19.low);
				$r = v14;
				return $r;
			}(this)));
			_g._res = _t20;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block12 = function() {
			switch(_Phi) {
			case 7:
				_t21 = _t6;
				_t22 = _t9;
				break;
			case 8:
				_t21 = _t8;
				_t22 = _t9;
				break;
			case 13:
				_t21 = _t24;
				_t22 = _t12;
				break;
			}
			var _t23 = false;
			_t23 = _t21 < 4.503599627370496e+15;
			if(_t23) _g._Next = 10; else _g._Next = 11;
			_Phi = 12;
			return null;
		};
		var _Block13 = function() {
			_t24 = _t21 * 2;
			_g._Next = 12;
			_Phi = 13;
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case 9:
				retVal = _Block9();
				break;
			case 10:
				retVal = _Block10();
				break;
			case 11:
				retVal = _Block11();
				break;
			case 12:
				retVal = _Block12();
				break;
			case 13:
				retVal = _Block13();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_tgoaddmath_glrFloat64bits
});
tardis.Go_tardisgolib_Gosched = $hx_exports.Go_tardisgolib_Gosched = function(gr,_bds) {
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,396742,"Go_tardisgolib_Gosched");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_tardisgolib_Gosched.__name__ = true;
tardis.Go_tardisgolib_Gosched.__interfaces__ = [tardis.StackFrame];
tardis.Go_tardisgolib_Gosched.__super__ = tardis.StackFrameBasis;
tardis.Go_tardisgolib_Gosched.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._t0 = tardis.Go.tardisgolib_gosched_chan.load();
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._t1 = { r0 : 0, r1 : false, r2 : null};
			_g._t1.r0 = -1;
			var _states = new Array();
			var _rnd = Std.random(1);
			_states[0] = _g._t0.hasContents();
			var _g1 = 0;
			while(_g1 < 1) {
				var _s = _g1++;
				var _i = (_s + _rnd) % 1;
				if(_states[_i]) {
					_g._t1.r0 = _i;
					break;
				}
			}
			var _g11 = _g._t1.r0;
			switch(_g11) {
			case 0:
				var _v = _g._t0.receive(null);
				_g._t1.r2 = _v.r0;
				_g._t1.r1 = _v.r1;
				break;
			}
			var _t2 = 0;
			var _t3 = false;
			_t2 = _g._t1.r0;
			_t3 = _t2 == 0;
			if(_t3) _g._Next = 1; else _g._Next = 2;
			return null;
		};
		var _Block1 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g2 = this._Next;
			switch(_g2) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_tardisgolib_Gosched
});
tardis._Go.Go_main_delay_36_1 = function(gr,_bds) {
	this._t2 = null;
	this._t1_stackalloc = new tardis.Object(0);
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,131,"Go_main_delay_36_1");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_delay_36_1.__name__ = true;
tardis._Go.Go_main_delay_36_1.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_delay_36_1.call = function(gr,_bds) {
	return new tardis._Go.Go_main_delay_36_1(gr,_bds);
};
tardis._Go.Go_main_delay_36_1.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_delay_36_1.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t1 = null;
			_g._t0 = _g._bds.w.load();
			_t1 = new tardis.Pointer(_g._t1_stackalloc.clear());
			_g._t2 = _t1.obj.get_object(0,_t1.off);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			if(!_g._t0.hasSpace()) return _g;
			_g._t0.send(_g._t2);
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_delay_36_1
});
tardis._Go.Go_main_makeBitmap = function(gr,_bds,p_file) {
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,166,"Go_main_makeBitmap");
	this._bds = _bds;
	this.p_file = p_file;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_makeBitmap.__name__ = true;
tardis._Go.Go_main_makeBitmap.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_makeBitmap.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_makeBitmap.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._t0 = new Image();
			_g._t0.src = _g.p_file;
			_g._res = _g._t0;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_makeBitmap
});
tardis._Go.Go_utf8_decodeRuneInternal = function(gr,_bds,p_p) {
	this._t58 = 0;
	this._t41 = 0;
	this._t35 = 0;
	this._t22 = 0;
	this._t18 = 0;
	this._t9 = 0;
	this._t5 = 0;
	this._t3 = 0;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,692,"Go_utf8_decodeRuneInternal");
	this._bds = _bds;
	this.p_p = p_p;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_utf8_decodeRuneInternal.__name__ = true;
tardis._Go.Go_utf8_decodeRuneInternal.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_utf8_decodeRuneInternal.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_utf8_decodeRuneInternal.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t1 = false;
			var _v = _g.p_p;
			if(_v == null) _g._t0 = 0; else _g._t0 = _v.length;
			_t1 = _g._t0 < 1;
			if(_t1) _g._Next = 1; else _g._Next = 2;
			return null;
		};
		var _Block1 = function() {
			_g._res = { r0 : 65533, r1 : 0, r2 : true};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block2 = function() {
			var _t2 = null;
			var _t4 = false;
			if(0 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t2 = _g.p_p.itemAddr(0);
			_g._t3 = _t2.obj.get_uint8(_t2.off);
			_t4 = tardis.Force.uintCompare(_g._t3,128) < 0;
			if(_t4) _g._Next = 3; else _g._Next = 4;
			return null;
		};
		var _Block3 = function() {
			_g._t5 = _g._t3;
			_g._res = { r0 : _g._t5, r1 : 1, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block4 = function() {
			var _t6 = false;
			_t6 = tardis.Force.uintCompare(_g._t3,192) < 0;
			if(_t6) _g._Next = 5; else _g._Next = 6;
			return null;
		};
		var _Block5 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block6 = function() {
			var _t7 = false;
			_t7 = _g._t0 < 2;
			if(_t7) _g._Next = 7; else _g._Next = 8;
			return null;
		};
		var _Block7 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : true};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block8 = function() {
			var _t8 = null;
			var _t10 = false;
			if(1 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t8 = _g.p_p.itemAddr(1);
			_g._t9 = _t8.obj.get_uint8(_t8.off);
			_t10 = tardis.Force.uintCompare(_g._t9,128) < 0;
			if(_t10) _g._Next = 9; else _g._Next = 11;
			return null;
		};
		var _Block9 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block10 = function() {
			var _t11 = false;
			_t11 = tardis.Force.uintCompare(_g._t3,224) < 0;
			if(_t11) _g._Next = 12; else _g._Next = 13;
			return null;
		};
		var _Block11 = function() {
			var _t12 = false;
			_t12 = tardis.Force.uintCompare(192,_g._t9) <= 0;
			if(_t12) _g._Next = 9; else _g._Next = 10;
			return null;
		};
		var _Block12 = function() {
			var _t13 = 0;
			var _t14 = 0;
			var _t15 = 0;
			var _t16 = 0;
			var _t17 = 0;
			var _t19 = false;
			_t13 = _g._t3 & 31 & 255;
			_t14 = _t13;
			var _v1 = _t14;
			var _v2;
			var v;
			var v1 = new tardis.Int64(0,6);
			v = v1;
			_v2 = tardis.Int64.getLow(v);
			if(_v2 == 0) _t15 = _v1; else _t15 = _v1 << _v2;
			_t16 = _g._t9 & 63 & 255;
			_t17 = _t16;
			_g._t18 = (_t15 | _t17) >> 0;
			_t19 = _g._t18 <= 127;
			if(_t19) _g._Next = 14; else _g._Next = 15;
			return null;
		};
		var _Block13 = function() {
			var _t20 = false;
			_t20 = _g._t0 < 3;
			if(_t20) _g._Next = 16; else _g._Next = 17;
			return null;
		};
		var _Block14 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block15 = function() {
			_g._res = { r0 : _g._t18, r1 : 2, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block16 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : true};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block17 = function() {
			var _t21 = null;
			var _t23 = false;
			if(2 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t21 = _g.p_p.itemAddr(2);
			_g._t22 = _t21.obj.get_uint8(_t21.off);
			_t23 = tardis.Force.uintCompare(_g._t22,128) < 0;
			if(_t23) _g._Next = 18; else _g._Next = 20;
			return null;
		};
		var _Block18 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block19 = function() {
			var _t24 = false;
			_t24 = tardis.Force.uintCompare(_g._t3,240) < 0;
			if(_t24) _g._Next = 21; else _g._Next = 22;
			return null;
		};
		var _Block20 = function() {
			var _t25 = false;
			_t25 = tardis.Force.uintCompare(192,_g._t22) <= 0;
			if(_t25) _g._Next = 18; else _g._Next = 19;
			return null;
		};
		var _Block21 = function() {
			var _t26 = 0;
			var _t27 = 0;
			var _t28 = 0;
			var _t29 = 0;
			var _t30 = 0;
			var _t31 = 0;
			var _t32 = 0;
			var _t33 = 0;
			var _t34 = 0;
			var _t36 = false;
			_t26 = _g._t3 & 15 & 255;
			_t27 = _t26;
			var _v11 = _t27;
			var _v21;
			var v2;
			var v3 = new tardis.Int64(0,12);
			v2 = v3;
			_v21 = tardis.Int64.getLow(v2);
			if(_v21 == 0) _t28 = _v11; else _t28 = _v11 << _v21;
			_t29 = _g._t9 & 63 & 255;
			_t30 = _t29;
			var _v12 = _t30;
			var _v22;
			var v4;
			var v5 = new tardis.Int64(0,6);
			v4 = v5;
			_v22 = tardis.Int64.getLow(v4);
			if(_v22 == 0) _t31 = _v12; else _t31 = _v12 << _v22;
			_t32 = (_t28 | _t31) >> 0;
			_t33 = _g._t22 & 63 & 255;
			_t34 = _t33;
			_g._t35 = (_t32 | _t34) >> 0;
			_t36 = _g._t35 <= 2047;
			if(_t36) _g._Next = 23; else _g._Next = 24;
			return null;
		};
		var _Block22 = function() {
			var _t37 = false;
			_t37 = _g._t0 < 4;
			if(_t37) _g._Next = 28; else _g._Next = 29;
			return null;
		};
		var _Block23 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block24 = function() {
			var _t38 = false;
			_t38 = 55296 <= _g._t35;
			if(_t38) _g._Next = 27; else _g._Next = 26;
			return null;
		};
		var _Block25 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block26 = function() {
			_g._res = { r0 : _g._t35, r1 : 3, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block27 = function() {
			var _t39 = false;
			_t39 = _g._t35 <= 57343;
			if(_t39) _g._Next = 25; else _g._Next = 26;
			return null;
		};
		var _Block28 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : true};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block29 = function() {
			var _t40 = null;
			var _t42 = false;
			if(3 >= _g.p_p.length) tardis.Scheduler.ioor();
			_t40 = _g.p_p.itemAddr(3);
			_g._t41 = _t40.obj.get_uint8(_t40.off);
			_t42 = tardis.Force.uintCompare(_g._t41,128) < 0;
			if(_t42) _g._Next = 30; else _g._Next = 32;
			return null;
		};
		var _Block30 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block31 = function() {
			var _t43 = false;
			_t43 = tardis.Force.uintCompare(_g._t3,248) < 0;
			if(_t43) _g._Next = 33; else _g._Next = 34;
			return null;
		};
		var _Block32 = function() {
			var _t44 = false;
			_t44 = tardis.Force.uintCompare(192,_g._t41) <= 0;
			if(_t44) _g._Next = 30; else _g._Next = 31;
			return null;
		};
		var _Block33 = function() {
			var _t45 = 0;
			var _t46 = 0;
			var _t47 = 0;
			var _t48 = 0;
			var _t49 = 0;
			var _t50 = 0;
			var _t51 = 0;
			var _t52 = 0;
			var _t53 = 0;
			var _t54 = 0;
			var _t55 = 0;
			var _t56 = 0;
			var _t57 = 0;
			var _t59 = false;
			_t45 = _g._t3 & 7 & 255;
			_t46 = _t45;
			var _v13 = _t46;
			var _v23;
			var v6;
			var v7 = new tardis.Int64(0,18);
			v6 = v7;
			_v23 = tardis.Int64.getLow(v6);
			if(_v23 == 0) _t47 = _v13; else _t47 = _v13 << _v23;
			_t48 = _g._t9 & 63 & 255;
			_t49 = _t48;
			var _v14 = _t49;
			var _v24;
			var v8;
			var v9 = new tardis.Int64(0,12);
			v8 = v9;
			_v24 = tardis.Int64.getLow(v8);
			if(_v24 == 0) _t50 = _v14; else _t50 = _v14 << _v24;
			_t51 = (_t47 | _t50) >> 0;
			_t52 = _g._t22 & 63 & 255;
			_t53 = _t52;
			var _v15 = _t53;
			var _v25;
			var v10;
			var v11 = new tardis.Int64(0,6);
			v10 = v11;
			_v25 = tardis.Int64.getLow(v10);
			if(_v25 == 0) _t54 = _v15; else _t54 = _v15 << _v25;
			_t55 = (_t51 | _t54) >> 0;
			_t56 = _g._t41 & 63 & 255;
			_t57 = _t56;
			_g._t58 = (_t55 | _t57) >> 0;
			_t59 = _g._t58 <= 65535;
			if(_t59) _g._Next = 35; else _g._Next = 37;
			return null;
		};
		var _Block34 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block35 = function() {
			_g._res = { r0 : 65533, r1 : 1, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block36 = function() {
			_g._res = { r0 : _g._t58, r1 : 4, r2 : false};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block37 = function() {
			var _t60 = false;
			_t60 = 1114111 < _g._t58;
			if(_t60) _g._Next = 35; else _g._Next = 36;
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case 9:
				retVal = _Block9();
				break;
			case 10:
				retVal = _Block10();
				break;
			case 11:
				retVal = _Block11();
				break;
			case 12:
				retVal = _Block12();
				break;
			case 13:
				retVal = _Block13();
				break;
			case 14:
				retVal = _Block14();
				break;
			case 15:
				retVal = _Block15();
				break;
			case 16:
				retVal = _Block16();
				break;
			case 17:
				retVal = _Block17();
				break;
			case 18:
				retVal = _Block18();
				break;
			case 19:
				retVal = _Block19();
				break;
			case 20:
				retVal = _Block20();
				break;
			case 21:
				retVal = _Block21();
				break;
			case 22:
				retVal = _Block22();
				break;
			case 23:
				retVal = _Block23();
				break;
			case 24:
				retVal = _Block24();
				break;
			case 25:
				retVal = _Block25();
				break;
			case 26:
				retVal = _Block26();
				break;
			case 27:
				retVal = _Block27();
				break;
			case 28:
				retVal = _Block28();
				break;
			case 29:
				retVal = _Block29();
				break;
			case 30:
				retVal = _Block30();
				break;
			case 31:
				retVal = _Block31();
				break;
			case 32:
				retVal = _Block32();
				break;
			case 33:
				retVal = _Block33();
				break;
			case 34:
				retVal = _Block34();
				break;
			case 35:
				retVal = _Block35();
				break;
			case 36:
				retVal = _Block36();
				break;
			case 37:
				retVal = _Block37();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_utf8_decodeRuneInternal
});
tardis._Go.Go_main_gopher = function(gr,_bds,p_x,p_y,p_state,p_in,p_out) {
	this._t0 = 0;
	this._SF1 = null;
	tardis.StackFrameBasis.call(this,gr,77,"Go_main_gopher");
	this._bds = _bds;
	this.p_x = p_x;
	this.p_y = p_y;
	this.p_state = p_state;
	this.p_in = p_in;
	this.p_out = p_out;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_gopher.__name__ = true;
tardis._Go.Go_main_gopher.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_gopher.call = function(gr,_bds,p_x,p_y,p_state,p_in,p_out) {
	return new tardis._Go.Go_main_gopher(gr,_bds,p_x,p_y,p_state,p_in,p_out);
};
tardis._Go.Go_main_gopher.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_gopher.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._Next = 1;
			return null;
		};
		var _Block1 = function() {
			_g._SF1 = new tardis._Go.Go_main_pickBooks(_g._goroutine,[],_g.p_x,_g.p_y,_g.p_state,_g.p_in);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._t0 = _g._SF1.res();
			new tardis._Go.Go_main_pushBooks(_g._goroutine,[],_g.p_x,_g.p_y,_g.p_state,_g._t0);
			_g._Next = -2;
			return _g;
		};
		var _Block_2 = function() {
			new tardis._Go.Go_main_fireBooks(_g._goroutine,[],_g.p_x,_g.p_y,_g.p_state,_g._t0,_g.p_out);
			_g._Next = -3;
			return _g;
		};
		var _Block_3 = function() {
			new tardis._Go.Go_main_moreBooks(_g._goroutine,[],_g.p_x,_g.p_y,_g.p_state);
			_g._Next = -4;
			return _g;
		};
		var _Block_4 = function() {
			_g._Next = 1;
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			case -3:
				retVal = _Block_3();
				break;
			case -4:
				retVal = _Block_4();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_gopher
});
tardis._Go.Go_tgoaddmath_init = function(gr,_bds) {
	tardis.StackFrameBasis.call(this,gr,82,"Go_tgoaddmath_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_tgoaddmath_init.__name__ = true;
tardis._Go.Go_tgoaddmath_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_tgoaddmath_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_tgoaddmath_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = tardis.Go.tgoaddmath_init_36_guard.load_bool();
			if(_t0) _g._Next = 2; else _g._Next = 1;
			return null;
		};
		var _Block1 = function() {
			tardis.Go.tgoaddmath_init_36_guard.store_bool(true);
			new tardis._Go.Go_tgoaddmath_init_35_1(_g._goroutine,[]);
			_g._Next = -2;
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			_g._Next = 2;
			return null;
		};
		var _Block2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_tgoaddmath_init
});
tardis.Go_utf16_Decode = $hx_exports.Go_utf16_Decode = function(gr,_bds,p_s) {
	this._Phi = 0;
	this._t42 = false;
	this._t41 = false;
	this._t40 = 0;
	this._t29 = false;
	this._t28 = false;
	this._t23 = 0;
	this._t21 = 0;
	this._t20 = 0;
	this._t19 = 0;
	this._SF1 = null;
	this._t18 = 0;
	this._t14 = 0;
	this._t13 = null;
	this._t12 = 0;
	this._t11 = 0;
	this._t10 = 0;
	this._t7 = 0;
	this._t6 = 0;
	this._t5 = null;
	this._t3 = 0;
	this._t1 = null;
	tardis.StackFrameBasis.call(this,gr,625,"Go_utf16_Decode");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_utf16_Decode.__name__ = true;
tardis.Go_utf16_Decode.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf16_Decode.__super__ = tardis.StackFrameBasis;
tardis.Go_utf16_Decode.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = 0;
			var _v = _g.p_s;
			if(_v == null) _t0 = 0; else _t0 = _v.length;
			_g._t1 = new tardis.Slice(new tardis.Pointer(new tardis.Object(_t0 * 4)),0,_t0,_t0,4);
			_g._Next = 3;
			_g._Phi = 0;
			return null;
		};
		var _Block1 = function() {
			var _t2 = null;
			var _t4 = false;
			tardis.Scheduler.wraprangechk(_g._t7,_g.p_s.length);
			_t2 = _g.p_s.itemAddr(_g._t7);
			_g._t3 = _t2.obj.get_uint16(_t2.off);
			_t4 = tardis.Force.uintCompare(55296,_g._t3) <= 0;
			if(_t4) _g._Next = 12; else _g._Next = 9;
			_g._Phi = 1;
			return null;
		};
		var _Block2 = function() {
			_g._t5 = _g._t1.subSlice(0,_g._t6);
			_g._res = _g._t5;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block3 = function() {
			var _g1 = _g._Phi;
			switch(_g1) {
			case 0:
				_g._t6 = 0;
				_g._t7 = 0;
				break;
			case 4:
				_g._t6 = _g._t10;
				_g._t7 = _g._t12;
				break;
			}
			var _t8 = 0;
			var _t9 = false;
			var _v1 = _g.p_s;
			if(_v1 == null) _t8 = 0; else _t8 = _v1.length;
			_t9 = _g._t7 < _t8;
			if(_t9) _g._Next = 1; else _g._Next = 2;
			_g._Phi = 3;
			return null;
		};
		var _Block4 = function() {
			var _g11 = _g._Phi;
			switch(_g11) {
			case 6:
				_g._t10 = _g._t23;
				_g._t11 = _g._t7;
				break;
			case 13:
				_g._t10 = _g._t40;
				_g._t11 = _g._t7;
				break;
			case 5:
				_g._t10 = _g._t21;
				_g._t11 = _g._t20;
				break;
			}
			_g._t12 = _g._t11 + 1 >> 0;
			_g._Next = 3;
			_g._Phi = 4;
			return null;
		};
		var _Block5 = function() {
			var _t15 = 0;
			var _t16 = null;
			var _t17 = 0;
			tardis.Scheduler.wraprangechk(_g._t6,_g._t1.length);
			_g._t13 = _g._t1.itemAddr(_g._t6);
			_g._t14 = _g._t3;
			_t15 = _g._t7 + 1 >> 0;
			if(_t15 < 0 || _t15 >= _g.p_s.length) tardis.Scheduler.ioor();
			_t16 = _g.p_s.itemAddr(_t15);
			_t17 = _t16.obj.get_uint16(_t16.off);
			_g._t18 = _t17;
			_g._SF1 = new tardis.Go_utf16_DecodeRune(_g._goroutine,[],_g._t14,_g._t18);
			_g._SF1.run();
			_g._t19 = _g._SF1.res();
			_g._t13.store_int32(_g._t19);
			_g._t20 = _g._t7 + 1 >> 0;
			_g._t21 = _g._t6 + 1 >> 0;
			_g._Next = 4;
			_g._Phi = 5;
			return null;
		};
		var _Block6 = function() {
			var _t22 = null;
			tardis.Scheduler.wraprangechk(_g._t6,_g._t1.length);
			_t22 = _g._t1.itemAddr(_g._t6);
			_t22.obj.iVec[_t22.off] = 65533;
			_g._t23 = _g._t6 + 1 >> 0;
			_g._Next = 4;
			_g._Phi = 6;
			return null;
		};
		var _Block7 = function() {
			var _t24 = false;
			_t24 = tardis.Force.uintCompare(55296,_g._t3) <= 0;
			if(_t24) _g._Next = 14; else _g._Next = 15;
			_g._Phi = 7;
			return null;
		};
		var _Block8 = function() {
			var _t25 = 0;
			var _t26 = null;
			var _t27 = 0;
			_t25 = _g._t7 + 1 >> 0;
			if(_t25 < 0 || _t25 >= _g.p_s.length) tardis.Scheduler.ioor();
			_t26 = _g.p_s.itemAddr(_t25);
			_t27 = _t26.obj.get_uint16(_t26.off);
			_g._t28 = tardis.Force.uintCompare(_t27,57344) < 0;
			_g._Next = 9;
			_g._Phi = 8;
			return null;
		};
		var _Block9 = function() {
			if(_g._Phi == 1) _g._t29 = false; else if(_g._Phi == 12) _g._t29 = false; else if(_g._Phi == 11) _g._t29 = false; else if(_g._Phi == 10) _g._t29 = false; else if(_g._Phi == 8) _g._t29 = _g._t28; else _g._t29 = false;
			if(_g._t29) _g._Next = 5; else _g._Next = 7;
			_g._Phi = 9;
			return null;
		};
		var _Block10 = function() {
			var _t30 = 0;
			var _t31 = null;
			var _t32 = 0;
			var _t33 = false;
			_t30 = _g._t7 + 1 >> 0;
			if(_t30 < 0 || _t30 >= _g.p_s.length) tardis.Scheduler.ioor();
			_t31 = _g.p_s.itemAddr(_t30);
			_t32 = _t31.obj.get_uint16(_t31.off);
			_t33 = tardis.Force.uintCompare(56320,_t32) <= 0;
			if(_t33) _g._Next = 8; else _g._Next = 9;
			_g._Phi = 10;
			return null;
		};
		var _Block11 = function() {
			var _t34 = 0;
			var _t35 = 0;
			var _t36 = false;
			_t34 = _g._t7 + 1 >> 0;
			var _v2 = _g.p_s;
			if(_v2 == null) _t35 = 0; else _t35 = _v2.length;
			_t36 = _t34 < _t35;
			if(_t36) _g._Next = 10; else _g._Next = 9;
			_g._Phi = 11;
			return null;
		};
		var _Block12 = function() {
			var _t37 = false;
			_t37 = tardis.Force.uintCompare(_g._t3,56320) < 0;
			if(_t37) _g._Next = 11; else _g._Next = 9;
			_g._Phi = 12;
			return null;
		};
		var _Block13 = function() {
			var _t38 = null;
			var _t39 = 0;
			tardis.Scheduler.wraprangechk(_g._t6,_g._t1.length);
			_t38 = _g._t1.itemAddr(_g._t6);
			_t39 = _g._t3;
			_t38.obj.iVec[_t38.off] = _t39;
			_g._t40 = _g._t6 + 1 >> 0;
			_g._Next = 4;
			_g._Phi = 13;
			return null;
		};
		var _Block14 = function() {
			_g._t41 = tardis.Force.uintCompare(_g._t3,57344) < 0;
			_g._Next = 15;
			_g._Phi = 14;
			return null;
		};
		var _Block15 = function() {
			if(_g._Phi == 7) _g._t42 = false; else if(_g._Phi == 14) _g._t42 = _g._t41; else _g._t42 = false;
			if(_g._t42) _g._Next = 6; else _g._Next = 13;
			_g._Phi = 15;
			return null;
		};
		var _Block_1 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g2 = this._Next;
			switch(_g2) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case 9:
				retVal = _Block9();
				break;
			case 10:
				retVal = _Block10();
				break;
			case 11:
				retVal = _Block11();
				break;
			case 12:
				retVal = _Block12();
				break;
			case 13:
				retVal = _Block13();
				break;
			case 14:
				retVal = _Block14();
				break;
			case 15:
				retVal = _Block15();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_utf16_Decode
});
tardis._Go.Go_tgoaddmath_glrFloat32frombits = function(gr,_bds,p_b) {
	this._Phi = 0;
	this._t23 = 0.0;
	this._t20 = 0.0;
	this._SF2 = null;
	this._t19 = 0;
	this._t16 = 0.0;
	this._t15 = 0;
	this._t13 = 0;
	this._t12 = 0;
	this._t11 = 0.0;
	this._t10 = 0.0;
	this._t9 = 0.0;
	this._t5 = 0;
	this._t4 = 0;
	this._t2 = 0.0;
	tardis.StackFrameBasis.call(this,gr,1342,"Go_tgoaddmath_glrFloat32frombits");
	this._bds = _bds;
	this.p_b = p_b;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_tgoaddmath_glrFloat32frombits.__name__ = true;
tardis._Go.Go_tgoaddmath_glrFloat32frombits.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_tgoaddmath_glrFloat32frombits.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_tgoaddmath_glrFloat32frombits.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = 0;
			var _t1 = false;
			_t0 = tardis.Force.toUint32(_g.p_b & 0x80000000);
			_t1 = tardis.Force.uintCompare(_t0,0) != 0;
			if(_t1) _g._Next = 1; else _g._Next = 2;
			_g._Phi = 0;
			return null;
		};
		var _Block1 = function() {
			_g._Next = 2;
			_g._Phi = 1;
			return null;
		};
		var _Block2 = function() {
			if(_g._Phi == 0) _g._t2 = 1; else if(_g._Phi == 1) _g._t2 = -1; else _g._t2 = 0.0;
			var _t3 = 0;
			var _t6 = false;
			var _v1 = _g.p_b;
			var _v2;
			var v;
			var v1 = new tardis.Int64(0,23);
			v = v1;
			_v2 = tardis.Int64.getLow(v);
			if(_v2 == 0) _t3 = _v1; else _t3 = _v1 >>> _v2;
			_g._t4 = (_t3 & 255) >>> 0;
			_g._t5 = (_g.p_b & 8388607) >>> 0;
			_t6 = tardis.Force.uintCompare(_g._t4,255) == 0;
			if(_t6) _g._Next = 3; else _g._Next = 4;
			_g._Phi = 2;
			return null;
		};
		var _Block3 = function() {
			var _t7 = false;
			_t7 = tardis.Force.uintCompare(_g._t5,0) == 0;
			if(_t7) _g._Next = 5; else _g._Next = 6;
			_g._Phi = 3;
			return null;
		};
		var _Block4 = function() {
			var _t8 = false;
			_t8 = tardis.Force.uintCompare(_g._t4,0) != 0;
			if(_t8) _g._Next = 7; else _g._Next = 8;
			_g._Phi = 4;
			return null;
		};
		var _Block5 = function() {
			_g._t9 = tardis.Force.floatDiv(_g._t2,0);
			_g._res = _g._t9;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block6 = function() {
			_g._t10 = Math.NaN;
			_g._t11 = _g._t10;
			_g._res = _g._t11;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block7 = function() {
			_g._t12 = _g._t5 + 8388608 >>> 0;
			_g._Next = 8;
			_g._Phi = 7;
			return null;
		};
		var _Block8 = function() {
			if(_g._Phi == 4) _g._t13 = _g._t5; else if(_g._Phi == 7) _g._t13 = _g._t12; else _g._t13 = 0;
			var _t14 = false;
			_t14 = tardis.Force.uintCompare(_g._t4,0) == 0;
			if(_t14) _g._Next = 9; else _g._Next = 10;
			_g._Phi = 8;
			return null;
		};
		var _Block9 = function() {
			_g._Next = 10;
			_g._Phi = 9;
			return null;
		};
		var _Block10 = function() {
			if(_g._Phi == 8) _g._t15 = _g._t4; else if(_g._Phi == 9) _g._t15 = 1; else _g._t15 = 0;
			var _t17 = 0;
			var _t18 = 0;
			_g._t16 = tardis._Go.HaxeInt64abs_Impl_.toUFloat((function($this) {
				var $r;
				var v2 = new tardis.Int64(0,_g._t13);
				$r = v2;
				return $r;
			}(this)));
			_t17 = _g._t15;
			_t18 = _t17 - 1023 >> 0;
			_g._t19 = _t18 - 52 >> 0;
			_g._SF2 = new tardis._Go.Go_tgoaddmath_pow2(_g._goroutine,[],_g._t19);
			_g._Next = -2;
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			_g._t20 = _g._SF2.res();
			var _t21 = 0.0;
			var _t22 = 0.0;
			_t21 = _g._t16 * _g._t20;
			_t22 = _t21;
			_g._t23 = _t22 * _g._t2;
			_g._res = _g._t23;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case 9:
				retVal = _Block9();
				break;
			case 10:
				retVal = _Block10();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_tgoaddmath_glrFloat32frombits
});
tardis._Go.Go_main_monitor = function(gr,_bds) {
	this._t112 = null;
	this._t109 = null;
	this._t106 = null;
	this._t104 = null;
	this._t98 = 0;
	this._t91 = null;
	this._t85 = 0;
	this._t82 = 0;
	this._t78 = 0;
	this._t73 = null;
	this._t69 = null;
	this._t66 = null;
	this._t63 = null;
	this._t60 = null;
	this._t58 = null;
	this._t49 = 0;
	this._t45 = 0;
	this._t38 = null;
	this._t32 = 0;
	this._t29 = 0;
	this._t25 = 0;
	this._t20 = null;
	this._t16 = null;
	this._t14 = null;
	this._t12 = null;
	this._t6 = 0;
	tardis.StackFrameBasis.call(this,gr,300,"Go_main_monitor");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_monitor.__name__ = true;
tardis._Go.Go_main_monitor.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_monitor.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_monitor.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = null;
			var _t1 = 0;
			var _t2 = false;
			_t0 = tardis.Go.main_smallpile.load();
			var _v = _t0;
			if(_v == null) _t1 = 0; else _t1 = _v.num_entries;
			_t2 = _t1 > 0;
			if(_t2) _g._Next = 1; else _g._Next = 3;
			return null;
		};
		var _Block1 = function() {
			var _t3 = false;
			_t3 = tardis.Go.main_showingBooks.load_bool();
			if(_t3) _g._Next = 2; else _g._Next = 4;
			return null;
		};
		var _Block2 = function() {
			var _t4 = 0;
			var _t5 = 0;
			var _t7 = null;
			var _t8 = null;
			var _t9 = 0;
			var _t10 = false;
			_t4 = tardis.Go.main_Sprite1state.load_int32();
			_t5 = 15 * _t4 >> 0;
			_g._t6 = 140 + _t5 >> 0;
			_t7 = tardis.Go.main_Logo1.load();
			_t8 = _t7.addr(8);
			_t9 = _t8.obj.get_int32(_t8.off);
			_t10 = _t9 != _g._t6;
			if(_t10) _g._Next = 6; else _g._Next = 7;
			return null;
		};
		var _Block3 = function() {
			var _t11 = false;
			_t11 = tardis.Go.main_showingBooks.load_bool();
			if(_t11) _g._Next = 5; else _g._Next = 2;
			return null;
		};
		var _Block4 = function() {
			_g._t12 = tardis.Go.main_Books.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t12,tardis.Go.main_smallPilePng);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			tardis.Go.main_showingBooks.store_bool(true);
			_g._Next = 2;
			return null;
		};
		var _Block5 = function() {
			_g._t14 = tardis.Go.main_Books.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t14,tardis.Go.main_emptyPilePng);
			_g._Next = -2;
			return _g;
		};
		var _Block_2 = function() {
			tardis.Go.main_showingBooks.store_bool(false);
			_g._Next = 2;
			return null;
		};
		var _Block6 = function() {
			_g._t16 = tardis.Go.main_Logo1.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t16,tardis.Go.main_WT);
			_g._Next = -3;
			return _g;
		};
		var _Block_3 = function() {
			var _t18 = null;
			var _t19 = null;
			_t18 = tardis.Go.main_Logo1.load();
			_t19 = _t18.addr(8);
			_t19.obj.iVec[_t19.off] = _g._t6;
			_g._t20 = tardis.Go.main_Logo1.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t20,tardis.Go.main_L1);
			_g._Next = -4;
			return _g;
		};
		var _Block_4 = function() {
			_g._Next = 7;
			return null;
		};
		var _Block7 = function() {
			var _t22 = 0;
			var _t23 = 0;
			var _t24 = false;
			_t22 = tardis.Go.main_s1state.load_int32();
			_t23 = tardis.Go.main_Sprite1state.load_int32();
			_t24 = _t22 != _t23;
			if(_t24) _g._Next = 8; else _g._Next = 9;
			return null;
		};
		var _Block8 = function() {
			var _t26 = false;
			_g._t25 = tardis.Go.main_s1state.load_int32();
			_t26 = _g._t25 == 2;
			if(_t26) _g._Next = 11; else _g._Next = 12;
			return null;
		};
		var _Block9 = function() {
			var _t27 = 0.0;
			var _t28 = 0.0;
			var _t30 = 0.0;
			var _t31 = 0.0;
			var _t33 = null;
			var _t34 = null;
			var _t35 = 0;
			var _t36 = false;
			_t27 = tardis.Go.main_Sprite1X.load_float64();
			_t28 = 90 + _t27;
			_g._t29 = tardis.Force.toInt32((function($this) {
				var $r;
				var _f = _t28;
				$r = _f >= 0?Math.floor(_f):Math.ceil(_f);
				return $r;
			}(this)));
			_t30 = tardis.Go.main_Sprite1Y.load_float64();
			_t31 = 45 + _t30;
			_g._t32 = tardis.Force.toInt32((function($this) {
				var $r;
				var _f1 = _t31;
				$r = _f1 >= 0?Math.floor(_f1):Math.ceil(_f1);
				return $r;
			}(this)));
			_t33 = tardis.Go.main_Sprite1.load();
			_t34 = _t33.addr(4);
			_t35 = _t34.obj.get_int32(_t34.off);
			_t36 = _t35 != _g._t29;
			if(_t36) _g._Next = 13; else _g._Next = 15;
			return null;
		};
		var _Block10 = function() {
			var _t37 = 0;
			_t37 = tardis.Go.main_Sprite1state.load_int32();
			tardis.Go.main_s1state.store_int32(_t37);
			_g._Next = 9;
			return null;
		};
		var _Block11 = function() {
			_g._t38 = tardis.Go.main_Sprite1.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t38,tardis.Go.main_white);
			_g._Next = -5;
			return _g;
		};
		var _Block_5 = function() {
			_g._Next = 10;
			return null;
		};
		var _Block12 = function() {
			var _t40 = false;
			_t40 = _g._t25 == 0;
			if(_t40) _g._Next = 11; else _g._Next = 10;
			return null;
		};
		var _Block13 = function() {
			var _t41 = null;
			var _t42 = null;
			var _t43 = null;
			var _t44 = null;
			var _t46 = false;
			_t41 = tardis.Go.main_Sprite1.load();
			_t42 = _t41.addr(4);
			_t42.obj.iVec[_t42.off] = _g._t29;
			_t43 = tardis.Go.main_Sprite1.load();
			_t44 = _t43.addr(8);
			_t44.obj.iVec[_t44.off] = _g._t32;
			_g._t45 = tardis.Go.main_Sprite1state.load_int32();
			_t46 = _g._t45 == 0;
			if(_t46) _g._Next = 16; else _g._Next = 18;
			return null;
		};
		var _Block14 = function() {
			var _t47 = 0;
			var _t48 = 0;
			var _t50 = null;
			var _t51 = null;
			var _t52 = 0;
			var _t53 = false;
			_t47 = tardis.Go.main_Sprite2state.load_int32();
			_t48 = 15 * _t47 >> 0;
			_g._t49 = 140 + _t48 >> 0;
			_t50 = tardis.Go.main_Logo2.load();
			_t51 = _t50.addr(8);
			_t52 = _t51.obj.get_int32(_t51.off);
			_t53 = _t52 != _g._t49;
			if(_t53) _g._Next = 23; else _g._Next = 24;
			return null;
		};
		var _Block15 = function() {
			var _t54 = null;
			var _t55 = null;
			var _t56 = 0;
			var _t57 = false;
			_t54 = tardis.Go.main_Sprite1.load();
			_t55 = _t54.addr(8);
			_t56 = _t55.obj.get_int32(_t55.off);
			_t57 = _t56 != _g._t32;
			if(_t57) _g._Next = 13; else _g._Next = 14;
			return null;
		};
		var _Block16 = function() {
			_g._t58 = tardis.Go.main_Sprite1.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t58,tardis.Go.main_pickPng1);
			_g._Next = -6;
			return _g;
		};
		var _Block_6 = function() {
			_g._Next = 14;
			return null;
		};
		var _Block17 = function() {
			_g._t60 = tardis.Go.main_Sprite1.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t60,tardis.Go.main_fullPng1);
			_g._Next = -7;
			return _g;
		};
		var _Block_7 = function() {
			_g._Next = 14;
			return null;
		};
		var _Block18 = function() {
			var _t62 = false;
			_t62 = _g._t45 == 1;
			if(_t62) _g._Next = 17; else _g._Next = 20;
			return null;
		};
		var _Block19 = function() {
			_g._t63 = tardis.Go.main_Sprite1.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t63,tardis.Go.main_shovelPng1);
			_g._Next = -8;
			return _g;
		};
		var _Block_8 = function() {
			_g._Next = 14;
			return null;
		};
		var _Block20 = function() {
			var _t65 = false;
			_t65 = _g._t45 == 2;
			if(_t65) _g._Next = 19; else _g._Next = 22;
			return null;
		};
		var _Block21 = function() {
			_g._t66 = tardis.Go.main_Sprite1.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t66,tardis.Go.main_emptyPng1);
			_g._Next = -9;
			return _g;
		};
		var _Block_9 = function() {
			_g._Next = 14;
			return null;
		};
		var _Block22 = function() {
			var _t68 = false;
			_t68 = _g._t45 == 3;
			if(_t68) _g._Next = 21; else _g._Next = 14;
			return null;
		};
		var _Block23 = function() {
			_g._t69 = tardis.Go.main_Logo2.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t69,tardis.Go.main_WT);
			_g._Next = -10;
			return _g;
		};
		var _Block_10 = function() {
			var _t71 = null;
			var _t72 = null;
			_t71 = tardis.Go.main_Logo2.load();
			_t72 = _t71.addr(8);
			_t72.obj.iVec[_t72.off] = _g._t49;
			_g._t73 = tardis.Go.main_Logo2.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t73,tardis.Go.main_L2);
			_g._Next = -11;
			return _g;
		};
		var _Block_11 = function() {
			_g._Next = 24;
			return null;
		};
		var _Block24 = function() {
			var _t75 = 0;
			var _t76 = 0;
			var _t77 = false;
			_t75 = tardis.Go.main_s2state.load_int32();
			_t76 = tardis.Go.main_Sprite2state.load_int32();
			_t77 = _t75 != _t76;
			if(_t77) _g._Next = 25; else _g._Next = 26;
			return null;
		};
		var _Block25 = function() {
			var _t79 = false;
			_g._t78 = tardis.Go.main_s2state.load_int32();
			_t79 = _g._t78 == 2;
			if(_t79) _g._Next = 28; else _g._Next = 29;
			return null;
		};
		var _Block26 = function() {
			var _t80 = 0.0;
			var _t81 = 0.0;
			var _t83 = 0.0;
			var _t84 = 0.0;
			var _t86 = null;
			var _t87 = null;
			var _t88 = 0;
			var _t89 = false;
			_t80 = tardis.Go.main_Sprite2X.load_float64();
			_t81 = 420 + _t80;
			_g._t82 = tardis.Force.toInt32((function($this) {
				var $r;
				var _f2 = _t81;
				$r = _f2 >= 0?Math.floor(_f2):Math.ceil(_f2);
				return $r;
			}(this)));
			_t83 = tardis.Go.main_Sprite2Y.load_float64();
			_t84 = 45 + _t83;
			_g._t85 = tardis.Force.toInt32((function($this) {
				var $r;
				var _f3 = _t84;
				$r = _f3 >= 0?Math.floor(_f3):Math.ceil(_f3);
				return $r;
			}(this)));
			_t86 = tardis.Go.main_Sprite2.load();
			_t87 = _t86.addr(4);
			_t88 = _t87.obj.get_int32(_t87.off);
			_t89 = _t88 != _g._t82;
			if(_t89) _g._Next = 30; else _g._Next = 32;
			return null;
		};
		var _Block27 = function() {
			var _t90 = 0;
			_t90 = tardis.Go.main_Sprite2state.load_int32();
			tardis.Go.main_s2state.store_int32(_t90);
			_g._Next = 26;
			return null;
		};
		var _Block28 = function() {
			_g._t91 = tardis.Go.main_Sprite2.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t91,tardis.Go.main_white);
			_g._Next = -12;
			return _g;
		};
		var _Block_12 = function() {
			_g._Next = 27;
			return null;
		};
		var _Block29 = function() {
			var _t93 = false;
			_t93 = _g._t78 == 0;
			if(_t93) _g._Next = 28; else _g._Next = 27;
			return null;
		};
		var _Block30 = function() {
			var _t94 = null;
			var _t95 = null;
			var _t96 = null;
			var _t97 = null;
			var _t99 = false;
			_t94 = tardis.Go.main_Sprite2.load();
			_t95 = _t94.addr(4);
			_t95.obj.iVec[_t95.off] = _g._t82;
			_t96 = tardis.Go.main_Sprite2.load();
			_t97 = _t96.addr(8);
			_t97.obj.iVec[_t97.off] = _g._t85;
			_g._t98 = tardis.Go.main_Sprite2state.load_int32();
			_t99 = _g._t98 == 0;
			if(_t99) _g._Next = 33; else _g._Next = 35;
			return null;
		};
		var _Block31 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block32 = function() {
			var _t100 = null;
			var _t101 = null;
			var _t102 = 0;
			var _t103 = false;
			_t100 = tardis.Go.main_Sprite2.load();
			_t101 = _t100.addr(8);
			_t102 = _t101.obj.get_int32(_t101.off);
			_t103 = _t102 != _g._t85;
			if(_t103) _g._Next = 30; else _g._Next = 31;
			return null;
		};
		var _Block33 = function() {
			_g._t104 = tardis.Go.main_Sprite2.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t104,tardis.Go.main_pickPng2);
			_g._Next = -13;
			return _g;
		};
		var _Block_13 = function() {
			_g._Next = 31;
			return null;
		};
		var _Block34 = function() {
			_g._t106 = tardis.Go.main_Sprite2.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t106,tardis.Go.main_fullPng2);
			_g._Next = -14;
			return _g;
		};
		var _Block_14 = function() {
			_g._Next = 31;
			return null;
		};
		var _Block35 = function() {
			var _t108 = false;
			_t108 = _g._t98 == 1;
			if(_t108) _g._Next = 34; else _g._Next = 37;
			return null;
		};
		var _Block36 = function() {
			_g._t109 = tardis.Go.main_Sprite2.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t109,tardis.Go.main_shovelPng2);
			_g._Next = -15;
			return _g;
		};
		var _Block_15 = function() {
			_g._Next = 31;
			return null;
		};
		var _Block37 = function() {
			var _t111 = false;
			_t111 = _g._t98 == 2;
			if(_t111) _g._Next = 36; else _g._Next = 39;
			return null;
		};
		var _Block38 = function() {
			_g._t112 = tardis.Go.main_Sprite2.load();
			new tardis._Go.Go_main_replaceBitmap(_g._goroutine,[],_g._t112,tardis.Go.main_emptyPng2);
			_g._Next = -16;
			return _g;
		};
		var _Block_16 = function() {
			_g._Next = 31;
			return null;
		};
		var _Block39 = function() {
			var _t114 = false;
			_t114 = _g._t98 == 3;
			if(_t114) _g._Next = 38; else _g._Next = 31;
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case 9:
				retVal = _Block9();
				break;
			case 10:
				retVal = _Block10();
				break;
			case 11:
				retVal = _Block11();
				break;
			case 12:
				retVal = _Block12();
				break;
			case 13:
				retVal = _Block13();
				break;
			case 14:
				retVal = _Block14();
				break;
			case 15:
				retVal = _Block15();
				break;
			case 16:
				retVal = _Block16();
				break;
			case 17:
				retVal = _Block17();
				break;
			case 18:
				retVal = _Block18();
				break;
			case 19:
				retVal = _Block19();
				break;
			case 20:
				retVal = _Block20();
				break;
			case 21:
				retVal = _Block21();
				break;
			case 22:
				retVal = _Block22();
				break;
			case 23:
				retVal = _Block23();
				break;
			case 24:
				retVal = _Block24();
				break;
			case 25:
				retVal = _Block25();
				break;
			case 26:
				retVal = _Block26();
				break;
			case 27:
				retVal = _Block27();
				break;
			case 28:
				retVal = _Block28();
				break;
			case 29:
				retVal = _Block29();
				break;
			case 30:
				retVal = _Block30();
				break;
			case 31:
				retVal = _Block31();
				break;
			case 32:
				retVal = _Block32();
				break;
			case 33:
				retVal = _Block33();
				break;
			case 34:
				retVal = _Block34();
				break;
			case 35:
				retVal = _Block35();
				break;
			case 36:
				retVal = _Block36();
				break;
			case 37:
				retVal = _Block37();
				break;
			case 38:
				retVal = _Block38();
				break;
			case 39:
				retVal = _Block39();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			case -3:
				retVal = _Block_3();
				break;
			case -4:
				retVal = _Block_4();
				break;
			case -5:
				retVal = _Block_5();
				break;
			case -6:
				retVal = _Block_6();
				break;
			case -7:
				retVal = _Block_7();
				break;
			case -8:
				retVal = _Block_8();
				break;
			case -9:
				retVal = _Block_9();
				break;
			case -10:
				retVal = _Block_10();
				break;
			case -11:
				retVal = _Block_11();
				break;
			case -12:
				retVal = _Block_12();
				break;
			case -13:
				retVal = _Block_13();
				break;
			case -14:
				retVal = _Block_14();
				break;
			case -15:
				retVal = _Block_15();
				break;
			case -16:
				retVal = _Block_16();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_monitor
});
tardis._Go.Go_main_init = function(gr,_bds) {
	tardis.StackFrameBasis.call(this,gr,373,"Go_main_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_init.__name__ = true;
tardis._Go.Go_main_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = tardis.Go.main_init_36_guard.load_bool();
			if(_t0) _g._Next = 2; else _g._Next = 1;
			return null;
		};
		var _Block1 = function() {
			tardis.Go.main_init_36_guard.store_bool(true);
			new tardis._Go.Go_tardisgolib_init(_g._goroutine,[]);
			_g._Next = -2;
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			var _t4 = null;
			_t4 = new tardis.Channel(0);
			tardis.Go.main_spChan.store(_t4);
			tardis.Go.main_showingBooks.store_bool(true);
			tardis.Go.main_s1state.store_int32(0);
			tardis.Go.main_s2state.store_int32(0);
			_g._Next = 2;
			return null;
		};
		var _Block2 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block_3 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			case -3:
				retVal = _Block_3();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_init
});
tardis.Go_utf16_Encode = $hx_exports.Go_utf16_Encode = function(gr,_bds,p_s) {
	this._Phi = 0;
	this._t37 = 0;
	this._t29 = null;
	this._SF1 = null;
	this._t27 = false;
	this._t26 = false;
	this._t23 = 0;
	this._t20 = 0;
	this._t19 = null;
	this._t17 = 0;
	this._t14 = 0;
	this._t13 = 0;
	this._t12 = 0;
	this._t11 = 0;
	this._t10 = 0;
	this._t9 = null;
	this._t4 = 0;
	this._t3 = 0;
	this._t2 = 0;
	this._t1 = 0;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,595,"Go_utf16_Encode");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_utf16_Encode.__name__ = true;
tardis.Go_utf16_Encode.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf16_Encode.__super__ = tardis.StackFrameBasis;
tardis.Go_utf16_Encode.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _v = _g.p_s;
			if(_v == null) _g._t0 = 0; else _g._t0 = _v.length;
			var _v1 = _g.p_s;
			if(_v1 == null) _g._t1 = 0; else _g._t1 = _v1.length;
			_g._Next = 1;
			_g._Phi = 0;
			return null;
		};
		var _Block1 = function() {
			var _g1 = _g._Phi;
			switch(_g1) {
			case 2:
				_g._t3 = _g._t4;
				break;
			case 4:
				_g._t2 = _g._t11;
				_g._t3 = _g._t4;
				break;
			case 0:
				_g._t2 = _g._t0;
				_g._t3 = -1;
				break;
			}
			var _t5 = false;
			_g._t4 = _g._t3 + 1 >> 0;
			_t5 = _g._t4 < _g._t1;
			if(_t5) _g._Next = 2; else _g._Next = 3;
			_g._Phi = 1;
			return null;
		};
		var _Block2 = function() {
			var _t6 = null;
			var _t7 = 0;
			var _t8 = false;
			tardis.Scheduler.wraprangechk(_g._t4,_g.p_s.length);
			_t6 = _g.p_s.itemAddr(_g._t4);
			_t7 = _t6.obj.get_int32(_t6.off);
			_t8 = _t7 >= 65536;
			if(_t8) _g._Next = 4; else _g._Next = 1;
			_g._Phi = 2;
			return null;
		};
		var _Block3 = function() {
			_g._t9 = new tardis.Slice(new tardis.Pointer(new tardis.Object(_g._t2 * 2)),0,_g._t2,_g._t2,2);
			var _v2 = _g.p_s;
			if(_v2 == null) _g._t10 = 0; else _g._t10 = _v2.length;
			_g._Next = 5;
			_g._Phi = 3;
			return null;
		};
		var _Block4 = function() {
			_g._t11 = _g._t2 + 1 >> 0;
			_g._Next = 1;
			_g._Phi = 4;
			return null;
		};
		var _Block5 = function() {
			var _g11 = _g._Phi;
			switch(_g11) {
			case 15:
				_g._t12 = _g._t37;
				_g._t13 = _g._t14;
				break;
			case 3:
				_g._t12 = 0;
				_g._t13 = -1;
				break;
			case 9:
				_g._t12 = _g._t23;
				_g._t13 = _g._t14;
				break;
			}
			var _t15 = false;
			_g._t14 = _g._t13 + 1 >> 0;
			_t15 = _g._t14 < _g._t10;
			if(_t15) _g._Next = 6; else _g._Next = 7;
			_g._Phi = 5;
			return null;
		};
		var _Block6 = function() {
			var _t16 = null;
			var _t18 = false;
			tardis.Scheduler.wraprangechk(_g._t14,_g.p_s.length);
			_t16 = _g.p_s.itemAddr(_g._t14);
			_g._t17 = _t16.obj.get_int32(_t16.off);
			_t18 = _g._t17 < 0;
			if(_t18) _g._Next = 8; else _g._Next = 10;
			_g._Phi = 6;
			return null;
		};
		var _Block7 = function() {
			_g._t19 = _g._t9.subSlice(0,_g._t12);
			_g._res = _g._t19;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block8 = function() {
			_g._Next = 9;
			_g._Phi = 8;
			return null;
		};
		var _Block9 = function() {
			if(_g._Phi == 8) _g._t20 = 65533; else if(_g._Phi == 14) _g._t20 = _g._t17; else _g._t20 = 0;
			var _t21 = null;
			var _t22 = 0;
			tardis.Scheduler.wraprangechk(_g._t12,_g._t9.length);
			_t21 = _g._t9.itemAddr(_g._t12);
			_t22 = _g._t20;
			_t21.obj.iVec[_t21.off] = _t22;
			_g._t23 = _g._t12 + 1 >> 0;
			_g._Next = 5;
			_g._Phi = 9;
			return null;
		};
		var _Block10 = function() {
			var _t24 = false;
			_t24 = 55296 <= _g._t17;
			if(_t24) _g._Next = 12; else _g._Next = 13;
			_g._Phi = 10;
			return null;
		};
		var _Block11 = function() {
			var _t25 = false;
			_t25 = _g._t17 > 1114111;
			if(_t25) _g._Next = 8; else _g._Next = 14;
			_g._Phi = 11;
			return null;
		};
		var _Block12 = function() {
			_g._t26 = _g._t17 < 57344;
			_g._Next = 13;
			_g._Phi = 12;
			return null;
		};
		var _Block13 = function() {
			if(_g._Phi == 10) _g._t27 = false; else if(_g._Phi == 12) _g._t27 = _g._t26; else _g._t27 = false;
			if(_g._t27) _g._Next = 8; else _g._Next = 11;
			_g._Phi = 13;
			return null;
		};
		var _Block14 = function() {
			var _t28 = false;
			_t28 = _g._t17 < 65536;
			if(_t28) _g._Next = 9; else _g._Next = 15;
			_g._Phi = 14;
			return null;
		};
		var _Block15 = function() {
			_g._SF1 = new tardis.Go_utf16_EncodeRune(_g._goroutine,[],_g._t17);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._t29 = _g._SF1.res();
			var _t30 = 0;
			var _t31 = 0;
			var _t32 = null;
			var _t33 = 0;
			var _t34 = 0;
			var _t35 = null;
			var _t36 = 0;
			_t30 = _g._t29.r0;
			_t31 = _g._t29.r1;
			tardis.Scheduler.wraprangechk(_g._t12,_g._t9.length);
			_t32 = _g._t9.itemAddr(_g._t12);
			_t33 = _t30;
			_t32.obj.iVec[_t32.off] = _t33;
			_t34 = _g._t12 + 1 >> 0;
			if(_t34 < 0 || _t34 >= _g._t9.length) tardis.Scheduler.ioor();
			_t35 = _g._t9.itemAddr(_t34);
			_t36 = _t31;
			_t35.obj.iVec[_t35.off] = _t36;
			_g._t37 = _g._t12 + 2 >> 0;
			_g._Next = 5;
			_g._Phi = 15;
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g2 = this._Next;
			switch(_g2) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case 9:
				retVal = _Block9();
				break;
			case 10:
				retVal = _Block10();
				break;
			case 11:
				retVal = _Block11();
				break;
			case 12:
				retVal = _Block12();
				break;
			case 13:
				retVal = _Block13();
				break;
			case 14:
				retVal = _Block14();
				break;
			case 15:
				retVal = _Block15();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_utf16_Encode
});
tardis.Go_utf16_EncodeRune = $hx_exports.Go_utf16_EncodeRune = function(gr,_bds,p_r) {
	this._t7 = false;
	this._SF1 = null;
	this._t6 = 0;
	this._t4 = 0;
	tardis.StackFrameBasis.call(this,gr,586,"Go_utf16_EncodeRune");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_utf16_EncodeRune.__name__ = true;
tardis.Go_utf16_EncodeRune.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf16_EncodeRune.__super__ = tardis.StackFrameBasis;
tardis.Go_utf16_EncodeRune.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = _g.p_r < 65536;
			if(_t0) _g._Next = 1; else _g._Next = 4;
			return null;
		};
		var _Block1 = function() {
			_g._res = { r0 : 65533, r1 : 65533};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block2 = function() {
			var _t1 = 0;
			var _t2 = 0;
			var _t3 = 0;
			var _t5 = 0;
			_t1 = _g.p_r - 65536 >> 0;
			var _v1 = _t1;
			var _v2;
			var v;
			var v1 = new tardis.Int64(0,10);
			v = v1;
			_v2 = tardis.Int64.getLow(v);
			if(_v2 == 0) _t2 = _v1; else _t2 = _v1 >> _v2;
			_t3 = (_t2 & 1023) >> 0;
			_g._t4 = 55296 + _t3 >> 0;
			_t5 = (_t1 & 1023) >> 0;
			_g._t6 = 56320 + _t5 >> 0;
			_g._res = { r0 : _g._t4, r1 : _g._t6};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block3 = function() {
			_g._SF1 = new tardis.Go_utf16_IsSurrogate(_g._goroutine,[],_g.p_r);
			_g._SF1.run();
			_g._t7 = _g._SF1.res();
			if(_g._t7) _g._Next = 1; else _g._Next = 2;
			return null;
		};
		var _Block4 = function() {
			var _t8 = false;
			_t8 = _g.p_r > 1114111;
			if(_t8) _g._Next = 1; else _g._Next = 3;
			return null;
		};
		var _Block_1 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_utf16_EncodeRune
});
tardis.Go_haxegoruntime_Runes2Raw = $hx_exports.Go_haxegoruntime_Runes2Raw = function(gr,_bds,p_r) {
	this._Phi = 0;
	this._t21 = 0;
	this._t20 = 0;
	this._t19 = null;
	this._t12 = 0;
	this._t11 = 0;
	this._t9 = 0;
	this._t8 = null;
	this._t6 = null;
	this._SF2 = null;
	this._t5 = 0;
	this._t4 = null;
	this._t2 = null;
	this._SF1 = null;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,488,"Go_haxegoruntime_Runes2Raw");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_haxegoruntime_Runes2Raw.__name__ = true;
tardis.Go_haxegoruntime_Runes2Raw.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_Runes2Raw.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_Runes2Raw.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t1 = false;
			_g._t0 = tardis.Go.haxegoruntime_ZiLen.load_int32();
			_t1 = _g._t0 == 1;
			if(_t1) _g._Next = 1; else _g._Next = 3;
			_g._Phi = 0;
			return null;
		};
		var _Block1 = function() {
			_g._SF1 = new tardis.Go_haxegoruntime_RunesToUTF16(_g._goroutine,[],_g.p_r);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._t2 = _g._SF1.res();
			var _t3 = 0;
			var _v = _g._t2;
			if(_v == null) _t3 = 0; else _t3 = _v.length;
			_g._t4 = new tardis.Slice(new tardis.Pointer(new tardis.Object(_t3 * 4)),0,_t3,_t3,4);
			var _v1 = _g._t2;
			if(_v1 == null) _g._t5 = 0; else _g._t5 = _v1.length;
			_g._Next = 4;
			_g._Phi = 1;
			return null;
		};
		var _Block2 = function() {
			_g._SF2 = new tardis.Go_haxegoruntime_RunesToUTF8(_g._goroutine,[],_g.p_r);
			_g._Next = -2;
			return _g;
		};
		var _Block_2 = function() {
			_g._t6 = _g._SF2.res();
			var _t7 = 0;
			var _v2 = _g._t6;
			if(_v2 == null) _t7 = 0; else _t7 = _v2.length;
			_g._t8 = new tardis.Slice(new tardis.Pointer(new tardis.Object(_t7 * 4)),0,_t7,_t7,4);
			var _v3 = _g._t6;
			if(_v3 == null) _g._t9 = 0; else _g._t9 = _v3.length;
			_g._Next = 8;
			_g._Phi = 2;
			return null;
		};
		var _Block3 = function() {
			var _t10 = false;
			_t10 = _g._t0 == 3;
			if(_t10) _g._Next = 2; else _g._Next = 7;
			_g._Phi = 3;
			return null;
		};
		var _Block4 = function() {
			if(_g._Phi == 1) _g._t11 = -1; else if(_g._Phi == 5) _g._t11 = _g._t12; else _g._t11 = 0;
			var _t13 = false;
			_g._t12 = _g._t11 + 1 >> 0;
			_t13 = _g._t12 < _g._t5;
			if(_t13) _g._Next = 5; else _g._Next = 6;
			_g._Phi = 4;
			return null;
		};
		var _Block5 = function() {
			var _t14 = null;
			var _t15 = null;
			var _t16 = 0;
			var _t17 = 0;
			tardis.Scheduler.wraprangechk(_g._t12,_g._t4.length);
			_t14 = _g._t4.itemAddr(_g._t12);
			tardis.Scheduler.wraprangechk(_g._t12,_g._t2.length);
			_t15 = _g._t2.itemAddr(_g._t12);
			_t16 = _t15.obj.get_uint16(_t15.off);
			_t17 = _t16;
			_t14.obj.iVec[_t14.off] = _t17;
			_g._Next = 4;
			_g._Phi = 5;
			return null;
		};
		var _Block6 = function() {
			_g._res = _g._t4;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block7 = function() {
			var _t18 = null;
			_t18 = new tardis.Pointer(new tardis.Object(0));
			_g._t19 = new tardis.Slice(_t18,0,-1,0,4);
			_g._res = _g._t19;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block8 = function() {
			if(_g._Phi == 2) _g._t20 = -1; else if(_g._Phi == 9) _g._t20 = _g._t21; else _g._t20 = 0;
			var _t22 = false;
			_g._t21 = _g._t20 + 1 >> 0;
			_t22 = _g._t21 < _g._t9;
			if(_t22) _g._Next = 9; else _g._Next = 10;
			_g._Phi = 8;
			return null;
		};
		var _Block9 = function() {
			var _t23 = null;
			var _t24 = null;
			var _t25 = 0;
			var _t26 = 0;
			tardis.Scheduler.wraprangechk(_g._t21,_g._t8.length);
			_t23 = _g._t8.itemAddr(_g._t21);
			tardis.Scheduler.wraprangechk(_g._t21,_g._t6.length);
			_t24 = _g._t6.itemAddr(_g._t21);
			_t25 = _t24.obj.get_uint8(_t24.off);
			_t26 = _t25;
			_t23.obj.iVec[_t23.off] = _t26;
			_g._Next = 8;
			_g._Phi = 9;
			return null;
		};
		var _Block10 = function() {
			_g._res = _g._t8;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case 9:
				retVal = _Block9();
				break;
			case 10:
				retVal = _Block10();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_haxegoruntime_Runes2Raw
});
tardis._Go.Go_tgoaddmath_glrFloat32bits = function(gr,_bds,p_f) {
	this._Phi = 0;
	this._t33 = 0;
	this._t28 = 0.0;
	this._t27 = 0.0;
	this._t25 = 0.0;
	this._t20 = null;
	this._t19 = 0.0;
	this._t17 = 0;
	this._t16 = 0.0;
	this._t14 = 0;
	this._t12 = 0;
	this._t11 = 0;
	this._t9 = 0;
	this._t8 = 0.0;
	this._t6 = 0.0;
	this._t5 = 0;
	this._t4 = 0.0;
	this._t3 = 0.0;
	tardis.StackFrameBasis.call(this,gr,1288,"Go_tgoaddmath_glrFloat32bits");
	this._bds = _bds;
	this.p_f = p_f;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_tgoaddmath_glrFloat32bits.__name__ = true;
tardis._Go.Go_tgoaddmath_glrFloat32bits.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_tgoaddmath_glrFloat32bits.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_tgoaddmath_glrFloat32bits.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = false;
			_t0 = _g.p_f == 0;
			if(_t0) _g._Next = 1; else _g._Next = 2;
			_g._Phi = 0;
			return null;
		};
		var _Block1 = function() {
			_g._res = 0;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block2 = function() {
			var _t1 = false;
			_t1 = _g.p_f != _g.p_f;
			if(_t1) _g._Next = 3; else _g._Next = 4;
			_g._Phi = 2;
			return null;
		};
		var _Block3 = function() {
			_g._res = 2143289344;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block4 = function() {
			var _t2 = false;
			_t2 = _g.p_f < 0;
			if(_t2) _g._Next = 5; else _g._Next = 6;
			_g._Phi = 4;
			return null;
		};
		var _Block5 = function() {
			_g._t3 = -_g.p_f;
			_g._Next = 6;
			_g._Phi = 5;
			return null;
		};
		var _Block6 = function() {
			var _g1 = _g._Phi;
			switch(_g1) {
			case 4:
				_g._t4 = _g.p_f;
				_g._t5 = 0;
				break;
			case 5:
				_g._t4 = _g._t3;
				_g._t5 = 0x80000000;
				break;
			}
			_g._Next = 8;
			_g._Phi = 6;
			return null;
		};
		var _Block7 = function() {
			var _t7 = false;
			_g._t6 = tardis.Force.floatDiv(_g._t8,2);
			_t7 = tardis.Force.uintCompare(_g._t9,255) == 0;
			if(_t7) _g._Next = 12; else _g._Next = 9;
			_g._Phi = 7;
			return null;
		};
		var _Block8 = function() {
			var _g11 = _g._Phi;
			switch(_g11) {
			case 6:
				_g._t8 = _g._t4;
				_g._t9 = 150;
				break;
			case 9:
				_g._t8 = _g._t6;
				_g._t9 = _g._t11;
				break;
			}
			var _t10 = false;
			_t10 = _g._t8 >= 1.6777216e+07;
			if(_t10) _g._Next = 7; else _g._Next = 12;
			_g._Phi = 8;
			return null;
		};
		var _Block9 = function() {
			_g._t11 = _g._t9 + 1 >>> 0;
			_g._Next = 8;
			_g._Phi = 9;
			return null;
		};
		var _Block10 = function() {
			var _t13 = false;
			_g._t12 = _g._t17 - 1 >>> 0;
			_t13 = tardis.Force.uintCompare(_g._t12,0) == 0;
			if(_t13) _g._Next = 11; else _g._Next = 13;
			_g._Phi = 10;
			return null;
		};
		var _Block11 = function() {
			if(_g._Phi == 12) _g._t14 = _g._t17; else if(_g._Phi == 10) _g._t14 = _g._t12; else _g._t14 = 0;
			var _t15 = false;
			_t15 = _g._t16 < 0;
			if(_t15) _g._Next = 14; else _g._Next = 15;
			_g._Phi = 11;
			return null;
		};
		var _Block12 = function() {
			var _g12 = _g._Phi;
			switch(_g12) {
			case 8:
				_g._t16 = _g._t8;
				_g._t17 = _g._t9;
				break;
			case 13:
				_g._t16 = _g._t19;
				_g._t17 = _g._t12;
				break;
			case 7:
				_g._t16 = _g._t6;
				_g._t17 = _g._t9;
				break;
			}
			var _t18 = false;
			_t18 = _g._t16 < 8.388608e+06;
			if(_t18) _g._Next = 10; else _g._Next = 11;
			_g._Phi = 12;
			return null;
		};
		var _Block13 = function() {
			_g._t19 = _g._t16 * 2;
			_g._Next = 12;
			_g._Phi = 13;
			return null;
		};
		var _Block14 = function() {
			_g._t20 = new tardis.Interface(1,"glrFloat32bits");
			tardis.Scheduler.panic(_g._goroutine,_g._t20);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block15 = function() {
			var _t21 = 0.0;
			var _t22 = 0.0;
			var _t23 = 0.0;
			var _t24 = 0.0;
			var _t26 = false;
			_t21 = _g._t16;
			_t22 = tardis.Force.floatDiv(_t21,2);
			_t23 = _g._t16;
			_t24 = 2 * _t22;
			_g._t25 = _t23 - _t24;
			_t26 = _g._t25 > 0.5;
			if(_t26) _g._Next = 19; else _g._Next = 18;
			_g._Phi = 15;
			return null;
		};
		var _Block16 = function() {
			_g._t27 = _g._t16 + 1;
			_g._Next = 17;
			_g._Phi = 16;
			return null;
		};
		var _Block17 = function() {
			if(_g._Phi == 18) _g._t28 = _g._t16; else if(_g._Phi == 16) _g._t28 = _g._t27; else _g._t28 = 0.0;
			var _t29 = 0;
			var _t30 = 0;
			var _t31 = 0;
			var _t32 = 0;
			var _v1 = _g._t14;
			var _v2;
			var v;
			var v1 = new tardis.Int64(0,23);
			v = v1;
			_v2 = tardis.Int64.getLow(v);
			if(_v2 == 0) _t29 = _v1; else _t29 = _v1 << _v2;
			_t30 = (_g._t5 | _t29) >>> 0;
			_t31 = tardis.Force.toUint32((function($this) {
				var $r;
				var _f = _g._t28;
				$r = _f >= 0?Math.floor(_f):Math.ceil(_f);
				return $r;
			}(this)));
			_t32 = (_t31 & -8388609) >>> 0;
			_g._t33 = (_t30 | _t32) >>> 0;
			_g._res = _g._t33;
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var _Block18 = function() {
			var _t34 = false;
			_t34 = _g._t25 >= 1.5;
			if(_t34) _g._Next = 16; else _g._Next = 17;
			_g._Phi = 18;
			return null;
		};
		var _Block19 = function() {
			var _t35 = false;
			_t35 = _g._t25 < 1;
			if(_t35) _g._Next = 16; else _g._Next = 18;
			_g._Phi = 19;
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g2 = this._Next;
			switch(_g2) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case 8:
				retVal = _Block8();
				break;
			case 9:
				retVal = _Block9();
				break;
			case 10:
				retVal = _Block10();
				break;
			case 11:
				retVal = _Block11();
				break;
			case 12:
				retVal = _Block12();
				break;
			case 13:
				retVal = _Block13();
				break;
			case 14:
				retVal = _Block14();
				break;
			case 15:
				retVal = _Block15();
				break;
			case 16:
				retVal = _Block16();
				break;
			case 17:
				retVal = _Block17();
				break;
			case 18:
				retVal = _Block18();
				break;
			case 19:
				retVal = _Block19();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_tgoaddmath_glrFloat32bits
});
tardis.Go_main_Start = $hx_exports.Go_main_Start = function(gr,_bds) {
	this._t39 = null;
	this._SF29 = null;
	this._t38 = null;
	this._t37 = null;
	this._SF28 = null;
	this._t36 = null;
	this._t35 = null;
	this._SF27 = null;
	this._t34 = null;
	this._t33 = null;
	this._SF26 = null;
	this._t32 = null;
	this._t31 = null;
	this._SF25 = null;
	this._t30 = null;
	this._t25 = null;
	this._t24 = null;
	this._t23 = null;
	this._t22 = null;
	this._t20 = null;
	this._SF18 = null;
	this._t19 = null;
	this._SF17 = null;
	this._t18 = null;
	this._SF16 = null;
	this._t17 = null;
	this._SF15 = null;
	this._t16 = null;
	this._SF14 = null;
	this._t15 = null;
	this._SF13 = null;
	this._t14 = null;
	this._SF12 = null;
	this._t13 = null;
	this._SF11 = null;
	this._t12 = null;
	this._SF10 = null;
	this._t11 = null;
	this._SF9 = null;
	this._t10 = null;
	this._SF8 = null;
	this._t9 = null;
	this._SF7 = null;
	this._t8 = null;
	this._SF6 = null;
	this._t7 = null;
	this._SF5 = null;
	this._t6 = null;
	this._SF4 = null;
	this._t5 = null;
	this._t4 = null;
	this._t3 = null;
	this._t2 = null;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,219,"Go_main_Start");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_main_Start.__name__ = true;
tardis.Go_main_Start.__interfaces__ = [tardis.StackFrame];
tardis.Go_main_Start.call = function(gr,_bds) {
	return new tardis.Go_main_Start(gr,_bds);
};
tardis.Go_main_Start.__super__ = tardis.StackFrameBasis;
tardis.Go_main_Start.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._t0 = window.document;
			tardis.Go.main_doc.store_uintptr(_g._t0);
			_g._t1 = tardis.Go.main_doc.load_uintptr();
			_g._t2 = new tardis.Interface(1,"myCanvas");
			_g._t3 = _g._t1.getElementById(tardis.Force.toHaxeParam(_g._t2));
			_g._t4 = _g._t3;
			_g._t5 = _g._t4.getContext("2d");
			tardis.Go.main_context.store_uintptr(_g._t5);
			tardis.Go_main_Start_36_1.call(tardis.Scheduler.makeGoroutine(),[]);
			tardis.Go_main_Start_36_2.call(tardis.Scheduler.makeGoroutine(),[]);
			_g._SF4 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/function.png");
			_g._Next = -4;
			return _g;
		};
		var _Block_1 = function() {
			return null;
		};
		var _Block_2 = function() {
			return null;
		};
		var _Block_3 = function() {
			return null;
		};
		var _Block_4 = function() {
			_g._t6 = _g._SF4.res();
			_g._SF5 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/emptypile.png");
			_g._Next = -5;
			return _g;
		};
		var _Block_5 = function() {
			_g._t7 = _g._SF5.res();
			tardis.Go.main_emptyPilePng.store_uintptr(_g._t7);
			_g._SF6 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/gophercolor16x16.png");
			_g._Next = -6;
			return _g;
		};
		var _Block_6 = function() {
			_g._t8 = _g._SF6.res();
			tardis.Go.main_L1.store_uintptr(_g._t8);
			_g._SF7 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/gophercolor16x16flipped.png");
			_g._Next = -7;
			return _g;
		};
		var _Block_7 = function() {
			_g._t9 = _g._SF7.res();
			tardis.Go.main_L2.store_uintptr(_g._t9);
			_g._SF8 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/pick.png");
			_g._Next = -8;
			return _g;
		};
		var _Block_8 = function() {
			_g._t10 = _g._SF8.res();
			tardis.Go.main_pickPng1.store_uintptr(_g._t10);
			_g._SF9 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/pick.png");
			_g._Next = -9;
			return _g;
		};
		var _Block_9 = function() {
			_g._t11 = _g._SF9.res();
			tardis.Go.main_pickPng2.store_uintptr(_g._t11);
			_g._SF10 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/smallpile.png");
			_g._Next = -10;
			return _g;
		};
		var _Block_10 = function() {
			_g._t12 = _g._SF10.res();
			tardis.Go.main_smallPilePng.store_uintptr(_g._t12);
			_g._SF11 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/full.png");
			_g._Next = -11;
			return _g;
		};
		var _Block_11 = function() {
			_g._t13 = _g._SF11.res();
			tardis.Go.main_fullPng1.store_uintptr(_g._t13);
			_g._SF12 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/full.png");
			_g._Next = -12;
			return _g;
		};
		var _Block_12 = function() {
			_g._t14 = _g._SF12.res();
			tardis.Go.main_fullPng2.store_uintptr(_g._t14);
			_g._SF13 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/empty.png");
			_g._Next = -13;
			return _g;
		};
		var _Block_13 = function() {
			_g._t15 = _g._SF13.res();
			tardis.Go.main_emptyPng1.store_uintptr(_g._t15);
			_g._SF14 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/empty.png");
			_g._Next = -14;
			return _g;
		};
		var _Block_14 = function() {
			_g._t16 = _g._SF14.res();
			tardis.Go.main_emptyPng2.store_uintptr(_g._t16);
			_g._SF15 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/shovel.png");
			_g._Next = -15;
			return _g;
		};
		var _Block_15 = function() {
			_g._t17 = _g._SF15.res();
			tardis.Go.main_shovelPng1.store_uintptr(_g._t17);
			_g._SF16 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/shovel.png");
			_g._Next = -16;
			return _g;
		};
		var _Block_16 = function() {
			_g._t18 = _g._SF16.res();
			tardis.Go.main_shovelPng2.store_uintptr(_g._t18);
			_g._SF17 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/white.png");
			_g._Next = -17;
			return _g;
		};
		var _Block_17 = function() {
			_g._t19 = _g._SF17.res();
			tardis.Go.main_white.store_uintptr(_g._t19);
			_g._SF18 = new tardis._Go.Go_main_makeBitmap(_g._goroutine,[],"assets/whitethumb.png");
			_g._Next = -18;
			return _g;
		};
		var _Block_18 = function() {
			_g._t20 = _g._SF18.res();
			tardis.Go.main_WT.store_uintptr(_g._t20);
			new tardis._Go.Go_main_makeHeadline(_g._goroutine,[],0);
			_g._Next = -19;
			return _g;
		};
		var _Block_19 = function() {
			_g._t22 = new tardis.Interface(0,1000);
			_g._t23 = new haxe.Timer(tardis.Force.toHaxeParam(_g._t22));
			tardis.Go.main_headlineTimer.store_uintptr(_g._t23);
			_g._t24 = tardis.Go.main_headlineTimer.load_uintptr();
			_g._t25 = new tardis.Interface(5,new tardis.Closure(tardis._Go.Go_main_makeHeadline.call,null));
			_g._t24.run = tardis.Force.toHaxeParam(_g._t25);
			new tardis._Go.Go_main_makeText(_g._goroutine,[],false,10,140,180,200,32768,"","Both animated gophers are \nrunning the code on the right.\nThe 2 logos show where they\neach are in that code now.\n\nGo calling native JS APIs.");
			_g._Next = -22;
			return _g;
		};
		var _Block_20 = function() {
			return null;
		};
		var _Block_21 = function() {
			return null;
		};
		var _Block_22 = function() {
			new tardis._Go.Go_main_makeText(_g._goroutine,[],true,630,140,200,200,32768,"","Inspired by Rob Pike:\nhttp://blog.golang.org/\nconcurrency-is-not-parallelism\n\nGopher by Renee French,\nCreative Commons 3.0 license");
			_g._Next = -23;
			return _g;
		};
		var _Block_23 = function() {
			new tardis._Go.Go_main_makeSprite(_g._goroutine,[],_g._t6,200,110);
			_g._Next = -24;
			return _g;
		};
		var _Block_24 = function() {
			_g._t30 = tardis.Go.main_emptyPilePng.load_uintptr();
			_g._SF25 = new tardis._Go.Go_main_makeSprite(_g._goroutine,[],_g._t30,390,50);
			_g._Next = -25;
			return _g;
		};
		var _Block_25 = function() {
			_g._t31 = _g._SF25.res();
			tardis.Go.main_Books.store(_g._t31);
			_g._t32 = tardis.Go.main_L1.load_uintptr();
			_g._SF26 = new tardis._Go.Go_main_makeSprite(_g._goroutine,[],_g._t32,230,140);
			_g._Next = -26;
			return _g;
		};
		var _Block_26 = function() {
			_g._t33 = _g._SF26.res();
			tardis.Go.main_Logo1.store(_g._t33);
			_g._t34 = tardis.Go.main_L2.load_uintptr();
			_g._SF27 = new tardis._Go.Go_main_makeSprite(_g._goroutine,[],_g._t34,540,140);
			_g._Next = -27;
			return _g;
		};
		var _Block_27 = function() {
			_g._t35 = _g._SF27.res();
			tardis.Go.main_Logo2.store(_g._t35);
			_g._t36 = tardis.Go.main_pickPng1.load_uintptr();
			_g._SF28 = new tardis._Go.Go_main_makeSprite(_g._goroutine,[],_g._t36,90,45);
			_g._Next = -28;
			return _g;
		};
		var _Block_28 = function() {
			_g._t37 = _g._SF28.res();
			tardis.Go.main_Sprite1.store(_g._t37);
			_g._t38 = tardis.Go.main_pickPng2.load_uintptr();
			_g._SF29 = new tardis._Go.Go_main_makeSprite(_g._goroutine,[],_g._t38,420,45);
			_g._Next = -29;
			return _g;
		};
		var _Block_29 = function() {
			_g._t39 = _g._SF29.res();
			tardis.Go.main_Sprite2.store(_g._t39);
			new tardis._Go.Go_main_startGophers(_g._goroutine,[]);
			_g._Next = -30;
			return _g;
		};
		var _Block_30 = function() {
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			case -3:
				retVal = _Block_3();
				break;
			case -4:
				retVal = _Block_4();
				break;
			case -5:
				retVal = _Block_5();
				break;
			case -6:
				retVal = _Block_6();
				break;
			case -7:
				retVal = _Block_7();
				break;
			case -8:
				retVal = _Block_8();
				break;
			case -9:
				retVal = _Block_9();
				break;
			case -10:
				retVal = _Block_10();
				break;
			case -11:
				retVal = _Block_11();
				break;
			case -12:
				retVal = _Block_12();
				break;
			case -13:
				retVal = _Block_13();
				break;
			case -14:
				retVal = _Block_14();
				break;
			case -15:
				retVal = _Block_15();
				break;
			case -16:
				retVal = _Block_16();
				break;
			case -17:
				retVal = _Block_17();
				break;
			case -18:
				retVal = _Block_18();
				break;
			case -19:
				retVal = _Block_19();
				break;
			case -20:
				retVal = _Block_20();
				break;
			case -21:
				retVal = _Block_21();
				break;
			case -22:
				retVal = _Block_22();
				break;
			case -23:
				retVal = _Block_23();
				break;
			case -24:
				retVal = _Block_24();
				break;
			case -25:
				retVal = _Block_25();
				break;
			case -26:
				retVal = _Block_26();
				break;
			case -27:
				retVal = _Block_27();
				break;
			case -28:
				retVal = _Block_28();
				break;
			case -29:
				retVal = _Block_29();
				break;
			case -30:
				retVal = _Block_30();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_main_Start
});
tardis.Go_utf8_DecodeRune = $hx_exports.Go_utf8_DecodeRune = function(gr,_bds,p_p) {
	this._t2 = 0;
	this._t1 = 0;
	this._t0 = null;
	this._SF1 = null;
	tardis.StackFrameBasis.call(this,gr,869,"Go_utf8_DecodeRune");
	this._bds = _bds;
	this.p_p = p_p;
	tardis.Scheduler.push(gr,this);
};
tardis.Go_utf8_DecodeRune.__name__ = true;
tardis.Go_utf8_DecodeRune.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_DecodeRune.callFromRT = function(_gr,p_p) {
	var _sf = new tardis.Go_utf8_DecodeRune(_gr,null,p_p).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
};
tardis.Go_utf8_DecodeRune.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_DecodeRune.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return this._res;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._SF1 = new tardis._Go.Go_utf8_decodeRuneInternal(_g._goroutine,[],_g.p_p);
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._t0 = _g._SF1.res();
			_g._t1 = _g._t0.r0;
			_g._t2 = _g._t0.r1;
			_g._res = { r0 : _g._t1, r1 : _g._t2};
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis.Go_utf8_DecodeRune
});
tardis._Go.Go_main_startGophers = function(gr,_bds) {
	this._t8 = null;
	this._t7 = null;
	tardis.StackFrameBasis.call(this,gr,41,"Go_main_startGophers");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_startGophers.__name__ = true;
tardis._Go.Go_main_startGophers.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_startGophers.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_startGophers.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			var _t0 = null;
			var _t1 = null;
			var _t2 = null;
			var _t3 = null;
			var _t4 = null;
			var _t5 = null;
			var _t6 = null;
			_t0 = new tardis.Channel(0);
			tardis.Go.main_bigpile.store(_t0);
			_t1 = new tardis.Channel(1);
			tardis.Go.main_smallpile.store(_t1);
			_t2 = new tardis.Channel(0);
			tardis.Go.main_oven.store(_t2);
			_t3 = tardis.Go.main_bigpile.load();
			_t4 = tardis.Go.main_smallpile.load();
			tardis._Go.Go_main_gopher.call(tardis.Scheduler.makeGoroutine(),[],tardis.Go.main_Sprite1X,tardis.Go.main_Sprite1Y,tardis.Go.main_Sprite1state,_t3,_t4);
			_t5 = tardis.Go.main_smallpile.load();
			_t6 = tardis.Go.main_oven.load();
			tardis._Go.Go_main_gopher.call(tardis.Scheduler.makeGoroutine(),[],tardis.Go.main_Sprite2X,tardis.Go.main_Sprite2Y,tardis.Go.main_Sprite2state,_t5,_t6);
			tardis._Go.Go_main_fire.call(tardis.Scheduler.makeGoroutine(),[]);
			_g._t7 = tardis.Go.main_bigpile.load();
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			if(!_g._t7.hasSpace()) return _g;
			_g._t7.send(1);
			_g._t8 = tardis.Go.main_smallpile.load();
			_g._Next = -2;
			return _g;
		};
		var _Block_2 = function() {
			if(!_g._t8.hasSpace()) return _g;
			_g._t8.send(10);
			tardis._Go.Go_main_fillbigpile.call(tardis.Scheduler.makeGoroutine(),[]);
			_g._incomplete = false;
			tardis.Scheduler.pop(_g._goroutine);
			return _g;
		};
		var retVal = null;
		while(retVal == null) {
			var _g1 = this._Next;
			switch(_g1) {
			case 0:
				retVal = _Block0();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_startGophers
});
tardis._Go.Go_main_fillbigpile = function(gr,_bds) {
	this._t14 = null;
	this._t7 = 0;
	this._t6 = null;
	this._t5 = null;
	this._t4 = null;
	this._t3 = null;
	this._t2 = null;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,57,"Go_main_fillbigpile");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
tardis._Go.Go_main_fillbigpile.__name__ = true;
tardis._Go.Go_main_fillbigpile.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_fillbigpile.call = function(gr,_bds) {
	return new tardis._Go.Go_main_fillbigpile(gr,_bds);
};
tardis._Go.Go_main_fillbigpile.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_fillbigpile.prototype = $extend(tardis.StackFrameBasis.prototype,{
	res: function() {
		return null;
	}
	,run: function() {
		var _g = this;
		var _Block0 = function() {
			_g._Next = 1;
			return null;
		};
		var _Block1 = function() {
			_g._t0 = tardis.Go.main_bigpile.load();
			_g._t1 = tardis.Go.main_bigpile.load();
			_g._t2 = tardis.Go.main_bigpile.load();
			_g._t3 = tardis.Go.main_bigpile.load();
			_g._t4 = tardis.Go.main_bigpile.load();
			_g._t5 = tardis.Go.main_bigpile.load();
			_g._Next = -1;
			return _g;
		};
		var _Block_1 = function() {
			_g._t6 = { r0 : 0, r1 : false};
			_g._t6.r0 = -1;
			var _states = new Array();
			var _rnd = Std.random(6);
			_states[0] = _g._t0.hasSpace();
			_states[1] = _g._t1.hasSpace();
			_states[2] = _g._t2.hasSpace();
			_states[3] = _g._t3.hasSpace();
			_states[4] = _g._t4.hasSpace();
			_states[5] = _g._t5.hasSpace();
			var _g1 = 0;
			while(_g1 < 6) {
				var _s = _g1++;
				var _i = (_s + _rnd) % 6;
				if(_states[_i]) {
					_g._t6.r0 = _i;
					break;
				}
			}
			var _g11 = _g._t6.r0;
			switch(_g11) {
			case 0:
				_g._t0.send(1);
				break;
			case 1:
				_g._t1.send(2);
				break;
			case 2:
				_g._t2.send(3);
				break;
			case 3:
				_g._t3.send(8);
				break;
			case 4:
				_g._t4.send(9);
				break;
			case 5:
				_g._t5.send(10);
				break;
			}
			if(_g._t6.r0 == -1) return _g;
			var _t8 = false;
			_g._t7 = _g._t6.r0;
			_t8 = _g._t7 == 0;
			if(_t8) _g._Next = 1; else _g._Next = 2;
			return null;
		};
		var _Block2 = function() {
			var _t9 = false;
			_t9 = _g._t7 == 1;
			if(_t9) _g._Next = 1; else _g._Next = 3;
			return null;
		};
		var _Block3 = function() {
			var _t10 = false;
			_t10 = _g._t7 == 2;
			if(_t10) _g._Next = 1; else _g._Next = 4;
			return null;
		};
		var _Block4 = function() {
			var _t11 = false;
			_t11 = _g._t7 == 3;
			if(_t11) _g._Next = 1; else _g._Next = 5;
			return null;
		};
		var _Block5 = function() {
			var _t12 = false;
			_t12 = _g._t7 == 4;
			if(_t12) _g._Next = 1; else _g._Next = 6;
			return null;
		};
		var _Block6 = function() {
			var _t13 = false;
			_t13 = _g._t7 == 5;
			if(_t13) _g._Next = 1; else _g._Next = 7;
			return null;
		};
		var _Block7 = function() {
			_g._t14 = new tardis.Interface(1,"blocking select matched no case");
			tardis.Scheduler.panic(_g._goroutine,_g._t14);
			_g._Next = -2;
			return _g;
		};
		var _Block_2 = function() {
			return null;
		};
		var retVal = null;
		while(retVal == null) {
			var _g2 = this._Next;
			switch(_g2) {
			case 0:
				retVal = _Block0();
				break;
			case 1:
				retVal = _Block1();
				break;
			case 2:
				retVal = _Block2();
				break;
			case 3:
				retVal = _Block3();
				break;
			case 4:
				retVal = _Block4();
				break;
			case 5:
				retVal = _Block5();
				break;
			case 6:
				retVal = _Block6();
				break;
			case 7:
				retVal = _Block7();
				break;
			case -1:
				retVal = _Block_1();
				break;
			case -2:
				retVal = _Block_2();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
		return retVal;
	}
	,__class__: tardis._Go.Go_main_fillbigpile
});
tardis.Go = $hx_exports.Go = function() { };
tardis.Go.__name__ = true;
tardis.Go.init = function() {
	tardis.Go.doneInit = true;
	var gr = tardis.Scheduler.makeGoroutine();
	if(gr != 0) throw "non-zero goroutine number in init";
	var _sfgr = new tardis._Go.Go_haxegoruntime_init(gr,[]).run();
	while(_sfgr._incomplete) tardis.Scheduler.runAll();
	var _sf = new tardis._Go.Go_main_init(gr,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	tardis.Scheduler.doneInit = true;
	tardis.Go.haxegoruntime_ZiLen.store_uint32("字".length);
};
tardis.Go.main = function() {
	tardis._Go.Go_main_main.callFromHaxe();
};
tardis.Go.CPos = function(pos) {
	var prefix = "";
	if(pos == 0) return "(pogo.NoPosHash)";
	if(pos < 0) {
		pos = -pos;
		prefix = "near ";
	}
	if(pos > 396700) return prefix + "/Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/tardisgolib.go:" + Std.string(pos - 396700); else if(pos > 1478) return prefix + "/Users/elliott/go/src/github.com/tardisgo/gohaxelib/_js/defs.go:" + Std.string(pos - 1478); else if(pos > 1234) return prefix + "/Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/tgoaddmath/math.go:" + Std.string(pos - 1234); else if(pos > 1207) return prefix + "/Users/elliott/go/src/github.com/tardisgo/tardisgo/golibruntime/golibruntime.go:" + Std.string(pos - 1207); else if(pos > 1092) return prefix + "/Users/elliott/go/src/github.com/tardisgo/tardisgo/tardisgolib/hx/hx.go:" + Std.string(pos - 1092); else if(pos > 647) return prefix + "/usr/local/go/src/unicode/utf8/utf8.go:" + Std.string(pos - 647); else if(pos > 539) return prefix + "/usr/local/go/src/unicode/utf16/utf16.go:" + Std.string(pos - 539); else if(pos > 383) return prefix + "/Users/elliott/go/src/github.com/tardisgo/tardisgo/haxe/haxegoruntime/haxegoruntime.go:" + Std.string(pos - 383); else if(pos > 0) return prefix + "gophers.go:" + (pos == null?"null":"" + pos); else return "(invalid pogo.PosHash:" + (pos == null?"null":"" + pos) + ")";
};
tardis.TypeInfo = function() { };
tardis.TypeInfo.__name__ = true;
tardis.TypeInfo.getName = function(id) {
	switch(id) {
	case 4:
		return "float64";
	case 5:
		return "func(e uintptr)";
	case 0:
		return "int";
	case 1:
		return "string";
	case 2:
		return "github.com/tardisgo/gohaxelib/_js.Sjs_html_Image";
	case 3:
		return "func()";
	default:
		return "UNKNOWN";
	}
};
tardis.TypeInfo.getId = function(name) {
	switch(name) {
	case "float64":
		return 4;
	case "func(e uintptr)":
		return 5;
	case "int":
		return 0;
	case "string":
		return 1;
	case "github.com/tardisgo/gohaxelib/_js.Sjs_html_Image":
		return 2;
	case "func()":
		return 3;
	default:
		return -1;
	}
};
Math.NaN = Number.NaN;
Math.NEGATIVE_INFINITY = Number.NEGATIVE_INFINITY;
Math.POSITIVE_INFINITY = Number.POSITIVE_INFINITY;
Math.isFinite = function(i) {
	return isFinite(i);
};
Math.isNaN = function(i1) {
	return isNaN(i1);
};
String.prototype.__class__ = String;
String.__name__ = true;
Array.__name__ = true;
Date.prototype.__class__ = Date;
Date.__name__ = ["Date"];
var Int = { __name__ : ["Int"]};
var Dynamic = { __name__ : ["Dynamic"]};
var Float = Number;
Float.__name__ = ["Float"];
var Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = { __name__ : ["Class"]};
var Enum = { };
tardis.Scheduler.doneInit = false;
tardis.Scheduler.grStacks = new Array();
tardis.Scheduler.grInPanic = new Array();
tardis.Scheduler.grPanicMsg = new Array();
tardis.Scheduler.panicStackDump = "";
tardis.Scheduler.entryCount = 0;
tardis.Scheduler.currentGR = 0;
tardis.Scheduler.runLimit = 0;
tardis.Go.utf8_init_36_guard = new tardis.Pointer(new tardis.Object(1));
tardis.Go.golibruntime_init_36_guard = new tardis.Pointer(new tardis.Object(1));
tardis.Go.tgoaddmath_init_36_guard = new tardis.Pointer(new tardis.Object(1));
tardis.Go.haxegoruntime_init_36_guard = new tardis.Pointer(new tardis.Object(1));
tardis.Go.haxegoruntime_ZiLen = new tardis.Pointer(new tardis.Object(4));
tardis.Go.tardisgolib_gosched_chan = new tardis.Pointer(new tardis.Object(4));
tardis.Go.tardisgolib_init_36_guard = new tardis.Pointer(new tardis.Object(1));
tardis.Go.utf16_init_36_guard = new tardis.Pointer(new tardis.Object(1));
tardis.Go.main_Sprite1state = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_Sprite1Y = new tardis.Pointer(new tardis.Object(8));
tardis.Go.main_spChan = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_emptyPilePng = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_timer = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_smallpile = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_s2state = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_init_36_guard = new tardis.Pointer(new tardis.Object(1));
tardis.Go.main_Books = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_pickPng1 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_showingBooks = new tardis.Pointer(new tardis.Object(1));
tardis.Go.main_Sprite1X = new tardis.Pointer(new tardis.Object(8));
tardis.Go.main_context = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_bigpile = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_white = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_Sprite2Y = new tardis.Pointer(new tardis.Object(8));
tardis.Go.main_emptyPng1 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_shovelPng1 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_WT = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_smallPilePng = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_oven = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_doc = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_L1 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_lastTime = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_headlineTimer = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_Sprite2 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_fullPng1 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_shovelPng2 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_L2 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_s1state = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_Sprite2state = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_Logo2 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_pickPng2 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_emptyPng2 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_fullPng2 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_Sprite2X = new tardis.Pointer(new tardis.Object(8));
tardis.Go.main_Sprite1 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_Logo1 = new tardis.Pointer(new tardis.Object(4));
tardis.Go.main_lastHeading = new tardis.Pointer(new tardis.Object(8));
tardis.Go.doneInit = false;
tardis.Go.main();
})(typeof window != "undefined" ? window : exports);
