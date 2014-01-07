#ifndef INCLUDED_openfl_events_SystemEvent
#define INCLUDED_openfl_events_SystemEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/events/Event.h>
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(openfl,events,SystemEvent)
namespace openfl{
namespace events{


class HXCPP_CLASS_ATTRIBUTES  SystemEvent_obj : public ::flash::events::Event_obj{
	public:
		typedef ::flash::events::Event_obj super;
		typedef SystemEvent_obj OBJ_;
		SystemEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_data);

	public:
		static hx::ObjectPtr< SystemEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_data);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SystemEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SystemEvent"); }

		virtual ::String toString( );

		virtual ::flash::events::Event clone( );

		int data;
		static ::String SYSTEM;
};

} // end namespace openfl
} // end namespace events

#endif /* INCLUDED_openfl_events_SystemEvent */ 
