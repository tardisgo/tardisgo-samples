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
#ifndef INCLUDED_tardis_Go_main_MouseUp
#include <tardis/Go_main_MouseUp.h>
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

Void Go_main_MouseUp_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_main_MouseUp::new","tardis/Go.hx",5096);
{
	HX_STACK_LINE(5104)
	this->_Next = (int)0;
	HX_STACK_LINE(5103)
	this->_t0 = null();
	HX_STACK_LINE(5098)
	super::__construct(gr,(int)16,HX_CSTRING("Go_main_MouseUp"));
	HX_STACK_LINE(5099)
	this->_bds = _bds;
	HX_STACK_LINE(5100)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_main_MouseUp_obj::~Go_main_MouseUp_obj() { }

Dynamic Go_main_MouseUp_obj::__CreateEmpty() { return  new Go_main_MouseUp_obj; }
hx::ObjectPtr< Go_main_MouseUp_obj > Go_main_MouseUp_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_main_MouseUp_obj > result = new Go_main_MouseUp_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_main_MouseUp_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_main_MouseUp_obj > result = new Go_main_MouseUp_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_main_MouseUp_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_main_MouseUp_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_main_MouseUp::SubFn0","tardis/Go.hx",5134);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5134)
		this->_t0 = ::tardis::Go_obj::main_mouseEvents->ref();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseUp_obj,SubFn0,(void))

::tardis::StackFrame Go_main_MouseUp_obj::run( ){
	HX_STACK_PUSH("Go_main_MouseUp::run","tardis/Go.hx",5117);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5117)
	while((true)){
		HX_STACK_LINE(5119)
		::tardis::Go_main_MouseUp _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5119)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5121)
				{
					HX_STACK_LINE(5121)
					this->_latestPH = (int)16;
					HX_STACK_LINE(5121)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5122)
				this->_t0 = ::tardis::Go_obj::main_mouseEvents->ref();
				HX_STACK_LINE(5123)
				this->_Next = (int)-1;
				HX_STACK_LINE(5124)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(5126)
				{
					HX_STACK_LINE(5126)
					this->_latestPH = (int)16;
					HX_STACK_LINE(5126)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(5127)
				if ((!(this->_t0->hasSpace()))){
					HX_STACK_LINE(5127)
					return hx::ObjectPtr<OBJ_>(this);
				}
				HX_STACK_LINE(5128)
				this->_t0->send((int)1);
				HX_STACK_LINE(5129)
				this->_incomplete = false;
				HX_STACK_LINE(5130)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5131)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(5133)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5117)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseUp_obj,run,return )

Dynamic Go_main_MouseUp_obj::res( ){
	HX_STACK_PUSH("Go_main_MouseUp::res","tardis/Go.hx",5102);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5102)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseUp_obj,res,return )

Void Go_main_MouseUp_obj::callFromHaxe( ){
{
		HX_STACK_PUSH("Go_main_MouseUp::callFromHaxe","tardis/Go.hx",5105);
		HX_STACK_LINE(5106)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(5106)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(5107)
		::tardis::Go_main_MouseUp _sf = hx::TCast< ::tardis::Go_main_MouseUp >::cast(::tardis::Go_main_MouseUp_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(5108)
		while((_sf->_incomplete)){
			HX_STACK_LINE(5108)
			::tardis::Scheduler_obj::runAll();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_main_MouseUp_obj,callFromHaxe,(void))

Void Go_main_MouseUp_obj::callFromRT( int _gr){
{
		HX_STACK_PUSH("Go_main_MouseUp::callFromRT","tardis/Go.hx",5110);
		HX_STACK_ARG(_gr,"_gr");
		HX_STACK_LINE(5111)
		::tardis::Go_main_MouseUp _sf = hx::TCast< ::tardis::Go_main_MouseUp >::cast(::tardis::Go_main_MouseUp_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(5112)
		while((_sf->_incomplete)){
			HX_STACK_LINE(5112)
			if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
				HX_STACK_LINE(5112)
				hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
			}
			else{
				HX_STACK_LINE(5112)
				::tardis::Scheduler_obj::currentGR = _gr;
				HX_STACK_LINE(5112)
				::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_main_MouseUp_obj,callFromRT,(void))

::tardis::Go_main_MouseUp Go_main_MouseUp_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_main_MouseUp::call","tardis/Go.hx",5115);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(5115)
	return ::tardis::Go_main_MouseUp_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_main_MouseUp_obj,call,return )


Go_main_MouseUp_obj::Go_main_MouseUp_obj()
{
}

void Go_main_MouseUp_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_main_MouseUp);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_main_MouseUp_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_main_MouseUp_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Go_main_MouseUp_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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

void Go_main_MouseUp_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Go_main_MouseUp_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_main_MouseUp_obj::__mClass,"__mClass");
};

Class Go_main_MouseUp_obj::__mClass;

void Go_main_MouseUp_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_main_MouseUp"), hx::TCanCast< Go_main_MouseUp_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_main_MouseUp_obj::__boot()
{
}

} // end namespace tardis
