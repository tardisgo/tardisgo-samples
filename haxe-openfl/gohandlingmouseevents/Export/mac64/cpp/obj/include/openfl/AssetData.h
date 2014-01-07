#ifndef INCLUDED_openfl_AssetData
#define INCLUDED_openfl_AssetData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(openfl,AssetData)
HX_DECLARE_CLASS1(openfl,AssetType)
namespace openfl{


class HXCPP_CLASS_ATTRIBUTES  AssetData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AssetData_obj OBJ_;
		AssetData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AssetData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AssetData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AssetData"); }

		::openfl::AssetType type;
		::String path;
		::String id;
};

} // end namespace openfl

#endif /* INCLUDED_openfl_AssetData */ 
