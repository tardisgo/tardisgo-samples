#include <hxcpp.h>

#ifndef INCLUDED_openfl_gl_GLObject
#include <openfl/gl/GLObject.h>
#endif
#ifndef INCLUDED_openfl_gl_GLRenderbuffer
#include <openfl/gl/GLRenderbuffer.h>
#endif
namespace openfl{
namespace gl{

Void GLRenderbuffer_obj::__construct(int version,Dynamic id)
{
HX_STACK_PUSH("GLRenderbuffer::new","openfl/gl/GLRenderbuffer.hx",7);
{
	HX_STACK_LINE(7)
	super::__construct(version,id);
}
;
	return null();
}

GLRenderbuffer_obj::~GLRenderbuffer_obj() { }

Dynamic GLRenderbuffer_obj::__CreateEmpty() { return  new GLRenderbuffer_obj; }
hx::ObjectPtr< GLRenderbuffer_obj > GLRenderbuffer_obj::__new(int version,Dynamic id)
{  hx::ObjectPtr< GLRenderbuffer_obj > result = new GLRenderbuffer_obj();
	result->__construct(version,id);
	return result;}

Dynamic GLRenderbuffer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GLRenderbuffer_obj > result = new GLRenderbuffer_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String GLRenderbuffer_obj::getType( ){
	HX_STACK_PUSH("GLRenderbuffer::getType","openfl/gl/GLRenderbuffer.hx",14);
	HX_STACK_THIS(this);
	HX_STACK_LINE(14)
	return HX_CSTRING("Renderbuffer");
}



GLRenderbuffer_obj::GLRenderbuffer_obj()
{
}

void GLRenderbuffer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GLRenderbuffer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GLRenderbuffer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic GLRenderbuffer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GLRenderbuffer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void GLRenderbuffer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getType"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GLRenderbuffer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GLRenderbuffer_obj::__mClass,"__mClass");
};

Class GLRenderbuffer_obj::__mClass;

void GLRenderbuffer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.gl.GLRenderbuffer"), hx::TCanCast< GLRenderbuffer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GLRenderbuffer_obj::__boot()
{
}

} // end namespace openfl
} // end namespace gl
