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
#ifndef INCLUDED_tardis_Go_haxegoruntime_M2
#include <tardis/Go_haxegoruntime_M2.h>
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

Void Go_haxegoruntime_M2_obj::__construct(int gr,Dynamic _bds,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2)
{
HX_STACK_PUSH("Go_haxegoruntime_M2::new","tardis/Go.hx",7269);
{
	HX_STACK_LINE(7288)
	this->_Next = (int)0;
	HX_STACK_LINE(7287)
	this->_t0 = null();
	HX_STACK_LINE(7276)
	super::__construct(gr,(int)200,HX_CSTRING("Go_haxegoruntime_M2"));
	HX_STACK_LINE(7277)
	this->_bds = _bds;
	HX_STACK_LINE(7278)
	this->p_rx = p_rx;
	HX_STACK_LINE(7279)
	this->p_typ = p_typ;
	HX_STACK_LINE(7280)
	this->p_meth = p_meth;
	HX_STACK_LINE(7281)
	this->p_a1 = p_a1;
	HX_STACK_LINE(7282)
	this->p_a2 = p_a2;
	HX_STACK_LINE(7283)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_M2_obj::~Go_haxegoruntime_M2_obj() { }

Dynamic Go_haxegoruntime_M2_obj::__CreateEmpty() { return  new Go_haxegoruntime_M2_obj; }
hx::ObjectPtr< Go_haxegoruntime_M2_obj > Go_haxegoruntime_M2_obj::__new(int gr,Dynamic _bds,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2)
{  hx::ObjectPtr< Go_haxegoruntime_M2_obj > result = new Go_haxegoruntime_M2_obj();
	result->__construct(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2);
	return result;}

Dynamic Go_haxegoruntime_M2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_M2_obj > result = new Go_haxegoruntime_M2_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

hx::Object *Go_haxegoruntime_M2_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_M2_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_M2::SubFn0","tardis/Go.hx",7315);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7315)
		this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_meth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_M2_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_M2_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_M2::run","tardis/Go.hx",7303);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7303)
	while((true)){
		HX_STACK_LINE(7305)
		::tardis::Go_haxegoruntime_M2 _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(7305)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(7307)
				{
					HX_STACK_LINE(7307)
					this->_latestPH = (int)200;
					HX_STACK_LINE(7307)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(7308)
				this->_t0 = ::tardis::Interface_obj::__new((int)0,this->p_meth);
				HX_STACK_LINE(7309)
				this->_res = this->_t0;
				HX_STACK_LINE(7310)
				this->_incomplete = false;
				HX_STACK_LINE(7311)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7312)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(7314)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(7303)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_M2_obj,run,return )

Dynamic Go_haxegoruntime_M2_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_M2::res","tardis/Go.hx",7286);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7286)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_M2_obj,res,return )

::tardis::Interface Go_haxegoruntime_M2_obj::callFromHaxe( ::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2){
	HX_STACK_PUSH("Go_haxegoruntime_M2::callFromHaxe","tardis/Go.hx",7289);
	HX_STACK_ARG(p_rx,"p_rx");
	HX_STACK_ARG(p_typ,"p_typ");
	HX_STACK_ARG(p_meth,"p_meth");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_LINE(7290)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(7290)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(7291)
	::tardis::Go_haxegoruntime_M2 _sf = hx::TCast< ::tardis::Go_haxegoruntime_M2 >::cast(::tardis::Go_haxegoruntime_M2_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_rx,p_typ,p_meth,p_a1,p_a2)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7292)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7292)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(7293)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Go_haxegoruntime_M2_obj,callFromHaxe,return )

::tardis::Interface Go_haxegoruntime_M2_obj::callFromRT( int _gr,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2){
	HX_STACK_PUSH("Go_haxegoruntime_M2::callFromRT","tardis/Go.hx",7295);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_rx,"p_rx");
	HX_STACK_ARG(p_typ,"p_typ");
	HX_STACK_ARG(p_meth,"p_meth");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_LINE(7296)
	::tardis::Go_haxegoruntime_M2 _sf = hx::TCast< ::tardis::Go_haxegoruntime_M2 >::cast(::tardis::Go_haxegoruntime_M2_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_rx,p_typ,p_meth,p_a1,p_a2)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7297)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7297)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(7297)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(7297)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(7297)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(7298)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Go_haxegoruntime_M2_obj,callFromRT,return )

::tardis::Go_haxegoruntime_M2 Go_haxegoruntime_M2_obj::call( int gr,Dynamic _bds,::tardis::Interface p_rx,::String p_typ,::String p_meth,::tardis::Interface p_a1,::tardis::Interface p_a2){
	HX_STACK_PUSH("Go_haxegoruntime_M2::call","tardis/Go.hx",7301);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_rx,"p_rx");
	HX_STACK_ARG(p_typ,"p_typ");
	HX_STACK_ARG(p_meth,"p_meth");
	HX_STACK_ARG(p_a1,"p_a1");
	HX_STACK_ARG(p_a2,"p_a2");
	HX_STACK_LINE(7301)
	return ::tardis::Go_haxegoruntime_M2_obj::__new(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(Go_haxegoruntime_M2_obj,call,return )


Go_haxegoruntime_M2_obj::Go_haxegoruntime_M2_obj()
{
}

void Go_haxegoruntime_M2_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_M2);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_a2,"p_a2");
	HX_MARK_MEMBER_NAME(p_a1,"p_a1");
	HX_MARK_MEMBER_NAME(p_meth,"p_meth");
	HX_MARK_MEMBER_NAME(p_typ,"p_typ");
	HX_MARK_MEMBER_NAME(p_rx,"p_rx");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_M2_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_a2,"p_a2");
	HX_VISIT_MEMBER_NAME(p_a1,"p_a1");
	HX_VISIT_MEMBER_NAME(p_meth,"p_meth");
	HX_VISIT_MEMBER_NAME(p_typ,"p_typ");
	HX_VISIT_MEMBER_NAME(p_rx,"p_rx");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_M2_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Go_haxegoruntime_M2_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Interface >(); return inValue; }
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

void Go_haxegoruntime_M2_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
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
	HX_CSTRING("p_a2"),
	HX_CSTRING("p_a1"),
	HX_CSTRING("p_meth"),
	HX_CSTRING("p_typ"),
	HX_CSTRING("p_rx"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_M2_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_M2_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_M2_obj::__mClass;

void Go_haxegoruntime_M2_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_M2"), hx::TCanCast< Go_haxegoruntime_M2_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_M2_obj::__boot()
{
}

} // end namespace tardis
