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
#ifndef INCLUDED_tardis_Go_utf8_DecodeLastRuneInString
#include <tardis/Go_utf8_DecodeLastRuneInString.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_DecodeRuneInString
#include <tardis/Go_utf8_DecodeRuneInString.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_RuneStart
#include <tardis/Go_utf8_RuneStart.h>
#endif
#ifndef INCLUDED_tardis_Interface
#include <tardis/Interface.h>
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

Void Go_utf8_DecodeLastRuneInString_obj::__construct(int gr,Dynamic _bds,::String p_s)
{
HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::new","tardis/Go.hx",2447);
{
	HX_STACK_LINE(2483)
	this->_Next = (int)0;
	HX_STACK_LINE(2482)
	this->_Phi = (int)0;
	HX_STACK_LINE(2481)
	this->_t22 = false;
	HX_STACK_LINE(2480)
	this->_t21 = (int)0;
	HX_STACK_LINE(2479)
	this->_t20 = (int)0;
	HX_STACK_LINE(2478)
	this->_t19 = (int)0;
	HX_STACK_LINE(2477)
	this->_t18 = null();
	HX_STACK_LINE(2475)
	this->_t17 = HX_CSTRING("");
	HX_STACK_LINE(2474)
	this->_t16 = (int)0;
	HX_STACK_LINE(2473)
	this->_t15 = (int)0;
	HX_STACK_LINE(2472)
	this->_t14 = false;
	HX_STACK_LINE(2471)
	this->_t13 = (int)0;
	HX_STACK_LINE(2470)
	this->_t12 = false;
	HX_STACK_LINE(2469)
	this->_t11 = false;
	HX_STACK_LINE(2467)
	this->_t10 = (int)0;
	HX_STACK_LINE(2466)
	this->_t9 = (int)0;
	HX_STACK_LINE(2465)
	this->_t8 = (int)0;
	HX_STACK_LINE(2464)
	this->_t7 = false;
	HX_STACK_LINE(2463)
	this->_t6 = (int)0;
	HX_STACK_LINE(2462)
	this->_t5 = false;
	HX_STACK_LINE(2461)
	this->_t4 = (int)0;
	HX_STACK_LINE(2460)
	this->_t3 = (int)0;
	HX_STACK_LINE(2459)
	this->_t2 = (int)0;
	HX_STACK_LINE(2458)
	this->_t1 = false;
	HX_STACK_LINE(2457)
	this->_t0 = (int)0;
	HX_STACK_LINE(2450)
	super::__construct(gr,(int)809,HX_CSTRING("Go_utf8_DecodeLastRuneInString"));
	HX_STACK_LINE(2451)
	this->_bds = _bds;
	HX_STACK_LINE(2452)
	this->p_s = p_s;
	HX_STACK_LINE(2453)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_DecodeLastRuneInString_obj::~Go_utf8_DecodeLastRuneInString_obj() { }

Dynamic Go_utf8_DecodeLastRuneInString_obj::__CreateEmpty() { return  new Go_utf8_DecodeLastRuneInString_obj; }
hx::ObjectPtr< Go_utf8_DecodeLastRuneInString_obj > Go_utf8_DecodeLastRuneInString_obj::__new(int gr,Dynamic _bds,::String p_s)
{  hx::ObjectPtr< Go_utf8_DecodeLastRuneInString_obj > result = new Go_utf8_DecodeLastRuneInString_obj();
	result->__construct(gr,_bds,p_s);
	return result;}

Dynamic Go_utf8_DecodeLastRuneInString_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_DecodeLastRuneInString_obj > result = new Go_utf8_DecodeLastRuneInString_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_DecodeLastRuneInString_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_DecodeLastRuneInString_obj::SubFn12( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn12","tardis/Go.hx",2666);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2667)
		int _t21;		HX_STACK_VAR(_t21,"_t21");
		HX_STACK_LINE(2668)
		bool _t22;		HX_STACK_VAR(_t22,"_t22");
		HX_STACK_LINE(2669)
		this->_t19 = this->_t18->__Field(HX_CSTRING("r0"),true);
		HX_STACK_LINE(2670)
		this->_t20 = this->_t18->__Field(HX_CSTRING("r1"),true);
		HX_STACK_LINE(2671)
		this->_latestPH = (int)835;
		HX_STACK_LINE(2672)
		_t21 = (this->_t16 + this->_t20);
		HX_STACK_LINE(2673)
		_t22 = (_t21 != this->_t0);
		HX_STACK_LINE(2674)
		this->_Next = (  ((_t22)) ? int((int)13) : int((int)14) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn12,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn11( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn11","tardis/Go.hx",2662);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2663)
		this->_latestPH = (int)834;
		HX_STACK_LINE(2664)
		this->_t17 = ::tardis::Force_obj::toRawString(this->_goroutine,::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->subSlice(this->_t16,this->_t0));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn11,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn10( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn10","tardis/Go.hx",2659);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2659)
		this->_Next = (int)12;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn10,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn9( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn9","tardis/Go.hx",2655);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2656)
		this->_t15 = (this->_t13 - (int)1);
		HX_STACK_LINE(2657)
		this->_Next = (int)9;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn9,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn8( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn8","tardis/Go.hx",2649);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2650)
		bool _t14;		HX_STACK_VAR(_t14,"_t14");
		HX_STACK_LINE(2651)
		this->_latestPH = (int)826;
		HX_STACK_LINE(2652)
		_t14 = (this->_t13 >= this->_t8);
		HX_STACK_LINE(2653)
		this->_Next = (  ((_t14)) ? int((int)7) : int((int)8) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn8,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn7","tardis/Go.hx",2643);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2644)
		bool _t12;		HX_STACK_VAR(_t12,"_t12");
		HX_STACK_LINE(2645)
		this->_latestPH = (int)831;
		HX_STACK_LINE(2646)
		_t12 = (this->_t13 < (int)0);
		HX_STACK_LINE(2647)
		this->_Next = (  ((_t12)) ? int((int)11) : int((int)12) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn7,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn6","tardis/Go.hx",2640);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2640)
		this->_Next = (  ((this->_t11)) ? int((int)8) : int((int)10) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn6,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn5","tardis/Go.hx",2636);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2637)
		this->_latestPH = (int)827;
		HX_STACK_LINE(2638)
		this->_t10 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt(this->_t13);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn5,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn4","tardis/Go.hx",2632);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2633)
		this->_t9 = (this->_t2 - (int)1);
		HX_STACK_LINE(2634)
		this->_Next = (int)9;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn4,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn3","tardis/Go.hx",2629);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2629)
		this->_Next = (int)6;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn3,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn2","tardis/Go.hx",2621);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2622)
		bool _t7;		HX_STACK_VAR(_t7,"_t7");
		HX_STACK_LINE(2623)
		this->_latestPH = (int)822;
		HX_STACK_LINE(2624)
		this->_t6 = (this->_t0 - (int)4);
		HX_STACK_LINE(2625)
		this->_latestPH = (int)823;
		HX_STACK_LINE(2626)
		_t7 = (this->_t6 < (int)0);
		HX_STACK_LINE(2627)
		this->_Next = (  ((_t7)) ? int((int)5) : int((int)6) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn2,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn1","tardis/Go.hx",2609);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2610)
		int _t3;		HX_STACK_VAR(_t3,"_t3");
		HX_STACK_LINE(2611)
		bool _t5;		HX_STACK_VAR(_t5,"_t5");
		HX_STACK_LINE(2612)
		this->_latestPH = (int)814;
		HX_STACK_LINE(2613)
		this->_t2 = (this->_t0 - (int)1);
		HX_STACK_LINE(2614)
		this->_latestPH = (int)815;
		HX_STACK_LINE(2615)
		_t3 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt(this->_t2);
		HX_STACK_LINE(2616)
		this->_t4 = _t3;
		HX_STACK_LINE(2617)
		this->_latestPH = (int)816;
		HX_STACK_LINE(2618)
		_t5 = (this->_t4 < (int)128);
		HX_STACK_LINE(2619)
		this->_Next = (  ((_t5)) ? int((int)3) : int((int)4) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn1,(void))

Void Go_utf8_DecodeLastRuneInString_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::SubFn0","tardis/Go.hx",2601);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2602)
		bool _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(2603)
		this->_latestPH = (int)810;
		HX_STACK_LINE(2604)
		this->_t0 = ::tardis::Force_obj::toUTF8length(this->_goroutine,this->p_s);
		HX_STACK_LINE(2605)
		this->_latestPH = (int)811;
		HX_STACK_LINE(2606)
		_t1 = (this->_t0 == (int)0);
		HX_STACK_LINE(2607)
		this->_Next = (  ((_t1)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_DecodeLastRuneInString_obj::run( ){
	HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::run","tardis/Go.hx",2498);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2498)
	while((true)){
		HX_STACK_LINE(2500)
		::tardis::Go_utf8_DecodeLastRuneInString _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(2500)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(2502)
				{
					HX_STACK_LINE(2502)
					this->_latestPH = (int)809;
					HX_STACK_LINE(2502)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(2503)
				{
					HX_STACK_LINE(2503)
					bool _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(2503)
					this->_latestPH = (int)810;
					HX_STACK_LINE(2503)
					this->_t0 = ::tardis::Force_obj::toUTF8length(this->_goroutine,this->p_s);
					HX_STACK_LINE(2503)
					this->_latestPH = (int)811;
					HX_STACK_LINE(2503)
					_t1 = (this->_t0 == (int)0);
					HX_STACK_LINE(2503)
					this->_Next = (  ((_t1)) ? int((int)1) : int((int)2) );
				}
				HX_STACK_LINE(2504)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(2506)
				{
					HX_STACK_LINE(2506)
					this->_latestPH = (int)809;
					HX_STACK_LINE(2506)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(2507)
				this->_latestPH = (int)812;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",2508);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)0,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(2508)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(2509)
				this->_incomplete = false;
				HX_STACK_LINE(2510)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(2511)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(2514)
				{
					HX_STACK_LINE(2514)
					this->_latestPH = (int)812;
					HX_STACK_LINE(2514)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(2515)
				{
					HX_STACK_LINE(2515)
					int _t3;		HX_STACK_VAR(_t3,"_t3");
					HX_STACK_LINE(2515)
					bool _t5;		HX_STACK_VAR(_t5,"_t5");
					HX_STACK_LINE(2515)
					this->_latestPH = (int)814;
					HX_STACK_LINE(2515)
					this->_t2 = (this->_t0 - (int)1);
					HX_STACK_LINE(2515)
					this->_latestPH = (int)815;
					HX_STACK_LINE(2515)
					_t3 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt(this->_t2);
					HX_STACK_LINE(2515)
					this->_t4 = _t3;
					HX_STACK_LINE(2515)
					this->_latestPH = (int)816;
					HX_STACK_LINE(2515)
					_t5 = (this->_t4 < (int)128);
					HX_STACK_LINE(2515)
					this->_Next = (  ((_t5)) ? int((int)3) : int((int)4) );
				}
				HX_STACK_LINE(2516)
				this->_Phi = (int)2;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(2518)
				{
					HX_STACK_LINE(2518)
					this->_latestPH = (int)812;
					HX_STACK_LINE(2518)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(2519)
				this->_latestPH = (int)817;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::Go_utf8_DecodeLastRuneInString_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",2520);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t4,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(2520)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(2521)
				this->_incomplete = false;
				HX_STACK_LINE(2522)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(2523)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(2526)
				{
					HX_STACK_LINE(2526)
					this->_latestPH = (int)817;
					HX_STACK_LINE(2526)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(2527)
				{
					HX_STACK_LINE(2527)
					bool _t7;		HX_STACK_VAR(_t7,"_t7");
					HX_STACK_LINE(2527)
					this->_latestPH = (int)822;
					HX_STACK_LINE(2527)
					this->_t6 = (this->_t0 - (int)4);
					HX_STACK_LINE(2527)
					this->_latestPH = (int)823;
					HX_STACK_LINE(2527)
					_t7 = (this->_t6 < (int)0);
					HX_STACK_LINE(2527)
					this->_Next = (  ((_t7)) ? int((int)5) : int((int)6) );
				}
				HX_STACK_LINE(2528)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(2530)
				{
					HX_STACK_LINE(2530)
					this->_latestPH = (int)817;
					HX_STACK_LINE(2530)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(2531)
				this->_Next = (int)6;
				HX_STACK_LINE(2532)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(2534)
				{
					HX_STACK_LINE(2534)
					this->_latestPH = (int)817;
					HX_STACK_LINE(2534)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(2535)
				this->_latestPH = (int)822;
				HX_STACK_LINE(2536)
				this->_t8 = (  (((this->_Phi == (int)4))) ? int(this->_t6) : int((  (((this->_Phi == (int)5))) ? int((int)0) : int((int)0) )) );
				HX_STACK_LINE(2537)
				{
					HX_STACK_LINE(2537)
					this->_t9 = (this->_t2 - (int)1);
					HX_STACK_LINE(2537)
					this->_Next = (int)9;
				}
				HX_STACK_LINE(2538)
				this->_Phi = (int)6;
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(2540)
				{
					HX_STACK_LINE(2540)
					this->_latestPH = (int)822;
					HX_STACK_LINE(2540)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(2541)
				{
					HX_STACK_LINE(2541)
					this->_latestPH = (int)827;
					HX_STACK_LINE(2541)
					this->_t10 = ::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->getAt(this->_t13);
				}
				HX_STACK_LINE(2542)
				this->_latestPH = (int)827;
				HX_STACK_LINE(2543)
				this->_SF1 = ::tardis::Go_utf8_RuneStart_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t10);
				HX_STACK_LINE(2544)
				this->_Next = (int)-1;
				HX_STACK_LINE(2545)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(2547)
				{
					HX_STACK_LINE(2547)
					this->_latestPH = (int)827;
					HX_STACK_LINE(2547)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(2548)
				this->_t11 = this->_SF1->res();
				HX_STACK_LINE(2550)
				this->_Next = (  ((this->_t11)) ? int((int)8) : int((int)10) );
				HX_STACK_LINE(2551)
				this->_Phi = (int)7;
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(2553)
				{
					HX_STACK_LINE(2553)
					this->_latestPH = (int)827;
					HX_STACK_LINE(2553)
					this->_latestBlock = (int)8;
				}
				HX_STACK_LINE(2554)
				{
					HX_STACK_LINE(2554)
					bool _t12;		HX_STACK_VAR(_t12,"_t12");
					HX_STACK_LINE(2554)
					this->_latestPH = (int)831;
					HX_STACK_LINE(2554)
					_t12 = (this->_t13 < (int)0);
					HX_STACK_LINE(2554)
					this->_Next = (  ((_t12)) ? int((int)11) : int((int)12) );
				}
				HX_STACK_LINE(2555)
				this->_Phi = (int)8;
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(2557)
				{
					HX_STACK_LINE(2557)
					this->_latestPH = (int)827;
					HX_STACK_LINE(2557)
					this->_latestBlock = (int)9;
				}
				HX_STACK_LINE(2558)
				this->_latestPH = (int)814;
				HX_STACK_LINE(2559)
				this->_t13 = (  (((this->_Phi == (int)6))) ? int(this->_t9) : int((  (((this->_Phi == (int)10))) ? int(this->_t15) : int((int)0) )) );
				HX_STACK_LINE(2560)
				{
					HX_STACK_LINE(2560)
					bool _t14;		HX_STACK_VAR(_t14,"_t14");
					HX_STACK_LINE(2560)
					this->_latestPH = (int)826;
					HX_STACK_LINE(2560)
					_t14 = (this->_t13 >= this->_t8);
					HX_STACK_LINE(2560)
					this->_Next = (  ((_t14)) ? int((int)7) : int((int)8) );
				}
				HX_STACK_LINE(2561)
				this->_Phi = (int)9;
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(2563)
				{
					HX_STACK_LINE(2563)
					this->_latestPH = (int)814;
					HX_STACK_LINE(2563)
					this->_latestBlock = (int)10;
				}
				HX_STACK_LINE(2564)
				{
					HX_STACK_LINE(2564)
					this->_t15 = (this->_t13 - (int)1);
					HX_STACK_LINE(2564)
					this->_Next = (int)9;
				}
				HX_STACK_LINE(2565)
				this->_Phi = (int)10;
			}
			;break;
			case (int)11: {
				HX_STACK_LINE(2567)
				{
					HX_STACK_LINE(2567)
					this->_latestPH = (int)814;
					HX_STACK_LINE(2567)
					this->_latestBlock = (int)11;
				}
				HX_STACK_LINE(2568)
				this->_Next = (int)12;
				HX_STACK_LINE(2569)
				this->_Phi = (int)11;
			}
			;break;
			case (int)12: {
				HX_STACK_LINE(2571)
				{
					HX_STACK_LINE(2571)
					this->_latestPH = (int)814;
					HX_STACK_LINE(2571)
					this->_latestBlock = (int)12;
				}
				HX_STACK_LINE(2572)
				this->_t16 = (  (((this->_Phi == (int)8))) ? int(this->_t13) : int((  (((this->_Phi == (int)11))) ? int((int)0) : int((int)0) )) );
				HX_STACK_LINE(2573)
				{
					HX_STACK_LINE(2573)
					this->_latestPH = (int)834;
					HX_STACK_LINE(2573)
					this->_t17 = ::tardis::Force_obj::toRawString(this->_goroutine,::tardis::Force_obj::toUTF8slice(this->_goroutine,this->p_s)->subSlice(this->_t16,this->_t0));
				}
				HX_STACK_LINE(2574)
				this->_latestPH = (int)834;
				HX_STACK_LINE(2575)
				this->_SF2 = ::tardis::Go_utf8_DecodeRuneInString_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t17);
				HX_STACK_LINE(2576)
				this->_Next = (int)-2;
				HX_STACK_LINE(2577)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-2: {
				HX_STACK_LINE(2579)
				{
					HX_STACK_LINE(2579)
					this->_latestPH = (int)834;
					HX_STACK_LINE(2579)
					this->_latestBlock = (int)-2;
				}
				HX_STACK_LINE(2580)
				this->_t18 = this->_SF2->res();
				HX_STACK_LINE(2582)
				{
					HX_STACK_LINE(2582)
					int _t21;		HX_STACK_VAR(_t21,"_t21");
					HX_STACK_LINE(2582)
					bool _t22;		HX_STACK_VAR(_t22,"_t22");
					HX_STACK_LINE(2582)
					this->_t19 = this->_t18->__Field(HX_CSTRING("r0"),true);
					HX_STACK_LINE(2582)
					this->_t20 = this->_t18->__Field(HX_CSTRING("r1"),true);
					HX_STACK_LINE(2582)
					this->_latestPH = (int)835;
					HX_STACK_LINE(2582)
					_t21 = (this->_t16 + this->_t20);
					HX_STACK_LINE(2582)
					_t22 = (_t21 != this->_t0);
					HX_STACK_LINE(2582)
					this->_Next = (  ((_t22)) ? int((int)13) : int((int)14) );
				}
				HX_STACK_LINE(2583)
				this->_Phi = (int)12;
			}
			;break;
			case (int)13: {
				HX_STACK_LINE(2585)
				{
					HX_STACK_LINE(2585)
					this->_latestPH = (int)834;
					HX_STACK_LINE(2585)
					this->_latestBlock = (int)13;
				}
				HX_STACK_LINE(2586)
				this->_latestPH = (int)836;
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",2587);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , (int)65533,false);
							__result->Add(HX_CSTRING("r1") , (int)1,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(2587)
				this->_res = _Function_3_1::Block();
				HX_STACK_LINE(2588)
				this->_incomplete = false;
				HX_STACK_LINE(2589)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(2590)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)14: {
				HX_STACK_LINE(2593)
				{
					HX_STACK_LINE(2593)
					this->_latestPH = (int)836;
					HX_STACK_LINE(2593)
					this->_latestBlock = (int)14;
				}
				HX_STACK_LINE(2594)
				this->_latestPH = (int)838;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::Go_utf8_DecodeLastRuneInString_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",2595);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t19,false);
							__result->Add(HX_CSTRING("r1") , __this->_t20,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(2595)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(2596)
				this->_incomplete = false;
				HX_STACK_LINE(2597)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(2598)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(2600)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(2498)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,run,return )

Dynamic Go_utf8_DecodeLastRuneInString_obj::res( ){
	HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::res","tardis/Go.hx",2456);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2456)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeLastRuneInString_obj,res,return )

Dynamic Go_utf8_DecodeLastRuneInString_obj::callFromHaxe( ::String p_s){
	HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::callFromHaxe","tardis/Go.hx",2484);
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(2485)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(2485)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(2486)
	::tardis::Go_utf8_DecodeLastRuneInString _sf = hx::TCast< ::tardis::Go_utf8_DecodeLastRuneInString >::cast(::tardis::Go_utf8_DecodeLastRuneInString_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(2487)
	while((_sf->_incomplete)){
		HX_STACK_LINE(2487)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(2488)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_DecodeLastRuneInString_obj,callFromHaxe,return )

Dynamic Go_utf8_DecodeLastRuneInString_obj::callFromRT( int _gr,::String p_s){
	HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::callFromRT","tardis/Go.hx",2490);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(2491)
	::tardis::Go_utf8_DecodeLastRuneInString _sf = hx::TCast< ::tardis::Go_utf8_DecodeLastRuneInString >::cast(::tardis::Go_utf8_DecodeLastRuneInString_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(2492)
	while((_sf->_incomplete)){
		HX_STACK_LINE(2492)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(2492)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(2492)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(2492)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(2493)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_DecodeLastRuneInString_obj,callFromRT,return )

::tardis::Go_utf8_DecodeLastRuneInString Go_utf8_DecodeLastRuneInString_obj::call( int gr,Dynamic _bds,::String p_s){
	HX_STACK_PUSH("Go_utf8_DecodeLastRuneInString::call","tardis/Go.hx",2496);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(2496)
	return ::tardis::Go_utf8_DecodeLastRuneInString_obj::__new(gr,_bds,p_s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_DecodeLastRuneInString_obj,call,return )


Go_utf8_DecodeLastRuneInString_obj::Go_utf8_DecodeLastRuneInString_obj()
{
}

void Go_utf8_DecodeLastRuneInString_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_DecodeLastRuneInString);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t22,"_t22");
	HX_MARK_MEMBER_NAME(_t21,"_t21");
	HX_MARK_MEMBER_NAME(_t20,"_t20");
	HX_MARK_MEMBER_NAME(_t19,"_t19");
	HX_MARK_MEMBER_NAME(_t18,"_t18");
	HX_MARK_MEMBER_NAME(_SF2,"_SF2");
	HX_MARK_MEMBER_NAME(_t17,"_t17");
	HX_MARK_MEMBER_NAME(_t16,"_t16");
	HX_MARK_MEMBER_NAME(_t15,"_t15");
	HX_MARK_MEMBER_NAME(_t14,"_t14");
	HX_MARK_MEMBER_NAME(_t13,"_t13");
	HX_MARK_MEMBER_NAME(_t12,"_t12");
	HX_MARK_MEMBER_NAME(_t11,"_t11");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
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
	HX_MARK_MEMBER_NAME(p_s,"p_s");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_DecodeLastRuneInString_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t22,"_t22");
	HX_VISIT_MEMBER_NAME(_t21,"_t21");
	HX_VISIT_MEMBER_NAME(_t20,"_t20");
	HX_VISIT_MEMBER_NAME(_t19,"_t19");
	HX_VISIT_MEMBER_NAME(_t18,"_t18");
	HX_VISIT_MEMBER_NAME(_SF2,"_SF2");
	HX_VISIT_MEMBER_NAME(_t17,"_t17");
	HX_VISIT_MEMBER_NAME(_t16,"_t16");
	HX_VISIT_MEMBER_NAME(_t15,"_t15");
	HX_VISIT_MEMBER_NAME(_t14,"_t14");
	HX_VISIT_MEMBER_NAME(_t13,"_t13");
	HX_VISIT_MEMBER_NAME(_t12,"_t12");
	HX_VISIT_MEMBER_NAME(_t11,"_t11");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
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
	HX_VISIT_MEMBER_NAME(p_s,"p_s");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_DecodeLastRuneInString_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_s") ) { return p_s; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_Phi") ) { return _Phi; }
		if (HX_FIELD_EQ(inName,"_t22") ) { return _t22; }
		if (HX_FIELD_EQ(inName,"_t21") ) { return _t21; }
		if (HX_FIELD_EQ(inName,"_t20") ) { return _t20; }
		if (HX_FIELD_EQ(inName,"_t19") ) { return _t19; }
		if (HX_FIELD_EQ(inName,"_t18") ) { return _t18; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { return _SF2; }
		if (HX_FIELD_EQ(inName,"_t17") ) { return _t17; }
		if (HX_FIELD_EQ(inName,"_t16") ) { return _t16; }
		if (HX_FIELD_EQ(inName,"_t15") ) { return _t15; }
		if (HX_FIELD_EQ(inName,"_t14") ) { return _t14; }
		if (HX_FIELD_EQ(inName,"_t13") ) { return _t13; }
		if (HX_FIELD_EQ(inName,"_t12") ) { return _t12; }
		if (HX_FIELD_EQ(inName,"_t11") ) { return _t11; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
		if (HX_FIELD_EQ(inName,"_t10") ) { return _t10; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SubFn9") ) { return SubFn9_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn8") ) { return SubFn8_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn7") ) { return SubFn7_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn6") ) { return SubFn6_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn5") ) { return SubFn5_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn4") ) { return SubFn4_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn3") ) { return SubFn3_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn2") ) { return SubFn2_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn1") ) { return SubFn1_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn0") ) { return SubFn0_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"SubFn12") ) { return SubFn12_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn11") ) { return SubFn11_dyn(); }
		if (HX_FIELD_EQ(inName,"SubFn10") ) { return SubFn10_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_utf8_DecodeLastRuneInString_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_s") ) { p_s=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t22") ) { _t22=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t21") ) { _t21=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t20") ) { _t20=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t19") ) { _t19=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t18") ) { _t18=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { _SF2=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t17") ) { _t17=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t14") ) { _t14=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_DecodeLastRuneInString_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t22"));
	outFields->push(HX_CSTRING("_t21"));
	outFields->push(HX_CSTRING("_t20"));
	outFields->push(HX_CSTRING("_t19"));
	outFields->push(HX_CSTRING("_t18"));
	outFields->push(HX_CSTRING("_SF2"));
	outFields->push(HX_CSTRING("_t17"));
	outFields->push(HX_CSTRING("_t16"));
	outFields->push(HX_CSTRING("_t15"));
	outFields->push(HX_CSTRING("_t14"));
	outFields->push(HX_CSTRING("_t13"));
	outFields->push(HX_CSTRING("_t12"));
	outFields->push(HX_CSTRING("_t11"));
	outFields->push(HX_CSTRING("_SF1"));
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
	outFields->push(HX_CSTRING("p_s"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("SubFn12"),
	HX_CSTRING("SubFn11"),
	HX_CSTRING("SubFn10"),
	HX_CSTRING("SubFn9"),
	HX_CSTRING("SubFn8"),
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
	HX_CSTRING("_t22"),
	HX_CSTRING("_t21"),
	HX_CSTRING("_t20"),
	HX_CSTRING("_t19"),
	HX_CSTRING("_t18"),
	HX_CSTRING("_SF2"),
	HX_CSTRING("_t17"),
	HX_CSTRING("_t16"),
	HX_CSTRING("_t15"),
	HX_CSTRING("_t14"),
	HX_CSTRING("_t13"),
	HX_CSTRING("_t12"),
	HX_CSTRING("_t11"),
	HX_CSTRING("_SF1"),
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
	HX_CSTRING("p_s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_DecodeLastRuneInString_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_DecodeLastRuneInString_obj::__mClass,"__mClass");
};

Class Go_utf8_DecodeLastRuneInString_obj::__mClass;

void Go_utf8_DecodeLastRuneInString_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_DecodeLastRuneInString"), hx::TCanCast< Go_utf8_DecodeLastRuneInString_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_DecodeLastRuneInString_obj::__boot()
{
}

} // end namespace tardis
