#ifndef INCLUDED__Map_Map_Impl_
#define INCLUDED__Map_Map_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(_Map,Map_Impl_)
namespace _Map{


class HXCPP_CLASS_ATTRIBUTES  Map_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Map_Impl__obj OBJ_;
		Map_Impl__obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Map_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Map_Impl__obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Map_Impl_"); }

};

} // end namespace _Map

#endif /* INCLUDED__Map_Map_Impl_ */ 
