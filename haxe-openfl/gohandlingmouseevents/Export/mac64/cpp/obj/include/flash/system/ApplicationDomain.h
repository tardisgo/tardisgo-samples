#ifndef INCLUDED_flash_system_ApplicationDomain
#define INCLUDED_flash_system_ApplicationDomain

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(flash,system,ApplicationDomain)
namespace flash{
namespace system{


class HXCPP_CLASS_ATTRIBUTES  ApplicationDomain_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ApplicationDomain_obj OBJ_;
		ApplicationDomain_obj();
		Void __construct(::flash::system::ApplicationDomain parentDomain);

	public:
		static hx::ObjectPtr< ApplicationDomain_obj > __new(::flash::system::ApplicationDomain parentDomain);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ApplicationDomain_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ApplicationDomain"); }

		virtual bool hasDefinition( ::String name);
		Dynamic hasDefinition_dyn();

		virtual Dynamic getDefinition( ::String name);
		Dynamic getDefinition_dyn();

		::flash::system::ApplicationDomain parentDomain;
		static ::flash::system::ApplicationDomain currentDomain;
};

} // end namespace flash
} // end namespace system

#endif /* INCLUDED_flash_system_ApplicationDomain */ 
