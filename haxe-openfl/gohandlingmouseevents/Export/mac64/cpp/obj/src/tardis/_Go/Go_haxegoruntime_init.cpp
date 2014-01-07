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
#ifndef INCLUDED_tardis_Interface
#include <tardis/Interface.h>
#endif
#ifndef INCLUDED_tardis_Pointer
#include <tardis/Pointer.h>
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
#ifndef INCLUDED_tardis__Go_Go_haxegoruntime_init
#include <tardis/_Go/Go_haxegoruntime_init.h>
#endif
#ifndef INCLUDED_tardis__Go_Go_haxegoruntime_init_36_1
#include <tardis/_Go/Go_haxegoruntime_init_36_1.h>
#endif
#ifndef INCLUDED_tardis__Go_Go_hxutil_init
#include <tardis/_Go/Go_hxutil_init.h>
#endif
#ifndef INCLUDED_tardis__Go_Go_utf16_init
#include <tardis/_Go/Go_utf16_init.h>
#endif
#ifndef INCLUDED_tardis__Go_Go_utf8_init
#include <tardis/_Go/Go_utf8_init.h>
#endif
namespace tardis{
namespace _Go{

Void Go_haxegoruntime_init_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_haxegoruntime_init::new","tardis/Go.hx",6786);
{
	HX_STACK_LINE(6798)
	this->_Next = (int)0;
	HX_STACK_LINE(6793)
	this->_t0 = false;
	HX_STACK_LINE(6788)
	super::__construct(gr,(int)134,HX_CSTRING("Go_haxegoruntime_init"));
	HX_STACK_LINE(6789)
	this->_bds = _bds;
	HX_STACK_LINE(6790)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_init_obj::~Go_haxegoruntime_init_obj() { }

Dynamic Go_haxegoruntime_init_obj::__CreateEmpty() { return  new Go_haxegoruntime_init_obj; }
hx::ObjectPtr< Go_haxegoruntime_init_obj > Go_haxegoruntime_init_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_haxegoruntime_init_obj > result = new Go_haxegoruntime_init_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_haxegoruntime_init_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_init_obj > result = new Go_haxegoruntime_init_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_haxegoruntime_init_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_init_obj::SubFn2( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_init::SubFn2","tardis/Go.hx",6862);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6862)
		this->_Next = (int)2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_init_obj,SubFn2,(void))

Void Go_haxegoruntime_init_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_init::SubFn1","tardis/Go.hx",6859);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6859)
		::tardis::Go_obj::haxegoruntime_init_36_guard->store(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_init_obj,SubFn1,(void))

Void Go_haxegoruntime_init_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_init::SubFn0","tardis/Go.hx",6854);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6855)
		bool _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(6856)
		_t0 = ::tardis::Go_obj::haxegoruntime_init_36_guard->ref();
		HX_STACK_LINE(6857)
		this->_Next = (  ((_t0)) ? int((int)2) : int((int)1) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_init_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_init_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_init::run","tardis/Go.hx",6811);
	HX_STACK_THIS(this);
	HX_STACK_LINE(6811)
	while((true)){
		HX_STACK_LINE(6813)
		::tardis::_Go::Go_haxegoruntime_init _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(6813)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(6815)
				{
					HX_STACK_LINE(6815)
					this->_latestPH = (int)134;
					HX_STACK_LINE(6815)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(6816)
				{
					HX_STACK_LINE(6816)
					bool _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(6816)
					_t0 = ::tardis::Go_obj::haxegoruntime_init_36_guard->ref();
					HX_STACK_LINE(6816)
					this->_Next = (  ((_t0)) ? int((int)2) : int((int)1) );
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(6819)
				{
					HX_STACK_LINE(6819)
					this->_latestPH = (int)134;
					HX_STACK_LINE(6819)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(6820)
				::tardis::Go_obj::haxegoruntime_init_36_guard->store(true);
				HX_STACK_LINE(6821)
				::tardis::_Go::Go_utf16_init_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()));
				HX_STACK_LINE(6822)
				this->_Next = (int)-1;
				HX_STACK_LINE(6823)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(6825)
				{
					HX_STACK_LINE(6825)
					this->_latestPH = (int)134;
					HX_STACK_LINE(6825)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(6827)
				::tardis::_Go::Go_utf8_init_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()));
				HX_STACK_LINE(6828)
				this->_Next = (int)-2;
				HX_STACK_LINE(6829)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-2: {
				HX_STACK_LINE(6831)
				{
					HX_STACK_LINE(6831)
					this->_latestPH = (int)134;
					HX_STACK_LINE(6831)
					this->_latestBlock = (int)-2;
				}
				HX_STACK_LINE(6833)
				::tardis::_Go::Go_hxutil_init_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()));
				HX_STACK_LINE(6834)
				this->_Next = (int)-3;
				HX_STACK_LINE(6835)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-3: {
				HX_STACK_LINE(6837)
				{
					HX_STACK_LINE(6837)
					this->_latestPH = (int)134;
					HX_STACK_LINE(6837)
					this->_latestBlock = (int)-3;
				}
				HX_STACK_LINE(6839)
				::tardis::_Go::Go_haxegoruntime_init_36_1_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()));
				HX_STACK_LINE(6840)
				this->_Next = (int)-4;
				HX_STACK_LINE(6841)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-4: {
				HX_STACK_LINE(6843)
				{
					HX_STACK_LINE(6843)
					this->_latestPH = (int)134;
					HX_STACK_LINE(6843)
					this->_latestBlock = (int)-4;
				}
				HX_STACK_LINE(6845)
				this->_Next = (int)2;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(6848)
				{
					HX_STACK_LINE(6848)
					this->_latestPH = (int)134;
					HX_STACK_LINE(6848)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(6849)
				this->_incomplete = false;
				HX_STACK_LINE(6850)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6851)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(6853)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(6811)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_init_obj,run,return )

Dynamic Go_haxegoruntime_init_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_init::res","tardis/Go.hx",6792);
	HX_STACK_THIS(this);
	HX_STACK_LINE(6792)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_init_obj,res,return )

Void Go_haxegoruntime_init_obj::callFromHaxe( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_init::callFromHaxe","tardis/Go.hx",6799);
		HX_STACK_LINE(6800)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(6800)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(6801)
		::tardis::_Go::Go_haxegoruntime_init _sf = hx::TCast< ::tardis::_Go::Go_haxegoruntime_init >::cast(::tardis::_Go::Go_haxegoruntime_init_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(6802)
		while((_sf->_incomplete)){
			HX_STACK_LINE(6802)
			::tardis::Scheduler_obj::runAll();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_init_obj,callFromHaxe,(void))

Void Go_haxegoruntime_init_obj::callFromRT( int _gr){
{
		HX_STACK_PUSH("Go_haxegoruntime_init::callFromRT","tardis/Go.hx",6804);
		HX_STACK_ARG(_gr,"_gr");
		HX_STACK_LINE(6805)
		::tardis::_Go::Go_haxegoruntime_init _sf = hx::TCast< ::tardis::_Go::Go_haxegoruntime_init >::cast(::tardis::_Go::Go_haxegoruntime_init_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(6806)
		while((_sf->_incomplete)){
			HX_STACK_LINE(6806)
			if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
				HX_STACK_LINE(6806)
				hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
			}
			else{
				HX_STACK_LINE(6806)
				::tardis::Scheduler_obj::currentGR = _gr;
				HX_STACK_LINE(6806)
				::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_init_obj,callFromRT,(void))

::tardis::_Go::Go_haxegoruntime_init Go_haxegoruntime_init_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_haxegoruntime_init::call","tardis/Go.hx",6809);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(6809)
	return ::tardis::_Go::Go_haxegoruntime_init_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_init_obj,call,return )


Go_haxegoruntime_init_obj::Go_haxegoruntime_init_obj()
{
}

void Go_haxegoruntime_init_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_init);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_SF4,"_SF4");
	HX_MARK_MEMBER_NAME(_SF3,"_SF3");
	HX_MARK_MEMBER_NAME(_SF2,"_SF2");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_init_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_SF4,"_SF4");
	HX_VISIT_MEMBER_NAME(_SF3,"_SF3");
	HX_VISIT_MEMBER_NAME(_SF2,"_SF2");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_init_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_SF4") ) { return _SF4; }
		if (HX_FIELD_EQ(inName,"_SF3") ) { return _SF3; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { return _SF2; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { return _SF1; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { return _Next; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SubFn2") ) { return SubFn2_dyn(); }
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

Dynamic Go_haxegoruntime_init_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< bool >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_SF4") ) { _SF4=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF3") ) { _SF3=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF2") ) { _SF2=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_init_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_SF4"));
	outFields->push(HX_CSTRING("_SF3"));
	outFields->push(HX_CSTRING("_SF2"));
	outFields->push(HX_CSTRING("_SF1"));
	outFields->push(HX_CSTRING("_t0"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("callFromHaxe"),
	HX_CSTRING("callFromRT"),
	HX_CSTRING("call"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("SubFn2"),
	HX_CSTRING("SubFn1"),
	HX_CSTRING("SubFn0"),
	HX_CSTRING("run"),
	HX_CSTRING("_Next"),
	HX_CSTRING("_SF4"),
	HX_CSTRING("_SF3"),
	HX_CSTRING("_SF2"),
	HX_CSTRING("_SF1"),
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_init_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_init_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_init_obj::__mClass;

void Go_haxegoruntime_init_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis._Go.Go_haxegoruntime_init"), hx::TCanCast< Go_haxegoruntime_init_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_init_obj::__boot()
{
}

} // end namespace tardis
} // end namespace _Go
