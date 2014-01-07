#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_io__Process_Stdin
#include <sys/io/_Process/Stdin.h>
#endif
namespace sys{
namespace io{
namespace _Process{

Void Stdin_obj::__construct(Dynamic p)
{
HX_STACK_PUSH("Stdin::new","/usr/lib/haxe/std/cpp/_std/sys/io/Process.hx",29);
{
	HX_STACK_LINE(30)
	this->p = p;
	HX_STACK_LINE(31)
	this->buf = ::haxe::io::Bytes_obj::alloc((int)1);
}
;
	return null();
}

Stdin_obj::~Stdin_obj() { }

Dynamic Stdin_obj::__CreateEmpty() { return  new Stdin_obj; }
hx::ObjectPtr< Stdin_obj > Stdin_obj::__new(Dynamic p)
{  hx::ObjectPtr< Stdin_obj > result = new Stdin_obj();
	result->__construct(p);
	return result;}

Dynamic Stdin_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Stdin_obj > result = new Stdin_obj();
	result->__construct(inArgs[0]);
	return result;}

int Stdin_obj::writeBytes( ::haxe::io::Bytes buf,int pos,int len){
	HX_STACK_PUSH("Stdin::writeBytes","/usr/lib/haxe/std/cpp/_std/sys/io/Process.hx",44);
	HX_STACK_THIS(this);
	HX_STACK_ARG(buf,"buf");
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(45)
	try{
		HX_STACK_LINE(45)
		return ::sys::io::_Process::Stdin_obj::_stdin_write(this->p,buf->b,pos,len);
	}
	catch(Dynamic __e){
		{
			HX_STACK_BEGIN_CATCH
			Dynamic e = __e;{
				HX_STACK_LINE(47)
				hx::Throw (::haxe::io::Eof_obj::__new());
			}
		}
	}
	HX_STACK_LINE(50)
	return (int)0;
}


Void Stdin_obj::writeByte( int c){
{
		HX_STACK_PUSH("Stdin::writeByte","/usr/lib/haxe/std/cpp/_std/sys/io/Process.hx",39);
		HX_STACK_THIS(this);
		HX_STACK_ARG(c,"c");
		HX_STACK_LINE(40)
		this->buf->b[(int)0] = c;
		HX_STACK_LINE(41)
		this->writeBytes(this->buf,(int)0,(int)1);
	}
return null();
}


Dynamic Stdin_obj::_stdin_write;


Stdin_obj::Stdin_obj()
{
}

void Stdin_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Stdin);
	HX_MARK_MEMBER_NAME(buf,"buf");
	HX_MARK_MEMBER_NAME(p,"p");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Stdin_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(buf,"buf");
	HX_VISIT_MEMBER_NAME(p,"p");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Stdin_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { return p; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { return buf; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_stdin_write") ) { return _stdin_write; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Stdin_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { p=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_stdin_write") ) { _stdin_write=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Stdin_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("buf"));
	outFields->push(HX_CSTRING("p"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_stdin_write"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("writeBytes"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("buf"),
	HX_CSTRING("p"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Stdin_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Stdin_obj::_stdin_write,"_stdin_write");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Stdin_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Stdin_obj::_stdin_write,"_stdin_write");
};

Class Stdin_obj::__mClass;

void Stdin_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.io._Process.Stdin"), hx::TCanCast< Stdin_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Stdin_obj::__boot()
{
	_stdin_write= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("process_stdin_write"),(int)4);
}

} // end namespace sys
} // end namespace io
} // end namespace _Process
