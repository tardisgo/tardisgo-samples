#include <hxcpp.h>

#ifndef INCLUDED_motion_BezierPath
#include <motion/BezierPath.h>
#endif
#ifndef INCLUDED_motion_ComponentPath
#include <motion/ComponentPath.h>
#endif
#ifndef INCLUDED_motion_IComponentPath
#include <motion/IComponentPath.h>
#endif
#ifndef INCLUDED_motion_LinearPath
#include <motion/LinearPath.h>
#endif
#ifndef INCLUDED_motion_MotionPath
#include <motion/MotionPath.h>
#endif
#ifndef INCLUDED_motion_RotationPath
#include <motion/RotationPath.h>
#endif
namespace motion{

Void MotionPath_obj::__construct()
{
HX_STACK_PUSH("MotionPath::new","motion/MotionPath.hx",20);
{
	HX_STACK_LINE(22)
	this->_x = ::motion::ComponentPath_obj::__new();
	HX_STACK_LINE(23)
	this->_y = ::motion::ComponentPath_obj::__new();
	HX_STACK_LINE(25)
	this->_rotation = null();
}
;
	return null();
}

MotionPath_obj::~MotionPath_obj() { }

Dynamic MotionPath_obj::__CreateEmpty() { return  new MotionPath_obj; }
hx::ObjectPtr< MotionPath_obj > MotionPath_obj::__new()
{  hx::ObjectPtr< MotionPath_obj > result = new MotionPath_obj();
	result->__construct();
	return result;}

Dynamic MotionPath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MotionPath_obj > result = new MotionPath_obj();
	result->__construct();
	return result;}

::motion::IComponentPath MotionPath_obj::get_y( ){
	HX_STACK_PUSH("MotionPath::get_y","motion/MotionPath.hx",93);
	HX_STACK_THIS(this);
	HX_STACK_LINE(93)
	return this->_y;
}


HX_DEFINE_DYNAMIC_FUNC0(MotionPath_obj,get_y,return )

::motion::IComponentPath MotionPath_obj::get_x( ){
	HX_STACK_PUSH("MotionPath::get_x","motion/MotionPath.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_LINE(86)
	return this->_x;
}


HX_DEFINE_DYNAMIC_FUNC0(MotionPath_obj,get_x,return )

::motion::RotationPath MotionPath_obj::get_rotation( ){
	HX_STACK_PUSH("MotionPath::get_rotation","motion/MotionPath.hx",73);
	HX_STACK_THIS(this);
	HX_STACK_LINE(75)
	if (((this->_rotation == null()))){
		HX_STACK_LINE(75)
		this->_rotation = ::motion::RotationPath_obj::__new(this->_x,this->_y);
	}
	HX_STACK_LINE(81)
	return this->_rotation;
}


HX_DEFINE_DYNAMIC_FUNC0(MotionPath_obj,get_rotation,return )

::motion::MotionPath MotionPath_obj::line( Float x,Float y,hx::Null< Float >  __o_strength){
Float strength = __o_strength.Default(1);
	HX_STACK_PUSH("MotionPath::line","motion/MotionPath.hx",56);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(strength,"strength");
{
		HX_STACK_LINE(58)
		this->_x->addPath(::motion::LinearPath_obj::__new(x,strength));
		HX_STACK_LINE(59)
		this->_y->addPath(::motion::LinearPath_obj::__new(y,strength));
		HX_STACK_LINE(61)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(MotionPath_obj,line,return )

::motion::MotionPath MotionPath_obj::bezier( Float x,Float y,Float controlX,Float controlY,hx::Null< Float >  __o_strength){
Float strength = __o_strength.Default(1);
	HX_STACK_PUSH("MotionPath::bezier","motion/MotionPath.hx",39);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(controlX,"controlX");
	HX_STACK_ARG(controlY,"controlY");
	HX_STACK_ARG(strength,"strength");
{
		HX_STACK_LINE(41)
		this->_x->addPath(::motion::BezierPath_obj::__new(x,controlX,strength));
		HX_STACK_LINE(42)
		this->_y->addPath(::motion::BezierPath_obj::__new(y,controlY,strength));
		HX_STACK_LINE(44)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC5(MotionPath_obj,bezier,return )


MotionPath_obj::MotionPath_obj()
{
}

void MotionPath_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MotionPath);
	HX_MARK_MEMBER_NAME(_y,"_y");
	HX_MARK_MEMBER_NAME(_x,"_x");
	HX_MARK_MEMBER_NAME(_rotation,"_rotation");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_END_CLASS();
}

void MotionPath_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_y,"_y");
	HX_VISIT_MEMBER_NAME(_x,"_x");
	HX_VISIT_MEMBER_NAME(_rotation,"_rotation");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
}

Dynamic MotionPath_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return inCallProp ? get_y() : y; }
		if (HX_FIELD_EQ(inName,"x") ) { return inCallProp ? get_x() : x; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"_y") ) { return _y; }
		if (HX_FIELD_EQ(inName,"_x") ) { return _x; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"line") ) { return line_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"get_y") ) { return get_y_dyn(); }
		if (HX_FIELD_EQ(inName,"get_x") ) { return get_x_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bezier") ) { return bezier_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { return inCallProp ? get_rotation() : rotation; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_rotation") ) { return _rotation; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_rotation") ) { return get_rotation_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MotionPath_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< ::motion::IComponentPath >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< ::motion::IComponentPath >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"_y") ) { _y=inValue.Cast< ::motion::ComponentPath >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_x") ) { _x=inValue.Cast< ::motion::ComponentPath >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< ::motion::RotationPath >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_rotation") ) { _rotation=inValue.Cast< ::motion::RotationPath >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MotionPath_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_y"));
	outFields->push(HX_CSTRING("_x"));
	outFields->push(HX_CSTRING("_rotation"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("rotation"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_y"),
	HX_CSTRING("get_x"),
	HX_CSTRING("get_rotation"),
	HX_CSTRING("line"),
	HX_CSTRING("bezier"),
	HX_CSTRING("_y"),
	HX_CSTRING("_x"),
	HX_CSTRING("_rotation"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	HX_CSTRING("rotation"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MotionPath_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MotionPath_obj::__mClass,"__mClass");
};

Class MotionPath_obj::__mClass;

void MotionPath_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.MotionPath"), hx::TCanCast< MotionPath_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MotionPath_obj::__boot()
{
}

} // end namespace motion
