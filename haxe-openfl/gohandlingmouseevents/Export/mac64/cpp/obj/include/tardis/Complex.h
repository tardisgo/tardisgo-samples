#ifndef INCLUDED_tardis_Complex
#define INCLUDED_tardis_Complex

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Complex)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Complex_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Complex_obj OBJ_;
		Complex_obj();
		Void __construct(Float r,Float i);

	public:
		static hx::ObjectPtr< Complex_obj > __new(Float r,Float i);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Complex_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Complex"); }

		Float imag;
		Float real;
		static ::tardis::Complex neg( ::tardis::Complex x);
		static Dynamic neg_dyn();

		static ::tardis::Complex add( ::tardis::Complex x,::tardis::Complex y);
		static Dynamic add_dyn();

		static ::tardis::Complex sub( ::tardis::Complex x,::tardis::Complex y);
		static Dynamic sub_dyn();

		static ::tardis::Complex mul( ::tardis::Complex x,::tardis::Complex y);
		static Dynamic mul_dyn();

		static ::tardis::Complex div( ::tardis::Complex x,::tardis::Complex y);
		static Dynamic div_dyn();

		static bool eq( ::tardis::Complex x,::tardis::Complex y);
		static Dynamic eq_dyn();

		static bool neq( ::tardis::Complex x,::tardis::Complex y);
		static Dynamic neq_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Complex */ 
