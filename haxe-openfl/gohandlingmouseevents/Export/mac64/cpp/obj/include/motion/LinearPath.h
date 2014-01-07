#ifndef INCLUDED_motion_LinearPath
#define INCLUDED_motion_LinearPath

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <motion/BezierPath.h>
HX_DECLARE_CLASS1(motion,BezierPath)
HX_DECLARE_CLASS1(motion,LinearPath)
namespace motion{


class HXCPP_CLASS_ATTRIBUTES  LinearPath_obj : public ::motion::BezierPath_obj{
	public:
		typedef ::motion::BezierPath_obj super;
		typedef LinearPath_obj OBJ_;
		LinearPath_obj();
		Void __construct(Float end,Float strength);

	public:
		static hx::ObjectPtr< LinearPath_obj > __new(Float end,Float strength);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LinearPath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LinearPath"); }

		virtual Float calculate( Float start,Float k);

};

} // end namespace motion

#endif /* INCLUDED_motion_LinearPath */ 
