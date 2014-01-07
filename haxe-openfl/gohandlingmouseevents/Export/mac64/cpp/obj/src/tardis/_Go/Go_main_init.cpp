#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_tardis_Channel
#include <tardis/Channel.h>
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
#ifndef INCLUDED_tardis__Go_Go_main_init
#include <tardis/_Go/Go_main_init.h>
#endif
namespace tardis{
namespace _Go{

Void Go_main_init_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_main_init::new","tardis/Go.hx",3247);
{
	HX_STACK_LINE(3256)
	this->_Next = (int)0;
	HX_STACK_LINE(3255)
	this->_t1 = null();
	HX_STACK_LINE(3254)
	this->_t0 = false;
	HX_STACK_LINE(3249)
	super::__construct(gr,(int)188,HX_CSTRING("Go_main_init"));
	HX_STACK_LINE(3250)
	this->_bds = _bds;
	HX_STACK_LINE(3251)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_main_init_obj::~Go_main_init_obj() { }

Dynamic Go_main_init_obj::__CreateEmpty() { return  new Go_main_init_obj; }
hx::ObjectPtr< Go_main_init_obj > Go_main_init_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_main_init_obj > result = new Go_main_init_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_main_init_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_main_init_obj > result = new Go_main_init_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_main_init_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_main_init_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_main_init::SubFn1","tardis/Go.hx",3292);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3293)
		::tardis::Channel _t1;		HX_STACK_VAR(_t1,"_t1");
		HX_STACK_LINE(3294)
		::tardis::Go_obj::main_init_36_guard->store(true);
		HX_STACK_LINE(3295)
		this->_latestPH = (int)14;
		HX_STACK_LINE(3296)
		_t1 = ::tardis::Channel_obj::__new((int)100);
		HX_STACK_LINE(3297)
		::tardis::Go_obj::main_mouseEvents->store(_t1);
		HX_STACK_LINE(3298)
		this->_Next = (int)2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_init_obj,SubFn1,(void))

Void Go_main_init_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_main_init::SubFn0","tardis/Go.hx",3287);
		HX_STACK_THIS(this);
		HX_STACK_LINE(3288)
		bool _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(3289)
		_t0 = ::tardis::Go_obj::main_init_36_guard->ref();
		HX_STACK_LINE(3290)
		this->_Next = (  ((_t0)) ? int((int)2) : int((int)1) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_init_obj,SubFn0,(void))

::tardis::StackFrame Go_main_init_obj::run( ){
	HX_STACK_PUSH("Go_main_init::run","tardis/Go.hx",3269);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3269)
	while((true)){
		HX_STACK_LINE(3271)
		::tardis::_Go::Go_main_init _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3271)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(3273)
				{
					HX_STACK_LINE(3273)
					this->_latestPH = (int)188;
					HX_STACK_LINE(3273)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(3274)
				{
					HX_STACK_LINE(3274)
					bool _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(3274)
					_t0 = ::tardis::Go_obj::main_init_36_guard->ref();
					HX_STACK_LINE(3274)
					this->_Next = (  ((_t0)) ? int((int)2) : int((int)1) );
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(3277)
				{
					HX_STACK_LINE(3277)
					this->_latestPH = (int)188;
					HX_STACK_LINE(3277)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(3278)
				{
					HX_STACK_LINE(3278)
					::tardis::Channel _t1;		HX_STACK_VAR(_t1,"_t1");
					HX_STACK_LINE(3278)
					::tardis::Go_obj::main_init_36_guard->store(true);
					HX_STACK_LINE(3278)
					this->_latestPH = (int)14;
					HX_STACK_LINE(3278)
					_t1 = ::tardis::Channel_obj::__new((int)100);
					HX_STACK_LINE(3278)
					::tardis::Go_obj::main_mouseEvents->store(_t1);
					HX_STACK_LINE(3278)
					this->_Next = (int)2;
				}
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(3281)
				{
					HX_STACK_LINE(3281)
					this->_latestPH = (int)188;
					HX_STACK_LINE(3281)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(3282)
				this->_incomplete = false;
				HX_STACK_LINE(3283)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(3284)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(3286)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(3269)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_init_obj,run,return )

Dynamic Go_main_init_obj::res( ){
	HX_STACK_PUSH("Go_main_init::res","tardis/Go.hx",3253);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3253)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_main_init_obj,res,return )

Void Go_main_init_obj::callFromHaxe( ){
{
		HX_STACK_PUSH("Go_main_init::callFromHaxe","tardis/Go.hx",3257);
		HX_STACK_LINE(3258)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(3258)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(3259)
		::tardis::_Go::Go_main_init _sf = hx::TCast< ::tardis::_Go::Go_main_init >::cast(::tardis::_Go::Go_main_init_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(3260)
		while((_sf->_incomplete)){
			HX_STACK_LINE(3260)
			::tardis::Scheduler_obj::runAll();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_main_init_obj,callFromHaxe,(void))

Void Go_main_init_obj::callFromRT( int _gr){
{
		HX_STACK_PUSH("Go_main_init::callFromRT","tardis/Go.hx",3262);
		HX_STACK_ARG(_gr,"_gr");
		HX_STACK_LINE(3263)
		::tardis::_Go::Go_main_init _sf = hx::TCast< ::tardis::_Go::Go_main_init >::cast(::tardis::_Go::Go_main_init_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(3264)
		while((_sf->_incomplete)){
			HX_STACK_LINE(3264)
			if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
				HX_STACK_LINE(3264)
				hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
			}
			else{
				HX_STACK_LINE(3264)
				::tardis::Scheduler_obj::currentGR = _gr;
				HX_STACK_LINE(3264)
				::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_main_init_obj,callFromRT,(void))

::tardis::_Go::Go_main_init Go_main_init_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_main_init::call","tardis/Go.hx",3267);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(3267)
	return ::tardis::_Go::Go_main_init_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_main_init_obj,call,return )


Go_main_init_obj::Go_main_init_obj()
{
}

void Go_main_init_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_main_init);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t1,"_t1");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_main_init_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t1,"_t1");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_main_init_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"_t1") ) { return _t1; }
		if (HX_FIELD_EQ(inName,"_t0") ) { return _t0; }
		if (HX_FIELD_EQ(inName,"res") ) { return res_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
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

Dynamic Go_main_init_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t1") ) { _t1=inValue.Cast< ::tardis::Channel >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_main_init_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
	outFields->push(HX_CSTRING("_t1"));
	outFields->push(HX_CSTRING("_t0"));
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
	HX_CSTRING("_t1"),
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_main_init_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_main_init_obj::__mClass,"__mClass");
};

Class Go_main_init_obj::__mClass;

void Go_main_init_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis._Go.Go_main_init"), hx::TCanCast< Go_main_init_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_main_init_obj::__boot()
{
}

} // end namespace tardis
} // end namespace _Go
