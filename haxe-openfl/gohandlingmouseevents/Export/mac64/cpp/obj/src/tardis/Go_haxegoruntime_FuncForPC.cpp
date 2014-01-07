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
#ifndef INCLUDED_tardis_Go_haxegoruntime_FuncForPC
#include <tardis/Go_haxegoruntime_FuncForPC.h>
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
namespace tardis{

Void Go_haxegoruntime_FuncForPC_obj::__construct(int gr,Dynamic _bds,Dynamic p_pc)
{
HX_STACK_PUSH("Go_haxegoruntime_FuncForPC::new","tardis/Go.hx",6920);
{
	HX_STACK_LINE(6931)
	this->_Next = (int)0;
	HX_STACK_LINE(6930)
	this->_t0 = null();
	HX_STACK_LINE(6923)
	super::__construct(gr,(int)394,HX_CSTRING("Go_haxegoruntime_FuncForPC"));
	HX_STACK_LINE(6924)
	this->_bds = _bds;
	HX_STACK_LINE(6925)
	this->p_pc = p_pc;
	HX_STACK_LINE(6926)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_FuncForPC_obj::~Go_haxegoruntime_FuncForPC_obj() { }

Dynamic Go_haxegoruntime_FuncForPC_obj::__CreateEmpty() { return  new Go_haxegoruntime_FuncForPC_obj; }
hx::ObjectPtr< Go_haxegoruntime_FuncForPC_obj > Go_haxegoruntime_FuncForPC_obj::__new(int gr,Dynamic _bds,Dynamic p_pc)
{  hx::ObjectPtr< Go_haxegoruntime_FuncForPC_obj > result = new Go_haxegoruntime_FuncForPC_obj();
	result->__construct(gr,_bds,p_pc);
	return result;}

Dynamic Go_haxegoruntime_FuncForPC_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_FuncForPC_obj > result = new Go_haxegoruntime_FuncForPC_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Go_haxegoruntime_FuncForPC_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_FuncForPC_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_FuncForPC::SubFn0","tardis/Go.hx",6961);
		HX_STACK_THIS(this);
		HX_STACK_LINE(6961)
		this->_t0 = ::tardis::Interface_obj::__new((int)0,HX_CSTRING("runtime.FuncForPC() not yet implemented"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_FuncForPC_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_FuncForPC_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_FuncForPC::run","tardis/Go.hx",6946);
	HX_STACK_THIS(this);
	HX_STACK_LINE(6946)
	while((true)){
		HX_STACK_LINE(6948)
		::tardis::Go_haxegoruntime_FuncForPC _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(6948)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(6950)
				{
					HX_STACK_LINE(6950)
					this->_latestPH = (int)394;
					HX_STACK_LINE(6950)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(6951)
				this->_t0 = ::tardis::Interface_obj::__new((int)0,HX_CSTRING("runtime.FuncForPC() not yet implemented"));
				HX_STACK_LINE(6952)
				::tardis::Scheduler_obj::panic(this->_goroutine,this->_t0);
				HX_STACK_LINE(6952)
				this->_Next = (int)-1;
				HX_STACK_LINE(6953)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(6955)
				{
					HX_STACK_LINE(6955)
					this->_latestPH = (int)394;
					HX_STACK_LINE(6955)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(6958)
				this->_incomplete = false;
				HX_STACK_LINE(6959)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(6960)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(6960)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(6946)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_FuncForPC_obj,run,return )

Dynamic Go_haxegoruntime_FuncForPC_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_FuncForPC::res","tardis/Go.hx",6929);
	HX_STACK_THIS(this);
	HX_STACK_LINE(6929)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_FuncForPC_obj,res,return )

::tardis::Pointer Go_haxegoruntime_FuncForPC_obj::callFromHaxe( Dynamic p_pc){
	HX_STACK_PUSH("Go_haxegoruntime_FuncForPC::callFromHaxe","tardis/Go.hx",6932);
	HX_STACK_ARG(p_pc,"p_pc");
	HX_STACK_LINE(6933)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(6933)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(6934)
	::tardis::Go_haxegoruntime_FuncForPC _sf = hx::TCast< ::tardis::Go_haxegoruntime_FuncForPC >::cast(::tardis::Go_haxegoruntime_FuncForPC_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_pc)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(6935)
	while((_sf->_incomplete)){
		HX_STACK_LINE(6935)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(6936)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_haxegoruntime_FuncForPC_obj,callFromHaxe,return )

::tardis::Pointer Go_haxegoruntime_FuncForPC_obj::callFromRT( int _gr,Dynamic p_pc){
	HX_STACK_PUSH("Go_haxegoruntime_FuncForPC::callFromRT","tardis/Go.hx",6938);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_pc,"p_pc");
	HX_STACK_LINE(6939)
	::tardis::Go_haxegoruntime_FuncForPC _sf = hx::TCast< ::tardis::Go_haxegoruntime_FuncForPC >::cast(::tardis::Go_haxegoruntime_FuncForPC_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_pc)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(6940)
	while((_sf->_incomplete)){
		HX_STACK_LINE(6940)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(6940)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(6940)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(6940)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(6941)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_FuncForPC_obj,callFromRT,return )

::tardis::Go_haxegoruntime_FuncForPC Go_haxegoruntime_FuncForPC_obj::call( int gr,Dynamic _bds,Dynamic p_pc){
	HX_STACK_PUSH("Go_haxegoruntime_FuncForPC::call","tardis/Go.hx",6944);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_pc,"p_pc");
	HX_STACK_LINE(6944)
	return ::tardis::Go_haxegoruntime_FuncForPC_obj::__new(gr,_bds,p_pc);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_haxegoruntime_FuncForPC_obj,call,return )


Go_haxegoruntime_FuncForPC_obj::Go_haxegoruntime_FuncForPC_obj()
{
}

void Go_haxegoruntime_FuncForPC_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_FuncForPC);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_pc,"p_pc");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_FuncForPC_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_pc,"p_pc");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_FuncForPC_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		if (HX_FIELD_EQ(inName,"_res") ) { return _res; }
		if (HX_FIELD_EQ(inName,"p_pc") ) { return p_pc; }
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

Dynamic Go_haxegoruntime_FuncForPC_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< ::tardis::Pointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_pc") ) { p_pc=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_FuncForPC_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_pc"));
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
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	HX_CSTRING("_res"),
	HX_CSTRING("p_pc"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_FuncForPC_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_FuncForPC_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_FuncForPC_obj::__mClass;

void Go_haxegoruntime_FuncForPC_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_FuncForPC"), hx::TCanCast< Go_haxegoruntime_FuncForPC_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_FuncForPC_obj::__boot()
{
}

} // end namespace tardis
