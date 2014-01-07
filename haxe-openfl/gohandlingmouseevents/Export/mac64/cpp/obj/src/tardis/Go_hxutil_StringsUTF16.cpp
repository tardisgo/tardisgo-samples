#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_tardis_Force
#include <tardis/Force.h>
#endif
#ifndef INCLUDED_tardis_Go
#include <tardis/Go.h>
#endif
#ifndef INCLUDED_tardis_Go_hxutil_StringsUTF16
#include <tardis/Go_hxutil_StringsUTF16.h>
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

Void Go_hxutil_StringsUTF16_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_hxutil_StringsUTF16::new","tardis/Go.hx",3758);
{
	HX_STACK_LINE(3769)
	this->_Next = (int)0;
	HX_STACK_LINE(3768)
	this->_t1 = false;
	HX_STACK_LINE(3767)
	this->_t0 = (int)0;
	HX_STACK_LINE(3760)
	super::__construct(gr,(int)1006,HX_CSTRING("Go_hxutil_StringsUTF16"));
	HX_STACK_LINE(3761)
	this->_bds = _bds;
	HX_STACK_LINE(3762)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_hxutil_StringsUTF16_obj::~Go_hxutil_StringsUTF16_obj() { }

Dynamic Go_hxutil_StringsUTF16_obj::__CreateEmpty() { return  new Go_hxutil_StringsUTF16_obj; }
hx::ObjectPtr< Go_hxutil_StringsUTF16_obj > Go_hxutil_StringsUTF16_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_hxutil_StringsUTF16_obj > result = new Go_hxutil_StringsUTF16_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_hxutil_StringsUTF16_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_hxutil_StringsUTF16_obj > result = new Go_hxutil_StringsUTF16_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_hxutil_StringsUTF16_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_hxutil_StringsUTF16_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_hxutil_StringsUTF16::SubFn0","tardis/Go.hx",3797);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3797)
		this->_t1 = (::tardis::Force_obj::uintCompare(this->_t0,(int)1) == (int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_StringsUTF16_obj,SubFn0,(void))

::tardis::StackFrame Go_hxutil_StringsUTF16_obj::run( ){
	HX_STACK_PUSH("Go_hxutil_StringsUTF16::run","tardis/Go.hx",3784);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3784)
	while((true)){
		HX_STACK_LINE(3786)
		::tardis::Go_hxutil_StringsUTF16 _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3786)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(3788)
				{
					HX_STACK_LINE(3788)
					this->_latestPH = (int)1006;
					HX_STACK_LINE(3788)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(3789)
				this->_t0 = HX_CSTRING("\xe5""\xad""\x97""").length;
				HX_STACK_LINE(3790)
				this->_t1 = (::tardis::Force_obj::uintCompare(this->_t0,(int)1) == (int)0);
				HX_STACK_LINE(3791)
				this->_res = this->_t1;
				HX_STACK_LINE(3792)
				this->_incomplete = false;
				HX_STACK_LINE(3793)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(3794)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(3796)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(3784)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_StringsUTF16_obj,run,return )

Dynamic Go_hxutil_StringsUTF16_obj::res( ){
	HX_STACK_PUSH("Go_hxutil_StringsUTF16::res","tardis/Go.hx",3765);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3765)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_StringsUTF16_obj,res,return )

bool Go_hxutil_StringsUTF16_obj::callFromHaxe( ){
	HX_STACK_PUSH("Go_hxutil_StringsUTF16::callFromHaxe","tardis/Go.hx",3770);
	HX_STACK_LINE(3771)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(3771)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(3772)
	::tardis::Go_hxutil_StringsUTF16 _sf = hx::TCast< ::tardis::Go_hxutil_StringsUTF16 >::cast(::tardis::Go_hxutil_StringsUTF16_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3773)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3773)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(3774)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_StringsUTF16_obj,callFromHaxe,return )

bool Go_hxutil_StringsUTF16_obj::callFromRT( int _gr){
	HX_STACK_PUSH("Go_hxutil_StringsUTF16::callFromRT","tardis/Go.hx",3776);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_LINE(3777)
	::tardis::Go_hxutil_StringsUTF16 _sf = hx::TCast< ::tardis::Go_hxutil_StringsUTF16 >::cast(::tardis::Go_hxutil_StringsUTF16_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3778)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3778)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(3778)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(3778)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(3778)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(3779)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_hxutil_StringsUTF16_obj,callFromRT,return )

::tardis::Go_hxutil_StringsUTF16 Go_hxutil_StringsUTF16_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_hxutil_StringsUTF16::call","tardis/Go.hx",3782);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(3782)
	return ::tardis::Go_hxutil_StringsUTF16_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_hxutil_StringsUTF16_obj,call,return )


Go_hxutil_StringsUTF16_obj::Go_hxutil_StringsUTF16_obj()
{
}

void Go_hxutil_StringsUTF16_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_hxutil_StringsUTF16);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_res,"_res");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_hxutil_StringsUTF16_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_hxutil_StringsUTF16_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t1") ) { return _t1; }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
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

Dynamic Go_hxutil_StringsUTF16_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
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

void Go_hxutil_StringsUTF16_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_SF1"));
	outFields->push(HX_CSTRING("_res"));
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
	HX_CSTRING("_t1"),
	HX_CSTRING("_t0"),
	HX_CSTRING("_SF1"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_hxutil_StringsUTF16_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_hxutil_StringsUTF16_obj::__mClass,"__mClass");
};

Class Go_hxutil_StringsUTF16_obj::__mClass;

void Go_hxutil_StringsUTF16_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_hxutil_StringsUTF16"), hx::TCanCast< Go_hxutil_StringsUTF16_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_hxutil_StringsUTF16_obj::__boot()
{
}

} // end namespace tardis
