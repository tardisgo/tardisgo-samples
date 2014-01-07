#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_Listener
#include <flash/events/Listener.h>
#endif
#ifndef INCLUDED_openfl_utils_WeakRef
#include <openfl/utils/WeakRef.h>
#endif
namespace flash{
namespace events{

Void Listener_obj::__construct(::openfl::utils::WeakRef listener,bool useCapture,int priority)
{
HX_STACK_PUSH("Listener::new","flash/events/EventDispatcher.hx",256);
{
	HX_STACK_LINE(258)
	this->listener = listener;
	HX_STACK_LINE(259)
	this->useCapture = useCapture;
	HX_STACK_LINE(260)
	this->priority = priority;
	HX_STACK_LINE(261)
	this->id = (::flash::events::Listener_obj::__id)++;
}
;
	return null();
}

Listener_obj::~Listener_obj() { }

Dynamic Listener_obj::__CreateEmpty() { return  new Listener_obj; }
hx::ObjectPtr< Listener_obj > Listener_obj::__new(::openfl::utils::WeakRef listener,bool useCapture,int priority)
{  hx::ObjectPtr< Listener_obj > result = new Listener_obj();
	result->__construct(listener,useCapture,priority);
	return result;}

Dynamic Listener_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Listener_obj > result = new Listener_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

bool Listener_obj::is( Dynamic listener,bool useCapture){
	HX_STACK_PUSH("Listener::is","flash/events/EventDispatcher.hx",273);
	HX_STACK_THIS(this);
	HX_STACK_ARG(listener,"listener");
	HX_STACK_ARG(useCapture,"useCapture");
	HX_STACK_LINE(273)
	return (bool(::Reflect_obj::compareMethods(this->listener->get(),listener)) && bool((this->useCapture == useCapture)));
}


HX_DEFINE_DYNAMIC_FUNC2(Listener_obj,is,return )

Void Listener_obj::dispatchEvent( ::flash::events::Event event){
{
		HX_STACK_PUSH("Listener::dispatchEvent","flash/events/EventDispatcher.hx",266);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(266)
		this->listener->get()(event).Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Listener_obj,dispatchEvent,(void))

int Listener_obj::__id;


Listener_obj::Listener_obj()
{
}

void Listener_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Listener);
	HX_MARK_MEMBER_NAME(useCapture,"useCapture");
	HX_MARK_MEMBER_NAME(priority,"priority");
	HX_MARK_MEMBER_NAME(listener,"listener");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_END_CLASS();
}

void Listener_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(useCapture,"useCapture");
	HX_VISIT_MEMBER_NAME(priority,"priority");
	HX_VISIT_MEMBER_NAME(listener,"listener");
	HX_VISIT_MEMBER_NAME(id,"id");
}

Dynamic Listener_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"is") ) { return is_dyn(); }
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"__id") ) { return __id; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"priority") ) { return priority; }
		if (HX_FIELD_EQ(inName,"listener") ) { return listener; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"useCapture") ) { return useCapture; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Listener_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"__id") ) { __id=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"priority") ) { priority=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"listener") ) { listener=inValue.Cast< ::openfl::utils::WeakRef >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"useCapture") ) { useCapture=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Listener_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("useCapture"));
	outFields->push(HX_CSTRING("priority"));
	outFields->push(HX_CSTRING("listener"));
	outFields->push(HX_CSTRING("id"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("__id"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("is"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("useCapture"),
	HX_CSTRING("priority"),
	HX_CSTRING("listener"),
	HX_CSTRING("id"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Listener_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Listener_obj::__id,"__id");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Listener_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Listener_obj::__id,"__id");
};

Class Listener_obj::__mClass;

void Listener_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.events.Listener"), hx::TCanCast< Listener_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Listener_obj::__boot()
{
	__id= (int)1;
}

} // end namespace flash
} // end namespace events
