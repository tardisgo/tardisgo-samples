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
#ifndef INCLUDED_tardis_Go_haxegoruntime_Goexit
#include <tardis/Go_haxegoruntime_Goexit.h>
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

Void Go_haxegoruntime_Goexit_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_haxegoruntime_Goexit::new","tardis/Go.hx",5805);
{
	HX_STACK_LINE(5813)
	this->_Next = (int)0;
	HX_STACK_LINE(5812)
	this->_t0 = null();
	HX_STACK_LINE(5807)
	super::__construct(gr,(int)392,HX_CSTRING("Go_haxegoruntime_Goexit"));
	HX_STACK_LINE(5808)
	this->_bds = _bds;
	HX_STACK_LINE(5809)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_Goexit_obj::~Go_haxegoruntime_Goexit_obj() { }

Dynamic Go_haxegoruntime_Goexit_obj::__CreateEmpty() { return  new Go_haxegoruntime_Goexit_obj; }
hx::ObjectPtr< Go_haxegoruntime_Goexit_obj > Go_haxegoruntime_Goexit_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_haxegoruntime_Goexit_obj > result = new Go_haxegoruntime_Goexit_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_haxegoruntime_Goexit_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_Goexit_obj > result = new Go_haxegoruntime_Goexit_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_haxegoruntime_Goexit_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_Goexit_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Goexit::SubFn0","tardis/Go.hx",5841);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5841)
		this->_t0 = ::tardis::Interface_obj::__new((int)0,HX_CSTRING("runtime.Goexit() not yet implemented"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Goexit_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_Goexit_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_Goexit::run","tardis/Go.hx",5826);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5826)
	while((true)){
		HX_STACK_LINE(5828)
		::tardis::Go_haxegoruntime_Goexit _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5828)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5830)
				{
					HX_STACK_LINE(5830)
					this->_latestPH = (int)392;
					HX_STACK_LINE(5830)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5831)
				this->_t0 = ::tardis::Interface_obj::__new((int)0,HX_CSTRING("runtime.Goexit() not yet implemented"));
				HX_STACK_LINE(5832)
				::tardis::Scheduler_obj::panic(this->_goroutine,this->_t0);
				HX_STACK_LINE(5832)
				this->_Next = (int)-1;
				HX_STACK_LINE(5833)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(5835)
				{
					HX_STACK_LINE(5835)
					this->_latestPH = (int)392;
					HX_STACK_LINE(5835)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(5838)
				this->_incomplete = false;
				HX_STACK_LINE(5839)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5840)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(5840)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5826)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Goexit_obj,run,return )

Dynamic Go_haxegoruntime_Goexit_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_Goexit::res","tardis/Go.hx",5811);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5811)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Goexit_obj,res,return )

Void Go_haxegoruntime_Goexit_obj::callFromHaxe( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Goexit::callFromHaxe","tardis/Go.hx",5814);
		HX_STACK_LINE(5815)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(5815)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(5816)
		::tardis::Go_haxegoruntime_Goexit _sf = hx::TCast< ::tardis::Go_haxegoruntime_Goexit >::cast(::tardis::Go_haxegoruntime_Goexit_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(5817)
		while((_sf->_incomplete)){
			HX_STACK_LINE(5817)
			::tardis::Scheduler_obj::runAll();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Goexit_obj,callFromHaxe,(void))

Void Go_haxegoruntime_Goexit_obj::callFromRT( int _gr){
{
		HX_STACK_PUSH("Go_haxegoruntime_Goexit::callFromRT","tardis/Go.hx",5819);
		HX_STACK_ARG(_gr,"_gr");
		HX_STACK_LINE(5820)
		::tardis::Go_haxegoruntime_Goexit _sf = hx::TCast< ::tardis::Go_haxegoruntime_Goexit >::cast(::tardis::Go_haxegoruntime_Goexit_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(5821)
		while((_sf->_incomplete)){
			HX_STACK_LINE(5821)
			if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
				HX_STACK_LINE(5821)
				hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
			}
			else{
				HX_STACK_LINE(5821)
				::tardis::Scheduler_obj::currentGR = _gr;
				HX_STACK_LINE(5821)
				::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_Goexit_obj,callFromRT,(void))

::tardis::Go_haxegoruntime_Goexit Go_haxegoruntime_Goexit_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_haxegoruntime_Goexit::call","tardis/Go.hx",5824);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(5824)
	return ::tardis::Go_haxegoruntime_Goexit_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_Goexit_obj,call,return )


Go_haxegoruntime_Goexit_obj::Go_haxegoruntime_Goexit_obj()
{
}

void Go_haxegoruntime_Goexit_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_Goexit);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_Goexit_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_Goexit_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
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

Dynamic Go_haxegoruntime_Goexit_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_Goexit_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
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
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_Goexit_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_Goexit_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_Goexit_obj::__mClass;

void Go_haxegoruntime_Goexit_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_Goexit"), hx::TCanCast< Go_haxegoruntime_Goexit_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_Goexit_obj::__boot()
{
}

} // end namespace tardis
