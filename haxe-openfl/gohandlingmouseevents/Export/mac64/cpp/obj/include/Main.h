#ifndef INCLUDED_Main
#define INCLUDED_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/display/Sprite.h>
HX_DECLARE_CLASS0(Main)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,events,MouseEvent)
HX_DECLARE_CLASS2(flash,utils,Timer)


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public ::flash::display::Sprite_obj{
	public:
		typedef ::flash::display::Sprite_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		virtual Void stage_onMouseUp( ::flash::events::MouseEvent event);
		Dynamic stage_onMouseUp_dyn();

		virtual Void stage_onMouseMove( ::flash::events::MouseEvent event);
		Dynamic stage_onMouseMove_dyn();

		virtual Void Logo_onMouseDown( ::flash::events::MouseEvent event);
		Dynamic Logo_onMouseDown_dyn();

		::flash::utils::Timer goTimer;
		Float cacheOffsetY;
		Float cacheOffsetX;
		::flash::display::Sprite Destination;
		::flash::display::Sprite Logo;
};


#endif /* INCLUDED_Main */ 
