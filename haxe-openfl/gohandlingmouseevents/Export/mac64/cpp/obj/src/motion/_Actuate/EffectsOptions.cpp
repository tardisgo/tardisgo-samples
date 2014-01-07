#include <hxcpp.h>

#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_motion_Actuate
#include <motion/Actuate.h>
#endif
#ifndef INCLUDED_motion__Actuate_EffectsOptions
#include <motion/_Actuate/EffectsOptions.h>
#endif
#ifndef INCLUDED_motion_actuators_FilterActuator
#include <motion/actuators/FilterActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_GenericActuator
#include <motion/actuators/GenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_IGenericActuator
#include <motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_SimpleActuator
#include <motion/actuators/SimpleActuator.h>
#endif
namespace motion{
namespace _Actuate{

Void EffectsOptions_obj::__construct(::flash::display::DisplayObject target,Float duration,bool overwrite)
{
HX_STACK_PUSH("EffectsOptions::new","motion/Actuate.hx",429);
{
	HX_STACK_LINE(431)
	this->target = target;
	HX_STACK_LINE(432)
	this->duration = duration;
	HX_STACK_LINE(433)
	this->overwrite = overwrite;
}
;
	return null();
}

EffectsOptions_obj::~EffectsOptions_obj() { }

Dynamic EffectsOptions_obj::__CreateEmpty() { return  new EffectsOptions_obj; }
hx::ObjectPtr< EffectsOptions_obj > EffectsOptions_obj::__new(::flash::display::DisplayObject target,Float duration,bool overwrite)
{  hx::ObjectPtr< EffectsOptions_obj > result = new EffectsOptions_obj();
	result->__construct(target,duration,overwrite);
	return result;}

Dynamic EffectsOptions_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EffectsOptions_obj > result = new EffectsOptions_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::motion::actuators::IGenericActuator EffectsOptions_obj::filter( Dynamic reference,Dynamic properties){
	HX_STACK_PUSH("EffectsOptions::filter","motion/Actuate.hx",444);
	HX_STACK_THIS(this);
	HX_STACK_ARG(reference,"reference");
	HX_STACK_ARG(properties,"properties");
	HX_STACK_LINE(446)
	properties->__FieldRef(HX_CSTRING("filter")) = reference;
	HX_STACK_LINE(448)
	return ::motion::Actuate_obj::tween(this->target,this->duration,properties,this->overwrite,hx::ClassOf< ::motion::actuators::FilterActuator >());
}


HX_DEFINE_DYNAMIC_FUNC2(EffectsOptions_obj,filter,return )


EffectsOptions_obj::EffectsOptions_obj()
{
}

void EffectsOptions_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EffectsOptions);
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(overwrite,"overwrite");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_END_CLASS();
}

void EffectsOptions_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(overwrite,"overwrite");
	HX_VISIT_MEMBER_NAME(duration,"duration");
}

Dynamic EffectsOptions_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"filter") ) { return filter_dyn(); }
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"overwrite") ) { return overwrite; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EffectsOptions_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::flash::display::DisplayObject >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"overwrite") ) { overwrite=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EffectsOptions_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("overwrite"));
	outFields->push(HX_CSTRING("duration"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("filter"),
	HX_CSTRING("target"),
	HX_CSTRING("overwrite"),
	HX_CSTRING("duration"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EffectsOptions_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EffectsOptions_obj::__mClass,"__mClass");
};

Class EffectsOptions_obj::__mClass;

void EffectsOptions_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion._Actuate.EffectsOptions"), hx::TCanCast< EffectsOptions_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EffectsOptions_obj::__boot()
{
}

} // end namespace motion
} // end namespace _Actuate
