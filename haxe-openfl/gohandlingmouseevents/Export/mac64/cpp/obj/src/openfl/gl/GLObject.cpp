#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_openfl_gl_GL
#include <openfl/gl/GL.h>
#endif
#ifndef INCLUDED_openfl_gl_GLObject
#include <openfl/gl/GLObject.h>
#endif
namespace openfl{
namespace gl{

Void GLObject_obj::__construct(int version,Dynamic id)
{
HX_STACK_PUSH("GLObject::new","openfl/gl/GLObject.hx",14);
{
	HX_STACK_LINE(16)
	this->version = version;
	HX_STACK_LINE(17)
	this->id = id;
}
;
	return null();
}

GLObject_obj::~GLObject_obj() { }

Dynamic GLObject_obj::__CreateEmpty() { return  new GLObject_obj; }
hx::ObjectPtr< GLObject_obj > GLObject_obj::__new(int version,Dynamic id)
{  hx::ObjectPtr< GLObject_obj > result = new GLObject_obj();
	result->__construct(version,id);
	return result;}

Dynamic GLObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GLObject_obj > result = new GLObject_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool GLObject_obj::get_valid( ){
	HX_STACK_PUSH("GLObject::get_valid","openfl/gl/GLObject.hx",71);
	HX_STACK_THIS(this);
	HX_STACK_LINE(71)
	return this->isValid();
}


HX_DEFINE_DYNAMIC_FUNC0(GLObject_obj,get_valid,return )

bool GLObject_obj::get_invalidated( ){
	HX_STACK_PUSH("GLObject::get_invalidated","openfl/gl/GLObject.hx",64);
	HX_STACK_THIS(this);
	HX_STACK_LINE(64)
	return this->isInvalid();
}


HX_DEFINE_DYNAMIC_FUNC0(GLObject_obj,get_invalidated,return )

::String GLObject_obj::toString( ){
	HX_STACK_PUSH("GLObject::toString","openfl/gl/GLObject.hx",50);
	HX_STACK_THIS(this);
	HX_STACK_LINE(50)
	return (((this->getType() + HX_CSTRING("(")) + ::Std_obj::string(this->id)) + HX_CSTRING(")"));
}


HX_DEFINE_DYNAMIC_FUNC0(GLObject_obj,toString,return )

bool GLObject_obj::isInvalid( ){
	HX_STACK_PUSH("GLObject::isInvalid","openfl/gl/GLObject.hx",43);
	HX_STACK_THIS(this);
	HX_STACK_LINE(43)
	return !(this->isValid());
}


HX_DEFINE_DYNAMIC_FUNC0(GLObject_obj,isInvalid,return )

bool GLObject_obj::isValid( ){
	HX_STACK_PUSH("GLObject::isValid","openfl/gl/GLObject.hx",36);
	HX_STACK_THIS(this);
	HX_STACK_LINE(36)
	return (bool((this->id != null())) && bool((this->version == ::openfl::gl::GL_obj::get_version())));
}


HX_DEFINE_DYNAMIC_FUNC0(GLObject_obj,isValid,return )

Void GLObject_obj::invalidate( ){
{
		HX_STACK_PUSH("GLObject::invalidate","openfl/gl/GLObject.hx",29);
		HX_STACK_THIS(this);
		HX_STACK_LINE(29)
		this->id = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GLObject_obj,invalidate,(void))

::String GLObject_obj::getType( ){
	HX_STACK_PUSH("GLObject::getType","openfl/gl/GLObject.hx",22);
	HX_STACK_THIS(this);
	HX_STACK_LINE(22)
	return HX_CSTRING("GLObject");
}


HX_DEFINE_DYNAMIC_FUNC0(GLObject_obj,getType,return )


GLObject_obj::GLObject_obj()
{
}

void GLObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GLObject);
	HX_MARK_MEMBER_NAME(version,"version");
	HX_MARK_MEMBER_NAME(valid,"valid");
	HX_MARK_MEMBER_NAME(invalidated,"invalidated");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_END_CLASS();
}

void GLObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(version,"version");
	HX_VISIT_MEMBER_NAME(valid,"valid");
	HX_VISIT_MEMBER_NAME(invalidated,"invalidated");
	HX_VISIT_MEMBER_NAME(id,"id");
}

Dynamic GLObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"valid") ) { return inCallProp ? get_valid() : valid; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isValid") ) { return isValid_dyn(); }
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"version") ) { return version; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_valid") ) { return get_valid_dyn(); }
		if (HX_FIELD_EQ(inName,"isInvalid") ) { return isInvalid_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"invalidated") ) { return inCallProp ? get_invalidated() : invalidated; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_invalidated") ) { return get_invalidated_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GLObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"valid") ) { valid=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"version") ) { version=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"invalidated") ) { invalidated=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GLObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("version"));
	outFields->push(HX_CSTRING("valid"));
	outFields->push(HX_CSTRING("invalidated"));
	outFields->push(HX_CSTRING("id"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_valid"),
	HX_CSTRING("get_invalidated"),
	HX_CSTRING("toString"),
	HX_CSTRING("isInvalid"),
	HX_CSTRING("isValid"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("getType"),
	HX_CSTRING("version"),
	HX_CSTRING("valid"),
	HX_CSTRING("invalidated"),
	HX_CSTRING("id"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GLObject_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GLObject_obj::__mClass,"__mClass");
};

Class GLObject_obj::__mClass;

void GLObject_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.gl.GLObject"), hx::TCanCast< GLObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GLObject_obj::__boot()
{
}

} // end namespace openfl
} // end namespace gl
