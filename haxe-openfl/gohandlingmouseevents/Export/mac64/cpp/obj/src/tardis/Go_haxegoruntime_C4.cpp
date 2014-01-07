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
#ifndef INCLUDED_tardis_Go_haxegoruntime_C4
#include <tardis/Go_haxegoruntime_C4.h>
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

Void Go_haxegoruntime_C4_obj::__construct(int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4)
{
HX_STACK_PUSH("Go_haxegoruntime_C4::new","tardis/Go.hx",5755);
{
	HX_STACK_LINE(5774)
	this->_Next = (int)0;
	HX_STACK_LINE(5773)
	this->_t0 = null();
	HX_STACK_LINE(5762)
	super::__construct(gr,(int)191,HX_CSTRING("Go_haxegoruntime_C4"));
	HX_STACK_LINE(5763)
	this->_bds = _bds;
	HX_STACK_LINE(5764)
	this->p_funcName = p_funcName;
	HX_STACK_LINE(5765)
	this->p_a1 = p_a1;
	HX_STACK_LINE(5766)
	this->p_a2 = p_a2;
	HX_STACK_LINE(5767)
	this->p_a3 = p_a3;
	HX_STACK_LINE(5768)
	this->p_a4 = p_a4;
	HX_STACK_LINE(5769)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_C4_obj::~Go_haxegoruntime_C4_obj() { }

Dynamic Go_haxegoruntime_C4_obj::__CreateEmpty() { return  new Go_haxegoruntime_C4_obj; }
hx::ObjectPtr< Go_haxegoruntime_C4_obj > Go_haxegoruntime_C4_obj::__new(int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4)
{  hx::ObjectPtr< Go_haxegoruntime_C4_obj > result = new Go_haxegoruntime_C4_obj();
	result->__construct(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4);
	return result;}

Dynamic Go_haxegoruntime_C4_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_C4_obj > result = new Go_haxegoruntime_C4_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

hx::Object *Go_haxegoruntime_C4_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_C4_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_C4::SubFn0","tardis/Go.hx",5801);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5801)
		this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_funcName);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C4_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_C4_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_C4::run","tardis/Go.hx",5789);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5789)
	while((true)){
		HX_STACK_LINE(5791)
		::tardis::Go_haxegoruntime_C4 _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5791)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5793)
				{
					HX_STACK_LINE(5793)
					this->_latestPH = (int)191;
					HX_STACK_LINE(5793)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5794)
				this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_funcName);
				HX_STACK_LINE(5795)
				this->_res = this->_t0;
				HX_STACK_LINE(5796)
				this->_incomplete = false;
				HX_STACK_LINE(5797)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5798)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(5800)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5789)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C4_obj,run,return )

Dynamic Go_haxegoruntime_C4_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_C4::res","tardis/Go.hx",5772);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5772)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_C4_obj,res,return )

::tardis::Interface Go_haxegoruntime_C4_obj::callFromHaxe( ::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4){
	HX_STACK_PUSH("Go_haxegoruntime_C4::callFromHaxe","tardis/Go.hx",5775);
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_ARG(p_a4,"p_a4");
	HX_STACK_LINE(5776)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(5776)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(5777)
	::tardis::Go_haxegoruntime_C4 _sf = hx::TCast< ::tardis::Go_haxegoruntime_C4 >::cast(::tardis::Go_haxegoruntime_C4_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_funcName,p_a1,p_a2,p_a3,p_a4)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5778)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5778)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(5779)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Go_haxegoruntime_C4_obj,callFromHaxe,return )

::tardis::Interface Go_haxegoruntime_C4_obj::callFromRT( int _gr,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4){
	HX_STACK_PUSH("Go_haxegoruntime_C4::callFromRT","tardis/Go.hx",5781);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_ARG(p_a4,"p_a4");
	HX_STACK_LINE(5782)
	::tardis::Go_haxegoruntime_C4 _sf = hx::TCast< ::tardis::Go_haxegoruntime_C4 >::cast(::tardis::Go_haxegoruntime_C4_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_funcName,p_a1,p_a2,p_a3,p_a4)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5783)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5783)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(5783)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(5783)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(5783)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(5784)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Go_haxegoruntime_C4_obj,callFromRT,return )

::tardis::Go_haxegoruntime_C4 Go_haxegoruntime_C4_obj::call( int gr,Dynamic _bds,::String p_funcName,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4){
	HX_STACK_PUSH("Go_haxegoruntime_C4::call","tardis/Go.hx",5787);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_funcName,"p_funcName");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_ARG(p_a4,"p_a4");
	HX_STACK_LINE(5787)
	return ::tardis::Go_haxegoruntime_C4_obj::__new(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(Go_haxegoruntime_C4_obj,call,return )


Go_haxegoruntime_C4_obj::Go_haxegoruntime_C4_obj()
{
}

void Go_haxegoruntime_C4_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_C4);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_a4,"p_a4");
	HX_MARK_MEMBER_NAME(p_a3,"p_a3");
	HX_MARK_MEMBER_NAME(p_a2,"p_a2");
	HX_MARK_MEMBER_NAME(p_a1,"p_a1");
	HX_MARK_MEMBER_NAME(p_funcName,"p_funcName");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_C4_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_a4,"p_a4");
	HX_VISIT_MEMBER_NAME(p_a3,"p_a3");
	HX_VISIT_MEMBER_NAME(p_a2,"p_a2");
	HX_VISIT_MEMBER_NAME(p_a1,"p_a1");
	HX_VISIT_MEMBER_NAME(p_funcName,"p_funcName");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_C4_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Go_haxegoruntime_C4_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Interface >(); return inValue; }
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

void Go_haxegoruntime_C4_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
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
	HX_CSTRING("p_a4"),
	HX_CSTRING("p_a3"),
	HX_CSTRING("p_a2"),
	HX_CSTRING("p_a1"),
	HX_CSTRING("p_funcName"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_C4_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_C4_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_C4_obj::__mClass;

void Go_haxegoruntime_C4_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_C4"), hx::TCanCast< Go_haxegoruntime_C4_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_C4_obj::__boot()
{
}

} // end namespace tardis
