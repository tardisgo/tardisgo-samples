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
#ifndef INCLUDED_tardis_Go_hxutil_HAXE
#include <tardis/Go_hxutil_HAXE.h>
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

Void Go_hxutil_HAXE_obj::__construct(int gr,Dynamic _bds,::String p_code)
{
HX_STACK_PUSH("Go_hxutil_HAXE::new","tardis/Go.hx",5214);
{
	HX_STACK_LINE(5224)
	this->_Next = (int)0;
	HX_STACK_LINE(5217)
	super::__construct(gr,(int)986,HX_CSTRING("Go_hxutil_HAXE"));
	HX_STACK_LINE(5218)
	this->_bds = _bds;
	HX_STACK_LINE(5219)
	this->p_code = p_code;
	HX_STACK_LINE(5220)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_hxutil_HAXE_obj::~Go_hxutil_HAXE_obj() { }

Dynamic Go_hxutil_HAXE_obj::__CreateEmpty() { return  new Go_hxutil_HAXE_obj; }
hx::ObjectPtr< Go_hxutil_HAXE_obj > Go_hxutil_HAXE_obj::__new(int gr,Dynamic _bds,::String p_code)
{  hx::ObjectPtr< Go_hxutil_HAXE_obj > result = new Go_hxutil_HAXE_obj();
	result->__construct(gr,_bds,p_code);
	return result;}

Dynamic Go_hxutil_HAXE_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_hxutil_HAXE_obj > result = new Go_hxutil_HAXE_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_hxutil_HAXE_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

::tardis::StackFrame Go_hxutil_HAXE_obj::run( ){
	HX_STACK_PUSH("Go_hxutil_HAXE::run","tardis/Go.hx",5239);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5239)
	while((true)){
		HX_STACK_LINE(5241)
		::tardis::Go_hxutil_HAXE _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5241)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5243)
				{
					HX_STACK_LINE(5243)
					this->_latestPH = (int)986;
					HX_STACK_LINE(5243)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5244)
				this->_res = (int)0;
				HX_STACK_LINE(5245)
				this->_incomplete = false;
				HX_STACK_LINE(5246)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5247)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(5249)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5239)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_HAXE_obj,run,return )

Dynamic Go_hxutil_HAXE_obj::res( ){
	HX_STACK_PUSH("Go_hxutil_HAXE::res","tardis/Go.hx",5223);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5223)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_HAXE_obj,res,return )

Dynamic Go_hxutil_HAXE_obj::callFromHaxe( ::String p_code){
	HX_STACK_PUSH("Go_hxutil_HAXE::callFromHaxe","tardis/Go.hx",5225);
	HX_STACK_ARG(p_code,"p_code");
	HX_STACK_LINE(5226)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(5226)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(5227)
	::tardis::Go_hxutil_HAXE _sf = hx::TCast< ::tardis::Go_hxutil_HAXE >::cast(::tardis::Go_hxutil_HAXE_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_code)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5228)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5228)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(5229)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_hxutil_HAXE_obj,callFromHaxe,return )

Dynamic Go_hxutil_HAXE_obj::callFromRT( int _gr,::String p_code){
	HX_STACK_PUSH("Go_hxutil_HAXE::callFromRT","tardis/Go.hx",5231);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_code,"p_code");
	HX_STACK_LINE(5232)
	::tardis::Go_hxutil_HAXE _sf = hx::TCast< ::tardis::Go_hxutil_HAXE >::cast(::tardis::Go_hxutil_HAXE_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_code)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5233)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5233)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(5233)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(5233)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(5233)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(5234)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_hxutil_HAXE_obj,callFromRT,return )

::tardis::Go_hxutil_HAXE Go_hxutil_HAXE_obj::call( int gr,Dynamic _bds,::String p_code){
	HX_STACK_PUSH("Go_hxutil_HAXE::call","tardis/Go.hx",5237);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_code,"p_code");
	HX_STACK_LINE(5237)
	return ::tardis::Go_hxutil_HAXE_obj::__new(gr,_bds,p_code);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_hxutil_HAXE_obj,call,return )


Go_hxutil_HAXE_obj::Go_hxutil_HAXE_obj()
{
}

void Go_hxutil_HAXE_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_hxutil_HAXE);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_code,"p_code");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_hxutil_HAXE_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_code,"p_code");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_hxutil_HAXE_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
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
		if (HX_FIELD_EQ(inName,"p_code") ) { return p_code; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_hxutil_HAXE_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"p_code") ) { p_code=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_hxutil_HAXE_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_code"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_code"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_hxutil_HAXE_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_hxutil_HAXE_obj::__mClass,"__mClass");
};

Class Go_hxutil_HAXE_obj::__mClass;

void Go_hxutil_HAXE_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_hxutil_HAXE"), hx::TCanCast< Go_hxutil_HAXE_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_hxutil_HAXE_obj::__boot()
{
}

} // end namespace tardis
