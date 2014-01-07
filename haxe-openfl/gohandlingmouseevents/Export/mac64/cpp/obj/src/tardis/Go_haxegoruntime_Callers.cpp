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
#ifndef INCLUDED_tardis_Go_haxegoruntime_Callers
#include <tardis/Go_haxegoruntime_Callers.h>
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

Void Go_haxegoruntime_Callers_obj::__construct(int gr,Dynamic _bds,int p_skip,::tardis::Slice p_pc)
{
HX_STACK_PUSH("Go_haxegoruntime_Callers::new","tardis/Go.hx",3919);
{
	HX_STACK_LINE(3932)
	this->_Next = (int)0;
	HX_STACK_LINE(3931)
	this->_t0 = null();
	HX_STACK_LINE(3923)
	super::__construct(gr,(int)393,HX_CSTRING("Go_haxegoruntime_Callers"));
	HX_STACK_LINE(3924)
	this->_bds = _bds;
	HX_STACK_LINE(3925)
	this->p_skip = p_skip;
	HX_STACK_LINE(3926)
	this->p_pc = p_pc;
	HX_STACK_LINE(3927)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_haxegoruntime_Callers_obj::~Go_haxegoruntime_Callers_obj() { }

Dynamic Go_haxegoruntime_Callers_obj::__CreateEmpty() { return  new Go_haxegoruntime_Callers_obj; }
hx::ObjectPtr< Go_haxegoruntime_Callers_obj > Go_haxegoruntime_Callers_obj::__new(int gr,Dynamic _bds,int p_skip,::tardis::Slice p_pc)
{  hx::ObjectPtr< Go_haxegoruntime_Callers_obj > result = new Go_haxegoruntime_Callers_obj();
	result->__construct(gr,_bds,p_skip,p_pc);
	return result;}

Dynamic Go_haxegoruntime_Callers_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_haxegoruntime_Callers_obj > result = new Go_haxegoruntime_Callers_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *Go_haxegoruntime_Callers_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_haxegoruntime_Callers_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_haxegoruntime_Callers::SubFn0","tardis/Go.hx",3962);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3962)
		this->_t0 = ::tardis::Interface_obj::__new((int)0,HX_CSTRING("runtime.Callers() not yet implemented"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Callers_obj,SubFn0,(void))

::tardis::StackFrame Go_haxegoruntime_Callers_obj::run( ){
	HX_STACK_PUSH("Go_haxegoruntime_Callers::run","tardis/Go.hx",3947);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3947)
	while((true)){
		HX_STACK_LINE(3949)
		::tardis::Go_haxegoruntime_Callers _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3949)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(3951)
				{
					HX_STACK_LINE(3951)
					this->_latestPH = (int)393;
					HX_STACK_LINE(3951)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(3952)
				this->_t0 = ::tardis::Interface_obj::__new((int)0,HX_CSTRING("runtime.Callers() not yet implemented"));
				HX_STACK_LINE(3953)
				::tardis::Scheduler_obj::panic(this->_goroutine,this->_t0);
				HX_STACK_LINE(3953)
				this->_Next = (int)-1;
				HX_STACK_LINE(3954)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			case (int)-1: {
				HX_STACK_LINE(3956)
				{
					HX_STACK_LINE(3956)
					this->_latestPH = (int)393;
					HX_STACK_LINE(3956)
					this->_latestBlock = (int)-1;
				}
				HX_STACK_LINE(3959)
				this->_incomplete = false;
				HX_STACK_LINE(3960)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(3961)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(3961)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(3947)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Callers_obj,run,return )

Dynamic Go_haxegoruntime_Callers_obj::res( ){
	HX_STACK_PUSH("Go_haxegoruntime_Callers::res","tardis/Go.hx",3930);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3930)
	return this->_res;
}


HX_DEFINE_DYNAMIC_FUNC0(Go_haxegoruntime_Callers_obj,res,return )

int Go_haxegoruntime_Callers_obj::callFromHaxe( int p_skip,::tardis::Slice p_pc){
	HX_STACK_PUSH("Go_haxegoruntime_Callers::callFromHaxe","tardis/Go.hx",3933);
	HX_STACK_ARG(p_skip,"p_skip");
	HX_STACK_ARG(p_pc,"p_pc");
	HX_STACK_LINE(3934)
	if ((!(::tardis::Go_obj::doneInit))){
		HX_STACK_LINE(3934)
		::tardis::Go_obj::init();
	}
	HX_STACK_LINE(3935)
	::tardis::Go_haxegoruntime_Callers _sf = hx::TCast< ::tardis::Go_haxegoruntime_Callers >::cast(::tardis::Go_haxegoruntime_Callers_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()),p_skip,p_pc)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3936)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3936)
		::tardis::Scheduler_obj::runAll();
	}
	HX_STACK_LINE(3937)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_haxegoruntime_Callers_obj,callFromHaxe,return )

int Go_haxegoruntime_Callers_obj::callFromRT( int _gr,int p_skip,::tardis::Slice p_pc){
	HX_STACK_PUSH("Go_haxegoruntime_Callers::callFromRT","tardis/Go.hx",3939);
	HX_STACK_ARG(_gr,"_gr");
	HX_STACK_ARG(p_skip,"p_skip");
	HX_STACK_ARG(p_pc,"p_pc");
	HX_STACK_LINE(3940)
	::tardis::Go_haxegoruntime_Callers _sf = hx::TCast< ::tardis::Go_haxegoruntime_Callers >::cast(::tardis::Go_haxegoruntime_Callers_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()),p_skip,p_pc)->run());		HX_STACK_VAR(_sf,"_sf");
	HX_STACK_LINE(3941)
	while((_sf->_incomplete)){
		HX_STACK_LINE(3941)
		if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
			HX_STACK_LINE(3941)
			hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
		}
		else{
			HX_STACK_LINE(3941)
			::tardis::Scheduler_obj::currentGR = _gr;
			HX_STACK_LINE(3941)
			::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
		}
	}
	HX_STACK_LINE(3942)
	return _sf->_res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Go_haxegoruntime_Callers_obj,callFromRT,return )

::tardis::Go_haxegoruntime_Callers Go_haxegoruntime_Callers_obj::call( int gr,Dynamic _bds,int p_skip,::tardis::Slice p_pc){
	HX_STACK_PUSH("Go_haxegoruntime_Callers::call","tardis/Go.hx",3945);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_ARG(p_skip,"p_skip");
	HX_STACK_ARG(p_pc,"p_pc");
	HX_STACK_LINE(3945)
	return ::tardis::Go_haxegoruntime_Callers_obj::__new(gr,_bds,p_skip,p_pc);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Go_haxegoruntime_Callers_obj,call,return )


Go_haxegoruntime_Callers_obj::Go_haxegoruntime_Callers_obj()
{
}

void Go_haxegoruntime_Callers_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_haxegoruntime_Callers);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	HX_MARK_MEMBER_NAME(_res,"_res");
	HX_MARK_MEMBER_NAME(p_pc,"p_pc");
	HX_MARK_MEMBER_NAME(p_skip,"p_skip");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_haxegoruntime_Callers_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	HX_VISIT_MEMBER_NAME(_res,"_res");
	HX_VISIT_MEMBER_NAME(p_pc,"p_pc");
	HX_VISIT_MEMBER_NAME(p_skip,"p_skip");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_haxegoruntime_Callers_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"p_skip") ) { return p_skip; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callFromRT") ) { return callFromRT_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFromHaxe") ) { return callFromHaxe_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Go_haxegoruntime_Callers_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< ::tardis::Interface >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_res") ) { _res=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_pc") ) { p_pc=inValue.Cast< ::tardis::Slice >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"p_skip") ) { p_skip=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_haxegoruntime_Callers_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t0"));
	outFields->push(HX_CSTRING("_res"));
	outFields->push(HX_CSTRING("p_pc"));
	outFields->push(HX_CSTRING("p_skip"));
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
	HX_CSTRING("p_skip"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_haxegoruntime_Callers_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_haxegoruntime_Callers_obj::__mClass,"__mClass");
};

Class Go_haxegoruntime_Callers_obj::__mClass;

void Go_haxegoruntime_Callers_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Go_haxegoruntime_Callers"), hx::TCanCast< Go_haxegoruntime_Callers_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_haxegoruntime_Callers_obj::__boot()
{
}

} // end namespace tardis
