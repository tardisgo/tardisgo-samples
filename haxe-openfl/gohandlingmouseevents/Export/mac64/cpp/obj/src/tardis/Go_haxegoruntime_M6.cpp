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
#ifndef INCLUDED_tardis_Go_haxegoruntime_M6
#include <tardis/Go_haxegoruntime_M6.h>
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

Void Go_haxegoruntime_M6_obj::__construct(int gr,Dynamic _bds,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5,::tardis::Interface p_a6)
{
HX_STACK_PUSH("Go_haxegoruntime_M6::new","tardis/Go.hx",3145);
{
	HX_STACK_LINE(3172)
	this->_Next = (int)0;
	HX_STACK_LINE(3171)
	this->_t0 = null();
	HX_STACK_LINE(3156)
	super::__construct(gr,(int)204,HX_CSTRING("Go_haxegoruntime_M6"));
	HX_STACK_LINE(3157)
	this->_bds = _bds;
	HX_STACK_LINE(3158)
	this->p_rx = p_rx;
	HX_STACK_LINE(3159)
	this->p_typ = p_typ;
	HX_STACK_LINE(3160)
	this->p_meth = p_meth;
	HX_STACK_LINE(3161)
	this->p_a1 = p_a1;
	HX_STACK_LINE(3162)
	this->p_a2 = p_a2;
	HX_STACK_LINE(3163)
	this->p_a3 = p_a3;
	HX_STACK_LINE(3164)
	this->p_a4 = p_a4;
	HX_STACK_LINE(3165)
	this->p_a5 = p_a5;
	HX_STACK_LINE(3166)
	this->p_a6 = p_a6;
	HX_STACK_LINE(3167)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_M6_obj::~Go_haxegoruntime_M6_obj() { }

Dynamic Go_haxegoruntime_M6_obj::__CreateEmpty() { return  new Go_haxegoruntime_M6_obj; }
hx::ObjectPtr< Go_haxegoruntime_M6_obj > Go_haxegoruntime_M6_obj::__new(int gr,Dynamic _bds,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5,::tardis::Interface p_a6)
{  hx::ObjectPtr< Go_haxegoruntime_M6_obj > result = new Go_haxegoruntime_M6_obj();
	result->__construct(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6);
	return result;}

Dynamic Go_haxegoruntime_M6_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_M6_obj > result = new Go_haxegoruntime_M6_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10]);
	return result;}

hx::Object *Go_haxegoruntime_M6_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_M6_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_M6::SubFn0","tardis/Go.hx",3199);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3199)
		this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_meth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_M6_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_M6_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_M6::run","tardis/Go.hx",3187);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3187)
	while((true)){
		HX_STACK_LINE(3189)
		::tardis::Go_haxegoruntime_M6 _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3189)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(3191)
				{
					HX_STACK_LINE(3191)
					this->_latestPH = (int)204;
					HX_STACK_LINE(3191)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(3192)
				this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_meth);
				HX_STACK_LINE(3193)
				this->_res = this->_t0;
				HX_STACK_LINE(3194)
				this->_incomplete = false;
				HX_STACK_LINE(3195)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(3196)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(3198)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(3187)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_M6_obj,run,return )

Dynamic Go_haxegoruntime_M6_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_M6::res","tardis/Go.hx",3170);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3170)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_M6_obj,res,return )

::tardis::Interface Go_haxegoruntime_M6_obj::callFromHaxe( ::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5,::tardis::Interface p_a6){
	HX_STACK_PUSH("Go_haxegoruntime_M6::callFromHaxe","tardis/Go.hx",3173);
	HX_STACK_ARG(p_rx,"p_rx");
	HX_STACK_ARG(p_typ,"p_typ");
	HX_STACK_ARG(p_meth,"p_meth");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_ARG(p_a4,"p_a4");
	HX_STACK_ARG(p_a5,"p_a5");
	HX_STACK_ARG(p_a6,"p_a6");
	HX_STACK_LINE(3174)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(3174)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(3175)
	::tardis::Go_haxegoruntime_M6 _sf = hx::TCast< ::tardis::Go_haxegoruntime_M6 >::cast(::tardis::Go_haxegoruntime_M6_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3176)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3176)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(3177)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC9(Go_haxegoruntime_M6_obj,callFromHaxe,return )

::tardis::Interface Go_haxegoruntime_M6_obj::callFromRT( int _gr,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5,::tardis::Interface p_a6){
	HX_STACK_PUSH("Go_haxegoruntime_M6::callFromRT","tardis/Go.hx",3179);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_rx,"p_rx");
	HX_STACK_ARG(p_typ,"p_typ");
	HX_STACK_ARG(p_meth,"p_meth");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_ARG(p_a4,"p_a4");
	HX_STACK_ARG(p_a5,"p_a5");
	HX_STACK_ARG(p_a6,"p_a6");
	HX_STACK_LINE(3180)
	::tardis::Go_haxegoruntime_M6 _sf = hx::TCast< ::tardis::Go_haxegoruntime_M6 >::cast(::tardis::Go_haxegoruntime_M6_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3181)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3181)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(3181)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(3181)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(3181)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(3182)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC10(Go_haxegoruntime_M6_obj,callFromRT,return )

::tardis::Go_haxegoruntime_M6 Go_haxegoruntime_M6_obj::call( int gr,Dynamic _bds,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2,::tardis::Interface p_a3,::tardis::Interface p_a4,::tardis::Interface p_a5,::tardis::Interface p_a6){
	HX_STACK_PUSH("Go_haxegoruntime_M6::call","tardis/Go.hx",3185);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_rx,"p_rx");
	HX_STACK_ARG(p_typ,"p_typ");
	HX_STACK_ARG(p_meth,"p_meth");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_ARG(p_a3,"p_a3");
	HX_STACK_ARG(p_a4,"p_a4");
	HX_STACK_ARG(p_a5,"p_a5");
	HX_STACK_ARG(p_a6,"p_a6");
	HX_STACK_LINE(3185)
	return ::tardis::Go_haxegoruntime_M6_obj::__new(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC11(Go_haxegoruntime_M6_obj,call,return )


Go_haxegoruntime_M6_obj::Go_haxegoruntime_M6_obj()
{
}

void Go_haxegoruntime_M6_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_M6);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_a6,"p_a6");
	HX_MARK_MEMBER_NAME(p_a5,"p_a5");
	HX_MARK_MEMBER_NAME(p_a4,"p_a4");
	HX_MARK_MEMBER_NAME(p_a3,"p_a3");
	HX_MARK_MEMBER_NAME(p_a2,"p_a2");
	HX_MARK_MEMBER_NAME(p_a1,"p_a1");
	HX_MARK_MEMBER_NAME(p_meth,"p_meth");
	HX_MARK_MEMBER_NAME(p_typ,"p_typ");
	HX_MARK_MEMBER_NAME(p_rx,"p_rx");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_M6_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_a6,"p_a6");
	HX_VISIT_MEMBER_NAME(p_a5,"p_a5");
	HX_VISIT_MEMBER_NAME(p_a4,"p_a4");
	HX_VISIT_MEMBER_NAME(p_a3,"p_a3");
	HX_VISIT_MEMBER_NAME(p_a2,"p_a2");
	HX_VISIT_MEMBER_NAME(p_a1,"p_a1");
	HX_VISIT_MEMBER_NAME(p_meth,"p_meth");
	HX_VISIT_MEMBER_NAME(p_typ,"p_typ");
	HX_VISIT_MEMBER_NAME(p_rx,"p_rx");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_M6_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_a6") ) { return p_a6; }
		if (HX_FIELD_EQ(inName,"p_a5") ) { return p_a5; }
		if (HX_FIELD_EQ(inName,"p_a4") ) { return p_a4; }
		if (HX_FIELD_EQ(inName,"p_a3") ) { return p_a3; }
		if (HX_FIELD_EQ(inName,"p_a2") ) { return p_a2; }
		if (HX_FIELD_EQ(inName,"p_a1") ) { return p_a1; }
		if (HX_FIELD_EQ(inName,"p_rx") ) { return p_rx; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		if (HX_FIELD_EQ(inName,"p_typ") ) { return p_typ; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SubFn0") ) { return SubFn0_dyn(); }
		if (HX_FIELD_EQ(inName,"p_meth") ) { return p_meth; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_haxegoruntime_M6_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a6") ) { p_a6=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a5") ) { p_a5=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a4") ) { p_a4=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a3") ) { p_a3=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a2") ) { p_a2=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_a1") ) { p_a1=inValue.Cast< ::tardis::Interface >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_rx") ) { p_rx=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_typ") ) { p_typ=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"p_meth") ) { p_meth=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_M6_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_a6"));
	outFields->push(HX_CSTRING("p_a5"));
	outFields->push(HX_CSTRING("p_a4"));
	outFields->push(HX_CSTRING("p_a3"));
	outFields->push(HX_CSTRING("p_a2"));
	outFields->push(HX_CSTRING("p_a1"));
	outFields->push(HX_CSTRING("p_meth"));
	outFields->push(HX_CSTRING("p_typ"));
	outFields->push(HX_CSTRING("p_rx"));
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
	HX_CSTRING("p_a6"),
	HX_CSTRING("p_a5"),
	HX_CSTRING("p_a4"),
	HX_CSTRING("p_a3"),
	HX_CSTRING("p_a2"),
	HX_CSTRING("p_a1"),
	HX_CSTRING("p_meth"),
	HX_CSTRING("p_typ"),
	HX_CSTRING("p_rx"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_M6_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_M6_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_M6_obj::__mClass;

void Go_haxegoruntime_M6_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_M6"), hx::TCanCast< Go_haxegoruntime_M6_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_M6_obj::__boot()
{
}

} // end namespace tardis
