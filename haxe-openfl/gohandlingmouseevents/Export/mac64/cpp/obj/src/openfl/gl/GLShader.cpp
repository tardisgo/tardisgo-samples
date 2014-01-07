#include <hxcpp.h>

#ifndef INCLUDED_openfl_gl_GLObject
#include <openfl/gl/GLObject.h>
#endif
#ifndef INCLUDED_openfl_gl_GLShader
#include <openfl/gl/GLShader.h>
#endif
namespace openfl{
namespace gl{

Void GLShader_obj::__construct(int version,Dynamic id)
{
HX_STACK_PUSH("GLShader::new","openfl/gl/GLShader.hx",7);
{
	HX_STACK_LINE(7)
	super::__construct(version,id);
}
;
	return null();
}

GLShader_obj::~GLShader_obj() { }

Dynamic GLShader_obj::__CreateEmpty() { return  new GLShader_obj; }
hx::ObjectPtr< GLShader_obj > GLShader_obj::__new(int version,Dynamic id)
{  hx::ObjectPtr< GLShader_obj > result = new GLShader_obj();
	result->__construct(version,id);
	return result;}

Dynamic GLShader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GLShader_obj > result = new GLShader_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String GLShader_obj::getType( ){
	HX_STACK_PUSH("GLShader::getType","openfl/gl/GLShader.hx",14);
	HX_STACK_THIS(this);
	HX_STACK_LINE(14)
	return HX_CSTRING("Shader");
}



GLShader_obj::GLShader_obj()
{
}

void GLShader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GLShader);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GLShader_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic GLShader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GLShader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void GLShader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getType"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GLShader_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GLShader_obj::__mClass,"__mClass");
};

Class GLShader_obj::__mClass;

void GLShader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.gl.GLShader"), hx::TCanCast< GLShader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GLShader_obj::__boot()
{
}

} // end namespace openfl
} // end namespace gl
