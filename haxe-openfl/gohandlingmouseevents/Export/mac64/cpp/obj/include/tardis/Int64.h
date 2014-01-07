#ifndef INCLUDED_tardis_Int64
#define INCLUDED_tardis_Int64

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Int64)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Int64_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Int64_obj OBJ_;
		Int64_obj();
		Void __construct(int high,int low);

	public:
		static hx::ObjectPtr< Int64_obj > __new(int high,int low);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Int64_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Int64"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		int low;
		int high;
		static int ushr32( int v,int n);
		static Dynamic ushr32_dyn();

		static ::tardis::Int64 make( int high,int low);
		static Dynamic make_dyn();

		static ::tardis::Int64 ofInt( int x);
		static Dynamic ofInt_dyn();

		static int toInt( ::tardis::Int64 x);
		static Dynamic toInt_dyn();

		static int getLow( ::tardis::Int64 x);
		static Dynamic getLow_dyn();

		static int getHigh( ::tardis::Int64 x);
		static Dynamic getHigh_dyn();

		static ::tardis::Int64 add( ::tardis::Int64 a,::tardis::Int64 b);
		static Dynamic add_dyn();

		static ::tardis::Int64 sub( ::tardis::Int64 a,::tardis::Int64 b);
		static Dynamic sub_dyn();

		static ::tardis::Int64 mul( ::tardis::Int64 a,::tardis::Int64 b);
		static Dynamic mul_dyn();

		static Dynamic divMod( ::tardis::Int64 modulus,::tardis::Int64 divisor);
		static Dynamic divMod_dyn();

		static ::tardis::Int64 div( ::tardis::Int64 a,::tardis::Int64 b);
		static Dynamic div_dyn();

		static ::tardis::Int64 mod( ::tardis::Int64 a,::tardis::Int64 b);
		static Dynamic mod_dyn();

		static ::tardis::Int64 shl( ::tardis::Int64 a,int b);
		static Dynamic shl_dyn();

		static ::tardis::Int64 shr( ::tardis::Int64 a,int b);
		static Dynamic shr_dyn();

		static ::tardis::Int64 ushr( ::tardis::Int64 a,int b);
		static Dynamic ushr_dyn();

		static ::tardis::Int64 _and( ::tardis::Int64 a,::tardis::Int64 b);
		static Dynamic _and_dyn();

		static ::tardis::Int64 _or( ::tardis::Int64 a,::tardis::Int64 b);
		static Dynamic _or_dyn();

		static ::tardis::Int64 _xor( ::tardis::Int64 a,::tardis::Int64 b);
		static Dynamic _xor_dyn();

		static ::tardis::Int64 neg( ::tardis::Int64 a);
		static Dynamic neg_dyn();

		static bool isNeg( ::tardis::Int64 a);
		static Dynamic isNeg_dyn();

		static bool isZero( ::tardis::Int64 a);
		static Dynamic isZero_dyn();

		static int uicompare( int a,int b);
		static Dynamic uicompare_dyn();

		static int compare( ::tardis::Int64 a,::tardis::Int64 b);
		static Dynamic compare_dyn();

		static int ucompare( ::tardis::Int64 a,::tardis::Int64 b);
		static Dynamic ucompare_dyn();

		static ::String toStr( ::tardis::Int64 a);
		static Dynamic toStr_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Int64 */ 
