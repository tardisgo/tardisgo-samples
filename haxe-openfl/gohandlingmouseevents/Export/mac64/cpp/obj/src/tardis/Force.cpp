#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_tardis_Force
#include <tardis/Force.h>
#endif
#ifndef INCLUDED_tardis_Go_haxegoruntime_RunesToUTF16
#include <tardis/Go_haxegoruntime_RunesToUTF16.h>
#endif
#ifndef INCLUDED_tardis_Go_haxegoruntime_RunesToUTF8
#include <tardis/Go_haxegoruntime_RunesToUTF8.h>
#endif
#ifndef INCLUDED_tardis_Go_haxegoruntime_UTF16toRunes
#include <tardis/Go_haxegoruntime_UTF16toRunes.h>
#endif
#ifndef INCLUDED_tardis_Go_haxegoruntime_UTF8toRunes
#include <tardis/Go_haxegoruntime_UTF8toRunes.h>
#endif
#ifndef INCLUDED_tardis_Int64
#include <tardis/Int64.h>
#endif
#ifndef INCLUDED_tardis_Interface
#include <tardis/Interface.h>
#endif
#ifndef INCLUDED_tardis_Pointer
#include <tardis/Pointer.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
#ifndef INCLUDED_tardis_Slice
#include <tardis/Slice.h>
#endif
#ifndef INCLUDED_tardis_StackFrame
#include <tardis/StackFrame.h>
#endif
#ifndef INCLUDED_tardis_StackFrameBasis
#include <tardis/StackFrameBasis.h>
#endif
namespace tardis{

Void Force_obj::__construct()
{
	return null();
}

Force_obj::~Force_obj() { }

Dynamic Force_obj::__CreateEmpty() { return  new Force_obj; }
hx::ObjectPtr< Force_obj > Force_obj::__new()
{  hx::ObjectPtr< Force_obj > result = new Force_obj();
	result->__construct();
	return result;}

Dynamic Force_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Force_obj > result = new Force_obj();
	result->__construct();
	return result;}

int Force_obj::toUint8( int v){
	HX_STACK_PUSH("Force::toUint8","tardis/Go.hx",101);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(101)
	return (int(v) & int((int)255));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Force_obj,toUint8,return )

int Force_obj::toUint16( int v){
	HX_STACK_PUSH("Force::toUint16","tardis/Go.hx",104);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(104)
	return (int(v) & int((int)65535));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Force_obj,toUint16,return )

int Force_obj::toUint32( int v){
	HX_STACK_PUSH("Force::toUint32","tardis/Go.hx",107);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(107)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Force_obj,toUint32,return )

::tardis::Int64 Force_obj::toUint64( ::tardis::Int64 v){
	HX_STACK_PUSH("Force::toUint64","tardis/Go.hx",117);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(117)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Force_obj,toUint64,return )

int Force_obj::toInt8( int v){
	HX_STACK_PUSH("Force::toInt8","tardis/Go.hx",120);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(121)
	int r = (int(v) & int((int)255));		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(122)
	if (((((int(r) & int((int)128))) != (int)0))){
		HX_STACK_LINE(122)
		return ((int)-256 + r);
	}
	HX_STACK_LINE(125)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Force_obj,toInt8,return )

int Force_obj::toInt16( int v){
	HX_STACK_PUSH("Force::toInt16","tardis/Go.hx",127);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(128)
	int r = (int(v) & int((int)65535));		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(129)
	if (((((int(r) & int((int)32768))) != (int)0))){
		HX_STACK_LINE(129)
		return ((int)-65536 + r);
	}
	HX_STACK_LINE(132)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Force_obj,toInt16,return )

int Force_obj::toInt32( int v){
	HX_STACK_PUSH("Force::toInt32","tardis/Go.hx",134);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(134)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Force_obj,toInt32,return )

::tardis::Int64 Force_obj::toInt64( ::tardis::Int64 v){
	HX_STACK_PUSH("Force::toInt64","tardis/Go.hx",152);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(152)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Force_obj,toInt64,return )

int Force_obj::toInt( Dynamic v){
	HX_STACK_PUSH("Force::toInt","tardis/Go.hx",155);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(155)
	if ((!(::Reflect_obj::isObject(v)))){
		HX_STACK_LINE(157)
		return v;
	}
	else{
		HX_STACK_LINE(159)
		if ((::Std_obj::is(v,hx::ClassOf< ::tardis::Interface >()))){
			HX_STACK_LINE(160)
			v = v->__Field(HX_CSTRING("val"),true);
			HX_STACK_LINE(161)
			if ((!(::Reflect_obj::isObject(v)))){
				HX_STACK_LINE(162)
				return v;
			}
			else{
				struct _Function_4_1{
					inline static int Block( Dynamic &v){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",164);
						{
							HX_STACK_LINE(164)
							::tardis::Int64 v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(164)
							return ::tardis::Int64_obj::getLow(v1);
						}
						return null();
					}
				};
				HX_STACK_LINE(164)
				return _Function_4_1::Block(v);
			}
		}
		else{
			struct _Function_3_1{
				inline static int Block( Dynamic &v){
					HX_STACK_PUSH("*::closure","tardis/Go.hx",166);
					{
						HX_STACK_LINE(166)
						::tardis::Int64 v1 = v;		HX_STACK_VAR(v1,"v1");
						HX_STACK_LINE(166)
						return ::tardis::Int64_obj::getLow(v1);
					}
					return null();
				}
			};
			HX_STACK_LINE(166)
			return _Function_3_1::Block(v);
		}
	}
	HX_STACK_LINE(155)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Force_obj,toInt,return )

Float Force_obj::toFloat( Float v){
	HX_STACK_PUSH("Force::toFloat","tardis/Go.hx",168);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(168)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Force_obj,toFloat,return )

int Force_obj::uintCompare( int x,int y){
	HX_STACK_PUSH("Force::uintCompare","tardis/Go.hx",180);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(181)
	if (((x == y))){
		HX_STACK_LINE(181)
		return (int)0;
	}
	HX_STACK_LINE(182)
	if (((x >= (int)0))){
		HX_STACK_LINE(182)
		if (((y >= (int)0))){
			HX_STACK_LINE(183)
			return (x - y);
		}
		else{
			HX_STACK_LINE(185)
			return (int)-1;
		}
	}
	else{
		HX_STACK_LINE(188)
		if (((y >= (int)0))){
			HX_STACK_LINE(189)
			return (int)1;
		}
		else{
			HX_STACK_LINE(191)
			return (x - y);
		}
	}
	HX_STACK_LINE(182)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Force_obj,uintCompare,return )

int Force_obj::checkIntDiv( int x,int y,int byts){
	HX_STACK_PUSH("Force::checkIntDiv","tardis/Go.hx",196);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(byts,"byts");
	HX_STACK_LINE(197)
	int r = y;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(198)
	switch( (int)(y)){
		case (int)0: {
			HX_STACK_LINE(199)
			::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("attempt to divide integer value by 0"));
		}
		;break;
		case (int)-1: {
			HX_STACK_LINE(201)
			switch( (int)(byts)){
				case (int)1: {
					HX_STACK_LINE(203)
					if (((x == (int)-128))){
						HX_STACK_LINE(204)
						r = (int)1;
					}
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(205)
					if (((x == (int)-32768))){
						HX_STACK_LINE(206)
						r = (int)1;
					}
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(207)
					if (((x == (int)-2147483648))){
						HX_STACK_LINE(208)
						r = (int)1;
					}
				}
				;break;
				default: {
				}
			}
		}
		;break;
	}
	HX_STACK_LINE(213)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Force_obj,checkIntDiv,return )

int Force_obj::intDiv( int x,int y,int sv){
	HX_STACK_PUSH("Force::intDiv","tardis/Go.hx",216);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(sv,"sv");
	HX_STACK_LINE(217)
	y = ::tardis::Force_obj::checkIntDiv(x,y,sv);
	HX_STACK_LINE(218)
	if (((y == (int)1))){
		HX_STACK_LINE(218)
		return x;
	}
	HX_STACK_LINE(219)
	Float f = (Float(x) / Float(y));		HX_STACK_VAR(f,"f");
	HX_STACK_LINE(220)
	return (  (((f >= (int)0))) ? int(::Math_obj::floor(f)) : int(::Math_obj::ceil(f)) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Force_obj,intDiv,return )

int Force_obj::intMod( int x,int y,int sv){
	HX_STACK_PUSH("Force::intMod","tardis/Go.hx",222);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(sv,"sv");
	HX_STACK_LINE(223)
	y = ::tardis::Force_obj::checkIntDiv(x,y,sv);
	HX_STACK_LINE(224)
	if (((y == (int)1))){
		HX_STACK_LINE(224)
		return (int)0;
	}
	HX_STACK_LINE(225)
	return hx::Mod(x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Force_obj,intMod,return )

Float Force_obj::floatDiv( Float x,Float y){
	HX_STACK_PUSH("Force::floatDiv","tardis/Go.hx",227);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(228)
	if (((y == 0.0))){
		HX_STACK_LINE(229)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("attempt to divide float value by 0"));
	}
	HX_STACK_LINE(230)
	return (Float(x) / Float(y));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Force_obj,floatDiv,return )

Float Force_obj::floatMod( Float x,Float y){
	HX_STACK_PUSH("Force::floatMod","tardis/Go.hx",232);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(233)
	if (((y == 0.0))){
		HX_STACK_LINE(234)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("attempt to modulo float value by 0"));
	}
	HX_STACK_LINE(235)
	return hx::Mod(x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Force_obj,floatMod,return )

int Force_obj::toUTF8length( int gr,::String s){
	HX_STACK_PUSH("Force::toUTF8length","tardis/Go.hx",238);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(s,"s");
	struct _Function_1_1{
		inline static int Block( ::String &s,int &gr){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",239);
			{
				HX_STACK_LINE(239)
				::tardis::Slice _this = ::tardis::Force_obj::toUTF8slice(gr,s);		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(239)
				return (_this->end - _this->start);
			}
			return null();
		}
	};
	HX_STACK_LINE(238)
	return (  (((HX_CSTRING("\xe5""\xad""\x97""").length == (int)3))) ? int(s.length) : int(_Function_1_1::Block(s,gr)) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Force_obj,toUTF8length,return )

::tardis::Slice Force_obj::toUTF8slice( int gr,::String s){
	HX_STACK_PUSH("Force::toUTF8slice","tardis/Go.hx",242);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(243)
	Array< int > a = Array_obj< int >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(244)
	int mask = (int)255;		HX_STACK_VAR(mask,"mask");
	HX_STACK_LINE(245)
	if (((HX_CSTRING("\xe5""\xad""\x97""").length == (int)1))){
		HX_STACK_LINE(245)
		mask = (int)65535;
	}
	HX_STACK_LINE(248)
	{
		HX_STACK_LINE(248)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = s.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(248)
		while(((_g1 < _g))){
			HX_STACK_LINE(248)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(249)
			Dynamic t = s.charCodeAt(i);		HX_STACK_VAR(t,"t");
			HX_STACK_LINE(250)
			if (((t == null()))){
				HX_STACK_LINE(251)
				::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("Haxe runtime Force.toUTF8slice() unexpected null encountered"));
			}
			else{
				HX_STACK_LINE(253)
				a[i] = (int(hx::TCast< Int >::cast(t)) & int(mask));
			}
		}
	}
	HX_STACK_LINE(255)
	::tardis::Slice sl = ::tardis::Slice_obj::__new(::tardis::Pointer_obj::__new(a),(int)0,(int)-1);		HX_STACK_VAR(sl,"sl");
	HX_STACK_LINE(256)
	if (((HX_CSTRING("\xe5""\xad""\x97""").length == (int)3))){
		HX_STACK_LINE(256)
		return sl;
	}
	struct _Function_1_1{
		inline static ::tardis::Slice Block( ::tardis::Slice &sl,int &gr){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",257);
			{
				HX_STACK_LINE(257)
				::tardis::Go_haxegoruntime_UTF16toRunes _sf = hx::TCast< ::tardis::Go_haxegoruntime_UTF16toRunes >::cast(::tardis::Go_haxegoruntime_UTF16toRunes_obj::__new(gr,Dynamic( Array_obj<Dynamic>::__new()),sl)->run());		HX_STACK_VAR(_sf,"_sf");
				HX_STACK_LINE(257)
				while((_sf->_incomplete)){
					HX_STACK_LINE(257)
					if (((::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first() == null()))){
						HX_STACK_LINE(257)
						hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
					}
					else{
						HX_STACK_LINE(257)
						::tardis::Scheduler_obj::currentGR = gr;
						HX_STACK_LINE(257)
						::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
					}
				}
				HX_STACK_LINE(257)
				return _sf->_res;
			}
			return null();
		}
	};
	HX_STACK_LINE(257)
	::tardis::Slice v1 = _Function_1_1::Block(sl,gr);		HX_STACK_VAR(v1,"v1");
	struct _Function_1_2{
		inline static ::tardis::Slice Block( int &gr,::tardis::Slice &v1){
			HX_STACK_PUSH("*::closure","tardis/Go.hx",258);
			{
				HX_STACK_LINE(258)
				::tardis::Go_haxegoruntime_RunesToUTF8 _sf = hx::TCast< ::tardis::Go_haxegoruntime_RunesToUTF8 >::cast(::tardis::Go_haxegoruntime_RunesToUTF8_obj::__new(gr,Dynamic( Array_obj<Dynamic>::__new()),v1)->run());		HX_STACK_VAR(_sf,"_sf");
				HX_STACK_LINE(258)
				while((_sf->_incomplete)){
					HX_STACK_LINE(258)
					if (((::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first() == null()))){
						HX_STACK_LINE(258)
						hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
					}
					else{
						HX_STACK_LINE(258)
						::tardis::Scheduler_obj::currentGR = gr;
						HX_STACK_LINE(258)
						::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
					}
				}
				HX_STACK_LINE(258)
				return _sf->_res;
			}
			return null();
		}
	};
	HX_STACK_LINE(258)
	return _Function_1_2::Block(gr,v1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Force_obj,toUTF8slice,return )

::String Force_obj::toRawString( int gr,::tardis::Slice sl){
	HX_STACK_PUSH("Force::toRawString","tardis/Go.hx",260);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(sl,"sl");
	HX_STACK_LINE(261)
	::String ret = HX_CSTRING("");		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(262)
	int mask = (int)255;		HX_STACK_VAR(mask,"mask");
	HX_STACK_LINE(263)
	if (((HX_CSTRING("\xe5""\xad""\x97""").length == (int)1))){
		struct _Function_2_1{
			inline static ::tardis::Slice Block( ::tardis::Slice &sl,int &gr){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",264);
				{
					HX_STACK_LINE(264)
					::tardis::Go_haxegoruntime_UTF8toRunes _sf = hx::TCast< ::tardis::Go_haxegoruntime_UTF8toRunes >::cast(::tardis::Go_haxegoruntime_UTF8toRunes_obj::__new(gr,Dynamic( Array_obj<Dynamic>::__new()),sl)->run());		HX_STACK_VAR(_sf,"_sf");
					HX_STACK_LINE(264)
					while((_sf->_incomplete)){
						HX_STACK_LINE(264)
						if (((::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first() == null()))){
							HX_STACK_LINE(264)
							hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
						}
						else{
							HX_STACK_LINE(264)
							::tardis::Scheduler_obj::currentGR = gr;
							HX_STACK_LINE(264)
							::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
						}
					}
					HX_STACK_LINE(264)
					return _sf->_res;
				}
				return null();
			}
		};
		HX_STACK_LINE(264)
		::tardis::Slice v1 = _Function_2_1::Block(sl,gr);		HX_STACK_VAR(v1,"v1");
		struct _Function_2_2{
			inline static ::tardis::Slice Block( int &gr,::tardis::Slice &v1){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",265);
				{
					HX_STACK_LINE(265)
					::tardis::Go_haxegoruntime_RunesToUTF16 _sf = hx::TCast< ::tardis::Go_haxegoruntime_RunesToUTF16 >::cast(::tardis::Go_haxegoruntime_RunesToUTF16_obj::__new(gr,Dynamic( Array_obj<Dynamic>::__new()),v1)->run());		HX_STACK_VAR(_sf,"_sf");
					HX_STACK_LINE(265)
					while((_sf->_incomplete)){
						HX_STACK_LINE(265)
						if (((::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first() == null()))){
							HX_STACK_LINE(265)
							hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
						}
						else{
							HX_STACK_LINE(265)
							::tardis::Scheduler_obj::currentGR = gr;
							HX_STACK_LINE(265)
							::tardis::Scheduler_obj::grStacks->__get(gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
						}
					}
					HX_STACK_LINE(265)
					return _sf->_res;
				}
				return null();
			}
		};
		HX_STACK_LINE(265)
		sl = _Function_2_2::Block(gr,v1);
		HX_STACK_LINE(266)
		mask = (int)65535;
	}
	HX_STACK_LINE(268)
	{
		HX_STACK_LINE(268)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = (sl->end - sl->start);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(268)
		while(((_g1 < _g))){
			HX_STACK_LINE(268)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(269)
			hx::AddEq(ret,::String::fromCharCode((int(sl->getAt(i)) & int(mask))));
		}
	}
	HX_STACK_LINE(271)
	return ret;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Force_obj,toRawString,return )


Force_obj::Force_obj()
{
}

void Force_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Force);
	HX_MARK_END_CLASS();
}

void Force_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Force_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"toInt") ) { return toInt_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"toInt8") ) { return toInt8_dyn(); }
		if (HX_FIELD_EQ(inName,"intDiv") ) { return intDiv_dyn(); }
		if (HX_FIELD_EQ(inName,"intMod") ) { return intMod_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"toUint8") ) { return toUint8_dyn(); }
		if (HX_FIELD_EQ(inName,"toInt16") ) { return toInt16_dyn(); }
		if (HX_FIELD_EQ(inName,"toInt32") ) { return toInt32_dyn(); }
		if (HX_FIELD_EQ(inName,"toInt64") ) { return toInt64_dyn(); }
		if (HX_FIELD_EQ(inName,"toFloat") ) { return toFloat_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toUint16") ) { return toUint16_dyn(); }
		if (HX_FIELD_EQ(inName,"toUint32") ) { return toUint32_dyn(); }
		if (HX_FIELD_EQ(inName,"toUint64") ) { return toUint64_dyn(); }
		if (HX_FIELD_EQ(inName,"floatDiv") ) { return floatDiv_dyn(); }
		if (HX_FIELD_EQ(inName,"floatMod") ) { return floatMod_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"uintCompare") ) { return uintCompare_dyn(); }
		if (HX_FIELD_EQ(inName,"checkIntDiv") ) { return checkIntDiv_dyn(); }
		if (HX_FIELD_EQ(inName,"toUTF8slice") ) { return toUTF8slice_dyn(); }
		if (HX_FIELD_EQ(inName,"toRawString") ) { return toRawString_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"toUTF8length") ) { return toUTF8length_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Force_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Force_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("toUint8"),
	HX_CSTRING("toUint16"),
	HX_CSTRING("toUint32"),
	HX_CSTRING("toUint64"),
	HX_CSTRING("toInt8"),
	HX_CSTRING("toInt16"),
	HX_CSTRING("toInt32"),
	HX_CSTRING("toInt64"),
	HX_CSTRING("toInt"),
	HX_CSTRING("toFloat"),
	HX_CSTRING("uintCompare"),
	HX_CSTRING("checkIntDiv"),
	HX_CSTRING("intDiv"),
	HX_CSTRING("intMod"),
	HX_CSTRING("floatDiv"),
	HX_CSTRING("floatMod"),
	HX_CSTRING("toUTF8length"),
	HX_CSTRING("toUTF8slice"),
	HX_CSTRING("toRawString"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Force_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Force_obj::__mClass,"__mClass");
};

Class Force_obj::__mClass;

void Force_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Force"), hx::TCanCast< Force_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Force_obj::__boot()
{
}

} // end namespace tardis
