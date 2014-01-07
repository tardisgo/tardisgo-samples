#ifndef INCLUDED_tardis_UnsafePointer
#define INCLUDED_tardis_UnsafePointer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/Pointer.h>
HX_DECLARE_CLASS1(tardis,Pointer)
HX_DECLARE_CLASS1(tardis,UnsafePointer)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  UnsafePointer_obj : public ::tardis::Pointer_obj{
	public:
		typedef ::tardis::Pointer_obj super;
		typedef UnsafePointer_obj OBJ_;
		UnsafePointer_obj();
		Void __construct(Dynamic x);

	public:
		static hx::ObjectPtr< UnsafePointer_obj > __new(Dynamic x);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~UnsafePointer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("UnsafePointer"); }

};

} // end namespace tardis

#endif /* INCLUDED_tardis_UnsafePointer */ 
