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
#ifndef INCLUDED_tardis_Go_haxegoruntime_C3
#include <tardis/Go_haxegoruntime_C3.h>
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

Void Go_haxegoruntime_C3_obj::__construct(int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3)
{
HX_STACK_PUSH("Go_haxegoruntime_C3::new","tardis/Go.hx",5048);
{
	HX_STACK_LINE(5065)
	this->_Next = (int)0;
	HX_STACK_LINE(5064)
	this->_t0 = null();
	HX_STACK_LINE(5054)
	super::__construct(gr,(int)190,HX_CSTRING("Go_haxegoruntime_C3"));
	HX_STACK_LINE(5055)
	this->_bds = _bds;
	HX_STACK_LINE(5056)
	this->p_funcName = p_funcName;
	HX_STACK_LINE(5057)
	this->p_a1 = p_a1;
	HX_STACK_LINE(5058)
	this->p_a2 = p_a2;
	HX_STACK_LINE(5059)
	this->p_a3 = p_a3;
	HX_STACK_LINE(5060)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_C3_obj::~Go_haxegoruntime_C3_obj() { }

Dynamic Go_haxegoruntime_C3_obj::__CreateEmpty() { return  new Go_haxegoruntime_C3_obj; }
hx::ObjectPtr< Go_haxegoruntime_C3_obj > Go_haxegoruntime_C3_obj::__new(int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3)
{  hx::ObjectPtr< Go_haxegoruntime_C3_obj > result = new Go_haxegoruntime_C3_obj();
	result->__construct(gr,_bds,p_funcName,p_a1,p_a2,p_a3);
	return result;}

Dynamic Go_haxegoruntime_C3_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_C3_obj > result = new Go_haxegoruntime_C3_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

hx::Object *Go_haxegoruntime_C3_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_C3_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_C3::SubFn0","tardis/Go.hx",5092);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5092)
		this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_funcName);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C3_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_C3_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_C3::run","tardis/Go.hx",5080);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5080)
	while((true)){
		HX_STACK_LINE(5082)
		::tardis::Go_haxegoruntime_C3 _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5082)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5084)
				{
					HX_STACK_LINE(5084)
					this->_latestPH = (int)190;
					HX_STACK_LINE(5084)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5085)
				this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_funcName);
				HX_STACK_LINE(5086)
				this->_res = this->_t0;
				HX_STACK_LINE(5087)
				this->_incomplete = false;
				HX_STACK_LINE(5088)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5089)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(5091)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5080)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C3_obj,run,return )

Dynamic Go_haxegoruntime_C3_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_C3::res","tardis/Go.hx",5063);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5063)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C3_obj,res,return )

::tardis::Interface Go_haxegoruntime_C3_obj::callFromHaxe( ::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3){
	HX_STACK_PUSH("Go_haxegoruntime_C3::callFromHaxe","tardis/Go.hx",5066);
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_LINE(5067)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(5067)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(5068)
	::tardis::Go_haxegoruntime_C3 _sf = hx::TCast< ::tardis::Go_haxegoruntime_C3 >::cast(::tardis::Go_haxegoruntime_C3_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_funcName,p_a1,p_a2,p_a3)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5069)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5069)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(5070)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Go_haxegoruntime_C3_obj,callFromHaxe,return )

::tardis::Interface Go_haxegoruntime_C3_obj::callFromRT( int _gr,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3){
	HX_STACK_PUSH("Go_haxegoruntime_C3::callFromRT","tardis/Go.hx",5072);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_LINE(5073)
	::tardis::Go_haxegoruntime_C3 _sf = hx::TCast< ::tardis::Go_haxegoruntime_C3 >::cast(::tardis::Go_haxegoruntime_C3_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_funcName,p_a1,p_a2,p_a3)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5074)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5074)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(5074)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(5074)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(5074)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(5075)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Go_haxegoruntime_C3_obj,callFromRT,return )

::tardis::Go_haxegoruntime_C3 Go_haxegoruntime_C3_obj::call( int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3){
	HX_STACK_PUSH("Go_haxegoruntime_C3::call","tardis/Go.hx",5078);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_LINE(5078)
	return ::tardis::Go_haxegoruntime_C3_obj::__new(gr,_bds,p_funcName,p_a1,p_a2,p_a3);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Go_haxegoruntime_C3_obj,call,return )


Go_haxegoruntime_C3_obj::Go_haxegoruntime_C3_obj()
{
}

void Go_haxegoruntime_C3_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_C3);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_a3,"p_a3");
	HX_MARK_MEMBER_NAME(p_a2,"p_a2");
	HX_MARK_MEMBER_NAME(p_a1,"p_a1");
	HX_MARK_MEMBER_NAME(p_funcName,"p_funcName");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_C3_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_a3,"p_a3");
	HX_VISIT_MEMBER_NAME(p_a2,"p_a2");
	HX_VISIT_MEMBER_NAME(p_a1,"p_a1");
	HX_VISIT_MEMBER_NAME(p_funcName,"p_funcName");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_C3_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Go_haxegoruntime_C3_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Interface >(); return inValue; }
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

void Go_haxegoruntime_C3_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
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
	HX_CSTRING("p_a3"),
	HX_CSTRING("p_a2"),
	HX_CSTRING("p_a1"),
	HX_CSTRING("p_funcName"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_C3_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_C3_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_C3_obj::__mClass;

void Go_haxegoruntime_C3_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_C3"), hx::TCanCast< Go_haxegoruntime_C3_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_C3_obj::__boot()
{
}

} // end namespace tardis
