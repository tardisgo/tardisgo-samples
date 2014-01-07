#include <hxcpp.h>

#ifndef INCLUDED_motion_actuators_PropertyDetails
#include <motion/actuators/PropertyDetails.h>
#endif
namespace motion{
namespace actuators{

Void PropertyDetails_obj::__construct(Dynamic target,::String propertyName,Float start,Float change,hx::Null< bool >  __o_isField)
{
HX_STACK_PUSH("PropertyDetails::new","motion/actuators/PropertyDetails.hx",19);
bool isField = __o_isField.Default(true);
{
	HX_STACK_LINE(21)
	this->target = target;
	HX_STACK_LINE(22)
	this->propertyName = propertyName;
	HX_STACK_LINE(23)
	this->start = start;
	HX_STACK_LINE(24)
	this->change = change;
	HX_STACK_LINE(25)
	this->isField = isField;
}
;
	return null();
}

PropertyDetails_obj::~PropertyDetails_obj() { }

Dynamic PropertyDetails_obj::__CreateEmpty() { return  new PropertyDetails_obj; }
hx::ObjectPtr< PropertyDetails_obj > PropertyDetails_obj::__new(Dynamic target,::String propertyName,Float start,Float change,hx::Null< bool >  __o_isField)
{  hx::ObjectPtr< PropertyDetails_obj > result = new PropertyDetails_obj();
	result->__construct(target,propertyName,start,change,__o_isField);
	return result;}

Dynamic PropertyDetails_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PropertyDetails_obj > result = new PropertyDetails_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}


PropertyDetails_obj::PropertyDetails_obj()
{
}

void PropertyDetails_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PropertyDetails);
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(start,"start");
	HX_MARK_MEMBER_NAME(propertyName,"propertyName");
	HX_MARK_MEMBER_NAME(isField,"isField");
	HX_MARK_MEMBER_NAME(change,"change");
	HX_MARK_END_CLASS();
}

void PropertyDetails_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(start,"start");
	HX_VISIT_MEMBER_NAME(propertyName,"propertyName");
	HX_VISIT_MEMBER_NAME(isField,"isField");
	HX_VISIT_MEMBER_NAME(change,"change");
}

Dynamic PropertyDetails_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		if (HX_FIELD_EQ(inName,"change") ) { return change; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isField") ) { return isField; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"propertyName") ) { return propertyName; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PropertyDetails_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { start=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"change") ) { change=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isField") ) { isField=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"propertyName") ) { propertyName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PropertyDetails_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("start"));
	outFields->push(HX_CSTRING("propertyName"));
	outFields->push(HX_CSTRING("isField"));
	outFields->push(HX_CSTRING("change"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("target"),
	HX_CSTRING("start"),
	HX_CSTRING("propertyName"),
	HX_CSTRING("isField"),
	HX_CSTRING("change"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PropertyDetails_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PropertyDetails_obj::__mClass,"__mClass");
};

Class PropertyDetails_obj::__mClass;

void PropertyDetails_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.actuators.PropertyDetails"), hx::TCanCast< PropertyDetails_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PropertyDetails_obj::__boot()
{
}

} // end namespace motion
} // end namespace actuators
