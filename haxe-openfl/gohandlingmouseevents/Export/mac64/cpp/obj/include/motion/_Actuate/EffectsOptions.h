#ifndef INCLUDED_motion__Actuate_EffectsOptions
#define INCLUDED_motion__Actuate_EffectsOptions

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(motion,_Actuate,EffectsOptions)
HX_DECLARE_CLASS2(motion,actuators,IGenericActuator)
namespace motion{
namespace _Actuate{


class HXCPP_CLASS_ATTRIBUTES  EffectsOptions_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EffectsOptions_obj OBJ_;
		EffectsOptions_obj();
		Void __construct(::flash::display::DisplayObject target,Float duration,bool overwrite);

	public:
		static hx::ObjectPtr< EffectsOptions_obj > __new(::flash::display::DisplayObject target,Float duration,bool overwrite);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EffectsOptions_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EffectsOptions"); }

		virtual ::motion::actuators::IGenericActuator filter( Dynamic reference,Dynamic properties);
		Dynamic filter_dyn();

		::flash::display::DisplayObject target;
		bool overwrite;
		Float duration;
};

} // end namespace motion
} // end namespace _Actuate

#endif /* INCLUDED_motion__Actuate_EffectsOptions */ 
