#ifndef INCLUDED_flash_events_ErrorEvent
#define INCLUDED_flash_events_ErrorEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/events/TextEvent.h>
HX_DECLARE_CLASS2(flash,events,ErrorEvent)
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,TextEvent)
namespace flash{
namespace events{


class HXCPP_CLASS_ATTRIBUTES  ErrorEvent_obj : public ::flash::events::TextEvent_obj{
	public:
		typedef ::flash::events::TextEvent_obj super;
		typedef ErrorEvent_obj OBJ_;
		ErrorEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::String __o_text,hx::Null< int >  __o_id);

	public:
		static hx::ObjectPtr< ErrorEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::String __o_text,hx::Null< int >  __o_id);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ErrorEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ErrorEvent"); }

		virtual ::String toString( );

		virtual ::flash::events::Event clone( );

		int errorID;
		static ::String ERROR;
};

} // end namespace flash
} // end namespace events

#endif /* INCLUDED_flash_events_ErrorEvent */ 
