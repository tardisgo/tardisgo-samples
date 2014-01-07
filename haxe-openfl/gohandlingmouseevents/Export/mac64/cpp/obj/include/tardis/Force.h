#ifndef INCLUDED_tardis_Force
#define INCLUDED_tardis_Force

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Force)
HX_DECLARE_CLASS1(tardis,Int64)
HX_DECLARE_CLASS1(tardis,Slice)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Force_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Force_obj OBJ_;
		Force_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Force_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Force_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Force"); }

		static int toUint8( int v);
		static Dynamic toUint8_dyn();

		static int toUint16( int v);
		static Dynamic toUint16_dyn();

		static int toUint32( int v);
		static Dynamic toUint32_dyn();

		static ::tardis::Int64 toUint64( ::tardis::Int64 v);
		static Dynamic toUint64_dyn();

		static int toInt8( int v);
		static Dynamic toInt8_dyn();

		static int toInt16( int v);
		static Dynamic toInt16_dyn();

		static int toInt32( int v);
		static Dynamic toInt32_dyn();

		static ::tardis::Int64 toInt64( ::tardis::Int64 v);
		static Dynamic toInt64_dyn();

		static int toInt( Dynamic v);
		static Dynamic toInt_dyn();

		static Float toFloat( Float v);
		static Dynamic toFloat_dyn();

		static int uintCompare( int x,int y);
		static Dynamic uintCompare_dyn();

		static int checkIntDiv( int x,int y,int byts);
		static Dynamic checkIntDiv_dyn();

		static int intDiv( int x,int y,int sv);
		static Dynamic intDiv_dyn();

		static int intMod( int x,int y,int sv);
		static Dynamic intMod_dyn();

		static Float floatDiv( Float x,Float y);
		static Dynamic floatDiv_dyn();

		static Float floatMod( Float x,Float y);
		static Dynamic floatMod_dyn();

		static int toUTF8length( int gr,::String s);
		static Dynamic toUTF8length_dyn();

		static ::tardis::Slice toUTF8slice( int gr,::String s);
		static Dynamic toUTF8slice_dyn();

		static ::String toRawString( int gr,::tardis::Slice sl);
		static Dynamic toRawString_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Force */ 
