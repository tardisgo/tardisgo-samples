#ifndef INCLUDED_motion__Actuate_TransformOptions
#define INCLUDED_motion__Actuate_TransformOptions

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(motion,_Actuate,TransformOptions)
HX_DECLARE_CLASS2(motion,actuators,IGenericActuator)
namespace motion{
namespace _Actuate{


class HXCPP_CLASS_ATTRIBUTES  TransformOptions_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TransformOptions_obj OBJ_;
		TransformOptions_obj();
		Void __construct(Dynamic target,Float duration,bool overwrite);

	public:
		static hx::ObjectPtr< TransformOptions_obj > __new(Dynamic target,Float duration,bool overwrite);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TransformOptions_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TransformOptions"); }

		virtual ::motion::actuators::IGenericActuator sound( Dynamic volume,Dynamic pan);
		Dynamic sound_dyn();

		virtual ::motion::actuators::IGenericActuator color( hx::Null< Float >  value,hx::Null< Float >  strength,Dynamic alpha);
		Dynamic color_dyn();

		Dynamic target;
		bool overwrite;
		Float duration;
};

} // end namespace motion
} // end namespace _Actuate

#endif /* INCLUDED_motion__Actuate_TransformOptions */ 
