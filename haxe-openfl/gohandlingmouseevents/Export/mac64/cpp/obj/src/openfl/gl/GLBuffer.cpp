#include <hxcpp.h>

#ifndef INCLUDED_openfl_gl_GLBuffer
#include <openfl/gl/GLBuffer.h>
#endif
#ifndef INCLUDED_openfl_gl_GLObject
#include <openfl/gl/GLObject.h>
#endif
namespace openfl{
namespace gl{

Void GLBuffer_obj::__construct(int version,Dynamic id)
{
HX_STACK_PUSH("GLBuffer::new","openfl/gl/GLBuffer.hx",7);
{
	HX_STACK_LINE(7)
	super::__construct(version,id);
}
;
	return null();
}

GLBuffer_obj::~GLBuffer_obj() { }

Dynamic GLBuffer_obj::__CreateEmpty() { return  new GLBuffer_obj; }
hx::ObjectPtr< GLBuffer_obj > GLBuffer_obj::__new(int version,Dynamic id)
{  hx::ObjectPtr< GLBuffer_obj > result = new GLBuffer_obj();
	result->__construct(version,id);
	return result;}

Dynamic GLBuffer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GLBuffer_obj > result = new GLBuffer_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String GLBuffer_obj::getType( ){
	HX_STACK_PUSH("GLBuffer::getType","openfl/gl/GLBuffer.hx",14);
	HX_STACK_THIS(this);
	HX_STACK_LINE(14)
	return HX_CSTRING("Buffer");
}



GLBuffer_obj::GLBuffer_obj()
{
}

void GLBuffer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GLBuffer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GLBuffer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic GLBuffer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GLBuffer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void GLBuffer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getType"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GLBuffer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GLBuffer_obj::__mClass,"__mClass");
};

Class GLBuffer_obj::__mClass;

void GLBuffer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.gl.GLBuffer"), hx::TCanCast< GLBuffer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GLBuffer_obj::__boot()
{
}

} // end namespace openfl
} // end namespace gl
