#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_tardis_Channel
#include <tardis/Channel.h>
#endif
#ifndef INCLUDED_tardis_Go
#include <tardis/Go.h>
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
#ifndef INCLUDED_tardis_StackFrame
#include <tardis/StackFrame.h>
#endif
#ifndef INCLUDED_tardis_StackFrameBasis
#include <tardis/StackFrameBasis.h>
#endif
#ifndef INCLUDED_tardis__Go_Go_main_handleMouse
#include <tardis/_Go/Go_main_handleMouse.h>
#endif
namespace tardis{
namespace _Go{

Void Go_main_handleMouse_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_main_handleMouse::new","tardis/Go.hx",8338);
{
	HX_STACK_LINE(8354)
	this->_Next = (int)0;
	HX_STACK_LINE(8353)
	this->_Phi = (int)0;
	HX_STACK_LINE(8352)
	this->_t10 = false;
	HX_STACK_LINE(8351)
	this->_t7 = false;
	HX_STACK_LINE(8350)
	this->_t6 = false;
	HX_STACK_LINE(8349)
	this->_t5 = (int)0;
	HX_STACK_LINE(8348)
	this->_t4 = null();
	HX_STACK_LINE(8347)
	this->_t2 = false;
	HX_STACK_LINE(8346)
	this->_t1 = (int)0;
	HX_STACK_LINE(8345)
	this->_t0 = null();
	HX_STACK_LINE(8340)
	super::__construct(gr,(int)24,HX_CSTRING("Go_main_handleMouse"));
	HX_STACK_LINE(8341)
	this->_bds = _bds;
	HX_STACK_LINE(8342)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_main_handleMouse_obj::~Go_main_handleMouse_obj() { }

Dynamic Go_main_handleMouse_obj::__CreateEmpty() { return  new Go_main_handleMouse_obj; }
hx::ObjectPtr< Go_main_handleMouse_obj > Go_main_handleMouse_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_main_handleMouse_obj > result = new Go_main_handleMouse_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_main_handleMouse_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_main_handleMouse_obj > result = new Go_main_handleMouse_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_main_handleMouse_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_main_handleMouse_obj::SubFn9( ){
{
		HX_STACK_PUSH("Go_main_handleMouse::SubFn9","tardis/Go.hx",8458);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8459)
		bool _t10;		HX_STACK_VAR(_t10,"_t10");
		HX_STACK_LINE(8460)
		_t10 = (this->_t5 == (int)1);
		HX_STACK_LINE(8461)
		this->_Next = (  ((_t10)) ? int((int)6) : int((int)4) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,SubFn9,(void))

Void Go_main_handleMouse_obj::SubFn8( ){
{
		HX_STACK_PUSH("Go_main_handleMouse::SubFn8","tardis/Go.hx",8453);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8454)
		this->_latestPH = (int)35;
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",8455);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("fileName") , HX_CSTRING("Go.hx"),false);
					__result->Add(HX_CSTRING("lineNumber") , (int)8455,false);
					__result->Add(HX_CSTRING("className") , HX_CSTRING("tardis._Go.Go_main_handleMouse"),false);
					__result->Add(HX_CSTRING("methodName") , HX_CSTRING("SubFn8"),false);
					__result->Add(HX_CSTRING("customParams") , Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("MOUSE_UP"))),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(8455)
		::haxe::Log_obj::trace(::tardis::Go_obj::CPos((int)35),_Function_1_1::Block());
		HX_STACK_LINE(8456)
		this->_Next = (int)4;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,SubFn8,(void))

Void Go_main_handleMouse_obj::SubFn7( ){
{
		HX_STACK_PUSH("Go_main_handleMouse::SubFn7","tardis/Go.hx",8448);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8449)
		this->_latestPH = (int)33;
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",8450);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("fileName") , HX_CSTRING("Go.hx"),false);
					__result->Add(HX_CSTRING("lineNumber") , (int)8450,false);
					__result->Add(HX_CSTRING("className") , HX_CSTRING("tardis._Go.Go_main_handleMouse"),false);
					__result->Add(HX_CSTRING("methodName") , HX_CSTRING("SubFn7"),false);
					__result->Add(HX_CSTRING("customParams") , Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("MOUSE_MOVE"))),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(8450)
		::haxe::Log_obj::trace(::tardis::Go_obj::CPos((int)33),_Function_1_1::Block());
		HX_STACK_LINE(8451)
		this->_Next = (int)4;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,SubFn7,(void))

Void Go_main_handleMouse_obj::SubFn6( ){
{
		HX_STACK_PUSH("Go_main_handleMouse::SubFn6","tardis/Go.hx",8445);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8445)
		this->_Next = (  ((this->_t7)) ? int((int)3) : int((int)1) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,SubFn6,(void))

Void Go_main_handleMouse_obj::SubFn5( ){
{
		HX_STACK_PUSH("Go_main_handleMouse::SubFn5","tardis/Go.hx",8440);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8441)
		bool _t6;		HX_STACK_VAR(_t6,"_t6");
		HX_STACK_LINE(8442)
		_t6 = (this->_t5 == (int)3);
		HX_STACK_LINE(8443)
		this->_Next = (  ((_t6)) ? int((int)5) : int((int)7) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,SubFn5,(void))

Void Go_main_handleMouse_obj::SubFn4( ){
{
		HX_STACK_PUSH("Go_main_handleMouse::SubFn4","tardis/Go.hx",8437);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8437)
		this->_t4 = ::tardis::Go_obj::main_mouseEvents->ref();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,SubFn4,(void))

Void Go_main_handleMouse_obj::SubFn3( ){
{
		HX_STACK_PUSH("Go_main_handleMouse::SubFn3","tardis/Go.hx",8432);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8433)
		this->_latestPH = (int)28;
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",8434);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("fileName") , HX_CSTRING("Go.hx"),false);
					__result->Add(HX_CSTRING("lineNumber") , (int)8434,false);
					__result->Add(HX_CSTRING("className") , HX_CSTRING("tardis._Go.Go_main_handleMouse"),false);
					__result->Add(HX_CSTRING("methodName") , HX_CSTRING("SubFn3"),false);
					__result->Add(HX_CSTRING("customParams") , Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("MOUSE_DOWN"))),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(8434)
		::haxe::Log_obj::trace(::tardis::Go_obj::CPos((int)28),_Function_1_1::Block());
		HX_STACK_LINE(8435)
		this->_Next = (int)4;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,SubFn3,(void))

Void Go_main_handleMouse_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_main_handleMouse::SubFn2","tardis/Go.hx",8427);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8428)
		bool _t2;		HX_STACK_VAR(_t2,"_t2");
		HX_STACK_LINE(8429)
		_t2 = (this->_t1 == (int)2);
		HX_STACK_LINE(8430)
		this->_Next = (  ((_t2)) ? int((int)2) : int((int)1) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,SubFn2,(void))

Void Go_main_handleMouse_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_main_handleMouse::SubFn1","tardis/Go.hx",8424);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8424)
		this->_t0 = ::tardis::Go_obj::main_mouseEvents->ref();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,SubFn1,(void))

Void Go_main_handleMouse_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_main_handleMouse::SubFn0","tardis/Go.hx",8421);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8421)
		this->_Next = (int)1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,SubFn0,(void))

::tardis::StackFrame Go_main_handleMouse_obj::run( ){
	HX_STACK_PUSH("Go_main_handleMouse::run","tardis/Go.hx",8367);
	HX_STACK_THIS(this);
	HX_STACK_LINE(8367)
	while((true)){
		HX_STACK_LINE(8369)
		::tardis::_Go::Go_main_handleMouse _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(8369)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(8371)
				{
					HX_STACK_LINE(8371)
					this->_latestPH = (int)24;
					HX_STACK_LINE(8371)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(8372)
				this->_Next = (int)1;
				HX_STACK_LINE(8373)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(8375)
				{
					HX_STACK_LINE(8375)
					this->_latestPH = (int)24;
					HX_STACK_LINE(8375)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(8376)
				this->_t0 = ::tardis::Go_obj::main_mouseEvents->ref();
				HX_STACK_LINE(8377)
				this->_latestPH = (int)26;
				HX_STACK_LINE(8378)
				this->_Next = (int)-1;
				HX_STACK_LINE(8379)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(8381)
				{
					HX_STACK_LINE(8381)
					this->_latestPH = (int)26;
					HX_STACK_LINE(8381)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(8382)
				if ((this->_t0->hasNoContents())){
					HX_STACK_LINE(8382)
					return hx::ObjectPtr<OBJ_>(this);
				}
				HX_STACK_LINE(8383)
				this->_t1 = this->_t0->receive((int)0)->__Field(HX_CSTRING("r0"),true);
				HX_STACK_LINE(8384)
				{
					HX_STACK_LINE(8384)
					bool _t2;		HX_STACK_VAR(_t2,"_t2");
					HX_STACK_LINE(8384)
					_t2 = (this->_t1 == (int)2);
					HX_STACK_LINE(8384)
					this->_Next = (  ((_t2)) ? int((int)2) : int((int)1) );
				}
				HX_STACK_LINE(8385)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(8387)
				{
					HX_STACK_LINE(8387)
					this->_latestPH = (int)26;
					HX_STACK_LINE(8387)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(8388)
				{
					HX_STACK_LINE(8388)
					this->_latestPH = (int)28;
					struct _Function_4_1{
						inline static Dynamic Block( ){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",8388);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("fileName") , HX_CSTRING("Go.hx"),false);
								__result->Add(HX_CSTRING("lineNumber") , (int)8434,false);
								__result->Add(HX_CSTRING("className") , HX_CSTRING("tardis._Go.Go_main_handleMouse"),false);
								__result->Add(HX_CSTRING("methodName") , HX_CSTRING("SubFn3"),false);
								__result->Add(HX_CSTRING("customParams") , Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("MOUSE_DOWN"))),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(8388)
					::haxe::Log_obj::trace(::tardis::Go_obj::CPos((int)28),_Function_4_1::Block());
					HX_STACK_LINE(8388)
					this->_Next = (int)4;
				}
				HX_STACK_LINE(8389)
				this->_Phi = (int)2;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(8391)
				{
					HX_STACK_LINE(8391)
					this->_latestPH = (int)26;
					HX_STACK_LINE(8391)
					this->_latestBlock = (int)3;
				}
				HX_STACK_LINE(8392)
				this->_t4 = ::tardis::Go_obj::main_mouseEvents->ref();
				HX_STACK_LINE(8393)
				this->_latestPH = (int)31;
				HX_STACK_LINE(8394)
				this->_Next = (int)-2;
				HX_STACK_LINE(8395)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-2: {
				HX_STACK_LINE(8397)
				{
					HX_STACK_LINE(8397)
					this->_latestPH = (int)31;
					HX_STACK_LINE(8397)
					this->_latestBlock = (int)-2;
				}
				HX_STACK_LINE(8398)
				if ((this->_t4->hasNoContents())){
					HX_STACK_LINE(8398)
					return hx::ObjectPtr<OBJ_>(this);
				}
				HX_STACK_LINE(8399)
				this->_t5 = this->_t4->receive((int)0)->__Field(HX_CSTRING("r0"),true);
				HX_STACK_LINE(8400)
				{
					HX_STACK_LINE(8400)
					bool _t6;		HX_STACK_VAR(_t6,"_t6");
					HX_STACK_LINE(8400)
					_t6 = (this->_t5 == (int)3);
					HX_STACK_LINE(8400)
					this->_Next = (  ((_t6)) ? int((int)5) : int((int)7) );
				}
				HX_STACK_LINE(8401)
				this->_Phi = (int)3;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(8403)
				{
					HX_STACK_LINE(8403)
					this->_latestPH = (int)31;
					HX_STACK_LINE(8403)
					this->_latestBlock = (int)4;
				}
				HX_STACK_LINE(8404)
				this->_latestPH = (int)29;
				HX_STACK_LINE(8405)
				this->_t7 = (  (((this->_Phi == (int)2))) ? bool(true) : bool((  (((this->_Phi == (int)5))) ? bool(this->_t7) : bool((  (((this->_Phi == (int)6))) ? bool(false) : bool((  (((this->_Phi == (int)7))) ? bool(this->_t7) : bool(false) )) )) )) );
				HX_STACK_LINE(8406)
				this->_Next = (  ((this->_t7)) ? int((int)3) : int((int)1) );
				HX_STACK_LINE(8407)
				this->_Phi = (int)4;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(8409)
				{
					HX_STACK_LINE(8409)
					this->_latestPH = (int)29;
					HX_STACK_LINE(8409)
					this->_latestBlock = (int)5;
				}
				HX_STACK_LINE(8410)
				{
					HX_STACK_LINE(8410)
					this->_latestPH = (int)33;
					struct _Function_4_1{
						inline static Dynamic Block( ){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",8410);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("fileName") , HX_CSTRING("Go.hx"),false);
								__result->Add(HX_CSTRING("lineNumber") , (int)8450,false);
								__result->Add(HX_CSTRING("className") , HX_CSTRING("tardis._Go.Go_main_handleMouse"),false);
								__result->Add(HX_CSTRING("methodName") , HX_CSTRING("SubFn7"),false);
								__result->Add(HX_CSTRING("customParams") , Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("MOUSE_MOVE"))),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(8410)
					::haxe::Log_obj::trace(::tardis::Go_obj::CPos((int)33),_Function_4_1::Block());
					HX_STACK_LINE(8410)
					this->_Next = (int)4;
				}
				HX_STACK_LINE(8411)
				this->_Phi = (int)5;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(8413)
				{
					HX_STACK_LINE(8413)
					this->_latestPH = (int)29;
					HX_STACK_LINE(8413)
					this->_latestBlock = (int)6;
				}
				HX_STACK_LINE(8414)
				{
					HX_STACK_LINE(8414)
					this->_latestPH = (int)35;
					struct _Function_4_1{
						inline static Dynamic Block( ){
							HX_STACK_PUSH("*::closure","tardis/Go.hx",8414);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("fileName") , HX_CSTRING("Go.hx"),false);
								__result->Add(HX_CSTRING("lineNumber") , (int)8455,false);
								__result->Add(HX_CSTRING("className") , HX_CSTRING("tardis._Go.Go_main_handleMouse"),false);
								__result->Add(HX_CSTRING("methodName") , HX_CSTRING("SubFn8"),false);
								__result->Add(HX_CSTRING("customParams") , Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("MOUSE_UP"))),false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(8414)
					::haxe::Log_obj::trace(::tardis::Go_obj::CPos((int)35),_Function_4_1::Block());
					HX_STACK_LINE(8414)
					this->_Next = (int)4;
				}
				HX_STACK_LINE(8415)
				this->_Phi = (int)6;
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(8417)
				{
					HX_STACK_LINE(8417)
					this->_latestPH = (int)29;
					HX_STACK_LINE(8417)
					this->_latestBlock = (int)7;
				}
				HX_STACK_LINE(8418)
				{
					HX_STACK_LINE(8418)
					bool _t10;		HX_STACK_VAR(_t10,"_t10");
					HX_STACK_LINE(8418)
					_t10 = (this->_t5 == (int)1);
					HX_STACK_LINE(8418)
					this->_Next = (  ((_t10)) ? int((int)6) : int((int)4) );
				}
				HX_STACK_LINE(8419)
				this->_Phi = (int)7;
			}
			;break;
			default: {
				HX_STACK_LINE(8420)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(8367)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,run,return )

Dynamic Go_main_handleMouse_obj::res( ){
	HX_STACK_PUSH("Go_main_handleMouse::res","tardis/Go.hx",8344);
	HX_STACK_THIS(this);
	HX_STACK_LINE(8344)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,res,return )

Void Go_main_handleMouse_obj::callFromHaxe( ){
{
		HX_STACK_PUSH("Go_main_handleMouse::callFromHaxe","tardis/Go.hx",8355);
		HX_STACK_LINE(8356)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(8356)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(8357)
		::tardis::_Go::Go_main_handleMouse _sf = hx::TCast< ::tardis::_Go::Go_main_handleMouse >::cast(::tardis::_Go::Go_main_handleMouse_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(8358)
		while((_sf->_incomplete)){
			HX_STACK_LINE(8358)
			::tardis::Scheduler_obj::runAll();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_main_handleMouse_obj,callFromHaxe,(void))

Void Go_main_handleMouse_obj::callFromRT( int _gr){
{
		HX_STACK_PUSH("Go_main_handleMouse::callFromRT","tardis/Go.hx",8360);
		HX_STACK_ARG(_gr,"_gr");
		HX_STACK_LINE(8361)
		::tardis::_Go::Go_main_handleMouse _sf = hx::TCast< ::tardis::_Go::Go_main_handleMouse >::cast(::tardis::_Go::Go_main_handleMouse_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(8362)
		while((_sf->_incomplete)){
			HX_STACK_LINE(8362)
			if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
				HX_STACK_LINE(8362)
				hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
			}
			else{
				HX_STACK_LINE(8362)
				::tardis::Scheduler_obj::currentGR = _gr;
				HX_STACK_LINE(8362)
				::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_main_handleMouse_obj,callFromRT,(void))

::tardis::_Go::Go_main_handleMouse Go_main_handleMouse_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_main_handleMouse::call","tardis/Go.hx",8365);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(8365)
	return ::tardis::_Go::Go_main_handleMouse_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_main_handleMouse_obj,call,return )


Go_main_handleMouse_obj::Go_main_handleMouse_obj()
{
}

void Go_main_handleMouse_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_main_handleMouse);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t10,"_t10");
	HX_MARK_MEMBER_NAME(_t7,"_t7");
	HX_MARK_MEMBER_NAME(_t6,"_t6");
	HX_MARK_MEMBER_NAME(_t5,"_t5");
	HX_MARK_MEMBER_NAME(_t4,"_t4");
	HX_MARK_MEMBER_NAME(_t2,"_t2");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_main_handleMouse_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t10,"_t10");
	HX_VISIT_MEMBER_NAME(_t7,"_t7");
	HX_VISIT_MEMBER_NAME(_t6,"_t6");
	HX_VISIT_MEMBER_NAME(_t5,"_t5");
	HX_VISIT_MEMBER_NAME(_t4,"_t4");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_main_handleMouse_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t7") ) { return _t7; }
		if (HX_FIELD_EQ(inName,"_t6") ) { return _t6; }
		if (HX_FIELD_EQ(inName,"_t5") ) { return _t5; }
		if (HX_FIELD_EQ(inName,"_t4") ) { return _t4; }
		if (HX_FIELD_EQ(inName,"_t2") ) { return _t2; }
		if (HX_FIELD_EQ(inName,"_t1") ) { return _t1; }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_Phi") ) { return _Phi; }
		if (HX_FIELD_EQ(inName,"_t10") ) { return _t10; }
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
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_main_handleMouse_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t7") ) { _t7=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t6") ) { _t6=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t5") ) { _t5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< ::tardis::Channel >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Channel >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t10") ) { _t10=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_main_handleMouse_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t10"));
	outFields->push(HX_CSTRING("_t7"));
	outFields->push(HX_CSTRING("_t6"));
	outFields->push(HX_CSTRING("_t5"));
	outFields->push(HX_CSTRING("_t4"));
	outFields->push(HX_CSTRING("_t2"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
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
	HX_CSTRING("_t10"),
	HX_CSTRING("_t7"),
	HX_CSTRING("_t6"),
	HX_CSTRING("_t5"),
	HX_CSTRING("_t4"),
	HX_CSTRING("_t2"),
	HX_CSTRING("_t1"),
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_main_handleMouse_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_main_handleMouse_obj::__mClass,"__mClass");
};

Class Go_main_handleMouse_obj::__mClass;

void Go_main_handleMouse_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis._Go.Go_main_handleMouse"), hx::TCanCast< Go_main_handleMouse_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_main_handleMouse_obj::__boot()
{
}

} // end namespace tardis
} // end namespace _Go
