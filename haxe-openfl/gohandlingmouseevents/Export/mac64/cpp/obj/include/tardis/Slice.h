#ifndef INCLUDED_tardis_Slice
#define INCLUDED_tardis_Slice

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Pointer)
HX_DECLARE_CLASS1(tardis,Slice)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Slice_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Slice_obj OBJ_;
		Slice_obj();
		Void __construct(::tardis::Pointer fromArray,int low,int high);

	public:
		static hx::ObjectPtr< Slice_obj > __new(::tardis::Pointer fromArray,int low,int high);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Slice_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Slice"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::tardis::Pointer addr( Dynamic dynIdx);
		Dynamic addr_dyn();

		virtual int cap( );
		Dynamic cap_dyn();

		virtual int len( );
		Dynamic len_dyn();

		virtual Void setAt( Dynamic dynIdx,Dynamic v);
		Dynamic setAt_dyn();

		virtual Dynamic getAt( Dynamic dynIdx);
		Dynamic getAt_dyn();

		virtual ::tardis::Slice subSlice( int low,int high);
		Dynamic subSlice_dyn();

		int end;
		int start;
		::tardis::Pointer baseArray;
};

} // end namespace tardis

#endif /* INCLUDED_tardis_Slice */ 
