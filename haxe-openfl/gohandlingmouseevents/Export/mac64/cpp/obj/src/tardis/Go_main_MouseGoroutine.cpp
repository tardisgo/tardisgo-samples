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
#ifndef INCLUDED_tardis_Go_main_MouseGoroutine
#include <tardis/Go_main_MouseGoroutine.h>
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
#ifndef INCLUDED_tardis__Go_Go_main_handleMouse
#include <tardis/_Go/Go_main_handleMouse.h>
#endif
namespace tardis{

Void Go_main_MouseGoroutine_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_main_MouseGoroutine::new","tardis/Go.hx",6965);
{
	HX_STACK_LINE(6972)
	this->_Next = (int)0;
	HX_STACK_LINE(6967)
	super::__construct(gr,(int)20,HX_CSTRING("Go_main_MouseGoroutine"));
	HX_STACK_LINE(6968)
	this->_bds = _bds;
	HX_STACK_LINE(6969)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_main_MouseGoroutine_obj::~Go_main_MouseGoroutine_obj() { }

Dynamic Go_main_MouseGoroutine_obj::__CreateEmpty() { return  new Go_main_MouseGoroutine_obj; }
hx::ObjectPtr< Go_main_MouseGoroutine_obj > Go_main_MouseGoroutine_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_main_MouseGoroutine_obj > result = new Go_main_MouseGoroutine_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_main_MouseGoroutine_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_main_MouseGoroutine_obj > result = new Go_main_MouseGoroutine_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_main_MouseGoroutine_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_main_MouseGoroutine_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_main_MouseGoroutine::SubFn0","tardis/Go.hx",6996);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6997)
		this->_latestPH = (int)21;
		HX_STACK_LINE(6998)
		::tardis::_Go::Go_main_handleMouse_obj::__new(::tardis::Scheduler_obj::makeGoroutine(),Dynamic( Array_obj<Dynamic>::__new()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseGoroutine_obj,SubFn0,(void))

::tardis::StackFrame Go_main_MouseGoroutine_obj::run( ){
	HX_STACK_PUSH("Go_main_MouseGoroutine::run","tardis/Go.hx",6985);
	HX_STACK_THIS(this);
	HX_STACK_LINE(6985)
	while((true)){
		HX_STACK_LINE(6987)
		::tardis::Go_main_MouseGoroutine _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(6987)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(6989)
				{
					HX_STACK_LINE(6989)
					this->_latestPH = (int)20;
					HX_STACK_LINE(6989)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(6990)
				{
					HX_STACK_LINE(6990)
					this->_latestPH = (int)21;
					HX_STACK_LINE(6990)
					::tardis::_Go::Go_main_handleMouse_obj::__new(::tardis::Scheduler_obj::makeGoroutine(),Dynamic( Array_obj<Dynamic>::__new()));
				}
				HX_STACK_LINE(6991)
				this->_incomplete = false;
				HX_STACK_LINE(6992)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6993)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(6995)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(6985)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseGoroutine_obj,run,return )

Dynamic Go_main_MouseGoroutine_obj::res( ){
	HX_STACK_PUSH("Go_main_MouseGoroutine::res","tardis/Go.hx",6971);
	HX_STACK_THIS(this);
	HX_STACK_LINE(6971)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseGoroutine_obj,res,return )

Void Go_main_MouseGoroutine_obj::callFromHaxe( ){
{
		HX_STACK_PUSH("Go_main_MouseGoroutine::callFromHaxe","tardis/Go.hx",6973);
		HX_STACK_LINE(6974)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(6974)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(6975)
		::tardis::Go_main_MouseGoroutine _sf = hx::TCast< ::tardis::Go_main_MouseGoroutine >::cast(::tardis::Go_main_MouseGoroutine_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(6976)
		while((_sf->_incomplete)){
			HX_STACK_LINE(6976)
			::tardis::Scheduler_obj::runAll();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseGoroutine_obj,callFromHaxe,(void))

Void Go_main_MouseGoroutine_obj::callFromRT( int _gr){
{
		HX_STACK_PUSH("Go_main_MouseGoroutine::callFromRT","tardis/Go.hx",6978);
		HX_STACK_ARG(_gr,"_gr");
		HX_STACK_LINE(6979)
		::tardis::Go_main_MouseGoroutine _sf = hx::TCast< ::tardis::Go_main_MouseGoroutine >::cast(::tardis::Go_main_MouseGoroutine_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(6980)
		while((_sf->_incomplete)){
			HX_STACK_LINE(6980)
			if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
				HX_STACK_LINE(6980)
				hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
			}
			else{
				HX_STACK_LINE(6980)
				::tardis::Scheduler_obj::currentGR = _gr;
				HX_STACK_LINE(6980)
				::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_main_MouseGoroutine_obj,callFromRT,(void))

::tardis::Go_main_MouseGoroutine Go_main_MouseGoroutine_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_main_MouseGoroutine::call","tardis/Go.hx",6983);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(6983)
	return ::tardis::Go_main_MouseGoroutine_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_main_MouseGoroutine_obj,call,return )


Go_main_MouseGoroutine_obj::Go_main_MouseGoroutine_obj()
{
}

void Go_main_MouseGoroutine_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_main_MouseGoroutine);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_main_MouseGoroutine_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_main_MouseGoroutine_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
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

Dynamic Go_main_MouseGoroutine_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_main_MouseGoroutine_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
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
	HX_CSTRING("res"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_main_MouseGoroutine_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_main_MouseGoroutine_obj::__mClass,"__mClass");
};

Class Go_main_MouseGoroutine_obj::__mClass;

void Go_main_MouseGoroutine_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_main_MouseGoroutine"), hx::TCanCast< Go_main_MouseGoroutine_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_main_MouseGoroutine_obj::__boot()
{
}

} // end namespace tardis
