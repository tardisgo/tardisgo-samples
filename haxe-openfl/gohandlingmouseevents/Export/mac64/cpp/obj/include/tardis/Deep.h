#ifndef INCLUDED_tardis_Deep
#define INCLUDED_tardis_Deep

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Deep)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Deep_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Deep_obj OBJ_;
		Deep_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Deep_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Deep_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Deep"); }

		static Dynamic copy( Dynamic v);
		static Dynamic copy_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Deep */ 
