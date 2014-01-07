#ifndef INCLUDED_motion_Actuate
#define INCLUDED_motion_Actuate

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(haxe,ds,ObjectMap)
HX_DECLARE_CLASS1(motion,Actuate)
HX_DECLARE_CLASS2(motion,_Actuate,EffectsOptions)
HX_DECLARE_CLASS2(motion,_Actuate,TransformOptions)
HX_DECLARE_CLASS2(motion,actuators,GenericActuator)
HX_DECLARE_CLASS2(motion,actuators,IGenericActuator)
HX_DECLARE_CLASS2(motion,easing,IEasing)
namespace motion{


class HXCPP_CLASS_ATTRIBUTES  Actuate_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Actuate_obj OBJ_;
		Actuate_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Actuate_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Actuate_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Actuate"); }

		static ::Class defaultActuator;
		static ::motion::easing::IEasing defaultEase;
		static ::haxe::ds::ObjectMap targetLibraries;
		static ::motion::actuators::IGenericActuator apply( Dynamic target,Dynamic properties,::Class customActuator);
		static Dynamic apply_dyn();

		static ::motion::_Actuate::EffectsOptions effects( ::flash::display::DisplayObject target,Float duration,hx::Null< bool >  overwrite);
		static Dynamic effects_dyn();

		static Array< ::Dynamic > getLibrary( Dynamic target,hx::Null< bool >  allowCreation);
		static Dynamic getLibrary_dyn();

		static ::motion::actuators::IGenericActuator motionPath( Dynamic target,Float duration,Dynamic properties,hx::Null< bool >  overwrite);
		static Dynamic motionPath_dyn();

		static Void pause( Dynamic target);
		static Dynamic pause_dyn();

		static Void pauseAll( );
		static Dynamic pauseAll_dyn();

		static Void reset( );
		static Dynamic reset_dyn();

		static Void resume( Dynamic target);
		static Dynamic resume_dyn();

		static Void resumeAll( );
		static Dynamic resumeAll_dyn();

		static Void stop( Dynamic target,Dynamic properties,hx::Null< bool >  complete,hx::Null< bool >  sendEvent);
		static Dynamic stop_dyn();

		static ::motion::actuators::IGenericActuator timer( Float duration,::Class customActuator);
		static Dynamic timer_dyn();

		static ::motion::_Actuate::TransformOptions transform( Dynamic target,hx::Null< Float >  duration,hx::Null< bool >  overwrite);
		static Dynamic transform_dyn();

		static ::motion::actuators::IGenericActuator tween( Dynamic target,Float duration,Dynamic properties,hx::Null< bool >  overwrite,::Class customActuator);
		static Dynamic tween_dyn();

		static Void unload( ::motion::actuators::GenericActuator actuator);
		static Dynamic unload_dyn();

		static ::motion::actuators::IGenericActuator update( Dynamic target,Float duration,Dynamic start,Dynamic end,hx::Null< bool >  overwrite);
		static Dynamic update_dyn();

};

} // end namespace motion

#endif /* INCLUDED_motion_Actuate */ 
