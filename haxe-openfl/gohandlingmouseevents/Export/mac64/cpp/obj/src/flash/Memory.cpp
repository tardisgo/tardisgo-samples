#include <hxcpp.h>

#ifndef INCLUDED_flash_Memory
#include <flash/Memory.h>
#endif
#ifndef INCLUDED_flash_utils_ByteArray
#include <flash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_flash_utils_IDataInput
#include <flash/utils/IDataInput.h>
#endif
#ifndef INCLUDED_flash_utils_IDataOutput
#include <flash/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
namespace flash{

Void Memory_obj::__construct()
{
	return null();
}

Memory_obj::~Memory_obj() { }

Dynamic Memory_obj::__CreateEmpty() { return  new Memory_obj; }
hx::ObjectPtr< Memory_obj > Memory_obj::__new()
{  hx::ObjectPtr< Memory_obj > result = new Memory_obj();
	result->__construct();
	return result;}

Dynamic Memory_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Memory_obj > result = new Memory_obj();
	result->__construct();
	return result;}

::flash::utils::ByteArray Memory_obj::gcRef;

int Memory_obj::len;

Void Memory_obj::select( ::flash::utils::ByteArray bytes){
{
		HX_STACK_PUSH("Memory::select","flash/Memory.hx",20);
		HX_STACK_ARG(bytes,"bytes");
		HX_STACK_LINE(33)
		::flash::Memory_obj::gcRef = bytes;
		HX_STACK_LINE(34)
		if (((bytes == null()))){
			HX_STACK_LINE(34)
			::__hxcpp_memory_clear();
		}
		else{
			HX_STACK_LINE(38)
			::__hxcpp_memory_select(bytes->b);
		}
		HX_STACK_LINE(45)
		if (((bytes == null()))){
			HX_STACK_LINE(45)
			::flash::Memory_obj::len = (int)0;
		}
		else{
			HX_STACK_LINE(49)
			::flash::Memory_obj::len = bytes->length;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,select,(void))

int Memory_obj::getByte( int addr){
	HX_STACK_PUSH("Memory::getByte","flash/Memory.hx",136);
	HX_STACK_ARG(addr,"addr");
	HX_STACK_LINE(136)
	return ::__hxcpp_memory_get_byte(addr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,getByte,return )

Float Memory_obj::getDouble( int addr){
	HX_STACK_PUSH("Memory::getDouble","flash/Memory.hx",144);
	HX_STACK_ARG(addr,"addr");
	HX_STACK_LINE(144)
	return ::__hxcpp_memory_get_double(addr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,getDouble,return )

Float Memory_obj::getFloat( int addr){
	HX_STACK_PUSH("Memory::getFloat","flash/Memory.hx",152);
	HX_STACK_ARG(addr,"addr");
	HX_STACK_LINE(152)
	return ::__hxcpp_memory_get_float(addr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,getFloat,return )

int Memory_obj::getI32( int addr){
	HX_STACK_PUSH("Memory::getI32","flash/Memory.hx",160);
	HX_STACK_ARG(addr,"addr");
	HX_STACK_LINE(160)
	return ::__hxcpp_memory_get_i32(addr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,getI32,return )

int Memory_obj::getUI16( int addr){
	HX_STACK_PUSH("Memory::getUI16","flash/Memory.hx",168);
	HX_STACK_ARG(addr,"addr");
	HX_STACK_LINE(168)
	return ::__hxcpp_memory_get_ui16(addr);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,getUI16,return )

Void Memory_obj::setByte( int addr,int v){
{
		HX_STACK_PUSH("Memory::setByte","flash/Memory.hx",176);
		HX_STACK_ARG(addr,"addr");
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(176)
		::__hxcpp_memory_set_byte(addr,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Memory_obj,setByte,(void))

Void Memory_obj::setDouble( int addr,Float v){
{
		HX_STACK_PUSH("Memory::setDouble","flash/Memory.hx",184);
		HX_STACK_ARG(addr,"addr");
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(184)
		::__hxcpp_memory_set_double(addr,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Memory_obj,setDouble,(void))

Void Memory_obj::setFloat( int addr,Float v){
{
		HX_STACK_PUSH("Memory::setFloat","flash/Memory.hx",192);
		HX_STACK_ARG(addr,"addr");
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(192)
		::__hxcpp_memory_set_float(addr,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Memory_obj,setFloat,(void))

Void Memory_obj::setI16( int addr,int v){
{
		HX_STACK_PUSH("Memory::setI16","flash/Memory.hx",200);
		HX_STACK_ARG(addr,"addr");
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(200)
		::__hxcpp_memory_set_i16(addr,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Memory_obj,setI16,(void))

Void Memory_obj::setI32( int addr,int v){
{
		HX_STACK_PUSH("Memory::setI32","flash/Memory.hx",208);
		HX_STACK_ARG(addr,"addr");
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(208)
		::__hxcpp_memory_set_i32(addr,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Memory_obj,setI32,(void))


Memory_obj::Memory_obj()
{
}

void Memory_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Memory);
	HX_MARK_END_CLASS();
}

void Memory_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Memory_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"len") ) { return len; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"gcRef") ) { return gcRef; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"select") ) { return select_dyn(); }
		if (HX_FIELD_EQ(inName,"getI32") ) { return getI32_dyn(); }
		if (HX_FIELD_EQ(inName,"setI16") ) { return setI16_dyn(); }
		if (HX_FIELD_EQ(inName,"setI32") ) { return setI32_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getByte") ) { return getByte_dyn(); }
		if (HX_FIELD_EQ(inName,"getUI16") ) { return getUI16_dyn(); }
		if (HX_FIELD_EQ(inName,"setByte") ) { return setByte_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getFloat") ) { return getFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"setFloat") ) { return setFloat_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getDouble") ) { return getDouble_dyn(); }
		if (HX_FIELD_EQ(inName,"setDouble") ) { return setDouble_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Memory_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"len") ) { len=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"gcRef") ) { gcRef=inValue.Cast< ::flash::utils::ByteArray >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Memory_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("gcRef"),
	HX_CSTRING("len"),
	HX_CSTRING("select"),
	HX_CSTRING("getByte"),
	HX_CSTRING("getDouble"),
	HX_CSTRING("getFloat"),
	HX_CSTRING("getI32"),
	HX_CSTRING("getUI16"),
	HX_CSTRING("setByte"),
	HX_CSTRING("setDouble"),
	HX_CSTRING("setFloat"),
	HX_CSTRING("setI16"),
	HX_CSTRING("setI32"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Memory_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Memory_obj::gcRef,"gcRef");
	HX_MARK_MEMBER_NAME(Memory_obj::len,"len");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Memory_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Memory_obj::gcRef,"gcRef");
	HX_VISIT_MEMBER_NAME(Memory_obj::len,"len");
};

Class Memory_obj::__mClass;

void Memory_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.Memory"), hx::TCanCast< Memory_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Memory_obj::__boot()
{
}

} // end namespace flash
