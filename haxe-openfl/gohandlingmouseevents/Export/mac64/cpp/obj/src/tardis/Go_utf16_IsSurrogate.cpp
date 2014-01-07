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
#ifndef INCLUDED_tardis_Go_utf16_IsSurrogate
#include <tardis/Go_utf16_IsSurrogate.h>
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

Void Go_utf16_IsSurrogate_obj::__construct(int gr,Dynamic _bds,int p_r)
{
HX_STACK_PUSH("Go_utf16_IsSurrogate::new","tardis/Go.hx",7174);
{
	HX_STACK_LINE(7188)
	this->_Next = (int)0;
	HX_STACK_LINE(7187)
	this->_Phi = (int)0;
	HX_STACK_LINE(7186)
	this->_t2 = false;
	HX_STACK_LINE(7185)
	this->_t1 = false;
	HX_STACK_LINE(7184)
	this->_t0 = false;
	HX_STACK_LINE(7177)
	super::__construct(gr,(int)455,HX_CSTRING("Go_utf16_IsSurrogate"));
	HX_STACK_LINE(7178)
	this->_bds = _bds;
	HX_STACK_LINE(7179)
	this->p_r = p_r;
	HX_STACK_LINE(7180)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf16_IsSurrogate_obj::~Go_utf16_IsSurrogate_obj() { }

Dynamic Go_utf16_IsSurrogate_obj::__CreateEmpty() { return  new Go_utf16_IsSurrogate_obj; }
hx::ObjectPtr< Go_utf16_IsSurrogate_obj > Go_utf16_IsSurrogate_obj::__new(int gr,Dynamic _bds,int p_r)
{  hx::ObjectPtr< Go_utf16_IsSurrogate_obj > result = new Go_utf16_IsSurrogate_obj();
	result->__construct(gr,_bds,p_r);
	return result;}

Dynamic Go_utf16_IsSurrogate_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf16_IsSurrogate_obj > result = new Go_utf16_IsSurrogate_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf16_IsSurrogate_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf16_IsSurrogate_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf16_IsSurrogate::SubFn1","tardis/Go.hx",7229);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7230)
		this->_t1 = (this->p_r < (int)57344);
		HX_STACK_LINE(7231)
		this->_Next = (int)2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_IsSurrogate_obj,SubFn1,(void))

Void Go_utf16_IsSurrogate_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf16_IsSurrogate::SubFn0","tardis/Go.hx",7224);
		HX_STACK_THIS(this);
		HX_STACK_LINE(7225)
		bool _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(7226)
		_t0 = ((int)55296 <= this->p_r);
		HX_STACK_LINE(7227)
		this->_Next = (  ((_t0)) ? int((int)1) : int((int)2) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_IsSurrogate_obj,SubFn0,(void))

::tardis::StackFrame Go_utf16_IsSurrogate_obj::run( ){
	HX_STACK_PUSH("Go_utf16_IsSurrogate::run","tardis/Go.hx",7203);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7203)
	while((true)){
		HX_STACK_LINE(7205)
		::tardis::Go_utf16_IsSurrogate _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(7205)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(7207)
				{
					HX_STACK_LINE(7207)
					this->_latestPH = (int)455;
					HX_STACK_LINE(7207)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(7208)
				{
					HX_STACK_LINE(7208)
					bool _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(7208)
					_t0 = ((int)55296 <= this->p_r);
					HX_STACK_LINE(7208)
					this->_Next = (  ((_t0)) ? int((int)1) : int((int)2) );
				}
				HX_STACK_LINE(7209)
				this->_Phi = (int)0;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(7211)
				{
					HX_STACK_LINE(7211)
					this->_latestPH = (int)455;
					HX_STACK_LINE(7211)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(7212)
				{
					HX_STACK_LINE(7212)
					this->_t1 = (this->p_r < (int)57344);
					HX_STACK_LINE(7212)
					this->_Next = (int)2;
				}
				HX_STACK_LINE(7213)
				this->_Phi = (int)1;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(7215)
				{
					HX_STACK_LINE(7215)
					this->_latestPH = (int)455;
					HX_STACK_LINE(7215)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(7216)
				this->_latestPH = (int)456;
				HX_STACK_LINE(7217)
				this->_t2 = (  (((this->_Phi == (int)0))) ? bool(false) : bool((  (((this->_Phi == (int)1))) ? bool(this->_t1) : bool(false) )) );
				HX_STACK_LINE(7218)
				this->_res = this->_t2;
				HX_STACK_LINE(7219)
				this->_incomplete = false;
				HX_STACK_LINE(7220)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7221)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(7223)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(7203)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_IsSurrogate_obj,run,return )

Dynamic Go_utf16_IsSurrogate_obj::res( ){
	HX_STACK_PUSH("Go_utf16_IsSurrogate::res","tardis/Go.hx",7183);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7183)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_IsSurrogate_obj,res,return )

bool Go_utf16_IsSurrogate_obj::callFromHaxe( int p_r){
	HX_STACK_PUSH("Go_utf16_IsSurrogate::callFromHaxe","tardis/Go.hx",7189);
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7190)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(7190)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(7191)
	::tardis::Go_utf16_IsSurrogate _sf = hx::TCast< ::tardis::Go_utf16_IsSurrogate >::cast(::tardis::Go_utf16_IsSurrogate_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7192)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7192)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(7193)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf16_IsSurrogate_obj,callFromHaxe,return )

bool Go_utf16_IsSurrogate_obj::callFromRT( int _gr,int p_r){
	HX_STACK_PUSH("Go_utf16_IsSurrogate::callFromRT","tardis/Go.hx",7195);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7196)
	::tardis::Go_utf16_IsSurrogate _sf = hx::TCast< ::tardis::Go_utf16_IsSurrogate >::cast(::tardis::Go_utf16_IsSurrogate_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_r)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7197)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7197)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(7197)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(7197)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(7197)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(7198)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf16_IsSurrogate_obj,callFromRT,return )

::tardis::Go_utf16_IsSurrogate Go_utf16_IsSurrogate_obj::call( int gr,Dynamic _bds,int p_r){
	HX_STACK_PUSH("Go_utf16_IsSurrogate::call","tardis/Go.hx",7201);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_r,"p_r");
	HX_STACK_LINE(7201)
	return ::tardis::Go_utf16_IsSurrogate_obj::__new(gr,_bds,p_r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf16_IsSurrogate_obj,call,return )


Go_utf16_IsSurrogate_obj::Go_utf16_IsSurrogate_obj()
{
}

void Go_utf16_IsSurrogate_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf16_IsSurrogate);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_Phi,"_Phi");
	HX_MARK_MEMBER_NAME(_t2,"_t2");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_r,"p_r");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf16_IsSurrogate_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_Phi,"_Phi");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_r,"p_r");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf16_IsSurrogate_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t2") ) { return _t2; }
		if (HX_FIELD_EQ(inName,"_t1") ) { return _t1; }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		if (HX_FIELD_EQ(inName,"p_r") ) { return p_r; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_Phi") ) { return _Phi; }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SubFn1") ) { return SubFn1_dyn(); }
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

Dynamic Go_utf16_IsSurrogate_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_r") ) { p_r=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_Phi") ) { _Phi=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf16_IsSurrogate_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_Phi"));
	outFields->push(HX_CSTRING("_t2"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
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
	HX_CSTRING("SubFn1"),
	HX_CSTRING("SubFn0"),
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("_Phi"),
	HX_CSTRING("_t2"),
	HX_CSTRING("_t1"),
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_r"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf16_IsSurrogate_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf16_IsSurrogate_obj::__mClass,"__mClass");
};

Class Go_utf16_IsSurrogate_obj::__mClass;

void Go_utf16_IsSurrogate_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf16_IsSurrogate"), hx::TCanCast< Go_utf16_IsSurrogate_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf16_IsSurrogate_obj::__boot()
{
}

} // end namespace tardis
