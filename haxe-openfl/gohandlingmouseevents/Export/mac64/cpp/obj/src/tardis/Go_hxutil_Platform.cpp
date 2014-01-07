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
#ifndef INCLUDED_tardis_Go_hxutil_Platform
#include <tardis/Go_hxutil_Platform.h>
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
namespace tardis{

Void Go_hxutil_Platform_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_hxutil_Platform::new","tardis/Go.hx",2677);
{
	HX_STACK_LINE(2685)
	this->_Next = (int)0;
	HX_STACK_LINE(2679)
	super::__construct(gr,(int)993,HX_CSTRING("Go_hxutil_Platform"));
	HX_STACK_LINE(2680)
	this->_bds = _bds;
	HX_STACK_LINE(2681)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_hxutil_Platform_obj::~Go_hxutil_Platform_obj() { }

Dynamic Go_hxutil_Platform_obj::__CreateEmpty() { return  new Go_hxutil_Platform_obj; }
hx::ObjectPtr< Go_hxutil_Platform_obj > Go_hxutil_Platform_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_hxutil_Platform_obj > result = new Go_hxutil_Platform_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_hxutil_Platform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_hxutil_Platform_obj > result = new Go_hxutil_Platform_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_hxutil_Platform_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

::tardis::StackFrame Go_hxutil_Platform_obj::run( ){
	HX_STACK_PUSH("Go_hxutil_Platform::run","tardis/Go.hx",2700);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2700)
	while((true)){
		HX_STACK_LINE(2702)
		::tardis::Go_hxutil_Platform _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(2702)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(2704)
				{
					HX_STACK_LINE(2704)
					this->_latestPH = (int)993;
					HX_STACK_LINE(2704)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(2705)
				this->_res = HX_CSTRING("go");
				HX_STACK_LINE(2706)
				this->_incomplete = false;
				HX_STACK_LINE(2707)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(2708)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(2710)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(2700)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_Platform_obj,run,return )

Dynamic Go_hxutil_Platform_obj::res( ){
	HX_STACK_PUSH("Go_hxutil_Platform::res","tardis/Go.hx",2684);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2684)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_Platform_obj,res,return )

::String Go_hxutil_Platform_obj::callFromHaxe( ){
	HX_STACK_PUSH("Go_hxutil_Platform::callFromHaxe","tardis/Go.hx",2686);
	HX_STACK_LINE(2687)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(2687)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(2688)
	::tardis::Go_hxutil_Platform _sf = hx::TCast< ::tardis::Go_hxutil_Platform >::cast(::tardis::Go_hxutil_Platform_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(2689)
	while((_sf->_incomplete)){
		HX_STACK_LINE(2689)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(2690)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_Platform_obj,callFromHaxe,return )

::String Go_hxutil_Platform_obj::callFromRT( int _gr){
	HX_STACK_PUSH("Go_hxutil_Platform::callFromRT","tardis/Go.hx",2692);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_LINE(2693)
	::tardis::Go_hxutil_Platform _sf = hx::TCast< ::tardis::Go_hxutil_Platform >::cast(::tardis::Go_hxutil_Platform_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(2694)
	while((_sf->_incomplete)){
		HX_STACK_LINE(2694)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(2694)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(2694)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(2694)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(2695)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_hxutil_Platform_obj,callFromRT,return )

::tardis::Go_hxutil_Platform Go_hxutil_Platform_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_hxutil_Platform::call","tardis/Go.hx",2698);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(2698)
	return ::tardis::Go_hxutil_Platform_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_hxutil_Platform_obj,call,return )


Go_hxutil_Platform_obj::Go_hxutil_Platform_obj()
{
}

void Go_hxutil_Platform_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_hxutil_Platform);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_res,"_res");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_hxutil_Platform_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_hxutil_Platform_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_hxutil_Platform_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_hxutil_Platform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_res"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_hxutil_Platform_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_hxutil_Platform_obj::__mClass,"__mClass");
};

Class Go_hxutil_Platform_obj::__mClass;

void Go_hxutil_Platform_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_hxutil_Platform"), hx::TCanCast< Go_hxutil_Platform_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_hxutil_Platform_obj::__boot()
{
}

} // end namespace tardis
