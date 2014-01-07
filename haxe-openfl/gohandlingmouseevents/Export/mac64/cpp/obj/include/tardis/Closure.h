#ifndef INCLUDED_tardis_Closure
#define INCLUDED_tardis_Closure

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Closure)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Closure_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Closure_obj OBJ_;
		Closure_obj();
		Void __construct(Dynamic f,Dynamic b);

	public:
		static hx::ObjectPtr< Closure_obj > __new(Dynamic f,Dynamic b);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Closure_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Closure"); }

		virtual Dynamic callFn( Dynamic params);
		Dynamic callFn_dyn();

		virtual Dynamic methVal( Dynamic t,Dynamic v);
		Dynamic methVal_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		Dynamic bds;
		Dynamic fn;
};

} // end namespace tardis

#endif /* INCLUDED_tardis_Closure */ 
