#ifndef INCLUDED_tardis_Go
#define INCLUDED_tardis_Go

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Go)
HX_DECLARE_CLASS1(tardis,Pointer)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Go_obj OBJ_;
		Go_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Go_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Go"); }

		static ::String Platform( );
		static Dynamic Platform_dyn();

		static int main_MOUSE_DOWN;
		static int main_MOUSE_UP;
		static int main_MOUSE_MOVE;
		static int utf8_RuneSelf;
		static int utf8_RuneError;
		static int utf8_MaxRune;
		static int utf8_UTFMax;
		static ::tardis::Pointer haxegoruntime_init_36_guard;
		static ::tardis::Pointer haxegoruntime_ZiLen;
		static ::tardis::Pointer main_init_36_guard;
		static ::tardis::Pointer main_mouseEvents;
		static ::tardis::Pointer utf16_init_36_guard;
		static ::tardis::Pointer utf8_init_36_guard;
		static ::tardis::Pointer hxutil_init_36_guard;
		static bool doneInit;
		static Void init( );
		static Dynamic init_dyn();

		static Void main( );
		static Dynamic main_dyn();

		static ::String CPos( int pos);
		static Dynamic CPos_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go */ 
