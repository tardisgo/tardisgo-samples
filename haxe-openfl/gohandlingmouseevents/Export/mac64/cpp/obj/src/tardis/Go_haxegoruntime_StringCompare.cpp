#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_tardis_Force
#include <tardis/Force.h>
#endif
#ifndef INCLUDED_tardis_Go
#include <tardis/Go.h>
#endif
#ifndef INCLUDED_tardis_Go_haxegoruntime_StringCompare
#include <tardis/Go_haxegoruntime_StringCompare.h>
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

Void Go_haxegoruntime_StringCompare_obj::__construct(int gr,Dynamic _bds,::String p_a,::String p_b)
{
HX_STACK_PUSH("Go_haxegoruntime_StringCompare::new","tardis/Go.hx",5300);
{
	HX_STACK_LINE(5337)
	this->_Next = (int)0;
	HX_STACK_LINE(5336)
	this->_Phi = (int)0;
	HX_STACK_LINE(5335)
	this->_t23 = false;
	HX_STACK_LINE(5334)
	this->_t22 = (int)0;
	HX_STACK_LINE(5333)
	this->_t21 = (int)0;
	HX_STACK_LINE(5332)
	this->_t20 = (int)0;
	HX_STACK_LINE(5331)
	this->_t19 = false;
	HX_STACK_LINE(5330)
	this->_t18 = (int)0;
	HX_STACK_LINE(5329)
	this->_t17 = null();
	HX_STACK_LINE(5328)
	this->_t16 = (int)0;
	HX_STACK_LINE(5327)
	this->_t15 = null();
	HX_STACK_LINE(5326)
	this->_t14 = false;
	HX_STACK_LINE(5325)
	this->_t13 = (int)0;
	HX_STACK_LINE(5324)
	this->_t12 = false;
	HX_STACK_LINE(5323)
	this->_t11 = (int)0;
	HX_STACK_LINE(5322)
	this->_t10 = (int)0;
	HX_STACK_LINE(5321)
	this->_t9 = false;
	HX_STACK_LINE(5320)
	this->_t8 = (int)0;
	HX_STACK_LINE(5319)
	this->_t7 = (int)0;
	HX_STACK_LINE(5318)
	this->_t6 = false;
	HX_STACK_LINE(5317)
	this->_t5 = (int)0;
	HX_STACK_LINE(5316)
	this->_t4 = null();
	HX_STACK_LINE(5315)
	this->_t3 = (int)0;
	HX_STACK_LINE(5314)
	this->_t2 = null();
	HX_STACK_LINE(5313)
	this->_t1 = null();
	HX_STACK_LINE(5312)
	this->_t0 = null();
	HX_STACK_LINE(5304)
	super::__construct(gr,(int)151,HX_CSTRING("Go_haxegoruntime_StringCompare"));
	HX_STACK_LINE(5305)
	this->_bds = _bds;
	HX_STACK_LINE(5306)
	this->p_a = p_a;
	HX_STACK_LINE(5307)
	this->p_b = p_b;
	HX_STACK_LINE(5308)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_StringCompare_obj::~Go_haxegoruntime_StringCompare_obj() { }

Dynamic Go_haxegoruntime_StringCompare_obj::__CreateEmpty() { return  new Go_haxegoruntime_StringCompare_obj; }
hx::ObjectPtr< Go_haxegoruntime_StringCompare_obj > Go_haxegoruntime_StringCompare_obj::__new(int gr,Dynamic _bds,::String p_a,::String p_b)
{  hx::ObjectPtr< Go_haxegoruntime_StringCompare_obj > result = new Go_haxegoruntime_StringCompare_obj();
	result->__construct(gr,_bds,p_a,p_b);
	return result;}

Dynamic Go_haxegoruntime_StringCompare_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_StringCompare_obj > result = new Go_haxegoruntime_StringCompare_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *Go_haxegoruntime_StringCompare_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_StringCompare_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_StringCompare::SubFn7","tardis/Go.hx",5498);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5499)
		int _t21;		HX_STACK_VAR(_t21,"_t21");
		HX_STACK_LINE(5500)
		int _t22;		HX_STACK_VAR(_t22,"_t22");
		HX_STACK_LINE(5501)
		bool _t23;		HX_STACK_VAR(_t23,"_t23");
		HX_STACK_LINE(5502)
		this->_latestPH = (int)168;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",5503);
				{
					HX_STACK_LINE(5503)
					::tardis::Slice _v = __this->_t0;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(5503)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(5503)
		_t21 = _Function_1_1::Block(this);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",5504);
				{
					HX_STACK_LINE(5504)
					::tardis::Slice _v = __this->_t1;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(5504)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(5504)
		_t22 = _Function_1_2::Block(this);
		HX_STACK_LINE(5505)
		_t23 = (_t21 < _t22);
		HX_STACK_LINE(5506)
		this->_Next = (  ((_t23)) ? int((int)11) : int((int)12) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_StringCompare_obj,SubFn7,(void))

Void Go_haxegoruntime_StringCompare_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_StringCompare::SubFn6","tardis/Go.hx",5494);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5495)
		this->_t20 = (this->_t10 + (int)1);
		HX_STACK_LINE(5496)
		this->_Next = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_StringCompare_obj,SubFn6,(void))

Void Go_haxegoruntime_StringCompare_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_StringCompare::SubFn5","tardis/Go.hx",5478);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5479)
		::tardis::Pointer _t15;		HX_STACK_VAR(_t15,"_t15");
		HX_STACK_LINE(5480)
		int _t16;		HX_STACK_VAR(_t16,"_t16");
		HX_STACK_LINE(5481)
		::tardis::Pointer _t17;		HX_STACK_VAR(_t17,"_t17");
		HX_STACK_LINE(5482)
		int _t18;		HX_STACK_VAR(_t18,"_t18");
		HX_STACK_LINE(5483)
		bool _t19;		HX_STACK_VAR(_t19,"_t19");
		HX_STACK_LINE(5484)
		this->_latestPH = (int)160;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",5485);
				{
					HX_STACK_LINE(5485)
					::tardis::Slice _this = __this->_t0;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(5485)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(5485)
		if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(5485)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(5486)
		_t15 = this->_t0->addr(this->_t10);
		HX_STACK_LINE(5487)
		_t16 = (int(_t15->ref()) | int((int)0));
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",5488);
				{
					HX_STACK_LINE(5488)
					::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(5488)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(5488)
		if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_1_2::Block(this)))))){
			HX_STACK_LINE(5488)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(5489)
		_t17 = this->_t1->addr(this->_t10);
		HX_STACK_LINE(5490)
		_t18 = (int(_t17->ref()) | int((int)0));
		HX_STACK_LINE(5491)
		_t19 = (::tardis::Force_obj::uintCompare(_t16,_t18) > (int)0);
		HX_STACK_LINE(5492)
		this->_Next = (  ((_t19)) ? int((int)7) : int((int)8) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_StringCompare_obj,SubFn5,(void))

Void Go_haxegoruntime_StringCompare_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_StringCompare::SubFn4","tardis/Go.hx",5471);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5472)
		int _t13;		HX_STACK_VAR(_t13,"_t13");
		HX_STACK_LINE(5473)
		bool _t14;		HX_STACK_VAR(_t14,"_t14");
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",5474);
				{
					HX_STACK_LINE(5474)
					::tardis::Slice _v = __this->_t1;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(5474)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(5474)
		_t13 = _Function_1_1::Block(this);
		HX_STACK_LINE(5475)
		_t14 = (this->_t10 < _t13);
		HX_STACK_LINE(5476)
		this->_Next = (  ((_t14)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_StringCompare_obj,SubFn4,(void))

Void Go_haxegoruntime_StringCompare_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_StringCompare::SubFn3","tardis/Go.hx",5463);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5464)
		int _t11;		HX_STACK_VAR(_t11,"_t11");
		HX_STACK_LINE(5465)
		bool _t12;		HX_STACK_VAR(_t12,"_t12");
		HX_STACK_LINE(5466)
		this->_latestPH = (int)156;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",5467);
				{
					HX_STACK_LINE(5467)
					::tardis::Slice _v = __this->_t0;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(5467)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(5467)
		_t11 = _Function_1_1::Block(this);
		HX_STACK_LINE(5468)
		_t12 = (this->_t10 < _t11);
		HX_STACK_LINE(5469)
		this->_Next = (  ((_t12)) ? int((int)4) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_StringCompare_obj,SubFn3,(void))

Void Go_haxegoruntime_StringCompare_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_StringCompare::SubFn2","tardis/Go.hx",5453);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5454)
		int _t7;		HX_STACK_VAR(_t7,"_t7");
		HX_STACK_LINE(5455)
		int _t8;		HX_STACK_VAR(_t8,"_t8");
		HX_STACK_LINE(5456)
		bool _t9;		HX_STACK_VAR(_t9,"_t9");
		HX_STACK_LINE(5457)
		this->_latestPH = (int)165;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",5458);
				{
					HX_STACK_LINE(5458)
					::tardis::Slice _v = __this->_t0;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(5458)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(5458)
		_t7 = _Function_1_1::Block(this);
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",5459);
				{
					HX_STACK_LINE(5459)
					::tardis::Slice _v = __this->_t1;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(5459)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(5459)
		_t8 = _Function_1_2::Block(this);
		HX_STACK_LINE(5460)
		_t9 = (_t7 == _t8);
		HX_STACK_LINE(5461)
		this->_Next = (  ((_t9)) ? int((int)9) : int((int)10) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_StringCompare_obj,SubFn2,(void))

Void Go_haxegoruntime_StringCompare_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_StringCompare::SubFn1","tardis/Go.hx",5437);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5438)
		::tardis::Pointer _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(5439)
		int _t3;		HX_STACK_VAR(_t3,"_t3");
		HX_STACK_LINE(5440)
		::tardis::Pointer _t4;		HX_STACK_VAR(_t4,"_t4");
		HX_STACK_LINE(5441)
		int _t5;		HX_STACK_VAR(_t5,"_t5");
		HX_STACK_LINE(5442)
		bool _t6;		HX_STACK_VAR(_t6,"_t6");
		HX_STACK_LINE(5443)
		this->_latestPH = (int)157;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",5444);
				{
					HX_STACK_LINE(5444)
					::tardis::Slice _this = __this->_t0;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(5444)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(5444)
		if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(5444)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(5445)
		_t2 = this->_t0->addr(this->_t10);
		HX_STACK_LINE(5446)
		_t3 = (int(_t2->ref()) | int((int)0));
		struct _Function_1_2{
			inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",5447);
				{
					HX_STACK_LINE(5447)
					::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(5447)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(5447)
		if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_1_2::Block(this)))))){
			HX_STACK_LINE(5447)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(5448)
		_t4 = this->_t1->addr(this->_t10);
		HX_STACK_LINE(5449)
		_t5 = (int(_t4->ref()) | int((int)0));
		HX_STACK_LINE(5450)
		_t6 = (::tardis::Force_obj::uintCompare(_t3,_t5) < (int)0);
		HX_STACK_LINE(5451)
		this->_Next = (  ((_t6)) ? int((int)5) : int((int)6) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_StringCompare_obj,SubFn1,(void))

Void Go_haxegoruntime_StringCompare_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_StringCompare::SubFn0","tardis/Go.hx",5430);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5431)
		this->_latestPH = (int)153;
		HX_STACK_LINE(5432)
		this->_t0 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_a);
		HX_STACK_LINE(5433)
		this->_latestPH = (int)154;
		HX_STACK_LINE(5434)
		this->_t1 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_b);
		HX_STACK_LINE(5435)
		this->_Next = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_StringCompare_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_StringCompare_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_StringCompare::run","tardis/Go.hx",5352);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5352)
	while((true)){
		HX_STACK_LINE(5354)
		::tardis::Go_haxegoruntime_StringCompare _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5354)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5356)
				{
					HX_STACK_LINE(5356)
					this->_latestPH = (int)151;
					HX_STACK_LINE(5356)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5357)
				{
					HX_STACK_LINE(5357)
					this->_latestPH = (int)153;
					HX_STACK_LINE(5357)
					this->_t0 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_a);
					HX_STACK_LINE(5357)
					this->_latestPH = (int)154;
					HX_STACK_LINE(5357)
					this->_t1 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_b);
					HX_STACK_LINE(5357)
					this->_Next = (int)3;
				}
				HX_STACK_LINE(5358)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(5360)
				{
					HX_STACK_LINE(5360)
					this->_latestPH = (int)151;
					HX_STACK_LINE(5360)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(5361)
				{
					HX_STACK_LINE(5361)
					::tardis::Pointer _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(5361)
					int _t3;		HX_STACK_VAR(_t3,"_t3");
					HX_STACK_LINE(5361)
					::tardis::Pointer _t4;		HX_STACK_VAR(_t4,"_t4");
					HX_STACK_LINE(5361)
					int _t5;		HX_STACK_VAR(_t5,"_t5");
					HX_STACK_LINE(5361)
					bool _t6;		HX_STACK_VAR(_t6,"_t6");
					HX_STACK_LINE(5361)
					this->_latestPH = (int)157;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",5361);
							{
								HX_STACK_LINE(5361)
								::tardis::Slice _this = __this->_t0;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(5361)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(5361)
					if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(5361)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(5361)
					_t2 = this->_t0->addr(this->_t10);
					HX_STACK_LINE(5361)
					_t3 = (int(_t2->ref()) | int((int)0));
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",5361);
							{
								HX_STACK_LINE(5361)
								::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(5361)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(5361)
					if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_4_2::Block(this)))))){
						HX_STACK_LINE(5361)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(5361)
					_t4 = this->_t1->addr(this->_t10);
					HX_STACK_LINE(5361)
					_t5 = (int(_t4->ref()) | int((int)0));
					HX_STACK_LINE(5361)
					_t6 = (::tardis::Force_obj::uintCompare(_t3,_t5) < (int)0);
					HX_STACK_LINE(5361)
					this->_Next = (  ((_t6)) ? int((int)5) : int((int)6) );
				}
				HX_STACK_LINE(5362)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(5364)
				{
					HX_STACK_LINE(5364)
					this->_latestPH = (int)151;
					HX_STACK_LINE(5364)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(5365)
				{
					HX_STACK_LINE(5365)
					int _t7;		HX_STACK_VAR(_t7,"_t7");
					HX_STACK_LINE(5365)
					int _t8;		HX_STACK_VAR(_t8,"_t8");
					HX_STACK_LINE(5365)
					bool _t9;		HX_STACK_VAR(_t9,"_t9");
					HX_STACK_LINE(5365)
					this->_latestPH = (int)165;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",5365);
							{
								HX_STACK_LINE(5365)
								::tardis::Slice _v = __this->_t0;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(5365)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(5365)
					_t7 = _Function_4_1::Block(this);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",5365);
							{
								HX_STACK_LINE(5365)
								::tardis::Slice _v = __this->_t1;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(5365)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(5365)
					_t8 = _Function_4_2::Block(this);
					HX_STACK_LINE(5365)
					_t9 = (_t7 == _t8);
					HX_STACK_LINE(5365)
					this->_Next = (  ((_t9)) ? int((int)9) : int((int)10) );
				}
				HX_STACK_LINE(5366)
				this->_Phi = (int)2;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(5368)
				{
					HX_STACK_LINE(5368)
					this->_latestPH = (int)151;
					HX_STACK_LINE(5368)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(5369)
				this->_latestPH = (int)155;
				HX_STACK_LINE(5370)
				this->_t10 = (  (((this->_Phi == (int)0))) ? int((int)0) : int((  (((this->_Phi == (int)8))) ? int(this->_t20) : int((int)0) )) );
				HX_STACK_LINE(5371)
				{
					HX_STACK_LINE(5371)
					int _t11;		HX_STACK_VAR(_t11,"_t11");
					HX_STACK_LINE(5371)
					bool _t12;		HX_STACK_VAR(_t12,"_t12");
					HX_STACK_LINE(5371)
					this->_latestPH = (int)156;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",5371);
							{
								HX_STACK_LINE(5371)
								::tardis::Slice _v = __this->_t0;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(5371)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(5371)
					_t11 = _Function_4_1::Block(this);
					HX_STACK_LINE(5371)
					_t12 = (this->_t10 < _t11);
					HX_STACK_LINE(5371)
					this->_Next = (  ((_t12)) ? int((int)4) : int((int)2) );
				}
				HX_STACK_LINE(5372)
				this->_Phi = (int)3;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(5374)
				{
					HX_STACK_LINE(5374)
					this->_latestPH = (int)155;
					HX_STACK_LINE(5374)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(5375)
				{
					HX_STACK_LINE(5375)
					int _t13;		HX_STACK_VAR(_t13,"_t13");
					HX_STACK_LINE(5375)
					bool _t14;		HX_STACK_VAR(_t14,"_t14");
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",5375);
							{
								HX_STACK_LINE(5375)
								::tardis::Slice _v = __this->_t1;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(5375)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(5375)
					_t13 = _Function_4_1::Block(this);
					HX_STACK_LINE(5375)
					_t14 = (this->_t10 < _t13);
					HX_STACK_LINE(5375)
					this->_Next = (  ((_t14)) ? int((int)1) : int((int)2) );
				}
				HX_STACK_LINE(5376)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(5378)
				{
					HX_STACK_LINE(5378)
					this->_latestPH = (int)155;
					HX_STACK_LINE(5378)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(5379)
				this->_latestPH = (int)158;
				HX_STACK_LINE(5380)
				this->_res = (int)-1;
				HX_STACK_LINE(5381)
				this->_incomplete = false;
				HX_STACK_LINE(5382)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5383)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(5386)
				{
					HX_STACK_LINE(5386)
					this->_latestPH = (int)158;
					HX_STACK_LINE(5386)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(5387)
				{
					HX_STACK_LINE(5387)
					::tardis::Pointer _t15;		HX_STACK_VAR(_t15,"_t15");
					HX_STACK_LINE(5387)
					int _t16;		HX_STACK_VAR(_t16,"_t16");
					HX_STACK_LINE(5387)
					::tardis::Pointer _t17;		HX_STACK_VAR(_t17,"_t17");
					HX_STACK_LINE(5387)
					int _t18;		HX_STACK_VAR(_t18,"_t18");
					HX_STACK_LINE(5387)
					bool _t19;		HX_STACK_VAR(_t19,"_t19");
					HX_STACK_LINE(5387)
					this->_latestPH = (int)160;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",5387);
							{
								HX_STACK_LINE(5387)
								::tardis::Slice _this = __this->_t0;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(5387)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(5387)
					if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(5387)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(5387)
					_t15 = this->_t0->addr(this->_t10);
					HX_STACK_LINE(5387)
					_t16 = (int(_t15->ref()) | int((int)0));
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",5387);
							{
								HX_STACK_LINE(5387)
								::tardis::Slice _this = __this->_t1;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(5387)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(5387)
					if (((bool((this->_t10 < (int)0)) || bool((this->_t10 >= _Function_4_2::Block(this)))))){
						HX_STACK_LINE(5387)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(5387)
					_t17 = this->_t1->addr(this->_t10);
					HX_STACK_LINE(5387)
					_t18 = (int(_t17->ref()) | int((int)0));
					HX_STACK_LINE(5387)
					_t19 = (::tardis::Force_obj::uintCompare(_t16,_t18) > (int)0);
					HX_STACK_LINE(5387)
					this->_Next = (  ((_t19)) ? int((int)7) : int((int)8) );
				}
				HX_STACK_LINE(5388)
				this->_Phi = (int)6;
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(5390)
				{
					HX_STACK_LINE(5390)
					this->_latestPH = (int)158;
					HX_STACK_LINE(5390)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(5391)
				this->_latestPH = (int)161;
				HX_STACK_LINE(5392)
				this->_res = (int)1;
				HX_STACK_LINE(5393)
				this->_incomplete = false;
				HX_STACK_LINE(5394)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5395)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(5398)
				{
					HX_STACK_LINE(5398)
					this->_latestPH = (int)161;
					HX_STACK_LINE(5398)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(5399)
				{
					HX_STACK_LINE(5399)
					this->_t20 = (this->_t10 + (int)1);
					HX_STACK_LINE(5399)
					this->_Next = (int)3;
				}
				HX_STACK_LINE(5400)
				this->_Phi = (int)8;
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(5402)
				{
					HX_STACK_LINE(5402)
					this->_latestPH = (int)161;
					HX_STACK_LINE(5402)
					this->_latestBlock = (int)9;
				}
				HX_STACK_LINE(5403)
				this->_latestPH = (int)166;
				HX_STACK_LINE(5404)
				this->_res = (int)0;
				HX_STACK_LINE(5405)
				this->_incomplete = false;
				HX_STACK_LINE(5406)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5407)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(5410)
				{
					HX_STACK_LINE(5410)
					this->_latestPH = (int)166;
					HX_STACK_LINE(5410)
					this->_latestBlock = (int)10;
				}
				HX_STACK_LINE(5411)
				{
					HX_STACK_LINE(5411)
					int _t21;		HX_STACK_VAR(_t21,"_t21");
					HX_STACK_LINE(5411)
					int _t22;		HX_STACK_VAR(_t22,"_t22");
					HX_STACK_LINE(5411)
					bool _t23;		HX_STACK_VAR(_t23,"_t23");
					HX_STACK_LINE(5411)
					this->_latestPH = (int)168;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",5411);
							{
								HX_STACK_LINE(5411)
								::tardis::Slice _v = __this->_t0;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(5411)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(5411)
					_t21 = _Function_4_1::Block(this);
					struct _Function_4_2{
						inline static int Block( ::tardis::Go_haxegoruntime_StringCompare_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",5411);
							{
								HX_STACK_LINE(5411)
								::tardis::Slice _v = __this->_t1;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(5411)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(5411)
					_t22 = _Function_4_2::Block(this);
					HX_STACK_LINE(5411)
					_t23 = (_t21 < _t22);
					HX_STACK_LINE(5411)
					this->_Next = (  ((_t23)) ? int((int)11) : int((int)12) );
				}
				HX_STACK_LINE(5412)
				this->_Phi = (int)10;
			}
			;break;
			case (int)11: {
				HX_STACK_LINE(5414)
				{
					HX_STACK_LINE(5414)
					this->_latestPH = (int)166;
					HX_STACK_LINE(5414)
					this->_latestBlock = (int)11;
				}
				HX_STACK_LINE(5415)
				this->_latestPH = (int)169;
				HX_STACK_LINE(5416)
				this->_res = (int)-1;
				HX_STACK_LINE(5417)
				this->_incomplete = false;
				HX_STACK_LINE(5418)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5419)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)12: {
				HX_STACK_LINE(5422)
				{
					HX_STACK_LINE(5422)
					this->_latestPH = (int)169;
					HX_STACK_LINE(5422)
					this->_latestBlock = (int)12;
				}
				HX_STACK_LINE(5423)
				this->_latestPH = (int)171;
				HX_STACK_LINE(5424)
				this->_res = (int)1;
				HX_STACK_LINE(5425)
				this->_incomplete = false;
				HX_STACK_LINE(5426)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5427)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(5429)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5352)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_StringCompare_obj,run,return )

Dynamic Go_haxegoruntime_StringCompare_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_StringCompare::res","tardis/Go.hx",5311);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5311)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_StringCompare_obj,res,return )

int Go_haxegoruntime_StringCompare_obj::callFromHaxe( ::String p_a,::String p_b){
	HX_STACK_PUSH("Go_haxegoruntime_StringCompare::callFromHaxe","tardis/Go.hx",5338);
	HX_STACK_ARG(p_a,"p_a");
	HX_STACK_ARG(p_b,"p_b");
	HX_STACK_LINE(5339)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(5339)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(5340)
	::tardis::Go_haxegoruntime_StringCompare _sf = hx::TCast< ::tardis::Go_haxegoruntime_StringCompare >::cast(::tardis::Go_haxegoruntime_StringCompare_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_a,p_b)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5341)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5341)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(5342)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_StringCompare_obj,callFromHaxe,return )

int Go_haxegoruntime_StringCompare_obj::callFromRT( int _gr,::String p_a,::String p_b){
	HX_STACK_PUSH("Go_haxegoruntime_StringCompare::callFromRT","tardis/Go.hx",5344);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_a,"p_a");
	HX_STACK_ARG(p_b,"p_b");
	HX_STACK_LINE(5345)
	::tardis::Go_haxegoruntime_StringCompare _sf = hx::TCast< ::tardis::Go_haxegoruntime_StringCompare >::cast(::tardis::Go_haxegoruntime_StringCompare_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_a,p_b)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5346)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5346)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(5346)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(5346)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(5346)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(5347)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_haxegoruntime_StringCompare_obj,callFromRT,return )

::tardis::Go_haxegoruntime_StringCompare Go_haxegoruntime_StringCompare_obj::call( int gr,Dynamic _bds,::String p_a,::String p_b){
	HX_STACK_PUSH("Go_haxegoruntime_StringCompare::call","tardis/Go.hx",5350);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_a,"p_a");
	HX_STACK_ARG(p_b,"p_b");
	HX_STACK_LINE(5350)
	return ::tardis::Go_haxegoruntime_StringCompare_obj::__new(gr,_bds,p_a,p_b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Go_haxegoruntime_StringCompare_obj,call,return )


Go_haxegoruntime_StringCompare_obj::Go_haxegoruntime_StringCompare_obj()
{
}

void Go_haxegoruntime_StringCompare_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_StringCompare);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t23,"_t23");
	HX_MARK_MEMBER_NAME(_t22,"_t22");
	HX_MARK_MEMBER_NAME(_t21,"_t21");
	HX_MARK_MEMBER_NAME(_t20,"_t20");
	HX_MARK_MEMBER_NAME(_t19,"_t19");
	HX_MARK_MEMBER_NAME(_t18,"_t18");
	HX_MARK_MEMBER_NAME(_t17,"_t17");
	HX_MARK_MEMBER_NAME(_t16,"_t16");
	HX_MARK_MEMBER_NAME(_t15,"_t15");
	HX_MARK_MEMBER_NAME(_t14,"_t14");
	HX_MARK_MEMBER_NAME(_t13,"_t13");
	HX_MARK_MEMBER_NAME(_t12,"_t12");
	HX_MARK_MEMBER_NAME(_t11,"_t11");
	HX_MARK_MEMBER_NAME(_t10,"_t10");
	HX_MARK_MEMBER_NAME(_t9,"_t9");
	HX_MARK_MEMBER_NAME(_t8,"_t8");
	HX_MARK_MEMBER_NAME(_t7,"_t7");
	HX_MARK_MEMBER_NAME(_t6,"_t6");
	HX_MARK_MEMBER_NAME(_t5,"_t5");
	HX_MARK_MEMBER_NAME(_t4,"_t4");
	HX_MARK_MEMBER_NAME(_t3,"_t3");
	HX_MARK_MEMBER_NAME(_t2,"_t2");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_b,"p_b");
	HX_MARK_MEMBER_NAME(p_a,"p_a");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_StringCompare_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t23,"_t23");
	HX_VISIT_MEMBER_NAME(_t22,"_t22");
	HX_VISIT_MEMBER_NAME(_t21,"_t21");
	HX_VISIT_MEMBER_NAME(_t20,"_t20");
	HX_VISIT_MEMBER_NAME(_t19,"_t19");
	HX_VISIT_MEMBER_NAME(_t18,"_t18");
	HX_VISIT_MEMBER_NAME(_t17,"_t17");
	HX_VISIT_MEMBER_NAME(_t16,"_t16");
	HX_VISIT_MEMBER_NAME(_t15,"_t15");
	HX_VISIT_MEMBER_NAME(_t14,"_t14");
	HX_VISIT_MEMBER_NAME(_t13,"_t13");
	HX_VISIT_MEMBER_NAME(_t12,"_t12");
	HX_VISIT_MEMBER_NAME(_t11,"_t11");
	HX_VISIT_MEMBER_NAME(_t10,"_t10");
	HX_VISIT_MEMBER_NAME(_t9,"_t9");
	HX_VISIT_MEMBER_NAME(_t8,"_t8");
	HX_VISIT_MEMBER_NAME(_t7,"_t7");
	HX_VISIT_MEMBER_NAME(_t6,"_t6");
	HX_VISIT_MEMBER_NAME(_t5,"_t5");
	HX_VISIT_MEMBER_NAME(_t4,"_t4");
	HX_VISIT_MEMBER_NAME(_t3,"_t3");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_b,"p_b");
	HX_VISIT_MEMBER_NAME(p_a,"p_a");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_StringCompare_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t9") ) { return _t9; }
		if (HX_FIELD_EQ(inName,"_t8") ) { return _t8; }
		if (HX_FIELD_EQ(inName,"_t7") ) { return _t7; }
		if (HX_FIELD_EQ(inName,"_t6") ) { return _t6; }
		if (HX_FIELD_EQ(inName,"_t5") ) { return _t5; }
		if (HX_FIELD_EQ(inName,"_t4") ) { return _t4; }
		if (HX_FIELD_EQ(inName,"_t3") ) { return _t3; }
		if (HX_FIELD_EQ(inName,"_t2") ) { return _t2; }
		if (HX_FIELD_EQ(inName,"_t1") ) { return _t1; }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		if (HX_FIELD_EQ(inName,"p_b") ) { return p_b; }
		if (HX_FIELD_EQ(inName,"p_a") ) { return p_a; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_Phi") ) { return _Phi; }
		if (HX_FIELD_EQ(inName,"_t23") ) { return _t23; }
		if (HX_FIELD_EQ(inName,"_t22") ) { return _t22; }
		if (HX_FIELD_EQ(inName,"_t21") ) { return _t21; }
		if (HX_FIELD_EQ(inName,"_t20") ) { return _t20; }
		if (HX_FIELD_EQ(inName,"_t19") ) { return _t19; }
		if (HX_FIELD_EQ(inName,"_t18") ) { return _t18; }
		if (HX_FIELD_EQ(inName,"_t17") ) { return _t17; }
		if (HX_FIELD_EQ(inName,"_t16") ) { return _t16; }
		if (HX_FIELD_EQ(inName,"_t15") ) { return _t15; }
		if (HX_FIELD_EQ(inName,"_t14") ) { return _t14; }
		if (HX_FIELD_EQ(inName,"_t13") ) { return _t13; }
		if (HX_FIELD_EQ(inName,"_t12") ) { return _t12; }
		if (HX_FIELD_EQ(inName,"_t11") ) { return _t11; }
		if (HX_FIELD_EQ(inName,"_t10") ) { return _t10; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SubFn7") ) { return SubFn7_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn6") ) { return SubFn6_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn5") ) { return SubFn5_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn4") ) { return SubFn4_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn3") ) { return SubFn3_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn2") ) { return SubFn2_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn1") ) { return SubFn1_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn0") ) { return SubFn0_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_haxegoruntime_StringCompare_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_b") ) { p_b=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a") ) { p_a=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t23") ) { _t23=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t22") ) { _t22=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t21") ) { _t21=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t20") ) { _t20=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t19") ) { _t19=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t18") ) { _t18=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t17") ) { _t17=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t14") ) { _t14=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_StringCompare_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t23"));
	outFields->push(HX_CSTRING("_t22"));
	outFields->push(HX_CSTRING("_t21"));
	outFields->push(HX_CSTRING("_t20"));
	outFields->push(HX_CSTRING("_t19"));
	outFields->push(HX_CSTRING("_t18"));
	outFields->push(HX_CSTRING("_t17"));
	outFields->push(HX_CSTRING("_t16"));
	outFields->push(HX_CSTRING("_t15"));
	outFields->push(HX_CSTRING("_t14"));
	outFields->push(HX_CSTRING("_t13"));
	outFields->push(HX_CSTRING("_t12"));
	outFields->push(HX_CSTRING("_t11"));
	outFields->push(HX_CSTRING("_t10"));
	outFields->push(HX_CSTRING("_t9"));
	outFields->push(HX_CSTRING("_t8"));
	outFields->push(HX_CSTRING("_t7"));
	outFields->push(HX_CSTRING("_t6"));
	outFields->push(HX_CSTRING("_t5"));
	outFields->push(HX_CSTRING("_t4"));
	outFields->push(HX_CSTRING("_t3"));
	outFields->push(HX_CSTRING("_t2"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_b"));
	outFields->push(HX_CSTRING("p_a"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("SubFn7"),
	HX_CSTRING("SubFn6"),
	HX_CSTRING("SubFn5"),
	HX_CSTRING("SubFn4"),
	HX_CSTRING("SubFn3"),
	HX_CSTRING("SubFn2"),
	HX_CSTRING("SubFn1"),
	HX_CSTRING("SubFn0"),
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("_Phi"),
	HX_CSTRING("_t23"),
	HX_CSTRING("_t22"),
	HX_CSTRING("_t21"),
	HX_CSTRING("_t20"),
	HX_CSTRING("_t19"),
	HX_CSTRING("_t18"),
	HX_CSTRING("_t17"),
	HX_CSTRING("_t16"),
	HX_CSTRING("_t15"),
	HX_CSTRING("_t14"),
	HX_CSTRING("_t13"),
	HX_CSTRING("_t12"),
	HX_CSTRING("_t11"),
	HX_CSTRING("_t10"),
	HX_CSTRING("_t9"),
	HX_CSTRING("_t8"),
	HX_CSTRING("_t7"),
	HX_CSTRING("_t6"),
	HX_CSTRING("_t5"),
	HX_CSTRING("_t4"),
	HX_CSTRING("_t3"),
	HX_CSTRING("_t2"),
	HX_CSTRING("_t1"),
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_b"),
	HX_CSTRING("p_a"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_StringCompare_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_StringCompare_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_StringCompare_obj::__mClass;

void Go_haxegoruntime_StringCompare_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_StringCompare"), hx::TCanCast< Go_haxegoruntime_StringCompare_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_StringCompare_obj::__boot()
{
}

} // end namespace tardis
