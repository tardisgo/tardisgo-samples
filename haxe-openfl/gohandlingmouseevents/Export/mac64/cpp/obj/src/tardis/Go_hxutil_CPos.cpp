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
#ifndef INCLUDED_tardis_Go_hxutil_CPos
#include <tardis/Go_hxutil_CPos.h>
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

Void Go_hxutil_CPos_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_hxutil_CPos::new","tardis/Go.hx",8049);
{
	HX_STACK_LINE(8057)
	this->_Next = (int)0;
	HX_STACK_LINE(8051)
	super::__construct(gr,(int)996,HX_CSTRING("Go_hxutil_CPos"));
	HX_STACK_LINE(8052)
	this->_bds = _bds;
	HX_STACK_LINE(8053)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_hxutil_CPos_obj::~Go_hxutil_CPos_obj() { }

Dynamic Go_hxutil_CPos_obj::__CreateEmpty() { return  new Go_hxutil_CPos_obj; }
hx::ObjectPtr< Go_hxutil_CPos_obj > Go_hxutil_CPos_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_hxutil_CPos_obj > result = new Go_hxutil_CPos_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_hxutil_CPos_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_hxutil_CPos_obj > result = new Go_hxutil_CPos_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_hxutil_CPos_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

::tardis::StackFrame Go_hxutil_CPos_obj::run( ){
	HX_STACK_PUSH("Go_hxutil_CPos::run","tardis/Go.hx",8072);
	HX_STACK_THIS(this);
	HX_STACK_LINE(8072)
	while((true)){
		HX_STACK_LINE(8074)
		::tardis::Go_hxutil_CPos _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(8074)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(8076)
				{
					HX_STACK_LINE(8076)
					this->_latestPH = (int)996;
					HX_STACK_LINE(8076)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(8077)
				this->_res = HX_CSTRING("<<go code pos>>");
				HX_STACK_LINE(8078)
				this->_incomplete = false;
				HX_STACK_LINE(8079)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(8080)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(8082)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(8072)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_CPos_obj,run,return )

Dynamic Go_hxutil_CPos_obj::res( ){
	HX_STACK_PUSH("Go_hxutil_CPos::res","tardis/Go.hx",8056);
	HX_STACK_THIS(this);
	HX_STACK_LINE(8056)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_CPos_obj,res,return )

::String Go_hxutil_CPos_obj::callFromHaxe( ){
	HX_STACK_PUSH("Go_hxutil_CPos::callFromHaxe","tardis/Go.hx",8058);
	HX_STACK_LINE(8059)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(8059)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(8060)
	::tardis::Go_hxutil_CPos _sf = hx::TCast< ::tardis::Go_hxutil_CPos >::cast(::tardis::Go_hxutil_CPos_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(8061)
	while((_sf->_incomplete)){
		HX_STACK_LINE(8061)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(8062)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_hxutil_CPos_obj,callFromHaxe,return )

::String Go_hxutil_CPos_obj::callFromRT( int _gr){
	HX_STACK_PUSH("Go_hxutil_CPos::callFromRT","tardis/Go.hx",8064);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_LINE(8065)
	::tardis::Go_hxutil_CPos _sf = hx::TCast< ::tardis::Go_hxutil_CPos >::cast(::tardis::Go_hxutil_CPos_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(8066)
	while((_sf->_incomplete)){
		HX_STACK_LINE(8066)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(8066)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(8066)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(8066)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(8067)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_hxutil_CPos_obj,callFromRT,return )

::tardis::Go_hxutil_CPos Go_hxutil_CPos_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_hxutil_CPos::call","tardis/Go.hx",8070);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(8070)
	return ::tardis::Go_hxutil_CPos_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_hxutil_CPos_obj,call,return )


Go_hxutil_CPos_obj::Go_hxutil_CPos_obj()
{
}

void Go_hxutil_CPos_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_hxutil_CPos);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_res,"_res");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_hxutil_CPos_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_hxutil_CPos_obj::__Field(const ::String &inName,bool inCallProp)
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
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_hxutil_CPos_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_hxutil_CPos_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_res"));
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
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_hxutil_CPos_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_hxutil_CPos_obj::__mClass,"__mClass");
};

Class Go_hxutil_CPos_obj::__mClass;

void Go_hxutil_CPos_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_hxutil_CPos"), hx::TCanCast< Go_hxutil_CPos_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_hxutil_CPos_obj::__boot()
{
}

} // end namespace tardis
