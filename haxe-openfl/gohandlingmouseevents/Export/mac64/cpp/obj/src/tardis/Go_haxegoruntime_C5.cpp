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
#ifndef INCLUDED_tardis_Go_haxegoruntime_C5
#include <tardis/Go_haxegoruntime_C5.h>
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

Void Go_haxegoruntime_C5_obj::__construct(int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5)
{
HX_STACK_PUSH("Go_haxegoruntime_C5::new","tardis/Go.hx",3966);
{
	HX_STACK_LINE(3987)
	this->_Next = (int)0;
	HX_STACK_LINE(3986)
	this->_t0 = null();
	HX_STACK_LINE(3974)
	super::__construct(gr,(int)192,HX_CSTRING("Go_haxegoruntime_C5"));
	HX_STACK_LINE(3975)
	this->_bds = _bds;
	HX_STACK_LINE(3976)
	this->p_funcName = p_funcName;
	HX_STACK_LINE(3977)
	this->p_a1 = p_a1;
	HX_STACK_LINE(3978)
	this->p_a2 = p_a2;
	HX_STACK_LINE(3979)
	this->p_a3 = p_a3;
	HX_STACK_LINE(3980)
	this->p_a4 = p_a4;
	HX_STACK_LINE(3981)
	this->p_a5 = p_a5;
	HX_STACK_LINE(3982)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_C5_obj::~Go_haxegoruntime_C5_obj() { }

Dynamic Go_haxegoruntime_C5_obj::__CreateEmpty() { return  new Go_haxegoruntime_C5_obj; }
hx::ObjectPtr< Go_haxegoruntime_C5_obj > Go_haxegoruntime_C5_obj::__new(int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5)
{  hx::ObjectPtr< Go_haxegoruntime_C5_obj > result = new Go_haxegoruntime_C5_obj();
	result->__construct(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5);
	return result;}

Dynamic Go_haxegoruntime_C5_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_C5_obj > result = new Go_haxegoruntime_C5_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7]);
	return result;}

hx::Object *Go_haxegoruntime_C5_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_C5_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_C5::SubFn0","tardis/Go.hx",4014);
		HX_STACK_THIS(this);
		HX_STACK_LINE(4014)
		this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_funcName);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C5_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_C5_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_C5::run","tardis/Go.hx",4002);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4002)
	while((true)){
		HX_STACK_LINE(4004)
		::tardis::Go_haxegoruntime_C5 _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(4004)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(4006)
				{
					HX_STACK_LINE(4006)
					this->_latestPH = (int)192;
					HX_STACK_LINE(4006)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(4007)
				this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_funcName);
				HX_STACK_LINE(4008)
				this->_res = this->_t0;
				HX_STACK_LINE(4009)
				this->_incomplete = false;
				HX_STACK_LINE(4010)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(4011)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(4013)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(4002)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C5_obj,run,return )

Dynamic Go_haxegoruntime_C5_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_C5::res","tardis/Go.hx",3985);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3985)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C5_obj,res,return )

::tardis::Interface Go_haxegoruntime_C5_obj::callFromHaxe( ::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5){
	HX_STACK_PUSH("Go_haxegoruntime_C5::callFromHaxe","tardis/Go.hx",3988);
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_ARG(p_a4,"p_a4");
	HX_STACK_ARG(p_a5,"p_a5");
	HX_STACK_LINE(3989)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(3989)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(3990)
	::tardis::Go_haxegoruntime_C5 _sf = hx::TCast< ::tardis::Go_haxegoruntime_C5 >::cast(::tardis::Go_haxegoruntime_C5_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3991)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3991)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(3992)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Go_haxegoruntime_C5_obj,callFromHaxe,return )

::tardis::Interface Go_haxegoruntime_C5_obj::callFromRT( int _gr,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5){
	HX_STACK_PUSH("Go_haxegoruntime_C5::callFromRT","tardis/Go.hx",3994);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_ARG(p_a4,"p_a4");
	HX_STACK_ARG(p_a5,"p_a5");
	HX_STACK_LINE(3995)
	::tardis::Go_haxegoruntime_C5 _sf = hx::TCast< ::tardis::Go_haxegoruntime_C5 >::cast(::tardis::Go_haxegoruntime_C5_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3996)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3996)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(3996)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(3996)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(3996)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(3997)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(Go_haxegoruntime_C5_obj,callFromRT,return )

::tardis::Go_haxegoruntime_C5 Go_haxegoruntime_C5_obj::call( int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5){
	HX_STACK_PUSH("Go_haxegoruntime_C5::call","tardis/Go.hx",4000);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_ARG(p_a4,"p_a4");
	HX_STACK_ARG(p_a5,"p_a5");
	HX_STACK_LINE(4000)
	return ::tardis::Go_haxegoruntime_C5_obj::__new(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(Go_haxegoruntime_C5_obj,call,return )


Go_haxegoruntime_C5_obj::Go_haxegoruntime_C5_obj()
{
}

void Go_haxegoruntime_C5_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_C5);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_a5,"p_a5");
	HX_MARK_MEMBER_NAME(p_a4,"p_a4");
	HX_MARK_MEMBER_NAME(p_a3,"p_a3");
	HX_MARK_MEMBER_NAME(p_a2,"p_a2");
	HX_MARK_MEMBER_NAME(p_a1,"p_a1");
	HX_MARK_MEMBER_NAME(p_funcName,"p_funcName");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_C5_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_a5,"p_a5");
	HX_VISIT_MEMBER_NAME(p_a4,"p_a4");
	HX_VISIT_MEMBER_NAME(p_a3,"p_a3");
	HX_VISIT_MEMBER_NAME(p_a2,"p_a2");
	HX_VISIT_MEMBER_NAME(p_a1,"p_a1");
	HX_VISIT_MEMBER_NAME(p_funcName,"p_funcName");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_C5_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_a5") ) { return p_a5; }
		if (HX_FIELD_EQ(inName,"p_a4") ) { return p_a4; }
		if (HX_FIELD_EQ(inName,"p_a3") ) { return p_a3; }
		if (HX_FIELD_EQ(inName,"p_a2") ) { return p_a2; }
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

Dynamic Go_haxegoruntime_C5_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a5") ) { p_a5=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a4") ) { p_a4=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a3") ) { p_a3=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a2") ) { p_a2=inValue.Cast< ::tardis::Interface >(); return inValue; }
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

void Go_haxegoruntime_C5_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_a5"));
	outFields->push(HX_CSTRING("p_a4"));
	outFields->push(HX_CSTRING("p_a3"));
	outFields->push(HX_CSTRING("p_a2"));
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
	HX_CSTRING("p_a5"),
	HX_CSTRING("p_a4"),
	HX_CSTRING("p_a3"),
	HX_CSTRING("p_a2"),
	HX_CSTRING("p_a1"),
	HX_CSTRING("p_funcName"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_C5_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_C5_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_C5_obj::__mClass;

void Go_haxegoruntime_C5_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_C5"), hx::TCanCast< Go_haxegoruntime_C5_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_C5_obj::__boot()
{
}

} // end namespace tardis
