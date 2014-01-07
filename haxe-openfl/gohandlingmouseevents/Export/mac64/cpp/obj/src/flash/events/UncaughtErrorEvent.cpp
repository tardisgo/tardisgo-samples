#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_events_ErrorEvent
#include <flash/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_TextEvent
#include <flash/events/TextEvent.h>
#endif
#ifndef INCLUDED_flash_events_UncaughtErrorEvent
#include <flash/events/UncaughtErrorEvent.h>
#endif
namespace flash{
namespace events{

Void UncaughtErrorEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,Dynamic error_in)
{
HX_STACK_PUSH("UncaughtErrorEvent::new","flash/events/UncaughtErrorEvent.hx",8);
bool bubbles = __o_bubbles.Default(true);
bool cancelable = __o_cancelable.Default(true);
{
	HX_STACK_LINE(10)
	super::__construct(type,bubbles,cancelable,null(),null());
	HX_STACK_LINE(11)
	this->error = error_in;
}
;
	return null();
}

UncaughtErrorEvent_obj::~UncaughtErrorEvent_obj() { }

Dynamic UncaughtErrorEvent_obj::__CreateEmpty() { return  new UncaughtErrorEvent_obj; }
hx::ObjectPtr< UncaughtErrorEvent_obj > UncaughtErrorEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,Dynamic error_in)
{  hx::ObjectPtr< UncaughtErrorEvent_obj > result = new UncaughtErrorEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,error_in);
	return result;}

Dynamic UncaughtErrorEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UncaughtErrorEvent_obj > result = new UncaughtErrorEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::String UncaughtErrorEvent_obj::toString( ){
	HX_STACK_PUSH("UncaughtErrorEvent::toString","flash/events/UncaughtErrorEvent.hx",23);
	HX_STACK_THIS(this);
	HX_STACK_LINE(23)
	return ((((((HX_CSTRING("[UncaughtErrorEvent type=") + this->get_type()) + HX_CSTRING(" bubbles=")) + ::Std_obj::string(this->get_bubbles())) + HX_CSTRING(" cancelable=")) + ::Std_obj::string(this->get_cancelable())) + HX_CSTRING("]"));
}


::flash::events::Event UncaughtErrorEvent_obj::clone( ){
	HX_STACK_PUSH("UncaughtErrorEvent::clone","flash/events/UncaughtErrorEvent.hx",16);
	HX_STACK_THIS(this);
	HX_STACK_LINE(16)
	return ::flash::events::UncaughtErrorEvent_obj::__new(this->get_type(),this->get_bubbles(),this->get_cancelable(),this->error);
}


::String UncaughtErrorEvent_obj::UNCAUGHT_ERROR;


UncaughtErrorEvent_obj::UncaughtErrorEvent_obj()
{
}

void UncaughtErrorEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UncaughtErrorEvent);
	HX_MARK_MEMBER_NAME(error,"error");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void UncaughtErrorEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(error,"error");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic UncaughtErrorEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"error") ) { return error; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"UNCAUGHT_ERROR") ) { return UNCAUGHT_ERROR; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic UncaughtErrorEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"error") ) { error=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"UNCAUGHT_ERROR") ) { UNCAUGHT_ERROR=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void UncaughtErrorEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("error"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("UNCAUGHT_ERROR"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("clone"),
	HX_CSTRING("error"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UncaughtErrorEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(UncaughtErrorEvent_obj::UNCAUGHT_ERROR,"UNCAUGHT_ERROR");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UncaughtErrorEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(UncaughtErrorEvent_obj::UNCAUGHT_ERROR,"UNCAUGHT_ERROR");
};

Class UncaughtErrorEvent_obj::__mClass;

void UncaughtErrorEvent_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.events.UncaughtErrorEvent"), hx::TCanCast< UncaughtErrorEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void UncaughtErrorEvent_obj::__boot()
{
	UNCAUGHT_ERROR= HX_CSTRING("uncaughtError");
}

} // end namespace flash
} // end namespace events
