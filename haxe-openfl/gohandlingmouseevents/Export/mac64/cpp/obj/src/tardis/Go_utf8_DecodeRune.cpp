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
#ifndef INCLUDED_tardis_Go_utf8_DecodeRune
#include <tardis/Go_utf8_DecodeRune.h>
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
#ifndef INCLUDED_tardis__Go_Go_utf8_decodeRuneInternal
#include <tardis/_Go/Go_utf8_decodeRuneInternal.h>
#endif
namespace tardis{

Void Go_utf8_DecodeRune_obj::__construct(int gr,Dynamic _bds,::tardis::Slice p_p)
{
HX_STACK_PUSH("Go_utf8_DecodeRune::new","tardis/Go.hx",8084);
{
	HX_STACK_LINE(8098)
	this->_Next = (int)0;
	HX_STACK_LINE(8097)
	this->_t2 = (int)0;
	HX_STACK_LINE(8096)
	this->_t1 = (int)0;
	HX_STACK_LINE(8095)
	this->_t0 = null();
	HX_STACK_LINE(8087)
	super::__construct(gr,(int)752,HX_CSTRING("Go_utf8_DecodeRune"));
	HX_STACK_LINE(8088)
	this->_bds = _bds;
	HX_STACK_LINE(8089)
	this->p_p = p_p;
	HX_STACK_LINE(8090)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf8_DecodeRune_obj::~Go_utf8_DecodeRune_obj() { }

Dynamic Go_utf8_DecodeRune_obj::__CreateEmpty() { return  new Go_utf8_DecodeRune_obj; }
hx::ObjectPtr< Go_utf8_DecodeRune_obj > Go_utf8_DecodeRune_obj::__new(int gr,Dynamic _bds,::tardis::Slice p_p)
{  hx::ObjectPtr< Go_utf8_DecodeRune_obj > result = new Go_utf8_DecodeRune_obj();
	result->__construct(gr,_bds,p_p);
	return result;}

Dynamic Go_utf8_DecodeRune_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf8_DecodeRune_obj > result = new Go_utf8_DecodeRune_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_utf8_DecodeRune_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf8_DecodeRune_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf8_DecodeRune::SubFn0","tardis/Go.hx",8134);
		HX_STACK_THIS(this);
		HX_STACK_LINE(8135)
		this->_t1 = this->_t0->__Field(HX_CSTRING("r0"),true);
		HX_STACK_LINE(8136)
		this->_t2 = this->_t0->__Field(HX_CSTRING("r1"),true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeRune_obj,SubFn0,(void))

::tardis::StackFrame Go_utf8_DecodeRune_obj::run( ){
	HX_STACK_PUSH("Go_utf8_DecodeRune::run","tardis/Go.hx",8113);
	HX_STACK_THIS(this);
	HX_STACK_LINE(8113)
	while((true)){
		HX_STACK_LINE(8115)
		::tardis::Go_utf8_DecodeRune _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(8115)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(8117)
				{
					HX_STACK_LINE(8117)
					this->_latestPH = (int)752;
					HX_STACK_LINE(8117)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(8118)
				this->_latestPH = (int)753;
				HX_STACK_LINE(8119)
				this->_SF1 = ::tardis::_Go::Go_utf8_decodeRuneInternal_obj::__new(this->_goroutine,Dynamic( Array_obj<Dynamic>::__new()),this->p_p);
				HX_STACK_LINE(8120)
				this->_Next = (int)-1;
				HX_STACK_LINE(8121)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(8123)
				{
					HX_STACK_LINE(8123)
					this->_latestPH = (int)753;
					HX_STACK_LINE(8123)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(8124)
				this->_t0 = this->_SF1->res();
				HX_STACK_LINE(8126)
				{
					HX_STACK_LINE(8126)
					this->_t1 = this->_t0->__Field(HX_CSTRING("r0"),true);
					HX_STACK_LINE(8126)
					this->_t2 = this->_t0->__Field(HX_CSTRING("r1"),true);
				}
				HX_STACK_LINE(8127)
				this->_latestPH = (int)754;
				struct _Function_3_1{
					inline static Dynamic Block( ::tardis::Go_utf8_DecodeRune_obj *__this){
						HX_STACK_PUSH("*::closure","tardis/Go.hx",8128);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("r0") , __this->_t1,false);
							__result->Add(HX_CSTRING("r1") , __this->_t2,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(8128)
				this->_res = _Function_3_1::Block(this);
				HX_STACK_LINE(8129)
				this->_incomplete = false;
				HX_STACK_LINE(8130)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(8131)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(8133)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(8113)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeRune_obj,run,return )

Dynamic Go_utf8_DecodeRune_obj::res( ){
	HX_STACK_PUSH("Go_utf8_DecodeRune::res","tardis/Go.hx",8093);
	HX_STACK_THIS(this);
	HX_STACK_LINE(8093)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf8_DecodeRune_obj,res,return )

Dynamic Go_utf8_DecodeRune_obj::callFromHaxe( ::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_DecodeRune::callFromHaxe","tardis/Go.hx",8099);
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(8100)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(8100)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(8101)
	::tardis::Go_utf8_DecodeRune _sf = hx::TCast< ::tardis::Go_utf8_DecodeRune >::cast(::tardis::Go_utf8_DecodeRune_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(8102)
	while((_sf->_incomplete)){
		HX_STACK_LINE(8102)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(8103)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf8_DecodeRune_obj,callFromHaxe,return )

Dynamic Go_utf8_DecodeRune_obj::callFromRT( int _gr,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_DecodeRune::callFromRT","tardis/Go.hx",8105);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(8106)
	::tardis::Go_utf8_DecodeRune _sf = hx::TCast< ::tardis::Go_utf8_DecodeRune >::cast(::tardis::Go_utf8_DecodeRune_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_p)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(8107)
	while((_sf->_incomplete)){
		HX_STACK_LINE(8107)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(8107)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(8107)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(8107)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(8108)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf8_DecodeRune_obj,callFromRT,return )

::tardis::Go_utf8_DecodeRune Go_utf8_DecodeRune_obj::call( int gr,Dynamic _bds,::tardis::Slice p_p){
	HX_STACK_PUSH("Go_utf8_DecodeRune::call","tardis/Go.hx",8111);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_p,"p_p");
	HX_STACK_LINE(8111)
	return ::tardis::Go_utf8_DecodeRune_obj::__new(gr,_bds,p_p);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_utf8_DecodeRune_obj,call,return )


Go_utf8_DecodeRune_obj::Go_utf8_DecodeRune_obj()
{
}

void Go_utf8_DecodeRune_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf8_DecodeRune);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t2,"_t2");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_SF1,"_SF1");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_p,"p_p");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf8_DecodeRune_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t2,"_t2");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_SF1,"_SF1");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_p,"p_p");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf8_DecodeRune_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t2") ) { return _t2; }
		if (HX_FIELD_EQ(inName,"_t1") ) { return _t1; }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		if (HX_FIELD_EQ(inName,"p_p") ) { return p_p; }
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

Dynamic Go_utf8_DecodeRune_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t2") ) { _t2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_p") ) { p_p=inValue.Cast< ::tardis::Slice >(); return inValue; }
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

void Go_utf8_DecodeRune_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t2"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_SF1"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_p"));
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
	HX_CSTRING("p_p"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf8_DecodeRune_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf8_DecodeRune_obj::__mClass,"__mClass");
};

Class Go_utf8_DecodeRune_obj::__mClass;

void Go_utf8_DecodeRune_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_utf8_DecodeRune"), hx::TCanCast< Go_utf8_DecodeRune_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf8_DecodeRune_obj::__boot()
{
}

} // end namespace tardis
