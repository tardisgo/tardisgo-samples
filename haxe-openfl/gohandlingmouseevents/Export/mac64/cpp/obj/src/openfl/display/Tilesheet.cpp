#include <hxcpp.h>

#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_Graphics
#include <flash/display/Graphics.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_openfl_display_Tilesheet
#include <openfl/display/Tilesheet.h>
#endif
namespace openfl{
namespace display{

Void Tilesheet_obj::__construct(::flash::display::BitmapData image)
{
HX_STACK_PUSH("Tilesheet::new","openfl/display/Tilesheet.hx",36);
{
	HX_STACK_LINE(38)
	this->__bitmap = image;
	HX_STACK_LINE(39)
	this->__handle = ::openfl::display::Tilesheet_obj::lime_tilesheet_create(image->__handle);
	HX_STACK_LINE(41)
	this->_bitmapWidth = this->__bitmap->get_width();
	HX_STACK_LINE(42)
	this->_bitmapHeight = this->__bitmap->get_height();
	HX_STACK_LINE(44)
	this->_tilePoints = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(45)
	this->_tiles = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(46)
	this->_tileUVs = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

Tilesheet_obj::~Tilesheet_obj() { }

Dynamic Tilesheet_obj::__CreateEmpty() { return  new Tilesheet_obj; }
hx::ObjectPtr< Tilesheet_obj > Tilesheet_obj::__new(::flash::display::BitmapData image)
{  hx::ObjectPtr< Tilesheet_obj > result = new Tilesheet_obj();
	result->__construct(image);
	return result;}

Dynamic Tilesheet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Tilesheet_obj > result = new Tilesheet_obj();
	result->__construct(inArgs[0]);
	return result;}

::flash::geom::Rectangle Tilesheet_obj::getTileUVs( int index){
	HX_STACK_PUSH("Tilesheet::getTileUVs","openfl/display/Tilesheet.hx",77);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(77)
	return this->_tileUVs->__get(index).StaticCast< ::flash::geom::Rectangle >();
}


HX_DEFINE_DYNAMIC_FUNC1(Tilesheet_obj,getTileUVs,return )

::flash::geom::Rectangle Tilesheet_obj::getTileRect( int index){
	HX_STACK_PUSH("Tilesheet::getTileRect","openfl/display/Tilesheet.hx",73);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(73)
	return this->_tiles->__get(index).StaticCast< ::flash::geom::Rectangle >();
}


HX_DEFINE_DYNAMIC_FUNC1(Tilesheet_obj,getTileRect,return )

::flash::geom::Point Tilesheet_obj::getTileCenter( int index){
	HX_STACK_PUSH("Tilesheet::getTileCenter","openfl/display/Tilesheet.hx",69);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(69)
	return this->_tilePoints->__get(index).StaticCast< ::flash::geom::Point >();
}


HX_DEFINE_DYNAMIC_FUNC1(Tilesheet_obj,getTileCenter,return )

Void Tilesheet_obj::drawTiles( ::flash::display::Graphics graphics,Array< Float > tileData,hx::Null< bool >  __o_smooth,hx::Null< int >  __o_flags){
bool smooth = __o_smooth.Default(false);
int flags = __o_flags.Default(0);
	HX_STACK_PUSH("Tilesheet::drawTiles","openfl/display/Tilesheet.hx",62);
	HX_STACK_THIS(this);
	HX_STACK_ARG(graphics,"graphics");
	HX_STACK_ARG(tileData,"tileData");
	HX_STACK_ARG(smooth,"smooth");
	HX_STACK_ARG(flags,"flags");
{
		HX_STACK_LINE(62)
		graphics->drawTiles(hx::ObjectPtr<OBJ_>(this),tileData,smooth,flags);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Tilesheet_obj,drawTiles,(void))

int Tilesheet_obj::addTileRect( ::flash::geom::Rectangle rectangle,::flash::geom::Point centerPoint){
	HX_STACK_PUSH("Tilesheet::addTileRect","openfl/display/Tilesheet.hx",51);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rectangle,"rectangle");
	HX_STACK_ARG(centerPoint,"centerPoint");
	HX_STACK_LINE(53)
	this->_tiles->push(rectangle);
	HX_STACK_LINE(54)
	if (((centerPoint == null()))){
		HX_STACK_LINE(54)
		this->_tilePoints->push(::openfl::display::Tilesheet_obj::defaultRatio);
	}
	else{
		HX_STACK_LINE(55)
		this->_tilePoints->push(::flash::geom::Point_obj::__new((Float(centerPoint->x) / Float(rectangle->width)),(Float(centerPoint->y) / Float(rectangle->height))));
	}
	HX_STACK_LINE(56)
	this->_tileUVs->push(::flash::geom::Rectangle_obj::__new((Float(rectangle->get_left()) / Float(this->_bitmapWidth)),(Float(rectangle->get_top()) / Float(this->_bitmapHeight)),(Float(rectangle->get_right()) / Float(this->_bitmapWidth)),(Float(rectangle->get_bottom()) / Float(this->_bitmapHeight))));
	HX_STACK_LINE(57)
	return ::openfl::display::Tilesheet_obj::lime_tilesheet_add_rect(this->__handle,rectangle,centerPoint);
}


HX_DEFINE_DYNAMIC_FUNC2(Tilesheet_obj,addTileRect,return )

int Tilesheet_obj::TILE_SCALE;

int Tilesheet_obj::TILE_ROTATION;

int Tilesheet_obj::TILE_RGB;

int Tilesheet_obj::TILE_ALPHA;

int Tilesheet_obj::TILE_TRANS_2x2;

int Tilesheet_obj::TILE_BLEND_NORMAL;

int Tilesheet_obj::TILE_BLEND_ADD;

int Tilesheet_obj::TILE_BLEND_MULTIPLY;

int Tilesheet_obj::TILE_BLEND_SCREEN;

::flash::geom::Point Tilesheet_obj::defaultRatio;

Dynamic Tilesheet_obj::lime_tilesheet_create;

Dynamic Tilesheet_obj::lime_tilesheet_add_rect;


Tilesheet_obj::Tilesheet_obj()
{
}

void Tilesheet_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Tilesheet);
	HX_MARK_MEMBER_NAME(_tileUVs,"_tileUVs");
	HX_MARK_MEMBER_NAME(_tiles,"_tiles");
	HX_MARK_MEMBER_NAME(_tilePoints,"_tilePoints");
	HX_MARK_MEMBER_NAME(_bitmapWidth,"_bitmapWidth");
	HX_MARK_MEMBER_NAME(_bitmapHeight,"_bitmapHeight");
	HX_MARK_MEMBER_NAME(__handle,"__handle");
	HX_MARK_MEMBER_NAME(__bitmap,"__bitmap");
	HX_MARK_END_CLASS();
}

void Tilesheet_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_tileUVs,"_tileUVs");
	HX_VISIT_MEMBER_NAME(_tiles,"_tiles");
	HX_VISIT_MEMBER_NAME(_tilePoints,"_tilePoints");
	HX_VISIT_MEMBER_NAME(_bitmapWidth,"_bitmapWidth");
	HX_VISIT_MEMBER_NAME(_bitmapHeight,"_bitmapHeight");
	HX_VISIT_MEMBER_NAME(__handle,"__handle");
	HX_VISIT_MEMBER_NAME(__bitmap,"__bitmap");
}

Dynamic Tilesheet_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_tiles") ) { return _tiles; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_tileUVs") ) { return _tileUVs; }
		if (HX_FIELD_EQ(inName,"__handle") ) { return __handle; }
		if (HX_FIELD_EQ(inName,"__bitmap") ) { return __bitmap; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawTiles") ) { return drawTiles_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getTileUVs") ) { return getTileUVs_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getTileRect") ) { return getTileRect_dyn(); }
		if (HX_FIELD_EQ(inName,"addTileRect") ) { return addTileRect_dyn(); }
		if (HX_FIELD_EQ(inName,"_tilePoints") ) { return _tilePoints; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"defaultRatio") ) { return defaultRatio; }
		if (HX_FIELD_EQ(inName,"_bitmapWidth") ) { return _bitmapWidth; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getTileCenter") ) { return getTileCenter_dyn(); }
		if (HX_FIELD_EQ(inName,"_bitmapHeight") ) { return _bitmapHeight; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"lime_tilesheet_create") ) { return lime_tilesheet_create; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_tilesheet_add_rect") ) { return lime_tilesheet_add_rect; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Tilesheet_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_tiles") ) { _tiles=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_tileUVs") ) { _tileUVs=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__handle") ) { __handle=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__bitmap") ) { __bitmap=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_tilePoints") ) { _tilePoints=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"defaultRatio") ) { defaultRatio=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_bitmapWidth") ) { _bitmapWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_bitmapHeight") ) { _bitmapHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"lime_tilesheet_create") ) { lime_tilesheet_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_tilesheet_add_rect") ) { lime_tilesheet_add_rect=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Tilesheet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_tileUVs"));
	outFields->push(HX_CSTRING("_tiles"));
	outFields->push(HX_CSTRING("_tilePoints"));
	outFields->push(HX_CSTRING("_bitmapWidth"));
	outFields->push(HX_CSTRING("_bitmapHeight"));
	outFields->push(HX_CSTRING("__handle"));
	outFields->push(HX_CSTRING("__bitmap"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TILE_SCALE"),
	HX_CSTRING("TILE_ROTATION"),
	HX_CSTRING("TILE_RGB"),
	HX_CSTRING("TILE_ALPHA"),
	HX_CSTRING("TILE_TRANS_2x2"),
	HX_CSTRING("TILE_BLEND_NORMAL"),
	HX_CSTRING("TILE_BLEND_ADD"),
	HX_CSTRING("TILE_BLEND_MULTIPLY"),
	HX_CSTRING("TILE_BLEND_SCREEN"),
	HX_CSTRING("defaultRatio"),
	HX_CSTRING("lime_tilesheet_create"),
	HX_CSTRING("lime_tilesheet_add_rect"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getTileUVs"),
	HX_CSTRING("getTileRect"),
	HX_CSTRING("getTileCenter"),
	HX_CSTRING("drawTiles"),
	HX_CSTRING("addTileRect"),
	HX_CSTRING("_tileUVs"),
	HX_CSTRING("_tiles"),
	HX_CSTRING("_tilePoints"),
	HX_CSTRING("_bitmapWidth"),
	HX_CSTRING("_bitmapHeight"),
	HX_CSTRING("__handle"),
	HX_CSTRING("__bitmap"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Tilesheet_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_SCALE,"TILE_SCALE");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_ROTATION,"TILE_ROTATION");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_RGB,"TILE_RGB");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_ALPHA,"TILE_ALPHA");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_TRANS_2x2,"TILE_TRANS_2x2");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_BLEND_NORMAL,"TILE_BLEND_NORMAL");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_BLEND_ADD,"TILE_BLEND_ADD");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_BLEND_MULTIPLY,"TILE_BLEND_MULTIPLY");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_BLEND_SCREEN,"TILE_BLEND_SCREEN");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::defaultRatio,"defaultRatio");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::lime_tilesheet_create,"lime_tilesheet_create");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::lime_tilesheet_add_rect,"lime_tilesheet_add_rect");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::TILE_SCALE,"TILE_SCALE");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::TILE_ROTATION,"TILE_ROTATION");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::TILE_RGB,"TILE_RGB");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::TILE_ALPHA,"TILE_ALPHA");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::TILE_TRANS_2x2,"TILE_TRANS_2x2");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::TILE_BLEND_NORMAL,"TILE_BLEND_NORMAL");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::TILE_BLEND_ADD,"TILE_BLEND_ADD");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::TILE_BLEND_MULTIPLY,"TILE_BLEND_MULTIPLY");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::TILE_BLEND_SCREEN,"TILE_BLEND_SCREEN");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::defaultRatio,"defaultRatio");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::lime_tilesheet_create,"lime_tilesheet_create");
	HX_VISIT_MEMBER_NAME(Tilesheet_obj::lime_tilesheet_add_rect,"lime_tilesheet_add_rect");
};

Class Tilesheet_obj::__mClass;

void Tilesheet_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.display.Tilesheet"), hx::TCanCast< Tilesheet_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Tilesheet_obj::__boot()
{
	TILE_SCALE= (int)1;
	TILE_ROTATION= (int)2;
	TILE_RGB= (int)4;
	TILE_ALPHA= (int)8;
	TILE_TRANS_2x2= (int)16;
	TILE_BLEND_NORMAL= (int)0;
	TILE_BLEND_ADD= (int)65536;
	TILE_BLEND_MULTIPLY= (int)131072;
	TILE_BLEND_SCREEN= (int)262144;
	defaultRatio= ::flash::geom::Point_obj::__new((int)0,(int)0);
	lime_tilesheet_create= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_tilesheet_create"),(int)1);
	lime_tilesheet_add_rect= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_tilesheet_add_rect"),(int)3);
}

} // end namespace openfl
} // end namespace display
