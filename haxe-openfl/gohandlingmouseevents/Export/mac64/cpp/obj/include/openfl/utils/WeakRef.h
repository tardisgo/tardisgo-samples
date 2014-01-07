#ifndef INCLUDED_openfl_utils_WeakRef
#define INCLUDED_openfl_utils_WeakRef

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,utils,WeakRef)
namespace openfl{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES  WeakRef_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef WeakRef_obj OBJ_;
		WeakRef_obj();
		Void __construct(Dynamic object,hx::Null< bool >  __o_makeWeak);

	public:
		static hx::ObjectPtr< WeakRef_obj > __new(Dynamic object,hx::Null< bool >  __o_makeWeak);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~WeakRef_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("WeakRef"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Dynamic get( );
		Dynamic get_dyn();

		int weakRef;
		Dynamic hardRef;
		static Dynamic lime_weak_ref_create;
		static Dynamic lime_weak_ref_get;
};

} // end namespace openfl
} // end namespace utils

#endif /* INCLUDED_openfl_utils_WeakRef */ 
