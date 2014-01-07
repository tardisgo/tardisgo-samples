#ifndef INCLUDED_tardis__Go_HaxeInt64abs_Impl_
#define INCLUDED_tardis__Go_HaxeInt64abs_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Int64)
HX_DECLARE_CLASS2(tardis,_Go,HaxeInt64abs_Impl_)
namespace tardis{
namespace _Go{


class HXCPP_CLASS_ATTRIBUTES  HaxeInt64abs_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef HaxeInt64abs_Impl__obj OBJ_;
		HaxeInt64abs_Impl__obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HaxeInt64abs_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HaxeInt64abs_Impl__obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HaxeInt64abs_Impl_"); }

		static ::tardis::Int64 _new( ::tardis::Int64 v);
		static Dynamic _new_dyn();

		static int toInt( ::tardis::Int64 v);
		static Dynamic toInt_dyn();

		static ::tardis::Int64 ofInt( int v);
		static Dynamic ofInt_dyn();

		static Float toFloat( ::tardis::Int64 vp);
		static Dynamic toFloat_dyn();

		static Float toUFloat( ::tardis::Int64 vp);
		static Dynamic toUFloat_dyn();

		static ::tardis::Int64 ofFloat( Float v);
		static Dynamic ofFloat_dyn();

		static ::tardis::Int64 ofUFloat( Float v);
		static Dynamic ofUFloat_dyn();

		static ::tardis::Int64 make( int h,int l);
		static Dynamic make_dyn();

		static ::String toString( ::tardis::Int64 v);
		static Dynamic toString_dyn();

		static ::String toStr( ::tardis::Int64 v);
		static Dynamic toStr_dyn();

		static ::tardis::Int64 neg( ::tardis::Int64 v);
		static Dynamic neg_dyn();

		static bool isZero( ::tardis::Int64 v);
		static Dynamic isZero_dyn();

		static bool isNeg( ::tardis::Int64 v);
		static Dynamic isNeg_dyn();

		static ::tardis::Int64 add( ::tardis::Int64 x,::tardis::Int64 y);
		static Dynamic add_dyn();

		static ::tardis::Int64 _and( ::tardis::Int64 x,::tardis::Int64 y);
		static Dynamic _and_dyn();

		static ::tardis::Int64 checkDiv( ::tardis::Int64 x,::tardis::Int64 y,bool isSigned);
		static Dynamic checkDiv_dyn();

		static ::tardis::Int64 div( ::tardis::Int64 x,::tardis::Int64 y,bool isSigned);
		static Dynamic div_dyn();

		static ::tardis::Int64 mod( ::tardis::Int64 x,::tardis::Int64 y,bool isSigned);
		static Dynamic mod_dyn();

		static ::tardis::Int64 mul( ::tardis::Int64 x,::tardis::Int64 y);
		static Dynamic mul_dyn();

		static ::tardis::Int64 _or( ::tardis::Int64 x,::tardis::Int64 y);
		static Dynamic _or_dyn();

		static ::tardis::Int64 shl( ::tardis::Int64 x,int y);
		static Dynamic shl_dyn();

		static ::tardis::Int64 ushr( ::tardis::Int64 x,int y);
		static Dynamic ushr_dyn();

		static ::tardis::Int64 sub( ::tardis::Int64 x,::tardis::Int64 y);
		static Dynamic sub_dyn();

		static ::tardis::Int64 _xor( ::tardis::Int64 x,::tardis::Int64 y);
		static Dynamic _xor_dyn();

		static int compare( ::tardis::Int64 x,::tardis::Int64 y);
		static Dynamic compare_dyn();

		static int ucompare( ::tardis::Int64 x,::tardis::Int64 y);
		static Dynamic ucompare_dyn();

};

} // end namespace tardis
} // end namespace _Go

#endif /* INCLUDED_tardis__Go_HaxeInt64abs_Impl_ */ 
