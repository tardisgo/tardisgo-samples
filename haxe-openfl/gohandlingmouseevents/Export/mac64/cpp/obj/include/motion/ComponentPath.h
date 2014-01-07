#ifndef INCLUDED_motion_ComponentPath
#define INCLUDED_motion_ComponentPath

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <motion/IComponentPath.h>
HX_DECLARE_CLASS1(motion,BezierPath)
HX_DECLARE_CLASS1(motion,ComponentPath)
HX_DECLARE_CLASS1(motion,IComponentPath)
namespace motion{


class HXCPP_CLASS_ATTRIBUTES  ComponentPath_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ComponentPath_obj OBJ_;
		ComponentPath_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ComponentPath_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ComponentPath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::motion::IComponentPath_obj *()
			{ return new ::motion::IComponentPath_delegate_< ComponentPath_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("ComponentPath"); }

		virtual Float get_end( );
		Dynamic get_end_dyn();

		virtual Float calculate( Float k);
		Dynamic calculate_dyn();

		virtual Void addPath( ::motion::BezierPath path);
		Dynamic addPath_dyn();

		Float totalStrength;
		Array< ::Dynamic > paths;
		Float end;
		Float start;
};

} // end namespace motion

#endif /* INCLUDED_motion_ComponentPath */ 
