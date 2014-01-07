#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_motion_ComponentPath
#include <motion/ComponentPath.h>
#endif
#ifndef INCLUDED_motion_IComponentPath
#include <motion/IComponentPath.h>
#endif
#ifndef INCLUDED_motion_RotationPath
#include <motion/RotationPath.h>
#endif
namespace motion{

Void RotationPath_obj::__construct(::motion::ComponentPath x,::motion::ComponentPath y)
{
HX_STACK_PUSH("RotationPath::new","motion/MotionPath.hx",247);
{
	HX_STACK_LINE(254)
	this->step = 0.01;
	HX_STACK_LINE(261)
	this->_x = x;
	HX_STACK_LINE(262)
	this->_y = y;
	HX_STACK_LINE(264)
	this->offset = (int)0;
	HX_STACK_LINE(266)
	this->start = this->calculate(0.0);
}
;
	return null();
}

RotationPath_obj::~RotationPath_obj() { }

Dynamic RotationPath_obj::__CreateEmpty() { return  new RotationPath_obj; }
hx::ObjectPtr< RotationPath_obj > RotationPath_obj::__new(::motion::ComponentPath x,::motion::ComponentPath y)
{  hx::ObjectPtr< RotationPath_obj > result = new RotationPath_obj();
	result->__construct(x,y);
	return result;}

Dynamic RotationPath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RotationPath_obj > result = new RotationPath_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *RotationPath_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::motion::IComponentPath_obj)) return operator ::motion::IComponentPath_obj *();
	return super::__ToInterface(inType);
}

Float RotationPath_obj::get_end( ){
	HX_STACK_PUSH("RotationPath::get_end","motion/MotionPath.hx",291);
	HX_STACK_THIS(this);
	HX_STACK_LINE(291)
	return this->calculate(1.0);
}


HX_DEFINE_DYNAMIC_FUNC0(RotationPath_obj,get_end,return )

Float RotationPath_obj::calculate( Float k){
	HX_STACK_PUSH("RotationPath::calculate","motion/MotionPath.hx",271);
	HX_STACK_THIS(this);
	HX_STACK_ARG(k,"k");
	HX_STACK_LINE(273)
	Float dX = (this->_x->calculate(k) - this->_x->calculate((k + this->step)));		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(274)
	Float dY = (this->_y->calculate(k) - this->_y->calculate((k + this->step)));		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(276)
	Float angle = (::Math_obj::atan2(dY,dX) * ((Float((int)180) / Float(::Math_obj::PI))));		HX_STACK_VAR(angle,"angle");
	HX_STACK_LINE(277)
	angle = hx::Mod(((angle + this->offset)),(int)360);
	HX_STACK_LINE(279)
	return angle;
}


HX_DEFINE_DYNAMIC_FUNC1(RotationPath_obj,calculate,return )


RotationPath_obj::RotationPath_obj()
{
}

void RotationPath_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RotationPath);
	HX_MARK_MEMBER_NAME(_y,"_y");
	HX_MARK_MEMBER_NAME(_x,"_x");
	HX_MARK_MEMBER_NAME(step,"step");
	HX_MARK_MEMBER_NAME(start,"start");
	HX_MARK_MEMBER_NAME(offset,"offset");
	HX_MARK_MEMBER_NAME(end,"end");
	HX_MARK_END_CLASS();
}

void RotationPath_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_y,"_y");
	HX_VISIT_MEMBER_NAME(_x,"_x");
	HX_VISIT_MEMBER_NAME(step,"step");
	HX_VISIT_MEMBER_NAME(start,"start");
	HX_VISIT_MEMBER_NAME(offset,"offset");
	HX_VISIT_MEMBER_NAME(end,"end");
}

Dynamic RotationPath_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"_y") ) { return _y; }
		if (HX_FIELD_EQ(inName,"_x") ) { return _x; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { return inCallProp ? get_end() : end; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"step") ) { return step; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { return offset; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_end") ) { return get_end_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"calculate") ) { return calculate_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RotationPath_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"_y") ) { _y=inValue.Cast< ::motion::ComponentPath >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_x") ) { _x=inValue.Cast< ::motion::ComponentPath >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { end=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"step") ) { step=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { start=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RotationPath_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_y"));
	outFields->push(HX_CSTRING("_x"));
	outFields->push(HX_CSTRING("step"));
	outFields->push(HX_CSTRING("start"));
	outFields->push(HX_CSTRING("offset"));
	outFields->push(HX_CSTRING("end"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_end"),
	HX_CSTRING("calculate"),
	HX_CSTRING("_y"),
	HX_CSTRING("_x"),
	HX_CSTRING("step"),
	HX_CSTRING("start"),
	HX_CSTRING("offset"),
	HX_CSTRING("end"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RotationPath_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RotationPath_obj::__mClass,"__mClass");
};

Class RotationPath_obj::__mClass;

void RotationPath_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.RotationPath"), hx::TCanCast< RotationPath_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void RotationPath_obj::__boot()
{
}

} // end namespace motion
