#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_text_Font
#include <flash/text/Font.h>
#endif
#ifndef INCLUDED_flash_text_FontStyle
#include <flash/text/FontStyle.h>
#endif
#ifndef INCLUDED_flash_text_FontType
#include <flash/text/FontType.h>
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
#ifndef INCLUDED_haxe_Resource
#include <haxe/Resource.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
namespace flash{
namespace text{

Void Font_obj::__construct(::String __o_filename,::flash::text::FontStyle style,::flash::text::FontType type)
{
HX_STACK_PUSH("Font::new","flash/text/Font.hx",22);
::String filename = __o_filename.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(22)
	if (((filename == HX_CSTRING("")))){
		HX_STACK_LINE(26)
		::Class fontClass = ::Type_obj::getClass(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(fontClass,"fontClass");
		HX_STACK_LINE(28)
		if ((::Reflect_obj::hasField(fontClass,HX_CSTRING("resourceName")))){
			HX_STACK_LINE(30)
			::flash::utils::ByteArray bytes = ::flash::utils::ByteArray_obj::fromBytes(::haxe::Resource_obj::getBytes(::Reflect_obj::field(fontClass,HX_CSTRING("resourceName"))));		HX_STACK_VAR(bytes,"bytes");
			HX_STACK_LINE(31)
			Dynamic details = ::flash::text::Font_obj::loadBytes(bytes);		HX_STACK_VAR(details,"details");
			HX_STACK_LINE(32)
			this->fontName = details->__Field(HX_CSTRING("family_name"),true);
			HX_STACK_LINE(34)
			if (((bool(details->__Field(HX_CSTRING("is_bold"),true)) && bool(details->__Field(HX_CSTRING("is_italic"),true))))){
				HX_STACK_LINE(34)
				this->fontStyle = ::flash::text::FontStyle_obj::BOLD_ITALIC;
			}
			else{
				HX_STACK_LINE(38)
				if ((details->__Field(HX_CSTRING("is_bold"),true))){
					HX_STACK_LINE(38)
					this->fontStyle = ::flash::text::FontStyle_obj::BOLD;
				}
				else{
					HX_STACK_LINE(42)
					if ((details->__Field(HX_CSTRING("is_italic"),true))){
						HX_STACK_LINE(42)
						this->fontStyle = ::flash::text::FontStyle_obj::ITALIC;
					}
					else{
						HX_STACK_LINE(46)
						this->fontStyle = ::flash::text::FontStyle_obj::REGULAR;
					}
				}
			}
			HX_STACK_LINE(52)
			this->fontType = ::flash::text::FontType_obj::EMBEDDED;
		}
		else{
			HX_STACK_LINE(56)
			::String className = ::Type_obj::getClassName(::Type_obj::getClass(hx::ObjectPtr<OBJ_>(this)));		HX_STACK_VAR(className,"className");
			HX_STACK_LINE(57)
			this->fontName = className.split(HX_CSTRING("."))->pop();
			HX_STACK_LINE(58)
			this->fontStyle = ::flash::text::FontStyle_obj::REGULAR;
			HX_STACK_LINE(59)
			this->fontType = ::flash::text::FontType_obj::EMBEDDED;
		}
	}
	else{
		HX_STACK_LINE(65)
		this->fontName = filename;
		HX_STACK_LINE(66)
		this->fontStyle = (  (((style == null()))) ? ::flash::text::FontStyle(::flash::text::FontStyle_obj::REGULAR) : ::flash::text::FontStyle(style) );
		HX_STACK_LINE(67)
		this->fontType = (  (((type == null()))) ? ::flash::text::FontType(::flash::text::FontType_obj::EMBEDDED) : ::flash::text::FontType(type) );
	}
}
;
	return null();
}

Font_obj::~Font_obj() { }

Dynamic Font_obj::__CreateEmpty() { return  new Font_obj; }
hx::ObjectPtr< Font_obj > Font_obj::__new(::String __o_filename,::flash::text::FontStyle style,::flash::text::FontType type)
{  hx::ObjectPtr< Font_obj > result = new Font_obj();
	result->__construct(__o_filename,style,type);
	return result;}

Dynamic Font_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Font_obj > result = new Font_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::String Font_obj::toString( ){
	HX_STACK_PUSH("Font::toString","flash/text/Font.hx",132);
	HX_STACK_THIS(this);
	HX_STACK_LINE(132)
	return ((((((HX_CSTRING("{ name=") + this->fontName) + HX_CSTRING(", style=")) + ::Std_obj::string(this->fontStyle)) + HX_CSTRING(", type=")) + ::Std_obj::string(this->fontType)) + HX_CSTRING(" }"));
}


HX_DEFINE_DYNAMIC_FUNC0(Font_obj,toString,return )

Array< ::Dynamic > Font_obj::__registeredFonts;

Array< ::Dynamic > Font_obj::__deviceFonts;

Array< ::Dynamic > Font_obj::enumerateFonts( hx::Null< bool >  __o_enumerateDeviceFonts){
bool enumerateDeviceFonts = __o_enumerateDeviceFonts.Default(false);
	HX_STACK_PUSH("Font::enumerateFonts","flash/text/Font.hx",74);
	HX_STACK_ARG(enumerateDeviceFonts,"enumerateDeviceFonts");
{
		HX_STACK_LINE(76)
		Array< ::Dynamic > result = ::flash::text::Font_obj::__registeredFonts->copy();		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(78)
		if ((enumerateDeviceFonts)){
			HX_STACK_LINE(80)
			if (((::flash::text::Font_obj::__deviceFonts == null()))){
				HX_STACK_LINE(82)
				::flash::text::Font_obj::__deviceFonts = Array_obj< ::Dynamic >::__new();
				HX_STACK_LINE(83)
				Array< ::Dynamic > styles = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::Dynamic >::__new().Add(::flash::text::FontStyle_obj::BOLD).Add(::flash::text::FontStyle_obj::BOLD_ITALIC).Add(::flash::text::FontStyle_obj::ITALIC).Add(::flash::text::FontStyle_obj::REGULAR));		HX_STACK_VAR(styles,"styles");

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Array< ::Dynamic >,styles)
				Void run(::String name,int style){
					HX_STACK_PUSH("*::_Function_3_1","flash/text/Font.hx",84);
					HX_STACK_ARG(name,"name");
					HX_STACK_ARG(style,"style");
					{
						HX_STACK_LINE(84)
						::flash::text::Font_obj::__deviceFonts->push(::flash::text::Font_obj::__new(name,styles->__get((int)0).StaticCast< Array< ::Dynamic > >()->__get(style).StaticCast< ::flash::text::FontStyle >(),::flash::text::FontType_obj::DEVICE));
					}
					return null();
				}
				HX_END_LOCAL_FUNC2((void))

				HX_STACK_LINE(84)
				::flash::text::Font_obj::lime_font_iterate_device_fonts( Dynamic(new _Function_3_1(styles)));
			}
			HX_STACK_LINE(88)
			result = result->concat(::flash::text::Font_obj::__deviceFonts);
		}
		HX_STACK_LINE(92)
		return result;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Font_obj,enumerateFonts,return )

Dynamic Font_obj::load( ::String filename){
	HX_STACK_PUSH("Font::load","flash/text/Font.hx",97);
	HX_STACK_ARG(filename,"filename");
	HX_STACK_LINE(99)
	Dynamic result = ::flash::text::Font_obj::freetype_import_font(filename,null(),(int)20480,null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(100)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Font_obj,load,return )

Dynamic Font_obj::loadBytes( ::flash::utils::ByteArray bytes){
	HX_STACK_PUSH("Font::loadBytes","flash/text/Font.hx",105);
	HX_STACK_ARG(bytes,"bytes");
	HX_STACK_LINE(107)
	Dynamic result = ::flash::text::Font_obj::freetype_import_font(HX_CSTRING(""),null(),(int)20480,bytes);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(108)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Font_obj,loadBytes,return )

Void Font_obj::registerFont( ::Class font){
{
		HX_STACK_PUSH("Font::registerFont","flash/text/Font.hx",113);
		HX_STACK_ARG(font,"font");
		HX_STACK_LINE(115)
		::flash::text::Font instance = ::Type_obj::createInstance(font,Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("")).Add(null()).Add(null())));		HX_STACK_VAR(instance,"instance");
		HX_STACK_LINE(117)
		if (((instance != null()))){
			HX_STACK_LINE(119)
			if ((::Reflect_obj::hasField(font,HX_CSTRING("resourceName")))){
				HX_STACK_LINE(119)
				::flash::text::Font_obj::lime_font_register_font(instance->fontName,::flash::utils::ByteArray_obj::fromBytes(::haxe::Resource_obj::getBytes(::Reflect_obj::field(font,HX_CSTRING("resourceName")))));
			}
			HX_STACK_LINE(125)
			::flash::text::Font_obj::__registeredFonts->push(instance);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Font_obj,registerFont,(void))

Dynamic Font_obj::freetype_import_font;

Dynamic Font_obj::lime_font_register_font;

Dynamic Font_obj::lime_font_iterate_device_fonts;


Font_obj::Font_obj()
{
}

void Font_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Font);
	HX_MARK_MEMBER_NAME(fontType,"fontType");
	HX_MARK_MEMBER_NAME(fontStyle,"fontStyle");
	HX_MARK_MEMBER_NAME(fontName,"fontName");
	HX_MARK_END_CLASS();
}

void Font_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(fontType,"fontType");
	HX_VISIT_MEMBER_NAME(fontStyle,"fontStyle");
	HX_VISIT_MEMBER_NAME(fontName,"fontName");
}

Dynamic Font_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"fontType") ) { return fontType; }
		if (HX_FIELD_EQ(inName,"fontName") ) { return fontName; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"loadBytes") ) { return loadBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"fontStyle") ) { return fontStyle; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"registerFont") ) { return registerFont_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"__deviceFonts") ) { return __deviceFonts; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"enumerateFonts") ) { return enumerateFonts_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"__registeredFonts") ) { return __registeredFonts; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"freetype_import_font") ) { return freetype_import_font; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_font_register_font") ) { return lime_font_register_font; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_font_iterate_device_fonts") ) { return lime_font_iterate_device_fonts; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Font_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"fontType") ) { fontType=inValue.Cast< ::flash::text::FontType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontName") ) { fontName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fontStyle") ) { fontStyle=inValue.Cast< ::flash::text::FontStyle >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"__deviceFonts") ) { __deviceFonts=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"__registeredFonts") ) { __registeredFonts=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"freetype_import_font") ) { freetype_import_font=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_font_register_font") ) { lime_font_register_font=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_font_iterate_device_fonts") ) { lime_font_iterate_device_fonts=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Font_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("fontType"));
	outFields->push(HX_CSTRING("fontStyle"));
	outFields->push(HX_CSTRING("fontName"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("__registeredFonts"),
	HX_CSTRING("__deviceFonts"),
	HX_CSTRING("enumerateFonts"),
	HX_CSTRING("load"),
	HX_CSTRING("loadBytes"),
	HX_CSTRING("registerFont"),
	HX_CSTRING("freetype_import_font"),
	HX_CSTRING("lime_font_register_font"),
	HX_CSTRING("lime_font_iterate_device_fonts"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("fontType"),
	HX_CSTRING("fontStyle"),
	HX_CSTRING("fontName"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Font_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Font_obj::__registeredFonts,"__registeredFonts");
	HX_MARK_MEMBER_NAME(Font_obj::__deviceFonts,"__deviceFonts");
	HX_MARK_MEMBER_NAME(Font_obj::freetype_import_font,"freetype_import_font");
	HX_MARK_MEMBER_NAME(Font_obj::lime_font_register_font,"lime_font_register_font");
	HX_MARK_MEMBER_NAME(Font_obj::lime_font_iterate_device_fonts,"lime_font_iterate_device_fonts");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Font_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Font_obj::__registeredFonts,"__registeredFonts");
	HX_VISIT_MEMBER_NAME(Font_obj::__deviceFonts,"__deviceFonts");
	HX_VISIT_MEMBER_NAME(Font_obj::freetype_import_font,"freetype_import_font");
	HX_VISIT_MEMBER_NAME(Font_obj::lime_font_register_font,"lime_font_register_font");
	HX_VISIT_MEMBER_NAME(Font_obj::lime_font_iterate_device_fonts,"lime_font_iterate_device_fonts");
};

Class Font_obj::__mClass;

void Font_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.text.Font"), hx::TCanCast< Font_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Font_obj::__boot()
{
	__registeredFonts= Array_obj< ::Dynamic >::__new();
	freetype_import_font= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("freetype_import_font"),(int)4);
	lime_font_register_font= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_font_register_font"),(int)2);
	lime_font_iterate_device_fonts= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_font_iterate_device_fonts"),(int)1);
}

} // end namespace flash
} // end namespace text
