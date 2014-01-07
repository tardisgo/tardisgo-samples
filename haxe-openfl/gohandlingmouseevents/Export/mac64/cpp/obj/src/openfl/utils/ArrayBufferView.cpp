#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_openfl_utils_ArrayBufferView
#include <openfl/utils/ArrayBufferView.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
namespace openfl{
namespace utils{

Void ArrayBufferView_obj::__construct(Dynamic lengthOrBuffer,hx::Null< int >  __o_byteOffset,Dynamic length)
{
HX_STACK_PUSH("ArrayBufferView::new","openfl/utils/ArrayBufferView.hx",24);
int byteOffset = __o_byteOffset.Default(0);
{
	HX_STACK_LINE(26)
	if ((::Std_obj::is(lengthOrBuffer,hx::ClassOf< ::Int >()))){
		HX_STACK_LINE(28)
		this->byteLength = ::Std_obj::_int(lengthOrBuffer);
		HX_STACK_LINE(29)
		this->byteOffset = (int)0;
		HX_STACK_LINE(30)
		this->buffer = ::flash::utils::ByteArray_obj::__new(::Std_obj::_int(lengthOrBuffer));
	}
	else{
		HX_STACK_LINE(34)
		this->buffer = lengthOrBuffer;
		HX_STACK_LINE(36)
		if (((this->buffer == null()))){
			HX_STACK_LINE(36)
			hx::Throw (HX_CSTRING("Invalid input buffer"));
		}
		HX_STACK_LINE(42)
		this->byteOffset = byteOffset;
		HX_STACK_LINE(44)
		if (((byteOffset > this->buffer->length))){
			HX_STACK_LINE(44)
			hx::Throw (HX_CSTRING("Invalid starting position"));
		}
		HX_STACK_LINE(50)
		if (((length == null()))){
			HX_STACK_LINE(50)
			this->byteLength = (this->buffer->length - byteOffset);
		}
		else{
			HX_STACK_LINE(56)
			this->byteLength = length;
			HX_STACK_LINE(58)
			if ((((this->byteLength + byteOffset) > this->buffer->length))){
				HX_STACK_LINE(58)
				hx::Throw (HX_CSTRING("Invalid buffer length"));
			}
		}
	}
	HX_STACK_LINE(68)
	this->buffer->bigEndian = false;
	HX_STACK_LINE(71)
	this->bytes = this->buffer->b;
}
;
	return null();
}

ArrayBufferView_obj::~ArrayBufferView_obj() { }

Dynamic ArrayBufferView_obj::__CreateEmpty() { return  new ArrayBufferView_obj; }
hx::ObjectPtr< ArrayBufferView_obj > ArrayBufferView_obj::__new(Dynamic lengthOrBuffer,hx::Null< int >  __o_byteOffset,Dynamic length)
{  hx::ObjectPtr< ArrayBufferView_obj > result = new ArrayBufferView_obj();
	result->__construct(lengthOrBuffer,__o_byteOffset,length);
	return result;}

Dynamic ArrayBufferView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ArrayBufferView_obj > result = new ArrayBufferView_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *ArrayBufferView_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::openfl::utils::IMemoryRange_obj)) return operator ::openfl::utils::IMemoryRange_obj *();
	return super::__ToInterface(inType);
}

Void ArrayBufferView_obj::setUInt8( int position,int value){
{
		HX_STACK_PUSH("ArrayBufferView::setUInt8","openfl/utils/ArrayBufferView.hx",189);
		HX_STACK_THIS(this);
		HX_STACK_ARG(position,"position");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(189)
		::__hxcpp_memory_set_byte(this->bytes,(position + this->byteOffset),value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ArrayBufferView_obj,setUInt8,(void))

Void ArrayBufferView_obj::setInt32( int position,int value){
{
		HX_STACK_PUSH("ArrayBufferView::setInt32","openfl/utils/ArrayBufferView.hx",177);
		HX_STACK_THIS(this);
		HX_STACK_ARG(position,"position");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(177)
		::__hxcpp_memory_set_i32(this->bytes,(position + this->byteOffset),value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ArrayBufferView_obj,setInt32,(void))

Void ArrayBufferView_obj::setInt16( int position,int value){
{
		HX_STACK_PUSH("ArrayBufferView::setInt16","openfl/utils/ArrayBufferView.hx",165);
		HX_STACK_THIS(this);
		HX_STACK_ARG(position,"position");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(165)
		::__hxcpp_memory_set_i16(this->bytes,(position + this->byteOffset),value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ArrayBufferView_obj,setInt16,(void))

Void ArrayBufferView_obj::setFloat32( int position,Float value){
{
		HX_STACK_PUSH("ArrayBufferView::setFloat32","openfl/utils/ArrayBufferView.hx",153);
		HX_STACK_THIS(this);
		HX_STACK_ARG(position,"position");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(153)
		::__hxcpp_memory_set_float(this->bytes,(position + this->byteOffset),value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ArrayBufferView_obj,setFloat32,(void))

int ArrayBufferView_obj::getUInt8( int position){
	HX_STACK_PUSH("ArrayBufferView::getUInt8","openfl/utils/ArrayBufferView.hx",141);
	HX_STACK_THIS(this);
	HX_STACK_ARG(position,"position");
	HX_STACK_LINE(141)
	return ::__hxcpp_memory_get_byte(this->bytes,(position + this->byteOffset));
}


HX_DEFINE_DYNAMIC_FUNC1(ArrayBufferView_obj,getUInt8,return )

int ArrayBufferView_obj::getStart( ){
	HX_STACK_PUSH("ArrayBufferView::getStart","openfl/utils/ArrayBufferView.hx",134);
	HX_STACK_THIS(this);
	HX_STACK_LINE(134)
	return this->byteOffset;
}


HX_DEFINE_DYNAMIC_FUNC0(ArrayBufferView_obj,getStart,return )

Dynamic ArrayBufferView_obj::getNativePointer( ){
	HX_STACK_PUSH("ArrayBufferView::getNativePointer","openfl/utils/ArrayBufferView.hx",127);
	HX_STACK_THIS(this);
	HX_STACK_LINE(127)
	return this->buffer->getNativePointer();
}


HX_DEFINE_DYNAMIC_FUNC0(ArrayBufferView_obj,getNativePointer,return )

int ArrayBufferView_obj::getLength( ){
	HX_STACK_PUSH("ArrayBufferView::getLength","openfl/utils/ArrayBufferView.hx",120);
	HX_STACK_THIS(this);
	HX_STACK_LINE(120)
	return this->byteLength;
}


HX_DEFINE_DYNAMIC_FUNC0(ArrayBufferView_obj,getLength,return )

int ArrayBufferView_obj::getInt32( int position){
	HX_STACK_PUSH("ArrayBufferView::getInt32","openfl/utils/ArrayBufferView.hx",108);
	HX_STACK_THIS(this);
	HX_STACK_ARG(position,"position");
	HX_STACK_LINE(108)
	return ::__hxcpp_memory_get_i32(this->bytes,(position + this->byteOffset));
}


HX_DEFINE_DYNAMIC_FUNC1(ArrayBufferView_obj,getInt32,return )

int ArrayBufferView_obj::getInt16( int position){
	HX_STACK_PUSH("ArrayBufferView::getInt16","openfl/utils/ArrayBufferView.hx",96);
	HX_STACK_THIS(this);
	HX_STACK_ARG(position,"position");
	HX_STACK_LINE(96)
	return ::__hxcpp_memory_get_i16(this->bytes,(position + this->byteOffset));
}


HX_DEFINE_DYNAMIC_FUNC1(ArrayBufferView_obj,getInt16,return )

Float ArrayBufferView_obj::getFloat32( int position){
	HX_STACK_PUSH("ArrayBufferView::getFloat32","openfl/utils/ArrayBufferView.hx",84);
	HX_STACK_THIS(this);
	HX_STACK_ARG(position,"position");
	HX_STACK_LINE(84)
	return ::__hxcpp_memory_get_float(this->bytes,(position + this->byteOffset));
}


HX_DEFINE_DYNAMIC_FUNC1(ArrayBufferView_obj,getFloat32,return )

::flash::utils::ByteArray ArrayBufferView_obj::getByteBuffer( ){
	HX_STACK_PUSH("ArrayBufferView::getByteBuffer","openfl/utils/ArrayBufferView.hx",77);
	HX_STACK_THIS(this);
	HX_STACK_LINE(77)
	return this->buffer;
}


HX_DEFINE_DYNAMIC_FUNC0(ArrayBufferView_obj,getByteBuffer,return )

::String ArrayBufferView_obj::invalidDataIndex;


ArrayBufferView_obj::ArrayBufferView_obj()
{
}

void ArrayBufferView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ArrayBufferView);
	HX_MARK_MEMBER_NAME(bytes,"bytes");
	HX_MARK_MEMBER_NAME(byteLength,"byteLength");
	HX_MARK_MEMBER_NAME(byteOffset,"byteOffset");
	HX_MARK_MEMBER_NAME(buffer,"buffer");
	HX_MARK_END_CLASS();
}

void ArrayBufferView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bytes,"bytes");
	HX_VISIT_MEMBER_NAME(byteLength,"byteLength");
	HX_VISIT_MEMBER_NAME(byteOffset,"byteOffset");
	HX_VISIT_MEMBER_NAME(buffer,"buffer");
}

Dynamic ArrayBufferView_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"bytes") ) { return bytes; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"buffer") ) { return buffer; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setUInt8") ) { return setUInt8_dyn(); }
		if (HX_FIELD_EQ(inName,"setInt32") ) { return setInt32_dyn(); }
		if (HX_FIELD_EQ(inName,"setInt16") ) { return setInt16_dyn(); }
		if (HX_FIELD_EQ(inName,"getUInt8") ) { return getUInt8_dyn(); }
		if (HX_FIELD_EQ(inName,"getStart") ) { return getStart_dyn(); }
		if (HX_FIELD_EQ(inName,"getInt32") ) { return getInt32_dyn(); }
		if (HX_FIELD_EQ(inName,"getInt16") ) { return getInt16_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getLength") ) { return getLength_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"setFloat32") ) { return setFloat32_dyn(); }
		if (HX_FIELD_EQ(inName,"getFloat32") ) { return getFloat32_dyn(); }
		if (HX_FIELD_EQ(inName,"byteLength") ) { return byteLength; }
		if (HX_FIELD_EQ(inName,"byteOffset") ) { return byteOffset; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getByteBuffer") ) { return getByteBuffer_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"invalidDataIndex") ) { return invalidDataIndex; }
		if (HX_FIELD_EQ(inName,"getNativePointer") ) { return getNativePointer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ArrayBufferView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"bytes") ) { bytes=inValue.Cast< Array< unsigned char > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"buffer") ) { buffer=inValue.Cast< ::flash::utils::ByteArray >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"byteLength") ) { byteLength=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"byteOffset") ) { byteOffset=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"invalidDataIndex") ) { invalidDataIndex=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ArrayBufferView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bytes"));
	outFields->push(HX_CSTRING("byteLength"));
	outFields->push(HX_CSTRING("byteOffset"));
	outFields->push(HX_CSTRING("buffer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("invalidDataIndex"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setUInt8"),
	HX_CSTRING("setInt32"),
	HX_CSTRING("setInt16"),
	HX_CSTRING("setFloat32"),
	HX_CSTRING("getUInt8"),
	HX_CSTRING("getStart"),
	HX_CSTRING("getNativePointer"),
	HX_CSTRING("getLength"),
	HX_CSTRING("getInt32"),
	HX_CSTRING("getInt16"),
	HX_CSTRING("getFloat32"),
	HX_CSTRING("getByteBuffer"),
	HX_CSTRING("bytes"),
	HX_CSTRING("byteLength"),
	HX_CSTRING("byteOffset"),
	HX_CSTRING("buffer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ArrayBufferView_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ArrayBufferView_obj::invalidDataIndex,"invalidDataIndex");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ArrayBufferView_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ArrayBufferView_obj::invalidDataIndex,"invalidDataIndex");
};

Class ArrayBufferView_obj::__mClass;

void ArrayBufferView_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.utils.ArrayBufferView"), hx::TCanCast< ArrayBufferView_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ArrayBufferView_obj::__boot()
{
	invalidDataIndex= HX_CSTRING("Invalid data index");
}

} // end namespace openfl
} // end namespace utils
