#include <hxcpp.h>

#ifndef INCLUDED_flash_errors_Error
#include <flash/errors/Error.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_TimerEvent
#include <flash/events/TimerEvent.h>
#endif
#ifndef INCLUDED_flash_utils_Timer
#include <flash/utils/Timer.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flash{
namespace utils{

Void Timer_obj::__construct(Float delay,hx::Null< int >  __o_repeatCount)
{
HX_STACK_PUSH("Timer::new","flash/utils/Timer.hx",21);
int repeatCount = __o_repeatCount.Default(0);
{
	HX_STACK_LINE(23)
	if (((bool(::Math_obj::isNaN(delay)) || bool((delay < (int)0))))){
		HX_STACK_LINE(23)
		hx::Throw (::flash::errors::Error_obj::__new(HX_CSTRING("The delay specified is negative or not a finite number"),null()));
	}
	HX_STACK_LINE(29)
	super::__construct(null());
	HX_STACK_LINE(31)
	this->__delay = delay;
	HX_STACK_LINE(32)
	this->repeatCount = repeatCount;
	HX_STACK_LINE(33)
	this->currentCount = (int)0;
}
;
	return null();
}

Timer_obj::~Timer_obj() { }

Dynamic Timer_obj::__CreateEmpty() { return  new Timer_obj; }
hx::ObjectPtr< Timer_obj > Timer_obj::__new(Float delay,hx::Null< int >  __o_repeatCount)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(delay,__o_repeatCount);
	return result;}

Dynamic Timer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Timer_obj::timer_onTimer( ){
{
		HX_STACK_PUSH("Timer::timer_onTimer","flash/utils/Timer.hx",115);
		HX_STACK_THIS(this);
		HX_STACK_LINE(117)
		(this->currentCount)++;
		HX_STACK_LINE(119)
		if (((bool((this->repeatCount > (int)0)) && bool((this->currentCount >= this->repeatCount))))){
			HX_STACK_LINE(121)
			this->stop();
			HX_STACK_LINE(122)
			this->dispatchEvent(::flash::events::TimerEvent_obj::__new(::flash::events::TimerEvent_obj::TIMER,null(),null()));
			HX_STACK_LINE(123)
			this->dispatchEvent(::flash::events::TimerEvent_obj::__new(::flash::events::TimerEvent_obj::TIMER_COMPLETE,null(),null()));
		}
		else{
			HX_STACK_LINE(125)
			this->dispatchEvent(::flash::events::TimerEvent_obj::__new(::flash::events::TimerEvent_obj::TIMER,null(),null()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,timer_onTimer,(void))

Float Timer_obj::set_delay( Float value){
	HX_STACK_PUSH("Timer::set_delay","flash/utils/Timer.hx",92);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(94)
	this->__delay = value;
	HX_STACK_LINE(96)
	if ((this->running)){
		HX_STACK_LINE(98)
		this->stop();
		HX_STACK_LINE(99)
		this->start();
	}
	HX_STACK_LINE(103)
	return this->__delay;
}


HX_DEFINE_DYNAMIC_FUNC1(Timer_obj,set_delay,return )

Float Timer_obj::get_delay( ){
	HX_STACK_PUSH("Timer::get_delay","flash/utils/Timer.hx",85);
	HX_STACK_THIS(this);
	HX_STACK_LINE(85)
	return this->__delay;
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,get_delay,return )

Void Timer_obj::stop( ){
{
		HX_STACK_PUSH("Timer::stop","flash/utils/Timer.hx",64);
		HX_STACK_THIS(this);
		HX_STACK_LINE(66)
		this->running = false;
		HX_STACK_LINE(68)
		if (((this->__timer != null()))){
			HX_STACK_LINE(70)
			this->__timer->stop();
			HX_STACK_LINE(71)
			this->__timer = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stop,(void))

Void Timer_obj::start( ){
{
		HX_STACK_PUSH("Timer::start","flash/utils/Timer.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_LINE(51)
		if ((!(this->running))){
			HX_STACK_LINE(55)
			this->running = true;
			HX_STACK_LINE(56)
			this->__timer = ::haxe::Timer_obj::__new(this->__delay);
			HX_STACK_LINE(57)
			this->__timer->run = this->timer_onTimer_dyn();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,start,(void))

Void Timer_obj::reset( ){
{
		HX_STACK_PUSH("Timer::reset","flash/utils/Timer.hx",38);
		HX_STACK_THIS(this);
		HX_STACK_LINE(40)
		if ((this->running)){
			HX_STACK_LINE(40)
			this->stop();
		}
		HX_STACK_LINE(46)
		this->currentCount = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,reset,(void))


Timer_obj::Timer_obj()
{
}

void Timer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Timer);
	HX_MARK_MEMBER_NAME(__timer,"__timer");
	HX_MARK_MEMBER_NAME(__delay,"__delay");
	HX_MARK_MEMBER_NAME(running,"running");
	HX_MARK_MEMBER_NAME(repeatCount,"repeatCount");
	HX_MARK_MEMBER_NAME(currentCount,"currentCount");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Timer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__timer,"__timer");
	HX_VISIT_MEMBER_NAME(__delay,"__delay");
	HX_VISIT_MEMBER_NAME(running,"running");
	HX_VISIT_MEMBER_NAME(repeatCount,"repeatCount");
	HX_VISIT_MEMBER_NAME(currentCount,"currentCount");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Timer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"delay") ) { return get_delay(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"__timer") ) { return __timer; }
		if (HX_FIELD_EQ(inName,"__delay") ) { return __delay; }
		if (HX_FIELD_EQ(inName,"running") ) { return running; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_delay") ) { return set_delay_dyn(); }
		if (HX_FIELD_EQ(inName,"get_delay") ) { return get_delay_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"repeatCount") ) { return repeatCount; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentCount") ) { return currentCount; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"timer_onTimer") ) { return timer_onTimer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Timer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"delay") ) { return set_delay(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"__timer") ) { __timer=inValue.Cast< ::haxe::Timer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__delay") ) { __delay=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"running") ) { running=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"repeatCount") ) { repeatCount=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentCount") ) { currentCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Timer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__timer"));
	outFields->push(HX_CSTRING("__delay"));
	outFields->push(HX_CSTRING("running"));
	outFields->push(HX_CSTRING("repeatCount"));
	outFields->push(HX_CSTRING("delay"));
	outFields->push(HX_CSTRING("currentCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("timer_onTimer"),
	HX_CSTRING("set_delay"),
	HX_CSTRING("get_delay"),
	HX_CSTRING("stop"),
	HX_CSTRING("start"),
	HX_CSTRING("reset"),
	HX_CSTRING("__timer"),
	HX_CSTRING("__delay"),
	HX_CSTRING("running"),
	HX_CSTRING("repeatCount"),
	HX_CSTRING("currentCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Timer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Timer_obj::__mClass,"__mClass");
};

Class Timer_obj::__mClass;

void Timer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.utils.Timer"), hx::TCanCast< Timer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Timer_obj::__boot()
{
}

} // end namespace flash
} // end namespace utils
