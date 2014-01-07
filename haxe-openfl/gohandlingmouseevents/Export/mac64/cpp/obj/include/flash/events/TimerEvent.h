#ifndef INCLUDED_flash_events_TimerEvent
#define INCLUDED_flash_events_TimerEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/events/Event.h>
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,TimerEvent)
namespace flash{
namespace events{


class HXCPP_CLASS_ATTRIBUTES  TimerEvent_obj : public ::flash::events::Event_obj{
	public:
		typedef ::flash::events::Event_obj super;
		typedef TimerEvent_obj OBJ_;
		TimerEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable);

	public:
		static hx::ObjectPtr< TimerEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TimerEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TimerEvent"); }

		virtual Void updateAfterEvent( );
		Dynamic updateAfterEvent_dyn();

		virtual ::String toString( );

		virtual ::flash::events::Event clone( );

		static ::String TIMER;
		static ::String TIMER_COMPLETE;
};

} // end namespace flash
} // end namespace events

#endif /* INCLUDED_flash_events_TimerEvent */ 
