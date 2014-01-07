#ifndef INCLUDED_flash_display_Bitmap
#define INCLUDED_flash_display_Bitmap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/display/DisplayObject.h>
HX_DECLARE_CLASS2(flash,display,Bitmap)
HX_DECLARE_CLASS2(flash,display,BitmapData)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,PixelSnapping)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
namespace flash{
namespace display{


class HXCPP_CLASS_ATTRIBUTES  Bitmap_obj : public ::flash::display::DisplayObject_obj{
	public:
		typedef ::flash::display::DisplayObject_obj super;
		typedef Bitmap_obj OBJ_;
		Bitmap_obj();
		Void __construct(::flash::display::BitmapData bitmapData,::flash::display::PixelSnapping pixelSnapping,hx::Null< bool >  __o_smoothing);

	public:
		static hx::ObjectPtr< Bitmap_obj > __new(::flash::display::BitmapData bitmapData,::flash::display::PixelSnapping pixelSnapping,hx::Null< bool >  __o_smoothing);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Bitmap_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Bitmap"); }

		virtual bool set_smoothing( bool value);
		Dynamic set_smoothing_dyn();

		virtual ::flash::display::BitmapData set_bitmapData( ::flash::display::BitmapData value);
		Dynamic set_bitmapData_dyn();

		virtual Void __rebuild( );
		Dynamic __rebuild_dyn();

		bool smoothing;
		::flash::display::BitmapData bitmapData;
};

} // end namespace flash
} // end namespace display

#endif /* INCLUDED_flash_display_Bitmap */ 
