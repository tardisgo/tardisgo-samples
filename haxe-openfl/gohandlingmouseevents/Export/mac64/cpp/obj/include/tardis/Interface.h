#ifndef INCLUDED_tardis_Interface
#define INCLUDED_tardis_Interface

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Interface)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Interface_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Interface_obj OBJ_;
		Interface_obj();
		Void __construct(int t,Dynamic v);

	public:
		static hx::ObjectPtr< Interface_obj > __new(int t,Dynamic v);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Interface_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Interface"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		Dynamic val;
		int typ;
		static ::tardis::Interface change( int t,::tardis::Interface i);
		static Dynamic change_dyn();

		static bool isEqual( ::tardis::Interface a,::tardis::Interface b);
		static Dynamic isEqual_dyn();

		static Dynamic _assert( int assTyp,::tardis::Interface ifce);
		static Dynamic _assert_dyn();

		static Dynamic assertOk( int assTyp,::tardis::Interface ifce);
		static Dynamic assertOk_dyn();

		static Dynamic invoke( ::tardis::Interface ifce,::String meth,Dynamic args);
		static Dynamic invoke_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Interface */ 
