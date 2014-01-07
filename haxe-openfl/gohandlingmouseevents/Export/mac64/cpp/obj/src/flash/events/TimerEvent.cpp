#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_TimerEvent
#include <flash/events/TimerEvent.h>
#endif
namespace flash{
namespace events{

Void TimerEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable)
{
HX_STACK_PUSH("TimerEvent::new","flash/events/TimerEvent.hx",11);
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
{
	HX_STACK_LINE(11)
	super::__construct(type,bubbles,cancelable);
}
;
	return null();
}

TimerEvent_obj::~TimerEvent_obj() { }

Dynamic TimerEvent_obj::__CreateEmpty() { return  new TimerEvent_obj; }
hx::ObjectPtr< TimerEvent_obj > TimerEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable)
{  hx::ObjectPtr< TimerEvent_obj > result = new TimerEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable);
	return result;}

Dynamic TimerEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TimerEvent_obj > result = new TimerEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void TimerEvent_obj::updateAfterEvent( ){
{
		HX_STACK_PUSH("TimerEvent::updateAfterEvent","flash/events/TimerEvent.hx",32);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TimerEvent_obj,updateAfterEvent,(void))

::String TimerEvent_obj::toString( ){
	HX_STACK_PUSH("TimerEvent::toString","flash/events/TimerEvent.hx",25);
	HX_STACK_THIS(this);
	HX_STACK_LINE(25)
	return ((((((HX_CSTRING("[TimerEvent type=") + this->get_type()) + HX_CSTRING(" bubbles=")) + ::Std_obj::string(this->get_bubbles())) + HX_CSTRING(" cancelable=")) + ::Std_obj::string(this->get_cancelable())) + HX_CSTRING("]"));
}


::flash::events::Event TimerEvent_obj::clone( ){
	HX_STACK_PUSH("TimerEvent::clone","flash/events/TimerEvent.hx",18);
	HX_STACK_THIS(this);
	HX_STACK_LINE(18)
	return ::flash::events::TimerEvent_obj::__new(this->get_type(),this->get_bubbles(),this->get_cancelable());
}


::String TimerEvent_obj::TIMER;

::String TimerEvent_obj::TIMER_COMPLETE;


TimerEvent_obj::TimerEvent_obj()
{
}

void TimerEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TimerEvent);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TimerEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TimerEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"TIMER") ) { return TIMER; }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TIMER_COMPLETE") ) { return TIMER_COMPLETE; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"updateAfterEvent") ) { return updateAfterEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TimerEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"TIMER") ) { TIMER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TIMER_COMPLETE") ) { TIMER_COMPLETE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TimerEvent_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TIMER"),
	HX_CSTRING("TIMER_COMPLETE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("updateAfterEvent"),
	HX_CSTRING("toString"),
	HX_CSTRING("clone"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TimerEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TimerEvent_obj::TIMER,"TIMER");
	HX_MARK_MEMBER_NAME(TimerEvent_obj::TIMER_COMPLETE,"TIMER_COMPLETE");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TimerEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TimerEvent_obj::TIMER,"TIMER");
	HX_VISIT_MEMBER_NAME(TimerEvent_obj::TIMER_COMPLETE,"TIMER_COMPLETE");
};

Class TimerEvent_obj::__mClass;

void TimerEvent_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.events.TimerEvent"), hx::TCanCast< TimerEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TimerEvent_obj::__boot()
{
	TIMER= HX_CSTRING("timer");
	TIMER_COMPLETE= HX_CSTRING("timerComplete");
}

} // end namespace flash
} // end namespace events
