#include <hxcpp.h>

#ifndef INCLUDED_openfl_gl_GLFramebuffer
#include <openfl/gl/GLFramebuffer.h>
#endif
#ifndef INCLUDED_openfl_gl_GLObject
#include <openfl/gl/GLObject.h>
#endif
namespace openfl{
namespace gl{

Void GLFramebuffer_obj::__construct(int version,Dynamic id)
{
HX_STACK_PUSH("GLFramebuffer::new","openfl/gl/GLFramebuffer.hx",7);
{
	HX_STACK_LINE(7)
	super::__construct(version,id);
}
;
	return null();
}

GLFramebuffer_obj::~GLFramebuffer_obj() { }

Dynamic GLFramebuffer_obj::__CreateEmpty() { return  new GLFramebuffer_obj; }
hx::ObjectPtr< GLFramebuffer_obj > GLFramebuffer_obj::__new(int version,Dynamic id)
{  hx::ObjectPtr< GLFramebuffer_obj > result = new GLFramebuffer_obj();
	result->__construct(version,id);
	return result;}

Dynamic GLFramebuffer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GLFramebuffer_obj > result = new GLFramebuffer_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String GLFramebuffer_obj::getType( ){
	HX_STACK_PUSH("GLFramebuffer::getType","openfl/gl/GLFramebuffer.hx",14);
	HX_STACK_THIS(this);
	HX_STACK_LINE(14)
	return HX_CSTRING("Framebuffer");
}



GLFramebuffer_obj::GLFramebuffer_obj()
{
}

void GLFramebuffer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GLFramebuffer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GLFramebuffer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic GLFramebuffer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GLFramebuffer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void GLFramebuffer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getType"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GLFramebuffer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GLFramebuffer_obj::__mClass,"__mClass");
};

Class GLFramebuffer_obj::__mClass;

void GLFramebuffer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.gl.GLFramebuffer"), hx::TCanCast< GLFramebuffer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GLFramebuffer_obj::__boot()
{
}

} // end namespace openfl
} // end namespace gl
