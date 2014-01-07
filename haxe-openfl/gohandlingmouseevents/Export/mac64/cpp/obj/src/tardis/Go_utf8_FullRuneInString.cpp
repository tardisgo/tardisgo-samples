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
#ifndef INCLUDED_tardis_Go_utf8_FullRuneInString
#include <tardis/Go_utf8_FullRuneInString.h>
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
#ifndef INCLUDED_tardis__Go_Go_utf8_decodeRuneInStringInternal
#include <tardis/_Go/Go_utf8_decodeRuneInStringInternal.h>
#endif
namespace tardis{

Void Go_utf8_FullRuneInString_obj::__construct(int gr,Dynamic _bds,::String p_s)
{
HX_STACK_PUSH("Go_utf8_FullRuneInString::new","tardis/Go.hx",7001);
{
	HX_STACK_LINE(7015)
	this->_Next = (int)0;
	HX_STACK_LINE(7014)
	this->_t4 = false;
	HX_STACK_LINE(7013)
	this->_t3 = false;
	HX_STACK_LINE(7012)
	this->_t0 = null();
	HX_STACK_LINE(7004)
	super::__construct(gr,(int)742,HX_CSTRING("Go_utf8_FullRuneInString"));
	HX_STACK_LINE(7005)
	this->_bds = _bds;
	HX_STACK_LINE(7006)
	this->p_s = p_s;
	HX_STACK_LINE(7007)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_FullRuneInString_obj::~Go_utf8_FullRuneInString_obj() { }

Dynamic Go_utf8_FullRuneInString_obj::__CreateEmpty() { return  new Go_utf8_FullRuneInString_obj; }
hx::ObjectPtr< Go_utf8_FullRuneInString_obj > Go_utf8_FullRuneInString_obj::__new(int gr,Dynamic _bds,::String p_s)
{  hx::ObjectPtr< Go_utf8_FullRuneInString_obj > result = new Go_utf8_FullRuneInString_obj();
	result->__construct(gr,_bds,p_s);
	return result;}

Dynamic Go_utf8_FullRuneInString_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_FullRuneInString_obj > result = new Go_utf8_FullRuneInString_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_FullRuneInString_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_FullRuneInString_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_FullRuneInString::SubFn0","tardis/Go.hx",7051);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7054)
		this->_t3 = this->_t0->__Field(HX_CSTRING("r2"),true);
		HX_STACK_LINE(7055)
		this->_t4 = !(this->_t3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_FullRuneInString_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_FullRuneInString_obj::run( ){
	HX_STACK_PUSH("Go_utf8_FullRuneInString::run","tardis/Go.hx",7030);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7030)
	while((true)){
		HX_STACK_LINE(7032)
		::tardis::Go_utf8_FullRuneInString _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(7032)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(7034)
				{
					HX_STACK_LINE(7034)
					this->_latestPH = (int)742;
					HX_STACK_LINE(7034)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(7035)
				this->_latestPH = (int)743;
				HX_STACK_LINE(7036)
				this->_SF1 = ::tardis::_Go::Go_utf8_decodeRuneInStringInternal_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->p_s);
				HX_STACK_LINE(7037)
				this->_Next = (int)-1;
				HX_STACK_LINE(7038)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(7040)
				{
					HX_STACK_LINE(7040)
					this->_latestPH = (int)743;
					HX_STACK_LINE(7040)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(7041)
				this->_t0 = this->_SF1->res();
				HX_STACK_LINE(7043)
				{
					HX_STACK_LINE(7043)
					this->_t3 = this->_t0->__Field(HX_CSTRING("r2"),true);
					HX_STACK_LINE(7043)
					this->_t4 = !(this->_t3);
				}
				HX_STACK_LINE(7044)
				this->_latestPH = (int)744;
				HX_STACK_LINE(7045)
				this->_res = this->_t4;
				HX_STACK_LINE(7046)
				this->_incomplete = false;
				HX_STACK_LINE(7047)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7048)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(7050)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(7030)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_FullRuneInString_obj,run,return )

Dynamic Go_utf8_FullRuneInString_obj::res( ){
	HX_STACK_PUSH("Go_utf8_FullRuneInString::res","tardis/Go.hx",7010);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7010)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_FullRuneInString_obj,res,return )

bool Go_utf8_FullRuneInString_obj::callFromHaxe( ::String p_s){
	HX_STACK_PUSH("Go_utf8_FullRuneInString::callFromHaxe","tardis/Go.hx",7016);
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(7017)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(7017)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(7018)
	::tardis::Go_utf8_FullRuneInString _sf = hx::TCast< ::tardis::Go_utf8_FullRuneInString >::cast(::tardis::Go_utf8_FullRuneInString_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7019)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7019)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(7020)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_FullRuneInString_obj,callFromHaxe,return )

bool Go_utf8_FullRuneInString_obj::callFromRT( int _gr,::String p_s){
	HX_STACK_PUSH("Go_utf8_FullRuneInString::callFromRT","tardis/Go.hx",7022);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(7023)
	::tardis::Go_utf8_FullRuneInString _sf = hx::TCast< ::tardis::Go_utf8_FullRuneInString >::cast(::tardis::Go_utf8_FullRuneInString_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7024)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7024)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(7024)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(7024)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(7024)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(7025)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_FullRuneInString_obj,callFromRT,return )

::tardis::Go_utf8_FullRuneInString Go_utf8_FullRuneInString_obj::call( int gr,Dynamic _bds,::String p_s){
	HX_STACK_PUSH("Go_utf8_FullRuneInString::call","tardis/Go.hx",7028);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(7028)
	return ::tardis::Go_utf8_FullRuneInString_obj::__new(gr,_bds,p_s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_FullRuneInString_obj,call,return )


Go_utf8_FullRuneInString_obj::Go_utf8_FullRuneInString_obj()
{
}

void Go_utf8_FullRuneInString_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_FullRuneInString);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t4,"_t4");
	HX_MARK_MEMBER_NAME(_t3,"_t3");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_s,"p_s");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_FullRuneInString_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t4,"_t4");
	HX_VISIT_MEMBER_NAME(_t3,"_t3");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_s,"p_s");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_FullRuneInString_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t4") ) { return _t4; }
		if (HX_FIELD_EQ(inName,"_t3") ) { return _t3; }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		if (HX_FIELD_EQ(inName,"p_s") ) { return p_s; }
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

Dynamic Go_utf8_FullRuneInString_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t4") ) { _t4=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t3") ) { _t3=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_s") ) { p_s=inValue.Cast< ::String >(); return inValue; }
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

void Go_utf8_FullRuneInString_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t4"));
	outFields->push(HX_CSTRING("_t3"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_SF1"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_s"));
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
	HX_CSTRING("p_s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_FullRuneInString_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_FullRuneInString_obj::__mClass,"__mClass");
};

Class Go_utf8_FullRuneInString_obj::__mClass;

void Go_utf8_FullRuneInString_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_FullRuneInString"), hx::TCanCast< Go_utf8_FullRuneInString_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_FullRuneInString_obj::__boot()
{
}

} // end namespace tardis
