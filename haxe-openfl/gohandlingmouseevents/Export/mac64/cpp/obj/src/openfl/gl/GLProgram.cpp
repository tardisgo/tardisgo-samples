#include <hxcpp.h>

#ifndef INCLUDED_openfl_gl_GLObject
#include <openfl/gl/GLObject.h>
#endif
#ifndef INCLUDED_openfl_gl_GLProgram
#include <openfl/gl/GLProgram.h>
#endif
#ifndef INCLUDED_openfl_gl_GLShader
#include <openfl/gl/GLShader.h>
#endif
namespace openfl{
namespace gl{

Void GLProgram_obj::__construct(int version,Dynamic id)
{
HX_STACK_PUSH("GLProgram::new","openfl/gl/GLProgram.hx",10);
{
	HX_STACK_LINE(12)
	super::__construct(version,id);
	HX_STACK_LINE(13)
	this->shaders = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

GLProgram_obj::~GLProgram_obj() { }

Dynamic GLProgram_obj::__CreateEmpty() { return  new GLProgram_obj; }
hx::ObjectPtr< GLProgram_obj > GLProgram_obj::__new(int version,Dynamic id)
{  hx::ObjectPtr< GLProgram_obj > result = new GLProgram_obj();
	result->__construct(version,id);
	return result;}

Dynamic GLProgram_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GLProgram_obj > result = new GLProgram_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String GLProgram_obj::getType( ){
	HX_STACK_PUSH("GLProgram::getType","openfl/gl/GLProgram.hx",32);
	HX_STACK_THIS(this);
	HX_STACK_LINE(32)
	return HX_CSTRING("Program");
}


Array< ::Dynamic > GLProgram_obj::getShaders( ){
	HX_STACK_PUSH("GLProgram::getShaders","openfl/gl/GLProgram.hx",25);
	HX_STACK_THIS(this);
	HX_STACK_LINE(25)
	return this->shaders->copy();
}


HX_DEFINE_DYNAMIC_FUNC0(GLProgram_obj,getShaders,return )

Void GLProgram_obj::attach( ::openfl::gl::GLShader shader){
{
		HX_STACK_PUSH("GLProgram::attach","openfl/gl/GLProgram.hx",18);
		HX_STACK_THIS(this);
		HX_STACK_ARG(shader,"shader");
		HX_STACK_LINE(18)
		this->shaders->push(shader);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GLProgram_obj,attach,(void))


GLProgram_obj::GLProgram_obj()
{
}

void GLProgram_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GLProgram);
	HX_MARK_MEMBER_NAME(shaders,"shaders");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GLProgram_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(shaders,"shaders");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic GLProgram_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"shaders") ) { return shaders; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getShaders") ) { return getShaders_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GLProgram_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"shaders") ) { shaders=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GLProgram_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("shaders"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getType"),
	HX_CSTRING("getShaders"),
	HX_CSTRING("attach"),
	HX_CSTRING("shaders"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GLProgram_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GLProgram_obj::__mClass,"__mClass");
};

Class GLProgram_obj::__mClass;

void GLProgram_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.gl.GLProgram"), hx::TCanCast< GLProgram_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GLProgram_obj::__boot()
{
}

} // end namespace openfl
} // end namespace gl
