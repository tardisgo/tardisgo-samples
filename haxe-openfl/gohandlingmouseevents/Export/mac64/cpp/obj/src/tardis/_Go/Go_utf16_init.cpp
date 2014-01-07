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
#ifndef INCLUDED_tardis__Go_Go_utf16_init
#include <tardis/_Go/Go_utf16_init.h>
#endif
namespace tardis{
namespace _Go{

Void Go_utf16_init_obj::__construct(int gr,Dynamic _bds)
{
HX_STACK_PUSH("Go_utf16_init::new","tardis/Go.hx",5251);
{
	HX_STACK_LINE(5259)
	this->_Next = (int)0;
	HX_STACK_LINE(5258)
	this->_t0 = false;
	HX_STACK_LINE(5253)
	super::__construct(gr,(int)986,HX_CSTRING("Go_utf16_init"));
	HX_STACK_LINE(5254)
	this->_bds = _bds;
	HX_STACK_LINE(5255)
	::tardis::Scheduler_obj::push(gr,hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

Go_utf16_init_obj::~Go_utf16_init_obj() { }

Dynamic Go_utf16_init_obj::__CreateEmpty() { return  new Go_utf16_init_obj; }
hx::ObjectPtr< Go_utf16_init_obj > Go_utf16_init_obj::__new(int gr,Dynamic _bds)
{  hx::ObjectPtr< Go_utf16_init_obj > result = new Go_utf16_init_obj();
	result->__construct(gr,_bds);
	return result;}

Dynamic Go_utf16_init_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Go_utf16_init_obj > result = new Go_utf16_init_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Go_utf16_init_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tardis::StackFrame_obj)) return operator ::tardis::StackFrame_obj *();
	return super::__ToInterface(inType);
}

Void Go_utf16_init_obj::SubFn1( ){
{
		HX_STACK_PUSH("Go_utf16_init::SubFn1","tardis/Go.hx",5295);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5296)
		::tardis::Go_obj::utf16_init_36_guard->store(true);
		HX_STACK_LINE(5297)
		this->_Next = (int)2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_init_obj,SubFn1,(void))

Void Go_utf16_init_obj::SubFn0( ){
{
		HX_STACK_PUSH("Go_utf16_init::SubFn0","tardis/Go.hx",5290);
		HX_STACK_THIS(this);
		HX_STACK_LINE(5291)
		bool _t0;		HX_STACK_VAR(_t0,"_t0");
		HX_STACK_LINE(5292)
		_t0 = ::tardis::Go_obj::utf16_init_36_guard->ref();
		HX_STACK_LINE(5293)
		this->_Next = (  ((_t0)) ? int((int)2) : int((int)1) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_init_obj,SubFn0,(void))

::tardis::StackFrame Go_utf16_init_obj::run( ){
	HX_STACK_PUSH("Go_utf16_init::run","tardis/Go.hx",5272);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5272)
	while((true)){
		HX_STACK_LINE(5274)
		::tardis::_Go::Go_utf16_init _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(5274)
		switch( (int)(_g->_Next)){
			case (int)0: {
				HX_STACK_LINE(5276)
				{
					HX_STACK_LINE(5276)
					this->_latestPH = (int)986;
					HX_STACK_LINE(5276)
					this->_latestBlock = (int)0;
				}
				HX_STACK_LINE(5277)
				{
					HX_STACK_LINE(5277)
					bool _t0;		HX_STACK_VAR(_t0,"_t0");
					HX_STACK_LINE(5277)
					_t0 = ::tardis::Go_obj::utf16_init_36_guard->ref();
					HX_STACK_LINE(5277)
					this->_Next = (  ((_t0)) ? int((int)2) : int((int)1) );
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(5280)
				{
					HX_STACK_LINE(5280)
					this->_latestPH = (int)986;
					HX_STACK_LINE(5280)
					this->_latestBlock = (int)1;
				}
				HX_STACK_LINE(5281)
				{
					HX_STACK_LINE(5281)
					::tardis::Go_obj::utf16_init_36_guard->store(true);
					HX_STACK_LINE(5281)
					this->_Next = (int)2;
				}
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(5284)
				{
					HX_STACK_LINE(5284)
					this->_latestPH = (int)986;
					HX_STACK_LINE(5284)
					this->_latestBlock = (int)2;
				}
				HX_STACK_LINE(5285)
				this->_incomplete = false;
				HX_STACK_LINE(5286)
				::tardis::Scheduler_obj::pop(this->_goroutine);
				HX_STACK_LINE(5287)
				return hx::ObjectPtr<OBJ_>(this);
			}
			;break;
			default: {
				HX_STACK_LINE(5289)
				::tardis::Scheduler_obj::bbi();
			}
		}
	}
	HX_STACK_LINE(5272)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_init_obj,run,return )

Dynamic Go_utf16_init_obj::res( ){
	HX_STACK_PUSH("Go_utf16_init::res","tardis/Go.hx",5257);
	HX_STACK_THIS(this);
	HX_STACK_LINE(5257)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_init_obj,res,return )

Void Go_utf16_init_obj::callFromHaxe( ){
{
		HX_STACK_PUSH("Go_utf16_init::callFromHaxe","tardis/Go.hx",5260);
		HX_STACK_LINE(5261)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(5261)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(5262)
		::tardis::_Go::Go_utf16_init _sf = hx::TCast< ::tardis::_Go::Go_utf16_init >::cast(::tardis::_Go::Go_utf16_init_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(5263)
		while((_sf->_incomplete)){
			HX_STACK_LINE(5263)
			::tardis::Scheduler_obj::runAll();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Go_utf16_init_obj,callFromHaxe,(void))

Void Go_utf16_init_obj::callFromRT( int _gr){
{
		HX_STACK_PUSH("Go_utf16_init::callFromRT","tardis/Go.hx",5265);
		HX_STACK_ARG(_gr,"_gr");
		HX_STACK_LINE(5266)
		::tardis::_Go::Go_utf16_init _sf = hx::TCast< ::tardis::_Go::Go_utf16_init >::cast(::tardis::_Go::Go_utf16_init_obj::__new(_gr,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(5267)
		while((_sf->_incomplete)){
			HX_STACK_LINE(5267)
			if (((::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first() == null()))){
				HX_STACK_LINE(5267)
				hx::Throw ((((((HX_CSTRING("Panic:") + ::Std_obj::string(::tardis::Scheduler_obj::grPanicMsg)) + HX_CSTRING("\nScheduler: null stack entry for goroutine ")) + _gr) + HX_CSTRING("\n")) + ::tardis::Scheduler_obj::stackDump()));
			}
			else{
				HX_STACK_LINE(5267)
				::tardis::Scheduler_obj::currentGR = _gr;
				HX_STACK_LINE(5267)
				::tardis::Scheduler_obj::grStacks->__get(_gr).StaticCast< ::List >()->first()->__Field(HX_CSTRING("run"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Go_utf16_init_obj,callFromRT,(void))

::tardis::_Go::Go_utf16_init Go_utf16_init_obj::call( int gr,Dynamic _bds){
	HX_STACK_PUSH("Go_utf16_init::call","tardis/Go.hx",5270);
	HX_STACK_ARG(gr,"gr");
	HX_STACK_ARG(_bds,"_bds");
	HX_STACK_LINE(5270)
	return ::tardis::_Go::Go_utf16_init_obj::__new(gr,_bds);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Go_utf16_init_obj,call,return )


Go_utf16_init_obj::Go_utf16_init_obj()
{
}

void Go_utf16_init_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Go_utf16_init);
	HX_MARK_MEMBER_NAME(_Next,"_Next");
	HX_MARK_MEMBER_NAME(_t0,"_t0");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Go_utf16_init_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_Next,"_Next");
	HX_VISIT_MEMBER_NAME(_t0,"_t0");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Go_utf16_init_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
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

Dynamic Go_utf16_init_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_t0") ) { _t0=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_Next") ) { _Next=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Go_utf16_init_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_Next"));
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
	HX_CSTRING("_t0"),
	HX_CSTRING("res"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Go_utf16_init_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Go_utf16_init_obj::__mClass,"__mClass");
};

Class Go_utf16_init_obj::__mClass;

void Go_utf16_init_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis._Go.Go_utf16_init"), hx::TCanCast< Go_utf16_init_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Go_utf16_init_obj::__boot()
{
}

} // end namespace tardis
} // end namespace _Go
