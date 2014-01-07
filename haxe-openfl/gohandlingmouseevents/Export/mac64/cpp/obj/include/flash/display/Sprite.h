#ifndef INCLUDED_flash_display_Sprite
#define INCLUDED_flash_display_Sprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/display/DisplayObjectContainer.h>
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,geom,Rectangle)
namespace flash{
namespace display{


class HXCPP_CLASS_ATTRIBUTES  Sprite_obj : public ::flash::display::DisplayObjectContainer_obj{
	public:
		typedef ::flash::display::DisplayObjectContainer_obj super;
		typedef Sprite_obj OBJ_;
		Sprite_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Sprite_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Sprite_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Sprite"); }

		virtual ::String __getType( );
		Dynamic __getType_dyn();

		virtual Void stopDrag( );
		Dynamic stopDrag_dyn();

		virtual Void startDrag( hx::Null< bool >  lockCenter,::flash::geom::Rectangle bounds);
		Dynamic startDrag_dyn();

		bool useHandCursor;
		bool buttonMode;
};

} // end namespace flash
} // end namespace display

#endif /* INCLUDED_flash_display_Sprite */ 
