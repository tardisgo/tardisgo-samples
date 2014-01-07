#include <hxcpp.h>

#ifndef INCLUDED_flash_display_Bitmap
#include <flash/display/Bitmap.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_Graphics
#include <flash/display/Graphics.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_PixelSnapping
#include <flash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_geom_Matrix
#include <flash/geom/Matrix.h>
#endif
namespace flash{
namespace display{

Void Bitmap_obj::__construct(::flash::display::BitmapData bitmapData,::flash::display::PixelSnapping pixelSnapping,hx::Null< bool >  __o_smoothing)
{
HX_STACK_PUSH("Bitmap::new","flash/display/Bitmap.hx",15);
bool smoothing = __o_smoothing.Default(false);
{
	HX_STACK_LINE(17)
	super::__construct(::flash::display::DisplayObject_obj::lime_create_display_object(),HX_CSTRING("Bitmap"));
	HX_STACK_LINE(19)
	this->set_pixelSnapping((  (((pixelSnapping == null()))) ? ::flash::display::PixelSnapping(::flash::display::PixelSnapping_obj::AUTO) : ::flash::display::PixelSnapping(pixelSnapping) ));
	HX_STACK_LINE(20)
	this->set_smoothing(smoothing);
	HX_STACK_LINE(22)
	if (((bitmapData != null()))){
		HX_STACK_LINE(22)
		this->set_bitmapData(bitmapData);
	}
	else{
		HX_STACK_LINE(26)
		if (((this->bitmapData != null()))){
			HX_STACK_LINE(26)
			this->__rebuild();
		}
	}
}
;
	return null();
}

Bitmap_obj::~Bitmap_obj() { }

Dynamic Bitmap_obj::__CreateEmpty() { return  new Bitmap_obj; }
hx::ObjectPtr< Bitmap_obj > Bitmap_obj::__new(::flash::display::BitmapData bitmapData,::flash::display::PixelSnapping pixelSnapping,hx::Null< bool >  __o_smoothing)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(bitmapData,pixelSnapping,__o_smoothing);
	return result;}

Dynamic Bitmap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

bool Bitmap_obj::set_smoothing( bool value){
	HX_STACK_PUSH("Bitmap::set_smoothing","flash/display/Bitmap.hx",72);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(74)
	this->smoothing = value;
	HX_STACK_LINE(75)
	this->__rebuild();
	HX_STACK_LINE(77)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Bitmap_obj,set_smoothing,return )

::flash::display::BitmapData Bitmap_obj::set_bitmapData( ::flash::display::BitmapData value){
	HX_STACK_PUSH("Bitmap::set_bitmapData","flash/display/Bitmap.hx",62);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(64)
	this->bitmapData = value;
	HX_STACK_LINE(65)
	this->__rebuild();
	HX_STACK_LINE(67)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Bitmap_obj,set_bitmapData,return )

Void Bitmap_obj::__rebuild( ){
{
		HX_STACK_PUSH("Bitmap::__rebuild","flash/display/Bitmap.hx",35);
		HX_STACK_THIS(this);
		HX_STACK_LINE(35)
		if (((this->__handle != null()))){
			HX_STACK_LINE(39)
			::flash::display::Graphics gfx = this->get_graphics();		HX_STACK_VAR(gfx,"gfx");
			HX_STACK_LINE(40)
			gfx->clear();
			HX_STACK_LINE(42)
			if (((this->bitmapData != null()))){
				HX_STACK_LINE(44)
				gfx->beginBitmapFill(this->bitmapData,null(),false,this->smoothing);
				HX_STACK_LINE(45)
				gfx->drawRect((int)0,(int)0,this->bitmapData->get_width(),this->bitmapData->get_height());
				HX_STACK_LINE(46)
				gfx->endFill();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bitmap_obj,__rebuild,(void))


Bitmap_obj::Bitmap_obj()
{
}

void Bitmap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bitmap);
	HX_MARK_MEMBER_NAME(smoothing,"smoothing");
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Bitmap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(smoothing,"smoothing");
	HX_VISIT_MEMBER_NAME(bitmapData,"bitmapData");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Bitmap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"__rebuild") ) { return __rebuild_dyn(); }
		if (HX_FIELD_EQ(inName,"smoothing") ) { return smoothing; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_smoothing") ) { return set_smoothing_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"set_bitmapData") ) { return set_bitmapData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bitmap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"smoothing") ) { if (inCallProp) return set_smoothing(inValue);smoothing=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { if (inCallProp) return set_bitmapData(inValue);bitmapData=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bitmap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("smoothing"));
	outFields->push(HX_CSTRING("bitmapData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_smoothing"),
	HX_CSTRING("set_bitmapData"),
	HX_CSTRING("__rebuild"),
	HX_CSTRING("smoothing"),
	HX_CSTRING("bitmapData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bitmap_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bitmap_obj::__mClass,"__mClass");
};

Class Bitmap_obj::__mClass;

void Bitmap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.display.Bitmap"), hx::TCanCast< Bitmap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Bitmap_obj::__boot()
{
}

} // end namespace flash
} // end namespace display
