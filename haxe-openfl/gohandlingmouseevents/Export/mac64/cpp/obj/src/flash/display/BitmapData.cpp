#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_Memory
#include <flash/Memory.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_BlendMode
#include <flash/display/BlendMode.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_OptimizedPerlin
#include <flash/display/OptimizedPerlin.h>
#endif
#ifndef INCLUDED_flash_filters_BitmapFilter
#include <flash/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_flash_geom_ColorTransform
#include <flash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_flash_geom_Matrix
#include <flash/geom/Matrix.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
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
namespace display{

Void BitmapData_obj::__construct(int width,int height,hx::Null< bool >  __o_transparent,hx::Null< int >  __o_fillColor,Dynamic gpuMode)
{
HX_STACK_PUSH("BitmapData::new","flash/display/BitmapData.hx",41);
bool transparent = __o_transparent.Default(true);
int fillColor = __o_fillColor.Default(-1);
{
	HX_STACK_LINE(43)
	this->__transparent = transparent;
	HX_STACK_LINE(45)
	if (((bool((width < (int)1)) || bool((height < (int)1))))){
		HX_STACK_LINE(45)
		this->__handle = null();
	}
	else{
		HX_STACK_LINE(51)
		int flags = (int)2;		HX_STACK_VAR(flags,"flags");
		HX_STACK_LINE(52)
		if ((transparent)){
			HX_STACK_LINE(52)
			hx::OrEq(flags,(int)1);
		}
		HX_STACK_LINE(53)
		int alpha = hx::UShr(fillColor,(int)24);		HX_STACK_VAR(alpha,"alpha");
		HX_STACK_LINE(55)
		if (((bool(transparent) && bool((alpha == (int)0))))){
			HX_STACK_LINE(55)
			fillColor = (int)0;
		}
		HX_STACK_LINE(61)
		this->__handle = ::flash::display::BitmapData_obj::lime_bitmap_data_create(width,height,flags,(int(fillColor) & int((int)16777215)),alpha,gpuMode);
	}
}
;
	return null();
}

BitmapData_obj::~BitmapData_obj() { }

Dynamic BitmapData_obj::__CreateEmpty() { return  new BitmapData_obj; }
hx::ObjectPtr< BitmapData_obj > BitmapData_obj::__new(int width,int height,hx::Null< bool >  __o_transparent,hx::Null< int >  __o_fillColor,Dynamic gpuMode)
{  hx::ObjectPtr< BitmapData_obj > result = new BitmapData_obj();
	result->__construct(width,height,__o_transparent,__o_fillColor,gpuMode);
	return result;}

Dynamic BitmapData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapData_obj > result = new BitmapData_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

hx::Object *BitmapData_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::flash::display::IBitmapDrawable_obj)) return operator ::flash::display::IBitmapDrawable_obj *();
	return super::__ToInterface(inType);
}

bool BitmapData_obj::get_transparent( ){
	HX_STACK_PUSH("BitmapData::get_transparent","flash/display/BitmapData.hx",717);
	HX_STACK_THIS(this);
	HX_STACK_LINE(717)
	return this->__transparent;
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,get_transparent,return )

int BitmapData_obj::get_height( ){
	HX_STACK_PUSH("BitmapData::get_height","flash/display/BitmapData.hx",716);
	HX_STACK_THIS(this);
	HX_STACK_LINE(716)
	return ::flash::display::BitmapData_obj::lime_bitmap_data_height(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,get_height,return )

int BitmapData_obj::get_width( ){
	HX_STACK_PUSH("BitmapData::get_width","flash/display/BitmapData.hx",715);
	HX_STACK_THIS(this);
	HX_STACK_LINE(715)
	return ::flash::display::BitmapData_obj::lime_bitmap_data_width(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,get_width,return )

::flash::geom::Rectangle BitmapData_obj::get_rect( ){
	HX_STACK_PUSH("BitmapData::get_rect","flash/display/BitmapData.hx",714);
	HX_STACK_THIS(this);
	HX_STACK_LINE(714)
	return ::flash::geom::Rectangle_obj::__new((int)0,(int)0,this->get_width(),this->get_height());
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,get_rect,return )

Void BitmapData_obj::__loadFromBytes( ::flash::utils::ByteArray bytes,::flash::utils::ByteArray rawAlpha){
{
		HX_STACK_PUSH("BitmapData::__loadFromBytes","flash/display/BitmapData.hx",646);
		HX_STACK_THIS(this);
		HX_STACK_ARG(bytes,"bytes");
		HX_STACK_ARG(rawAlpha,"rawAlpha");
		HX_STACK_LINE(646)
		this->__handle = ::flash::display::BitmapData_obj::lime_bitmap_data_from_bytes(bytes,rawAlpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,__loadFromBytes,(void))

Void BitmapData_obj::__drawToSurface( Dynamic surface,::flash::geom::Matrix matrix,::flash::geom::ColorTransform colorTransform,::String blendMode,::flash::geom::Rectangle clipRect,bool smoothing){
{
		HX_STACK_PUSH("BitmapData::__drawToSurface","flash/display/BitmapData.hx",632);
		HX_STACK_THIS(this);
		HX_STACK_ARG(surface,"surface");
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_ARG(colorTransform,"colorTransform");
		HX_STACK_ARG(blendMode,"blendMode");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(smoothing,"smoothing");
		HX_STACK_LINE(632)
		::flash::display::BitmapData_obj::lime_render_surface_to_surface(surface,this->__handle,matrix,colorTransform,blendMode,clipRect,smoothing);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,__drawToSurface,(void))

Void BitmapData_obj::unmultiplyAlpha( ){
{
		HX_STACK_PUSH("BitmapData::unmultiplyAlpha","flash/display/BitmapData.hx",625);
		HX_STACK_THIS(this);
		HX_STACK_LINE(625)
		::flash::display::BitmapData_obj::lime_bitmap_data_unmultiply_alpha(this->__handle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,unmultiplyAlpha,(void))

Void BitmapData_obj::unlock( ::flash::geom::Rectangle changeRect){
{
		HX_STACK_PUSH("BitmapData::unlock","flash/display/BitmapData.hx",618);
		HX_STACK_THIS(this);
		HX_STACK_ARG(changeRect,"changeRect");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,unlock,(void))

int BitmapData_obj::threshold( ::flash::display::BitmapData sourceBitmapData,::flash::geom::Rectangle sourceRect,::flash::geom::Point destPoint,::String operation,int threshold,hx::Null< int >  __o_color,hx::Null< int >  __o_mask,hx::Null< bool >  __o_copySource){
int color = __o_color.Default(0);
int mask = __o_mask.Default(-1);
bool copySource = __o_copySource.Default(false);
	HX_STACK_PUSH("BitmapData::threshold","flash/display/BitmapData.hx",467);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sourceBitmapData,"sourceBitmapData");
	HX_STACK_ARG(sourceRect,"sourceRect");
	HX_STACK_ARG(destPoint,"destPoint");
	HX_STACK_ARG(operation,"operation");
	HX_STACK_ARG(threshold,"threshold");
	HX_STACK_ARG(color,"color");
	HX_STACK_ARG(mask,"mask");
	HX_STACK_ARG(copySource,"copySource");
{
		HX_STACK_LINE(467)
		if (((bool((bool((bool((sourceBitmapData == hx::ObjectPtr<OBJ_>(this))) && bool(sourceRect->equals(this->get_rect())))) && bool((destPoint->x == (int)0)))) && bool((destPoint->y == (int)0))))){
			HX_STACK_LINE(471)
			int hits = (int)0;		HX_STACK_VAR(hits,"hits");
			HX_STACK_LINE(473)
			threshold = (int((int((int((int(((int(threshold) & int((int)255)))) << int((int)24))) | int((int(((int((int(threshold) >> int((int)8))) & int((int)255)))) << int((int)16))))) | int((int(((int((int(threshold) >> int((int)16))) & int((int)255)))) << int((int)8))))) | int((int((int(threshold) >> int((int)24))) & int((int)255))));
			HX_STACK_LINE(474)
			color = (int((int((int((int(((int(color) & int((int)255)))) << int((int)24))) | int((int(((int((int(color) >> int((int)8))) & int((int)255)))) << int((int)16))))) | int((int(((int((int(color) >> int((int)16))) & int((int)255)))) << int((int)8))))) | int((int((int(color) >> int((int)24))) & int((int)255))));
			HX_STACK_LINE(476)
			::flash::utils::ByteArray memory = ::flash::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(memory,"memory");
			HX_STACK_LINE(477)
			memory->setLength(((this->get_width() * this->get_height()) * (int)4));
			HX_STACK_LINE(478)
			memory = this->getPixels(this->get_rect());
			HX_STACK_LINE(479)
			memory->position = (int)0;
			HX_STACK_LINE(480)
			::flash::Memory_obj::select(memory);
			HX_STACK_LINE(482)
			int thresholdMask = (int(threshold) & int(mask));		HX_STACK_VAR(thresholdMask,"thresholdMask");
			HX_STACK_LINE(484)
			int width_yy;		HX_STACK_VAR(width_yy,"width_yy");
			int position;		HX_STACK_VAR(position,"position");
			int pixelMask;		HX_STACK_VAR(pixelMask,"pixelMask");
			int pixelValue;		HX_STACK_VAR(pixelValue,"pixelValue");
			int i;		HX_STACK_VAR(i,"i");
			bool test;		HX_STACK_VAR(test,"test");
			HX_STACK_LINE(486)
			{
				HX_STACK_LINE(486)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				int _g = this->get_height();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(486)
				while(((_g1 < _g))){
					HX_STACK_LINE(486)
					int yy = (_g1)++;		HX_STACK_VAR(yy,"yy");
					HX_STACK_LINE(488)
					width_yy = (this->get_width() * yy);
					HX_STACK_LINE(490)
					{
						HX_STACK_LINE(490)
						int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
						int _g2 = this->get_width();		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(490)
						while(((_g3 < _g2))){
							HX_STACK_LINE(490)
							int xx = (_g3)++;		HX_STACK_VAR(xx,"xx");
							HX_STACK_LINE(492)
							position = (((width_yy + xx)) * (int)4);
							HX_STACK_LINE(493)
							pixelValue = ::flash::Memory_obj::getI32(position);
							HX_STACK_LINE(494)
							pixelMask = (int(pixelValue) & int(mask));
							HX_STACK_LINE(496)
							i = ::flash::display::BitmapData_obj::__ucompare(pixelMask,thresholdMask);
							HX_STACK_LINE(497)
							test = false;
							HX_STACK_LINE(499)
							if (((operation == HX_CSTRING("==")))){
								HX_STACK_LINE(499)
								test = (i == (int)0);
							}
							else{
								HX_STACK_LINE(500)
								if (((operation == HX_CSTRING("<")))){
									HX_STACK_LINE(500)
									test = (i == (int)-1);
								}
								else{
									HX_STACK_LINE(501)
									if (((operation == HX_CSTRING(">")))){
										HX_STACK_LINE(501)
										test = (i == (int)1);
									}
									else{
										HX_STACK_LINE(502)
										if (((operation == HX_CSTRING("!=")))){
											HX_STACK_LINE(502)
											test = (i != (int)0);
										}
										else{
											HX_STACK_LINE(503)
											if (((operation == HX_CSTRING("<=")))){
												HX_STACK_LINE(503)
												test = (bool((i == (int)0)) || bool((i == (int)-1)));
											}
											else{
												HX_STACK_LINE(504)
												if (((operation == HX_CSTRING(">=")))){
													HX_STACK_LINE(504)
													test = (bool((i == (int)0)) || bool((i == (int)1)));
												}
											}
										}
									}
								}
							}
							HX_STACK_LINE(506)
							if ((test)){
								HX_STACK_LINE(508)
								::flash::Memory_obj::setI32(position,color);
								HX_STACK_LINE(509)
								(hits)++;
							}
						}
					}
				}
			}
			HX_STACK_LINE(517)
			memory->position = (int)0;
			HX_STACK_LINE(518)
			this->setPixels(this->get_rect(),memory);
			HX_STACK_LINE(519)
			::flash::Memory_obj::select(null());
			HX_STACK_LINE(520)
			return hits;
		}
		else{
			HX_STACK_LINE(524)
			int sx = ::Std_obj::_int(sourceRect->x);		HX_STACK_VAR(sx,"sx");
			HX_STACK_LINE(525)
			int sy = ::Std_obj::_int(sourceRect->y);		HX_STACK_VAR(sy,"sy");
			HX_STACK_LINE(526)
			int sw = ::Std_obj::_int(sourceBitmapData->get_width());		HX_STACK_VAR(sw,"sw");
			HX_STACK_LINE(527)
			int sh = ::Std_obj::_int(sourceBitmapData->get_height());		HX_STACK_VAR(sh,"sh");
			HX_STACK_LINE(529)
			int dx = ::Std_obj::_int(destPoint->x);		HX_STACK_VAR(dx,"dx");
			HX_STACK_LINE(530)
			int dy = ::Std_obj::_int(destPoint->y);		HX_STACK_VAR(dy,"dy");
			HX_STACK_LINE(532)
			int bw = ((this->get_width() - sw) - dx);		HX_STACK_VAR(bw,"bw");
			HX_STACK_LINE(533)
			int bh = ((this->get_height() - sh) - dy);		HX_STACK_VAR(bh,"bh");
			HX_STACK_LINE(535)
			int dw = (  (((bw < (int)0))) ? int((sw + (((this->get_width() - sw) - dx)))) : int(sw) );		HX_STACK_VAR(dw,"dw");
			HX_STACK_LINE(536)
			int dh = (  (((bw < (int)0))) ? int((sh + (((this->get_height() - sh) - dy)))) : int(sh) );		HX_STACK_VAR(dh,"dh");
			HX_STACK_LINE(538)
			int hits = (int)0;		HX_STACK_VAR(hits,"hits");
			HX_STACK_LINE(540)
			threshold = (int((int((int((int(((int(threshold) & int((int)255)))) << int((int)24))) | int((int(((int((int(threshold) >> int((int)8))) & int((int)255)))) << int((int)16))))) | int((int(((int((int(threshold) >> int((int)16))) & int((int)255)))) << int((int)8))))) | int((int((int(threshold) >> int((int)24))) & int((int)255))));
			HX_STACK_LINE(541)
			color = (int((int((int((int(((int(color) & int((int)255)))) << int((int)24))) | int((int(((int((int(color) >> int((int)8))) & int((int)255)))) << int((int)16))))) | int((int(((int((int(color) >> int((int)16))) & int((int)255)))) << int((int)8))))) | int((int((int(color) >> int((int)24))) & int((int)255))));
			HX_STACK_LINE(543)
			int canvasMemory = ((sw * sh) * (int)4);		HX_STACK_VAR(canvasMemory,"canvasMemory");
			HX_STACK_LINE(544)
			int sourceMemory = (int)0;		HX_STACK_VAR(sourceMemory,"sourceMemory");
			HX_STACK_LINE(546)
			if ((copySource)){
				HX_STACK_LINE(546)
				sourceMemory = ((sw * sh) * (int)4);
			}
			HX_STACK_LINE(552)
			int totalMemory = (canvasMemory + sourceMemory);		HX_STACK_VAR(totalMemory,"totalMemory");
			HX_STACK_LINE(553)
			::flash::utils::ByteArray memory = ::flash::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(memory,"memory");
			HX_STACK_LINE(554)
			memory->setLength(totalMemory);
			HX_STACK_LINE(555)
			memory->position = (int)0;
			HX_STACK_LINE(556)
			::flash::display::BitmapData bitmapData = sourceBitmapData->clone();		HX_STACK_VAR(bitmapData,"bitmapData");
			HX_STACK_LINE(557)
			::flash::utils::ByteArray pixels = bitmapData->getPixels(sourceRect);		HX_STACK_VAR(pixels,"pixels");
			HX_STACK_LINE(558)
			memory->writeBytes(pixels,null(),null());
			HX_STACK_LINE(559)
			memory->position = canvasMemory;
			HX_STACK_LINE(561)
			if ((copySource)){
				HX_STACK_LINE(561)
				memory->writeBytes(pixels,null(),null());
			}
			HX_STACK_LINE(567)
			memory->position = (int)0;
			HX_STACK_LINE(568)
			::flash::Memory_obj::select(memory);
			HX_STACK_LINE(570)
			int thresholdMask = (int(threshold) & int(mask));		HX_STACK_VAR(thresholdMask,"thresholdMask");
			HX_STACK_LINE(572)
			int position;		HX_STACK_VAR(position,"position");
			int pixelMask;		HX_STACK_VAR(pixelMask,"pixelMask");
			int pixelValue;		HX_STACK_VAR(pixelValue,"pixelValue");
			int i;		HX_STACK_VAR(i,"i");
			bool test;		HX_STACK_VAR(test,"test");
			HX_STACK_LINE(574)
			{
				HX_STACK_LINE(574)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(574)
				while(((_g < dh))){
					HX_STACK_LINE(574)
					int yy = (_g)++;		HX_STACK_VAR(yy,"yy");
					HX_STACK_LINE(576)
					{
						HX_STACK_LINE(576)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(576)
						while(((_g1 < dw))){
							HX_STACK_LINE(576)
							int xx = (_g1)++;		HX_STACK_VAR(xx,"xx");
							HX_STACK_LINE(578)
							position = ((((xx + sx) + (((yy + sy)) * sw))) * (int)4);
							HX_STACK_LINE(579)
							pixelValue = ::flash::Memory_obj::getI32(position);
							HX_STACK_LINE(580)
							pixelMask = (int(pixelValue) & int(mask));
							HX_STACK_LINE(582)
							i = ::flash::display::BitmapData_obj::__ucompare(pixelMask,thresholdMask);
							HX_STACK_LINE(583)
							test = false;
							HX_STACK_LINE(585)
							if (((operation == HX_CSTRING("==")))){
								HX_STACK_LINE(585)
								test = (i == (int)0);
							}
							else{
								HX_STACK_LINE(586)
								if (((operation == HX_CSTRING("<")))){
									HX_STACK_LINE(586)
									test = (i == (int)-1);
								}
								else{
									HX_STACK_LINE(587)
									if (((operation == HX_CSTRING(">")))){
										HX_STACK_LINE(587)
										test = (i == (int)1);
									}
									else{
										HX_STACK_LINE(588)
										if (((operation == HX_CSTRING("!=")))){
											HX_STACK_LINE(588)
											test = (i != (int)0);
										}
										else{
											HX_STACK_LINE(589)
											if (((operation == HX_CSTRING("<=")))){
												HX_STACK_LINE(589)
												test = (bool((i == (int)0)) || bool((i == (int)-1)));
											}
											else{
												HX_STACK_LINE(590)
												if (((operation == HX_CSTRING(">=")))){
													HX_STACK_LINE(590)
													test = (bool((i == (int)0)) || bool((i == (int)1)));
												}
											}
										}
									}
								}
							}
							HX_STACK_LINE(592)
							if ((test)){
								HX_STACK_LINE(594)
								::flash::Memory_obj::setI32(position,color);
								HX_STACK_LINE(595)
								(hits)++;
							}
							else{
								HX_STACK_LINE(597)
								if ((copySource)){
									HX_STACK_LINE(597)
									::flash::Memory_obj::setI32(position,::flash::Memory_obj::getI32((canvasMemory + position)));
								}
							}
						}
					}
				}
			}
			HX_STACK_LINE(607)
			memory->position = (int)0;
			HX_STACK_LINE(608)
			bitmapData->setPixels(sourceRect,memory);
			HX_STACK_LINE(609)
			this->copyPixels(bitmapData,bitmapData->get_rect(),destPoint,null(),null(),null());
			HX_STACK_LINE(610)
			::flash::Memory_obj::select(null());
			HX_STACK_LINE(611)
			return hits;
		}
		HX_STACK_LINE(467)
		return (int)0;
	}
}


HX_DEFINE_DYNAMIC_FUNC8(BitmapData_obj,threshold,return )

Void BitmapData_obj::setVector( ::flash::geom::Rectangle rect,Array< int > pixels){
{
		HX_STACK_PUSH("BitmapData::setVector","flash/display/BitmapData.hx",445);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_ARG(pixels,"pixels");
		HX_STACK_LINE(447)
		int count = ::Std_obj::_int((rect->width * rect->height));		HX_STACK_VAR(count,"count");
		HX_STACK_LINE(448)
		if (((pixels->length < count))){
			HX_STACK_LINE(448)
			return null();
		}
		HX_STACK_LINE(451)
		::flash::display::BitmapData_obj::lime_bitmap_data_set_array(this->__handle,rect,pixels);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,setVector,(void))

Void BitmapData_obj::setPixels( ::flash::geom::Rectangle rect,::flash::utils::ByteArray pixels){
{
		HX_STACK_PUSH("BitmapData::setPixels","flash/display/BitmapData.hx",435);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_ARG(pixels,"pixels");
		HX_STACK_LINE(437)
		int size = ::Std_obj::_int(((rect->width * rect->height) * (int)4));		HX_STACK_VAR(size,"size");
		HX_STACK_LINE(438)
		pixels->checkData(::Std_obj::_int(size));
		HX_STACK_LINE(439)
		::flash::display::BitmapData_obj::lime_bitmap_data_set_bytes(this->__handle,rect,pixels,pixels->position);
		HX_STACK_LINE(440)
		hx::AddEq(pixels->position,size);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,setPixels,(void))

Void BitmapData_obj::setPixel32( int x,int y,int color){
{
		HX_STACK_PUSH("BitmapData::setPixel32","flash/display/BitmapData.hx",428);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(color,"color");
		HX_STACK_LINE(428)
		::flash::display::BitmapData_obj::lime_bitmap_data_set_pixel32(this->__handle,x,y,color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,setPixel32,(void))

Void BitmapData_obj::setPixel( int x,int y,int color){
{
		HX_STACK_PUSH("BitmapData::setPixel","flash/display/BitmapData.hx",421);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(color,"color");
		HX_STACK_LINE(421)
		::flash::display::BitmapData_obj::lime_bitmap_data_set_pixel(this->__handle,x,y,color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,setPixel,(void))

Void BitmapData_obj::setFormat( int format){
{
		HX_STACK_PUSH("BitmapData::setFormat","flash/display/BitmapData.hx",414);
		HX_STACK_THIS(this);
		HX_STACK_ARG(format,"format");
		HX_STACK_LINE(414)
		::flash::display::BitmapData_obj::lime_bitmap_data_set_format(this->__handle,format);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,setFormat,(void))

Void BitmapData_obj::setFlags( int flags){
{
		HX_STACK_PUSH("BitmapData::setFlags","flash/display/BitmapData.hx",406);
		HX_STACK_THIS(this);
		HX_STACK_ARG(flags,"flags");
		HX_STACK_LINE(406)
		::flash::display::BitmapData_obj::lime_bitmap_data_set_flags(this->__handle,flags);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,setFlags,(void))

Void BitmapData_obj::setAlphaMode( int alphaMode){
{
		HX_STACK_PUSH("BitmapData::setAlphaMode","flash/display/BitmapData.hx",399);
		HX_STACK_THIS(this);
		HX_STACK_ARG(alphaMode,"alphaMode");
		HX_STACK_LINE(399)
		::flash::display::BitmapData_obj::lime_bitmap_data_set_alpha_mode(this->__handle,alphaMode);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,setAlphaMode,(void))

Void BitmapData_obj::scroll( int x,int y){
{
		HX_STACK_PUSH("BitmapData::scroll","flash/display/BitmapData.hx",392);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_LINE(392)
		::flash::display::BitmapData_obj::lime_bitmap_data_scroll(this->__handle,x,y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,scroll,(void))

Void BitmapData_obj::perlinNoise( Float baseX,Float baseY,int numOctaves,int randomSeed,bool stitch,bool fractalNoise,hx::Null< int >  __o_channelOptions,hx::Null< bool >  __o_grayScale,Array< ::Dynamic > offsets){
int channelOptions = __o_channelOptions.Default(7);
bool grayScale = __o_grayScale.Default(false);
	HX_STACK_PUSH("BitmapData::perlinNoise","flash/display/BitmapData.hx",377);
	HX_STACK_THIS(this);
	HX_STACK_ARG(baseX,"baseX");
	HX_STACK_ARG(baseY,"baseY");
	HX_STACK_ARG(numOctaves,"numOctaves");
	HX_STACK_ARG(randomSeed,"randomSeed");
	HX_STACK_ARG(stitch,"stitch");
	HX_STACK_ARG(fractalNoise,"fractalNoise");
	HX_STACK_ARG(channelOptions,"channelOptions");
	HX_STACK_ARG(grayScale,"grayScale");
	HX_STACK_ARG(offsets,"offsets");
{
		HX_STACK_LINE(379)
		::flash::display::OptimizedPerlin perlin = ::flash::display::OptimizedPerlin_obj::__new(randomSeed,numOctaves,null());		HX_STACK_VAR(perlin,"perlin");
		HX_STACK_LINE(380)
		perlin->fill(hx::ObjectPtr<OBJ_>(this),baseX,baseY,(int)0,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC9(BitmapData_obj,perlinNoise,(void))

Void BitmapData_obj::paletteMap( ::flash::display::BitmapData sourceBitmapData,::flash::geom::Rectangle sourceRect,::flash::geom::Point destPoint,Array< int > redArray,Array< int > greenArray,Array< int > blueArray,Array< int > alphaArray){
{
		HX_STACK_PUSH("BitmapData::paletteMap","flash/display/BitmapData.hx",338);
		HX_STACK_THIS(this);
		HX_STACK_ARG(sourceBitmapData,"sourceBitmapData");
		HX_STACK_ARG(sourceRect,"sourceRect");
		HX_STACK_ARG(destPoint,"destPoint");
		HX_STACK_ARG(redArray,"redArray");
		HX_STACK_ARG(greenArray,"greenArray");
		HX_STACK_ARG(blueArray,"blueArray");
		HX_STACK_ARG(alphaArray,"alphaArray");
		HX_STACK_LINE(339)
		::flash::utils::ByteArray memory = ::flash::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(memory,"memory");
		HX_STACK_LINE(340)
		int sw = ::Std_obj::_int(sourceRect->width);		HX_STACK_VAR(sw,"sw");
		HX_STACK_LINE(341)
		int sh = ::Std_obj::_int(sourceRect->height);		HX_STACK_VAR(sh,"sh");
		HX_STACK_LINE(342)
		memory->setLength(((sw * sh) * (int)4));
		HX_STACK_LINE(343)
		memory = this->getPixels(sourceRect);
		HX_STACK_LINE(344)
		memory->position = (int)0;
		HX_STACK_LINE(345)
		::flash::Memory_obj::select(memory);
		HX_STACK_LINE(347)
		int width_yy;		HX_STACK_VAR(width_yy,"width_yy");
		int position;		HX_STACK_VAR(position,"position");
		int pixelMask;		HX_STACK_VAR(pixelMask,"pixelMask");
		HX_STACK_LINE(348)
		int pixelValue;		HX_STACK_VAR(pixelValue,"pixelValue");
		int r;		HX_STACK_VAR(r,"r");
		int g;		HX_STACK_VAR(g,"g");
		int b;		HX_STACK_VAR(b,"b");
		int color;		HX_STACK_VAR(color,"color");
		HX_STACK_LINE(350)
		{
			HX_STACK_LINE(350)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(350)
			while(((_g < sh))){
				HX_STACK_LINE(350)
				int yy = (_g)++;		HX_STACK_VAR(yy,"yy");
				HX_STACK_LINE(351)
				width_yy = (sw * yy);
				HX_STACK_LINE(353)
				{
					HX_STACK_LINE(353)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(353)
					while(((_g1 < sw))){
						HX_STACK_LINE(353)
						int xx = (_g1)++;		HX_STACK_VAR(xx,"xx");
						HX_STACK_LINE(354)
						position = (((width_yy + xx)) * (int)4);
						HX_STACK_LINE(355)
						pixelValue = ::flash::Memory_obj::getI32(position);
						HX_STACK_LINE(357)
						r = (int((int(pixelValue) >> int((int)8))) & int((int)255));
						HX_STACK_LINE(358)
						g = (int((int(pixelValue) >> int((int)16))) & int((int)255));
						HX_STACK_LINE(359)
						b = (int((int(pixelValue) >> int((int)24))) & int((int)255));
						struct _Function_5_1{
							inline static int Block( int &g,int &r,Array< int > &greenArray,int &b,Array< int > &redArray,Array< int > &blueArray){
								HX_STACK_PUSH("*::closure","flash/display/BitmapData.hx",361);
								{
									HX_STACK_LINE(361)
									int pixel = (int((int((int((int)-16777216) | int(redArray->__get(r)))) | int(greenArray->__get(g)))) | int(blueArray->__get(b)));		HX_STACK_VAR(pixel,"pixel");
									HX_STACK_LINE(361)
									return (int((int((int((int(((int(pixel) & int((int)255)))) << int((int)24))) | int((int(((int((int(pixel) >> int((int)8))) & int((int)255)))) << int((int)16))))) | int((int(((int((int(pixel) >> int((int)16))) & int((int)255)))) << int((int)8))))) | int((int((int(pixel) >> int((int)24))) & int((int)255))));
								}
								return null();
							}
						};
						HX_STACK_LINE(361)
						color = _Function_5_1::Block(g,r,greenArray,b,redArray,blueArray);
						HX_STACK_LINE(366)
						::flash::Memory_obj::setI32(position,color);
					}
				}
			}
		}
		HX_STACK_LINE(370)
		memory->position = (int)0;
		HX_STACK_LINE(371)
		::flash::geom::Rectangle destRect = ::flash::geom::Rectangle_obj::__new(destPoint->x,destPoint->y,sw,sh);		HX_STACK_VAR(destRect,"destRect");
		HX_STACK_LINE(372)
		this->setPixels(destRect,memory);
		HX_STACK_LINE(373)
		::flash::Memory_obj::select(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(BitmapData_obj,paletteMap,(void))

Void BitmapData_obj::noise( int randomSeed,hx::Null< int >  __o_low,hx::Null< int >  __o_high,hx::Null< int >  __o_channelOptions,hx::Null< bool >  __o_grayScale){
int low = __o_low.Default(0);
int high = __o_high.Default(255);
int channelOptions = __o_channelOptions.Default(7);
bool grayScale = __o_grayScale.Default(false);
	HX_STACK_PUSH("BitmapData::noise","flash/display/BitmapData.hx",331);
	HX_STACK_THIS(this);
	HX_STACK_ARG(randomSeed,"randomSeed");
	HX_STACK_ARG(low,"low");
	HX_STACK_ARG(high,"high");
	HX_STACK_ARG(channelOptions,"channelOptions");
	HX_STACK_ARG(grayScale,"grayScale");
{
		HX_STACK_LINE(331)
		::flash::display::BitmapData_obj::lime_bitmap_data_noise(this->__handle,randomSeed,low,high,channelOptions,grayScale);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(BitmapData_obj,noise,(void))

Void BitmapData_obj::multiplyAlpha( ){
{
		HX_STACK_PUSH("BitmapData::multiplyAlpha","flash/display/BitmapData.hx",324);
		HX_STACK_THIS(this);
		HX_STACK_LINE(324)
		::flash::display::BitmapData_obj::lime_bitmap_data_multiply_alpha(this->__handle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,multiplyAlpha,(void))

Void BitmapData_obj::lock( ){
{
		HX_STACK_PUSH("BitmapData::lock","flash/display/BitmapData.hx",317);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,lock,(void))

Array< int > BitmapData_obj::getVector( ::flash::geom::Rectangle rect){
	HX_STACK_PUSH("BitmapData::getVector","flash/display/BitmapData.hx",271);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rect,"rect");
	HX_STACK_LINE(273)
	int pixels = ::Std_obj::_int((rect->width * rect->height));		HX_STACK_VAR(pixels,"pixels");
	HX_STACK_LINE(274)
	if (((pixels < (int)1))){
		HX_STACK_LINE(274)
		return Array_obj< int >::__new();
	}
	HX_STACK_LINE(276)
	Array< int > result = Array_obj< int >::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(277)
	result[(pixels - (int)1)] = (int)0;
	HX_STACK_LINE(280)
	::flash::display::BitmapData_obj::lime_bitmap_data_get_array(this->__handle,rect,result);
	HX_STACK_LINE(287)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,getVector,return )

::flash::utils::ByteArray BitmapData_obj::getPixels( ::flash::geom::Rectangle rect){
	HX_STACK_PUSH("BitmapData::getPixels","flash/display/BitmapData.hx",236);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rect,"rect");
	HX_STACK_LINE(238)
	::flash::utils::ByteArray result = ::flash::display::BitmapData_obj::lime_bitmap_data_get_pixels(this->__handle,rect);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(239)
	if (((result != null()))){
		HX_STACK_LINE(239)
		result->position = result->length;
	}
	HX_STACK_LINE(240)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,getPixels,return )

int BitmapData_obj::getPixel32( int x,int y){
	HX_STACK_PUSH("BitmapData::getPixel32","flash/display/BitmapData.hx",229);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(229)
	return ::flash::display::BitmapData_obj::lime_bitmap_data_get_pixel32(this->__handle,x,y);
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,getPixel32,return )

int BitmapData_obj::getPixel( int x,int y){
	HX_STACK_PUSH("BitmapData::getPixel","flash/display/BitmapData.hx",222);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(222)
	return ::flash::display::BitmapData_obj::lime_bitmap_data_get_pixel(this->__handle,x,y);
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,getPixel,return )

::flash::geom::Rectangle BitmapData_obj::getColorBoundsRect( int mask,int color,hx::Null< bool >  __o_findColor){
bool findColor = __o_findColor.Default(true);
	HX_STACK_PUSH("BitmapData::getColorBoundsRect","flash/display/BitmapData.hx",213);
	HX_STACK_THIS(this);
	HX_STACK_ARG(mask,"mask");
	HX_STACK_ARG(color,"color");
	HX_STACK_ARG(findColor,"findColor");
{
		HX_STACK_LINE(215)
		::flash::geom::Rectangle result = ::flash::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(216)
		::flash::display::BitmapData_obj::lime_bitmap_data_get_color_bounds_rect(this->__handle,mask,color,findColor,result);
		HX_STACK_LINE(217)
		return result;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,getColorBoundsRect,return )

::flash::geom::Rectangle BitmapData_obj::generateFilterRect( ::flash::geom::Rectangle sourceRect,::flash::filters::BitmapFilter filter){
	HX_STACK_PUSH("BitmapData::generateFilterRect","flash/display/BitmapData.hx",204);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sourceRect,"sourceRect");
	HX_STACK_ARG(filter,"filter");
	HX_STACK_LINE(206)
	::flash::geom::Rectangle result = ::flash::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(207)
	::flash::display::BitmapData_obj::lime_bitmap_data_generate_filter_rect(sourceRect,filter,result);
	HX_STACK_LINE(208)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,generateFilterRect,return )

Void BitmapData_obj::floodFill( int x,int y,int color){
{
		HX_STACK_PUSH("BitmapData::floodFill","flash/display/BitmapData.hx",197);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(color,"color");
		HX_STACK_LINE(197)
		::flash::display::BitmapData_obj::lime_bitmap_data_flood_fill(this->__handle,x,y,color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,floodFill,(void))

Void BitmapData_obj::fillRectEx( ::flash::geom::Rectangle rect,int color,hx::Null< int >  __o_alpha){
int alpha = __o_alpha.Default(255);
	HX_STACK_PUSH("BitmapData::fillRectEx","flash/display/BitmapData.hx",190);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rect,"rect");
	HX_STACK_ARG(color,"color");
	HX_STACK_ARG(alpha,"alpha");
{
		HX_STACK_LINE(190)
		::flash::display::BitmapData_obj::lime_bitmap_data_fill(this->__handle,rect,color,alpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,fillRectEx,(void))

Void BitmapData_obj::fillRect( ::flash::geom::Rectangle rect,int color){
{
		HX_STACK_PUSH("BitmapData::fillRect","flash/display/BitmapData.hx",183);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_ARG(color,"color");
		HX_STACK_LINE(183)
		::flash::display::BitmapData_obj::lime_bitmap_data_fill(this->__handle,rect,(int(color) & int((int)16777215)),hx::UShr(color,(int)24));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,fillRect,(void))

::flash::utils::ByteArray BitmapData_obj::encode( ::String format,hx::Null< Float >  __o_quality){
Float quality = __o_quality.Default(0.9);
	HX_STACK_PUSH("BitmapData::encode","flash/display/BitmapData.hx",162);
	HX_STACK_THIS(this);
	HX_STACK_ARG(format,"format");
	HX_STACK_ARG(quality,"quality");
{
		HX_STACK_LINE(162)
		return ::flash::display::BitmapData_obj::lime_bitmap_data_encode(this->__handle,format,quality);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,encode,return )

Void BitmapData_obj::dumpBits( ){
{
		HX_STACK_PUSH("BitmapData::dumpBits","flash/display/BitmapData.hx",155);
		HX_STACK_THIS(this);
		HX_STACK_LINE(155)
		::flash::display::BitmapData_obj::lime_bitmap_data_dump_bits(this->__handle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,dumpBits,(void))

Void BitmapData_obj::draw( ::flash::display::IBitmapDrawable source,::flash::geom::Matrix matrix,::flash::geom::ColorTransform colorTransform,::flash::display::BlendMode blendMode,::flash::geom::Rectangle clipRect,hx::Null< bool >  __o_smoothing){
bool smoothing = __o_smoothing.Default(false);
	HX_STACK_PUSH("BitmapData::draw","flash/display/BitmapData.hx",148);
	HX_STACK_THIS(this);
	HX_STACK_ARG(source,"source");
	HX_STACK_ARG(matrix,"matrix");
	HX_STACK_ARG(colorTransform,"colorTransform");
	HX_STACK_ARG(blendMode,"blendMode");
	HX_STACK_ARG(clipRect,"clipRect");
	HX_STACK_ARG(smoothing,"smoothing");
{
		HX_STACK_LINE(148)
		source->__drawToSurface(this->__handle,matrix,colorTransform,::Std_obj::string(blendMode),clipRect,smoothing);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,draw,(void))

Void BitmapData_obj::dispose( ){
{
		HX_STACK_PUSH("BitmapData::dispose","flash/display/BitmapData.hx",135);
		HX_STACK_THIS(this);
		HX_STACK_LINE(137)
		if (((this->__handle != null()))){
			HX_STACK_LINE(137)
			::flash::display::BitmapData_obj::lime_bitmap_data_dispose(this->__handle);
		}
		HX_STACK_LINE(143)
		this->__handle = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,dispose,(void))

Void BitmapData_obj::destroyHardwareSurface( ){
{
		HX_STACK_PUSH("BitmapData::destroyHardwareSurface","flash/display/BitmapData.hx",127);
		HX_STACK_THIS(this);
		HX_STACK_LINE(127)
		::flash::display::BitmapData_obj::lime_bitmap_data_destroy_hardware_surface(this->__handle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,destroyHardwareSurface,(void))

Void BitmapData_obj::createHardwareSurface( ){
{
		HX_STACK_PUSH("BitmapData::createHardwareSurface","flash/display/BitmapData.hx",120);
		HX_STACK_THIS(this);
		HX_STACK_LINE(120)
		::flash::display::BitmapData_obj::lime_bitmap_data_create_hardware_surface(this->__handle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,createHardwareSurface,(void))

Void BitmapData_obj::copyPixels( ::flash::display::BitmapData sourceBitmapData,::flash::geom::Rectangle sourceRect,::flash::geom::Point destPoint,::flash::display::BitmapData alphaBitmapData,::flash::geom::Point alphaPoint,hx::Null< bool >  __o_mergeAlpha){
bool mergeAlpha = __o_mergeAlpha.Default(false);
	HX_STACK_PUSH("BitmapData::copyPixels","flash/display/BitmapData.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sourceBitmapData,"sourceBitmapData");
	HX_STACK_ARG(sourceRect,"sourceRect");
	HX_STACK_ARG(destPoint,"destPoint");
	HX_STACK_ARG(alphaBitmapData,"alphaBitmapData");
	HX_STACK_ARG(alphaPoint,"alphaPoint");
	HX_STACK_ARG(mergeAlpha,"mergeAlpha");
{
		HX_STACK_LINE(105)
		::flash::display::BitmapData_obj::lime_bitmap_data_copy(sourceBitmapData->__handle,sourceRect,this->__handle,destPoint,mergeAlpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,copyPixels,(void))

Void BitmapData_obj::copyChannel( ::flash::display::BitmapData sourceBitmapData,::flash::geom::Rectangle sourceRect,::flash::geom::Point destPoint,int sourceChannel,int destChannel){
{
		HX_STACK_PUSH("BitmapData::copyChannel","flash/display/BitmapData.hx",98);
		HX_STACK_THIS(this);
		HX_STACK_ARG(sourceBitmapData,"sourceBitmapData");
		HX_STACK_ARG(sourceRect,"sourceRect");
		HX_STACK_ARG(destPoint,"destPoint");
		HX_STACK_ARG(sourceChannel,"sourceChannel");
		HX_STACK_ARG(destChannel,"destChannel");
		HX_STACK_LINE(98)
		::flash::display::BitmapData_obj::lime_bitmap_data_copy_channel(sourceBitmapData->__handle,sourceRect,this->__handle,destPoint,sourceChannel,destChannel);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(BitmapData_obj,copyChannel,(void))

Void BitmapData_obj::colorTransform( ::flash::geom::Rectangle rect,::flash::geom::ColorTransform colorTransform){
{
		HX_STACK_PUSH("BitmapData::colorTransform","flash/display/BitmapData.hx",91);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_ARG(colorTransform,"colorTransform");
		HX_STACK_LINE(91)
		::flash::display::BitmapData_obj::lime_bitmap_data_color_transform(this->__handle,rect,colorTransform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,colorTransform,(void))

::flash::display::BitmapData BitmapData_obj::clone( ){
	HX_STACK_PUSH("BitmapData::clone","flash/display/BitmapData.hx",82);
	HX_STACK_THIS(this);
	HX_STACK_LINE(84)
	::flash::display::BitmapData bitmapData = ::flash::display::BitmapData_obj::__new((int)0,(int)0,this->get_transparent(),null(),null());		HX_STACK_VAR(bitmapData,"bitmapData");
	HX_STACK_LINE(85)
	bitmapData->__handle = ::flash::display::BitmapData_obj::lime_bitmap_data_clone(this->__handle);
	HX_STACK_LINE(86)
	return bitmapData;
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,clone,return )

Void BitmapData_obj::clear( int color){
{
		HX_STACK_PUSH("BitmapData::clear","flash/display/BitmapData.hx",75);
		HX_STACK_THIS(this);
		HX_STACK_ARG(color,"color");
		HX_STACK_LINE(75)
		::flash::display::BitmapData_obj::lime_bitmap_data_clear(this->__handle,color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,clear,(void))

Void BitmapData_obj::applyFilter( ::flash::display::BitmapData sourceBitmapData,::flash::geom::Rectangle sourceRect,::flash::geom::Point destPoint,::flash::filters::BitmapFilter filter){
{
		HX_STACK_PUSH("BitmapData::applyFilter","flash/display/BitmapData.hx",68);
		HX_STACK_THIS(this);
		HX_STACK_ARG(sourceBitmapData,"sourceBitmapData");
		HX_STACK_ARG(sourceRect,"sourceRect");
		HX_STACK_ARG(destPoint,"destPoint");
		HX_STACK_ARG(filter,"filter");
		HX_STACK_LINE(68)
		::flash::display::BitmapData_obj::lime_bitmap_data_apply_filter(this->__handle,sourceBitmapData->__handle,sourceRect,destPoint,filter);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(BitmapData_obj,applyFilter,(void))

int BitmapData_obj::CLEAR;

int BitmapData_obj::BLACK;

int BitmapData_obj::WHITE;

int BitmapData_obj::RED;

int BitmapData_obj::GREEN;

int BitmapData_obj::BLUE;

::String BitmapData_obj::PNG;

::String BitmapData_obj::JPG;

int BitmapData_obj::TRANSPARENT;

int BitmapData_obj::HARDWARE;

int BitmapData_obj::FORMAT_8888;

int BitmapData_obj::FORMAT_4444;

int BitmapData_obj::FORMAT_565;

int BitmapData_obj::createColor( int rgb,hx::Null< int >  __o_alpha){
int alpha = __o_alpha.Default(255);
	HX_STACK_PUSH("BitmapData::createColor","flash/display/BitmapData.hx",112);
	HX_STACK_ARG(rgb,"rgb");
	HX_STACK_ARG(alpha,"alpha");
{
		HX_STACK_LINE(112)
		return (int(rgb) | int((int(alpha) << int((int)24))));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,createColor,return )

int BitmapData_obj::extractAlpha( int argb){
	HX_STACK_PUSH("BitmapData::extractAlpha","flash/display/BitmapData.hx",169);
	HX_STACK_ARG(argb,"argb");
	HX_STACK_LINE(169)
	return hx::UShr(argb,(int)24);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,extractAlpha,return )

int BitmapData_obj::extractColor( int argb){
	HX_STACK_PUSH("BitmapData::extractColor","flash/display/BitmapData.hx",176);
	HX_STACK_ARG(argb,"argb");
	HX_STACK_LINE(176)
	return (int(argb) & int((int)16777215));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,extractColor,return )

::flash::utils::ByteArray BitmapData_obj::getRGBAPixels( ::flash::display::BitmapData bitmapData){
	HX_STACK_PUSH("BitmapData::getRGBAPixels","flash/display/BitmapData.hx",245);
	HX_STACK_ARG(bitmapData,"bitmapData");
	HX_STACK_LINE(247)
	::flash::utils::ByteArray data = bitmapData->getPixels(::flash::geom::Rectangle_obj::__new((int)0,(int)0,bitmapData->get_width(),bitmapData->get_height()));		HX_STACK_VAR(data,"data");
	HX_STACK_LINE(248)
	int size = (bitmapData->get_width() * bitmapData->get_height());		HX_STACK_VAR(size,"size");
	HX_STACK_LINE(250)
	int alpha;		HX_STACK_VAR(alpha,"alpha");
	int red;		HX_STACK_VAR(red,"red");
	int green;		HX_STACK_VAR(green,"green");
	int blue;		HX_STACK_VAR(blue,"blue");
	HX_STACK_LINE(252)
	{
		HX_STACK_LINE(252)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(252)
		while(((_g < size))){
			HX_STACK_LINE(252)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(254)
			alpha = data->__get((i * (int)4));
			HX_STACK_LINE(255)
			red = data->__get(((i * (int)4) + (int)1));
			HX_STACK_LINE(256)
			green = data->__get(((i * (int)4) + (int)2));
			HX_STACK_LINE(257)
			blue = data->__get(((i * (int)4) + (int)3));
			HX_STACK_LINE(259)
			hx::__ArrayImplRef(data,(i * (int)4)) = red;
			HX_STACK_LINE(260)
			hx::__ArrayImplRef(data,((i * (int)4) + (int)1)) = green;
			HX_STACK_LINE(261)
			hx::__ArrayImplRef(data,((i * (int)4) + (int)2)) = blue;
			HX_STACK_LINE(262)
			hx::__ArrayImplRef(data,((i * (int)4) + (int)3)) = alpha;
		}
	}
	HX_STACK_LINE(266)
	return data;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,getRGBAPixels,return )

::flash::display::BitmapData BitmapData_obj::load( ::String filename,hx::Null< int >  __o_format){
int format = __o_format.Default(0);
	HX_STACK_PUSH("BitmapData::load","flash/display/BitmapData.hx",292);
	HX_STACK_ARG(filename,"filename");
	HX_STACK_ARG(format,"format");
{
		HX_STACK_LINE(294)
		::flash::display::BitmapData result = ::flash::display::BitmapData_obj::__new((int)0,(int)0,null(),null(),null());		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(295)
		result->__handle = ::flash::display::BitmapData_obj::lime_bitmap_data_load(filename,format);
		HX_STACK_LINE(296)
		return result;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,load,return )

::flash::display::BitmapData BitmapData_obj::loadFromBytes( ::flash::utils::ByteArray bytes,::flash::utils::ByteArray rawAlpha){
	HX_STACK_PUSH("BitmapData::loadFromBytes","flash/display/BitmapData.hx",301);
	HX_STACK_ARG(bytes,"bytes");
	HX_STACK_ARG(rawAlpha,"rawAlpha");
	HX_STACK_LINE(303)
	::flash::display::BitmapData result = ::flash::display::BitmapData_obj::__new((int)0,(int)0,true,null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(304)
	result->__handle = ::flash::display::BitmapData_obj::lime_bitmap_data_from_bytes(bytes,rawAlpha);
	HX_STACK_LINE(305)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,loadFromBytes,return )

::flash::display::BitmapData BitmapData_obj::loadFromHaxeBytes( ::haxe::io::Bytes bytes,::haxe::io::Bytes rawAlpha){
	HX_STACK_PUSH("BitmapData::loadFromHaxeBytes","flash/display/BitmapData.hx",310);
	HX_STACK_ARG(bytes,"bytes");
	HX_STACK_ARG(rawAlpha,"rawAlpha");
	HX_STACK_LINE(310)
	return ::flash::display::BitmapData_obj::loadFromBytes(::flash::utils::ByteArray_obj::fromBytes(bytes),(  (((rawAlpha == null()))) ? ::flash::utils::ByteArray(null()) : ::flash::utils::ByteArray(::flash::utils::ByteArray_obj::fromBytes(rawAlpha)) ));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,loadFromHaxeBytes,return )

bool BitmapData_obj::sameValue( int a,int b){
	HX_STACK_PUSH("BitmapData::sameValue","flash/display/BitmapData.hx",385);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(385)
	return (a == b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,sameValue,return )

int BitmapData_obj::__flipPixel( int pixel){
	HX_STACK_PUSH("BitmapData::__flipPixel","flash/display/BitmapData.hx",639);
	HX_STACK_ARG(pixel,"pixel");
	HX_STACK_LINE(639)
	return (int((int((int((int(((int(pixel) & int((int)255)))) << int((int)24))) | int((int(((int((int(pixel) >> int((int)8))) & int((int)255)))) << int((int)16))))) | int((int(((int((int(pixel) >> int((int)16))) & int((int)255)))) << int((int)8))))) | int((int((int(pixel) >> int((int)24))) & int((int)255))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,__flipPixel,return )

int BitmapData_obj::__ucompare( int n1,int n2){
	HX_STACK_PUSH("BitmapData::__ucompare","flash/display/BitmapData.hx",653);
	HX_STACK_ARG(n1,"n1");
	HX_STACK_ARG(n2,"n2");
	HX_STACK_LINE(655)
	int tmp1;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(656)
	int tmp2;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(658)
	tmp1 = (int((int(n1) >> int((int)24))) & int((int)255));
	HX_STACK_LINE(659)
	tmp2 = (int((int(n2) >> int((int)24))) & int((int)255));
	HX_STACK_LINE(661)
	if (((tmp1 != tmp2))){
		HX_STACK_LINE(661)
		return (  (((tmp1 > tmp2))) ? int((int)1) : int((int)-1) );
	}
	else{
		HX_STACK_LINE(667)
		tmp1 = (int((int(n1) >> int((int)16))) & int((int)255));
		HX_STACK_LINE(668)
		tmp2 = (int((int(n2) >> int((int)16))) & int((int)255));
		HX_STACK_LINE(670)
		if (((tmp1 != tmp2))){
			HX_STACK_LINE(670)
			return (  (((tmp1 > tmp2))) ? int((int)1) : int((int)-1) );
		}
		else{
			HX_STACK_LINE(676)
			tmp1 = (int((int(n1) >> int((int)8))) & int((int)255));
			HX_STACK_LINE(677)
			tmp2 = (int((int(n2) >> int((int)8))) & int((int)255));
			HX_STACK_LINE(679)
			if (((tmp1 != tmp2))){
				HX_STACK_LINE(679)
				return (  (((tmp1 > tmp2))) ? int((int)1) : int((int)-1) );
			}
			else{
				HX_STACK_LINE(685)
				tmp1 = (int(n1) & int((int)255));
				HX_STACK_LINE(686)
				tmp2 = (int(n2) & int((int)255));
				HX_STACK_LINE(688)
				if (((tmp1 != tmp2))){
					HX_STACK_LINE(688)
					return (  (((tmp1 > tmp2))) ? int((int)1) : int((int)-1) );
				}
				else{
					HX_STACK_LINE(692)
					return (int)0;
				}
			}
		}
	}
	HX_STACK_LINE(661)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,__ucompare,return )

Dynamic BitmapData_obj::lime_bitmap_data_create;

Dynamic BitmapData_obj::lime_bitmap_data_load;

Dynamic BitmapData_obj::lime_bitmap_data_from_bytes;

Dynamic BitmapData_obj::lime_bitmap_data_clear;

Dynamic BitmapData_obj::lime_bitmap_data_clone;

Dynamic BitmapData_obj::lime_bitmap_data_apply_filter;

Dynamic BitmapData_obj::lime_bitmap_data_color_transform;

Dynamic BitmapData_obj::lime_bitmap_data_copy;

Dynamic BitmapData_obj::lime_bitmap_data_copy_channel;

Dynamic BitmapData_obj::lime_bitmap_data_fill;

Dynamic BitmapData_obj::lime_bitmap_data_get_pixels;

Dynamic BitmapData_obj::lime_bitmap_data_get_pixel;

Dynamic BitmapData_obj::lime_bitmap_data_get_pixel32;

Dynamic BitmapData_obj::lime_bitmap_data_get_pixel_rgba;

Dynamic BitmapData_obj::lime_bitmap_data_get_array;

Dynamic BitmapData_obj::lime_bitmap_data_get_color_bounds_rect;

Dynamic BitmapData_obj::lime_bitmap_data_scroll;

Dynamic BitmapData_obj::lime_bitmap_data_set_pixel;

Dynamic BitmapData_obj::lime_bitmap_data_set_pixel32;

Dynamic BitmapData_obj::lime_bitmap_data_set_pixel_rgba;

Dynamic BitmapData_obj::lime_bitmap_data_set_bytes;

Dynamic BitmapData_obj::lime_bitmap_data_set_format;

Dynamic BitmapData_obj::lime_bitmap_data_set_array;

Dynamic BitmapData_obj::lime_bitmap_data_create_hardware_surface;

Dynamic BitmapData_obj::lime_bitmap_data_destroy_hardware_surface;

Dynamic BitmapData_obj::lime_bitmap_data_dispose;

Dynamic BitmapData_obj::lime_bitmap_data_generate_filter_rect;

Dynamic BitmapData_obj::lime_render_surface_to_surface;

Dynamic BitmapData_obj::lime_bitmap_data_height;

Dynamic BitmapData_obj::lime_bitmap_data_width;

Dynamic BitmapData_obj::lime_bitmap_data_get_transparent;

Dynamic BitmapData_obj::lime_bitmap_data_set_flags;

Dynamic BitmapData_obj::lime_bitmap_data_encode;

Dynamic BitmapData_obj::lime_bitmap_data_dump_bits;

Dynamic BitmapData_obj::lime_bitmap_data_flood_fill;

Dynamic BitmapData_obj::lime_bitmap_data_noise;

Dynamic BitmapData_obj::lime_bitmap_data_unmultiply_alpha;

Dynamic BitmapData_obj::lime_bitmap_data_multiply_alpha;

Dynamic BitmapData_obj::lime_bitmap_data_set_alpha_mode;


BitmapData_obj::BitmapData_obj()
{
}

void BitmapData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapData);
	HX_MARK_MEMBER_NAME(__transparent,"__transparent");
	HX_MARK_MEMBER_NAME(__handle,"__handle");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(transparent,"transparent");
	HX_MARK_MEMBER_NAME(rect,"rect");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_END_CLASS();
}

void BitmapData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__transparent,"__transparent");
	HX_VISIT_MEMBER_NAME(__handle,"__handle");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(transparent,"transparent");
	HX_VISIT_MEMBER_NAME(rect,"rect");
	HX_VISIT_MEMBER_NAME(height,"height");
}

Dynamic BitmapData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		if (HX_FIELD_EQ(inName,"lock") ) { return lock_dyn(); }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		if (HX_FIELD_EQ(inName,"rect") ) { return inCallProp ? get_rect() : rect; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"noise") ) { return noise_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? get_width() : width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"unlock") ) { return unlock_dyn(); }
		if (HX_FIELD_EQ(inName,"scroll") ) { return scroll_dyn(); }
		if (HX_FIELD_EQ(inName,"encode") ) { return encode_dyn(); }
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? get_height() : height; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_rect") ) { return get_rect_dyn(); }
		if (HX_FIELD_EQ(inName,"setPixel") ) { return setPixel_dyn(); }
		if (HX_FIELD_EQ(inName,"setFlags") ) { return setFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"getPixel") ) { return getPixel_dyn(); }
		if (HX_FIELD_EQ(inName,"fillRect") ) { return fillRect_dyn(); }
		if (HX_FIELD_EQ(inName,"dumpBits") ) { return dumpBits_dyn(); }
		if (HX_FIELD_EQ(inName,"__handle") ) { return __handle; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sameValue") ) { return sameValue_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"threshold") ) { return threshold_dyn(); }
		if (HX_FIELD_EQ(inName,"setVector") ) { return setVector_dyn(); }
		if (HX_FIELD_EQ(inName,"setPixels") ) { return setPixels_dyn(); }
		if (HX_FIELD_EQ(inName,"setFormat") ) { return setFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"getVector") ) { return getVector_dyn(); }
		if (HX_FIELD_EQ(inName,"getPixels") ) { return getPixels_dyn(); }
		if (HX_FIELD_EQ(inName,"floodFill") ) { return floodFill_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__ucompare") ) { return __ucompare_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"setPixel32") ) { return setPixel32_dyn(); }
		if (HX_FIELD_EQ(inName,"paletteMap") ) { return paletteMap_dyn(); }
		if (HX_FIELD_EQ(inName,"getPixel32") ) { return getPixel32_dyn(); }
		if (HX_FIELD_EQ(inName,"fillRectEx") ) { return fillRectEx_dyn(); }
		if (HX_FIELD_EQ(inName,"copyPixels") ) { return copyPixels_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createColor") ) { return createColor_dyn(); }
		if (HX_FIELD_EQ(inName,"__flipPixel") ) { return __flipPixel_dyn(); }
		if (HX_FIELD_EQ(inName,"perlinNoise") ) { return perlinNoise_dyn(); }
		if (HX_FIELD_EQ(inName,"copyChannel") ) { return copyChannel_dyn(); }
		if (HX_FIELD_EQ(inName,"applyFilter") ) { return applyFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"transparent") ) { return inCallProp ? get_transparent() : transparent; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"extractAlpha") ) { return extractAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"extractColor") ) { return extractColor_dyn(); }
		if (HX_FIELD_EQ(inName,"setAlphaMode") ) { return setAlphaMode_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getRGBAPixels") ) { return getRGBAPixels_dyn(); }
		if (HX_FIELD_EQ(inName,"loadFromBytes") ) { return loadFromBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"multiplyAlpha") ) { return multiplyAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"__transparent") ) { return __transparent; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { return colorTransform_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_transparent") ) { return get_transparent_dyn(); }
		if (HX_FIELD_EQ(inName,"__loadFromBytes") ) { return __loadFromBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"__drawToSurface") ) { return __drawToSurface_dyn(); }
		if (HX_FIELD_EQ(inName,"unmultiplyAlpha") ) { return unmultiplyAlpha_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"loadFromHaxeBytes") ) { return loadFromHaxeBytes_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getColorBoundsRect") ) { return getColorBoundsRect_dyn(); }
		if (HX_FIELD_EQ(inName,"generateFilterRect") ) { return generateFilterRect_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_load") ) { return lime_bitmap_data_load; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_copy") ) { return lime_bitmap_data_copy; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_fill") ) { return lime_bitmap_data_fill; }
		if (HX_FIELD_EQ(inName,"createHardwareSurface") ) { return createHardwareSurface_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_clear") ) { return lime_bitmap_data_clear; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_clone") ) { return lime_bitmap_data_clone; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_width") ) { return lime_bitmap_data_width; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_noise") ) { return lime_bitmap_data_noise; }
		if (HX_FIELD_EQ(inName,"destroyHardwareSurface") ) { return destroyHardwareSurface_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_create") ) { return lime_bitmap_data_create; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_scroll") ) { return lime_bitmap_data_scroll; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_height") ) { return lime_bitmap_data_height; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_encode") ) { return lime_bitmap_data_encode; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_dispose") ) { return lime_bitmap_data_dispose; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_pixel") ) { return lime_bitmap_data_get_pixel; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_array") ) { return lime_bitmap_data_get_array; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_pixel") ) { return lime_bitmap_data_set_pixel; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_bytes") ) { return lime_bitmap_data_set_bytes; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_array") ) { return lime_bitmap_data_set_array; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_flags") ) { return lime_bitmap_data_set_flags; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_dump_bits") ) { return lime_bitmap_data_dump_bits; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_from_bytes") ) { return lime_bitmap_data_from_bytes; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_pixels") ) { return lime_bitmap_data_get_pixels; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_format") ) { return lime_bitmap_data_set_format; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_flood_fill") ) { return lime_bitmap_data_flood_fill; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_pixel32") ) { return lime_bitmap_data_get_pixel32; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_pixel32") ) { return lime_bitmap_data_set_pixel32; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_apply_filter") ) { return lime_bitmap_data_apply_filter; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_copy_channel") ) { return lime_bitmap_data_copy_channel; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_render_surface_to_surface") ) { return lime_render_surface_to_surface; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_pixel_rgba") ) { return lime_bitmap_data_get_pixel_rgba; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_pixel_rgba") ) { return lime_bitmap_data_set_pixel_rgba; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_multiply_alpha") ) { return lime_bitmap_data_multiply_alpha; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_alpha_mode") ) { return lime_bitmap_data_set_alpha_mode; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_color_transform") ) { return lime_bitmap_data_color_transform; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_transparent") ) { return lime_bitmap_data_get_transparent; }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_unmultiply_alpha") ) { return lime_bitmap_data_unmultiply_alpha; }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_generate_filter_rect") ) { return lime_bitmap_data_generate_filter_rect; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_color_bounds_rect") ) { return lime_bitmap_data_get_color_bounds_rect; }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_create_hardware_surface") ) { return lime_bitmap_data_create_hardware_surface; }
		break;
	case 41:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_destroy_hardware_surface") ) { return lime_bitmap_data_destroy_hardware_surface; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BitmapData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"rect") ) { rect=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__handle") ) { __handle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"transparent") ) { transparent=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"__transparent") ) { __transparent=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_load") ) { lime_bitmap_data_load=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_copy") ) { lime_bitmap_data_copy=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_fill") ) { lime_bitmap_data_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_clear") ) { lime_bitmap_data_clear=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_clone") ) { lime_bitmap_data_clone=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_width") ) { lime_bitmap_data_width=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_noise") ) { lime_bitmap_data_noise=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_create") ) { lime_bitmap_data_create=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_scroll") ) { lime_bitmap_data_scroll=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_height") ) { lime_bitmap_data_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_encode") ) { lime_bitmap_data_encode=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_dispose") ) { lime_bitmap_data_dispose=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_pixel") ) { lime_bitmap_data_get_pixel=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_array") ) { lime_bitmap_data_get_array=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_pixel") ) { lime_bitmap_data_set_pixel=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_bytes") ) { lime_bitmap_data_set_bytes=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_array") ) { lime_bitmap_data_set_array=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_flags") ) { lime_bitmap_data_set_flags=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_dump_bits") ) { lime_bitmap_data_dump_bits=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_from_bytes") ) { lime_bitmap_data_from_bytes=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_pixels") ) { lime_bitmap_data_get_pixels=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_format") ) { lime_bitmap_data_set_format=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_flood_fill") ) { lime_bitmap_data_flood_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_pixel32") ) { lime_bitmap_data_get_pixel32=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_pixel32") ) { lime_bitmap_data_set_pixel32=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_apply_filter") ) { lime_bitmap_data_apply_filter=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_copy_channel") ) { lime_bitmap_data_copy_channel=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_render_surface_to_surface") ) { lime_render_surface_to_surface=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_pixel_rgba") ) { lime_bitmap_data_get_pixel_rgba=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_pixel_rgba") ) { lime_bitmap_data_set_pixel_rgba=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_multiply_alpha") ) { lime_bitmap_data_multiply_alpha=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_set_alpha_mode") ) { lime_bitmap_data_set_alpha_mode=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_color_transform") ) { lime_bitmap_data_color_transform=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_transparent") ) { lime_bitmap_data_get_transparent=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_unmultiply_alpha") ) { lime_bitmap_data_unmultiply_alpha=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_generate_filter_rect") ) { lime_bitmap_data_generate_filter_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_get_color_bounds_rect") ) { lime_bitmap_data_get_color_bounds_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_create_hardware_surface") ) { lime_bitmap_data_create_hardware_surface=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 41:
		if (HX_FIELD_EQ(inName,"lime_bitmap_data_destroy_hardware_surface") ) { lime_bitmap_data_destroy_hardware_surface=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BitmapData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__transparent"));
	outFields->push(HX_CSTRING("__handle"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("transparent"));
	outFields->push(HX_CSTRING("rect"));
	outFields->push(HX_CSTRING("height"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("CLEAR"),
	HX_CSTRING("BLACK"),
	HX_CSTRING("WHITE"),
	HX_CSTRING("RED"),
	HX_CSTRING("GREEN"),
	HX_CSTRING("BLUE"),
	HX_CSTRING("PNG"),
	HX_CSTRING("JPG"),
	HX_CSTRING("TRANSPARENT"),
	HX_CSTRING("HARDWARE"),
	HX_CSTRING("FORMAT_8888"),
	HX_CSTRING("FORMAT_4444"),
	HX_CSTRING("FORMAT_565"),
	HX_CSTRING("createColor"),
	HX_CSTRING("extractAlpha"),
	HX_CSTRING("extractColor"),
	HX_CSTRING("getRGBAPixels"),
	HX_CSTRING("load"),
	HX_CSTRING("loadFromBytes"),
	HX_CSTRING("loadFromHaxeBytes"),
	HX_CSTRING("sameValue"),
	HX_CSTRING("__flipPixel"),
	HX_CSTRING("__ucompare"),
	HX_CSTRING("lime_bitmap_data_create"),
	HX_CSTRING("lime_bitmap_data_load"),
	HX_CSTRING("lime_bitmap_data_from_bytes"),
	HX_CSTRING("lime_bitmap_data_clear"),
	HX_CSTRING("lime_bitmap_data_clone"),
	HX_CSTRING("lime_bitmap_data_apply_filter"),
	HX_CSTRING("lime_bitmap_data_color_transform"),
	HX_CSTRING("lime_bitmap_data_copy"),
	HX_CSTRING("lime_bitmap_data_copy_channel"),
	HX_CSTRING("lime_bitmap_data_fill"),
	HX_CSTRING("lime_bitmap_data_get_pixels"),
	HX_CSTRING("lime_bitmap_data_get_pixel"),
	HX_CSTRING("lime_bitmap_data_get_pixel32"),
	HX_CSTRING("lime_bitmap_data_get_pixel_rgba"),
	HX_CSTRING("lime_bitmap_data_get_array"),
	HX_CSTRING("lime_bitmap_data_get_color_bounds_rect"),
	HX_CSTRING("lime_bitmap_data_scroll"),
	HX_CSTRING("lime_bitmap_data_set_pixel"),
	HX_CSTRING("lime_bitmap_data_set_pixel32"),
	HX_CSTRING("lime_bitmap_data_set_pixel_rgba"),
	HX_CSTRING("lime_bitmap_data_set_bytes"),
	HX_CSTRING("lime_bitmap_data_set_format"),
	HX_CSTRING("lime_bitmap_data_set_array"),
	HX_CSTRING("lime_bitmap_data_create_hardware_surface"),
	HX_CSTRING("lime_bitmap_data_destroy_hardware_surface"),
	HX_CSTRING("lime_bitmap_data_dispose"),
	HX_CSTRING("lime_bitmap_data_generate_filter_rect"),
	HX_CSTRING("lime_render_surface_to_surface"),
	HX_CSTRING("lime_bitmap_data_height"),
	HX_CSTRING("lime_bitmap_data_width"),
	HX_CSTRING("lime_bitmap_data_get_transparent"),
	HX_CSTRING("lime_bitmap_data_set_flags"),
	HX_CSTRING("lime_bitmap_data_encode"),
	HX_CSTRING("lime_bitmap_data_dump_bits"),
	HX_CSTRING("lime_bitmap_data_flood_fill"),
	HX_CSTRING("lime_bitmap_data_noise"),
	HX_CSTRING("lime_bitmap_data_unmultiply_alpha"),
	HX_CSTRING("lime_bitmap_data_multiply_alpha"),
	HX_CSTRING("lime_bitmap_data_set_alpha_mode"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_transparent"),
	HX_CSTRING("get_height"),
	HX_CSTRING("get_width"),
	HX_CSTRING("get_rect"),
	HX_CSTRING("__loadFromBytes"),
	HX_CSTRING("__drawToSurface"),
	HX_CSTRING("unmultiplyAlpha"),
	HX_CSTRING("unlock"),
	HX_CSTRING("threshold"),
	HX_CSTRING("setVector"),
	HX_CSTRING("setPixels"),
	HX_CSTRING("setPixel32"),
	HX_CSTRING("setPixel"),
	HX_CSTRING("setFormat"),
	HX_CSTRING("setFlags"),
	HX_CSTRING("setAlphaMode"),
	HX_CSTRING("scroll"),
	HX_CSTRING("perlinNoise"),
	HX_CSTRING("paletteMap"),
	HX_CSTRING("noise"),
	HX_CSTRING("multiplyAlpha"),
	HX_CSTRING("lock"),
	HX_CSTRING("getVector"),
	HX_CSTRING("getPixels"),
	HX_CSTRING("getPixel32"),
	HX_CSTRING("getPixel"),
	HX_CSTRING("getColorBoundsRect"),
	HX_CSTRING("generateFilterRect"),
	HX_CSTRING("floodFill"),
	HX_CSTRING("fillRectEx"),
	HX_CSTRING("fillRect"),
	HX_CSTRING("encode"),
	HX_CSTRING("dumpBits"),
	HX_CSTRING("draw"),
	HX_CSTRING("dispose"),
	HX_CSTRING("destroyHardwareSurface"),
	HX_CSTRING("createHardwareSurface"),
	HX_CSTRING("copyPixels"),
	HX_CSTRING("copyChannel"),
	HX_CSTRING("colorTransform"),
	HX_CSTRING("clone"),
	HX_CSTRING("clear"),
	HX_CSTRING("applyFilter"),
	HX_CSTRING("__transparent"),
	HX_CSTRING("__handle"),
	HX_CSTRING("width"),
	HX_CSTRING("transparent"),
	HX_CSTRING("rect"),
	HX_CSTRING("height"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BitmapData_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BitmapData_obj::CLEAR,"CLEAR");
	HX_MARK_MEMBER_NAME(BitmapData_obj::BLACK,"BLACK");
	HX_MARK_MEMBER_NAME(BitmapData_obj::WHITE,"WHITE");
	HX_MARK_MEMBER_NAME(BitmapData_obj::RED,"RED");
	HX_MARK_MEMBER_NAME(BitmapData_obj::GREEN,"GREEN");
	HX_MARK_MEMBER_NAME(BitmapData_obj::BLUE,"BLUE");
	HX_MARK_MEMBER_NAME(BitmapData_obj::PNG,"PNG");
	HX_MARK_MEMBER_NAME(BitmapData_obj::JPG,"JPG");
	HX_MARK_MEMBER_NAME(BitmapData_obj::TRANSPARENT,"TRANSPARENT");
	HX_MARK_MEMBER_NAME(BitmapData_obj::HARDWARE,"HARDWARE");
	HX_MARK_MEMBER_NAME(BitmapData_obj::FORMAT_8888,"FORMAT_8888");
	HX_MARK_MEMBER_NAME(BitmapData_obj::FORMAT_4444,"FORMAT_4444");
	HX_MARK_MEMBER_NAME(BitmapData_obj::FORMAT_565,"FORMAT_565");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_create,"lime_bitmap_data_create");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_load,"lime_bitmap_data_load");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_from_bytes,"lime_bitmap_data_from_bytes");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_clear,"lime_bitmap_data_clear");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_clone,"lime_bitmap_data_clone");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_apply_filter,"lime_bitmap_data_apply_filter");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_color_transform,"lime_bitmap_data_color_transform");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_copy,"lime_bitmap_data_copy");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_copy_channel,"lime_bitmap_data_copy_channel");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_fill,"lime_bitmap_data_fill");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_pixels,"lime_bitmap_data_get_pixels");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_pixel,"lime_bitmap_data_get_pixel");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_pixel32,"lime_bitmap_data_get_pixel32");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_pixel_rgba,"lime_bitmap_data_get_pixel_rgba");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_array,"lime_bitmap_data_get_array");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_color_bounds_rect,"lime_bitmap_data_get_color_bounds_rect");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_scroll,"lime_bitmap_data_scroll");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_pixel,"lime_bitmap_data_set_pixel");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_pixel32,"lime_bitmap_data_set_pixel32");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_pixel_rgba,"lime_bitmap_data_set_pixel_rgba");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_bytes,"lime_bitmap_data_set_bytes");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_format,"lime_bitmap_data_set_format");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_array,"lime_bitmap_data_set_array");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_create_hardware_surface,"lime_bitmap_data_create_hardware_surface");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_destroy_hardware_surface,"lime_bitmap_data_destroy_hardware_surface");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_dispose,"lime_bitmap_data_dispose");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_generate_filter_rect,"lime_bitmap_data_generate_filter_rect");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_render_surface_to_surface,"lime_render_surface_to_surface");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_height,"lime_bitmap_data_height");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_width,"lime_bitmap_data_width");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_transparent,"lime_bitmap_data_get_transparent");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_flags,"lime_bitmap_data_set_flags");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_encode,"lime_bitmap_data_encode");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_dump_bits,"lime_bitmap_data_dump_bits");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_flood_fill,"lime_bitmap_data_flood_fill");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_noise,"lime_bitmap_data_noise");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_unmultiply_alpha,"lime_bitmap_data_unmultiply_alpha");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_multiply_alpha,"lime_bitmap_data_multiply_alpha");
	HX_MARK_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_alpha_mode,"lime_bitmap_data_set_alpha_mode");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BitmapData_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::CLEAR,"CLEAR");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::BLACK,"BLACK");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::WHITE,"WHITE");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::RED,"RED");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::GREEN,"GREEN");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::BLUE,"BLUE");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::PNG,"PNG");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::JPG,"JPG");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::TRANSPARENT,"TRANSPARENT");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::HARDWARE,"HARDWARE");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::FORMAT_8888,"FORMAT_8888");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::FORMAT_4444,"FORMAT_4444");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::FORMAT_565,"FORMAT_565");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_create,"lime_bitmap_data_create");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_load,"lime_bitmap_data_load");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_from_bytes,"lime_bitmap_data_from_bytes");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_clear,"lime_bitmap_data_clear");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_clone,"lime_bitmap_data_clone");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_apply_filter,"lime_bitmap_data_apply_filter");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_color_transform,"lime_bitmap_data_color_transform");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_copy,"lime_bitmap_data_copy");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_copy_channel,"lime_bitmap_data_copy_channel");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_fill,"lime_bitmap_data_fill");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_pixels,"lime_bitmap_data_get_pixels");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_pixel,"lime_bitmap_data_get_pixel");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_pixel32,"lime_bitmap_data_get_pixel32");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_pixel_rgba,"lime_bitmap_data_get_pixel_rgba");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_array,"lime_bitmap_data_get_array");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_color_bounds_rect,"lime_bitmap_data_get_color_bounds_rect");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_scroll,"lime_bitmap_data_scroll");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_pixel,"lime_bitmap_data_set_pixel");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_pixel32,"lime_bitmap_data_set_pixel32");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_pixel_rgba,"lime_bitmap_data_set_pixel_rgba");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_bytes,"lime_bitmap_data_set_bytes");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_format,"lime_bitmap_data_set_format");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_array,"lime_bitmap_data_set_array");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_create_hardware_surface,"lime_bitmap_data_create_hardware_surface");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_destroy_hardware_surface,"lime_bitmap_data_destroy_hardware_surface");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_dispose,"lime_bitmap_data_dispose");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_generate_filter_rect,"lime_bitmap_data_generate_filter_rect");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_render_surface_to_surface,"lime_render_surface_to_surface");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_height,"lime_bitmap_data_height");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_width,"lime_bitmap_data_width");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_get_transparent,"lime_bitmap_data_get_transparent");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_flags,"lime_bitmap_data_set_flags");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_encode,"lime_bitmap_data_encode");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_dump_bits,"lime_bitmap_data_dump_bits");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_flood_fill,"lime_bitmap_data_flood_fill");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_noise,"lime_bitmap_data_noise");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_unmultiply_alpha,"lime_bitmap_data_unmultiply_alpha");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_multiply_alpha,"lime_bitmap_data_multiply_alpha");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::lime_bitmap_data_set_alpha_mode,"lime_bitmap_data_set_alpha_mode");
};

Class BitmapData_obj::__mClass;

void BitmapData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.display.BitmapData"), hx::TCanCast< BitmapData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BitmapData_obj::__boot()
{
	CLEAR= (int)0;
	BLACK= (int)-16777216;
	WHITE= (int)-16777216;
	RED= (int)-65536;
	GREEN= (int)-16711936;
	BLUE= (int)-16776961;
	PNG= HX_CSTRING("png");
	JPG= HX_CSTRING("jpg");
	TRANSPARENT= (int)1;
	HARDWARE= (int)2;
	FORMAT_8888= (int)0;
	FORMAT_4444= (int)1;
	FORMAT_565= (int)2;
	lime_bitmap_data_create= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_create"),(int)-1);
	lime_bitmap_data_load= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_load"),(int)2);
	lime_bitmap_data_from_bytes= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_from_bytes"),(int)2);
	lime_bitmap_data_clear= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_clear"),(int)2);
	lime_bitmap_data_clone= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_clone"),(int)1);
	lime_bitmap_data_apply_filter= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_apply_filter"),(int)5);
	lime_bitmap_data_color_transform= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_color_transform"),(int)3);
	lime_bitmap_data_copy= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_copy"),(int)5);
	lime_bitmap_data_copy_channel= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_copy_channel"),(int)-1);
	lime_bitmap_data_fill= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_fill"),(int)4);
	lime_bitmap_data_get_pixels= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_get_pixels"),(int)2);
	lime_bitmap_data_get_pixel= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_get_pixel"),(int)3);
	lime_bitmap_data_get_pixel32= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_get_pixel32"),(int)3);
	lime_bitmap_data_get_pixel_rgba= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_get_pixel_rgba"),(int)3);
	lime_bitmap_data_get_array= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_get_array"),(int)3);
	lime_bitmap_data_get_color_bounds_rect= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_get_color_bounds_rect"),(int)5);
	lime_bitmap_data_scroll= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_scroll"),(int)3);
	lime_bitmap_data_set_pixel= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_set_pixel"),(int)4);
	lime_bitmap_data_set_pixel32= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_set_pixel32"),(int)4);
	lime_bitmap_data_set_pixel_rgba= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_set_pixel_rgba"),(int)4);
	lime_bitmap_data_set_bytes= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_set_bytes"),(int)4);
	lime_bitmap_data_set_format= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_set_format"),(int)2);
	lime_bitmap_data_set_array= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_set_array"),(int)3);
	lime_bitmap_data_create_hardware_surface= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_create_hardware_surface"),(int)1);
	lime_bitmap_data_destroy_hardware_surface= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_destroy_hardware_surface"),(int)1);
	lime_bitmap_data_dispose= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_dispose"),(int)1);
	lime_bitmap_data_generate_filter_rect= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_generate_filter_rect"),(int)3);
	lime_render_surface_to_surface= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_render_surface_to_surface"),(int)-1);
	lime_bitmap_data_height= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_height"),(int)1);
	lime_bitmap_data_width= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_width"),(int)1);
	lime_bitmap_data_get_transparent= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_get_transparent"),(int)1);
	lime_bitmap_data_set_flags= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_set_flags"),(int)1);
	lime_bitmap_data_encode= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_encode"),(int)3);
	lime_bitmap_data_dump_bits= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_dump_bits"),(int)1);
	lime_bitmap_data_flood_fill= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_flood_fill"),(int)4);
	lime_bitmap_data_noise= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_noise"),(int)-1);
	lime_bitmap_data_unmultiply_alpha= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_unmultiply_alpha"),(int)1);
	lime_bitmap_data_multiply_alpha= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_multiply_alpha"),(int)1);
	lime_bitmap_data_set_alpha_mode= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_bitmap_data_set_alpha_mode"),(int)2);
}

} // end namespace flash
} // end namespace display
