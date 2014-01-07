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
#ifndef INCLUDED_tardis_Go_utf8_DecodeRuneInString
#include <tardis/Go_utf8_DecodeRuneInString.h>
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

Void Go_utf8_DecodeRuneInString_obj::__construct(int gr,Dynamic _bds,::String p_s)
{
HX_STACK_PUSH("Go_utf8_DecodeRuneInString::new","tardis/Go.hx",5605);
{
	HX_STACK_LINE(5619)
	this->_Next = (int)0;
	HX_STACK_LINE(5618)
	this->_t2 = (int)0;
	HX_STACK_LINE(5617)
	this->_t1 = (int)0;
	HX_STACK_LINE(5616)
	this->_t0 = null();
	HX_STACK_LINE(5608)
	super::__construct(gr,(int)762,HX_CSTRING("Go_utf8_DecodeRuneInString"));
	HX_STACK_LINE(5609)
	this->_bds = _bds;
	HX_STACK_LINE(5610)
	this->p_s = p_s;
	HX_STACK_LINE(5611)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_DecodeRuneInString_obj::~Go_utf8_DecodeRuneInString_obj() { }

Dynamic Go_utf8_DecodeRuneInString_obj::__CreateEmpty() { return  new Go_utf8_DecodeRuneInString_obj; }
hx::ObjectPtr< Go_utf8_DecodeRuneInString_obj > Go_utf8_DecodeRuneInString_obj::__new(int gr,Dynamic _bds,::String p_s)
{  hx::ObjectPtr< Go_utf8_DecodeRuneInString_obj > result = new Go_utf8_DecodeRuneInString_obj();
	result->__construct(gr,_bds,p_s);
	return result;}

Dynamic Go_utf8_DecodeRuneInString_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_DecodeRuneInString_obj > result = new Go_utf8_DecodeRuneInString_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_DecodeRuneInString_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_DecodeRuneInString_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeRuneInString::SubFn0","tardis/Go.hx",5655);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5656)
		this->_t1 = this->_t0->__Field(HX_CSTRING("r0"),true);
		HX_STACK_LINE(5657)
		this->_t2 = this->_t0->__Field(HX_CSTRING("r1"),true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeRuneInString_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_DecodeRuneInString_obj::run( ){
	HX_STACK_PUSH("Go_utf8_DecodeRuneInString::run","tardis/Go.hx",5634);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5634)
	while((true)){
		HX_STACK_LINE(5636)
		::tardis::Go_utf8_DecodeRuneInString _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5636)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5638)
				{
					HX_STACK_LINE(5638)
					this->_latestPH = (int)762;
					HX_STACK_LINE(5638)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5639)
				this->_latestPH = (int)763;
				HX_STACK_LINE(5640)
				this->_SF1 = ::tardis::_Go::Go_utf8_decodeRuneInStringInternal_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->p_s);
				HX_STACK_LINE(5641)
				this->_Next = (int)-1;
				HX_STACK_LINE(5642)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(5644)
				{
					HX_STACK_LINE(5644)
					this->_latestPH = (int)763;
					HX_STACK_LINE(5644)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(5645)
				this->_t0 = this->_SF1->res();
				HX_STACK_LINE(5647)
				{
					HX_STACK_LINE(5647)
					this->_t1 = this->_t0->__Field(HX_CSTRING("r0"),true);
					HX_STACK_LINE(5647)
					this->_t2 = this->_t0->__Field(HX_CSTRING("r1"),true);
				}
				HX_STACK_LINE(5648)
				this->_latestPH = (int)764;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::Go_utf8_DecodeRuneInString_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",5649);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t1,false);
							__result->Add(HX_CSTRING("r1") , __this->_t2,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(5649)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(5650)
				this->_incomplete = false;
				HX_STACK_LINE(5651)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5652)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(5654)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5634)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeRuneInString_obj,run,return )

Dynamic Go_utf8_DecodeRuneInString_obj::res( ){
	HX_STACK_PUSH("Go_utf8_DecodeRuneInString::res","tardis/Go.hx",5614);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5614)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeRuneInString_obj,res,return )

Dynamic Go_utf8_DecodeRuneInString_obj::callFromHaxe( ::String p_s){
	HX_STACK_PUSH("Go_utf8_DecodeRuneInString::callFromHaxe","tardis/Go.hx",5620);
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(5621)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(5621)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(5622)
	::tardis::Go_utf8_DecodeRuneInString _sf = hx::TCast< ::tardis::Go_utf8_DecodeRuneInString >::cast(::tardis::Go_utf8_DecodeRuneInString_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5623)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5623)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(5624)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_DecodeRuneInString_obj,callFromHaxe,return )

Dynamic Go_utf8_DecodeRuneInString_obj::callFromRT( int _gr,::String p_s){
	HX_STACK_PUSH("Go_utf8_DecodeRuneInString::callFromRT","tardis/Go.hx",5626);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(5627)
	::tardis::Go_utf8_DecodeRuneInString _sf = hx::TCast< ::tardis::Go_utf8_DecodeRuneInString >::cast(::tardis::Go_utf8_DecodeRuneInString_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_s)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(5628)
	while((_sf->_incomplete)){
		HX_STACK_LINE(5628)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(5628)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(5628)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(5628)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(5629)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_DecodeRuneInString_obj,callFromRT,return )

::tardis::Go_utf8_DecodeRuneInString Go_utf8_DecodeRuneInString_obj::call( int gr,Dynamic _bds,::String p_s){
	HX_STACK_PUSH("Go_utf8_DecodeRuneInString::call","tardis/Go.hx",5632);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_s,"p_s");
	HX_STACK_LINE(5632)
	return ::tardis::Go_utf8_DecodeRuneInString_obj::__new(gr,_bds,p_s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_DecodeRuneInString_obj,call,return )


Go_utf8_DecodeRuneInString_obj::Go_utf8_DecodeRuneInString_obj()
{
}

void Go_utf8_DecodeRuneInString_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_DecodeRuneInString);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t2,"_t2");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_s,"p_s");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_DecodeRuneInString_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_s,"p_s");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_DecodeRuneInString_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t2") ) { return _t2; }
		if (HX_FIELD_EQ(inName,"_t1") ) { return _t1; }
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

Dynamic Go_utf8_DecodeRuneInString_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_s") ) { p_s=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_SF1") ) { _SF1=inValue.Cast< ::tardis::StackFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf8_DecodeRuneInString_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t2"));
	outFields->push(HX_CSTRING("_t1"));
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
	HX_CSTRING("_t2"),
	HX_CSTRING("_t1"),
	HX_CSTRING("_t0"),
	HX_CSTRING("_SF1"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_DecodeRuneInString_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_DecodeRuneInString_obj::__mClass,"__mClass");
};

Class Go_utf8_DecodeRuneInString_obj::__mClass;

void Go_utf8_DecodeRuneInString_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_DecodeRuneInString"), hx::TCanCast< Go_utf8_DecodeRuneInString_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_DecodeRuneInString_obj::__boot()
{
}

} // end namespace tardis
