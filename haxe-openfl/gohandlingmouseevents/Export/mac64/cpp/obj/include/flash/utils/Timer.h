#ifndef INCLUDED_flash_utils_Timer
#define INCLUDED_flash_utils_Timer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/events/EventDispatcher.h>
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,utils,Timer)
HX_DECLARE_CLASS1(haxe,Timer)
namespace flash{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES  Timer_obj : public ::flash::events::EventDispatcher_obj{
	public:
		typedef ::flash::events::EventDispatcher_obj super;
		typedef Timer_obj OBJ_;
		Timer_obj();
		Void __construct(Float delay,hx::Null< int >  __o_repeatCount);

	public:
		static hx::ObjectPtr< Timer_obj > __new(Float delay,hx::Null< int >  __o_repeatCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Timer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Timer"); }

		virtual Void timer_onTimer( );
		Dynamic timer_onTimer_dyn();

		virtual Float set_delay( Float value);
		Dynamic set_delay_dyn();

		virtual Float get_delay( );
		Dynamic get_delay_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void start( );
		Dynamic start_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		::haxe::Timer __timer;
		Float __delay;
		bool running;
		int repeatCount;
		int currentCount;
};

} // end namespace flash
} // end namespace utils

#endif /* INCLUDED_flash_utils_Timer */ 
