#ifndef INCLUDED_tardis_TypeInfo
#define INCLUDED_tardis_TypeInfo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Interface)
HX_DECLARE_CLASS1(tardis,TypeInfo)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  TypeInfo_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TypeInfo_obj OBJ_;
		TypeInfo_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TypeInfo_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TypeInfo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TypeInfo"); }

		static ::String getName( int id);
		static Dynamic getName_dyn();

		static ::String typeString( ::tardis::Interface i);
		static Dynamic typeString_dyn();

		static int getId( ::String name);
		static Dynamic getId_dyn();

		static bool isAssignableTo( int v,int t);
		static Dynamic isAssignableTo_dyn();

		static bool isIdentical( int v,int t);
		static Dynamic isIdentical_dyn();

		static bool isConcrete( int t);
		static Dynamic isConcrete_dyn();

		static Dynamic zeroValue( int t);
		static Dynamic zeroValue_dyn();

		static Dynamic method( int t,::String m);
		static Dynamic method_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_TypeInfo */ 
