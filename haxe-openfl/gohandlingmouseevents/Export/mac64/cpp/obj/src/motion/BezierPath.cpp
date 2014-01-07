#include <hxcpp.h>

#ifndef INCLUDED_motion_BezierPath
#include <motion/BezierPath.h>
#endif
namespace motion{

Void BezierPath_obj::__construct(Float end,Float control,Float strength)
{
HX_STACK_PUSH("BezierPath::new","motion/MotionPath.hx",208);
{
	HX_STACK_LINE(210)
	this->end = end;
	HX_STACK_LINE(211)
	this->control = control;
	HX_STACK_LINE(212)
	this->strength = strength;
}
;
	return null();
}

BezierPath_obj::~BezierPath_obj() { }

Dynamic BezierPath_obj::__CreateEmpty() { return  new BezierPath_obj; }
hx::ObjectPtr< BezierPath_obj > BezierPath_obj::__new(Float end,Float control,Float strength)
{  hx::ObjectPtr< BezierPath_obj > result = new BezierPath_obj();
	result->__construct(end,control,strength);
	return result;}

Dynamic BezierPath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BezierPath_obj > result = new BezierPath_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Float BezierPath_obj::calculate( Float start,Float k){
	HX_STACK_PUSH("BezierPath::calculate","motion/MotionPath.hx",217);
	HX_STACK_THIS(this);
	HX_STACK_ARG(start,"start");
	HX_STACK_ARG(k,"k");
	HX_STACK_LINE(217)
	return (((((((int)1 - k)) * (((int)1 - k))) * start) + ((((int)2 * (((int)1 - k))) * k) * this->control)) + ((k * k) * this->end));
}


HX_DEFINE_DYNAMIC_FUNC2(BezierPath_obj,calculate,return )


BezierPath_obj::BezierPath_obj()
{
}

void BezierPath_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BezierPath);
	HX_MARK_MEMBER_NAME(strength,"strength");
	HX_MARK_MEMBER_NAME(end,"end");
	HX_MARK_MEMBER_NAME(control,"control");
	HX_MARK_END_CLASS();
}

void BezierPath_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(strength,"strength");
	HX_VISIT_MEMBER_NAME(end,"end");
	HX_VISIT_MEMBER_NAME(control,"control");
}

Dynamic BezierPath_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { return end; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"control") ) { return control; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"strength") ) { return strength; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"calculate") ) { return calculate_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BezierPath_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { end=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"control") ) { control=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"strength") ) { strength=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BezierPath_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("strength"));
	outFields->push(HX_CSTRING("end"));
	outFields->push(HX_CSTRING("control"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("calculate"),
	HX_CSTRING("strength"),
	HX_CSTRING("end"),
	HX_CSTRING("control"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BezierPath_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BezierPath_obj::__mClass,"__mClass");
};

Class BezierPath_obj::__mClass;

void BezierPath_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.BezierPath"), hx::TCanCast< BezierPath_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BezierPath_obj::__boot()
{
}

} // end namespace motion
