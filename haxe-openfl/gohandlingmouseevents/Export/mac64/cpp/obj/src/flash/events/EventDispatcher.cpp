#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_flash_events_ErrorEvent
#include <flash/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_EventPhase
#include <flash/events/EventPhase.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IOErrorEvent
#include <flash/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_flash_events_Listener
#include <flash/events/Listener.h>
#endif
#ifndef INCLUDED_flash_events_TextEvent
#include <flash/events/TextEvent.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_openfl_utils_WeakRef
#include <openfl/utils/WeakRef.h>
#endif
namespace flash{
namespace events{

Void EventDispatcher_obj::__construct(::flash::events::IEventDispatcher target)
{
HX_STACK_PUSH("EventDispatcher::new","flash/events/EventDispatcher.hx",16);
{
	HX_STACK_LINE(18)
	this->__target = (  (((target == null()))) ? ::flash::events::IEventDispatcher(hx::ObjectPtr<OBJ_>(this)) : ::flash::events::IEventDispatcher(target) );
	HX_STACK_LINE(19)
	this->__eventMap = null();
}
;
	return null();
}

EventDispatcher_obj::~EventDispatcher_obj() { }

Dynamic EventDispatcher_obj::__CreateEmpty() { return  new EventDispatcher_obj; }
hx::ObjectPtr< EventDispatcher_obj > EventDispatcher_obj::__new(::flash::events::IEventDispatcher target)
{  hx::ObjectPtr< EventDispatcher_obj > result = new EventDispatcher_obj();
	result->__construct(target);
	return result;}

Dynamic EventDispatcher_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventDispatcher_obj > result = new EventDispatcher_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *EventDispatcher_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::flash::events::IEventDispatcher_obj)) return operator ::flash::events::IEventDispatcher_obj *();
	return super::__ToInterface(inType);
}

Void EventDispatcher_obj::__dispatchIOErrorEvent( ){
{
		HX_STACK_PUSH("EventDispatcher::__dispatchIOErrorEvent","flash/events/EventDispatcher.hx",205);
		HX_STACK_THIS(this);
		HX_STACK_LINE(205)
		this->dispatchEvent(::flash::events::IOErrorEvent_obj::__new(::flash::events::IOErrorEvent_obj::IO_ERROR,null(),null(),null(),null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,__dispatchIOErrorEvent,(void))

Void EventDispatcher_obj::__dispatchCompleteEvent( ){
{
		HX_STACK_PUSH("EventDispatcher::__dispatchCompleteEvent","flash/events/EventDispatcher.hx",198);
		HX_STACK_THIS(this);
		HX_STACK_LINE(198)
		this->dispatchEvent(::flash::events::Event_obj::__new(::flash::events::Event_obj::COMPLETE,null(),null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,__dispatchCompleteEvent,(void))

bool EventDispatcher_obj::willTrigger( ::String type){
	HX_STACK_PUSH("EventDispatcher::willTrigger","flash/events/EventDispatcher.hx",185);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_LINE(187)
	if (((this->__eventMap == null()))){
		HX_STACK_LINE(187)
		return false;
	}
	HX_STACK_LINE(193)
	return this->__eventMap->exists(type);
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,willTrigger,return )

::String EventDispatcher_obj::toString( ){
	HX_STACK_PUSH("EventDispatcher::toString","flash/events/EventDispatcher.hx",178);
	HX_STACK_THIS(this);
	HX_STACK_LINE(178)
	return ((HX_CSTRING("[object ") + ::Type_obj::getClassName(::Type_obj::getClass(hx::ObjectPtr<OBJ_>(this)))) + HX_CSTRING("]"));
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,toString,return )

Void EventDispatcher_obj::removeEventListener( ::String type,Dynamic listener,hx::Null< bool >  __o_capture){
bool capture = __o_capture.Default(false);
	HX_STACK_PUSH("EventDispatcher::removeEventListener","flash/events/EventDispatcher.hx",148);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_ARG(listener,"listener");
	HX_STACK_ARG(capture,"capture");
{
		HX_STACK_LINE(150)
		if (((bool((this->__eventMap == null())) || bool(!(this->__eventMap->exists(type)))))){
			HX_STACK_LINE(150)
			return null();
		}
		HX_STACK_LINE(156)
		Array< ::Dynamic > list = this->__eventMap->get(type);		HX_STACK_VAR(list,"list");
		HX_STACK_LINE(157)
		::flash::events::Listener item;		HX_STACK_VAR(item,"item");
		HX_STACK_LINE(159)
		{
			HX_STACK_LINE(159)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(159)
			while(((_g1 < _g))){
				HX_STACK_LINE(159)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(161)
				if (((list->__get(i).StaticCast< ::flash::events::Listener >() != null()))){
					HX_STACK_LINE(163)
					item = list->__get(i).StaticCast< ::flash::events::Listener >();
					HX_STACK_LINE(164)
					if (((bool((item != null())) && bool(item->is(listener,capture))))){
						HX_STACK_LINE(166)
						list[i] = null();
						HX_STACK_LINE(167)
						return null();
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventDispatcher_obj,removeEventListener,(void))

bool EventDispatcher_obj::hasEventListener( ::String type){
	HX_STACK_PUSH("EventDispatcher::hasEventListener","flash/events/EventDispatcher.hx",123);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_LINE(125)
	if (((this->__eventMap == null()))){
		HX_STACK_LINE(125)
		return false;
	}
	HX_STACK_LINE(131)
	Array< ::Dynamic > list = this->__eventMap->get(type);		HX_STACK_VAR(list,"list");
	HX_STACK_LINE(133)
	if (((list != null()))){
		HX_STACK_LINE(135)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(135)
		while(((_g < list->length))){
			HX_STACK_LINE(135)
			::flash::events::Listener item = list->__get(_g).StaticCast< ::flash::events::Listener >();		HX_STACK_VAR(item,"item");
			HX_STACK_LINE(135)
			++(_g);
			HX_STACK_LINE(137)
			if (((item != null()))){
				HX_STACK_LINE(137)
				return true;
			}
		}
	}
	HX_STACK_LINE(143)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,hasEventListener,return )

bool EventDispatcher_obj::dispatchEvent( ::flash::events::Event event){
	HX_STACK_PUSH("EventDispatcher::dispatchEvent","flash/events/EventDispatcher.hx",54);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(56)
	if (((this->__eventMap == null()))){
		HX_STACK_LINE(56)
		return false;
	}
	HX_STACK_LINE(62)
	if (((event->get_target() == null()))){
		HX_STACK_LINE(62)
		event->set_target(this->__target);
	}
	HX_STACK_LINE(68)
	if (((event->get_currentTarget() == null()))){
		HX_STACK_LINE(68)
		event->set_currentTarget(this->__target);
	}
	HX_STACK_LINE(74)
	Array< ::Dynamic > list = this->__eventMap->get(event->get_type());		HX_STACK_VAR(list,"list");
	HX_STACK_LINE(75)
	bool capture = (event->get_eventPhase() == ::flash::events::EventPhase_obj::CAPTURING_PHASE);		HX_STACK_VAR(capture,"capture");
	HX_STACK_LINE(77)
	if (((list != null()))){
		HX_STACK_LINE(79)
		int index = (int)0;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(80)
		int length = list->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(82)
		::flash::events::Listener listItem;		HX_STACK_VAR(listItem,"listItem");
		::flash::events::Listener listener;		HX_STACK_VAR(listener,"listener");
		HX_STACK_LINE(84)
		while(((index < length))){
			HX_STACK_LINE(86)
			listItem = list->__get(index).StaticCast< ::flash::events::Listener >();
			HX_STACK_LINE(87)
			listener = (  (((bool((listItem != null())) && bool((listItem->listener->get() != null()))))) ? ::flash::events::Listener(listItem) : ::flash::events::Listener(null()) );
			HX_STACK_LINE(89)
			if (((listener == null()))){
				HX_STACK_LINE(91)
				list->splice(index,(int)1);
				HX_STACK_LINE(92)
				(length)--;
			}
			else{
				HX_STACK_LINE(96)
				if (((listener->useCapture == capture))){
					HX_STACK_LINE(98)
					listener->dispatchEvent(event);
					HX_STACK_LINE(100)
					if ((event->__getIsCancelledNow())){
						HX_STACK_LINE(100)
						return true;
					}
				}
				HX_STACK_LINE(108)
				(index)++;
			}
		}
		HX_STACK_LINE(114)
		return true;
	}
	HX_STACK_LINE(118)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,dispatchEvent,return )

Void EventDispatcher_obj::addEventListener( ::String type,Dynamic listener,hx::Null< bool >  __o_useCapture,hx::Null< int >  __o_priority,hx::Null< bool >  __o_useWeakReference){
bool useCapture = __o_useCapture.Default(false);
int priority = __o_priority.Default(0);
bool useWeakReference = __o_useWeakReference.Default(false);
	HX_STACK_PUSH("EventDispatcher::addEventListener","flash/events/EventDispatcher.hx",24);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_ARG(listener,"listener");
	HX_STACK_ARG(useCapture,"useCapture");
	HX_STACK_ARG(priority,"priority");
	HX_STACK_ARG(useWeakReference,"useWeakReference");
{
		HX_STACK_LINE(26)
		if ((useWeakReference)){
			HX_STACK_LINE(28)
			::haxe::Log_obj::trace(HX_CSTRING("WARNING: Weak listener not supported for native (using hard reference)"),hx::SourceInfo(HX_CSTRING("EventDispatcher.hx"),28,HX_CSTRING("flash.events.EventDispatcher"),HX_CSTRING("addEventListener")));
			HX_STACK_LINE(29)
			useWeakReference = false;
		}
		HX_STACK_LINE(33)
		if (((this->__eventMap == null()))){
			HX_STACK_LINE(33)
			this->__eventMap = ::haxe::ds::StringMap_obj::__new();
		}
		HX_STACK_LINE(39)
		Array< ::Dynamic > list = this->__eventMap->get(type);		HX_STACK_VAR(list,"list");
		HX_STACK_LINE(41)
		if (((list == null()))){
			HX_STACK_LINE(43)
			list = Array_obj< ::Dynamic >::__new();
			HX_STACK_LINE(44)
			this->__eventMap->set(type,list);
		}
		HX_STACK_LINE(48)
		list->push(::flash::events::Listener_obj::__new(::openfl::utils::WeakRef_obj::__new(listener,useWeakReference),useCapture,priority));
		HX_STACK_LINE(49)
		list->sort(::flash::events::EventDispatcher_obj::__sortEvents_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(EventDispatcher_obj,addEventListener,(void))

int EventDispatcher_obj::__sortEvents( ::flash::events::Listener a,::flash::events::Listener b){
	HX_STACK_PUSH("EventDispatcher::__sortEvents","flash/events/EventDispatcher.hx",212);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(214)
	if (((bool((a == null())) || bool((b == null()))))){
		HX_STACK_LINE(214)
		return (int)0;
	}
	HX_STACK_LINE(220)
	::flash::events::Listener al = a;		HX_STACK_VAR(al,"al");
	HX_STACK_LINE(221)
	::flash::events::Listener bl = b;		HX_STACK_VAR(bl,"bl");
	HX_STACK_LINE(223)
	if (((bool((al == null())) || bool((bl == null()))))){
		HX_STACK_LINE(223)
		return (int)0;
	}
	HX_STACK_LINE(229)
	if (((al->priority == bl->priority))){
		HX_STACK_LINE(229)
		return (  (((al->id == bl->id))) ? int((int)0) : int((  (((al->id > bl->id))) ? int((int)1) : int((int)-1) )) );
	}
	else{
		HX_STACK_LINE(233)
		return (  (((al->priority < bl->priority))) ? int((int)1) : int((int)-1) );
	}
	HX_STACK_LINE(229)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(EventDispatcher_obj,__sortEvents,return )


EventDispatcher_obj::EventDispatcher_obj()
{
}

void EventDispatcher_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventDispatcher);
	HX_MARK_MEMBER_NAME(__target,"__target");
	HX_MARK_MEMBER_NAME(__eventMap,"__eventMap");
	HX_MARK_END_CLASS();
}

void EventDispatcher_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__target,"__target");
	HX_VISIT_MEMBER_NAME(__eventMap,"__eventMap");
}

Dynamic EventDispatcher_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"__target") ) { return __target; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__eventMap") ) { return __eventMap; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"willTrigger") ) { return willTrigger_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__sortEvents") ) { return __sortEvents_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"hasEventListener") ) { return hasEventListener_dyn(); }
		if (HX_FIELD_EQ(inName,"addEventListener") ) { return addEventListener_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"removeEventListener") ) { return removeEventListener_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"__dispatchIOErrorEvent") ) { return __dispatchIOErrorEvent_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"__dispatchCompleteEvent") ) { return __dispatchCompleteEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EventDispatcher_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"__target") ) { __target=inValue.Cast< ::flash::events::IEventDispatcher >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__eventMap") ) { __eventMap=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EventDispatcher_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__target"));
	outFields->push(HX_CSTRING("__eventMap"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("__sortEvents"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("__dispatchIOErrorEvent"),
	HX_CSTRING("__dispatchCompleteEvent"),
	HX_CSTRING("willTrigger"),
	HX_CSTRING("toString"),
	HX_CSTRING("removeEventListener"),
	HX_CSTRING("hasEventListener"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("addEventListener"),
	HX_CSTRING("__target"),
	HX_CSTRING("__eventMap"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventDispatcher_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventDispatcher_obj::__mClass,"__mClass");
};

Class EventDispatcher_obj::__mClass;

void EventDispatcher_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.events.EventDispatcher"), hx::TCanCast< EventDispatcher_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EventDispatcher_obj::__boot()
{
}

} // end namespace flash
} // end namespace events
