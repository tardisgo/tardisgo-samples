#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_tardis_Channel
#include <tardis/Channel.h>
#endif
#ifndef INCLUDED_tardis_Go
#include <tardis/Go.h>
#endif
#ifndef INCLUDED_tardis_Go_main_MouseMove
#include <tardis/Go_main_MouseMove.h>
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
namespace tardis{

Void Go_main_MouseMove_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_main_MouseMove::new","tardis/Go.hx",4018);
{
	HX_STACK_LINE(4026)
	this->_Next = (int)0;
	HX_STACK_LINE(4025)
	this->_t0 = null();
	HX_STACK_LINE(4020)
	super::__construct(gr,(int)18,HX_CSTRING("Go_main_MouseMove"));
	HX_STACK_LINE(4021)
	this->_bds = _bds;
	HX_STACK_LINE(4022)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_main_MouseMove_obj::~Go_main_MouseMove_obj() { }

Dynamic Go_main_MouseMove_obj::__CreateEmpty() { return  new Go_main_MouseMove_obj; }
hx::ObjectPtr< Go_main_MouseMove_obj > Go_main_MouseMove_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_main_MouseMove_obj > result = new Go_main_MouseMove_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_main_MouseMove_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_main_MouseMove_obj > result = new Go_main_MouseMove_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_main_MouseMove_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_main_MouseMove_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_main_MouseMove::SubFn0","tardis/Go.hx",4056);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4056)
		this->_t0 = ::tardis::Go_obj::main_mouseEvents->ref();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseMove_obj,SubFn0,(void))

::tardis::StackFrame Go_main_MouseMove_obj::run( ){
	HX_STACK_PUSH("Go_main_MouseMove::run","tardis/Go.hx",4039);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4039)
	while((true)){
		HX_STACK_LINE(4041)
		::tardis::Go_main_MouseMove _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(4041)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(4043)
				{
					HX_STACK_LINE(4043)
					this->_latestPH = (int)18;
					HX_STACK_LINE(4043)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(4044)
				this->_t0 = ::tardis::Go_obj::main_mouseEvents->ref();
				HX_STACK_LINE(4045)
				this->_Next = (int)-1;
				HX_STACK_LINE(4046)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(4048)
				{
					HX_STACK_LINE(4048)
					this->_latestPH = (int)18;
					HX_STACK_LINE(4048)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(4049)
				if ((!(this->_t0->hasSpace()))){
					HX_STACK_LINE(4049)
					return hx::ObjectPtr<OBJ_>(this);
				}
				HX_STACK_LINE(4050)
				this->_t0->send((int)3);
				HX_STACK_LINE(4051)
				this->_incomplete = false;
				HX_STACK_LINE(4052)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4053)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(4055)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(4039)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseMove_obj,run,return )

Dynamic Go_main_MouseMove_obj::res( ){
	HX_STACK_PUSH("Go_main_MouseMove::res","tardis/Go.hx",4024);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4024)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseMove_obj,res,return )

Void Go_main_MouseMove_obj::callFromHaxe( ){
{
		HX_STACK_PUSH("Go_main_MouseMove::callFromHaxe","tardis/Go.hx",4027);
		HX_STACK_LINE(4028)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(4028)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(4029)
		::tardis::Go_main_MouseMove _sf = hx::TCast< ::tardis::Go_main_MouseMove >::cast(::tardis::Go_main_MouseMove_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(4030)
		while((_sf->_incomplete)){
			HX_STACK_LINE(4030)
			::tardis::Scheduler_obj::runAll();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseMove_obj,callFromHaxe,(void))

Void Go_main_MouseMove_obj::callFromRT( int _gr){
{
		HX_STACK_PUSH("Go_main_MouseMove::callFromRT","tardis/Go.hx",4032);
		HX_STACK_ARG(_gr,"_gr");
		HX_STACK_LINE(4033)
		::tardis::Go_main_MouseMove _sf = hx::TCast< ::tardis::Go_main_MouseMove >::cast(::tardis::Go_main_MouseMove_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(4034)
		while((_sf->_incomplete)){
			HX_STACK_LINE(4034)
			if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
				HX_STACK_LINE(4034)
				hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
			}
			else{
				HX_STACK_LINE(4034)
				::tardis::Scheduler_obj::currentGR = _gr;
				HX_STACK_LINE(4034)
				::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_main_MouseMove_obj,callFromRT,(void))

::tardis::Go_main_MouseMove Go_main_MouseMove_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_main_MouseMove::call","tardis/Go.hx",4037);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(4037)
	return ::tardis::Go_main_MouseMove_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_main_MouseMove_obj,call,return )


Go_main_MouseMove_obj::Go_main_MouseMove_obj()
{
}

void Go_main_MouseMove_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_main_MouseMove);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_main_MouseMove_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_main_MouseMove_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Go_main_MouseMove_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Channel >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_main_MouseMove_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Go_main_MouseMove_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_main_MouseMove_obj::__mClass,"__mClass");
};

Class Go_main_MouseMove_obj::__mClass;

void Go_main_MouseMove_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_main_MouseMove"), hx::TCanCast< Go_main_MouseMove_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_main_MouseMove_obj::__boot()
{
}

} // end namespace tardis
