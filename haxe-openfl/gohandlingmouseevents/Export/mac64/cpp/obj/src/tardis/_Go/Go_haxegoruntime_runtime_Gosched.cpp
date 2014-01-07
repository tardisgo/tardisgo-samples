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
#ifndef INCLUDED_tardis__Go_Go_haxegoruntime_runtime_Gosched
#include <tardis/_Go/Go_haxegoruntime_runtime_Gosched.h>
#endif
namespace tardis{
namespace _Go{

Void Go_haxegoruntime_runtime_Gosched_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_haxegoruntime_runtime_Gosched::new","tardis/Go.hx",3577);
{
	HX_STACK_LINE(3584)
	this->_Next = (int)0;
	HX_STACK_LINE(3579)
	super::__construct(gr,(int)385,HX_CSTRING("Go_haxegoruntime_runtime_Gosched"));
	HX_STACK_LINE(3580)
	this->_bds = _bds;
	HX_STACK_LINE(3581)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_runtime_Gosched_obj::~Go_haxegoruntime_runtime_Gosched_obj() { }

Dynamic Go_haxegoruntime_runtime_Gosched_obj::__CreateEmpty() { return  new Go_haxegoruntime_runtime_Gosched_obj; }
hx::ObjectPtr< Go_haxegoruntime_runtime_Gosched_obj > Go_haxegoruntime_runtime_Gosched_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_haxegoruntime_runtime_Gosched_obj > result = new Go_haxegoruntime_runtime_Gosched_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_haxegoruntime_runtime_Gosched_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_runtime_Gosched_obj > result = new Go_haxegoruntime_runtime_Gosched_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_haxegoruntime_runtime_Gosched_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

::tardis::StackFrame Go_haxegoruntime_runtime_Gosched_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_runtime_Gosched::run","tardis/Go.hx",3597);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3597)
	while((true)){
		HX_STACK_LINE(3599)
		::tardis::_Go::Go_haxegoruntime_runtime_Gosched _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3599)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(3601)
				{
					HX_STACK_LINE(3601)
					this->_latestPH = (int)385;
					HX_STACK_LINE(3601)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(3602)
				this->_incomplete = false;
				HX_STACK_LINE(3603)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(3604)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(3606)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(3597)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_runtime_Gosched_obj,run,return )

Dynamic Go_haxegoruntime_runtime_Gosched_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_runtime_Gosched::res","tardis/Go.hx",3583);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3583)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_runtime_Gosched_obj,res,return )

Void Go_haxegoruntime_runtime_Gosched_obj::callFromHaxe( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_runtime_Gosched::callFromHaxe","tardis/Go.hx",3585);
		HX_STACK_LINE(3586)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(3586)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(3587)
		::tardis::_Go::Go_haxegoruntime_runtime_Gosched _sf = hx::TCast< ::tardis::_Go::Go_haxegoruntime_runtime_Gosched >::cast(::tardis::_Go::Go_haxegoruntime_runtime_Gosched_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(3588)
		while((_sf->_incomplete)){
			HX_STACK_LINE(3588)
			::tardis::Scheduler_obj::runAll();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_runtime_Gosched_obj,callFromHaxe,(void))

Void Go_haxegoruntime_runtime_Gosched_obj::callFromRT( int _gr){
{
		HX_STACK_PUSH("Go_haxegoruntime_runtime_Gosched::callFromRT","tardis/Go.hx",3590);
		HX_STACK_ARG(_gr,"_gr");
		HX_STACK_LINE(3591)
		::tardis::_Go::Go_haxegoruntime_runtime_Gosched _sf = hx::TCast< ::tardis::_Go::Go_haxegoruntime_runtime_Gosched >::cast(::tardis::_Go::Go_haxegoruntime_runtime_Gosched_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(3592)
		while((_sf->_incomplete)){
			HX_STACK_LINE(3592)
			if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
				HX_STACK_LINE(3592)
				hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
			}
			else{
				HX_STACK_LINE(3592)
				::tardis::Scheduler_obj::currentGR = _gr;
				HX_STACK_LINE(3592)
				::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_runtime_Gosched_obj,callFromRT,(void))

::tardis::_Go::Go_haxegoruntime_runtime_Gosched Go_haxegoruntime_runtime_Gosched_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_haxegoruntime_runtime_Gosched::call","tardis/Go.hx",3595);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(3595)
	return ::tardis::_Go::Go_haxegoruntime_runtime_Gosched_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_runtime_Gosched_obj,call,return )


Go_haxegoruntime_runtime_Gosched_obj::Go_haxegoruntime_runtime_Gosched_obj()
{
}

void Go_haxegoruntime_runtime_Gosched_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_runtime_Gosched);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_runtime_Gosched_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_runtime_Gosched_obj::__Field(const ::String &inName,bool inCallProp)
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
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_haxegoruntime_runtime_Gosched_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_runtime_Gosched_obj::__GetFields(Array< ::String> &outFields)
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
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("res"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_runtime_Gosched_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_runtime_Gosched_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_runtime_Gosched_obj::__mClass;

void Go_haxegoruntime_runtime_Gosched_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis._Go.Go_haxegoruntime_runtime_Gosched"), hx::TCanCast< Go_haxegoruntime_runtime_Gosched_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_runtime_Gosched_obj::__boot()
{
}

} // end namespace tardis
} // end namespace _Go
