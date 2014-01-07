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
#ifndef INCLUDED_tardis_Go_utf8_FullRune
#include <tardis/Go_utf8_FullRune.h>
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
#ifndef INCLUDED_tardis__Go_Go_utf8_decodeRuneInternal
#include <tardis/_Go/Go_utf8_decodeRuneInternal.h>
#endif
namespace tardis{

Void Go_utf8_FullRune_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_p)
{
HX_STACK_PUSH("Go_utf8_FullRune::new","tardis/Go.hx",4060);
{
	HX_STACK_LINE(4074)
	this->_Next = (int)0;
	HX_STACK_LINE(4073)
	this->_t4 = false;
	HX_STACK_LINE(4072)
	this->_t3 = false;
	HX_STACK_LINE(4071)
	this->_t0 = null();
	HX_STACK_LINE(4063)
	super::__construct(gr,(int)736,HX_CSTRING("Go_utf8_FullRune"));
	HX_STACK_LINE(4064)
	this->_bds = _bds;
	HX_STACK_LINE(4065)
	this->p_p = p_p;
	HX_STACK_LINE(4066)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_FullRune_obj::~Go_utf8_FullRune_obj() { }

Dynamic Go_utf8_FullRune_obj::__CreateEmpty() { return  new Go_utf8_FullRune_obj; }
hx::ObjectPtr< Go_utf8_FullRune_obj > Go_utf8_FullRune_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_p)
{  hx::ObjectPtr< Go_utf8_FullRune_obj > result = new Go_utf8_FullRune_obj();
	result->__construct(gr,_bds,p_p);
	return result;}

Dynamic Go_utf8_FullRune_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_FullRune_obj > result = new Go_utf8_FullRune_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_FullRune_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_FullRune_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_FullRune::SubFn0","tardis/Go.hx",4110);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4113)
		this->_t3 = this->_t0->__Field(HX_CSTRING("r2"),true);
		HX_STACK_LINE(4114)
		this->_t4 = !(this->_t3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_FullRune_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_FullRune_obj::run( ){
	HX_STACK_PUSH("Go_utf8_FullRune::run","tardis/Go.hx",4089);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4089)
	while((true)){
		HX_STACK_LINE(4091)
		::tardis::Go_utf8_FullRune _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(4091)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(4093)
				{
					HX_STACK_LINE(4093)
					this->_latestPH = (int)736;
					HX_STACK_LINE(4093)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(4094)
				this->_latestPH = (int)737;
				HX_STACK_LINE(4095)
				this->_SF1 = ::tardis::_Go::Go_utf8_decodeRuneInternal_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->p_p);
				HX_STACK_LINE(4096)
				this->_Next = (int)-1;
				HX_STACK_LINE(4097)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(4099)
				{
					HX_STACK_LINE(4099)
					this->_latestPH = (int)737;
					HX_STACK_LINE(4099)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(4100)
				this->_t0 = this->_SF1->res();
				HX_STACK_LINE(4102)
				{
					HX_STACK_LINE(4102)
					this->_t3 = this->_t0->__Field(HX_CSTRING("r2"),true);
					HX_STACK_LINE(4102)
					this->_t4 = !(this->_t3);
				}
				HX_STACK_LINE(4103)
				this->_latestPH = (int)738;
				HX_STACK_LINE(4104)
				this->_res = this->_t4;
				HX_STACK_LINE(4105)
				this->_incomplete = false;
				HX_STACK_LINE(4106)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4107)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(4109)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(4089)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_FullRune_obj,run,return )

Dynamic Go_utf8_FullRune_obj::res( ){
	HX_STACK_PUSH("Go_utf8_FullRune::res","tardis/Go.hx",4069);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4069)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_FullRune_obj,res,return )

bool Go_utf8_FullRune_obj::callFromHaxe( ::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_FullRune::callFromHaxe","tardis/Go.hx",4075);
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(4076)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(4076)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(4077)
	::tardis::Go_utf8_FullRune _sf = hx::TCast< ::tardis::Go_utf8_FullRune >::cast(::tardis::Go_utf8_FullRune_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(4078)
	while((_sf->_incomplete)){
		HX_STACK_LINE(4078)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(4079)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_FullRune_obj,callFromHaxe,return )

bool Go_utf8_FullRune_obj::callFromRT( int _gr,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_FullRune::callFromRT","tardis/Go.hx",4081);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(4082)
	::tardis::Go_utf8_FullRune _sf = hx::TCast< ::tardis::Go_utf8_FullRune >::cast(::tardis::Go_utf8_FullRune_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(4083)
	while((_sf->_incomplete)){
		HX_STACK_LINE(4083)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(4083)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(4083)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(4083)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(4084)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_FullRune_obj,callFromRT,return )

::tardis::Go_utf8_FullRune Go_utf8_FullRune_obj::call( int gr,Dynamic _bds,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_FullRune::call","tardis/Go.hx",4087);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(4087)
	return ::tardis::Go_utf8_FullRune_obj::__new(gr,_bds,p_p);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_FullRune_obj,call,return )


Go_utf8_FullRune_obj::Go_utf8_FullRune_obj()
{
}

void Go_utf8_FullRune_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_FullRune);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t4,"_t4");
	HX_MARK_MEMBER_NAME(_t3,"_t3");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_p,"p_p");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_FullRune_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t4,"_t4");
	HX_VISIT_MEMBER_NAME(_t3,"_t3");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_p,"p_p");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_FullRune_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t4") ) { return _t4; }
		if (HX_FIELD_EQ(inName,"_t3") ) { return _t3; }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		if (HX_FIELD_EQ(inName,"p_p") ) { return p_p; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
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

Dynamic Go_utf8_FullRune_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_p") ) { p_p=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_FullRune_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t4"));
	outFields->push(HX_CSTRING("_t3"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_SF1"));
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
	HX_CSTRING("SubFn0"),
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("_t4"),
	HX_CSTRING("_t3"),
	HX_CSTRING("_t0"),
	HX_CSTRING("_SF1"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_p"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_FullRune_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_FullRune_obj::__mClass,"__mClass");
};

Class Go_utf8_FullRune_obj::__mClass;

void Go_utf8_FullRune_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_FullRune"), hx::TCanCast< Go_utf8_FullRune_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_FullRune_obj::__boot()
{
}

} // end namespace tardis
