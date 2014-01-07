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
#ifndef INCLUDED_tardis_Go_haxegoruntime_RunesToUTF16
#include <tardis/Go_haxegoruntime_RunesToUTF16.h>
#endif
#ifndef INCLUDED_tardis_Go_utf16_Encode
#include <tardis/Go_utf16_Encode.h>
#endif
#ifndef INCLUDED_tardis_Interface
#include <tardis/Interface.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
#ifndef INCLUDED_tardis_Slice
#include <tardis/Slice.h>
#endif
#ifndef INCLUDED_tardis_StackFrame
#include <tardis/StackFrame.h>
#endif
#ifndef INCLUDED_tardis_StackFrameBasis
#include <tardis/StackFrameBasis.h>
#endif
namespace tardis{

Void Go_haxegoruntime_RunesToUTF16_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_r)
{
HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF16::new","tardis/Go.hx",5708);
{
	HX_STACK_LINE(5720)
	this->_Next = (int)0;
	HX_STACK_LINE(5719)
	this->_t0 = null();
	HX_STACK_LINE(5711)
	super::__construct(gr,(int)106,HX_CSTRING("Go_haxegoruntime_RunesToUTF16"));
	HX_STACK_LINE(5712)
	this->_bds = _bds;
	HX_STACK_LINE(5713)
	this->p_r = p_r;
	HX_STACK_LINE(5714)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_RunesToUTF16_obj::~Go_haxegoruntime_RunesToUTF16_obj() { }

Dynamic Go_haxegoruntime_RunesToUTF16_obj::__CreateEmpty() { return  new Go_haxegoruntime_RunesToUTF16_obj; }
hx::ObjectPtr< Go_haxegoruntime_RunesToUTF16_obj > Go_haxegoruntime_RunesToUTF16_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_r)
{  hx::ObjectPtr< Go_haxegoruntime_RunesToUTF16_obj > result = new Go_haxegoruntime_RunesToUTF16_obj();
	result->__construct(gr,_bds,p_r);
	return result;}

Dynamic Go_haxegoruntime_RunesToUTF16_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_RunesToUTF16_obj > result = new Go_haxegoruntime_RunesToUTF16_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_haxegoruntime_RunesToUTF16_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

::tardis::StackFrame Go_haxegoruntime_RunesToUTF16_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF16::run","tardis/Go.hx",5735);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5735)
	while((true)){
		HX_STACK_LINE(5737)
		::tardis::Go_haxegoruntime_RunesToUTF16 _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5737)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5739)
				{
					HX_STACK_LINE(5739)
					this->_latestPH = (int)106;
					HX_STACK_LINE(5739)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5740)
				this->_latestPH = (int)107;
				HX_STACK_LINE(5741)
				this->_SF1 = ::tardis::Go_utf16_Encode_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->p_r);
				HX_STACK_LINE(5742)
				this->_Next = (int)-1;
				HX_STACK_LINE(5743)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(5745)
				{
					HX_STACK_LINE(5745)
					this->_latestPH = (int)107;
					HX_STACK_LINE(5745)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(5746)
				this->_t0 = this->_SF1->res();
				HX_STACK_LINE(5748)
				this->_res = this->_t0;
				HX_STACK_LINE(5749)
				this->_incomplete = false;
				HX_STACK_LINE(5750)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5751)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(5753)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5735)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_RunesToUTF16_obj,run,return )

Dynamic Go_haxegoruntime_RunesToUTF16_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF16::res","tardis/Go.hx",5717);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5717)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_RunesToUTF16_obj,res,return )

::tardis::Slice Go_haxegoruntime_RunesToUTF16_obj::callFromHaxe( ::tardis::Slice p_r){
	HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF16::callFromHaxe","tardis/Go.hx",5721);
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(5722)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(5722)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(5723)
	::tardis::Go_haxegoruntime_RunesToUTF16 _sf = hx::TCast< ::tardis::Go_haxegoruntime_RunesToUTF16 >::cast(::tardis::Go_haxegoruntime_RunesToUTF16_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5724)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5724)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(5725)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_RunesToUTF16_obj,callFromHaxe,return )

::tardis::Slice Go_haxegoruntime_RunesToUTF16_obj::callFromRT( int _gr,::tardis::Slice p_r){
	HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF16::callFromRT","tardis/Go.hx",5727);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(5728)
	::tardis::Go_haxegoruntime_RunesToUTF16 _sf = hx::TCast< ::tardis::Go_haxegoruntime_RunesToUTF16 >::cast(::tardis::Go_haxegoruntime_RunesToUTF16_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5729)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5729)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(5729)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(5729)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(5729)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(5730)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_RunesToUTF16_obj,callFromRT,return )

::tardis::Go_haxegoruntime_RunesToUTF16 Go_haxegoruntime_RunesToUTF16_obj::call( int gr,Dynamic _bds,::tardis::Slice p_r){
	HX_STACK_PUSH("Go_haxegoruntime_RunesToUTF16::call","tardis/Go.hx",5733);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(5733)
	return ::tardis::Go_haxegoruntime_RunesToUTF16_obj::__new(gr,_bds,p_r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_haxegoruntime_RunesToUTF16_obj,call,return )


Go_haxegoruntime_RunesToUTF16_obj::Go_haxegoruntime_RunesToUTF16_obj()
{
}

void Go_haxegoruntime_RunesToUTF16_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_RunesToUTF16);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_r,"p_r");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_RunesToUTF16_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_r,"p_r");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_RunesToUTF16_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		if (HX_FIELD_EQ(inName,"p_r") ) { return p_r; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_haxegoruntime_RunesToUTF16_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Slice >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_r") ) { p_r=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_RunesToUTF16_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_SF1"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_r"));
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
	HX_CSTRING("_t0"),
	HX_CSTRING("_SF1"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_r"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_RunesToUTF16_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_RunesToUTF16_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_RunesToUTF16_obj::__mClass;

void Go_haxegoruntime_RunesToUTF16_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_RunesToUTF16"), hx::TCanCast< Go_haxegoruntime_RunesToUTF16_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_RunesToUTF16_obj::__boot()
{
}

} // end namespace tardis
