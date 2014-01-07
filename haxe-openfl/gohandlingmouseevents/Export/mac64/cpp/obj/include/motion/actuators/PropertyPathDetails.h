#ifndef INCLUDED_motion_actuators_PropertyPathDetails
#define INCLUDED_motion_actuators_PropertyPathDetails

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <motion/actuators/PropertyDetails.h>
HX_DECLARE_CLASS1(motion,IComponentPath)
HX_DECLARE_CLASS2(motion,actuators,PropertyDetails)
HX_DECLARE_CLASS2(motion,actuators,PropertyPathDetails)
namespace motion{
namespace actuators{


class HXCPP_CLASS_ATTRIBUTES  PropertyPathDetails_obj : public ::motion::actuators::PropertyDetails_obj{
	public:
		typedef ::motion::actuators::PropertyDetails_obj super;
		typedef PropertyPathDetails_obj OBJ_;
		PropertyPathDetails_obj();
		Void __construct(Dynamic target,::String propertyName,::motion::IComponentPath path,hx::Null< bool >  __o_isField);

	public:
		static hx::ObjectPtr< PropertyPathDetails_obj > __new(Dynamic target,::String propertyName,::motion::IComponentPath path,hx::Null< bool >  __o_isField);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PropertyPathDetails_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PropertyPathDetails"); }

		::motion::IComponentPath path;
};

} // end namespace motion
} // end namespace actuators

#endif /* INCLUDED_motion_actuators_PropertyPathDetails */ 
