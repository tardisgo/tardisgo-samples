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
#ifndef INCLUDED_tardis_Go_utf8_RuneStart
#include <tardis/Go_utf8_RuneStart.h>
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

Void Go_utf8_RuneStart_obj::__construct(int gr,Dynamic _bds,int p_b)
{
HX_STACK_PUSH("Go_utf8_RuneStart::new","tardis/Go.hx",5138);
{
	HX_STACK_LINE(5150)
	this->_Next = (int)0;
	HX_STACK_LINE(5149)
	this->_t1 = false;
	HX_STACK_LINE(5148)
	this->_t0 = (int)0;
	HX_STACK_LINE(5141)
	super::__construct(gr,(int)925,HX_CSTRING("Go_utf8_RuneStart"));
	HX_STACK_LINE(5142)
	this->_bds = _bds;
	HX_STACK_LINE(5143)
	this->p_b = p_b;
	HX_STACK_LINE(5144)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_RuneStart_obj::~Go_utf8_RuneStart_obj() { }

Dynamic Go_utf8_RuneStart_obj::__CreateEmpty() { return  new Go_utf8_RuneStart_obj; }
hx::ObjectPtr< Go_utf8_RuneStart_obj > Go_utf8_RuneStart_obj::__new(int gr,Dynamic _bds,int p_b)
{  hx::ObjectPtr< Go_utf8_RuneStart_obj > result = new Go_utf8_RuneStart_obj();
	result->__construct(gr,_bds,p_b);
	return result;}

Dynamic Go_utf8_RuneStart_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_RuneStart_obj > result = new Go_utf8_RuneStart_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_RuneStart_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_RuneStart_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_RuneStart::SubFn0","tardis/Go.hx",5177);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5178)
		int _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(5179)
		_t0 = (int((int(this->p_b) & int((int)192))) & int((int)255));
		HX_STACK_LINE(5180)
		this->_t1 = (::tardis::Force_obj::uintCompare(_t0,(int)128) != (int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneStart_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_RuneStart_obj::run( ){
	HX_STACK_PUSH("Go_utf8_RuneStart::run","tardis/Go.hx",5165);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5165)
	while((true)){
		HX_STACK_LINE(5167)
		::tardis::Go_utf8_RuneStart _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5167)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5169)
				{
					HX_STACK_LINE(5169)
					this->_latestPH = (int)925;
					HX_STACK_LINE(5169)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5170)
				{
					HX_STACK_LINE(5170)
					int _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(5170)
					_t0 = (int((int(this->p_b) & int((int)192))) & int((int)255));
					HX_STACK_LINE(5170)
					this->_t1 = (::tardis::Force_obj::uintCompare(_t0,(int)128) != (int)0);
				}
				HX_STACK_LINE(5171)
				this->_res = this->_t1;
				HX_STACK_LINE(5172)
				this->_incomplete = false;
				HX_STACK_LINE(5173)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5174)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(5176)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5165)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneStart_obj,run,return )

Dynamic Go_utf8_RuneStart_obj::res( ){
	HX_STACK_PUSH("Go_utf8_RuneStart::res","tardis/Go.hx",5147);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5147)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_RuneStart_obj,res,return )

bool Go_utf8_RuneStart_obj::callFromHaxe( int p_b){
	HX_STACK_PUSH("Go_utf8_RuneStart::callFromHaxe","tardis/Go.hx",5151);
	HX_STACK_ARG(p_b,"p_b");
	HX_STACK_LINE(5152)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(5152)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(5153)
	::tardis::Go_utf8_RuneStart _sf = hx::TCast< ::tardis::Go_utf8_RuneStart >::cast(::tardis::Go_utf8_RuneStart_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_b)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5154)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5154)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(5155)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_RuneStart_obj,callFromHaxe,return )

bool Go_utf8_RuneStart_obj::callFromRT( int _gr,int p_b){
	HX_STACK_PUSH("Go_utf8_RuneStart::callFromRT","tardis/Go.hx",5157);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_b,"p_b");
	HX_STACK_LINE(5158)
	::tardis::Go_utf8_RuneStart _sf = hx::TCast< ::tardis::Go_utf8_RuneStart >::cast(::tardis::Go_utf8_RuneStart_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_b)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5159)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5159)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(5159)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(5159)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(5159)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(5160)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_RuneStart_obj,callFromRT,return )

::tardis::Go_utf8_RuneStart Go_utf8_RuneStart_obj::call( int gr,Dynamic _bds,int p_b){
	HX_STACK_PUSH("Go_utf8_RuneStart::call","tardis/Go.hx",5163);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_b,"p_b");
	HX_STACK_LINE(5163)
	return ::tardis::Go_utf8_RuneStart_obj::__new(gr,_bds,p_b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_RuneStart_obj,call,return )


Go_utf8_RuneStart_obj::Go_utf8_RuneStart_obj()
{
}

void Go_utf8_RuneStart_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_RuneStart);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_b,"p_b");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_RuneStart_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_b,"p_b");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_RuneStart_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t1") ) { return _t1; }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		if (HX_FIELD_EQ(inName,"p_b") ) { return p_b; }
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
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_utf8_RuneStart_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_b") ) { p_b=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_RuneStart_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_b"));
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
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_b"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_RuneStart_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_RuneStart_obj::__mClass,"__mClass");
};

Class Go_utf8_RuneStart_obj::__mClass;

void Go_utf8_RuneStart_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_RuneStart"), hx::TCanCast< Go_utf8_RuneStart_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_RuneStart_obj::__boot()
{
}

} // end namespace tardis
