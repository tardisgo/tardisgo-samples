#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_tardis_Go
#include <tardis/Go.h>
#endif
#ifndef INCLUDED_tardis_Interface
#include <tardis/Interface.h>
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
#ifndef INCLUDED_tardis__Go_Go_haxegoruntime_getgoroot
#include <tardis/_Go/Go_haxegoruntime_getgoroot.h>
#endif
namespace tardis{
namespace _Go{

Void Go_haxegoruntime_getgoroot_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_haxegoruntime_getgoroot::new","tardis/Go.hx",2085);
{
	HX_STACK_LINE(2094)
	this->_Next = (int)0;
	HX_STACK_LINE(2093)
	this->_t0 = null();
	HX_STACK_LINE(2087)
	super::__construct(gr,(int)418,HX_CSTRING("Go_haxegoruntime_getgoroot"));
	HX_STACK_LINE(2088)
	this->_bds = _bds;
	HX_STACK_LINE(2089)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_getgoroot_obj::~Go_haxegoruntime_getgoroot_obj() { }

Dynamic Go_haxegoruntime_getgoroot_obj::__CreateEmpty() { return  new Go_haxegoruntime_getgoroot_obj; }
hx::ObjectPtr< Go_haxegoruntime_getgoroot_obj > Go_haxegoruntime_getgoroot_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_haxegoruntime_getgoroot_obj > result = new Go_haxegoruntime_getgoroot_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_haxegoruntime_getgoroot_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_getgoroot_obj > result = new Go_haxegoruntime_getgoroot_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_haxegoruntime_getgoroot_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_getgoroot_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_getgoroot::SubFn0","tardis/Go.hx",2125);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2125)
		this->_t0 = ::tardis::Interface_obj::__new((int)0,HX_CSTRING("runtime.getgoroot() not yet implemented"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_getgoroot_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_getgoroot_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_getgoroot::run","tardis/Go.hx",2109);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2109)
	while((true)){
		HX_STACK_LINE(2111)
		::tardis::_Go::Go_haxegoruntime_getgoroot _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(2111)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(2113)
				{
					HX_STACK_LINE(2113)
					this->_latestPH = (int)418;
					HX_STACK_LINE(2113)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(2114)
				this->_t0 = ::tardis::Interface_obj::__new((int)0,HX_CSTRING("runtime.getgoroot() not yet implemented"));
				HX_STACK_LINE(2115)
				this->_latestPH = (int)419;
				HX_STACK_LINE(2116)
				::tardis::Scheduler_obj::panic(this->_goroutine,this->_t0);
				HX_STACK_LINE(2116)
				this->_Next = (int)-1;
				HX_STACK_LINE(2117)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(2119)
				{
					HX_STACK_LINE(2119)
					this->_latestPH = (int)419;
					HX_STACK_LINE(2119)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(2122)
				this->_incomplete = false;
				HX_STACK_LINE(2123)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(2124)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(2124)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(2109)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_getgoroot_obj,run,return )

Dynamic Go_haxegoruntime_getgoroot_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_getgoroot::res","tardis/Go.hx",2092);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2092)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_getgoroot_obj,res,return )

::String Go_haxegoruntime_getgoroot_obj::callFromHaxe( ){
	HX_STACK_PUSH("Go_haxegoruntime_getgoroot::callFromHaxe","tardis/Go.hx",2095);
	HX_STACK_LINE(2096)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(2096)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(2097)
	::tardis::_Go::Go_haxegoruntime_getgoroot _sf = hx::TCast< ::tardis::_Go::Go_haxegoruntime_getgoroot >::cast(::tardis::_Go::Go_haxegoruntime_getgoroot_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(2098)
	while((_sf->_incomplete)){
		HX_STACK_LINE(2098)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(2099)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_getgoroot_obj,callFromHaxe,return )

::String Go_haxegoruntime_getgoroot_obj::callFromRT( int _gr){
	HX_STACK_PUSH("Go_haxegoruntime_getgoroot::callFromRT","tardis/Go.hx",2101);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_LINE(2102)
	::tardis::_Go::Go_haxegoruntime_getgoroot _sf = hx::TCast< ::tardis::_Go::Go_haxegoruntime_getgoroot >::cast(::tardis::_Go::Go_haxegoruntime_getgoroot_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(2103)
	while((_sf->_incomplete)){
		HX_STACK_LINE(2103)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(2103)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(2103)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(2103)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(2104)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_getgoroot_obj,callFromRT,return )

::tardis::_Go::Go_haxegoruntime_getgoroot Go_haxegoruntime_getgoroot_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_haxegoruntime_getgoroot::call","tardis/Go.hx",2107);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(2107)
	return ::tardis::_Go::Go_haxegoruntime_getgoroot_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_getgoroot_obj,call,return )


Go_haxegoruntime_getgoroot_obj::Go_haxegoruntime_getgoroot_obj()
{
}

void Go_haxegoruntime_getgoroot_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_getgoroot);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_getgoroot_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_getgoroot_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
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

Dynamic Go_haxegoruntime_getgoroot_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_getgoroot_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("SubFn0"),
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_getgoroot_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_getgoroot_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_getgoroot_obj::__mClass;

void Go_haxegoruntime_getgoroot_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis._Go.Go_haxegoruntime_getgoroot"), hx::TCanCast< Go_haxegoruntime_getgoroot_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_getgoroot_obj::__boot()
{
}

} // end namespace tardis
} // end namespace _Go
