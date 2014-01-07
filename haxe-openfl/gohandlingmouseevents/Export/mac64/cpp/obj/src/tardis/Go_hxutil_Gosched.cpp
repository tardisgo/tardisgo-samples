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
#ifndef INCLUDED_tardis_Go_hxutil_Gosched
#include <tardis/Go_hxutil_Gosched.h>
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

Void Go_hxutil_Gosched_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_hxutil_Gosched::new","tardis/Go.hx",5183);
{
	HX_STACK_LINE(5190)
	this->_Next = (int)0;
	HX_STACK_LINE(5185)
	super::__construct(gr,(int)1013,HX_CSTRING("Go_hxutil_Gosched"));
	HX_STACK_LINE(5186)
	this->_bds = _bds;
	HX_STACK_LINE(5187)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_hxutil_Gosched_obj::~Go_hxutil_Gosched_obj() { }

Dynamic Go_hxutil_Gosched_obj::__CreateEmpty() { return  new Go_hxutil_Gosched_obj; }
hx::ObjectPtr< Go_hxutil_Gosched_obj > Go_hxutil_Gosched_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_hxutil_Gosched_obj > result = new Go_hxutil_Gosched_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_hxutil_Gosched_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_hxutil_Gosched_obj > result = new Go_hxutil_Gosched_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_hxutil_Gosched_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

::tardis::StackFrame Go_hxutil_Gosched_obj::run( ){
	HX_STACK_PUSH("Go_hxutil_Gosched::run","tardis/Go.hx",5203);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5203)
	while((true)){
		HX_STACK_LINE(5205)
		::tardis::Go_hxutil_Gosched _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5205)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5207)
				{
					HX_STACK_LINE(5207)
					this->_latestPH = (int)1013;
					HX_STACK_LINE(5207)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5208)
				this->_incomplete = false;
				HX_STACK_LINE(5209)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5210)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(5212)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5203)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_Gosched_obj,run,return )

Dynamic Go_hxutil_Gosched_obj::res( ){
	HX_STACK_PUSH("Go_hxutil_Gosched::res","tardis/Go.hx",5189);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5189)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_Gosched_obj,res,return )

Void Go_hxutil_Gosched_obj::callFromHaxe( ){
{
		HX_STACK_PUSH("Go_hxutil_Gosched::callFromHaxe","tardis/Go.hx",5191);
		HX_STACK_LINE(5192)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(5192)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(5193)
		::tardis::Go_hxutil_Gosched _sf = hx::TCast< ::tardis::Go_hxutil_Gosched >::cast(::tardis::Go_hxutil_Gosched_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(5194)
		while((_sf->_incomplete)){
			HX_STACK_LINE(5194)
			::tardis::Scheduler_obj::runAll();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_Gosched_obj,callFromHaxe,(void))

Void Go_hxutil_Gosched_obj::callFromRT( int _gr){
{
		HX_STACK_PUSH("Go_hxutil_Gosched::callFromRT","tardis/Go.hx",5196);
		HX_STACK_ARG(_gr,"_gr");
		HX_STACK_LINE(5197)
		::tardis::Go_hxutil_Gosched _sf = hx::TCast< ::tardis::Go_hxutil_Gosched >::cast(::tardis::Go_hxutil_Gosched_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(5198)
		while((_sf->_incomplete)){
			HX_STACK_LINE(5198)
			if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
				HX_STACK_LINE(5198)
				hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
			}
			else{
				HX_STACK_LINE(5198)
				::tardis::Scheduler_obj::currentGR = _gr;
				HX_STACK_LINE(5198)
				::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_hxutil_Gosched_obj,callFromRT,(void))

::tardis::Go_hxutil_Gosched Go_hxutil_Gosched_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_hxutil_Gosched::call","tardis/Go.hx",5201);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(5201)
	return ::tardis::Go_hxutil_Gosched_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_hxutil_Gosched_obj,call,return )


Go_hxutil_Gosched_obj::Go_hxutil_Gosched_obj()
{
}

void Go_hxutil_Gosched_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_hxutil_Gosched);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_hxutil_Gosched_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_hxutil_Gosched_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
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

Dynamic Go_hxutil_Gosched_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_hxutil_Gosched_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
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
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_hxutil_Gosched_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_hxutil_Gosched_obj::__mClass,"__mClass");
};

Class Go_hxutil_Gosched_obj::__mClass;

void Go_hxutil_Gosched_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_hxutil_Gosched"), hx::TCanCast< Go_hxutil_Gosched_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_hxutil_Gosched_obj::__boot()
{
}

} // end namespace tardis
