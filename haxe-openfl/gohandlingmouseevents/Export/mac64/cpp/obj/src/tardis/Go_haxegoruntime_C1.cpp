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
#ifndef INCLUDED_tardis_Go_haxegoruntime_C1
#include <tardis/Go_haxegoruntime_C1.h>
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

Void Go_haxegoruntime_C1_obj::__construct(int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1)
{
HX_STACK_PUSH("Go_haxegoruntime_C1::new","tardis/Go.hx",3203);
{
	HX_STACK_LINE(3216)
	this->_Next = (int)0;
	HX_STACK_LINE(3215)
	this->_t0 = null();
	HX_STACK_LINE(3207)
	super::__construct(gr,(int)188,HX_CSTRING("Go_haxegoruntime_C1"));
	HX_STACK_LINE(3208)
	this->_bds = _bds;
	HX_STACK_LINE(3209)
	this->p_funcName = p_funcName;
	HX_STACK_LINE(3210)
	this->p_a1 = p_a1;
	HX_STACK_LINE(3211)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_C1_obj::~Go_haxegoruntime_C1_obj() { }

Dynamic Go_haxegoruntime_C1_obj::__CreateEmpty() { return  new Go_haxegoruntime_C1_obj; }
hx::ObjectPtr< Go_haxegoruntime_C1_obj > Go_haxegoruntime_C1_obj::__new(int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1)
{  hx::ObjectPtr< Go_haxegoruntime_C1_obj > result = new Go_haxegoruntime_C1_obj();
	result->__construct(gr,_bds,p_funcName,p_a1);
	return result;}

Dynamic Go_haxegoruntime_C1_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_C1_obj > result = new Go_haxegoruntime_C1_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *Go_haxegoruntime_C1_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_C1_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_C1::SubFn0","tardis/Go.hx",3243);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3243)
		this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_funcName);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C1_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_C1_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_C1::run","tardis/Go.hx",3231);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3231)
	while((true)){
		HX_STACK_LINE(3233)
		::tardis::Go_haxegoruntime_C1 _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3233)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(3235)
				{
					HX_STACK_LINE(3235)
					this->_latestPH = (int)188;
					HX_STACK_LINE(3235)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(3236)
				this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_funcName);
				HX_STACK_LINE(3237)
				this->_res = this->_t0;
				HX_STACK_LINE(3238)
				this->_incomplete = false;
				HX_STACK_LINE(3239)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(3240)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(3242)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(3231)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C1_obj,run,return )

Dynamic Go_haxegoruntime_C1_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_C1::res","tardis/Go.hx",3214);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3214)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C1_obj,res,return )

::tardis::Interface Go_haxegoruntime_C1_obj::callFromHaxe( ::String p_funcName,::tardis::Interface p_a1){
	HX_STACK_PUSH("Go_haxegoruntime_C1::callFromHaxe","tardis/Go.hx",3217);
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_LINE(3218)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(3218)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(3219)
	::tardis::Go_haxegoruntime_C1 _sf = hx::TCast< ::tardis::Go_haxegoruntime_C1 >::cast(::tardis::Go_haxegoruntime_C1_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_funcName,p_a1)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3220)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3220)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(3221)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_C1_obj,callFromHaxe,return )

::tardis::Interface Go_haxegoruntime_C1_obj::callFromRT( int _gr,::String p_funcName,::tardis::Interface p_a1){
	HX_STACK_PUSH("Go_haxegoruntime_C1::callFromRT","tardis/Go.hx",3223);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_LINE(3224)
	::tardis::Go_haxegoruntime_C1 _sf = hx::TCast< ::tardis::Go_haxegoruntime_C1 >::cast(::tardis::Go_haxegoruntime_C1_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_funcName,p_a1)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3225)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3225)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(3225)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(3225)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(3225)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(3226)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_haxegoruntime_C1_obj,callFromRT,return )

::tardis::Go_haxegoruntime_C1 Go_haxegoruntime_C1_obj::call( int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1){
	HX_STACK_PUSH("Go_haxegoruntime_C1::call","tardis/Go.hx",3229);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_LINE(3229)
	return ::tardis::Go_haxegoruntime_C1_obj::__new(gr,_bds,p_funcName,p_a1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Go_haxegoruntime_C1_obj,call,return )


Go_haxegoruntime_C1_obj::Go_haxegoruntime_C1_obj()
{
}

void Go_haxegoruntime_C1_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_C1);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_a1,"p_a1");
	HX_MARK_MEMBER_NAME(p_funcName,"p_funcName");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_C1_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_a1,"p_a1");
	HX_VISIT_MEMBER_NAME(p_funcName,"p_funcName");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_C1_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_a1") ) { return p_a1; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SubFn0") ) { return SubFn0_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		if (HX_FIELD_EQ(inName,"p_funcName") ) { return p_funcName; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_haxegoruntime_C1_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a1") ) { p_a1=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"p_funcName") ) { p_funcName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_C1_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_a1"));
	outFields->push(HX_CSTRING("p_funcName"));
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
	HX_CSTRING("p_a1"),
	HX_CSTRING("p_funcName"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_C1_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_C1_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_C1_obj::__mClass;

void Go_haxegoruntime_C1_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_C1"), hx::TCanCast< Go_haxegoruntime_C1_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_C1_obj::__boot()
{
}

} // end namespace tardis
