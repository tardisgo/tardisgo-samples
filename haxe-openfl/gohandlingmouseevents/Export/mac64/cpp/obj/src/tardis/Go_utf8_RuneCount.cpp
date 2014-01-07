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
#ifndef INCLUDED_tardis_Go_utf8_DecodeRune
#include <tardis/Go_utf8_DecodeRune.h>
#endif
#ifndef INCLUDED_tardis_Go_utf8_RuneCount
#include <tardis/Go_utf8_RuneCount.h>
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

Void Go_utf8_RuneCount_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_p)
{
HX_STACK_PUSH("Go_utf8_RuneCount::new","tardis/Go.hx",3007);
{
	HX_STACK_LINE(3035)
	this->_Next = (int)0;
	HX_STACK_LINE(3034)
	this->_Phi = (int)0;
	HX_STACK_LINE(3033)
	this->_t16 = (int)0;
	HX_STACK_LINE(3032)
	this->_t15 = (int)0;
	HX_STACK_LINE(3031)
	this->_t13 = null();
	HX_STACK_LINE(3029)
	this->_t12 = null();
	HX_STACK_LINE(3028)
	this->_t11 = (int)0;
	HX_STACK_LINE(3027)
	this->_t10 = (int)0;
	HX_STACK_LINE(3026)
	this->_t9 = (int)0;
	HX_STACK_LINE(3025)
	this->_t8 = (int)0;
	HX_STACK_LINE(3024)
	this->_t7 = false;
	HX_STACK_LINE(3023)
	this->_t6 = (int)0;
	HX_STACK_LINE(3022)
	this->_t5 = (int)0;
	HX_STACK_LINE(3021)
	this->_t4 = (int)0;
	HX_STACK_LINE(3020)
	this->_t3 = (int)0;
	HX_STACK_LINE(3019)
	this->_t2 = false;
	HX_STACK_LINE(3018)
	this->_t1 = (int)0;
	HX_STACK_LINE(3017)
	this->_t0 = null();
	HX_STACK_LINE(3010)
	super::__construct(gr,(int)900,HX_CSTRING("Go_utf8_RuneCount"));
	HX_STACK_LINE(3011)
	this->_bds = _bds;
	HX_STACK_LINE(3012)
	this->p_p = p_p;
	HX_STACK_LINE(3013)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_RuneCount_obj::~Go_utf8_RuneCount_obj() { }

Dynamic Go_utf8_RuneCount_obj::__CreateEmpty() { return  new Go_utf8_RuneCount_obj; }
hx::ObjectPtr< Go_utf8_RuneCount_obj > Go_utf8_RuneCount_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_p)
{  hx::ObjectPtr< Go_utf8_RuneCount_obj > result = new Go_utf8_RuneCount_obj();
	result->__construct(gr,_bds,p_p);
	return result;}

Dynamic Go_utf8_RuneCount_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_RuneCount_obj > result = new Go_utf8_RuneCount_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_RuneCount_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_RuneCount_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_utf8_RuneCount::SubFn6","tardis/Go.hx",3138);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3140)
		this->_t15 = this->_t13->__Field(HX_CSTRING("r1"),true);
		HX_STACK_LINE(3141)
		this->_t16 = (this->_t3 + this->_t15);
		HX_STACK_LINE(3142)
		this->_Next = (int)5;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCount_obj,SubFn6,(void))

Void Go_utf8_RuneCount_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_utf8_RuneCount::SubFn5","tardis/Go.hx",3134);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3135)
		this->_latestPH = (int)907;
		HX_STACK_LINE(3136)
		this->_t12 = this->p_p->subSlice(this->_t3,(int)-1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCount_obj,SubFn5,(void))

Void Go_utf8_RuneCount_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_utf8_RuneCount::SubFn4","tardis/Go.hx",3130);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3131)
		this->_t11 = (this->_t4 + (int)1);
		HX_STACK_LINE(3132)
		this->_Next = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCount_obj,SubFn4,(void))

Void Go_utf8_RuneCount_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_utf8_RuneCount::SubFn3","tardis/Go.hx",3126);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3127)
		this->_t8 = (this->_t3 + (int)1);
		HX_STACK_LINE(3128)
		this->_Next = (int)5;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCount_obj,SubFn3,(void))

Void Go_utf8_RuneCount_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_utf8_RuneCount::SubFn2","tardis/Go.hx",3118);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3119)
		int _t6;		HX_STACK_VAR(_t6,"_t6");
		HX_STACK_LINE(3120)
		bool _t7;		HX_STACK_VAR(_t7,"_t7");
		HX_STACK_LINE(3121)
		this->_latestPH = (int)903;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf8_RuneCount_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3122);
				{
					HX_STACK_LINE(3122)
					::tardis::Slice _v = __this->p_p;		HX_STACK_VAR(_v,"_v");
					HX_STACK_LINE(3122)
					return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(3122)
		_t6 = _Function_1_1::Block(this);
		HX_STACK_LINE(3123)
		_t7 = (this->_t3 < _t6);
		HX_STACK_LINE(3124)
		this->_Next = (  ((_t7)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCount_obj,SubFn2,(void))

Void Go_utf8_RuneCount_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf8_RuneCount::SubFn1","tardis/Go.hx",3107);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3108)
		::tardis::Pointer _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(3109)
		int _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(3110)
		bool _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(3111)
		this->_latestPH = (int)904;
		struct _Function_1_1{
			inline static int Block( ::tardis::Go_utf8_RuneCount_obj *__this){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",3112);
				{
					HX_STACK_LINE(3112)
					::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(3112)
					return (_this->end - _this->start);
				}
				return null();
			}
		};
		HX_STACK_LINE(3112)
		if (((bool((this->_t3 < (int)0)) || bool((this->_t3 >= _Function_1_1::Block(this)))))){
			HX_STACK_LINE(3112)
			::tardis::Scheduler_obj::ioor();
		}
		HX_STACK_LINE(3113)
		_t0 = this->p_p->addr(this->_t3);
		HX_STACK_LINE(3114)
		_t1 = (int(_t0->ref()) | int((int)0));
		HX_STACK_LINE(3115)
		_t2 = (::tardis::Force_obj::uintCompare(_t1,(int)128) < (int)0);
		HX_STACK_LINE(3116)
		this->_Next = (  ((_t2)) ? int((int)4) : int((int)6) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCount_obj,SubFn1,(void))

Void Go_utf8_RuneCount_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_RuneCount::SubFn0","tardis/Go.hx",3104);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3104)
		this->_Next = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCount_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_RuneCount_obj::run( ){
	HX_STACK_PUSH("Go_utf8_RuneCount::run","tardis/Go.hx",3050);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3050)
	while((true)){
		HX_STACK_LINE(3052)
		::tardis::Go_utf8_RuneCount _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3052)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(3054)
				{
					HX_STACK_LINE(3054)
					this->_latestPH = (int)900;
					HX_STACK_LINE(3054)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(3055)
				this->_Next = (int)3;
				HX_STACK_LINE(3056)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(3058)
				{
					HX_STACK_LINE(3058)
					this->_latestPH = (int)900;
					HX_STACK_LINE(3058)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(3059)
				{
					HX_STACK_LINE(3059)
					::tardis::Pointer _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(3059)
					int _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(3059)
					bool _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(3059)
					this->_latestPH = (int)904;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf8_RuneCount_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3059);
							{
								HX_STACK_LINE(3059)
								::tardis::Slice _this = __this->p_p;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(3059)
								return (_this->end - _this->start);
							}
							return null();
						}
					};
					HX_STACK_LINE(3059)
					if (((bool((this->_t3 < (int)0)) || bool((this->_t3 >= _Function_4_1::Block(this)))))){
						HX_STACK_LINE(3059)
						::tardis::Scheduler_obj::ioor();
					}
					HX_STACK_LINE(3059)
					_t0 = this->p_p->addr(this->_t3);
					HX_STACK_LINE(3059)
					_t1 = (int(_t0->ref()) | int((int)0));
					HX_STACK_LINE(3059)
					_t2 = (::tardis::Force_obj::uintCompare(_t1,(int)128) < (int)0);
					HX_STACK_LINE(3059)
					this->_Next = (  ((_t2)) ? int((int)4) : int((int)6) );
				}
				HX_STACK_LINE(3060)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(3062)
				{
					HX_STACK_LINE(3062)
					this->_latestPH = (int)900;
					HX_STACK_LINE(3062)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(3063)
				this->_latestPH = (int)911;
				HX_STACK_LINE(3064)
				this->_res = this->_t4;
				HX_STACK_LINE(3065)
				this->_incomplete = false;
				HX_STACK_LINE(3066)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(3067)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(3070)
				{
					HX_STACK_LINE(3070)
					this->_latestPH = (int)911;
					HX_STACK_LINE(3070)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(3071)
				this->_latestPH = (int)901;
				HX_STACK_LINE(3072)
				this->_t3 = (  (((this->_Phi == (int)0))) ? int((int)0) : int((  (((this->_Phi == (int)5))) ? int(this->_t9) : int((int)0) )) );
				HX_STACK_LINE(3073)
				this->_latestPH = (int)902;
				HX_STACK_LINE(3074)
				this->_t4 = (  (((this->_Phi == (int)0))) ? int((int)0) : int((  (((this->_Phi == (int)5))) ? int(this->_t11) : int((int)0) )) );
				HX_STACK_LINE(3075)
				this->_latestPH = (int)907;
				HX_STACK_LINE(3076)
				this->_t5 = (  (((this->_Phi == (int)0))) ? int((int)0) : int((  (((this->_Phi == (int)5))) ? int(this->_t10) : int((int)0) )) );
				HX_STACK_LINE(3077)
				{
					HX_STACK_LINE(3077)
					int _t6;		HX_STACK_VAR(_t6,"_t6");
					HX_STACK_LINE(3077)
					bool _t7;		HX_STACK_VAR(_t7,"_t7");
					HX_STACK_LINE(3077)
					this->_latestPH = (int)903;
					struct _Function_4_1{
						inline static int Block( ::tardis::Go_utf8_RuneCount_obj *__this){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",3077);
							{
								HX_STACK_LINE(3077)
								::tardis::Slice _v = __this->p_p;		HX_STACK_VAR(_v,"_v");
								HX_STACK_LINE(3077)
								return (  (((_v == null()))) ? int((int)0) : int((_v->end - _v->start)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(3077)
					_t6 = _Function_4_1::Block(this);
					HX_STACK_LINE(3077)
					_t7 = (this->_t3 < _t6);
					HX_STACK_LINE(3077)
					this->_Next = (  ((_t7)) ? int((int)1) : int((int)2) );
				}
				HX_STACK_LINE(3078)
				this->_Phi = (int)3;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(3080)
				{
					HX_STACK_LINE(3080)
					this->_latestPH = (int)907;
					HX_STACK_LINE(3080)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(3081)
				{
					HX_STACK_LINE(3081)
					this->_t8 = (this->_t3 + (int)1);
					HX_STACK_LINE(3081)
					this->_Next = (int)5;
				}
				HX_STACK_LINE(3082)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(3084)
				{
					HX_STACK_LINE(3084)
					this->_latestPH = (int)907;
					HX_STACK_LINE(3084)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(3085)
				this->_latestPH = (int)901;
				HX_STACK_LINE(3086)
				this->_t9 = (  (((this->_Phi == (int)4))) ? int(this->_t8) : int((  (((this->_Phi == (int)6))) ? int(this->_t16) : int((int)0) )) );
				HX_STACK_LINE(3087)
				this->_latestPH = (int)907;
				HX_STACK_LINE(3088)
				this->_t10 = (  (((this->_Phi == (int)4))) ? int(this->_t5) : int((  (((this->_Phi == (int)6))) ? int(this->_t15) : int((int)0) )) );
				HX_STACK_LINE(3089)
				{
					HX_STACK_LINE(3089)
					this->_t11 = (this->_t4 + (int)1);
					HX_STACK_LINE(3089)
					this->_Next = (int)3;
				}
				HX_STACK_LINE(3090)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(3092)
				{
					HX_STACK_LINE(3092)
					this->_latestPH = (int)907;
					HX_STACK_LINE(3092)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(3093)
				{
					HX_STACK_LINE(3093)
					this->_latestPH = (int)907;
					HX_STACK_LINE(3093)
					this->_t12 = this->p_p->subSlice(this->_t3,(int)-1);
				}
				HX_STACK_LINE(3094)
				this->_SF1 = ::tardis::Go_utf8_DecodeRune_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->_t12);
				HX_STACK_LINE(3095)
				this->_Next = (int)-1;
				HX_STACK_LINE(3096)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(3098)
				{
					HX_STACK_LINE(3098)
					this->_latestPH = (int)907;
					HX_STACK_LINE(3098)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(3099)
				this->_t13 = this->_SF1->res();
				HX_STACK_LINE(3101)
				{
					HX_STACK_LINE(3101)
					this->_t15 = this->_t13->__Field(HX_CSTRING("r1"),true);
					HX_STACK_LINE(3101)
					this->_t16 = (this->_t3 + this->_t15);
					HX_STACK_LINE(3101)
					this->_Next = (int)5;
				}
				HX_STACK_LINE(3102)
				this->_Phi = (int)6;
			}
			;break;
			default: {
				HX_STACK_LINE(3103)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(3050)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCount_obj,run,return )

Dynamic Go_utf8_RuneCount_obj::res( ){
	HX_STACK_PUSH("Go_utf8_RuneCount::res","tardis/Go.hx",3016);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3016)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneCount_obj,res,return )

int Go_utf8_RuneCount_obj::callFromHaxe( ::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_RuneCount::callFromHaxe","tardis/Go.hx",3036);
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(3037)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(3037)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(3038)
	::tardis::Go_utf8_RuneCount _sf = hx::TCast< ::tardis::Go_utf8_RuneCount >::cast(::tardis::Go_utf8_RuneCount_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3039)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3039)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(3040)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_RuneCount_obj,callFromHaxe,return )

int Go_utf8_RuneCount_obj::callFromRT( int _gr,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_RuneCount::callFromRT","tardis/Go.hx",3042);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(3043)
	::tardis::Go_utf8_RuneCount _sf = hx::TCast< ::tardis::Go_utf8_RuneCount >::cast(::tardis::Go_utf8_RuneCount_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3044)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3044)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(3044)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(3044)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(3044)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(3045)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_RuneCount_obj,callFromRT,return )

::tardis::Go_utf8_RuneCount Go_utf8_RuneCount_obj::call( int gr,Dynamic _bds,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_RuneCount::call","tardis/Go.hx",3048);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(3048)
	return ::tardis::Go_utf8_RuneCount_obj::__new(gr,_bds,p_p);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_RuneCount_obj,call,return )


Go_utf8_RuneCount_obj::Go_utf8_RuneCount_obj()
{
}

void Go_utf8_RuneCount_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_RuneCount);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t16,"_t16");
	HX_MARK_MEMBER_NAME(_t15,"_t15");
	HX_MARK_MEMBER_NAME(_t13,"_t13");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
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
	HX_MARK_MEMBER_NAME(p_p,"p_p");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_RuneCount_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t16,"_t16");
	HX_VISIT_MEMBER_NAME(_t15,"_t15");
	HX_VISIT_MEMBER_NAME(_t13,"_t13");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
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
	HX_VISIT_MEMBER_NAME(p_p,"p_p");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_RuneCount_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_p") ) { return p_p; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_Phi") ) { return _Phi; }
		if (HX_FIELD_EQ(inName,"_t16") ) { return _t16; }
		if (HX_FIELD_EQ(inName,"_t15") ) { return _t15; }
		if (HX_FIELD_EQ(inName,"_t13") ) { return _t13; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
		if (HX_FIELD_EQ(inName,"_t12") ) { return _t12; }
		if (HX_FIELD_EQ(inName,"_t11") ) { return _t11; }
		if (HX_FIELD_EQ(inName,"_t10") ) { return _t10; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
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

Dynamic Go_utf8_RuneCount_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t9") ) { _t9=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t8") ) { _t8=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_p") ) { p_p=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t16") ) { _t16=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t15") ) { _t15=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t13") ) { _t13=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t12") ) { _t12=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t11") ) { _t11=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_RuneCount_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t16"));
	outFields->push(HX_CSTRING("_t15"));
	outFields->push(HX_CSTRING("_t13"));
	outFields->push(HX_CSTRING("_SF1"));
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
	outFields->push(HX_CSTRING("p_p"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
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
	HX_CSTRING("_t16"),
	HX_CSTRING("_t15"),
	HX_CSTRING("_t13"),
	HX_CSTRING("_SF1"),
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
	HX_CSTRING("p_p"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_RuneCount_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_RuneCount_obj::__mClass,"__mClass");
};

Class Go_utf8_RuneCount_obj::__mClass;

void Go_utf8_RuneCount_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_RuneCount"), hx::TCanCast< Go_utf8_RuneCount_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_RuneCount_obj::__boot()
{
}

} // end namespace tardis
