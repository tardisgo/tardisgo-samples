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
#ifndef INCLUDED_tardis__Go_Go_haxegoruntime_cstringToGo
#include <tardis/_Go/Go_haxegoruntime_cstringToGo.h>
#endif
namespace tardis{
namespace _Go{

Void Go_haxegoruntime_cstringToGo_obj::__construct(int gr,Dynamic _bds,Dynamic p_arg0)
{
HX_STACK_PUSH("Go_haxegoruntime_cstringToGo::new","tardis/Go.hx",8003);
{
	HX_STACK_LINE(8014)
	this->_Next = (int)0;
	HX_STACK_LINE(8013)
	this->_t0 = null();
	HX_STACK_LINE(8006)
	super::__construct(gr,(int)413,HX_CSTRING("Go_haxegoruntime_cstringToGo"));
	HX_STACK_LINE(8007)
	this->_bds = _bds;
	HX_STACK_LINE(8008)
	this->p_arg0 = p_arg0;
	HX_STACK_LINE(8009)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_cstringToGo_obj::~Go_haxegoruntime_cstringToGo_obj() { }

Dynamic Go_haxegoruntime_cstringToGo_obj::__CreateEmpty() { return  new Go_haxegoruntime_cstringToGo_obj; }
hx::ObjectPtr< Go_haxegoruntime_cstringToGo_obj > Go_haxegoruntime_cstringToGo_obj::__new(int gr,Dynamic _bds,Dynamic p_arg0)
{  hx::ObjectPtr< Go_haxegoruntime_cstringToGo_obj > result = new Go_haxegoruntime_cstringToGo_obj();
	result->__construct(gr,_bds,p_arg0);
	return result;}

Dynamic Go_haxegoruntime_cstringToGo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_cstringToGo_obj > result = new Go_haxegoruntime_cstringToGo_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_haxegoruntime_cstringToGo_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_cstringToGo_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_cstringToGo::SubFn0","tardis/Go.hx",8045);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8045)
		this->_t0 = ::tardis::Interface_obj::__new((int)0,HX_CSTRING("runtime.cstringToGo() not yet implemented"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_cstringToGo_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_cstringToGo_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_cstringToGo::run","tardis/Go.hx",8029);
	HX_STACK_THIS(this);
	HX_STACK_LINE(8029)
	while((true)){
		HX_STACK_LINE(8031)
		::tardis::_Go::Go_haxegoruntime_cstringToGo _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(8031)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(8033)
				{
					HX_STACK_LINE(8033)
					this->_latestPH = (int)413;
					HX_STACK_LINE(8033)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(8034)
				this->_t0 = ::tardis::Interface_obj::__new((int)0,HX_CSTRING("runtime.cstringToGo() not yet implemented"));
				HX_STACK_LINE(8035)
				this->_latestPH = (int)414;
				HX_STACK_LINE(8036)
				::tardis::Scheduler_obj::panic(this->_goroutine,this->_t0);
				HX_STACK_LINE(8036)
				this->_Next = (int)-1;
				HX_STACK_LINE(8037)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(8039)
				{
					HX_STACK_LINE(8039)
					this->_latestPH = (int)414;
					HX_STACK_LINE(8039)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(8042)
				this->_incomplete = false;
				HX_STACK_LINE(8043)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(8044)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(8044)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(8029)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_cstringToGo_obj,run,return )

Dynamic Go_haxegoruntime_cstringToGo_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_cstringToGo::res","tardis/Go.hx",8012);
	HX_STACK_THIS(this);
	HX_STACK_LINE(8012)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_cstringToGo_obj,res,return )

::String Go_haxegoruntime_cstringToGo_obj::callFromHaxe( Dynamic p_arg0){
	HX_STACK_PUSH("Go_haxegoruntime_cstringToGo::callFromHaxe","tardis/Go.hx",8015);
	HX_STACK_ARG(p_arg0,"p_arg0");
	HX_STACK_LINE(8016)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(8016)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(8017)
	::tardis::_Go::Go_haxegoruntime_cstringToGo _sf = hx::TCast< ::tardis::_Go::Go_haxegoruntime_cstringToGo >::cast(::tardis::_Go::Go_haxegoruntime_cstringToGo_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_arg0)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(8018)
	while((_sf->_incomplete)){
		HX_STACK_LINE(8018)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(8019)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_cstringToGo_obj,callFromHaxe,return )

::String Go_haxegoruntime_cstringToGo_obj::callFromRT( int _gr,Dynamic p_arg0){
	HX_STACK_PUSH("Go_haxegoruntime_cstringToGo::callFromRT","tardis/Go.hx",8021);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_arg0,"p_arg0");
	HX_STACK_LINE(8022)
	::tardis::_Go::Go_haxegoruntime_cstringToGo _sf = hx::TCast< ::tardis::_Go::Go_haxegoruntime_cstringToGo >::cast(::tardis::_Go::Go_haxegoruntime_cstringToGo_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_arg0)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(8023)
	while((_sf->_incomplete)){
		HX_STACK_LINE(8023)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(8023)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(8023)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(8023)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(8024)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_cstringToGo_obj,callFromRT,return )

::tardis::_Go::Go_haxegoruntime_cstringToGo Go_haxegoruntime_cstringToGo_obj::call( int gr,Dynamic _bds,Dynamic p_arg0){
	HX_STACK_PUSH("Go_haxegoruntime_cstringToGo::call","tardis/Go.hx",8027);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_arg0,"p_arg0");
	HX_STACK_LINE(8027)
	return ::tardis::_Go::Go_haxegoruntime_cstringToGo_obj::__new(gr,_bds,p_arg0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_haxegoruntime_cstringToGo_obj,call,return )


Go_haxegoruntime_cstringToGo_obj::Go_haxegoruntime_cstringToGo_obj()
{
}

void Go_haxegoruntime_cstringToGo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_cstringToGo);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_arg0,"p_arg0");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_cstringToGo_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_arg0,"p_arg0");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_cstringToGo_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_arg0") ) { return p_arg0; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_haxegoruntime_cstringToGo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"p_arg0") ) { p_arg0=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_cstringToGo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_arg0"));
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
	HX_CSTRING("p_arg0"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_cstringToGo_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_cstringToGo_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_cstringToGo_obj::__mClass;

void Go_haxegoruntime_cstringToGo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis._Go.Go_haxegoruntime_cstringToGo"), hx::TCanCast< Go_haxegoruntime_cstringToGo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_cstringToGo_obj::__boot()
{
}

} // end namespace tardis
} // end namespace _Go
