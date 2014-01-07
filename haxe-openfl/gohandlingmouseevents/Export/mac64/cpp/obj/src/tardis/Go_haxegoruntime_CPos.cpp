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
#ifndef INCLUDED_tardis_Go_haxegoruntime_CPos
#include <tardis/Go_haxegoruntime_CPos.h>
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

Void Go_haxegoruntime_CPos_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_haxegoruntime_CPos::new","tardis/Go.hx",7914);
{
	HX_STACK_LINE(7922)
	this->_Next = (int)0;
	HX_STACK_LINE(7916)
	super::__construct(gr,(int)181,HX_CSTRING("Go_haxegoruntime_CPos"));
	HX_STACK_LINE(7917)
	this->_bds = _bds;
	HX_STACK_LINE(7918)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_CPos_obj::~Go_haxegoruntime_CPos_obj() { }

Dynamic Go_haxegoruntime_CPos_obj::__CreateEmpty() { return  new Go_haxegoruntime_CPos_obj; }
hx::ObjectPtr< Go_haxegoruntime_CPos_obj > Go_haxegoruntime_CPos_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_haxegoruntime_CPos_obj > result = new Go_haxegoruntime_CPos_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_haxegoruntime_CPos_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_CPos_obj > result = new Go_haxegoruntime_CPos_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_haxegoruntime_CPos_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

::tardis::StackFrame Go_haxegoruntime_CPos_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_CPos::run","tardis/Go.hx",7937);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7937)
	while((true)){
		HX_STACK_LINE(7939)
		::tardis::Go_haxegoruntime_CPos _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(7939)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(7941)
				{
					HX_STACK_LINE(7941)
					this->_latestPH = (int)181;
					HX_STACK_LINE(7941)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(7942)
				this->_res = HX_CSTRING("<<code pos>>");
				HX_STACK_LINE(7943)
				this->_incomplete = false;
				HX_STACK_LINE(7944)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(7945)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(7947)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(7937)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_CPos_obj,run,return )

Dynamic Go_haxegoruntime_CPos_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_CPos::res","tardis/Go.hx",7921);
	HX_STACK_THIS(this);
	HX_STACK_LINE(7921)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_CPos_obj,res,return )

::String Go_haxegoruntime_CPos_obj::callFromHaxe( ){
	HX_STACK_PUSH("Go_haxegoruntime_CPos::callFromHaxe","tardis/Go.hx",7923);
	HX_STACK_LINE(7924)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(7924)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(7925)
	::tardis::Go_haxegoruntime_CPos _sf = hx::TCast< ::tardis::Go_haxegoruntime_CPos >::cast(::tardis::Go_haxegoruntime_CPos_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7926)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7926)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(7927)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_CPos_obj,callFromHaxe,return )

::String Go_haxegoruntime_CPos_obj::callFromRT( int _gr){
	HX_STACK_PUSH("Go_haxegoruntime_CPos::callFromRT","tardis/Go.hx",7929);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_LINE(7930)
	::tardis::Go_haxegoruntime_CPos _sf = hx::TCast< ::tardis::Go_haxegoruntime_CPos >::cast(::tardis::Go_haxegoruntime_CPos_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(7931)
	while((_sf->_incomplete)){
		HX_STACK_LINE(7931)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(7931)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(7931)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(7931)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(7932)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_CPos_obj,callFromRT,return )

::tardis::Go_haxegoruntime_CPos Go_haxegoruntime_CPos_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_haxegoruntime_CPos::call","tardis/Go.hx",7935);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(7935)
	return ::tardis::Go_haxegoruntime_CPos_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_CPos_obj,call,return )


Go_haxegoruntime_CPos_obj::Go_haxegoruntime_CPos_obj()
{
}

void Go_haxegoruntime_CPos_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_CPos);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_res,"_res");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_CPos_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_CPos_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Go_haxegoruntime_CPos_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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

void Go_haxegoruntime_CPos_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_CPos_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_CPos_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_CPos_obj::__mClass;

void Go_haxegoruntime_CPos_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_CPos"), hx::TCanCast< Go_haxegoruntime_CPos_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_CPos_obj::__boot()
{
}

} // end namespace tardis
