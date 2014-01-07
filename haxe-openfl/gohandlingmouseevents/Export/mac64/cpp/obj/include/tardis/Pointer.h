#ifndef INCLUDED_tardis_Pointer
#define INCLUDED_tardis_Pointer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Pointer)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Pointer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Pointer_obj OBJ_;
		Pointer_obj();
		Void __construct(Dynamic from);

	public:
		static hx::ObjectPtr< Pointer_obj > __new(Dynamic from);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Pointer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Pointer"); }

		virtual int len( );
		Dynamic len_dyn();

		virtual ::tardis::Pointer addr( int off);
		Dynamic addr_dyn();

		virtual Void store( Dynamic v);
		Dynamic store_dyn();

		virtual Dynamic ref( );
		Dynamic ref_dyn();

		virtual Dynamic load( );
		Dynamic load_dyn();

		Array< int > offs;
		Dynamic heapObj;
		static ::tardis::Pointer copy( ::tardis::Pointer v);
		static Dynamic copy_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Pointer */ 
